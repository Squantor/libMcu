/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Timer software interface
 */
#ifndef RP2040_TIMER_SW_HPP
#define RP2040_TIMER_SW_HPP

namespace libMcuLL::timer {
template <libMcu::timerBaseAddress const& timerAddress_>
struct timer : libMcu::peripheralBase {
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
  static libMcuHw::timer::peripheral* timerPeripheral() {
    return reinterpret_cast<libMcuHw::timer::peripheral*>(timerAddress);
  }

 private:
  static constexpr libMcu::hwAddressType timerAddress{timerAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::timer
#endif