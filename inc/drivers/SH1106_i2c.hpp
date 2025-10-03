/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file SH1106_i2c.hpp
 * @brief driver for the SH1106 OLED display driver via I2C
 */
#ifndef SH1106_I2C_HPP
#define SH1106_I2C_HPP

#include "SH1106/SH1106.hpp"

namespace libMcuDriver::SH1106 {

/**
 * @brief
 * @todo i2chal template parameter needs check with a concept
 * @todo porting from SSD1306 needs to be completed
 * @tparam &i2cHal
 * @tparam &i2cAddress
 * @tparam &config
 */
template <auto &i2cHal, const libmcuhal::I2cDeviceAddress &i2cAddress, auto &config>
struct SH1106 {
  /**
   * @brief
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results init() {
    return sendCommand(config.initCommands);
  }
  /**
   * @brief Get the Xsize object
   * @return constexpr std::uint32_t
   */
  constexpr std::uint32_t getXsize() {
    return config.xSize;
  }
  /**
   * @brief Get the Ysize object
   * @return constexpr std::uint32_t
   */
  constexpr std::uint32_t getYsize() {
    return config.ySize;
  }
  /**
   * @brief
   * @param commands
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results sendCommand(const std::span<const std::uint8_t> commands) {
    return send(preamble_command, commands);
  }
  /**
   * @brief
   * @param command
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results sendCommand(std::uint8_t command) {
    std::array<std::uint8_t, 1> commands{command};
    return sendCommand(commands);
  }
  /**
   * @brief
   * @param command
   * @param argument
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results sendCommand(std::uint8_t command, std::uint8_t argument) {
    std::array<std::uint8_t, 2> commands{command, argument};
    return sendCommand(commands);
  }
  /**
   * @brief
   * @param data
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results sendData(const std::span<const std::uint8_t> data) {
    return send(preamble_data, data);
  }
  /**
   * @brief
   * @param action
   * @param commands
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results send(std::uint8_t action, const std::span<const std::uint8_t> commands) {
    libmcu::Results result;
    // result = i2cHal.startMasterWrite(i2cAddress, action);
    if (result != libmcu::Results::NoError)
      goto stopI2C;
    // result = i2cHal.continueMasterWrite(commands);
    if (result != libmcu::Results::NoError)
      goto stopI2C;
  stopI2C:
    // i2cHal.stopMaster();
    return result;
  }
  /**
   * @brief Set the display contrast value
   * @param contrast contrast value from 1 to 255
   * @return status of I2C transaction
   */
  constexpr libmcu::Results contrast(std::uint8_t value) {
    return sendCommand(cmd_set_constrast, FormatContrastLevelArg(value));
  }
  /**
   * @brief Set the Display Ram object
   * @param state
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results setDisplayRam(bool state) {
    if (state == true)
      return sendCommand(cmdDisplayRam);
    else
      return sendCommand(cmd_set_display_on);
  }
  /**
   * @brief Invert the display
   * @param state
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results invertDisplay(bool state) {
    if (state == true)
      return sendCommand(cmd_set_display_inverted);
    else
      return sendCommand(cmd_set_display_normal);
  }
  /**
   * @brief Set the Address of the display pointer in page mode
   * @param column column address
   * @param page page address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results setAddressInPageMode(uint8_t column, uint8_t page) {
    std::array<std::uint8_t, 3> commands{CmdSetPageStart(page), cmdSetLowerColumnAddress(column),
                                         cmdSetHigherColumnAddress(column)};
    return sendCommand(commands);
  }
  /**
   * @brief Set the Display Start Line object
   * @param line
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results setDisplayStartLine(uint32_t line) {
    return sendCommand(CmdSetDisplayStartLine(line));
  }
  /**
   * @brief Set the Column Address object
   * @param start
   * @param end
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results setColumnAddress(uint32_t start, uint32_t end) {
    std::array<std::uint8_t, 3> commands{cmdSetColumnAddress, static_cast<std::uint8_t>(start), static_cast<std::uint8_t>(end)};
    return sendCommand(commands);
  }
  /**
   * @brief Set the Page Address object
   * @param start
   * @param end
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results setPageAddress(uint32_t start, uint32_t end) {
    std::array<std::uint8_t, 3> commands{cmdSetPageAddress, static_cast<std::uint8_t>(start), static_cast<std::uint8_t>(end)};
    return sendCommand(commands);
  }
};

}  // namespace libMcuDriver::SH1106

#endif