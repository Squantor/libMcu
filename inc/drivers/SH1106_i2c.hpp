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

#include "../libmcu/libmcudriver.hpp"
#include "SH1106/SH1106.hpp"

namespace libMcuDriver::SH1106 {

/**
 * @brief
 * @todo i2chal template parameter needs check with a concept
 * @todo porting from SSD1306 needs to be completed
 * @tparam &i2c_hal
 * @tparam &i2c_address
 * @tparam &config
 */
template <auto &i2c_hal, const libmcu::I2cDeviceAddress &i2c_address, auto &config>
struct SH1106 : public Display {
  /**
   * @brief
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results Init() {
    state = libmcu::States::Initializing;
    return SendCommand(config.initCommands, this);
  }
  /**
   * @brief Get the Xsize object
   * @return constexpr std::uint32_t
   */
  constexpr std::uint32_t GetXsize() {
    return config.xSize;
  }
  /**
   * @brief Get the Ysize object
   * @return constexpr std::uint32_t
   */
  constexpr std::uint32_t GetYsize() {
    return config.ySize;
  }
  /**
   * @brief
   * @param commands
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SendCommand(const std::span<const std::uint8_t> commands, AsyncInterface *callback = nullptr) {
    return Send(preamble_command, commands, callback);
  }
  /**
   * @brief
   * @param command
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SendCommand(std::uint8_t command) {
    std::array<std::uint8_t, 1> commands{command};
    return SendCommand(commands);
  }
  /**
   * @brief
   * @param command
   * @param argument
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SendCommand(std::uint8_t command, std::uint8_t argument) {
    std::array<std::uint8_t, 2> commands{command, argument};
    return SendCommand(commands);
  }
  /**
   * @brief
   * @param data
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SendData(const std::span<const std::uint8_t> data) {
    return Send(preamble_data, data);
  }
  /**
   * @brief
   * @param action
   * @param commands
   * @param callback Callback to execute when Send is done
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results Send(std::uint8_t action, const std::span<const std::uint8_t> commands,
                                 AsyncInterface *callback = nullptr) {
    libmcu::Results result;
    libmcu::AsyncHandle handle;
    (void)callback;
    result = i2c_hal.Claim(handle);
    if (result != libmcu::Results::Claimed)
      goto claim_fail;
    command_buffer[0] = action;

    result = i2c_hal.StartMasterTransmit(handle, i2c_address, std::span<std::uint8_t>(command_buffer.begin(), 1));
    if (result != libmcu::Results::NoError)
      goto stopI2C;

    result = i2c_hal.ContinueMasterTransmit(handle, commands);
    if (result != libmcu::Results::NoError)
      goto stopI2C;

  stopI2C:
    i2c_hal.StopMaster(handle, this);
    i2c_hal.Unclaim(handle);
  claim_fail:
    return result;
  }
  /**
   * @brief Set the display contrast value
   * @param contrast contrast value from 1 to 255
   * @return status of I2C transaction
   */
  constexpr libmcu::Results Contrast(std::uint8_t value) {
    return SendCommand(cmd_set_constrast, FormatContrastLevelArg(value));
  }
  /**
   * @brief Set the Display Ram object
   * @param state
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SetDisplayRam(bool state) {
    if (state == true)
      return SendCommand(cmdDisplayRam);
    else
      return SendCommand(cmd_set_display_on);
  }
  /**
   * @brief Invert the display
   * @param state
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results InvertDisplay(bool state) {
    if (state == true)
      return SendCommand(cmd_set_display_inverted);
    else
      return SendCommand(cmd_set_display_normal);
  }
  /**
   * @brief Set the Address of the display pointer in page mode
   * @param column column address
   * @param page page address
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SetAddressInPageMode(uint8_t column, uint8_t page) {
    std::array<std::uint8_t, 3> commands{CmdSetPageStart(page), cmdSetLowerColumnAddress(column),
                                         cmdSetHigherColumnAddress(column)};
    return SendCommand(commands);
  }
  /**
   * @brief Set the Display Start Line object
   * @param line
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SetDisplayStartLine(uint32_t line) {
    return SendCommand(CmdSetDisplayStartLine(line));
  }
  /**
   * @brief Set the Column Address object
   * @param start
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SetColumnAddress(uint32_t start, uint32_t end) {
    std::array<std::uint8_t, 3> commands{cmdSetColumnAddress, static_cast<std::uint8_t>(start), static_cast<std::uint8_t>(end)};
    return SendCommand(commands);
  }
  /**
   * @brief Set the Page Address object
   * @param start
   * @param end
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results SetPageAddress(uint32_t start, uint32_t end) {
    std::array<std::uint8_t, 3> commands{cmdSetPageAddress, static_cast<std::uint8_t>(start), static_cast<std::uint8_t>(end)};
    return SendCommand(commands);
  }
  /**
   * @brief
   */
  constexpr void Progress(void) override {}
  /**
   * @brief Callback method
   * Called from I2C HAL
   */
  constexpr void Callback(void) override {
    switch (state) {
      case libmcu::States::Initializing:
        // we get callback from the I2C HAL driver
        // todo check error status
        state = libmcu::States::Idle;
        break;
      default:
        // should not happen
        break;
    }
  }

 private:
  libmcu::States state = libmcu::States::Initializing;
  std::array<std::uint8_t, 4> command_buffer;
};

}  // namespace libMcuDriver::SH1106

#endif