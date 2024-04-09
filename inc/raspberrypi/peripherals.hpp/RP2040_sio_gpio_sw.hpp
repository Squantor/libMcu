/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 SIO GPIO software interface
 */
#ifndef RP2040_SIO_GPIO_SW_HPP
#define RP2040_SIO_GPIO_SW_HPP

namespace libMcuLL {
namespace sw {
namespace sioGpio {
template <libMcuLL::sioBaseAddress const& sioAddress_>
struct sioGpio : libMcuLL::peripheralBase {
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
  static hw::sio::peripheral* sioPeripheral() {
    return reinterpret_cast<hw::sio::peripheral*>(sioAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType sioAddress{sioAddress_}; /**< peripheral address */
};
}  // namespace sioGpio
}  // namespace sw
}  // namespace libMcuLL
#endif