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
#ifndef RP2040_ROSC_SW_HPP
#define RP2040_ROSC_SW_HPP

namespace libmcull::rosc {
namespace hardware = libmcuhw::rosc;
template <libmcu::RoscBaseAddress const& roscAddress_>
struct rosc : libmcull::PeripheralBase {
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
  static hardware::rosc* roscPeripheral() {
    return reinterpret_cast<hardware::rosc*>(roscAddress);
  }

 private:
  static constexpr libmcu::HwAddressType roscAddress = roscAddress_; /*!< peripheral address */
};
}  // namespace libmcull::rosc
#endif