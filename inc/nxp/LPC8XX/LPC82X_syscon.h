/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC820 series common system control registers, defines and functions.
*/
#ifndef LPC82X_SYSCON_H
#define LPC82X_SYSCON_H

typedef volatile struct {
    uint32_t SYSMEMREMAP;      /* System memory remap (R/W) */
    uint32_t PRESETCTRL;       /* Peripheral reset control (R/W) */
    uint32_t SYSPLLCTRL;       /* System PLL control (R/W) */
    uint32_t SYSPLLSTAT;       /* System PLL status (R/W ) */
    uint32_t RESERVED0[4];
    uint32_t SYSOSCCTRL;       /* System oscillator control (R/W) */
    uint32_t WDTOSCCTRL;       /* Watchdog oscillator control (R/W) */
    uint32_t IRCCTRL;          /* IRC Control Register (Available only in LPC82X) */
    uint32_t RESERVED1[1];
    uint32_t SYSRSTSTAT;       /* System reset status Register (R/W ) */
    uint32_t RESERVED2[3];
    uint32_t SYSPLLCLKSEL;     /* System PLL clock source select (R/W) */
    uint32_t SYSPLLCLKUEN;     /* System PLL clock source update enable (R/W) */
    uint32_t RESERVED3[10];
    uint32_t MAINCLKSEL;       /* Main clock source select (R/W) */
    uint32_t MAINCLKUEN;       /* Main clock source update enable (R/W) */
    uint32_t SYSAHBCLKDIV;     /* System AHB clock divider (R/W) */
    uint32_t RESERVED4[1];
    uint32_t SYSAHBCLKCTRL;    /* System AHB clock control (R/W) */
    uint32_t RESERVED5[4];
    uint32_t UARTCLKDIV;       /* UART clock divider (R/W) */
    uint32_t RESERVED6[18];
    uint32_t CLKOUTSEL;        /* CLKOUT clock source select (R/W) */
    uint32_t CLKOUTUEN;        /* CLKOUT clock source update enable (R/W) */
    uint32_t CLKOUTDIV;        /* CLKOUT clock divider (R/W) */
    uint32_t RESERVED7;
    uint32_t UARTFRGDIV;       /* UART fractional divider SUB(R/W) */
    uint32_t UARTFRGMULT;      /* UART fractional divider ADD(R/W) */
    uint32_t RESERVED8[1];
    uint32_t EXTTRACECMD;      /* External trace buffer command register  */
    uint32_t PIOPORCAP0;       /* POR captured PIO status 0 (R/ ) */
    uint32_t RESERVED9[12];
    uint32_t IOCONCLKDIV[7];   /* Peripheral clock x to the IOCON block for programmable glitch filter */
    uint32_t BODCTRL;          /* BOD control (R/W) */
    uint32_t SYSTCKCAL;        /* System tick counter calibration (R/W) */
    uint32_t RESERVED10[6];
    uint32_t IRQLATENCY;       /* IRQ delay */
    uint32_t NMISRC;           /* NMI Source Control     */
    uint32_t PINTSEL[8];       /* GPIO Pin Interrupt Select register 0 */
    uint32_t RESERVED11[27];
    uint32_t STARTERP0;        /* Start logic signal enable Register 0 (R/W) */
    uint32_t RESERVED12[3];
    uint32_t STARTERP1;        /* Start logic signal enable Register 0 (R/W) */
    uint32_t RESERVED13[6];
    uint32_t PDSLEEPCFG;       /* Power-down states in Deep-sleep mode (R/W) */
    uint32_t PDAWAKECFG;       /* Power-down states after wake-up (R/W) */
    uint32_t PDRUNCFG;         /* Power-down configuration Register (R/W) */
    uint32_t RESERVED14[111];
    const uint32_t DEVICEID;   /* Device ID (R/ ) */
} SYSCON_Type;

/** Clock control 0 peripheral list */
typedef enum {
    CLKCTRL_NONE = 0,               /**< Empty clock enable */
    CLKCTRL_ROM = (1 << 1),         /**< ROM clock enable */
    CLKCTRL_RAM0_1 = (1 << 2),      /**< RAM 0 and 1 clock enable */
    CLKCTRL_FLASHREG = (1 << 3),    /**< Flash clock enable */
    CLKCTRL_FLASH = (1 << 4),       /**< Flash clock enable */
    CLKCTRL_I2C0 = (1 << 5),        /**< I2C0 clock enable */
    CLKCTRL_GPIO = (1 << 6),        /**< GPIO clock enable */
    CLKCTRL_SWM = (1 << 7),         /**< SWM clock enable */
    CLKCTRL_SCT = (1 << 8),         /**< SCT clock enable */
    CLKCTRL_WKT = (1 << 9),         /**< WKT clock enable */
    CLKCTRL_MRT = (1 << 10),        /**< MRT clock enable */
    CLKCTRL_SPI0 = (1 << 11),       /**< SPI0 clock enable */
    CLKCTRL_SPI1 = (1 << 12),       /**< SPI1 clock enable */
    CLKCTRL_CRC = (1 << 13),        /**< CRC clock enable */
    CLKCTRL_UART0 = (1 << 14),      /**< UART0 clock enable */
    CLKCTRL_UART1 = (1 << 15),      /**< UART1 clock enable */
    CLKCTRL_UART2 = (1 << 16),      /**< UART2 clock enable */
    CLKCTRL_WWDT = (1 << 17),       /**< WWDT clock enable */
    CLKCTRL_IOCON = (1 << 18),      /**< IOCON clock enable */
    CLKCTRL_ACMP = (1 << 19),       /**< ACMP clock enable */
    CLKCTRL_I2C1 = (1 << 21),       /**< I2C1 clock enable */
    CLKCTRL_I2C2 = (1 << 22),       /**< I2C2 clock enable */
    CLKCTRL_I2C3 = (1 << 23),       /**< I2C3 clock enable */
    CLKCTRL_ADC = (1 << 24),        /**< ADC clock enable */
    CLKCTRL_MTB = (1 << 26),        /**< MTB clock enable */
    CLKCTRL_DMA = (1 << 29),       /**< DMA clock enable */
} SYSCON_CLKCTRL_Type;

/**
 * @brief   Enables clocks to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Settings for clock control 0 register, see SYSCON_CLKCTRL_Type enum
 * @return  Nothing
 */
static inline void sysconEnableClocks(SYSCON_Type *peripheral, uint32_t setting)
{
    peripheral->SYSAHBCLKCTRL = setting | peripheral->SYSAHBCLKCTRL;
}

/**
 * @brief   Disables clocks to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Settings for clock control 0 register, see SYSCON_CLKCTRL_Type enum
 * @return  Nothing
 */
static inline void sysconDisableClocks(SYSCON_Type *peripheral, uint32_t setting)
{
    peripheral->SYSAHBCLKCTRL = ~setting & peripheral->SYSAHBCLKCTRL;
}

#include "nxp/LPC8XX/LPC82X_syscon_old.h"
#include "nxp/LPC8XX/LPC8XX_syscon.h"
#include "nxp/LPC8XX/LPC8XX_syscon_old.h"

#endif