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
#ifndef RP2040_GPIO_QSPI_LL_HPP
#define RP2040_GPIO_QSPI_LL_HPP

namespace libmcull::gpioQspi {
namespace hardware = libmcuhw::gpio_qspi;
/**
 * @brief
 * @tparam gpio_qspi_address
 */
template <libmcu::IoQspiBaseAddress const& gpio_qspi_address>
struct GpioQspi : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libmcuhw::gpio_qspi::GpioQspi* GetPeripheral() {
    return reinterpret_cast<libmcuhw::gpio_qspi::GpioQspi*>(gpio_qspi_address_);
  }

 private:
  static constexpr libmcu::HwAddressType gpio_qspi_address_ = gpio_qspi_address; /*!< peripheral address */
};  // namespace libmcu::IoQspiBaseAddress
}  // namespace libmcull::gpioQspi
#endif