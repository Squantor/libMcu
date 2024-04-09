/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Testbench Manager software interface
 */
#ifndef RP2040_TBMAN_SW_HPP
#define RP2040_TBMAN_SW_HPP

namespace libMcuLL {
namespace sw {
namespace tbman {
template <libMcuLL::tbmanBaseAddress const& tbmanAddress_>
struct tbman : libMcuLL::peripheralBase {
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
  static hw::tbman::peripheral* tbmanPeripheral() {
    return reinterpret_cast<hw::tbman::peripheral*>(tbmanAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType tbmanAddress{tbmanAddress_}; /**< peripheral address */
};
}  // namespace tbman
}  // namespace sw
}  // namespace libMcuLL
#endif