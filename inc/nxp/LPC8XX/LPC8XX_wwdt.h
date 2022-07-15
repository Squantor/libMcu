/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series common windowed watchdog registers, defines and functions.
*/
#ifndef LPC8XX_WWDT_H
#define LPC8XX_WWDT_H

/* WDT oscillator frequency value */
#define WDT_OSC (LPC8XX_IRC_FREQ)

typedef volatile struct {
  uint32_t MOD;      /* basic mode and status register */
  uint32_t TC;       /* time-out value register */
  uint32_t FEED;     /* Writing 0xAA followed by 0x55 reloads the Watchdog timer */
  const uint32_t TV; /* current value of the Watchdog timer */
  const uint32_t RESERVED0;
  uint32_t WARNINT; /* contains the Watchdog warning interrupt value */
  uint32_t WINDOW;  /* contains the Watchdog window value. */
} WWDT_Type;

/* Reserved bits masks for registers */
#define WWDT_MOD_RESERVED (~0x3f)
#define WWDT_TC_RESERVED 0xff000000
#define WWDT_FEED_RESERVED (~0xff)
#define WWDT_TV_RESERVED 0xff000000
#define WWDT_WARNINT_RESERVED (~0x3ff)
#define WWDT_WINDOW_RESERVED 0xff000000

/** Watchdog Mode Bitmask */
#define WWDT_WDMOD_BITMASK ((uint32_t)0x1F)
/** WWDT interrupt enable bit */
#define WWDT_WDMOD_WDEN ((uint32_t)(1 << 0))
/** WWDT interrupt enable bit */
#define WWDT_WDMOD_WDRESET ((uint32_t)(1 << 1))
/** WWDT time out flag bit */
#define WWDT_WDMOD_WDTOF ((uint32_t)(1 << 2))
/** WDT Time Out flag bit */
#define WWDT_WDMOD_WDINT ((uint32_t)(1 << 3))

#include "nxp/LPC8XX/LPC8XX_wwdt_old.h"

#endif