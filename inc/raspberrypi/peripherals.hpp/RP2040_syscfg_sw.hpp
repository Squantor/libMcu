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

namespace libMcuLL {
namespace sw {
namespace syscfg {
template <libMcuLL::syscfgBaseAddress const& syscfgAddress_>
struct syscfg : libMcuLL::peripheralBase {
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
  static hw::syscfg::peripheral* syscfgPeripheral() {
    return reinterpret_cast<hw::syscfg::peripheral*>(syscfgAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType syscfgAddress{syscfgAddress_}; /**< peripheral address */
};
}  // namespace syscfg
}  // namespace sw
}  // namespace libMcuLL
#endif