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
  constexpr libMcu::results sendCommand(std::span<const std::uint8_t> commands) {
    return send(preambleCommand, commands);
  }
  constexpr libMcu::results sendData(std::span<const std::uint8_t> data) {
    return send(preambleData, data);
  }
  constexpr libMcu::results send(std::uint8_t action, std::span<const std::uint8_t> commands) {
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
};

}  // namespace libMcuDriver::SSD1306

#endif