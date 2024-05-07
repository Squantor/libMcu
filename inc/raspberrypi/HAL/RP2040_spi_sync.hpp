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
using namespace libMcuLL;

template <spiBaseAddress const& spiBaseAddress_>
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
  static hw::gpioBank0::peripheral* gpioBank0Peripheral() {
    return reinterpret_cast<hw::gpioBank0::peripheral*>(spiBaseAddress + libMcuLL::hw::peripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::gpioBank0::peripheral* gpioBank0PeripheralSet() {
    return reinterpret_cast<hw::gpioBank0::peripheral*>(spiBaseAddress + libMcuLL::hw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::gpioBank0::peripheral* gpioBank0PeripheralClear() {
    return reinterpret_cast<hw::gpioBank0::peripheral*>(spiBaseAddress + libMcuLL::hw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::gpioBank0::peripheral* gpioBank0PeripheralToggle() {
    return reinterpret_cast<hw::gpioBank0::peripheral*>(spiBaseAddress + libMcuLL::hw::peripheralOffsetXor);
  }

  static constexpr hwAddressType spiBaseAddress = spiBaseAddress_; /**< spi peripheral address */
};
}  // namespace libMcuHal::spi

#endif