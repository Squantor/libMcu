/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series Flash Control registers, defines and functions.
 */
#ifndef LPC84X_FLASH_CTRL_H
#define LPC84X_FLASH_CTRL_H

/** FLASH_CTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t FLASHCFG;       /**< Flash configuration register, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t FMSSTART;       /**< Flash signature start address register, offset: 0x20 */
  __IO uint32_t FMSSTOP;        /**< Flash signaure stop address register, offset: 0x24 */
       uint8_t RESERVED_2[4];
  __I  uint32_t FMSW0;          /**< Flash signature generation result register returns the flash signature produced by the embedded signature generator.., offset: 0x2C */
       uint8_t RESERVED_3[4016];
  __I  uint32_t FMSTAT;         /**< Flash signature generation status bit, offset: 0xFE0 */
       uint8_t RESERVED_4[4];
  __O  uint32_t FMSTATCLR;      /**< Clear FLASH signature generation status bit, offset: 0xFE8 */
} FLASH_CTRL_Type;

#endif
