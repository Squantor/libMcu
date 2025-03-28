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

namespace libmcull::rtc {
namespace hardware = libmcuhw::rtc;
template <libmcu::rtcBaseAddress const& rtcAddress_>
struct rtc : libmcu::PeripheralBase {
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
  static constexpr libmcu::hwAddressType rtcAddress{rtcAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::rtc
#endif