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
/**
 * @brief
 * @tparam gpio_address
 */
template <libmcull::GpioBaseAddress const& gpio_address>
struct Gpio : libmcull::PeripheralBase {
  template <typename T>
  constexpr void setup(T& pin) {
    // setup peripheral mode
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio::Gpio* gpioPeripheral() {
    return reinterpret_cast<libmcuhw::gpio::Gpio*>(gpio_address_);
  }

 private:
  static constexpr libmcu::HwAddressType gpio_address_ = gpio_address; /*!< peripheral address */
};

}  // namespace libmcull::gpio

#endif