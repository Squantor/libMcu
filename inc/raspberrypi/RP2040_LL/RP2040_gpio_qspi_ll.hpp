/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_gpio_qspi_ll.hpp
 * @brief low level interface for the RP2040 GPIO QSPI
 */
#ifndef RP2040_GPIO_QSPI_SW_HPP
#define RP2040_GPIO_QSPI_SW_HPP

namespace libmcull::gpioQspi {
template <libmcu::IoQspiBaseAddress const& gpioQspiAddress_>
struct gpioQspi : libmcu::PeripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libmcuhw::gpioQspi::gpioQspi* gpioQspiPeripheral() {
    return reinterpret_cast<libmcuhw::gpioQspi::gpioQspi*>(gpioQspiAddress);
  }

 private:
  static constexpr libmcu::HwAddressType gpioQspiAddress = gpioQspiAddress_; /*!< peripheral address */
};
}  // namespace libmcull::gpioQspi
#endif