/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 GPIO QSPI software interface
 */
#ifndef RP2040_GPIO_QSPI_SW_HPP
#define RP2040_GPIO_QSPI_SW_HPP

namespace libMcuLL::gpioQspi {
template <libMcu::ioQspiBaseAddress const& gpioQspiAddress_>
struct gpioQspi : libMcu::peripheralBase {
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
  static libMcuHw::gpioQspi::gpioQspi* gpioQspiPeripheral() {
    return reinterpret_cast<libMcuHw::gpioQspi::gpioQspi*>(gpioQspiAddress);
  }

 private:
  static constexpr libMcu::hwAddressType gpioQspiAddress = gpioQspiAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::gpioQspi
#endif