/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_busctrl_ll.hpp
 * @brief low level interface for the RP2040 bus controller
 */
#ifndef RP2040_BUSCTRL_SW_HPP
#define RP2040_BUSCTRL_SW_HPP

namespace libMcuLL::busctrl {
namespace hardware = libMcuHw::busctrl;
/**
 * @brief
 * @tparam busctrlAddress_
 */
template <libmcu::busCtrlBaseAddress const& busctrlAddress_>
struct busctrl : libmcu::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::busctrl* busctrlPeripheral() {
    return reinterpret_cast<hardware::busctrl*>(busctrlAddress);
  }

 private:
  static constexpr libmcu::hwAddressType busctrlAddress = busctrlAddress_; /*!< peripheral address */
};
}  // namespace libMcuLL::busctrl
#endif