/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file  RP2040_hal_spi.hpp
 * @brief HAL library for synchronous RP2040 SPI
 */
#ifndef RP2040_HAL_SPI
#define RP2040_HAL_SPI

namespace libmcuhal::spi {

template <libmcu::spiBaseAddress const& spiBaseAddress_>
struct spi {
  /**
   * @brief Initialize the spi HAL
   */
  void initialize() {}

 private:
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libmcuhw::gpioBank0::gpioBank0* gpioBank0Peripheral() {
    return reinterpret_cast<libmcuhw::gpioBank0::gpioBank0*>(spiBaseAddress + libmcuhw::peripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libmcuhw::gpioBank0::gpioBank0* gpioBank0PeripheralSet() {
    return reinterpret_cast<libmcuhw::gpioBank0::gpioBank0*>(spiBaseAddress + libmcuhw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libmcuhw::gpioBank0::gpioBank0* gpioBank0PeripheralClear() {
    return reinterpret_cast<libmcuhw::gpioBank0::gpioBank0*>(spiBaseAddress + libmcuhw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libmcuhw::gpioBank0::gpioBank0* gpioBank0PeripheralToggle() {
    return reinterpret_cast<libmcuhw::gpioBank0::gpioBank0*>(spiBaseAddress + libmcuhw::peripheralOffsetXor);
  }

  static constexpr libmcu::hwAddressType spiBaseAddress = spiBaseAddress_; /*!< spi peripheral address */
};
}  // namespace libmcuhal::spi

#endif