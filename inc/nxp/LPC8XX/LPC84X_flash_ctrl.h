/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series Flash Control registers, defines and functions.
 */
#ifndef LPC84X_FLASH_CTRL_H
#define LPC84X_FLASH_CTRL_H

/** FLASH_CTRL - Register Layout Typedef */
typedef volatile struct FLASH_CTRL_Struct {
  uint8_t RESERVED_0[16];
  uint32_t FLASHCFG; /**< Flash configuration register, offset: 0x10 */
  uint8_t RESERVED_1[12];
  uint32_t FMSSTART; /**< Flash signature start address register, offset: 0x20 */
  uint32_t FMSSTOP;  /**< Flash signaure stop address register, offset: 0x24 */
  uint8_t RESERVED_2[4];
  const uint32_t FMSW0; /**< Flash signature generation result register returns the flash signature produced by the embedded
                           signature generator.., offset: 0x2C */
  uint8_t RESERVED_3[4016];
  const uint32_t FMSTAT; /**< Flash signature generation status bit, offset: 0xFE0 */
  uint8_t RESERVED_4[4];
  uint32_t FMSTATCLR; /**< Clear FLASH signature generation status bit, offset: 0xFE8 */
} FLASH_CTRL_Type;

#define FLASH_CTRL_CFG_RESERVED (0xFFFFFFFC) /**< Flash Control configuration register reserved bits*/

/* FLASH Access time definitions */
typedef enum {
  FLASHTIM_1_CLOCK = 0,  /**< Flash accesses use 1 CPU clocks. Use for up to 20 MHz CPU clock*/
  FLASHTIM_2_CLOCKS = 1, /**< Flash accesses use 2 CPU clocks. Use for up to 30 MHz CPU clock*/
  FLASHTIM_3_CLOCKS = 2, /**< Flash accesses use 3 CPU clocks. Dont know for what frequency*/
} FLASH_CTRL_FLASHTIM_T;

static inline void FlashControlFlashClocks(FLASH_CTRL_FLASHTIM_T flashTiming) {
  uint32_t flashcfg = FLASH_CTRL->FLASHCFG & FLASH_CTRL_CFG_RESERVED;
  FLASH_CTRL->FLASHCFG = flashcfg | flashTiming;
}

#endif
