/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 PLL software interface
 */
#ifndef RP2040_PLL_SW_HPP
#define RP2040_PLL_SW_HPP

namespace libMcuLL {
namespace sw {
namespace pll {
template <libMcuLL::pllBaseAddress const& pllAddress_>
struct pll : libMcuLL::peripheralBase {
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
  static hw::pll::peripheral* pllPeripheral() {
    return reinterpret_cast<hw::pll::peripheral*>(pllAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType pllAddress = pllAddress_; /**< peripheral address */
};
}  // namespace pll
}  // namespace sw
}  // namespace libMcuLL
#endif