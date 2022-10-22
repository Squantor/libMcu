/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series  Power control unit registers, defines and functions.
 */
#ifndef LPC84X_PMU_H
#define LPC84X_PMU_H

/** PMU - Register Layout Typedef */
typedef volatile struct PMU_Struct {
  uint32_t PCON;     /**< Power control register, offset: 0x0 */
  uint32_t GPREG[4]; /**< General purpose register N, array offset: 0x4, array step: 0x4 */
  uint32_t DPDCTRL;  /**< Deep power-down control register. Also includes bits for general purpose storage., offset: 0x14 */
} PMU_Type;

#endif
