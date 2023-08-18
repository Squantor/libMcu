/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Flash memory control functions
 */
#ifndef LPC81X_FMC_HPP
#define LPC81X_FMC_HPP

namespace instances {
namespace fmc {
using namespace registers::fmc;
template <uint32_t base>
struct fmc {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  static auto regs() {
    return reinterpret_cast<registers::fmc::registers *>(base);
  }
};
}  // namespace fmc
}  // namespace instances

#endif