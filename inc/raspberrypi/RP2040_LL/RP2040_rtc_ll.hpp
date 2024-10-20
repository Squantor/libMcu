/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 RTC software interface
 */
#ifndef RP2040_RTC_SW_HPP
#define RP2040_RTC_SW_HPP

namespace libMcuLL::rtc {
namespace hardware = libMcuHw::rtc;
template <libMcu::rtcBaseAddress const& rtcAddress_>
struct rtc : libMcu::peripheralBase {
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
  static hardware::rtc* rtcPeripheral() {
    return reinterpret_cast<hardware::rtc*>(rtcAddress);
  }

 private:
  static constexpr libMcu::hwAddressType rtcAddress{rtcAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::rtc
#endif