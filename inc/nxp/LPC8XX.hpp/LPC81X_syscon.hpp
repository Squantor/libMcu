/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series system control functions
 */
#ifndef LPC81X_SYSCON_HPP
#define LPC81X_SYSCON_HPP

namespace instances {
namespace syscon {
using namespace registers::syscon;
template <uint32_t base>
struct syscon {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to syscon registers
   */
  static auto regs() {
    return reinterpret_cast<registers::syscon::registers *>(base);
  }
};
}  // namespace syscon
}  // namespace instances

#endif