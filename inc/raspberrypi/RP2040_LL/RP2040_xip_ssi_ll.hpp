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
#ifndef RP2040_XIP_SSI_SW_HPP
#define RP2040_XIP_SSI_SW_HPP

namespace libmcull::xipSsi {
namespace hardware = libmcuhw::xipSsi;
template <libmcu::XipSsiBaseAddress const& xipSsiAddress_>
struct xipSsi : libmcu::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::xipSsi* xipSsiPeripheral() {
    return reinterpret_cast<hardware::xipSsi*>(xipSsiAddress);
  }

 private:
  static constexpr libmcu::HwAddressType xipSsiAddress{xipSsiAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::xipSsi
#endif