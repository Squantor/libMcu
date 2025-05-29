/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_ppb_ll.hpp
 * @brief low level interface for the RP2040 PPB
 */
#ifndef RP2040_PPB_SW_HPP
#define RP2040_PPB_SW_HPP

namespace libmcull::ppb {
namespace hardware = libmcuhw::ppb;
/**
 * @brief
 * @tparam ppbAddress_
 */
template <libmcu::PpbBaseAddress const& ppbAddress_>
struct ppb : libmcu::PeripheralBase {
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
  static hardware::ppb* ppbPeripheral() {
    return reinterpret_cast<hardware::ppb*>(ppbAddress);
  }

 private:
  static constexpr libmcu::HwAddressType ppbAddress = ppbAddress_; /*!< peripheral address */
};
}  // namespace libmcull::ppb
#endif