/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series Micro Trace Buffer registers, defines and functions.
 */
#ifndef LPC84X_MTB_H
#define LPC84X_MTB_H

/** MTB - Register Layout Typedef */
typedef struct {
  __IO uint32_t POSITION;                          /**< POSITION Register, offset: 0x0 */
  __IO uint32_t MASTER;                            /**< MASTER Register, offset: 0x4 */
  __IO uint32_t FLOW;                              /**< FLOW Register, offset: 0x8 */
  __I  uint32_t BASE;                              /**< Indicates where the SRAM is located in the processor memory map. This register is provided to enable auto discovery of the MTB SRAM location, by a debug agent., offset: 0xC */
} MTB_Type;

#endif
