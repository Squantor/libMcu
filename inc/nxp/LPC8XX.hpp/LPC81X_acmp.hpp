/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series analog comparator functions
 */
#ifndef LPC81X_ACMP_HPP
#define LPC81X_ACMP_HPP

namespace instances {
namespace acmp {
using namespace registers::acmp;
template <uint32_t base>
struct acmp {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to analog comparator registers
   */
  static auto regs() {
    return reinterpret_cast<registers::acmp::registers *>(base);
  }
};
}  // namespace acmp
}  // namespace instances

#endif