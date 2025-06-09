/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file display_memlcd.hpp
 * @brief display middleware for Sharp Memory LCD
 */
#ifndef MIDDLEWARE_MEMLCD_HPP
#define MIDDLEWARE_MEMLCD_HPP

#include <cstdint>
#include <array>
#include <span>

namespace libMcuMid::display {

namespace driver = libMcuDrv::memlcd;
template <typename config, auto& driver>
// TODO maybe rename to displayDriverColumn based?
class DisplayMemlcd {
 public:
  DisplayMemlcd() {};
  constexpr void Init() {
    SetBuffer(0x0000);
    Update();
  }
  /**
   * @brief fill the framebuffer with a pattern
   * @param pattern to fill the framebuffer with
   */
  constexpr void Fill(std::uint32_t pattern) {
    SetBuffer(pattern);
  }
  /**
   * @brief Set pixel at coordinate
   * @param x x coordinate of the pixel to set
   * @param y y coordinate of the pixel to get
   * @param color pixel value to set
   */
  constexpr void SetPixel(std::uint32_t x, std::uint32_t y, std::uint32_t color) {
    int index = X2index(x) + Y2index(y);
    if (color == 0)
      frame_buffer_[index] = frame_buffer_[index] & ~(0x01 << (x & 0xF));
    else
      frame_buffer_[index] = frame_buffer_[index] | (0x01 << (x & 0xF));
  }
  /**
   * @brief Get pixel value at coordinate
   * @param x x coordinate of the pixel to get
   * @param y y coordinate of the pixel to get
   * @return pixel value
   */
  constexpr std::uint32_t GetPixel(std::uint32_t x, std::uint32_t y) {
    int index = X2index(x) + Y2index(y);
    return frame_buffer_[index] & (0x01 << (x & 0xF));
  }
  /**
   * @brief fill a block of the display with given color
   * @param xStart X start position of the block
   * @param yStart Y start position of the block
   * @param xEnd X end position of the block
   * @param yEnd Y end position of the block
   * @param color color to fill the block with
   */
  constexpr void Fill(std::uint32_t xStart, std::uint32_t yStart, std::uint32_t xEnd, std::uint32_t yEnd, std::uint32_t color) {
    if (xEnd > getXSize())
      xEnd = getXSize();
    if (yEnd > getYSize())
      yEnd = getYSize();
    for (std::uint32_t y = yStart; y < yEnd; y++) {
      for (std::uint32_t x = xStart; x < xEnd; x++) {
        setPixel(x, y, color);
      }
    }
  }
  /**
   * @brief get X size of display
   * @return X size
   */
  constexpr std::uint32_t GetXSize() const {
    return driver.getXSize();
  }
  /**
   * @brief Get maximum Y size of display
   * @return Y size
   */
  constexpr std::uint32_t GetYSize() const {
    return driver.getYSize();
  }
  /**
   * @brief Copy over the framebuffer to the LCD
   */
  constexpr void Update() {
    // TODO write only dirty lines to LCD
    driver.transferLines(frame_buffer_);
  }

 private:
  /**
   * @brief convert Y coordinate to index in the frame buffer
   * @param y y coordinate
   * @return index in the frame buffer while taking M0, M1, M2 bits and addressing word into account
   */
  constexpr int Y2index(uint16_t y) const {
    return y * ((config::maxX / 16) + 1);
  }
  /**
   * @brief convert X coordinate to index in the frame buffer
   * @param x x coordinate
   * @return index in the frame buffer while taking M0, M1, M2 bits and addressing word into account
   */
  constexpr int X2index(uint16_t x) const {
    return (x / 16) + 1;
  }
  /**
   * @brief clear the frame buffer
   * This clears the framebuffer and sets up M0 bit and the line addresses at the beginning of each line
   * @param value bit pattern to write
   */
  constexpr void SetBuffer(uint16_t value) {
    frame_buffer_.fill(value);
    for (uint16_t i = 0; i < config::maxY; i++) {
      // add M0, M1, M2 bits and line addres to beginning of each line entry
      frame_buffer_[y2index(i)] = driver::cmdDataUpdate | (i + 1) << config::addrShift;
    }
  }
  // Adding 16 bit word per row for spi data setup and teardown and one extra word for last line
  std::array<std::uint16_t, (((config::maxX / 16) + 1) * config::maxY) + 1> frame_buffer_;
};
}  // namespace libMcuMid::display
#endif