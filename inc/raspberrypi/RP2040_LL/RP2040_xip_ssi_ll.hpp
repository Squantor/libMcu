/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_xip_ssi_ll.hpp
 * @brief low level interface for the RP2040 Execute In Place Serial interface
 */
#ifndef RP2040_XIP_SSI_LL_HPP
#define RP2040_XIP_SSI_LL_HPP

namespace libmcull::xipSsi {
namespace hardware = libmcuhw::xipSsi;
/**
 * @brief
 * @tparam xipssi_address
 */
template <libmcu::XipSsiBaseAddress const& xipssi_address>
struct XipSsi : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::XipSsi* GetPeripheral() {
    return reinterpret_cast<hardware::XipSsi*>(xipssi_address_);
  }

 private:
  static constexpr libmcu::HwAddressType xipssi_address_{xipssi_address}; /*!< peripheral address */
};
}  // namespace libmcull::xipSsi
#endif