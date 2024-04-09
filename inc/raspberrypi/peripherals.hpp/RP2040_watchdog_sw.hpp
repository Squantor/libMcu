/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Watchdog software interface
 */
#ifndef RP2040_WATCHDOG_SW_HPP
#define RP2040_WATCHDOG_SW_HPP

namespace libMcuLL {
namespace sw {
namespace watchdog {
template <libMcuLL::watchdogBaseAddress const& watchdogAddress_>
struct watchdog : libMcuLL::peripheralBase {
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
  static hw::watchdog::peripheral* watchdogPeripheral() {
    return reinterpret_cast<hw::watchdog::peripheral*>(watchdogAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType watchdogAddress{watchdogAddress_}; /**< peripheral address */
};
}  // namespace watchdog
}  // namespace sw
}  // namespace libMcuLL
#endif