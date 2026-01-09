/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file PCF8574.hpp
 * @brief driver for the PCF8574 I2C expander
 */
#ifndef PCF8574_HPP
#define PCF8574_HPP

#include "../libmcu/libmcudriver.hpp"

namespace libMcuDriver::PCF8574 {
/**
 * @brief PCF8574 driver
 * @todo i2chal template parameter needs check with a concept
 * @tparam i2c_hal I2C hal to be used
 * @tparam i2c_address I2C address the port expander is connected to
 */
template <auto &i2c_hal, const libmcu::I2cDeviceAddress &i2c_address>
struct PCF8574 : public libmcu::NonBlocking {
  /**
   * @brief
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results Init() {
    // read out port expander to clear the interrupt and update internal state
    i2c_hal.Receive(i2c_address, pin_state);
    return libmcu::Results::NoError;
  }
  // todo, register for pin change callback
  /**
   * @brief
   */
  constexpr void Progress(void) override {}
  /**
   * @brief
   */
  constexpr void Callback(void) override {}

 private:
  // todo: current pin state
  std::array<std::uint8_t, 1> pin_state;
};
}  // namespace libMcuDriver::PCF8574

#endif