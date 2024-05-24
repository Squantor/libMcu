/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Bus control software interface
 */
#ifndef RP2040_BUSCTRL_SW_HPP
#define RP2040_BUSCTRL_SW_HPP

namespace libMcuLL::sw::busctrl {
template <libMcuLL::busCtrlBaseAddress const& busctrlAddress_>
struct busctrl : libMcuLL::peripheralBase {
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
  static hw::busctrl::peripheral* busctrlPeripheral() {
    return reinterpret_cast<hw::busctrl::peripheral*>(busctrlAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType busctrlAddress = busctrlAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::busctrl
#endif