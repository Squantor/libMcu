/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 System configuration software interface
 */
#ifndef RP2040_SYSCFG_SW_HPP
#define RP2040_SYSCFG_SW_HPP

namespace libMcuLL::syscfg {
template <libMcu::syscfgBaseAddress const& syscfgAddress_>
struct syscfg : libMcu::peripheralBase {
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
  static libMcuHw::syscfg::peripheral* syscfgPeripheral() {
    return reinterpret_cast<libMcuHw::syscfg::peripheral*>(syscfgAddress);
  }

 private:
  static constexpr libMcu::hwAddressType syscfgAddress{syscfgAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::syscfg
#endif