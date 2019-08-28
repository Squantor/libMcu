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
LPC810 series common system control functions
*/
#ifndef LPC81X_SYSCON_H
#define LPC81X_SYSCON_H

typedef struct {
    volatile uint32_t SYSMEMREMAP;      /* System memory remap (R/W) */
    volatile uint32_t PRESETCTRL;       /* Peripheral reset control (R/W) */
    volatile uint32_t SYSPLLCTRL;       /* System PLL control (R/W) */
    volatile uint32_t SYSPLLSTAT;       /* System PLL status (R/W ) */
    uint32_t RESERVED0[4];
    volatile uint32_t SYSOSCCTRL;       /* System oscillator control (R/W) */
    volatile uint32_t WDTOSCCTRL;       /* Watchdog oscillator control (R/W) */
    uint32_t RESERVED1[2];
    volatile uint32_t SYSRSTSTAT;       /* System reset status Register (R/W ) */
    uint32_t RESERVED2[3];
    volatile uint32_t SYSPLLCLKSEL;     /* System PLL clock source select (R/W) */
    volatile uint32_t SYSPLLCLKUEN;     /* System PLL clock source update enable (R/W) */
    uint32_t RESERVED3[10];
    volatile uint32_t MAINCLKSEL;       /* Main clock source select (R/W) */
    volatile uint32_t MAINCLKUEN;       /* Main clock source update enable (R/W) */
    volatile uint32_t SYSAHBCLKDIV;     /* System AHB clock divider (R/W) */
    uint32_t RESERVED4[1];
    volatile uint32_t SYSAHBCLKCTRL;    /* System AHB clock control (R/W) */
    uint32_t RESERVED5[4];
    volatile uint32_t UARTCLKDIV;       /* UART clock divider (R/W) */
    uint32_t RESERVED6[18];
    volatile uint32_t CLKOUTSEL;        /* CLKOUT clock source select (R/W) */
    volatile uint32_t CLKOUTUEN;        /* CLKOUT clock source update enable (R/W) */
    volatile uint32_t CLKOUTDIV;        /* CLKOUT clock divider (R/W) */
    uint32_t RESERVED7;
    volatile uint32_t UARTFRGDIV;       /* UART fractional divider SUB(R/W) */
    volatile uint32_t UARTFRGMULT;      /* UART fractional divider ADD(R/W) */
    uint32_t RESERVED8[1];
    volatile uint32_t EXTTRACECMD;      /* External trace buffer command register  */
    volatile uint32_t PIOPORCAP0;       /* POR captured PIO status 0 (R/ ) */
    uint32_t RESERVED9[12];
    volatile uint32_t IOCONCLKDIV[7];   /* Peripheral clock x to the IOCON block for programmable glitch filter */
    volatile uint32_t BODCTRL;          /* BOD control (R/W) */
    volatile uint32_t SYSTCKCAL;        /* System tick counter calibration (R/W) */
    uint32_t RESERVED10[6];
    volatile uint32_t IRQLATENCY;       /* IRQ delay */
    volatile uint32_t NMISRC;           /* NMI Source Control     */
    volatile uint32_t PINTSEL[8];       /* GPIO Pin Interrupt Select register 0 */
    uint32_t RESERVED11[27];
    volatile uint32_t STARTERP0;        /* Start logic signal enable Register 0 (R/W) */
    uint32_t RESERVED12[3];
    volatile uint32_t STARTERP1;        /* Start logic signal enable Register 0 (R/W) */
    uint32_t RESERVED13[6];
    volatile uint32_t PDSLEEPCFG;       /* Power-down states in Deep-sleep mode (R/W) */
    volatile uint32_t PDAWAKECFG;       /* Power-down states after wake-up (R/W) */
    volatile uint32_t PDRUNCFG;         /* Power-down configuration Register (R/W) */
    uint32_t RESERVED14[111];
    volatile const uint32_t DEVICEID;   /* Device ID (R/ ) */
} LPC_SYSCTL_T;

/* Reserved bits masks for registers */
#define SYSCTL_PRESETCTRL_RESERVED      0xffffe000
#define SYSCTL_SYSAHBCLKCTRL_RESERVED   0xfff00000
#define SYSCTL_PIOPORCAP0_RESERVED      0xffffc000
#define SYSCTL_STARTERP1_RESERVED       ((1<<2)|(3<<6)|(7<<9)|(1<<14)|(0x1f<<16)|0xff800000)

/* PDWAKECFG and PDRUNCFG register masks */
#define PDWAKEUPWRMASK  (0x00006D10)
#define PDWAKEUPDATMASK (0x000080EF)

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
} SYSCTL_PERIPH_RESET_T;

#include "nxp/LPC8XX/LPC8XX_syscon.h"

#endif