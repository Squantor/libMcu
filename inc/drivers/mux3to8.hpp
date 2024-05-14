/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Driver for a 3 to 8 multiplexer, usable for 74138's 4051's and such
 */
#ifndef MUX3TO8_HPP
#define MUX3TO8_HPP

namespace libMcuDriver::mux {

using namespace libMcuHal;
template <auto &gpioPeripheral>
struct mux3to8 {
  void initialize() {
    gpioPeripheral.initialize();
  }

 private:
  // add constraints here
  using peripheralType = std::remove_reference<decltype(gpioPeripheral)>::type;
  // static_assert(std::is_same<libMcuHal::gpio::gpio, peripheralType>::value, "peripheral is not a libMcuHal::gpio");
  static_assert(std::is_base_of<libMcuHal::halGpioBase, peripheralType>::value, "peripheral is not a Hal Gpio Class");
};
}  // namespace libMcuDriver::mux

#endif