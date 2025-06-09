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
#ifndef RP2040_WATCHDOG_LL_HPP
#define RP2040_WATCHDOG_LL_HPP

namespace libmcull::watchdog {
namespace hardware = libmcuhw::watchdog;
/**
 * @brief
 * @tparam watchdog_address
 */
template <libmcu::WatchdogBaseAddress const& watchdog_address>
struct Watchdog : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Watchdog* GetPeripheral() {
    return reinterpret_cast<hardware::Watchdog*>(watchdog_address_);
  }

 private:
  static constexpr libmcu::HwAddressType watchdog_address_{watchdog_address}; /*!< peripheral address */
};
}  // namespace libmcull::watchdog
#endif