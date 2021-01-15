/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series I/O Control registers, defines and functions.
 */
#ifndef LPC84X_IOCON_H
#define LPC84X_IOCON_H

typedef struct {
  __IO uint32_t PIO[56];    /**< Digital I/O control for pins PIO0_17..Digital I/O control for pins PIO1_10, array offset: 0x0, array step: 0x4 */
} IOCON_Type;

#endif
