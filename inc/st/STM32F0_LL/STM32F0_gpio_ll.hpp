/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file STM32F0_rcc_ll.hpp
 * @brief STM32F0 Reset and clock control low level code and definitions
 */

#ifndef STM32F0_GPIO_LL_HPP
#define STM32F0_GPIO_LL_HPP

namespace libmcull::gpio {
namespace hardware = libmcuhw::gpio;

template <libmcu::gpioBaseAddress const& gpioAddress_>
struct gpio : libmcu::PeripheralBase {
  template <typename T>
  constexpr void setup(T& pin) {
    // setup peripheral mode
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio::gpio* gpioPeripheral() {
    return reinterpret_cast<libmcuhw::gpio::gpio*>(gpioAddress);
  }

 private:
  static constexpr libmcu::HwAddressType gpioAddress = gpioAddress_; /*!< peripheral address */
};

}  // namespace libmcull::gpio

#endif