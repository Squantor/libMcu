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
class displayMemlcd {
 public:
  displayMemlcd() {};
  constexpr void init() {
    setBuffer(0x0000);
    update();
  }
  /**
   * @brief fill the framebuffer with a pattern
   * @param pattern to fill the framebuffer with
   */
  constexpr void fill(std::uint32_t pattern) {
    setBuffer(pattern);
  }
  /**
   * @brief Set pixel at coordinate
   * @param x x coordinate of the pixel to set
   * @param y y coordinate of the pixel to get
   * @param color pixel value to set
   */
  constexpr void setPixel(std::uint32_t x, std::uint32_t y, std::uint32_t color) {
    int index = x2index(x) + y2index(y);
    if (color == 0)
      frameBuffer[index] = frameBuffer[index] & ~(0x01 << (x & 0xF));
    else
      frameBuffer[index] = frameBuffer[index] | (0x01 << (x & 0xF));
  }
  /**
   * @brief Get pixel value at coordinate
   * @param x x coordinate of the pixel to get
   * @param y y coordinate of the pixel to get
   * @return pixel value
   */
  constexpr std::uint32_t getPixel(std::uint32_t x, std::uint32_t y) {
    int index = x2index(x) + y2index(y);
    return frameBuffer[index] & (0x01 << (x & 0xF));
  }
  /**
   * @brief fill a block of the display with given color
   * @param xStart X start position of the block
   * @param yStart Y start position of the block
   * @param xEnd X end position of the block
   * @param yEnd Y end position of the block
   * @param color color to fill the block with
   */
  constexpr void fill(std::uint32_t xStart, std::uint32_t yStart, std::uint32_t xEnd, std::uint32_t yEnd, std::uint32_t color) {
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
  constexpr std::uint32_t getXSize() const {
    return driver.getXSize();
  }
  /**
   * @brief Get maximum Y size of display
   * @return Y size
   */
  constexpr std::uint32_t getYSize() const {
    return driver.getYSize();
  }
  /**
   * @brief Copy over the framebuffer to the LCD
   */
  constexpr void update() {
    // TODO write only dirty lines to LCD
    driver.transferLines(frameBuffer);
  }

 private:
  /**
   * @brief convert Y coordinate to index in the frame buffer
   * @param y y coordinate
   * @return index in the frame buffer while taking M0, M1, M2 bits and addressing word into account
   */
  constexpr int y2index(uint16_t y) const {
    return y * ((config::maxX / 16) + 1);
  }
  /**
   * @brief convert X coordinate to index in the frame buffer
   * @param x x coordinate
   * @return index in the frame buffer while taking M0, M1, M2 bits and addressing word into account
   */
  constexpr int x2index(uint16_t x) const {
    return (x / 16) + 1;
  }
  /**
   * @brief clear the frame buffer
   * This clears the framebuffer and sets up M0 bit and the line addresses at the beginning of each line
   * @param value bit pattern to write
   */
  constexpr void setBuffer(uint16_t value) {
    frameBuffer.fill(value);
    for (uint16_t i = 0; i < config::maxY; i++) {
      // add M0, M1, M2 bits and line addres to beginning of each line entry
      frameBuffer[y2index(i)] = driver::cmdDataUpdate | (i + 1) << config::addrShift;
    }
  }
  // Adding 16 bit word per row for spi data setup and teardown and one extra word for last line
  std::array<std::uint16_t, (((config::maxX / 16) + 1) * config::maxY) + 1> frameBuffer;
};
}  // namespace libMcuMid::display
#endif