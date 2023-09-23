/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series I2C functions
 */
#ifndef LPC81X_I2C_HPP
#define LPC81X_I2C_HPP

namespace instances {
namespace i2c {
using namespace registers::i2c;
template <uint32_t base>
struct i2c {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to i2c registers
   */
  static auto regs() {
    return reinterpret_cast<registers::i2c::registers *>(base);
  }
};
}  // namespace i2c
}  // namespace instances

#endif