/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 PPB software interface
 */
#ifndef RP2040_PPB_SW_HPP
#define RP2040_PPB_SW_HPP

namespace libMcuLL::sw::ppb {
template <libMcuLL::ppbBaseAddress const& ppbAddress_>
struct ppb : libMcuLL::peripheralBase {
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
  static hw::ppb::peripheral* ppbPeripheral() {
    return reinterpret_cast<hw::ppb::peripheral*>(ppbAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType ppbAddress = ppbAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::ppb
#endif