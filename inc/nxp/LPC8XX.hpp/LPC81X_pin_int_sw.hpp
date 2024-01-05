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

namespace libMcuLL {
namespace sw {
namespace pin_int {
using namespace hw::gpio;
template <libMcuLL::PININTbaseAddress address_>
struct gpio {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to pin interrupt registers
   */
  static hw::pinint::peripheral *peripheral() {
    return reinterpret_cast<hw::pinint::peripheral *>(address_);
  }
};
}  // namespace pin_int
}  // namespace sw
}  // namespace libMcuLL

#endif