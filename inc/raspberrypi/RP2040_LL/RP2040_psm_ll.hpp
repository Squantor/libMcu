/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_psm_ll.hpp
 * @brief low level interface for the RP2040 PSM
 */
#ifndef RP2040_PSM_LL_HPP
#define RP2040_PSM_LL_HPP

namespace libmcull::psm {
namespace hardware = libmcuhw::psm;
/**
 * @brief
 * @tparam psm_address
 */
template <libmcu::PsmBaseAddress const& psm_address>
struct Psm : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Psm* GetPeripheral() {
    return reinterpret_cast<hardware::Psm*>(psm_address_);
  }

 private:
  static constexpr libmcu::HwAddressType psm_address_{psm_address}; /*!< peripheral address */
};
}  // namespace libmcull::psm
#endif