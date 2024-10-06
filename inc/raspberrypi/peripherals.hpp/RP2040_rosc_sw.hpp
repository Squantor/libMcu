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

namespace libMcuLL::rosc {
namespace hardware = libMcuHw::rosc;
template <libMcu::roscBaseAddress const& roscAddress_>
struct rosc : libMcu::peripheralBase {
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
  static constexpr libMcu::hwAddressType roscAddress = roscAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::rosc
#endif