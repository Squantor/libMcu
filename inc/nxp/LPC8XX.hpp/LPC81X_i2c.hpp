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
template <libMcuLL::I2Ctype base>
struct i2c {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to i2c registers
   */
  static auto regs() {
    return reinterpret_cast<registers::i2c::registers *>(base);
  }

  /**
   * @brief Initialize I2C master
   *
   * @param bitRate requested bit rate
   * @return uint32_t actual bit rate
   */
  uint32_t initMaster(uint32_t bitRate) {
    uint32_t divider = CLOCK_AHB / bitRate;
    regs()->CLKDIV = divider + 1;
    regs()->CFG = CFG::MSTEN;
    return CLOCK_AHB / divider;
  }
};
}  // namespace i2c
}  // namespace instances

#endif