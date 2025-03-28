/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_watchdog_ll.hpp
 * @brief low level interface for the RP2040 Watchdog
 */
#ifndef RP2040_WATCHDOG_SW_HPP
#define RP2040_WATCHDOG_SW_HPP

namespace libmcull::watchdog {
namespace hardware = libmcuhw::watchdog;
template <libmcu::watchdogBaseAddress const& watchdogAddress_>
struct watchdog : libmcu::PeripheralBase {
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
  static constexpr libmcu::hwAddressType watchdogAddress{watchdogAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::watchdog
#endif