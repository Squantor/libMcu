/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 ROSC software interface
 */
#ifndef RP2040_ROSC_SW_HPP
#define RP2040_ROSC_SW_HPP

namespace libMcuLL::sw::rosc {
template <libMcuLL::roscBaseAddress const& roscAddress_>
struct rosc : libMcuLL::peripheralBase {
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
  static hw::rosc::peripheral* roscPeripheral() {
    return reinterpret_cast<hw::rosc::peripheral*>(roscAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType roscAddress = roscAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::rosc
#endif