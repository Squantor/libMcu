/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 SPI GPIO software interface
 */
#ifndef RP2040_SPI_SW_HPP
#define RP2040_SPI_SW_HPP

namespace libMcuLL {
namespace sw {
namespace spi {
template <libMcuLL::spiBaseAddress const& spiAddress_>
struct spi : libMcuLL::peripheralBase {
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
  static hw::spi::peripheral* spiPeripheral() {
    return reinterpret_cast<hw::spi::peripheral*>(spiAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType spiAddress{spiAddress_}; /**< peripheral address */
};
}  // namespace spi
}  // namespace sw
}  // namespace libMcuLL
#endif