/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series analog comparator, defines and functions.
 */
#ifndef LPC84X_ACOMP_H
#define LPC84X_ACOMP_H

/** ACOMP - Register Layout Typedef */
typedef volatile struct ACOMP_Struct {
  uint32_t CTRL; /**< Comparator control register, offset: 0x0 */
  uint32_t LAD;  /**< Voltage ladder register, offset: 0x4 */
} ACOMP_Type;

#endif