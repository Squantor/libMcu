/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Execute In Place Serial interface software interface
 */
#ifndef RP2040_XIP_SSI_SW_HPP
#define RP2040_XIP_SSI_SW_HPP

namespace libMcuLL::xipSsi {
namespace hardware = libMcuHw::xipSsi;
template <libMcu::xipSsiBaseAddress const& xipSsiAddress_>
struct xipSsi : libMcu::peripheralBase {
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
  static constexpr libMcu::hwAddressType xipSsiAddress{xipSsiAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::xipSsi
#endif