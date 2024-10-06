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

namespace libMcuLL::watchdog {
namespace hardware = libMcuHw::watchdog;
template <libMcu::watchdogBaseAddress const& watchdogAddress_>
struct watchdog : libMcu::peripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::watchdog* watchdogPeripheral() {
    return reinterpret_cast<hardware::watchdog*>(watchdogAddress);
  }

 private:
  static constexpr libMcu::hwAddressType watchdogAddress{watchdogAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::watchdog
#endif