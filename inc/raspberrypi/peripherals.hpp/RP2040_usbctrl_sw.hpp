/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 USB software interface
 */
#ifndef RP2040_USBCTRL_SW_HPP
#define RP2040_USBCTRL_SW_HPP

namespace libMcuLL::sw::usbctrl {
template <libMcuLL::usbCtrlRegsBaseAddress const& usbctrlAddress_>
struct usbctrl : libMcuLL::peripheralBase {
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
  static hw::usbCtrl::peripheral* usbctrlPeripheral() {
    return reinterpret_cast<hw::usbCtrl::peripheral*>(usbctrlAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType usbctrlAddress{usbctrlAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sw::usbctrl
#endif