/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 SPI HAL
 */
#ifndef RP2040_HAL_SPI
#define RP2040_HAL_SPI

namespace libMcuHal::spi {

template <libMcu::spiBaseAddress const& spiBaseAddress_>
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
  static libMcuHw::gpioBank0::gpioBank0* gpioBank0Peripheral() {
    return reinterpret_cast<libMcuHw::gpioBank0::gpioBank0*>(spiBaseAddress + libMcuHw::peripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::gpioBank0::gpioBank0* gpioBank0PeripheralSet() {
    return reinterpret_cast<libMcuHw::gpioBank0::gpioBank0*>(spiBaseAddress + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::gpioBank0::gpioBank0* gpioBank0PeripheralClear() {
    return reinterpret_cast<libMcuHw::gpioBank0::gpioBank0*>(spiBaseAddress + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::gpioBank0::gpioBank0* gpioBank0PeripheralToggle() {
    return reinterpret_cast<libMcuHw::gpioBank0::gpioBank0*>(spiBaseAddress + libMcuHw::peripheralOffsetXor);
  }

  static constexpr libMcu::hwAddressType spiBaseAddress = spiBaseAddress_; /**< spi peripheral address */
};
}  // namespace libMcuHal::spi

#endif