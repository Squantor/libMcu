/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file SSD1306_conf_gen_128x64.hpp
 * @brief SSD1306 configuration for a generic 128 x 64 display
 */
#ifndef SSD1306_CONF_GEN_128X64_HPP
#define SSD1306_CONF_GEN_128X64_HPP

#include <cstdint>
#include <array>
#include <span>

namespace libMcuDriver::SSD1306 {

struct generic128x64 {
  static constexpr std::array<const std::uint8_t, 26> initCommands = {displaySleep,
                                                                      setDisplayClockDivide,
                                                                      displayClockDivisor(0x80),
                                                                      setMultiplexRatio,
                                                                      multiplexRatio(63),
                                                                      setDisplayOffset,
                                                                      displayOffset(0),
                                                                      setDisplayStartLine(0),
                                                                      setChargePump,
                                                                      chargePumpOn(true),
                                                                      setMemoryAddressingMode,
                                                                      AddressingMode(horizontalMode),
                                                                      setSegmentRemap(column127),
                                                                      comOutputScanDirection(remappedDirection),
                                                                      setComPinsHardware,
                                                                      ComPinsHardware(alternatingNormal),
                                                                      setContrast,
                                                                      ContrastLevel(0x01),
                                                                      setPrechargeLevel,
                                                                      prechargeLevel(0xF1),
                                                                      setVcomDeselectLevel,
                                                                      vcomDeselectLevel(4),
                                                                      displayOn,
                                                                      displayNormal,
                                                                      scrollOff,
                                                                      displayActive};

  static constexpr std::uint8_t xSize{128};
  static constexpr std::uint8_t ySize{64};
};

}  // namespace libMcuDriver::SSD1306
#endif