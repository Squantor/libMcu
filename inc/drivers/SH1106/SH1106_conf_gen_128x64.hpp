/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file SH1106_conf_gen_128x64.hpp
 * @brief SH1106 configuration for a generic 128 x 64 display
 */
#ifndef SH1106_CONF_GEN_128X64_HPP
#define SH1106_CONF_GEN_128X64_HPP

namespace libMcuDriver::SH1106 {
/**
 * @brief SH1106 configuration for a generic 128 x 64 display
 */
struct Generic128x64 {
  static constexpr std::array<const std::uint8_t, 26> init_commands = {
    // configuration commands
    cmd_display_sleep,
    cmd_set_display_clock_divisor,
    FormatDisplayClockDivisorArg(0x80),
    cmd_set_multiplex_ratio,
    FormatMultiplexRatioArg(63),
    cmd_set_display_offset,
    FormatDisplayOffsetArg(0),
    CmdSetDisplayStartLine(0),
    FormatSetPageAddress(0),
    FormatSetLowerColumnAddress(0),
    FormatSetHigherColumnAddress(0),
    cmd_set_charge_pump,
    FormatChargePumpOnArg(true),
    CmdSetSegmentRemap(segmentMapping::column127),
    CmdComOutputScanDirection(scanDirection::remappedDirection),
    cmd_set_com_pins_hardware,
    FormatComPinsHardwareArg(comPinMapping::AlternatingNormal),
    cmd_set_constrast,
    FormatContrastLevelArg(0x10),
    cmd_set_precharge_level,
    FormatPrechargeLevelArg(0xF1),
    cmd_set_vcom_deselect_level,
    FormatVcomDeselectArg(4),
    cmd_set_display_on,
    cmd_set_display_normal,
    cmd_set_display_active};

  static constexpr std::uint8_t size_x{128};                            /*!< width of display */
  static constexpr std::uint8_t size_y{64};                             /*!< height of display */
  static constexpr std::uint8_t size_pages{8};                          /*!< number of pages */
  static constexpr std::size_t size_framebuffer{(size_x * size_y) / 8}; /*!< size of framebuffer */
};

}  // namespace libMcuDriver::SH1106
#endif