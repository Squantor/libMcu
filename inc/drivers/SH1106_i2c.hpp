/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file SH1106_i2c.hpp
 * @brief driver for the SH1106 OLED display driver via I2C
 */
#ifndef SH1106_I2C_HPP
#define SH1106_I2C_HPP

#include "../libmcu/libmcudrv.hpp"
#include "SH1106/SH1106.hpp"
#include "SH1106/SH1106_conf_gen_128x64.hpp"

namespace libmcudrv::SH1106 {

/**
 * @brief SH1106 driver over I2C bus
 * @todo switched from FINO to FIDFO, need proper state management here!
 * @todo i2chal template parameter needs check with a concept
 * @todo optimize transfer by keeping what bytes are dirty
 * @tparam i2c_hal I2C hal to be used
 * @tparam i2c_address I2C address the display is connected to
 * @tparam config display configuration
 * @tparam Assert Assertion class
 */
template <auto &i2c_hal, const libmcu::I2cDeviceAddress &i2c_address, auto &config,
          libmcu::Assert_concept Assert = libmcu::Assert_default>
struct SH1106 : public Gfx_display_driver<std::uint16_t, std::uint32_t> {
  using Coord_type = std::uint16_t;
  using Pixel_type = std::uint32_t;
  /**
   * @brief
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results init() {
    state = libmcu::States::Initializing;
    framebuffer.fill(0);
    return send_command(config.init_commands, this);
  }
  /**
   * @brief Get the maximum X coordinate of the display
   * @return constexpr std::uint32_t
   */
  constexpr std::uint16_t get_width() override {
    return config.size_x;
  }
  /**
   * @brief Get the maximum Y coordinate of the display
   * @return constexpr std::uint32_t
   */
  constexpr std::uint16_t get_height() override {
    return config.size_y;
  }
  /**
   * @brief
   * @param commands
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results send_command(const std::span<const std::uint8_t> commands, NonBlocking *callback = nullptr) {
    return send(preamble_command_buffer, commands, callback);
  }
  /**
   * @brief
   * @param data
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results send_data(const std::span<const std::uint8_t> data, NonBlocking *callback = nullptr) {
    return send(preamble_data_buffer, data, callback);
  }
  /**
   * @brief
   * @param action
   * @param commands
   * @param callback Callback to execute when Send is done
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results send(const std::span<const std::uint8_t> action, const std::span<const std::uint8_t> commands,
                                 NonBlocking *callback) {
    i2c_hal.StartMasterTransmit(i2c_address, action);
    i2c_hal.StopMasterTransmit(commands, callback);
    return libmcu::Results::NoError;
  }
  /**
   * @brief Set the display contrast value
   * @param contrast contrast value from 1 to 255
   * @return status of I2C transaction
   */
  constexpr libmcu::Results contrast(std::uint8_t value) {
    std::span<uint8_t> set_contrast_buffer = allocator.request(2);
    set_contrast_buffer[0] = cmd_set_constrast;
    set_contrast_buffer[1] = FormatContrastLevelArg(value);
    return send_command(set_contrast_buffer);
  }
  /**
   * @brief Set the Column Address object
   * @param start
   * @return constexpr libmcu::Results
   * @todo Not implemented
   */
  constexpr libmcu::Results set_column_address(uint32_t column) {
    std::span<uint8_t> set_column_address_buffer = allocator.request(2);
    std::uint32_t column_byte = static_cast<uint8_t>(column & 0xFF);
    set_column_address_buffer[0] = FormatSetHigherColumnAddress(static_cast<uint8_t>(column_byte));
    set_column_address_buffer[1] = FormatSetLowerColumnAddress(static_cast<uint8_t>(column_byte));
    return send_command(set_column_address_buffer);
  }
  /**
   * @brief Set the display page address start
   * @param address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results set_page_address(uint32_t page) {
    std::span<uint8_t> set_page_address_buffer = allocator.request(1);
    set_page_address_buffer[0] = FormatSetPageAddress(static_cast<uint8_t>(page));
    return send_command(set_page_address_buffer);
  }
  /**
   * @brief Set the display address to write data to
   * @param column Column address
   * @param page Page address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results set_address(uint32_t column, uint32_t page, NonBlocking *callback = nullptr) {
    std::span<uint8_t> set_address_buffer = allocator.request(3);
    column = column + config.column_offset;
    set_address_buffer[0] = FormatSetHigherColumnAddress(static_cast<uint8_t>(column));
    set_address_buffer[1] = FormatSetLowerColumnAddress(static_cast<uint8_t>(column));
    set_address_buffer[2] = FormatSetPageAddress(static_cast<uint8_t>(page));
    return send_command(set_address_buffer, callback);
  }
  /**
   * @brief Transfers framebuffer information to the display
   * Will queue up a bunch of I2C transfers in one go
   */
  constexpr void flip(void) override {
    if (state != libmcu::States::Idle) {
      // we are already busy, update flip request counter
      flip_requests++;
      return;
    }
    state = libmcu::States::Busy;
    flip_internal();
  }
  /**
   * @brief Clear the framebuffer with clear pixels, does not flip
   * @param color Color to clear with
   */
  constexpr void clear(uint32_t color = 0) override {
    std::uint8_t clear_pixel;
    if (color) {
      clear_pixel = 0xFF;
    } else {
      clear_pixel = 0x00;
    }
    std::fill(framebuffer.begin(), framebuffer.end(), clear_pixel);
  }
  /**
   * @brief Set a pixel on the display to a certain color
   * @param x X position
   * @param y Y position
   * @param color Color
   */
  constexpr void set_pixel(std::uint16_t x, std::uint16_t y, std::uint32_t color) override {
    std::uint8_t bitmask = 1 << (y & 0x07);
    std::size_t index = (y >> 3) * config.size_x + x;
    if (color) {
      framebuffer[index] |= bitmask;
    } else {
      framebuffer[index] &= ~bitmask;
    }
  }
  /**
   * @brief Set the display state
   * @param state Display state to set
   */
  constexpr void set_state(Display_state state) override {
    (void)state;
  }
  /**
   * @brief Blit a bitmap to the display
   * @param x X position
   * @param y Y position
   * @param bitmap Bitmap to blit
   */
  constexpr void blit(std::uint16_t x, std::uint16_t y, const libmcu::bitmap::Const_bitmap &bitmap) override {
    // compute bitmap bounds
    libmcu::bitmap::Bitmap_size bitmap_size = bitmap.get_size();
    std::uint32_t bitmap_width = bitmap_size.w;
    std::uint32_t bitmap_height = bitmap_size.h;
    if (bitmap_width + x > config.size_x) {
      bitmap_width = bitmap_width - (bitmap_width + x - config.size_x);
    }
    if (bitmap_height + y > config.size_y) {
      bitmap_height = bitmap_height - (bitmap_height + y - config.size_y);
    }
    // copy bitmap data to framebuffer
    for (std::uint32_t i = 0; i < bitmap_height; i++) {
      for (std::uint32_t j = 0; j < bitmap_width; j++) {
        set_pixel(x + j, y, bitmap.get_pixel(j, i));
      }
      y++;
    }
  }
  /**
   * @brief
   */
  constexpr void Progress(void) override {}
  /**
   * @brief Callback method
   * Called from I2C HAL
   */
  constexpr void Callback(void) override {
    switch (state) {
      case libmcu::States::Busy:
        // fallthrough
      case libmcu::States::Initializing:
        // we get callback from the I2C HAL driver
        // todo check error status
        allocator.reset();
        if (flip_counter != flip_requests) {
          flip_counter++;
          flip_internal();
        } else {
          state = libmcu::States::Idle;
        }
        break;

      default:
        // should not happen
        break;
    }
  }
  libmcu::States state = libmcu::States::Initializing; /*!< Current state of the display */

 private:
  /**
   * @brief Transfers framebuffer information to the display
   * Will queue up a bunch of I2C transfers in one go
   */
  constexpr void flip_internal(void) {
    std::span<uint8_t> framebuffer_span = framebuffer;
    for (uint32_t i = 0; i < config.size_pages; i++) {
      set_address(0, i);
      send_data(framebuffer_span.subspan(i * config.size_x, config.size_x));
    }
    // We want a callback after flip is done so the state can be updated so we do a SetAddress here
    set_address(0, 0, this);
  }
  std::size_t flip_counter = 0;  /*!< How many times the framebuffer has been flipped */
  std::size_t flip_requests = 0; /*!< How many times the framebuffer has to be flipped */
  std::array<std::uint8_t, config.size_framebuffer> framebuffer;
  std::array<const std::uint8_t, 1> preamble_command_buffer = {preamble_command};
  std::array<const std::uint8_t, 1> preamble_data_buffer = {preamble_data};
  libmcu::Fidfo_allocator<std::uint8_t, 64, Assert> allocator;
};

}  // namespace libmcudrv::SH1106

#endif