/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file SSD1306_i2c.hpp
 * @brief driver for the SSD1306 OLED display via I2C
 */
#ifndef SSD1306_HPP
#define SSD1306_HPP

#include <cstdint>

namespace libMcuDriver::SSD1306 {

constexpr inline std::uint8_t preambleCommand{0x00};
constexpr inline std::uint8_t preambleData{0x40};

constexpr std::uint8_t setVcomDeselectLevel = 0xDB;
constexpr std::uint8_t vcomDeselectLevel(std::uint8_t level) {
  return (level & 0x07) << 4;
}
constexpr std::uint8_t setComPinsHardware = 0xDA;
enum comPinMapping : std::uint8_t {
  sequentialNormal = 0x00,
  sequentialRemapped = 0x20,
  alternatingNormal = 0x10,
  alternatingRemapped = 0x30,
};
constexpr std::uint8_t ComPinsHardware(comPinMapping setting) {
  return 0x02 | setting;
}

constexpr std::uint8_t setDisplayClockDivide{0xD5};
constexpr std::uint8_t displayClockDivisor(std::uint8_t ratio) {
  return ratio;
}

constexpr std::uint8_t setPrechargeLevel = 0xD9;
constexpr std::uint8_t prechargeLevel(std::uint8_t level) {
  return level;
}

constexpr std::uint8_t setDisplayOffset = 0xD3;
constexpr std::uint8_t displayOffset(std::uint8_t offset) {
  return offset;
}

enum scanDirection : std::uint8_t {
  normalDirection = 0x00,
  remappedDirection = 0x08,
};

constexpr std::uint8_t comOutputScanDirection(scanDirection mode) {
  return mode | 0xC0;
}

constexpr std::uint8_t setPageStart(std::uint8_t address) {
  return (address & 0x07) | 0xB0;
}
constexpr std::uint8_t displayActive{0xAF};     /*!< turn display on */
constexpr std::uint8_t displaySleep{0xAE};      /*!< turn display off */
constexpr std::uint8_t setMultiplexRatio{0xA8}; /*!< multiplex ratio */
constexpr std::uint8_t multiplexRatio(std::uint8_t ratio) {
  return ratio;
}
constexpr std::uint8_t displayInvert{0xA7}; /*!< invert display */
constexpr std::uint8_t displayNormal{0xA6}; /*!< normal display */
constexpr std::uint8_t displayRam{0xA5};    /*!< display RAM content */
constexpr std::uint8_t displayOn{0xA4};     /*!< turn all pixels on */

enum segmentMapping : std::uint8_t {
  column0 = 0,  /*!< Segment 0 mapped to column address 0 */
  column127 = 1 /*!< Segment 0 mapped to column address 127 */
};
/*!< @brief set segment remapping */
constexpr std::uint8_t setSegmentRemap(segmentMapping mapping) {
  return mapping | 0xA0;
}
constexpr std::uint8_t setChargePump = 0x8D; /*!< set charge pump state */
constexpr std::uint8_t chargePumpOn(bool pumpOn) {
  if (pumpOn)
    return 0x14;
  else
    return 0x10;
}
constexpr std::uint8_t setContrast = 0x81; /*!< set contrast level */
constexpr std::uint8_t ContrastLevel(std::uint8_t level) {
  return level;
}
constexpr std::uint8_t setDisplayStartLine(std::uint8_t address) {
  return (address & 0x3F) | 0x40;
}
constexpr std::uint8_t scrollOn{0x2F};
constexpr std::uint8_t scrollOff{0x2E};
constexpr std::uint8_t setPageAddress{0x22};
constexpr std::uint8_t setColumnAddress{0x21};
constexpr std::uint8_t setMemoryAddressingMode{0x20};

enum addressingModes : std::uint8_t {
  horizontalMode = 0, /*!< Horizontal addressing mode */
  verticalMode = 1,   /*!< vertical addressing mode */
  pageMode = 2,       /*!< page addressing mode */
  invalidMode = 3,    /*!< INVALID! DO NOT USE! */
};

constexpr std::uint8_t AddressingMode(addressingModes mode) {
  return mode;
}

constexpr std::uint8_t higherColumnAddress(std::uint8_t address) {
  return (address & 0x0F) | 0x10;
}

constexpr std::uint8_t lowerColumnAddress(std::uint8_t address) {
  return (address & 0x0F) | 0x00;
}

}  // namespace libMcuDriver::SSD1306

#endif