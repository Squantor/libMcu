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

namespace libMcuLL {
namespace sw {
namespace rtc {
template <libMcuLL::rtcBaseAddress const& rtcAddress_>
struct rtc : libMcuLL::peripheralBase {
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
  static hw::rtc::peripheral* rtcPeripheral() {
    return reinterpret_cast<hw::rtc::peripheral*>(rtcAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType rtcAddress{rtcAddress_}; /**< peripheral address */
};
}  // namespace rtc
}  // namespace sw
}  // namespace libMcuLL
#endif