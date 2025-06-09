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
#ifndef RP2040_BUSCTRL_LL_HPP
#define RP2040_BUSCTRL_LL_HPP

namespace libmcull::busctrl {
namespace hardware = libmcuhw::busctrl;
/**
 * @brief
 * @tparam busctrl_address
 */
template <libmcu::BusCtrlBaseAddress const& busctrl_address>
struct Busctrl : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::BusCtrl* GetPeripheral() {
    return reinterpret_cast<hardware::BusCtrl*>(busctrl_address_);
  }

 private:
  static constexpr libmcu::HwAddressType busctrl_address_ = busctrl_address; /*!< peripheral address */
};
}  // namespace libmcull::busctrl
#endif