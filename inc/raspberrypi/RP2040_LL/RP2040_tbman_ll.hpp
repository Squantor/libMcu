/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_tbman_ll.hpp
 * @brief low level interface for the RP2040 Testbench Manager
 */
#ifndef RP2040_TBMAN_LL_HPP
#define RP2040_TBMAN_LL_HPP

namespace libmcull::tbman {
namespace hardware = libmcuhw::tbman;
/**
 * @brief
 * @tparam tbman_address
 */
template <libmcu::TbmanBaseAddress const& tbman_address>
struct Tbman : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Tbman* GetPeripheral() {
    return reinterpret_cast<hardware::Tbman*>(tbman_address_);
  }

 private:
  static constexpr libmcu::HwAddressType tbman_address_{tbman_address}; /*!< peripheral address */
};
}  // namespace libmcull::tbman
#endif