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
template <gpioHalType gpioPeripheral_>
struct mux3to8 {
  void initialize() {
    // gpioPeripheral.output(notEnablePin);
  }

 private:
  static constexpr gpioHalType gpioPeripheral = gpioPeripheral_;
};
}  // namespace libMcuDriver::mux

#endif