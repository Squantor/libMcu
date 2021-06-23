/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC820 series common system control registers, defines and functions.
*/
#ifndef LPC82X_SYSCON_OLD_H
#define LPC82X_SYSCON_OLD_H

#define SYSCTL_WAKEUP_I2C1INT     (1 << 7)
#define SYSCTL_WAKEUP_I2C2INT     (1 << 21)
#define SYSCTL_WAKEUP_I2C3INT     (1 << 22)

#define SYSCTL_SLPWAKE_ADC_PD    (1 << 4)

/* Reserved bits masks for registers */
#define SYSCTL_PRESETCTRL_RESERVED      0xfffe2000
#define SYSCTL_SYSAHBCLKCTRL_RESERVED   0xda100000
#define SYSCTL_PIOPORCAP0_RESERVED      0xfffc0000
#define SYSCTL_STARTERP1_RESERVED       ((1<<2)|(1<<6)|(7<<9)|(1<<14)|0xff9f0000)

/* PDWAKECFG and PDRUNCFG register masks */
#define PDWAKEUPWRMASK  (0x00006D00)
#define PDWAKEUPDATMASK (0x000080FF)

typedef enum {
    RESET_SPI0,
    RESET_SPI1,
    RESET_UARTFBRG,
    RESET_USART0,
    RESET_USART1,
    RESET_USART2,
    RESET_I2C0,
    RESET_MRT,
    RESET_SCT,
    RESET_WKT,
    RESET_GPIO,
    RESET_FLASH,
    RESET_ACMP,
    RESET_I2C1 = 14,
    RESET_I2C2,
    RESET_I2C3,
} SYSCTL_PERIPH_RESET_T;

#include "nxp/LPC8XX/LPC8XX_syscon.h"

#endif