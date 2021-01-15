/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series Input Multiplexer registers, defines and functions.
 */
#ifndef LPC84X_INPUTMUX_H
#define LPC84X_INPUTMUX_H

/** INPUTMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t DMA_INMUX_INMUX[2];                /**< DMA output trigger selection to become DMA trigger, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[24];
  __IO uint32_t SCT_INMUX[4];                      /**< input select register for SCT, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[16];
  __IO uint32_t DMA_ITRIG_INMUX[25];               /**< Trigger select register for DMA channel, array offset: 0x40, array step: 0x4 */
} INPUTMUX_Type;

#endif
