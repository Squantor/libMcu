/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_rtc_ll.hpp
 * @brief low level interface for the RP2040 RTC
 */
#ifndef RP2040_RTC_SW_HPP
#define RP2040_RTC_SW_HPP

namespace libMcuLL::rtc {
namespace hardware = libMcuHw::rtc;
template <libMcu::rtcBaseAddress const& rtcAddress_>
struct rtc : libMcu::PeripheralBase {
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
  static constexpr libMcu::hwAddressType rtcAddress{rtcAddress_}; /*!< peripheral address */
};
}  // namespace libMcuLL::rtc
#endif