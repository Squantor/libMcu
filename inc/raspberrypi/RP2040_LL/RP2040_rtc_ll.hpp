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
#ifndef RP2040_RTC_LL_HPP
#define RP2040_RTC_LL_HPP

namespace libmcull::rtc {
namespace hardware = libmcuhw::rtc;
/**
 * @brief
 * @tparam rtc_address
 */
template <libmcu::RtcBaseAddress const& rtc_address>
struct Rtc : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Rtc* GetPeripheral() {
    return reinterpret_cast<hardware::Rtc*>(rtc_address_);
  }

 private:
  static constexpr libmcu::HwAddressType rtc_address_{rtc_address}; /*!< peripheral address */
};
}  // namespace libmcull::rtc
#endif