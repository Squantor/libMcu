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

namespace libMcuLL {
namespace sw {
namespace xipSsi {
template <libMcuLL::xipSsiBaseAddress const& xipSsiAddress_>
struct xipSsi : libMcuLL::peripheralBase {
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
  static hw::xipSsi::peripheral* xipSsiPeripheral() {
    return reinterpret_cast<hw::xipSsi::peripheral*>(xipSsiAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType xipSsiAddress{xipSsiAddress_}; /**< peripheral address */
};
}  // namespace xipSsi
}  // namespace sw
}  // namespace libMcuLL
#endif