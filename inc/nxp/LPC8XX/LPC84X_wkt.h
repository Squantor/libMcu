/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series wakeup timer registers, defines and functions.
 */
#ifndef LPC84X_WKT_H
#define LPC84X_WKT_H

/** WKT - Register Layout Typedef */
typedef volatile struct {
    uint32_t CTRL;         /**< Self wake-up timer control register., offset: 0x0 */
    uint8_t RESERVED_0[8];
    uint32_t COUNT;        /**< Counter register., offset: 0xC */
} WKT_Type;

#endif
