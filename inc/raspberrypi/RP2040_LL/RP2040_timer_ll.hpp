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
#ifndef RP2040_TIMER_SW_HPP
#define RP2040_TIMER_SW_HPP

namespace libmcull::timer {
namespace hardware = libmcuhw::timer;
template <libmcu::TimerBaseAddress const& timerAddress_>
struct timer : libmcu::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::timer* timerPeripheral() {
    return reinterpret_cast<hardware::timer*>(timerAddress);
  }

 private:
  static constexpr libmcu::HwAddressType timerAddress{timerAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::timer
#endif