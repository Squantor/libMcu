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

namespace libMcuLL::usbCtrl {
namespace hardware = libMcuHw::usbCtrl;
template <libMcu::usbCtrlRegsBaseAddress const& usbctrlAddress_>
struct usbctrl : libMcu::peripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::usbCtrl* usbctrlPeripheral() {
    return reinterpret_cast<hardware::usbCtrl*>(usbctrlAddress);
  }

 private:
  static constexpr libMcu::hwAddressType usbctrlAddress{usbctrlAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::usbCtrl
#endif