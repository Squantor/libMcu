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

namespace libMcuLL {
namespace sw {
namespace timer {
template <libMcuLL::timerBaseAddress const& timerAddress_>
struct timer : libMcuLL::peripheralBase {
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
  static hw::timer::peripheral* timerPeripheral() {
    return reinterpret_cast<hw::timer::peripheral*>(timerAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType timerAddress{timerAddress_}; /**< peripheral address */
};
}  // namespace timer
}  // namespace sw
}  // namespace libMcuLL
#endif