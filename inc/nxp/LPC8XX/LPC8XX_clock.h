/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series common clocking registers, defines and functions.
*/
#ifndef LPC8XX_CLOCK_H
#define LPC8XX_CLOCK_H

/* Internal oscillator frequency */
#define SYSCTL_IRC_FREQ     (12000000)
#ifndef MAX_CLOCK_FREQ
#define MAX_CLOCK_FREQ      (30000000)
#endif

typedef enum SYSCTL_PLLCLKSRC {
    SYSCTL_PLLCLKSRC_IRC = 0,        /*!< Internal oscillator */
    SYSCTL_PLLCLKSRC_SYSOSC,        /*!< Crystal (system) oscillator */
    SYSCTL_PLLCLKSRC_RESERVED,
    SYSCTL_PLLCLKSRC_EXT_CLKIN,    /*!< External clock input */
} SYSCTL_PLLCLKSRC_T;

typedef enum WDTLFO_OSC {
    WDTLFO_OSC_ILLEGAL,
    WDTLFO_OSC_0_60,
    WDTLFO_OSC_1_05,
    WDTLFO_OSC_1_40,
    WDTLFO_OSC_1_75,
    WDTLFO_OSC_2_10,
    WDTLFO_OSC_2_40,
    WDTLFO_OSC_2_70,
    WDTLFO_OSC_3_00,
    WDTLFO_OSC_3_25,
    WDTLFO_OSC_3_50,
    WDTLFO_OSC_3_75,
    WDTLFO_OSC_4_00,
    WDTLFO_OSC_4_20,
    WDTLFO_OSC_4_40,
    WDTLFO_OSC_4_60
} WDTLFO_OSC_T;

typedef enum SYSCTL_MAINCLKSRC {
    SYSCTL_MAINCLKSRC_IRC = 0,
    SYSCTL_MAINCLKSRC_PLLIN,
    SYSCTL_MAINCLKSRC_WDTOSC,
    SYSCTL_MAINCLKSRC_PLLOUT,
} SYSCTL_MAINCLKSRC_T;

typedef enum SYSCTL_CLOCK {
    SYSCTL_CLOCK_SYS = 0,    /*!< System clock */
    SYSCTL_CLOCK_ROM,        /*!< ROM clock */
    SYSCTL_CLOCK_RAM,        /*!< RAM clock */
    SYSCTL_CLOCK_FLASHREG,    /*!< FLASH register interface clock */
    SYSCTL_CLOCK_FLASH,        /*!< FLASH array access clock */
    SYSCTL_CLOCK_I2C0,        /*!< I2C0 clock */
    SYSCTL_CLOCK_GPIO,        /*!< GPIO clock */
    SYSCTL_CLOCK_SWM,        /*!< Switch matrix clock */
    SYSCTL_CLOCK_SCT,        /*!< State configurable timer clock */
    SYSCTL_CLOCK_WKT,        /*!< Self wake-up timer clock */
    SYSCTL_CLOCK_MRT,        /*!< Multi-rate timer clock */
    SYSCTL_CLOCK_SPI0,        /*!< SPI0 clock */
    SYSCTL_CLOCK_SPI1,        /*!< SPI01 clock */
    SYSCTL_CLOCK_CRC,        /*!< CRC clock */
    SYSCTL_CLOCK_UART0,        /*!< UART0 clock */
    SYSCTL_CLOCK_UART1,        /*!< UART1 clock */
    SYSCTL_CLOCK_UART2,        /*!< UART2 clock */
    SYSCTL_CLOCK_WWDT,        /*!< Watchdog clock */
    SYSCTL_CLOCK_IOCON,        /*!< IOCON clock */
    SYSCTL_CLOCK_ACOMP,        /*!< Analog comparator clock */

    /* LPC82x Specific Clocks */
    SYSCTL_CLOCK_I2C1 = 21, /*!< I2C1 Clock */
    SYSCTL_CLOCK_I2C2,      /*!< I2C2 Clock */
    SYSCTL_CLOCK_I2C3,      /*!< I2C3 Clock */
    SYSCTL_CLOCK_ADC,       /*!< 12-Bit ADC Clock */
    SYSCTL_CLOCK_MTB = 26,  /*!< Macro Trace Buffer [USED FOR DEBUGGING] */
    SYSCTL_CLOCK_DMA = 29,  /*!< DMA Clock */
} SYSCTL_CLOCK_T;

typedef enum SYSCTL_CLKOUTSRC {
    SYSCTL_CLKOUTSRC_IRC = 0,        /*!< Internal oscillator for CLKOUT */
    SYSCTL_CLKOUTSRC_SYSOSC,        /*!< System oscillator for CLKOUT */
    SYSCTL_CLKOUTSRC_WDTOSC,        /*!< Watchdog oscillator for CLKOUT */
    SYSCTL_CLKOUTSRC_MAINSYSCLK,    /*!< Main system clock for CLKOUT */
} SYSCTL_CLKOUTSRC_T;

static inline uint32_t ClockGetIntOscRate(void)
{
    return SYSCTL_IRC_FREQ;
}

static inline uint32_t ClockGetSystemPLLInClockRate(void)
{
    uint32_t clkRate;

    switch ((SYSCTL_PLLCLKSRC_T) (LPC_SYSCTL->SYSPLLCLKSEL & 0x3)) {
    case SYSCTL_PLLCLKSRC_IRC:
        clkRate = ClockGetIntOscRate();
        break;

    case SYSCTL_PLLCLKSRC_SYSOSC:
        clkRate = CLOCK_XTAL;
        break;
    
    case SYSCTL_PLLCLKSRC_EXT_CLKIN:
        clkRate = CLOCK_EXT_IN;
        break;

    default:
        clkRate = 0;
    }
    return clkRate;
}

/* Compute a WDT or LFO rate */
static inline uint32_t ClockGetWdtLfoRate(uint32_t reg)
{
    uint32_t div;
    WDTLFO_OSC_T clk;

    /* Get WDT oscillator settings */
    clk = (WDTLFO_OSC_T) ((reg >> 5) & 0xF);
    div = reg & 0x1F;
    
    // translating table from LPCopen to a big switch case
    uint32_t wdtOscRate;
    switch(clk)
    {
        case 0: wdtOscRate = 0; break;
        case 1: wdtOscRate = 600000; break;
        case 2: wdtOscRate = 1050000; break;
        case 3: wdtOscRate = 1400000; break;
        case 4: wdtOscRate = 1750000; break;
        case 5: wdtOscRate = 2100000; break;
        case 6: wdtOscRate = 2400000; break;
        case 7: wdtOscRate = 2700000; break;
        case 8: wdtOscRate = 3000000; break;
        case 9: wdtOscRate = 3250000; break;
        case 10: wdtOscRate = 3500000; break;
        case 11: wdtOscRate = 3750000; break;
        case 12: wdtOscRate = 4000000; break;
        case 13: wdtOscRate = 4200000; break;
        case 14: wdtOscRate = 4400000; break;
        case 15: wdtOscRate = 4600000; break;
        // we could some assert for the next case
        default: wdtOscRate = 0; break;
    }

    return wdtOscRate / ((div + 1) << 1);
}

static inline uint32_t ClockGetWDTOSCRate(void)
{
    return ClockGetWdtLfoRate(
        LPC_SYSCTL->WDTOSCCTRL & ~SYSCTL_WDTOSCCTRL_RESERVED
        );
}

static inline uint32_t ClockGetPLLFreq(uint32_t PLLReg, uint32_t inputRate)
{
    uint32_t m_val = ((PLLReg & 0x1F) + 1);

    return (inputRate * m_val);
}

static inline uint32_t ClockGetSystemPLLOutClockRate(void)
{
    return ClockGetPLLFreq(
        (LPC_SYSCTL->SYSPLLCTRL & ~SYSCTL_SYSPLLCTRL_RESERVED),
        ClockGetSystemPLLInClockRate()
        );
}

static inline uint32_t ClockGetMainClockRate(void)
{
	uint32_t clkRate = 0;
    #ifdef CLOCK_MAIN_SOURCE
    switch (CLOCK_MAIN_SOURCE) 
    {
        case SYSCTL_MAINCLKSRC_IRC:
            clkRate = ClockGetIntOscRate();
            break;

        case SYSCTL_MAINCLKSRC_PLLIN:
            clkRate = ClockGetSystemPLLInClockRate();
            break;

        case SYSCTL_MAINCLKSRC_WDTOSC:
            clkRate = ClockGetWDTOSCRate();
            break;

        case SYSCTL_MAINCLKSRC_PLLOUT:
            clkRate = ClockGetSystemPLLOutClockRate();
            break;
    }
    #else
    switch ((SYSCTL_MAINCLKSRC_T) (LPC_SYSCTL->MAINCLKSEL & 0x3)) 
    {
        case SYSCTL_MAINCLKSRC_IRC:
            clkRate = ClockGetIntOscRate();
            break;

        case SYSCTL_MAINCLKSRC_PLLIN:
            clkRate = ClockGetSystemPLLInClockRate();
            break;

        case SYSCTL_MAINCLKSRC_WDTOSC:
            clkRate = ClockGetWDTOSCRate();
            break;

        case SYSCTL_MAINCLKSRC_PLLOUT:
            clkRate = ClockGetSystemPLLOutClockRate();
            break;
    }
    #endif

	return clkRate;
}

static inline void ClockSetupSystemPLL(uint8_t msel, uint8_t psel)
{
    LPC_SYSCTL->SYSPLLCTRL = (msel & 0x1F) | ((psel & 0x3) << 5);
}

static inline bool ClockIsSystemPLLLocked(void)
{
    return (bool) ((LPC_SYSCTL->SYSPLLSTAT & 1) != 0);
}

static inline void ClockSetWDTOSC(WDTLFO_OSC_T wdtclk, uint8_t div)
{
    LPC_SYSCTL->WDTOSCCTRL  = (((uint32_t) wdtclk) << 5) | ((div >> 1) - 1);
}

static inline SYSCTL_MAINCLKSRC_T ClockGetMainClockSource(void)
{
    return (SYSCTL_MAINCLKSRC_T) (LPC_SYSCTL->MAINCLKSEL & ~SYSCTL_MAINCLKSEL_RESERVED);
}

static inline void ClockSetSysClockDiv(uint32_t div)
{
    LPC_SYSCTL->SYSAHBCLKDIV  = div;
}

static inline void ClockEnablePeriphClock(SYSCTL_CLOCK_T clk)
{
    LPC_SYSCTL->SYSAHBCLKCTRL = (1 << clk) | (LPC_SYSCTL->SYSAHBCLKCTRL & ~SYSCTL_SYSAHBCLKCTRL_RESERVED);
}

static inline void ClockDisablePeriphClock(SYSCTL_CLOCK_T clk)
{
    uint32_t sysahbclkctrlRegister = LPC_SYSCTL->SYSAHBCLKCTRL & ~((1 << clk) | SYSCTL_SYSAHBCLKCTRL_RESERVED);
    LPC_SYSCTL->SYSAHBCLKCTRL = sysahbclkctrlRegister;
}

static inline void ClockSetUARTClockDiv(uint32_t div)
{
    LPC_SYSCTL->UARTCLKDIV = div;
}

static inline uint32_t ClockGetUARTClockDiv(void)
{
    return LPC_SYSCTL->UARTCLKDIV & ~SYSCTL_UARTCLKDIV_RESERVED;
}

static inline void SysctlSetUSARTFRGDivider(uint8_t div)
{
    LPC_SYSCTL->UARTFRGDIV = (uint32_t) div;
}

static inline uint32_t SysctlGetUSARTFRGDivider(void)
{
    return LPC_SYSCTL->UARTFRGDIV & ~SYSCTL_UARTFRGDIV_RESERVED;
}

static inline void SysctlSetUSARTFRGMultiplier(uint8_t mult)
{
    LPC_SYSCTL->UARTFRGMULT = (uint32_t) mult;
}

static inline uint32_t SysctlGetUSARTFRGMultiplier(void)
{
    return LPC_SYSCTL->UARTFRGMULT & ~SYSCTL_UARTFRGMULT_RESERVED;
}

static inline uint32_t ClockGetUSARTNBaseClockRate(void)
{
    uint64_t inclk;
	uint32_t div;

	div = (uint32_t) ClockGetUARTClockDiv();
	if (div == 0) {
		/* Divider is 0 so UART clock is disabled */
		inclk = 0;
	}
	else {
		uint32_t mult, divf;

		/* Input clock into FRG block is the divided main system clock */
		inclk = (uint64_t) (ClockGetMainClockRate() / div);

		divf = SysctlGetUSARTFRGDivider();
		if (divf == 0xFF) {
			/* Fractional part is enabled, get multiplier */
			mult = (uint32_t) SysctlGetUSARTFRGMultiplier();

			/* Get fractional error */
			inclk = (inclk * 256) / (uint64_t) (256 + mult);
		}
	}

	return (uint32_t) inclk;
}

static inline uint32_t ClockSetUSARTNBaseClockRate(uint32_t rate, bool fEnable)
{
	uint32_t div, inclk;

	inclk = ClockGetMainClockRate();

	/* Get integer divider for coarse rate */
	div = inclk / rate;
	if (div == 0) {
		div = 1;
	}

	/* Approximated rate with only integer divider */
	ClockSetUARTClockDiv((uint8_t) div);

	if (fEnable) {
		uint32_t uart_fra_multiplier;

		SysctlPeriphReset(RESET_UARTFBRG);

		/* Enable fractional divider */
		SysctlSetUSARTFRGDivider(0xFF);

		/* Compute the fractional divisor (the lower byte is the
		   fractional portion) */
		uart_fra_multiplier = ((inclk / div) * 256) / rate;

		/* ...just the fractional portion (the lower byte) */
		SysctlSetUSARTFRGMultiplier((uint8_t) uart_fra_multiplier);
	}
	else {
		/* Disable fractional generator and use integer divider only */
		SysctlSetUSARTFRGDivider(0);
	}

	return ClockGetUSARTNBaseClockRate();
}

static inline void ClockSetSystemPLLSource(SYSCTL_PLLCLKSRC_T src)
{
    LPC_SYSCTL->SYSPLLCLKSEL  = (uint32_t) src;
    LPC_SYSCTL->SYSPLLCLKUEN  = 0;
    LPC_SYSCTL->SYSPLLCLKUEN  = 1;
}

static inline void ClockSetPLLBypass(bool bypass, bool highfr)
{
    uint32_t ctrl = 0;
    if(bypass)
        ctrl |= (1 << 0);
    if(highfr) 
        ctrl |= (1 << 1);

    LPC_SYSCTL->SYSOSCCTRL = ctrl;
}

static inline void ClockSetMainClockSource(SYSCTL_MAINCLKSRC_T src)
{
    LPC_SYSCTL->MAINCLKSEL  = (uint32_t) src;
    
    /* sequnce a 0 followed by 1 to update MAINCLK source selection */
    LPC_SYSCTL->MAINCLKUEN  = 0;
    LPC_SYSCTL->MAINCLKUEN  = 1;
}

static inline void ClockSetCLKOUTSource(SYSCTL_CLKOUTSRC_T src, uint32_t div)
{
    LPC_SYSCTL->CLKOUTSEL = (uint32_t) src;
    
    /* sequnce a 0 followed by 1 to update CLKOUT source selection */
    LPC_SYSCTL->CLKOUTUEN = 0;
    LPC_SYSCTL->CLKOUTUEN = 1;
    LPC_SYSCTL->CLKOUTDIV = div;
}

static inline uint32_t ClockGetSystemClockRate(void)
{
    return ClockGetMainClockRate() / (LPC_SYSCTL->SYSAHBCLKDIV & ~SYSCTL_SYSAHBCLKDIV_RESERVED);
}

static inline uint32_t ClockGetIOCONCLKDIVClockRate(PIN_CLKDIV_T reg)
{
    uint32_t div = LPC_SYSCTL->IOCONCLKDIV[reg] & ~SYSCTL_IOCONCLKDIV_RESERVED;
    uint32_t main_clk = ClockGetMainClockRate();
    
    return (div == 0) ? 0 : (main_clk / div);
}

static inline void ClockSetIOCONCLKDIV(PIN_CLKDIV_T reg, uint8_t div)
{
    int t_reg = IOCONCLK_MAX-reg;
    LPC_SYSCTL->IOCONCLKDIV[t_reg] = div;
}

#endif