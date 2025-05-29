/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_xip_ctrl_ll.hpp
 * @brief low level interface for the RP2040 Execute In Place
 */
#ifndef RP2040_XIP_CTRL_SW_HPP
#define RP2040_XIP_CTRL_SW_HPP

namespace libmcull::xip {
namespace hardware = libmcuhw::xip;
template <libmcu::XipCtrlBaseAddress const& xipCtrlAddress_>
struct xipCtrl : libmcu::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::xip* xipCtrlPeripheral() {
    return reinterpret_cast<hardware::xip*>(xipCtrlAddress);
  }

 private:
  static constexpr libmcu::HwAddressType xipCtrlAddress{xipCtrlAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::xip
#endif