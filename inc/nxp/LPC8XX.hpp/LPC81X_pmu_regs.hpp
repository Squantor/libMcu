/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Power management unit register interface
 */
#ifndef LPC81X_PMU_REGS_HPP
#define LPC81X_PMU_REGS_HPP

namespace libMcuLL {
namespace hw {
namespace pmu {

/**
 * @brief power management register definitions
 *
 */
struct peripheral {
  volatile uint32_t PCON;     /**< Power control Register (R/W) */
  volatile uint32_t GPREG[4]; /**< General purpose Registers 0..3 (R/W) */
  volatile uint32_t DPDCTRL;  /**< Deep power-down control register (R/W) */
};

}  // namespace pmu
}  // namespace hw
}  // namespace libMcuLL

#endif