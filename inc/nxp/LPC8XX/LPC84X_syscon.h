/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series system control registers, defines and functions.
 */
#ifndef LPC84X_SYSCON_H
#define LPC84X_SYSCON_H

/** SYSCON - Register Layout Typedef */
typedef volatile struct {
    uint32_t SYSMEMREMAP;           /**< System Remap register, offset: 0x0 */
    uint8_t RESERVED_0[4];
    uint32_t SYSPLLCTRL;            /**< PLL control, offset: 0x8 */
    const uint32_t SYSPLLSTAT;      /**< PLL status, offset: 0xC */
    uint8_t RESERVED_1[16];
    uint32_t SYSOSCCTRL;            /**< system oscillator control, offset: 0x20 */
    uint32_t WDTOSCCTRL;            /**< Watchdog oscillator control, offset: 0x24 */
    uint32_t FROOSCCTRL;            /**< FRO oscillator control, offset: 0x28 */
    uint8_t RESERVED_2[4];
    uint32_t FRODIRECTCLKUEN;       /**< FRO direct clock source update enable register, offset: 0x30 */
    uint8_t RESERVED_3[4];
    uint32_t SYSRSTSTAT;            /**< System reset status register, offset: 0x38 */
    uint8_t RESERVED_4[4];
    uint32_t SYSPLLCLKSEL;          /**< System PLL clock source select register, offset: 0x40 */
    uint32_t SYSPLLCLKUEN;          /**< System PLL clock source update enable register, offset: 0x44 */
    uint32_t MAINCLKPLLSEL;         /**< Main clock source select register, offset: 0x48 */
    uint32_t MAINCLKPLLUEN;         /**< Main clock source update enable register, offset: 0x4C */
    uint32_t MAINCLKSEL;            /**< Main clock source select register, offset: 0x50 */
    uint32_t MAINCLKUEN;            /**< Main clock source update enable register, offset: 0x54 */
    uint32_t SYSAHBCLKDIV;          /**< System clock divider register, offset: 0x58 */
    uint8_t RESERVED_5[4];
    uint32_t CAPTCLKSEL;            /**< CAPT clock source select register, offset: 0x60 */
    uint32_t ADCCLKSEL;             /**< ADC clock source select register, offset: 0x64 */
    uint32_t ADCCLKDIV;             /**< ADC clock divider register, offset: 0x68 */
    uint32_t SCTCLKSEL;             /**< SCT clock source select register, offset: 0x6C */
    uint32_t SCTCLKDIV;             /**< SCT clock divider register, offset: 0x70 */
    uint32_t EXTCLKSEL;             /**< external clock source select register, offset: 0x74 */
    uint8_t RESERVED_6[8];
    uint32_t SYSAHBCLKCTRL0;        /**< System clock group 0 control register, offset: 0x80 */
    uint32_t SYSAHBCLKCTRL1;        /**< System clock group 1 control register, offset: 0x84 */
    uint32_t PRESETCTRL0;           /**< Peripheral reset group 0 control register, offset: 0x88 */
    uint32_t PRESETCTRL1;           /**< Peripheral reset group 1 control register, offset: 0x8C */
    uint32_t FCLKSEL[11];           /**< peripheral clock source select register. FCLK0SEL~FCLK4SEL are for UART0~UART4 clock source select register. FCLK5SEL~FCLK8SEL are for I2C0~I2C3 clock source select register. FCLK9SEL~FCLK10SEL are for SPI0~SPI1 clock source select register., array offset: 0x90, array step: 0x4 */
    uint8_t RESERVED_7[20];
    struct {                        /* offset: 0xD0, array step: 0x10 */
        uint32_t DIV;               /**< fractional generator N divider value register, array offset: 0xD0, array step: 0x10 */
        uint32_t MULT;              /**< fractional generator N multiplier value register, array offset: 0xD4, array step: 0x10 */
        uint32_t CLKSEL;            /**< FRG N clock source select register, array offset: 0xD8, array step: 0x10 */
        uint8_t RESERVED_0[4];
    } FRG[2];
    uint32_t CLKOUTSEL;             /**< CLKOUT clock source select register, offset: 0xF0 */
    uint32_t CLKOUTDIV;             /**< CLKOUT clock divider registers, offset: 0xF4 */
    uint8_t RESERVED_8[4];
    uint32_t EXTTRACECMD;           /**< External trace buffer command register, offset: 0xFC */
    const uint32_t PIOPORCAP[2];    /**< POR captured PIO N status register(PIO0 has 32 PIOs, PIO1 has 22 PIOs), array offset: 0x100, array step: 0x4 */
    uint8_t RESERVED_9[44];
    uint32_t IOCONCLKDIV6;          /**< Peripheral clock 6 to the IOCON block for programmable glitch filter, offset: 0x134 */
    uint32_t IOCONCLKDIV5;          /**< Peripheral clock 6 to the IOCON block for programmable glitch filter, offset: 0x138 */
    uint32_t IOCONCLKDIV4;          /**< Peripheral clock 4 to the IOCON block for programmable glitch filter, offset: 0x13C */
    uint32_t IOCONCLKDIV3;          /**< Peripheral clock 3 to the IOCON block for programmable glitch filter, offset: 0x140 */
    uint32_t IOCONCLKDIV2;          /**< Peripheral clock 2 to the IOCON block for programmable glitch filter, offset: 0x144 */
    uint32_t IOCONCLKDIV1;          /**< Peripheral clock 1 to the IOCON block for programmable glitch filter, offset: 0x148 */
    uint32_t IOCONCLKDIV0;          /**< Peripheral clock 0 to the IOCON block for programmable glitch filter, offset: 0x14C */
    uint32_t BODCTRL;               /**< BOD control register, offset: 0x150 */
    uint32_t SYSTCKCAL;             /**< System tick timer calibration register, offset: 0x154 */
    uint8_t RESERVED_10[24];
    uint32_t IRQLATENCY;            /**< IRQ latency register, offset: 0x170 */
    uint32_t NMISRC;                /**< NMI source selection register, offset: 0x174 */
    uint32_t PINTSEL[8];            /**< Pin interrupt select registers N, array offset: 0x178, array step: 0x4 */
    uint8_t RESERVED_11[108];
    uint32_t STARTERP0;             /**< Start logic 0 pin wake-up enable register 0, offset: 0x204 */
    uint8_t RESERVED_12[12];
    uint32_t STARTERP1;             /**< Start logic 0 pin wake-up enable register 1, offset: 0x214 */
    uint8_t RESERVED_13[24];
    uint32_t PDSLEEPCFG;            /**< Deep-sleep configuration register, offset: 0x230 */
    uint32_t PDAWAKECFG;            /**< Wake-up configuration register, offset: 0x234 */
    uint32_t PDRUNCFG;              /**< Power configuration register, offset: 0x238 */
    uint8_t RESERVED_14[444];
    const uint32_t DEVICE_ID;       /**< Part ID register, offset: 0x3F8 */
} SYSCON_Type;

typedef enum {
    SYSPLLCTRL_POSTDIV_2 = 0u,  /**< Post PLL division ratio of two */
    SYSPLLCTRL_POSTDIV_4 = 1u,  /**< Post PLL division ratio of two */
    SYSPLLCTRL_POSTDIV_8 = 2u,  /**< Post PLL division ratio of two */
    SYSPLLCTRL_POSTDIV_16 = 3u, /**< Post PLL division ratio of two */
} SYSPLLCTRL_PSEL_Type;

#define SYSPLLCTRL_MASK             0xFFFFFF80  /**< Reserved bits of the System PLL control register */

#define SYSOSCCTRL_MASK             0xFFFFFFFC  /**< Reserved bits of System oscillator control register */
#define SYSOSCCTRL_BYPASS           (1 << 0)    /**< Oscillator is bypassed, used with external oscillator */
#define SYSOSCCTRL_FREQ_1_20MHZ     (0 << 1)    /**< Oscillator frequency range from 1 to 20MHz */
#define SYSOSCCTRL_FREQ_15_25MHZ    (1 << 1)    /**< Oscillator frequency range from 15 to 25MHz */

#define SYSPLLCLKSEL_MASK       0xFFFFFFFC   /**< Reserved bits of the Main clock pll select register */
typedef enum {
    SYSPLLCLKSEL_FRO = 0u,      /**< System oscillator (crystal oscillator) */
    SYSPLLCLKSEL_EXTCLK = 1u,   /**< External clock network */
    SYSPLLCLKSEL_WATCHDOG = 2u, /**< Watchdog oscillator */
    SYSPLLCLKSEL_FRO_DIV = 3u   /**< FRO divided by two */
} SYSPLLCLKSEL_Type;

#define SYSPLLCLKUEN_MASK       0xFFFFFFFE  /**< Reserved bits of the main clock pll select update register */
#define SYSPLLCLKUEN_UPDATE     (1 << 0)    /**< Update main clock pll select */

#define MAINCLKPLLSEL_MASK      0xFFFFFFFC  /**< Reserved bits of the Main clock pll select register */
typedef enum {
    MAINCLKPLLSEL_PREPLL = 0u,  /**< Pre PLL */
    MAINCLKPLLSEL_SYSPLL = 1u,  /**< System PLL */
} MAINCLKPLLSEL_Type;

#define MAINCLKPLLUEN_MASK      0xFFFFFFFE  /**< Reserved bits of the main clock pll select update register */
#define MAINCLKPLLUEN_UPDATE    (1 << 0)    /**< Update main clock pll select */

#define MAINCLKSEL_MASK         0xFFFFFFF8  /**< Reserved bits of the main clock source select register */
typedef enum {
    MAINCLKSEL_FRO = 0u,        /**< System oscillator (crystal oscillator) */
    MAINCLKSEL_EXTCLK = 1u,     /**< External clock network */
    MAINCLKSEL_WATCHDOG = 2u,   /**< Watchdog oscillator */
    MAINCLKSEL_FRO_DIV = 3u     /**< FRO divided by two */
} MAINCLOCKSEL_Type;

#define MAINCLKUEN_MASK         0xFFFFFFFE  /**< Reserved bits of the main clock source update register */
#define MAINCLKUEN_UPDATE       (1 << 0)    /**< Update main clock source */

#define SYSAHBCLKDIV_MASK       0xFFFFFF00  /**< Reserved bits of the system clock divider register */

typedef enum {
    EXTCLKSEL_SYSOSC = 0u,  /**< System oscillator (crystal oscillator) */
    EXTCLKSEL_CLK_IN = 1u,  /**< CLK_IN pin */
} EXTCLKSEL_Type;

/** Clock control 0 peripheral list */
typedef enum {
    CLKCTRL0_NONE = 0,              /**< Empty clock enable */
    CLKCTRL0_ROM = (1 << 1),        /**< ROM clock enable */
    CLKCTRL0_RAM0_1 = (1 << 2),     /**< RAM 0 and 1 clock enable */
    CLKCTRL0_FLASH = (1 << 4),      /**< Flash clock enable */
    CLKCTRL0_I2C0 = (1 << 5),       /**< I2C0 clock enable */
    CLKCTRL0_GPIO0 = (1 << 6),      /**< GPIO0 clock enable */
    CLKCTRL0_SWM = (1 << 7),        /**< SWM clock enable */
    CLKCTRL0_SCT = (1 << 8),        /**< SCT clock enable */
    CLKCTRL0_WKT = (1 << 9),        /**< WKT clock enable */
    CLKCTRL0_MRT = (1 << 10),       /**< MRT clock enable */
    CLKCTRL0_SPI0 = (1 << 11),      /**< SPI0 clock enable */
    CLKCTRL0_SPI1 = (1 << 12),      /**< SPI1 clock enable */
    CLKCTRL0_CRC = (1 << 13),       /**< CRC clock enable */
    CLKCTRL0_UART0 = (1 << 14),     /**< UART0 clock enable */
    CLKCTRL0_UART1 = (1 << 15),     /**< UART1 clock enable */
    CLKCTRL0_UART2 = (1 << 16),     /**< UART2 clock enable */
    CLKCTRL0_WWDT = (1 << 17),      /**< WWDT clock enable */
    CLKCTRL0_IOCON = (1 << 18),     /**< IOCON clock enable */
    CLKCTRL0_ACMP = (1 << 19),      /**< ACMP clock enable */
    CLKCTRL0_GPIO1 = (1 << 20),     /**< GPIO1 clock enable */
    CLKCTRL0_I2C1 = (1 << 21),      /**< I2C1 clock enable */
    CLKCTRL0_I2C2 = (1 << 22),      /**< I2C2 clock enable */
    CLKCTRL0_I2C3 = (1 << 23),      /**< I2C3 clock enable */
    CLKCTRL0_ADC = (1 << 24),       /**< ADC clock enable */
    CLKCTRL0_CTIMER0 = (1 << 25),   /**< CTIMER0 clock enable */
    CLKCTRL0_MTB = (1 << 26),       /**< MTB clock enable */
    CLKCTRL0_DAC0 = (1 << 27),      /**< MTB clock enable */
    CLKCTRL0_GPIO_INT = (1 << 28),  /**< GPIO_INT clock enable */
    CLKCTRL0_DMA = (1 << 29),       /**< DMA clock enable */
    CLKCTRL0_UART3 = (1 << 30),     /**< UART3 clock enable */
    CLKCTRL0_UART4 = (1 << 31),     /**< UART4 clock enable */
} SYSCON_CLKCTRL0_Type;

/** Clock control 1 peripheral list */
typedef enum {
    CLKCTRL1_NONE = 0,          /**< Empty clock enable */    
    CLKCTRL1_CAPT = (1 << 0),   /**< CAPT clock enable */
    CLKCTRL1_DAC1 = (1 << 1),   /**< DAC1 clock enable */
} SYSCON_CLKCTRL1_Type;

/** reset control 0 peripheral list */
typedef enum {
    RESETCTRL0_NONE = 0,                /*!< No reset 0 clear */
    RESETCTRL0_FLASH = (1 << 4),        /**< Flash reset clear */
    RESETCTRL0_I2C0 = (1 << 5),         /**< I2C0 reset clear */
    RESETCTRL0_GPIO0 = (1 << 6),        /**< GPIO0 reset clear */
    RESETCTRL0_SWM = (1 << 7),          /**< SWM reset clear */
    RESETCTRL0_SCT = (1 << 8),          /**< SCT reset clear */
    RESETCTRL0_WKT = (1 << 9),          /**< WKT reset clear */
    RESETCTRL0_MRT = (1 << 10),         /**< MRT reset clear */
    RESETCTRL0_SPI0 = (1 << 11),        /**< SPI0 reset clear */
    RESETCTRL0_SPI1 = (1 << 12),        /**< SPI1 reset clear */
    RESETCTRL0_CRC = (1 << 13),         /**< CRC reset clear */
    RESETCTRL0_UART0 = (1 << 14),       /**< UART0 reset clear */
    RESETCTRL0_UART1 = (1 << 15),       /**< UART1 reset clear */
    RESETCTRL0_UART2 = (1 << 16),       /**< UART2 reset clear */
    RESETCTRL0_IOCON = (1 << 18),       /**< IOCON reset clear */
    RESETCTRL0_ACMP = (1 << 19),        /**< ACMP reset clear */
    RESETCTRL0_GPIO1 = (1 << 20),       /**< GPIO1 reset clear */
    RESETCTRL0_I2C1 = (1 << 21),        /**< I2C1 reset clear */
    RESETCTRL0_I2C2 = (1 << 22),        /**< I2C2 reset clear */
    RESETCTRL0_I2C3 = (1 << 23),        /**< I2C3 reset clear */
    RESETCTRL0_ADC = (1 << 24),         /**< ADC reset clear */
    RESETCTRL0_CTIMER0 = (1 << 25),     /**< CTIMER0 reset clear */
    RESETCTRL0_DAC0 = (1 << 27),        /**< MTB reset clear */
    RESETCTRL0_GPIO_INT = (1 << 28),    /**< GPIO_INT reset clear */
    RESETCTRL0_DMA = (1 << 29),         /**< DMA reset clear */
    RESETCTRL0_UART3 = (1 << 30),       /**< UART3 reset clear */
    RESETCTRL0_UART4 = (1 << 31),       /**< UART4 reset clear */
} SYSCON_RESETCTRL0_Type;

/** reset control 1 peripheral list */
typedef enum {
    RESETCTRL1_NONE       = (0),        /*!< no reset clear */
    RESETCTRL1_CAPT       = (1 << 0),   /**< CAPT reset clear */
    RESETCTRL1_DAC1       = (1 << 1),   /**< DAC1 reset clear */
    RESETCTRL1_FRG0       = (1 << 3),   /**< Fractional baud rate generator 0 reset clear */
    RESETCTRL1_FRG1       = (1 << 4),   /**< Fractional baud rate generator 1 reset clear */
} SYSCON_RESETCTRL1_Type;


/** peripheral list for clock source selection, translation happens in function */
/** TODO: make difference between LPC844 and LPC845 as they have different peripherals */
typedef enum {
    UART0CLKSEL = 0,    /**< UART0 clock source select */
    UART1CLKSEL = 1,    /**< UART1 clock source select */
    UART2CLKSEL = 2,    /**< UART2 clock source select */
    UART3CLKSEL = 3,    /**< UART3 clock source select */
    UART4CLKSEL = 4,    /**< UART4 clock source select */
    I2C0CLKSEL = 5,     /**< I2C0 clock source select */
    I2C1CLKSEL = 6,     /**< I2C1 clock source select */
    I2C2CLKSEL = 7,     /**< I2C2 clock source select */
    I2C3CLKSEL = 8,     /**< I2C2 clock source select */
    SPI0CLKSEL = 9,     /**< SPI0 clock source select */
    SPI1CLKSEL = 10,    /**< SPI1 clock source select */
} SYSCON_CLKSEL_Type;

typedef enum {
    CLKSRC_FRO      = 0x0, /**< FRO clock source */
    CLKSRC_MAIN     = 0x1, /**< Main clock clock source */
    CLKSRC_FRG0     = 0x2, /**< FRG0 clock clock source */
    CLKSRC_FRG1     = 0x3, /**< FRG0 clock clock source */
    CLKSRC_FRO_DIV  = 0x4, /**< FRO/2 clock source */
    CLKSRC_NONE     = 0x7, /**< No clock source */
} SYSCON_CLKSRC_Type;

typedef enum {
    FRG0 = 0,   /**< Fractional Rate generator 0 */
    FRG1 = 1,   /**< Fractional Rate generator 1 */
} SYSCON_FRGSEL_Type;

typedef enum {
    FRGSRC_FRO      = 0x0,  /**< FRO clock source for FRG */
    FRGSRC_MAIN     = 0x1,  /**< Main clock source for FRG */
    FRGSRC_SYSPLL   = 0x2,  /**< System PLL clock source for FRG */
    FRGSRC_NONE     = 0x3,  /**< No clock source for FRG */
} SYSCON_FRGSRC_Type;

typedef enum {
    CLKOUT_FRO          = 0, /**< output FRO clock */
    CLKOUT_MAIN         = 1, /**< output main clock */
    CLKOUT_SYS_PLL      = 2, /**< output PLL clock */
    CLKOUT_EXT_CLK      = 3, /**< output external clock */
    CLKOUT_WATCHDOG_CLK = 4, /**< output watchdog clock */
} CLKOUT_SOURCE_Type;

#define CLKOUT_RESERVED_MASK    (0x00000007)

typedef enum {
    PDRUNCFG_FROOUT    = (1 << 0),
    PDRUNCFG_FRO       = (1 << 1),
    PDRUNCFG_FLASH     = (1 << 2),
    PDRUNCFG_BOD       = (1 << 3),
    PDRUNCFG_ADC       = (1 << 4),
    PDRUNCFG_SYSOSC    = (1 << 5),
    PDRUNCFG_WDTOSC    = (1 << 6),
    PDRUNCFG_SYSPLL    = (1 << 7),
    PDRUNCFG_DAC0      = (1 << 13),
    PDRUNCFG_DAC1      = (1 << 14),
    PDRUNCFG_ACMP      = (1 << 15),
} PDCFG_Type;

#define PDRUNCFG_DEFAULT    0x0000EDF8  /**< Default configuration for Powerdown register */
#define PDRUNCFG_MASK       0xFFFF1F00  /**< Default configuration for Powerdown register */

/**
 * @brief   Sets up system PLL
 * @param   peripheral  base address of SYSCON peripheral
 * @param   msel        Feedback divider value
 * @param   psel        Post divider ratio
 * @return  Nothing
 */
static inline void sysconPllControl(SYSCON_Type *peripheral, uint32_t msel, SYSPLLCTRL_PSEL_Type psel)
{
    peripheral->SYSPLLCTRL = (peripheral->SYSPLLCTRL & SYSPLLCTRL_MASK) | msel | (psel << 5);
}

/**
 * @brief   Sets up system PLL
 * @param   peripheral  base address of SYSCON peripheral
 * @return  PLL status, zero is not locked, one is locked
 */
static inline uint32_t sysconPllStatus(SYSCON_Type *peripheral)
{
    return peripheral->SYSPLLSTAT;
}

/**
 * @brief   Sets up system oscillator
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting     Setting for the system oscillator
 * @return  Nothing
 */
static inline void sysconSysOscControl(SYSCON_Type *peripheral, uint32_t setting)
{
    peripheral->SYSOSCCTRL = (peripheral->SYSOSCCTRL & SYSOSCCTRL_MASK ) | setting;
}

/**
 * @brief   Select System clock clock source
 * @param   peripheral  base address of SYSCON peripheral
 * @param   source      Clock source of the main clock network
 * @return  Nothing
 */
static inline void sysconSysPllClockSelect(SYSCON_Type *peripheral, SYSPLLCLKSEL_Type setting)
{
    peripheral->SYSPLLCLKSEL = (peripheral->MAINCLKSEL & SYSPLLCLKSEL_MASK) | setting;
    peripheral->SYSPLLCLKUEN = peripheral->MAINCLKUEN & ~SYSPLLCLKUEN_UPDATE;
    peripheral->SYSPLLCLKUEN = peripheral->MAINCLKUEN | SYSPLLCLKUEN_UPDATE;
}

/**
 * @brief   Select system pll clock source
 * @param   peripheral  base address of SYSCON peripheral
 * @param   source      Clock source of the main clock network
 * @return  Nothing
 */
static inline void sysconMainClockPllSelect(SYSCON_Type *peripheral, MAINCLKPLLSEL_Type setting)
{
    peripheral->MAINCLKPLLSEL = (peripheral->MAINCLKSEL & MAINCLKPLLSEL_MASK) | setting;
    peripheral->MAINCLKPLLUEN = peripheral->MAINCLKUEN & ~MAINCLKPLLUEN_UPDATE;
    peripheral->MAINCLKPLLUEN = peripheral->MAINCLKUEN | MAINCLKPLLUEN_UPDATE;
}

/**
 * @brief   Select main clock source
 * @param   peripheral  base address of SYSCON peripheral
 * @param   source      Clock source of the main clock network
 * @return  Nothing
 */
static inline void sysconMainClockSelect(SYSCON_Type *peripheral, MAINCLOCKSEL_Type setting)
{
    peripheral->MAINCLKSEL = (peripheral->MAINCLKSEL & MAINCLKSEL_MASK) | setting;
    peripheral->MAINCLKUEN = peripheral->MAINCLKUEN & ~MAINCLKUEN_UPDATE;
    peripheral->MAINCLKUEN = peripheral->MAINCLKUEN | MAINCLKUEN_UPDATE;
}

/**
 * @brief   Set main clock divider
 * @param   peripheral  base address of SYSCON peripheral
 * @param   divider     Divider value, 0 is disable, 1 is divide by 1
 * @return  Nothing
 */
static inline void sysconMainClockDivider(SYSCON_Type *peripheral, uint32_t divider)
{
    peripheral->SYSAHBCLKDIV = (peripheral->SYSAHBCLKDIV & MAINCLKSEL_MASK) | divider;
}

/**
 * @brief   Select external clock source
 * @param   peripheral  base address of SYSCON peripheral
 * @param   source      Clock source of the external clock network
 * @return  Nothing
 */
static inline void sysconExternalClockSelect(SYSCON_Type *peripheral, EXTCLKSEL_Type setting)
{
    peripheral->EXTCLKSEL = setting;
}

/**
 * @brief   Enables clocks to various peripherals
 * @param   peripheral  : base address of SYSCON peripheral
 * @param   setting0    Settings for clock control 0 register, see CLKCTRL0 enum
 * @param   setting1    Settings for clock control 1 register, see CLKCTRL1 enum
 * @return  Nothing
 */
static inline void sysconEnableClocks(SYSCON_Type *peripheral, uint32_t setting0, uint32_t setting1)
{
    peripheral->SYSAHBCLKCTRL0 = setting0 | peripheral->SYSAHBCLKCTRL0;
    peripheral->SYSAHBCLKCTRL1 = setting1 | peripheral->SYSAHBCLKCTRL1;
}

/**
 * @brief   Disables clocks to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   setting0    Settings for clock control 0 register, see CLKCTRL0 enum
 * @param   setting1    Settings for clock control 1 register, see CLKCTRL1 enum
 * @return  Nothing
 */
static inline void sysconDisableClocks(SYSCON_Type *peripheral, uint32_t setting0, uint32_t setting1)
{
    peripheral->SYSAHBCLKCTRL0 = ~setting0 & peripheral->SYSAHBCLKCTRL0;
    peripheral->SYSAHBCLKCTRL1 = ~setting1 & peripheral->SYSAHBCLKCTRL1;
}

/**
 * @brief   Enables reset signal to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   resets0     Settings for reset control 0 register, see RESETCTRL0 enum
 * @param   resets1     Settings for reset control 1 register, see RESETCTRL1 enum
 * @return  Nothing
 */
static inline void sysconEnableResets(SYSCON_Type *peripheral, uint32_t resets0, uint32_t resets1)
{
    peripheral->PRESETCTRL0 = resets0 | peripheral->PRESETCTRL0;
    peripheral->PRESETCTRL1 = resets1 | peripheral->PRESETCTRL1;
}

/**
 * @brief   Disables reset signal to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   resets0     Settings for reset control 0 register, see RESETCTRL0 enum
 * @param   resets1     Settings for reset control 1 register, see RESETCTRL1 enum
 * @return  Nothing
 */
static inline void sysconDisableResets(SYSCON_Type *peripheral, uint32_t resets0, uint32_t resets1)
{
    peripheral->PRESETCTRL0 = ~resets0 & peripheral->PRESETCTRL0;
    peripheral->PRESETCTRL1 = ~resets1 & peripheral->PRESETCTRL1;
}

/**
 * @brief   Select the clock input for a peripheral
 * @param   peripheral  base address of SYSCON peripheral
 * @param   select      Peripheral to setup the clock for
 * @param   source      Clock source to connect to the peripheral
 */
static inline void sysconPeripheralClockSelect(SYSCON_Type *peripheral, SYSCON_CLKSEL_Type select, SYSCON_CLKSRC_Type source)
{
    peripheral->FCLKSEL[select] = (peripheral->FCLKSEL[select] & 0xFFFFFFF8) | source;
}

/**
 * @brief   Setup Fractional clock generator
 * @param   peripheral  base address of SYSCON peripheral
 * @param   frg         FRG to configure
 * @param   divider     DIV value for FRG
 * @param   multiplier  MULT value for FRG
 * @param   source      source for the FRG
 */
static inline void sysconFrg0Setup(SYSCON_Type *peripheral, SYSCON_FRGSEL_Type frg, uint8_t divider, uint8_t multiplier, SYSCON_FRGSRC_Type source)
{
    peripheral->FRG[frg].DIV = divider;
    peripheral->FRG[frg].MULT = multiplier;
    peripheral->FRG[frg].CLKSEL = source;
}

/**
 * @brief   Select clock source to output on CLKOUT pin
 * @param   peripheral  base address of SYSCON peripheral
 * @param   source      clock source, see CLKOUT_SOURCE_Type enum
 * @return  Nothing
 */
static inline void sysconClkoutSource(SYSCON_Type *peripheral, CLKOUT_SOURCE_Type source)
{
    peripheral->CLKOUTSEL = source & CLKOUT_RESERVED_MASK;
}

/**
 * @brief   set CLKOUT divider
 * @param   peripheral  base address of SYSCON peripheral
 * @param   divider     division value, 0 means divider disabled, 1 is divide by 1
 * @return  Nothing
 */
static inline void sysconClkoutDivider(SYSCON_Type *peripheral, uint8_t divider)
{
    peripheral->CLKOUTDIV = divider;
}

/**
 * @brief   Enable power to various peripherals
 * @param   peripheral      base address of SYSCON peripheral
 * @param   powerEnables    set of peripherals to give power
 * @return  Nothing
 */
static inline void sysconPowerEnable(SYSCON_Type *peripheral, uint32_t powerEnables)
{
    peripheral->PDRUNCFG = peripheral->PDRUNCFG & (~powerEnables | PDRUNCFG_MASK);
}
 
/**
 * @brief   Disable power to various peripherals
 * @param   peripheral      base address of SYSCON peripheral
 * @param   powerDisables   set of peripherals to remove power
 * @return  Nothing
 */
static inline void sysconPowerDisable(SYSCON_Type *peripheral, uint32_t powerDisables)
{
    peripheral->PDRUNCFG = peripheral->PDRUNCFG | (powerDisables & ~PDRUNCFG_MASK);
}

#endif
