/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file SH1106_i2c.hpp
 * @brief driver for the SH1106 OLED display driver via I2C
 * @todo Change all constexpr formatting function arguments to uint32_t's
 */
#ifndef SH1106_HPP
#define SH1106_HPP

#include <cstdint>

namespace libMcuDriver::SH1106 {

constexpr inline std::uint8_t preamble_command{0x00};            /*!< command preamble */
constexpr inline std::uint8_t preamble_data{0x40};               /*!< data preamble */
constexpr inline std::uint8_t cmd_set_vcom_deselect_level{0xDB}; /*!< set Vcom deselect level */
/**
 * @brief format Vcom deselect level argument
 * @param level Vcom level
 * @return formatted value
 */
constexpr std::uint8_t FormatVcomDeselectArg(std::uint32_t level) {
  return static_cast<std::uint8_t>((level & 0x07) << 4);
}
constexpr std::uint8_t cmd_set_com_pins_hardware{0xDA}; /*!< set COM pins hardware configuration */
/**
 * @brief Various common pin mapping modes
 */
enum class comPinMapping : std::uint8_t {
  SequentialNormal = 0x02,
  AlternatingNormal = 0x12,
};
constexpr std::uint8_t FormatComPinsHardwareArg(comPinMapping setting) {
  return static_cast<std::uint8_t>(setting);
}
constexpr std::uint8_t cmd_set_display_clock_divisor{0xD5}; /*!< set display clock divide ratio */
/**
 * @brief format display clock divisor
 * @param ratio division ratio
 * @return formatted value
 */
constexpr std::uint8_t FormatDisplayClockDivisorArg(std::uint8_t ratio) {
  return ratio;
}
constexpr std::uint8_t cmd_set_precharge_level{0xD9}; /*!< set precharge level */
constexpr std::uint8_t FormatPrechargeLevelArg(std::uint8_t level) {
  return level;
}
constexpr std::uint8_t cmd_set_display_offset{0xD3};
constexpr std::uint8_t FormatDisplayOffsetArg(std::uint8_t offset) {
  return offset;
}
enum class scanDirection : std::uint8_t {
  normalDirection = 0x00,
  remappedDirection = 0x08,
};
constexpr std::uint8_t CmdComOutputScanDirection(scanDirection mode) {
  return 0xC0 | static_cast<std::uint8_t>(mode);
}
constexpr std::uint8_t CmdSetPageStart(std::uint8_t address) {
  return (address & 0x07) | 0xB0;
}
constexpr std::uint8_t cmd_set_display_active{0xAF};  /*!< turn display on */
constexpr std::uint8_t cmd_display_sleep{0xAE};       /*!< turn display off */
constexpr std::uint8_t cmd_set_multiplex_ratio{0xA8}; /*!< multiplex ratio */
constexpr std::uint8_t FormatMultiplexRatioArg(std::uint8_t ratio) {
  return ratio;
}
constexpr std::uint8_t cmd_set_display_inverted{0xA7}; /*!< invert display */
constexpr std::uint8_t cmd_set_display_normal{0xA6};   /*!< normal display */
constexpr std::uint8_t cmdDisplayRam{0xA5};            /*!< display RAM content */
constexpr std::uint8_t cmd_set_display_on{0xA4};       /*!< turn all pixels on */

enum segmentMapping : std::uint8_t {
  column0 = 0,  /*!< Segment 0 mapped to column address 0 */
  column127 = 1 /*!< Segment 0 mapped to column address 127 */
};
/*!< @brief set segment remapping */
constexpr std::uint8_t CmdSetSegmentRemap(segmentMapping mapping) {
  return mapping | 0xA0;
}
constexpr std::uint8_t cmd_set_charge_pump{0x8D}; /*!< set charge pump state */
constexpr std::uint8_t FormatChargePumpOnArg(bool pumpOn) {
  if (pumpOn)
    return 0x14;
  else
    return 0x10;
}
constexpr std::uint8_t cmd_set_constrast{0x81}; /*!< set contrast level */
constexpr std::uint8_t FormatContrastLevelArg(std::uint8_t level) {
  return level;
}
constexpr std::uint8_t CmdSetDisplayStartLine(std::uint32_t address) {
  return static_cast<std::uint8_t>((address & 0x3F) | 0x40);
}
constexpr std::uint8_t scrollOn{0x2F};
constexpr std::uint8_t cmd_set_scrolling_off{0x2E};
constexpr std::uint8_t cmdSetPageAddress{0x22};
constexpr std::uint8_t cmdSetColumnAddress{0x21};
constexpr std::uint8_t cmd_set_addressing_mode{0x20};

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

}  // namespace libMcuDriver::SH1106

#endif