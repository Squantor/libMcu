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
  uint32_t SYSMEMREMAP; /* System memory remap (R/W) */
  uint32_t PRESETCTRL;  /* Peripheral reset control (R/W) */
  uint32_t SYSPLLCTRL;  /* System PLL control (R/W) */
  uint32_t SYSPLLSTAT;  /* System PLL status (R/W ) */
  uint32_t RESERVED0[4];
  uint32_t SYSOSCCTRL; /* System oscillator control (R/W) */
  uint32_t WDTOSCCTRL; /* Watchdog oscillator control (R/W) */
  uint32_t IRCCTRL;    /* IRC Control Register (Available only in LPC82X) */
  uint32_t RESERVED1[1];
  uint32_t SYSRSTSTAT; /* System reset status Register (R/W ) */
  uint32_t RESERVED2[3];
  uint32_t SYSPLLCLKSEL; /* System PLL clock source select (R/W) */
  uint32_t SYSPLLCLKUEN; /* System PLL clock source update enable (R/W) */
  uint32_t RESERVED3[10];
  uint32_t MAINCLKSEL;   /* Main clock source select (R/W) */
  uint32_t MAINCLKUEN;   /* Main clock source update enable (R/W) */
  uint32_t SYSAHBCLKDIV; /* System AHB clock divider (R/W) */
  uint32_t RESERVED4[1];
  uint32_t SYSAHBCLKCTRL; /* System AHB clock control (R/W) */
  uint32_t RESERVED5[4];
  uint32_t UARTCLKDIV; /* UART clock divider (R/W) */
  uint32_t RESERVED6[18];
  uint32_t CLKOUTSEL; /* CLKOUT clock source select (R/W) */
  uint32_t CLKOUTUEN; /* CLKOUT clock source update enable (R/W) */
  uint32_t CLKOUTDIV; /* CLKOUT clock divider (R/W) */
  uint32_t RESERVED7;
  uint32_t UARTFRGDIV;  /* UART fractional divider SUB(R/W) */
  uint32_t UARTFRGMULT; /* UART fractional divider ADD(R/W) */
  uint32_t RESERVED8[1];
  uint32_t EXTTRACECMD; /* External trace buffer command register  */
  uint32_t PIOPORCAP0;  /* POR captured PIO status 0 (R/ ) */
  uint32_t RESERVED9[12];
  uint32_t IOCONCLKDIV[7]; /* Peripheral clock x to the IOCON block for
                              programmable glitch filter */
  uint32_t BODCTRL;        /* BOD control (R/W) */
  uint32_t SYSTCKCAL;      /* System tick counter calibration (R/W) */
  uint32_t RESERVED10[6];
  uint32_t IRQLATENCY; /* IRQ delay */
  uint32_t NMISRC;     /* NMI Source Control     */
  uint32_t PINTSEL[8]; /* GPIO Pin Interrupt Select register 0 */
  uint32_t RESERVED11[27];
  uint32_t STARTERP0; /* Start logic signal enable Register 0 (R/W) */
  uint32_t RESERVED12[3];
  uint32_t STARTERP1; /* Start logic signal enable Register 0 (R/W) */
  uint32_t RESERVED13[6];
  uint32_t PDSLEEPCFG; /* Power-down states in Deep-sleep mode (R/W) */
  uint32_t PDAWAKECFG; /* Power-down states after wake-up (R/W) */
  uint32_t PDRUNCFG;   /* Power-down configuration Register (R/W) */
  uint32_t RESERVED14[111];
  const uint32_t DEVICEID; /* Device ID (R/ ) */
} SYSCON_Type;

/** reset control 0 peripheral list */
typedef enum {
  RESETCTRL_NONE = 0,           /*!< No reset 0 clear */
  RESETCTRL_SPI0 = (1 << 0),    /**< SPI0 reset clear */
  RESETCTRL_SPI1 = (1 << 1),    /**< SPI1 reset clear */
  RESETCTRL_UARTFRG = (1 << 2), /**< UART fractional baud rate generator reset clear */
  RESETCTRL_UART0 = (1 << 3),   /**< UART0 reset clear */
  RESETCTRL_UART1 = (1 << 4),   /**< UART1 reset clear */
  RESETCTRL_UART2 = (1 << 5),   /**< UART2 reset clear */
  RESETCTRL_I2C0 = (1 << 6),    /**< I2C0 reset clear */
  RESETCTRL_MRT = (1 << 7),     /**< MRT reset clear */
  RESETCTRL_SCT = (1 << 8),     /**< SCT reset clear */
  RESETCTRL_WKT = (1 << 9),     /**< WKT reset clear */
  RESETCTRL_GPIO = (1 << 10),   /**< GPIO reset clear */
  RESETCTRL_FLASH = (1 << 11),  /**< Flash reset clear */
  RESETCTRL_ACMP = (1 << 12),   /**< UART2 reset clear */
  RESETCTRL_I2C1 = (1 << 14),   /**< I2C0 reset clear */
  RESETCTRL_I2C2 = (1 << 15),   /**< I2C0 reset clear */
  RESETCTRL_I2C3 = (1 << 16),   /**< I2C0 reset clear */
  RESETCTRL_ADC = (1 << 24),    /**< ADC reset clear */
  RESETCTRL_DMA = (1 << 29),    /**< I2C0 reset clear */
} SYSCON_RESETCTRL_Type;

#define PRESETCTRL_MASK 0xDEFE2000 /**< Reserved bits of the Peripheral reset control register */

typedef enum {
  SYSPLLCTRL_POSTDIV_2 = 0u,  /**< Post PLL division ratio of two */
  SYSPLLCTRL_POSTDIV_4 = 1u,  /**< Post PLL division ratio of four */
  SYSPLLCTRL_POSTDIV_8 = 2u,  /**< Post PLL division ratio of eight */
  SYSPLLCTRL_POSTDIV_16 = 3u, /**< Post PLL division ratio of sixteen */
} SYSPLLCTRL_PSEL_Type;

#define SYSPLLCTRL_MASK 0xFFFFFF80 /**< Reserved bits of the System PLL control register */

#define SYSOSCCTRL_MASK 0xFFFFFFFC            /**< Reserved bits of System oscillator control register */
#define SYSOSCCTRL_BYPASS(value) (value << 0) /**< Oscillator is bypassed, used with external oscillator */
#define SYSOSCCTRL_FREQ_1_20MHZ (0 << 1)      /**< Oscillator frequency range from 1 to 20MHz */
#define SYSOSCCTRL_FREQ_15_25MHZ (1 << 1)     /**< Oscillator frequency range from 15 to 25MHz */

#define SYSPLLCLKSEL_MASK 0xFFFFFFFC /**< Reserved bits of the Main clock pll select register */
typedef enum {
  SYSPLLCLKSEL_IRC = 0u,    /**< Internal resonant crystal oscillator */
  SYSPLLCLKSEL_SYSOSC = 1u, /**< Crystal oscillator (SYSOSC) */
  SYSPLLCLKSEL_CLKIN = 3u   /**< CLKIN. External clock input */
} SYSPLLCLKSEL_Type;

#define SYSPLLCLKUEN_MASK                                                                            \
  0xFFFFFFFE                         /**< Reserved bits of the main clock pll select update register \
                                      */
#define SYSPLLCLKUEN_UPDATE (1 << 0) /**< Update main clock pll select */

#define MAINCLKSEL_MASK 0xFFFFFFFC /**< Reserved bits of the main clock source select register */
typedef enum {
  MAINCLKSEL_IRC = 0u,      /**< Internal resonant crystal oscillator */
  MAINCLKSEL_PLL_IN = 1u,   /**< PLL input */
  MAINCLKSEL_WATCHDOG = 2u, /**< Watchdog oscillator */
  MAINCLKSEL_PLL_OUT = 3u   /**< PLL output */
} MAINCLOCKSEL_Type;

#define MAINCLKUEN_MASK 0xFFFFFFFE /**< Reserved bits of the main clock source update register */
#define MAINCLKUEN_UPDATE (1 << 0) /**< Update main clock source */

/** Clock control 0 peripheral list */
typedef enum {
  CLKCTRL_NONE = 0,            /**< Empty clock enable */
  CLKCTRL_ROM = (1 << 1),      /**< ROM clock enable */
  CLKCTRL_RAM0_1 = (1 << 2),   /**< RAM 0 and 1 clock enable */
  CLKCTRL_FLASHREG = (1 << 3), /**< Flash clock enable */
  CLKCTRL_FLASH = (1 << 4),    /**< Flash clock enable */
  CLKCTRL_I2C0 = (1 << 5),     /**< I2C0 clock enable */
  CLKCTRL_GPIO = (1 << 6),     /**< GPIO clock enable */
  CLKCTRL_SWM = (1 << 7),      /**< SWM clock enable */
  CLKCTRL_SCT = (1 << 8),      /**< SCT clock enable */
  CLKCTRL_WKT = (1 << 9),      /**< WKT clock enable */
  CLKCTRL_MRT = (1 << 10),     /**< MRT clock enable */
  CLKCTRL_SPI0 = (1 << 11),    /**< SPI0 clock enable */
  CLKCTRL_SPI1 = (1 << 12),    /**< SPI1 clock enable */
  CLKCTRL_CRC = (1 << 13),     /**< CRC clock enable */
  CLKCTRL_UART0 = (1 << 14),   /**< UART0 clock enable */
  CLKCTRL_UART1 = (1 << 15),   /**< UART1 clock enable */
  CLKCTRL_UART2 = (1 << 16),   /**< UART2 clock enable */
  CLKCTRL_WWDT = (1 << 17),    /**< WWDT clock enable */
  CLKCTRL_IOCON = (1 << 18),   /**< IOCON clock enable */
  CLKCTRL_ACMP = (1 << 19),    /**< ACMP clock enable */
  CLKCTRL_I2C1 = (1 << 21),    /**< I2C1 clock enable */
  CLKCTRL_I2C2 = (1 << 22),    /**< I2C2 clock enable */
  CLKCTRL_I2C3 = (1 << 23),    /**< I2C3 clock enable */
  CLKCTRL_ADC = (1 << 24),     /**< ADC clock enable */
  CLKCTRL_MTB = (1 << 26),     /**< MTB clock enable */
  CLKCTRL_DMA = (1 << 29),     /**< DMA clock enable */
} SYSCON_CLKCTRL_Type;

typedef enum {
  CLKOUT_IRC = 0,      /**< output IRC clock */
  CLKOUT_SYSOSC = 1,   /**< output System oscillator (crystal oscillator) clock */
  CLKOUT_WATCHDOG = 2, /**< output watchdog */
  CLKOUT_MAIN = 3,     /**< output main clock */
} CLKOUT_SOURCE_Type;

#define CLKOUT_RESERVED_MASK (0xFFFFFFFC)

#define MAINCLKUEN_MASK 0xFFFFFFFE /**< Reserved bits of the main clock source update register */
#define MAINCLKUEN_UPDATE (1 << 0) /**< Update main clock source */

#define SYSAHBCLKDIV_MASK 0xFFFFFF00 /**< Reserved bits of the system clock divider register */

#define SYSAHBCLKCTRL_MASK 0xDA100000 /**< Reserved bits of the peripheral clock control register */

#define UARTCLKDIV_MASK 0xFFFFFF00 /**< Reserved bits of the USART clock divider register */

#define UARTFRGDIV_MASK 0xFFFFFF00 /**< Reserved bits of the USART clock divider register */

#define UARTFRGMULT_MASK 0xFFFFFF00 /**< Reserved bits of the USART clock divider register */

typedef enum {
  PDRUNCFG_IRCOUT = (1 << 0),
  PDRUNCFG_IRC = (1 << 1),
  PDRUNCFG_FLASH = (1 << 2),
  PDRUNCFG_BOD = (1 << 3),
  PDRUNCFG_ADC = (1 << 4),
  PDRUNCFG_SYSOSC = (1 << 5),
  PDRUNCFG_WDTOSC = (1 << 6),
  PDRUNCFG_SYSPLL = (1 << 7),
  PDRUNCFG_ACMP = (1 << 15),
} PDCFG_Type;

#define PDRUNCFG_DEFAULT 0x0000EDF0 /**< Default configuration for Powerdown register */
#define PDRUNCFG_MASK 0xFFFF7F00    /**< Reserved bits */

#include "nxp/LPC8XX/LPC82X_81X_syscon.h"
#include "nxp/LPC8XX/LPC8XX_syscon.h"

#endif