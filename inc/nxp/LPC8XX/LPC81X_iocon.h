/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC81X series I/O Control registers, defines and functions.
 */
#ifndef LPC81X_IOCON_H
#define LPC81X_IOCON_H

typedef volatile struct IOCON_Struct {
  uint32_t
      PIO[56]; /**< Digital I/O control for pins PIO0_17..Digital I/O control
                  for pins PIO1_10, array offset: 0x0, array step: 0x4 */
} IOCON_Type;

#define IOCON_RESERVED_MASK                                                   \
  (0x0001FF78u) /**< Masking off reserved pins so they do not accidentaly get \
                   set */

#include "nxp/LPC8XX/LPC8XX_iocon.h"

#endif
