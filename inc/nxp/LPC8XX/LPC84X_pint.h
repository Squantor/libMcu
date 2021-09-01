/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series Pin interrupt registers, defines and functions.
 */
#ifndef LPC84X_PINT_H
#define LPC84X_PINT_H

/** PINT - Register Layout Typedef */
typedef volatile struct PINT_Struct {
    uint32_t ISEL;          /**< Pin Interrupt Mode register, offset: 0x0 */
    uint32_t IENR;          /**< Pin interrupt level or rising edge interrupt enable register, offset: 0x4 */
    const uint32_t SIENR;   /**< Pin interrupt level or rising edge interrupt set register, offset: 0x8 */
    const uint32_t CIENR;   /**< Pin interrupt level (rising edge interrupt) clear register, offset: 0xC */
    uint32_t IENF;          /**< Pin interrupt active level or falling edge interrupt enable register, offset: 0x10 */
    const uint32_t SIENF;   /**< Pin interrupt active level or falling edge interrupt set register, offset: 0x14 */
    const uint32_t CIENF;   /**< Pin interrupt active level or falling edge interrupt clear register, offset: 0x18 */
    uint32_t RISE;          /**< Pin interrupt rising edge register, offset: 0x1C */
    uint32_t FALL;          /**< Pin interrupt falling edge register, offset: 0x20 */
    uint32_t IST;           /**< Pin interrupt status register, offset: 0x24 */
    uint32_t PMCTRL;        /**< Pattern match interrupt control register, offset: 0x28 */
    uint32_t PMSRC;         /**< Pattern match interrupt bit-slice source register, offset: 0x2C */
    uint32_t PMCFG;         /**< Pattern match interrupt bit slice configuration register, offset: 0x30 */
} PINT_Type;

#endif
