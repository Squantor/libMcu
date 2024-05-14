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
// template <auto &gpioPeripheral, auto &notEnablePin, auto &A0Pin>
template <auto &gpioPeripheral>
struct mux3to8 {
  void initialize() {
    gpioPeripheral.initialize();
  }

 private:
  // add constraints here
  using peripheralType = std::remove_reference<decltype(gpioPeripheral)>::type;
  // using notEnablePinType = std::remove_reference<decltype(notEnablePin)>::type;
  // using A0PinType = std::remove_reference<decltype(A0Pin)>::type;
  static_assert(std::is_base_of<libMcuHal::halGpioBase, peripheralType>::value, "gpioPeripheral is not a Hal Gpio Class");
  // static_assert(std::is_base_of<libMcu::pinBase, notEnablePinType>::value, "gpioPeripheral is not a Hal Gpio Class");
  // static_assert(std::is_base_of<libMcu::pinBase, A0PinType>::value, "gpioPeripheral is not a Hal Gpio Class");
};
}  // namespace libMcuDriver::mux

#endif