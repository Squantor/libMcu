/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file STM32F0_rcc_ll.hpp
 * \brief STM32F0 Reset and clock control low level code and definitions
 */

#ifndef STM32F0_GPIO_LL_HPP
#define STM32F0_GPIO_LL_HPP

namespace libMcuLL::gpio {
namespace hardware = libMcuHw::gpio;

template <libMcu::gpioBaseAddress const& gpioAddress_>
struct gpio : libMcu::PeripheralBase {
  template <typename T>
  constexpr void setup(T& pin) {
    // setup peripheral mode
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libMcuHw::gpio::gpio* gpioPeripheral() {
    return reinterpret_cast<libMcuHw::gpio::gpio*>(gpioAddress);
  }

 private:
  static constexpr libMcu::hwAddressType gpioAddress = gpioAddress_; /*!< peripheral address */
};

}  // namespace libMcuLL::gpio

#endif