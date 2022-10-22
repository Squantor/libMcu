/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC800 series common cyclic redudancy check registers, definitions and
functions.
*/
#ifndef LPC8XX_CRC_H
#define LPC8XX_CRC_H

/* CRC register block structure */
typedef volatile struct {
  uint32_t MODE; /* CRC Mode Register */
  uint32_t SEED; /* CRC SEED Register */
  union {
    const uint32_t SUM; /* CRC Checksum Register. */
    uint32_t WRDATA32;  /* CRC Data Register: write size 32-bit */
    uint16_t WRDATA16;  /* CRC Data Register: write size 16-bit */
    uint8_t WRDATA8;    /* CRC Data Register: write size 8-bit */
  };
} CRC_Type;

/* CRC MODE register description */
#define CRC_MODE_POLY_BITMASK ((0x03))      /** CRC polynomial Bit mask */
#define CRC_MODE_POLY_CCITT (0x00)          /** Select CRC-CCITT polynomial */
#define CRC_MODE_POLY_CRC16 (0x01)          /** Select CRC-16 polynomial */
#define CRC_MODE_POLY_CRC32 (0x02)          /** Select CRC-32 polynomial */
#define CRC_MODE_WRDATA_BITMASK (0x03 << 2) /** CRC WR_Data Config Bit mask */
#define CRC_MODE_WRDATA_BIT_RVS (1 << 2)    /** Select Bit order reverse for WR_DATA (per byte) */
#define CRC_MODE_WRDATA_CMPL                                                     \
  (1 << 3)                               /** Select One's complement for WR_DATA \
                                          */
#define CRC_MODE_SUM_BITMASK (0x03 << 4) /** CRC Sum Config Bit mask */
#define CRC_MODE_SUM_BIT_RVS (1 << 4)    /** Select Bit order reverse for CRC_SUM */
#define CRC_MODE_SUM_CMPL (1 << 5)       /** Select One's complement for CRC_SUM */

#define MODE_CFG_CCITT (0x00) /** Pre-defined mode word for default CCITT setup */
#define MODE_CFG_CRC16 (0x15) /** Pre-defined mode word for default CRC16 setup */
#define MODE_CFG_CRC32 (0x36) /** Pre-defined mode word for default CRC32 setup */

#define CRC_SEED_CCITT (0x0000FFFF) /** Initial seed value for CCITT mode */
#define CRC_SEED_CRC16 (0x00000000) /** Initial seed value for CRC16 mode */
#define CRC_SEED_CRC32 (0xFFFFFFFF) /** Initial seed value for CRC32 mode */

/* CRC polynomial */
typedef enum IP_CRC_001_POLY {
  CRC_POLY_CCITT = CRC_MODE_POLY_CCITT, /**< CRC-CCIT polynomial */
  CRC_POLY_CRC16 = CRC_MODE_POLY_CRC16, /**< CRC-16 polynomial */
  CRC_POLY_CRC32 = CRC_MODE_POLY_CRC32, /**< CRC-32 polynomial */
  CRC_POLY_LAST,
} CRC_POLY_T;

#include "nxp/LPC8XX/LPC8XX_crc_old.h"

#endif