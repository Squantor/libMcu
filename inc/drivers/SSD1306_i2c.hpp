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
#ifndef SSD1306_I2C_HPP
#define SSD1306_I2C_HPP

#include "SSD1306/SSD1306.hpp"
#include <span>

namespace libMcuDriver::SSD1306 {
namespace i2c = libMcuLL::i2c;

template <auto &i2cHal, const libMcu::i2cDeviceAddress &i2cAddress, auto &config>
struct SSD1306 {
  constexpr libMcu::results init() {
    return sendCommand(config.initCommands);
  }
  constexpr libMcu::results sendCommand(const std::span<const std::uint8_t> commands) {
    return send(preambleCommand, commands);
  }
  constexpr libMcu::results sendCommand(std::uint8_t command) {
    std::array<std::uint8_t, 1> commands{command};
    return sendCommand(commands);
  }
  constexpr libMcu::results sendCommand(std::uint8_t command, std::uint8_t argument) {
    std::array<std::uint8_t, 2> commands{command, argument};
    return sendCommand(commands);
  }
  constexpr libMcu::results sendData(const std::span<const std::uint8_t> data) {
    return send(preambleData, data);
  }
  constexpr libMcu::results send(std::uint8_t action, const std::span<const std::uint8_t> commands) {
    libMcu::results result;
    result = i2cHal.startMasterWrite(i2cAddress, action);
    if (result != libMcu::results::NO_ERROR)
      goto stopI2C;
    result = i2cHal.continueMasterWrite(commands);
    if (result != libMcu::results::NO_ERROR)
      goto stopI2C;
  stopI2C:
    i2cHal.stopMaster();
    return result;
  }
  constexpr libMcu::results setContrast(std::uint8_t contrast) {
    return sendCommand({setContrast, ContrastLevel(contrast)});
  }
  constexpr libMcu::results setDisplayRam(bool state) {
    if (state == true)
      return sendCommand(cmdDisplayRam);
    else
      return sendCommand(CmdDisplayOn);
  }
  constexpr libMcu::results invertDisplay(bool state) {
    if (state == true)
      return sendCommand(cmdDisplayInvert);
    else
      return sendCommand(cmdDisplayNormal);
  }
  /**
   * @brief Set the Address of the display pointer in page mode
   * @param column column address
   * @param page page address
   * @return constexpr libMcu::results
   */
  constexpr libMcu::results setAddressInPageMode(uint8_t column, uint8_t page) {
    std::array<std::uint8_t, 3> commands{cmdSetPageStart(page), cmdSetLowerColumnAddress(column),
                                         cmdSetHigherColumnAddress(column)};
    return sendCommand(commands);
  }
  constexpr libMcu::results setDisplayStartLine(uint32_t line) {
    return sendCommand(cmdSetDisplayStartLine(line));
  }
  constexpr libMcu::results setColumnAddress(uint32_t start, uint32_t end) {
    std::array<std::uint8_t, 3> commands{cmdSetColumnAddress, static_cast<std::uint8_t>(start), static_cast<std::uint8_t>(end)};
    return sendCommand(commands);
  }
  constexpr libMcu::results setPageAddress(uint32_t start, uint32_t end) {
    std::array<std::uint8_t, 3> commands{cmdSetPageAddress, static_cast<std::uint8_t>(start), static_cast<std::uint8_t>(end)};
    return sendCommand(commands);
  }
};

}  // namespace libMcuDriver::SSD1306

#endif