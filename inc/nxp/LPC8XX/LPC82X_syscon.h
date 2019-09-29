/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>
*/
/* 
LPC820 series common system control functions
*/
#ifndef LPC82X_SYSCON_H
#define LPC82X_SYSCON_H

typedef struct {
    __IO uint32_t SYSMEMREMAP;      /* System memory remap (R/W) */
    __IO uint32_t PRESETCTRL;       /* Peripheral reset control (R/W) */
    __IO uint32_t SYSPLLCTRL;       /* System PLL control (R/W) */
    __IO uint32_t SYSPLLSTAT;       /* System PLL status (R/W ) */
    uint32_t RESERVED0[4];
    __IO uint32_t SYSOSCCTRL;       /* System oscillator control (R/W) */
    __IO uint32_t WDTOSCCTRL;       /* Watchdog oscillator control (R/W) */
    __IO uint32_t IRCCTRL;          /* IRC Control Register (Available only in LPC82X) */
    uint32_t RESERVED1[1];
    __IO uint32_t SYSRSTSTAT;       /* System reset status Register (R/W ) */
    uint32_t RESERVED2[3];
    __IO uint32_t SYSPLLCLKSEL;     /* System PLL clock source select (R/W) */
    __IO uint32_t SYSPLLCLKUEN;     /* System PLL clock source update enable (R/W) */
    uint32_t RESERVED3[10];
    __IO uint32_t MAINCLKSEL;       /* Main clock source select (R/W) */
    __IO uint32_t MAINCLKUEN;       /* Main clock source update enable (R/W) */
    __IO uint32_t SYSAHBCLKDIV;     /* System AHB clock divider (R/W) */
    uint32_t RESERVED4[1];
    __IO uint32_t SYSAHBCLKCTRL;    /* System AHB clock control (R/W) */
    uint32_t RESERVED5[4];
    __IO uint32_t UARTCLKDIV;       /* UART clock divider (R/W) */
    uint32_t RESERVED6[18];
    __IO uint32_t CLKOUTSEL;        /* CLKOUT clock source select (R/W) */
    __IO uint32_t CLKOUTUEN;        /* CLKOUT clock source update enable (R/W) */
    __IO uint32_t CLKOUTDIV;        /* CLKOUT clock divider (R/W) */
    uint32_t RESERVED7;
    __IO uint32_t UARTFRGDIV;       /* UART fractional divider SUB(R/W) */
    __IO uint32_t UARTFRGMULT;      /* UART fractional divider ADD(R/W) */
    uint32_t RESERVED8[1];
    __IO uint32_t EXTTRACECMD;      /* External trace buffer command register  */
    __IO uint32_t PIOPORCAP0;       /* POR captured PIO status 0 (R/ ) */
    uint32_t RESERVED9[12];
    __IO uint32_t IOCONCLKDIV[7];   /* Peripheral clock x to the IOCON block for programmable glitch filter */
    __IO uint32_t BODCTRL;          /* BOD control (R/W) */
    __IO uint32_t SYSTCKCAL;        /* System tick counter calibration (R/W) */
    uint32_t RESERVED10[6];
    __IO uint32_t IRQLATENCY;       /* IRQ delay */
    __IO uint32_t NMISRC;           /* NMI Source Control     */
    __IO uint32_t PINTSEL[8];       /* GPIO Pin Interrupt Select register 0 */
    uint32_t RESERVED11[27];
    __IO uint32_t STARTERP0;        /* Start logic signal enable Register 0 (R/W) */
    uint32_t RESERVED12[3];
    __IO uint32_t STARTERP1;        /* Start logic signal enable Register 0 (R/W) */
    uint32_t RESERVED13[6];
    __IO uint32_t PDSLEEPCFG;       /* Power-down states in Deep-sleep mode (R/W) */
    __IO uint32_t PDAWAKECFG;       /* Power-down states after wake-up (R/W) */
    __IO uint32_t PDRUNCFG;         /* Power-down configuration Register (R/W) */
    uint32_t RESERVED14[111];
    __I  uint32_t DEVICEID;   /* Device ID (R/ ) */
} LPC_SYSCTL_T;

/**
 * Peripheral interrupt wakeup events values
 */
#define SYSCTL_WAKEUP_I2C1INT     (1 << 7)    /*!< I2C1 interrupt wake-up [Available only on LPC82X] */
#define SYSCTL_WAKEUP_I2C2INT     (1 << 21)    /*!< I2C2 interrupt wake-up [Available only on LPC82X] */
#define SYSCTL_WAKEUP_I2C3INT     (1 << 22)    /*!< I2C3 interrupt wake-up [Available only on LPC82X] */

/**
 * Deep sleep to wakeup and power state setup values
 */
#define SYSCTL_SLPWAKE_ADC_PD    (1 << 4)    /*!< ADC wake-up configuration [Available only on LPC82x] */

/* Reserved bits masks for registers */
#define SYSCTL_PRESETCTRL_RESERVED      0xfffe2000
#define SYSCTL_SYSAHBCLKCTRL_RESERVED   0xda100000
#define SYSCTL_PIOPORCAP0_RESERVED      0xfffc0000
#define SYSCTL_STARTERP1_RESERVED       ((1<<2)|(1<<6)|(7<<9)|(1<<14)|0xff9f0000)

/* PDWAKECFG and PDRUNCFG register masks */
#define PDWAKEUPWRMASK  (0x00006D00)
#define PDWAKEUPDATMASK (0x000080FF)

/**
 * Peripheral reset identifiers
 */
typedef enum {
    RESET_SPI0,            /*!< SPI0 reset control */
    RESET_SPI1,            /*!< SPI1 reset control */
    RESET_UARTFBRG,        /*!< UART fractional baud rate generator reset control */
    RESET_USART0,        /*!< USART0 reset control */
    RESET_USART1,        /*!< USART1 reset control */
    RESET_USART2,        /*!< USART2 reset control */
    RESET_I2C0,            /*!< I2C0 reset control */
    RESET_MRT,            /*!< MRT reset control */
    RESET_SCT,            /*!< SCT reset control */
    RESET_WKT,            /*!< Self wake-up timer (WKT) control */
    RESET_GPIO,            /*!< GPIO reset control */
    RESET_FLASH,        /*!< FLASH reset control */
    RESET_ACMP,            /*!< ACMP reset control */
    RESET_I2C1 = 14,    /*!< I2C1 reset control [Available only in LPC82x] */
    RESET_I2C2,            /*!< I2C2 reset control [Available only in LPC82x] */
    RESET_I2C3,            /*!< I2C3 reset control [Available only in LPC82x] */
} SYSCTL_PERIPH_RESET_T;

#include "nxp/LPC8XX/LPC8XX_syscon.h"

#endif