/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_rosc_ll.hpp
 * @brief low level interface for the RP2040 RC oscillator
 */
#ifndef RP2040_ROSC_LL_HPP
#define RP2040_ROSC_LL_HPP

namespace libmcull::rosc {
namespace hardware = libmcuhw::rosc;
/**
 * @brief
 * @tparam rosc_address
 */
template <libmcu::RoscBaseAddress const& rosc_address>
struct Rosc : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Rosc* GetPeripheral() {
    return reinterpret_cast<hardware::Rosc*>(rosc_address_);
  }

 private:
  static constexpr libmcu::HwAddressType rosc_address_ = rosc_address; /*!< peripheral address */
};
}  // namespace libmcull::rosc
#endif