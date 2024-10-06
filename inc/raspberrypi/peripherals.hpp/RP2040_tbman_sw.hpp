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

namespace libMcuLL::tbman {
template <libMcu::tbmanBaseAddress const& tbmanAddress_>
struct tbman : libMcu::peripheralBase {
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
  static libMcuHw::tbman::peripheral* tbmanPeripheral() {
    return reinterpret_cast<libMcuHw::tbman::peripheral*>(tbmanAddress);
  }

 private:
  static constexpr libMcu::hwAddressType tbmanAddress{tbmanAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::tbman
#endif