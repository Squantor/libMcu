/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file SSD1306_i2c.hpp
 * @brief driver for the SSD1306 OLED display via I2C
 * @todo Change all constexpr formatting function arguments to uint32_t's
 */
#ifndef SSD1306_HPP
#define SSD1306_HPP

#include <cstdint>

namespace libmcudrv::SSD1306 {

constexpr inline std::uint8_t preambleCommand{0x00};         /*!< command preamble */
constexpr inline std::uint8_t preambleData{0x40};            /*!< data preamble */
constexpr inline std::uint8_t cmdSetVcomDeselectLevel{0xDB}; /*!< set Vcom deselect level */
/**
 * @brief format Vcom deselect level
 * @param level Vcom level
 * @return formatted value
 */
constexpr std::uint8_t formatVcomDeselectArg(std::uint32_t level) {
  return static_cast<std::uint8_t>((level & 0x07) << 4);
}
constexpr std::uint8_t setComPinsHardware{0xDA}; /*!< set COM pins hardware configuration */
/**
 * @brief Various common pin mapping modes
 */
enum class comPinMapping : std::uint8_t {
  sequentialNormal = 0x00,
  sequentialRemapped = 0x20,
  alternatingNormal = 0x10,
  alternatingRemapped = 0x30,
};
constexpr std::uint8_t formatComPinsHardwareArg(comPinMapping setting) {
  return 0x02 | static_cast<std::uint8_t>(setting);
}
constexpr std::uint8_t cmdSetDisplayClockDivide{0xD5}; /*!< set display clock divide ratio */
/**
 * @brief format display clock divisor
 * @param ratio division ratio
 * @return formatted value
 */
constexpr std::uint8_t formatDisplayClockDivisor(std::uint8_t ratio) {
  return ratio;
}
constexpr std::uint8_t cmdSetPrechargeLevel{0xD9}; /*!< set precharge level */
constexpr std::uint8_t prechargeLevel(std::uint8_t level) {
  return level;
}
constexpr std::uint8_t cmdSetDisplayOffset{0xD3};
constexpr std::uint8_t displayOffset(std::uint8_t offset) {
  return offset;
}
enum scanDirection : std::uint8_t {
  normalDirection = 0x00,
  remappedDirection = 0x08,
};
constexpr std::uint8_t cmdComOutputScanDirection(scanDirection mode) {
  return mode | 0xC0;
}
constexpr std::uint8_t cmdSetPageStart(std::uint8_t address) {
  return (address & 0x07) | 0xB0;
}
constexpr std::uint8_t cmdDisplayActive{0xAF};     /*!< turn display on */
constexpr std::uint8_t cmdDisplaySleep{0xAE};      /*!< turn display off */
constexpr std::uint8_t cmdSetMultiplexRatio{0xA8}; /*!< multiplex ratio */
constexpr std::uint8_t formatMultiplexRatioArg(std::uint8_t ratio) {
  return ratio;
}
constexpr std::uint8_t cmdDisplayInvert{0xA7}; /*!< invert display */
constexpr std::uint8_t cmdDisplayNormal{0xA6}; /*!< normal display */
constexpr std::uint8_t cmdDisplayRam{0xA5};    /*!< display RAM content */
constexpr std::uint8_t CmdDisplayOn{0xA4};     /*!< turn all pixels on */

enum segmentMapping : std::uint8_t {
  column0 = 0,  /*!< Segment 0 mapped to column address 0 */
  column127 = 1 /*!< Segment 0 mapped to column address 127 */
};
/*!< @brief set segment remapping */
constexpr std::uint8_t cmdSetSegmentRemap(segmentMapping mapping) {
  return mapping | 0xA0;
}
constexpr std::uint8_t setChargePump{0x8D}; /*!< set charge pump state */
constexpr std::uint8_t chargePumpOn(bool pumpOn) {
  if (pumpOn)
    return 0x14;
  else
    return 0x10;
}
constexpr std::uint8_t setContrast{0x81}; /*!< set contrast level */
constexpr std::uint8_t ContrastLevel(std::uint8_t level) {
  return level;
}
constexpr std::uint8_t cmdSetDisplayStartLine(std::uint32_t address) {
  return static_cast<std::uint8_t>((address & 0x3F) | 0x40);
}
constexpr std::uint8_t scrollOn{0x2F};
constexpr std::uint8_t scrollOff{0x2E};
constexpr std::uint8_t cmdSetPageAddress{0x22};
constexpr std::uint8_t cmdSetColumnAddress{0x21};
constexpr std::uint8_t cmdSetMemoryAddressingMode{0x20};

enum class addressingModes : std::uint8_t {
  horizontalMode = 0, /*!< Horizontal addressing mode */
  verticalMode = 1,   /*!< vertical addressing mode */
  pageMode = 2,       /*!< page addressing mode */
  invalidMode = 3,    /*!< INVALID! DO NOT USE! */
};

constexpr std::uint8_t formatAddressingModeArg(addressingModes mode) {
  return static_cast<std::uint8_t>(mode) & 0x03;
}

constexpr std::uint8_t cmdSetHigherColumnAddress(std::uint8_t address) {
  return (address & 0x0F) | 0x10;
}

constexpr std::uint8_t cmdSetLowerColumnAddress(std::uint8_t address) {
  return (address & 0x0F) | 0x00;
}

}  // namespace libmcudrv::SSD1306

#endif