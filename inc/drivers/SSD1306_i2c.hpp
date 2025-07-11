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
namespace i2c = libmcull::i2c;

template <auto &i2cHal, const libmcu::i2cDeviceAddress &i2cAddress, auto &config>
struct SSD1306 {
  constexpr libmcu::Results init() {
    return sendCommand(config.initCommands);
  }
  constexpr std::uint32_t getXsize() {
    return config.xSize;
  }
  constexpr std::uint32_t getYsize() {
    return config.ySize;
  }
  constexpr libmcu::Results sendCommand(const std::span<const std::uint8_t> commands) {
    return send(preambleCommand, commands);
  }
  constexpr libmcu::Results sendCommand(std::uint8_t command) {
    std::array<std::uint8_t, 1> commands{command};
    return sendCommand(commands);
  }
  constexpr libmcu::Results sendCommand(std::uint8_t command, std::uint8_t argument) {
    std::array<std::uint8_t, 2> commands{command, argument};
    return sendCommand(commands);
  }
  constexpr libmcu::Results sendData(const std::span<const std::uint8_t> data) {
    return send(preambleData, data);
  }
  constexpr libmcu::Results send(std::uint8_t action, const std::span<const std::uint8_t> commands) {
    libmcu::Results result;
    result = i2cHal.startMasterWrite(i2cAddress, action);
    if (result != libmcu::Results::NoError)
      goto stopI2C;
    result = i2cHal.continueMasterWrite(commands);
    if (result != libmcu::Results::NoError)
      goto stopI2C;
  stopI2C:
    i2cHal.stopMaster();
    return result;
  }
  /**
   * @brief Set the display contrast value
   * @param contrast contrast value from 1 to 255
   * @return status of I2C transaction
   */
  constexpr libmcu::Results contrast(std::uint8_t value) {
    return sendCommand(setContrast, ContrastLevel(value));
  }
  constexpr libmcu::Results setDisplayRam(bool state) {
    if (state == true)
      return sendCommand(cmdDisplayRam);
    else
      return sendCommand(CmdDisplayOn);
  }
  constexpr libmcu::Results invertDisplay(bool state) {
    if (state == true)
      return sendCommand(cmdDisplayInvert);
    else
      return sendCommand(cmdDisplayNormal);
  }
  /**
   * @brief Set the Address of the display pointer in page mode
   * @param column column address
   * @param page page address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results setAddressInPageMode(uint8_t column, uint8_t page) {
    std::array<std::uint8_t, 3> commands{cmdSetPageStart(page), cmdSetLowerColumnAddress(column),
                                         cmdSetHigherColumnAddress(column)};
    return sendCommand(commands);
  }
  constexpr libmcu::Results setDisplayStartLine(uint32_t line) {
    return sendCommand(cmdSetDisplayStartLine(line));
  }
  constexpr libmcu::Results setColumnAddress(uint32_t start, uint32_t end) {
    std::array<std::uint8_t, 3> commands{cmdSetColumnAddress, static_cast<std::uint8_t>(start), static_cast<std::uint8_t>(end)};
    return sendCommand(commands);
  }
  constexpr libmcu::Results setPageAddress(uint32_t start, uint32_t end) {
    std::array<std::uint8_t, 3> commands{cmdSetPageAddress, static_cast<std::uint8_t>(start), static_cast<std::uint8_t>(end)};
    return sendCommand(commands);
  }
};

}  // namespace libMcuDriver::SSD1306

#endif