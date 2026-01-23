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
 * @todo i2chal template parameter needs check with a concept
 * @todo optimize transfer by keeping what bytes are dirty
 * @tparam i2c_hal I2C hal to be used
 * @tparam i2c_address I2C address the display is connected to
 * @tparam config display configuration
 * @tparam Assert Assertion class
 */
template <auto &i2c_hal, const libmcu::I2cDeviceAddress &i2c_address, auto &config,
          libmcu::AssertCallable Assert = libmcu::NoAssert>
struct SH1106 : public GfxDisplay<std::uint32_t, std::uint32_t> {
  /**
   * @brief
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results Init() {
    state = libmcu::States::Initializing;
    framebuffer.fill(0);
    SendCommand(config.init_commands);
    Flip();
    return SetAddress(0, 0, this);
  }
  /**
   * @brief Get the maximum X coordinate of the display
   * @return constexpr std::uint32_t
   */
  constexpr std::uint32_t GetXsize() {
    return config.xSize;
  }
  /**
   * @brief Get the maximum Y coordinate of the display
   * @return constexpr std::uint32_t
   */
  constexpr std::uint32_t GetYsize() {
    return config.ySize;
  }
  /**
   * @brief
   * @param commands
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SendCommand(const std::span<const std::uint8_t> commands, NonBlocking *callback = nullptr) {
    return Send(preamble_command_buffer, commands, callback);
  }
  /**
   * @brief
   * @param data
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SendData(const std::span<const std::uint8_t> data, NonBlocking *callback = nullptr) {
    return Send(preamble_data_buffer, data, callback);
  }
  /**
   * @brief
   * @param action
   * @param commands
   * @param callback Callback to execute when Send is done
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results Send(const std::span<const std::uint8_t> action, const std::span<const std::uint8_t> commands,
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
  constexpr libmcu::Results Contrast(std::uint8_t value) {
    std::span<uint8_t> set_contrast_buffer = allocator.Request(2);
    set_contrast_buffer[0] = cmd_set_constrast;
    set_contrast_buffer[1] = FormatContrastLevelArg(value);
    return SendCommand(set_contrast_buffer);
  }
  /**
   * @brief Set the Column Address object
   * @param start
   * @return constexpr libmcu::Results
   * @todo Not implemented
   */
  constexpr libmcu::Results SetColumnAddress(uint32_t column) {
    std::span<uint8_t> set_column_address_buffer = allocator.Request(2);
    std::uint32_t column_byte = static_cast<uint8_t>(column & 0xFF);
    set_column_address_buffer[0] = FormatSetHigherColumnAddress(static_cast<uint8_t>(column_byte));
    set_column_address_buffer[1] = FormatSetLowerColumnAddress(static_cast<uint8_t>(column_byte));
    return SendCommand(set_column_address_buffer);
  }
  /**
   * @brief Set the display page address start
   * @param address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SetPageAddress(uint32_t page) {
    std::span<uint8_t> set_page_address_buffer = allocator.Request(1);
    set_page_address_buffer[0] = FormatSetPageAddress(static_cast<uint8_t>(page));
    return SendCommand(set_page_address_buffer);
  }
  /**
   * @brief Set the display address to write data to
   * @param column Column address
   * @param page Page address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SetAddress(uint32_t column, uint32_t page, NonBlocking *callback = nullptr) {
    std::span<uint8_t> set_address_buffer = allocator.Request(3);
    column = column + config.column_offset;
    set_address_buffer[0] = FormatSetHigherColumnAddress(static_cast<uint8_t>(column));
    set_address_buffer[1] = FormatSetLowerColumnAddress(static_cast<uint8_t>(column));
    set_address_buffer[2] = FormatSetPageAddress(static_cast<uint8_t>(page));
    return SendCommand(set_address_buffer, callback);
  }
  /**
   * @brief Transfers framebuffer information to the display
   * Will queue up a bunch of I2C transfers in one go
   */
  constexpr void Flip(void) override {
    std::span<uint8_t> framebuffer_span = framebuffer;
    for (uint32_t i = 0; i < config.size_pages; i++) {
      SetAddress(0, i);
      SendData(framebuffer_span.subspan(i * config.size_x, config.size_x));
    }
  }
  /**
   * @brief Clear the framebuffer with clear pixels, does not flip
   * @todo Not implemented
   */
  constexpr void Clear(uint32_t color = 0) override {
    std::uint8_t clear_pixel;
    if (color) {
      clear_pixel = 0xFF;
    } else {
      clear_pixel = 0x00;
    }

    std::fill(framebuffer.begin(), framebuffer.end(), clear_pixel);
  }
  /**
   * @brief Set the Pixel object
   *
   * @param x
   * @param y
   * @param color
   */
  constexpr void SetPixel(uint32_t x, uint32_t y, uint32_t color) override {
    (void)x;
    (void)y;
    (void)color;
  }
  /**
   * @brief Set the display state
   * @param state Display state to set
   */
  constexpr void SetState(GfxDisplayState state) override {
    (void)state;
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
      case libmcu::States::Initializing:
        // we get callback from the I2C HAL driver
        // todo check error status
        state = libmcu::States::Idle;
        break;
      default:
        // should not happen
        break;
    }
  }

 private:
  libmcu::States state = libmcu::States::Initializing;
  std::array<std::uint8_t, config.size_framebuffer> framebuffer;
  std::array<const std::uint8_t, 1> preamble_command_buffer = {preamble_command};
  std::array<const std::uint8_t, 1> preamble_data_buffer = {preamble_data};
  libmcu::FinoAllocator<std::uint8_t, 32> allocator;  // Some overprovisioning is needed to be safe
};

}  // namespace libmcudrv::SH1106

#endif