/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Execute In Place control software interface
 */
#ifndef RP2040_XIP_CTRL_SW_HPP
#define RP2040_XIP_CTRL_SW_HPP

namespace libMcuLL::xip {
template <libMcu::xipCtrlBaseAddress const& xipCtrlAddress_>
struct xipCtrl : libMcu::peripheralBase {
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
  static libMcuHw::xip::peripheral* xipCtrlPeripheral() {
    return reinterpret_cast<libMcuHw::xip::peripheral*>(xipCtrlAddress);
  }

 private:
  static constexpr libMcu::hwAddressType xipCtrlAddress{xipCtrlAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::xip
#endif