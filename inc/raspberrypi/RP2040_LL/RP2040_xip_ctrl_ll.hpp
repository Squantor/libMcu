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
#ifndef RP2040_XIP_CTRL_LL_HPP
#define RP2040_XIP_CTRL_LL_HPP

namespace libmcull::xip {
namespace hardware = libmcuhw::xip;
/**
 * @brief
 * @tparam xipctrl_address
 */
template <libmcu::XipCtrlBaseAddress const& xipctrl_address>
struct XipCtrl : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Xip* GetPeripheral() {
    return reinterpret_cast<hardware::Xip*>(xipctrl_address_);
  }

 private:
  static constexpr libmcu::HwAddressType xipctrl_address_{xipctrl_address}; /*!< peripheral address */
};
}  // namespace libmcull::xip
#endif