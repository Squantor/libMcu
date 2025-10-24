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
#ifndef RP2040_PPB_LL_HPP
#define RP2040_PPB_LL_HPP

namespace libmcull::ppb {
namespace hardware = libmcuhw::ppb;
/**
 * @brief
 * @tparam ppbAddress_
 */
template <libmcu::PpbBaseAddress const& ppb_address>
struct Ppb : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Ppb* GetPeripheral() {
    return reinterpret_cast<hardware::Ppb*>(ppb_address_);
  }

 private:
  static constexpr libmcu::HwAddressType ppb_address_ = ppb_address; /*!< peripheral address */
};
}  // namespace libmcull::ppb
#endif