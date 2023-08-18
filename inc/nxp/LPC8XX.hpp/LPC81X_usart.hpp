/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series USART functions
 */
#ifndef LPC81X_USART_HPP
#define LPC81X_USART_HPP

namespace instances {
namespace usart {
using namespace registers::usart;
template <uint32_t base>
struct usart {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to usart registers
   */
  static auto regs() {
    return reinterpret_cast<registers::usart::registers *>(base);
  }
};
}  // namespace usart
}  // namespace instances

#endif