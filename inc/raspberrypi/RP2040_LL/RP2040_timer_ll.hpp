/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_timer_ll.hpp
 * @brief low level interface for the RP2040 Timer
 */
#ifndef RP2040_TIMER_LL_HPP
#define RP2040_TIMER_LL_HPP

namespace libmcull::timer {
namespace hardware = libmcuhw::timer;
/**
 * @brief
 * @tparam timer_address
 */
template <libmcu::TimerBaseAddress const& timer_address>
struct Timer : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Timer* GetPeripheral() {
    return reinterpret_cast<hardware::Timer*>(timer_address_);
  }

 private:
  static constexpr libmcu::HwAddressType timer_address_{timer_address}; /*!< peripheral address */
};
}  // namespace libmcull::timer
#endif