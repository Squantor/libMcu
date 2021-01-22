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
typedef struct {
    __IO uint32_t SYSMEMREMAP;       /**< System Remap register, offset: 0x0 */
         uint8_t RESERVED_0[4];
    __IO uint32_t SYSPLLCTRL;        /**< PLL control, offset: 0x8 */
    __I  uint32_t SYSPLLSTAT;        /**< PLL status, offset: 0xC */
         uint8_t RESERVED_1[16];
    __IO uint32_t SYSOSCCTRL;        /**< system oscillator control, offset: 0x20 */
    __IO uint32_t WDTOSCCTRL;        /**< Watchdog oscillator control, offset: 0x24 */
    __IO uint32_t FROOSCCTRL;        /**< FRO oscillator control, offset: 0x28 */
         uint8_t RESERVED_2[4];
    __IO uint32_t FRODIRECTCLKUEN;   /**< FRO direct clock source update enable register, offset: 0x30 */
         uint8_t RESERVED_3[4];
    __IO uint32_t SYSRSTSTAT;        /**< System reset status register, offset: 0x38 */
         uint8_t RESERVED_4[4];
    __IO uint32_t SYSPLLCLKSEL;      /**< System PLL clock source select register, offset: 0x40 */
    __IO uint32_t SYSPLLCLKUEN;      /**< System PLL clock source update enable register, offset: 0x44 */
    __IO uint32_t MAINCLKPLLSEL;     /**< Main clock source select register, offset: 0x48 */
    __IO uint32_t MAINCLKPLLUEN;     /**< Main clock source update enable register, offset: 0x4C */
    __IO uint32_t MAINCLKSEL;        /**< Main clock source select register, offset: 0x50 */
    __IO uint32_t MAINCLKUEN;        /**< Main clock source update enable register, offset: 0x54 */
    __IO uint32_t SYSAHBCLKDIV;      /**< System clock divider register, offset: 0x58 */
         uint8_t RESERVED_5[4];
    __IO uint32_t CAPTCLKSEL;        /**< CAPT clock source select register, offset: 0x60 */
    __IO uint32_t ADCCLKSEL;         /**< ADC clock source select register, offset: 0x64 */
    __IO uint32_t ADCCLKDIV;         /**< ADC clock divider register, offset: 0x68 */
    __IO uint32_t SCTCLKSEL;         /**< SCT clock source select register, offset: 0x6C */
    __IO uint32_t SCTCLKDIV;         /**< SCT clock divider register, offset: 0x70 */
    __IO uint32_t EXTCLKSEL;         /**< external clock source select register, offset: 0x74 */
         uint8_t RESERVED_6[8];
    __IO uint32_t SYSAHBCLKCTRL0;    /**< System clock group 0 control register, offset: 0x80 */
    __IO uint32_t SYSAHBCLKCTRL1;    /**< System clock group 1 control register, offset: 0x84 */
    __IO uint32_t PRESETCTRL0;       /**< Peripheral reset group 0 control register, offset: 0x88 */
    __IO uint32_t PRESETCTRL1;       /**< Peripheral reset group 1 control register, offset: 0x8C */
    __IO uint32_t FCLKSEL[11];       /**< peripheral clock source select register. FCLK0SEL~FCLK4SEL are for UART0~UART4 clock source select register. FCLK5SEL~FCLK8SEL are for I2C0~I2C3 clock source select register. FCLK9SEL~FCLK10SEL are for SPI0~SPI1 clock source select register., array offset: 0x90, array step: 0x4 */
         uint8_t RESERVED_7[20];
    struct {                                         /* offset: 0xD0, array step: 0x10 */
        __IO uint32_t FRGDIV;          /**< fractional generator N divider value register, array offset: 0xD0, array step: 0x10 */
        __IO uint32_t FRGMULT;         /**< fractional generator N multiplier value register, array offset: 0xD4, array step: 0x10 */
        __IO uint32_t FRGCLKSEL;       /**< FRG N clock source select register, array offset: 0xD8, array step: 0x10 */
             uint8_t RESERVED_0[4];
    } FRG[2];
    __IO uint32_t CLKOUTSEL;         /**< CLKOUT clock source select register, offset: 0xF0 */
    __IO uint32_t CLKOUTDIV;         /**< CLKOUT clock divider registers, offset: 0xF4 */
         uint8_t RESERVED_8[4];
    __IO uint32_t EXTTRACECMD;       /**< External trace buffer command register, offset: 0xFC */
    __I  uint32_t PIOPORCAP[2];      /**< POR captured PIO N status register(PIO0 has 32 PIOs, PIO1 has 22 PIOs), array offset: 0x100, array step: 0x4 */
         uint8_t RESERVED_9[44];
    __IO uint32_t IOCONCLKDIV6;      /**< Peripheral clock 6 to the IOCON block for programmable glitch filter, offset: 0x134 */
    __IO uint32_t IOCONCLKDIV5;      /**< Peripheral clock 6 to the IOCON block for programmable glitch filter, offset: 0x138 */
    __IO uint32_t IOCONCLKDIV4;      /**< Peripheral clock 4 to the IOCON block for programmable glitch filter, offset: 0x13C */
    __IO uint32_t IOCONCLKDIV3;      /**< Peripheral clock 3 to the IOCON block for programmable glitch filter, offset: 0x140 */
    __IO uint32_t IOCONCLKDIV2;      /**< Peripheral clock 2 to the IOCON block for programmable glitch filter, offset: 0x144 */
    __IO uint32_t IOCONCLKDIV1;      /**< Peripheral clock 1 to the IOCON block for programmable glitch filter, offset: 0x148 */
    __IO uint32_t IOCONCLKDIV0;      /**< Peripheral clock 0 to the IOCON block for programmable glitch filter, offset: 0x14C */
    __IO uint32_t BODCTRL;           /**< BOD control register, offset: 0x150 */
    __IO uint32_t SYSTCKCAL;         /**< System tick timer calibration register, offset: 0x154 */
         uint8_t RESERVED_10[24];
    __IO uint32_t IRQLATENCY;        /**< IRQ latency register, offset: 0x170 */
    __IO uint32_t NMISRC;            /**< NMI source selection register, offset: 0x174 */
    __IO uint32_t PINTSEL[8];        /**< Pin interrupt select registers N, array offset: 0x178, array step: 0x4 */
         uint8_t RESERVED_11[108];
    __IO uint32_t STARTERP0;         /**< Start logic 0 pin wake-up enable register 0, offset: 0x204 */
         uint8_t RESERVED_12[12];
    __IO uint32_t STARTERP1;         /**< Start logic 0 pin wake-up enable register 1, offset: 0x214 */
         uint8_t RESERVED_13[24];
    __IO uint32_t PDSLEEPCFG;        /**< Deep-sleep configuration register, offset: 0x230 */
    __IO uint32_t PDAWAKECFG;        /**< Wake-up configuration register, offset: 0x234 */
    __IO uint32_t PDRUNCFG;          /**< Power configuration register, offset: 0x238 */
         uint8_t RESERVED_14[444];
    __I  uint32_t DEVICE_ID;         /**< Part ID register, offset: 0x3F8 */
} SYSCON_Type;

/** Clock control 0 peripheral list */
typedef enum {
    CLKCTRL0_NONE       = 0,            /**< Empty clock enable */
    CLKCTRL0_ROM        = (1 << 1),     /**< ROM clock enable */
    CLKCTRL0_RAM0_1     = (1 << 2),     /**< RAM 0 and 1 clock enable */
    CLKCTRL0_FLASH      = (1 << 4),     /**< Flash clock enable */
    CLKCTRL0_I2C0       = (1 << 5),     /**< I2C0 clock enable */
    CLKCTRL0_GPIO0      = (1 << 6),     /**< GPIO0 clock enable */
    CLKCTRL0_SWM        = (1 << 7),     /**< SWM clock enable */
    CLKCTRL0_SCT        = (1 << 8),     /**< SCT clock enable */
    CLKCTRL0_WKT        = (1 << 9),     /**< WKT clock enable */
    CLKCTRL0_MRT        = (1 << 10),    /**< MRT clock enable */
    CLKCTRL0_SPI0       = (1 << 11),    /**< SPI0 clock enable */
    CLKCTRL0_SPI1       = (1 << 12),    /**< SPI1 clock enable */
    CLKCTRL0_CRC        = (1 << 13),    /**< CRC clock enable */
    CLKCTRL0_UART0      = (1 << 14),    /**< UART0 clock enable */
    CLKCTRL0_UART1      = (1 << 15),    /**< UART1 clock enable */
    CLKCTRL0_UART2      = (1 << 16),    /**< UART2 clock enable */
    CLKCTRL0_WWDT       = (1 << 17),    /**< WWDT clock enable */
    CLKCTRL0_IOCON      = (1 << 18),    /**< IOCON clock enable */
    CLKCTRL0_ACMP       = (1 << 19),    /**< ACMP clock enable */
    CLKCTRL0_GPIO1      = (1 << 20),    /**< GPIO1 clock enable */
    CLKCTRL0_I2C1       = (1 << 21),    /**< I2C1 clock enable */
    CLKCTRL0_I2C2       = (1 << 22),    /**< I2C2 clock enable */
    CLKCTRL0_I2C3       = (1 << 23),    /**< I2C3 clock enable */
    CLKCTRL0_ADC        = (1 << 24),    /**< ADC clock enable */
    CLKCTRL0_CTIMER0    = (1 << 25),    /**< CTIMER0 clock enable */
    CLKCTRL0_MTB        = (1 << 26),    /**< MTB clock enable */
    CLKCTRL0_DAC0       = (1 << 27),    /**< MTB clock enable */
    CLKCTRL0_GPIO_INT   = (1 << 28),    /**< GPIO_INT clock enable */
    CLKCTRL0_DMA        = (1 << 29),    /**< DMA clock enable */
    CLKCTRL0_UART3      = (1 << 30),    /**< UART3 clock enable */
    CLKCTRL0_UART4      = (1 << 31),    /**< UART4 clock enable */
} SYSCON_CLKCTRL0_Type;

/** Clock control 1 peripheral list */
typedef enum {
    CLKCTRL1_NONE       = 0,        /**< Empty clock enable */    
    CLKCTRL1_CAPT       = (1 << 0), /**< CAPT clock enable */
    CLKCTRL1_DAC1       = (1 << 1), /**< DAC1 clock enable */
} SYSCON_CLKCTRL1_Type;

/** reset control 0 peripheral list */
typedef enum {
    RESETCTRL0_FLASH      = (1 << 4),     /**< Flash reset clear */
    RESETCTRL0_I2C0       = (1 << 5),     /**< I2C0 reset clear */
    RESETCTRL0_GPIO0      = (1 << 6),     /**< GPIO0 reset clear */
    RESETCTRL0_SWM        = (1 << 7),     /**< SWM reset clear */
    RESETCTRL0_SCT        = (1 << 8),     /**< SCT reset clear */
    RESETCTRL0_WKT        = (1 << 9),     /**< WKT reset clear */
    RESETCTRL0_MRT        = (1 << 10),    /**< MRT reset clear */
    RESETCTRL0_SPI0       = (1 << 11),    /**< SPI0 reset clear */
    RESETCTRL0_SPI1       = (1 << 12),    /**< SPI1 reset clear */
    RESETCTRL0_CRC        = (1 << 13),    /**< CRC reset clear */
    RESETCTRL0_UART0      = (1 << 14),    /**< UART0 reset clear */
    RESETCTRL0_UART1      = (1 << 15),    /**< UART1 reset clear */
    RESETCTRL0_UART2      = (1 << 16),    /**< UART2 reset clear */
    RESETCTRL0_IOCON      = (1 << 18),    /**< IOCON reset clear */
    RESETCTRL0_ACMP       = (1 << 19),    /**< ACMP reset clear */
    RESETCTRL0_GPIO1      = (1 << 20),    /**< GPIO1 reset clear */
    RESETCTRL0_I2C1       = (1 << 21),    /**< I2C1 reset clear */
    RESETCTRL0_I2C2       = (1 << 22),    /**< I2C2 reset clear */
    RESETCTRL0_I2C3       = (1 << 23),    /**< I2C3 reset clear */
    RESETCTRL0_ADC        = (1 << 24),    /**< ADC reset clear */
    RESETCTRL0_CTIMER0    = (1 << 25),    /**< CTIMER0 reset clear */
    RESETCTRL0_DAC0       = (1 << 27),    /**< MTB reset clear */
    RESETCTRL0_GPIO_INT   = (1 << 28),    /**< GPIO_INT reset clear */
    RESETCTRL0_DMA        = (1 << 29),    /**< DMA reset clear */
    RESETCTRL0_UART3      = (1 << 30),    /**< UART3 reset clear */
    RESETCTRL0_UART4      = (1 << 31),    /**< UART4 reset clear */
} SYSCON_RESETCTRL0_Type;

/** reset control 1 peripheral list */
typedef enum {
    RESETCTRL1_CAPT       = (1 << 0),    /**< CAPT reset clear */
    RESETCTRL1_DAC1       = (1 << 1),    /**< DAC1 reset clear */
    RESETCTRL1_FRG0       = (1 << 3),    /**< Fractional baud rate generator 0 reset clear */
    RESETCTRL1_FRG1       = (1 << 4),    /**< Fractional baud rate generator 1 reset clear */
} SYSCON_RESETCTRL1_Type;

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

#define PDRUNCFG_DEFAULT        0x0000EDF8  /**< Default configuration for Powerdown register */
#define PDRUNCFG_RESERVED_MASK  0x00001F00  /**< Default configuration for Powerdown register */

/**
 * @brief   Enables clocks to various peripherals
 * @param   peripheral  : base address of SYSCON peripheral
 * @param   setting0    Settings for clock control 0 register, see CLKCTRL0 enum
 * @param   setting1    Settings for clock control 1 register, see CLKCTRL1 enum
 * @return  Nothing
 */
static inline void sysconlEnableClocks(SYSCON_Type *peripheral, uint32_t setting0, uint32_t setting1)
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
static inline void sysconlDisableClocks(SYSCON_Type *peripheral, uint32_t setting0, uint32_t setting1)
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
static inline void sysconlEnableResets(SYSCON_Type *peripheral, uint32_t resets0, uint32_t resets1)
{
    peripheral->SYSAHBCLKCTRL0 = resets0 | peripheral->SYSAHBCLKCTRL0;
    peripheral->SYSAHBCLKCTRL1 = resets1 | peripheral->SYSAHBCLKCTRL1;
}

/**
 * @brief   Disables reset signal to various peripherals
 * @param   peripheral  base address of SYSCON peripheral
 * @param   resets0     Settings for reset control 0 register, see RESETCTRL0 enum
 * @param   resets1     Settings for reset control 1 register, see RESETCTRL1 enum
 * @return  Nothing
 */
static inline void sysconlDisableResets(SYSCON_Type *peripheral, uint32_t resets0, uint32_t resets1)
{
    peripheral->SYSAHBCLKCTRL0 = ~resets0 & peripheral->SYSAHBCLKCTRL0;
    peripheral->SYSAHBCLKCTRL1 = ~resets1 & peripheral->SYSAHBCLKCTRL1;
}

/**
 * @brief   Select clock source to output on CLKOUT pin
 * @param   peripheral  base address of SYSCON peripheral
 * @param   source      clock source, see CLKOUT_SOURCE_Type enum
 * @return  Nothing
 */
static inline void sysconlClkoutSource(SYSCON_Type *peripheral, CLKOUT_SOURCE_Type source)
{
    peripheral->CLKOUTSEL = source & CLKOUT_RESERVED_MASK;
}

/**
 * @brief   set CLKOUT divider
 * @param   peripheral  base address of SYSCON peripheral
 * @param   divider     division value
 * @return  Nothing
 */
static inline void sysconlClkoutDivider(SYSCON_Type *peripheral, uint8_t divider)
{
    peripheral->CLKOUTDIV = divider;
}

/**
 * @brief   Enable power to various peripherals
 * @param   peripheral      base address of SYSCON peripheral
 * @param   powerEnables    set of peripherals to give power
 * @return  Nothing
 */
static inline void sysconlPowerEnable(SYSCON_Type *peripheral, uint32_t powerEnables)
{
    peripheral->PDRUNCFG = peripheral->PDRUNCFG & ~(powerEnables & ~PDRUNCFG_RESERVED_MASK);
}

/**
 * @brief   Disable power to various peripherals
 * @param   peripheral      base address of SYSCON peripheral
 * @param   powerDisables   set of peripherals to remove power
 * @return  Nothing
 */
static inline void sysconlPowerDisable(SYSCON_Type *peripheral, uint32_t powerDisables)
{
    peripheral->PDRUNCFG = peripheral->PDRUNCFG | (powerDisables & ~PDRUNCFG_RESERVED_MASK);
}

#endif
