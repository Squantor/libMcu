/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 XOSC software interface
 */
#ifndef RP2040_XOSC_SW_HPP
#define RP2040_XOSC_SW_HPP

namespace libMcuLL {
namespace sw {
namespace xosc {
template <libMcuLL::xoscBaseAddress const& xoscAddress_>
struct xosc : libMcuLL::peripheralBase {
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
  static hw::xosc::peripheral* xoscPeripheral() {
    return reinterpret_cast<hw::xosc::peripheral*>(xoscAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType xoscAddress = xoscAddress_; /**< peripheral address */
};
}  // namespace xosc
}  // namespace sw
}  // namespace libMcuLL
#endif