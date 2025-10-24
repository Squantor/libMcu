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
#ifndef RP2040_USBCTRL_LL_HPP
#define RP2040_USBCTRL_LL_HPP

namespace libmcull::usbCtrl {
namespace hardware = libmcuhw::usbCtrl;
/**
 * @brief
 * @tparam usbctrl_address
 */
template <libmcu::UsbCtrlRegsBaseAddress const& usbctrl_address>
struct Usbctrl : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::UsbCtrl* GetPeripheral() {
    return reinterpret_cast<hardware::UsbCtrl*>(usbctrl_address_);
  }

 private:
  static constexpr libmcu::HwAddressType usbctrl_address_{usbctrl_address}; /*!< peripheral address */
};
}  // namespace libmcull::usbCtrl
#endif