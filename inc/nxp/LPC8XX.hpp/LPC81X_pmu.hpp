/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Power management unit functions
 */
#ifndef LPC81X_PMU_HPP
#define LPC81X_PMU_HPP

namespace instances {
namespace pmu {
using namespace registers::pmu;
template <libMcuLL::PMUtype base>
struct pmu {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to power management unit registers
   */
  static auto regs() {
    return reinterpret_cast<registers::pmu::registers *>(base);
  }
};
}  // namespace pmu
}  // namespace instances

#endif