/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series pin interrupt functions
 */
#ifndef LPC81X_PIN_INT_HPP
#define LPC81X_PIN_INT_HPP

namespace instances {
namespace pin_int {
using namespace registers::gpio;
template <libMcuLL::PININTaddress address_>
struct gpio {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to pin interrupt registers
   */
  static auto regs() {
    return reinterpret_cast<registers::pinint::registers *>(address_);
  }
};
}  // namespace pin_int
}  // namespace instances

#endif