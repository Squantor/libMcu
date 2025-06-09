/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file display_dir_SSD1306.hpp
 * @brief display middleware for SSD1306, direct mode only
 */
#ifndef DISPLAY_DIR_SSD1306_HPP
#define DISPLAY_DIR_SSD1306_HPP

#include <cstdint>
#include <array>
#include <span>

namespace libMcuMid::display {
/**
 * @brief
 *
 * @tparam config
 * @tparam driver
 */
template <auto& config, auto& driver>
// TODO maybe rename to displayDriverColumn based?
class displayDirSSD1306 {
 public:
  displayDirSSD1306() {};
  void fill(std::uint32_t pattern) {
    // TODO add error handling
    buffer.fill(static_cast<std::uint8_t>(pattern));
    driver.setColumnAddress(0, config.xSize - 1);
    driver.setPageAddress(0, (config.ySize / 8) - 1);
    for (uint32_t y = 0; y < config.ySize; y += 8) {
      for (uint32_t x = 0; x < config.xSize; x += 16) {
        driver.sendData(buffer);
      }
    }
  }
  void fill(std::uint32_t xStart, std::uint32_t yStart, std::uint32_t xEnd, std::uint32_t yEnd, std::uint32_t pattern) {
    buffer.fill(static_cast<std::uint8_t>(pattern));
    driver.setColumnAddress(xStart, xEnd - 1);
    driver.setPageAddress(yStart / 8, (yEnd / 8) - 1);
    // compute amount of bytes to write
    std::uint32_t bytesToWrite = (xEnd - xStart) * ((yEnd / 8) - (yStart / 8) + 1);
    do {
      driver.sendData(buffer);
      bytesToWrite -= buffer.size();
    } while (bytesToWrite > buffer.size());
    if (bytesToWrite > 0) {
      driver.sendData(std::span<const std::uint8_t>(buffer).subspan(0, bytesToWrite));
    }
  }
  void writeBlock(std::uint32_t xStart, std::uint32_t yStart, std::uint32_t xEnd, std::uint32_t yEnd,
                  std::span<const std::uint8_t> data) {
    // TODO add error handling
    driver.setColumnAddress(xStart, xEnd - 1);
    driver.setPageAddress(yStart / 8, yEnd / 8);
    driver.sendData(data);
  }
  void setPixel(std::uint32_t x, std::uint32_t y, std::uint32_t color) {
    static_assert(false, "not implemented for this display");
  }
  void getPixel(std::uint32_t x, std::uint32_t y, std::uint32_t& color) {
    static_assert(false, "not implemented for this display");
  }
  std::uint32_t getXSize() {
    return driver.getXsize();
  }
  std::uint32_t getYSize() {
    return driver.getYsize();
  }
  /**
   * @brief Scroll the display
   * Uses the SSD1306 set start address, no copying of data done
   * @param xPos start address to scroll to, no checking done
   */
  libmcu::Results scroll(std::uint32_t xPos) {
    return (driver.setDisplayStartLine(xPos));
  }
  /**
   * @brief set the display brightness
   * @param percentage from 0 to 100% mapped onto the value
   * @return result of i2c transaction
   */
  libmcu::Results brightness(std::uint32_t percentage) {
    // scale percentage to value
    std::uint32_t value = percentage * 255 / 100;
    if (value == 0)
      value = 1;
    return driver.contrast(value);
  }
  /**
   * @brief invert the display
   * @param isInverted inversion state
   * @return Result of i2c transaction
   */
  libmcu::Results invert(bool isInverted) {
    return driver.invertDisplay(isInverted);
  }

 private:
  std::array<std::uint8_t, 16> buffer; /*!< buffer for display operations*/
};
}  // namespace libMcuMid::display

#endif