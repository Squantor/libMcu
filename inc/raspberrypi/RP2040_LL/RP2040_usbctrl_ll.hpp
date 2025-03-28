/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_usbctrl_ll.hpp
 * @brief low level interface for the RP2040 USB
 */
#ifndef RP2040_USBCTRL_SW_HPP
#define RP2040_USBCTRL_SW_HPP

namespace libmcull::usbCtrl {
namespace hardware = libmcuhw::usbCtrl;
template <libmcu::usbCtrlRegsBaseAddress const& usbctrlAddress_>
struct usbctrl : libmcu::PeripheralBase {
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
  static constexpr libmcu::hwAddressType usbctrlAddress{usbctrlAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::usbCtrl
#endif