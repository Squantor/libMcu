/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series wakeup timer registers, defines and functions.
*/
#ifndef LPC8XX_WKT_H
#define LPC8XX_WKT_H

typedef volatile struct {
  uint32_t CTRL; /* Alarm/Wakeup Timer Control register */
  uint32_t Reserved[2];
  uint32_t COUNT; /* Alarm/Wakeup Timer Counter register */
} WKT_Type;

#define WKT_CTRL_RESERVED (~7)

/**
 * WKT Control register bit fields & masks
 */
#define WKT_CTRL_CLKSEL ((uint32_t)(1 << 0))    /*!< Select the self wake-up timer clock source */
#define WKT_CTRL_ALARMFLAG ((uint32_t)(1 << 1)) /*!< Wake-up or alarm timer flag */
#define WKT_CTRL_CLEARCTR ((uint32_t)(1 << 2))  /*!< Clears the self wake-up timer */

/**
 * WKT Clock source values enum
 */
typedef enum {
  WKT_CLKSRC_DIVIRC = 0, /* Divided IRC clock - runs at 750kHz */
  WKT_CLKSRC_10KHZ = 1   /* Low power clock - runs at 10kHz */
} WKT_CLKSRC_T;

#include "nxp/LPC8XX/LPC8XX_wkt_old.h"

#endif