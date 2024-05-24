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

namespace libMcuLL::sw::gpioQspi {
template <libMcuLL::ioQspiBaseAddress const& gpioQspiAddress_>
struct gpioQspi : libMcuLL::peripheralBase {
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
  static hw::gpioQspi::peripheral* gpioQspiPeripheral() {
    return reinterpret_cast<hw::gpioQspi::peripheral*>(gpioQspiAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType gpioQspiAddress = gpioQspiAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::gpioQspi
#endif