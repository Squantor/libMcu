/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Multi rate timer functions
 */
#ifndef LPC81X_MRT_HPP
#define LPC81X_MRT_HPP

namespace instances {
namespace mrt {
using namespace registers::mrt;
template <uint32_t base>
struct mrt {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to mrt registers
   */
  static auto regs() {
    return reinterpret_cast<registers::mrt::registers *>(base);
  }
};
}  // namespace mrt
}  // namespace instances

#endif