/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series CRC engine registers, defines and functions.
 */
#ifndef LPC84X_CRC_H
#define LPC84X_CRC_H

/** CRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MODE;       /**< CRC mode register, offset: 0x0 */
  __IO uint32_t SEED;       /**< CRC seed register, offset: 0x4 */
  union {                   /* offset: 0x8 */
    __I  uint32_t SUM;      /**< CRC checksum register, offset: 0x8 */
    __O  uint32_t WR_DATA;  /**< CRC data register, offset: 0x8 */
  };
} CRC_Type;

#endif
