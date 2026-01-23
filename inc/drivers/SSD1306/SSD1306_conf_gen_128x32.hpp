/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file SSD1306_conf_gen_128x32.hpp
 * @brief SSD1306 configuration for a generic 128 x 32 display
 */
#ifndef SSD1306_CONF_GEN_128X32_HPP
#define SSD1306_CONF_GEN_128X32_HPP

#include <cstdint>
#include <array>
#include <span>

namespace libmcudrv::SSD1306 {

struct generic128x32 {
  static constexpr std::array<const std::uint8_t, 26> initCommands = {cmdDisplaySleep,
                                                                      cmdSetDisplayClockDivide,
                                                                      formatDisplayClockDivisor(0x80),
                                                                      cmdSetMultiplexRatio,
                                                                      formatMultiplexRatioArg(31),
                                                                      cmdSetDisplayOffset,
                                                                      displayOffset(0),
                                                                      cmdSetDisplayStartLine(0),
                                                                      setChargePump,
                                                                      chargePumpOn(true),
                                                                      cmdSetMemoryAddressingMode,
                                                                      formatAddressingModeArg(addressingModes::horizontalMode),
                                                                      cmdSetSegmentRemap(column127),
                                                                      cmdComOutputScanDirection(remappedDirection),
                                                                      setComPinsHardware,
                                                                      formatComPinsHardwareArg(comPinMapping::sequentialNormal),
                                                                      setContrast,
                                                                      ContrastLevel(0x01),
                                                                      cmdSetPrechargeLevel,
                                                                      prechargeLevel(0xF1),
                                                                      cmdSetVcomDeselectLevel,
                                                                      formatVcomDeselectArg(4),
                                                                      CmdDisplayOn,
                                                                      cmdDisplayNormal,
                                                                      scrollOff,
                                                                      cmdDisplayActive};
  static constexpr std::uint8_t xSize{128};
  static constexpr std::uint8_t ySize{32};
};

}  // namespace libmcudrv::SSD1306
#endif