/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series DAC registers, defines and functions.
 */
#ifndef LPC84X_DAC_H
#define LPC84X_DAC_H

/** DAC - Register Layout Typedef */
typedef volatile struct {
  uint32_t CR;   /**< D/A Converter Register. This register contains the digital value to be converted to analog and a power control
                    bit., offset: 0x0 */
  uint32_t CTRL; /**< DAC Control register. This register controls DMA and timer operation., offset: 0x4 */
  uint32_t CNTVAL; /**< DAC Counter Value register. This register contains the reload value for the DAC DMA/Interrupt timer.,
                      offset: 0x8 */
} DAC_Type;

#endif
