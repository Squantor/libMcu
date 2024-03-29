/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC800 series common system control registers, defines and functions.
*/
#ifndef LPC8XX_SYSCON_OLD_H
#define LPC8XX_SYSCON_OLD_H

/**
 * System reset status values
 */
#define SYSCTL_RST_POR (1 << 0)    /*!< POR reset status */
#define SYSCTL_RST_EXTRST (1 << 1) /*!< External reset status */
#define SYSCTL_RST_WDT (1 << 2)    /*!< Watchdog reset status */
#define SYSCTL_RST_BOD (1 << 3)    /*!< Brown-out detect reset status */
#define SYSCTL_RST_SYSRST (1 << 4) /*!< software system reset status */

/**
 * Peripheral interrupt wakeup events values
 */
#define SYSCTL_WAKEUP_SPI0TINT (1 << 0)  /*!< SPI0 interrupt wake-up */
#define SYSCTL_WAKEUP_SPI1INT (1 << 1)   /*!< SPI0 interrupt wake-up */
#define SYSCTL_WAKEUP_USART0INT (1 << 3) /*!< USART0 interrupt wake-up */
#define SYSCTL_WAKEUP_USART1INT (1 << 4) /*!< USART1 interrupt wake-up */
#define SYSCTL_WAKEUP_USART2INT (1 << 5) /*!< USART2 interrupt wake-up */
#define SYSCTL_WAKEUP_I2C0INT (1 << 8)   /*!< I2C0 interrupt wake-up */
#define SYSCTL_WAKEUP_WWDTINT (1 << 12)  /*!< WWDT interrupt wake-up */
#define SYSCTL_WAKEUP_BODINT (1 << 13)   /*!< Brown Out Detect (BOD) interrupt wake-up */
#define SYSCTL_WAKEUP_WKTINT (1 << 15)   /*!< Self wake-up timer interrupt wake-up */

/**
 * Deep sleep setup values
 */
#define SYSCTL_DEEPSLP_BOD_PD (1 << 3) /*!< BOD power-down control in Deep-sleep mode, powered down */
#define SYSCTL_DEEPSLP_WDTOSC_PD                                              \
  (1 << 6) /*!< Watchdog oscillator power control in Deep-sleep, powered down \
            */

/**
 * Deep sleep to wakeup and power state setup values
 */
#define SYSCTL_SLPWAKE_IRCOUT_PD (1 << 0) /*!< IRC oscillator output wake-up configuration */
#define SYSCTL_SLPWAKE_IRC_PD (1 << 1)    /*!< IRC oscillator power-down wake-up configuration */
#define SYSCTL_SLPWAKE_FLASH_PD (1 << 2)  /*!< Flash wake-up configuration */
#define SYSCTL_SLPWAKE_BOD_PD (1 << 3)    /*!< BOD wake-up configuration */
#define SYSCTL_SLPWAKE_SYSOSC_PD (1 << 5) /*!< System oscillator wake-up configuration */
#define SYSCTL_SLPWAKE_WDTOSC_PD (1 << 6) /*!< Watchdog oscillator wake-up configuration */
#define SYSCTL_SLPWAKE_SYSPLL_PD (1 << 7) /*!< System PLL wake-up configuration */
#define SYSCTL_SLPWAKE_ACMP_PD (1 << 15)  /*!< Analog comparator wake-up configuration */

/**
 * Non-Maskable Interrupt Enable/Disable value
 */
#define SYSCTL_NMISRC_ENABLE ((uint32_t)1 << 31) /*!< Enable the Non-Maskable Interrupt (NMI) source */

/* PDSLEEPCFG register mask */
#define PDSLEEPWRMASK (0x0000FFB7)
#define PDSLEEPDATMASK (0x00000048)

/**
 * @brief IOCON Perpipheral Clock divider selction for input filter
 * sampling clock
 */
typedef enum PIN_CLKDIV {
  IOCONCLKDIV0 = 0,           /*!< Clock divider 0 */
  IOCONCLKDIV1,               /*!< Clock divider 1 */
  IOCONCLKDIV2,               /*!< Clock divider 2 */
  IOCONCLKDIV3,               /*!< Clock divider 3 */
  IOCONCLKDIV4,               /*!< Clock divider 4 */
  IOCONCLKDIV5,               /*!< Clock divider 5 */
  IOCONCLKDIV6,               /*!< Clock divider 6 */
  IOCONCLK_MAX = IOCONCLKDIV6 /*!< Top value used to reverse the dividers */
} PIN_CLKDIV_T;

/* Reserved bits masks for registers */
#define SYSCTL_SYSMEMREMAP_RESERVED (~3)
#define SYSCTL_SYSPLLCTRL_RESERVED (~0x7f)
#define SYSCTL_SYSPLLSTAT_RESERVED (~1)
#define SYSCTL_SYSOSCCTRL_RESERVED (~3)
#define SYSCTL_WDTOSCCTRL_RESERVED (~0x1ff)
#define SYSCTL_SYSRSTSTAT_RESERVED (~0x1f)
#define SYSCTL_SYSPLLCLKSEL_RESERVED (~3)
#define SYSCTL_SYSPLLCLKUEN_RESERVED (~1)
#define SYSCTL_MAINCLKSEL_RESERVED (~3)
#define SYSCTL_MAINCLKUEN_RESERVED (~1)
#define SYSCTL_SYSAHBCLKDIV_RESERVED (~0xff)
#define SYSCTL_UARTCLKDIV_RESERVED (~0xff)
#define SYSCTL_CLKOUTSEL_RESERVED (~3)
#define SYSCTL_CLKOUTUEN_RESERVED (~1)
#define SYSCTL_CLKOUTDIV_RESERVED (~0xff)
#define SYSCTL_UARTFRGDIV_RESERVED (~0xff)
#define SYSCTL_UARTFRGMULT_RESERVED (~0xff)
#define SYSCTL_EXTTRACECMD_RESERVED (~3)
#define SYSCTL_IOCONCLKDIV_RESERVED (~0xff)
#define SYSCTL_BODCTRL_RESERVED (~0x1f)
#define SYSCTL_SYSTCKCAL_RESERVED 0xfc000000
#define SYSCTL_IRQLATENCY_RESERVED (~0xff)
#define SYSCTL_NMISRC_RESERVED (~(0x1f | (1u << 31)))
#define SYSCTL_PINTSEL_RESERVED (~0x3f)
#define SYSCTL_STARTERP0_RESERVED (~0xff)
/* The following have reserved bits, but they are specially handled elsewhere.
 */
/* #define SYSCTL_PDSLEEPCFG_RESERVED      (~(1<<3)|(3<<4)|(1<<6)) */
/* #define SYSCTL_PDAWAKECFG_RESERVED */
/* #define SYSCTL_PDRUNCFG_RESERVED   */

/**
 * System memory remap modes used to remap interrupt vectors
 */
typedef enum SYSCTL_BOOT_MODE_REMAP {
  REMAP_BOOT_LOADER_MODE, /*!< Interrupt vectors are re-mapped to Boot ROM */
  REMAP_USER_RAM_MODE,    /*!< Interrupt vectors are re-mapped to user Static RAM
                           */
  REMAP_USER_FLASH_MODE   /*!< Interrupt vectors are not re-mapped and reside in
                             Flash */
} SYSCTL_BOOT_MODE_REMAP_T;

/**
 * Brown-out detector reset level
 */
typedef enum SYSCTL_BODRSTLVL {
  SYSCTL_BODRSTLVL_0, /*!< Brown-out reset at 1.46 ~ 1.63v */
  SYSCTL_BODRSTLVL_1, /*!< Brown-out reset at 2.06v ~ 2.15v */
  SYSCTL_BODRSTLVL_2, /*!< Brown-out reset at 2.35v ~ 2.43v */
  SYSCTL_BODRSTLVL_3, /*!< Brown-out reset at 2.63v ~ 2.71v */
} SYSCTL_BODRSTLVL_T;

/**
 * Brown-out detector interrupt level
 */
typedef enum SYSCTL_BODRINTVAL {
  SYSCTL_BODINTVAL_LVL0, /* Brown-out interrupt at 1.65 ~ 1.80v */
  SYSCTL_BODINTVAL_LVL1, /* Brown-out interrupt at 2.22v ~ 2.35v*/
  SYSCTL_BODINTVAL_LVL2, /* Brown-out interrupt at 2.52v ~ 2.66v */
  SYSCTL_BODINTVAL_LVL3, /* Brown-out interrupt at 2.80v ~ 2.90v */
} SYSCTL_BODRINTVAL_T;

static inline void SysctlMap(SYSCTL_BOOT_MODE_REMAP_T remap) {
  SYSCON->SYSMEMREMAP = (uint32_t)remap;
}

static inline uint32_t SysctlGetSystemRSTStatus(void) {
  return SYSCON->SYSRSTSTAT & ~SYSCTL_SYSRSTSTAT_RESERVED;
}

static inline void SysctlClearSystemRSTStatus(uint32_t reset) {
  SYSCON->SYSRSTSTAT = reset;
}

static inline void SysctlSetBODLevels(SYSCTL_BODRSTLVL_T rstlvl, SYSCTL_BODRINTVAL_T intlvl) {
  SYSCON->BODCTRL = ((uint32_t)rstlvl) | (((uint32_t)intlvl) << 2);
}

static inline void SysctlEnableBODReset(void) {
  SYSCON->BODCTRL = (1 << 4) | (SYSCON->BODCTRL & ~SYSCTL_BODCTRL_RESERVED);
}

static inline void SysctlDisableBODReset(void) {
  uint32_t bodctrlRegister = SYSCON->BODCTRL & ~((1 << 4) | SYSCTL_BODCTRL_RESERVED);
  SYSCON->BODCTRL = bodctrlRegister;
}

static inline void SysctlSetSYSTCKCAL(uint32_t sysCalVal) {
  SYSCON->SYSTCKCAL = sysCalVal;
}

static inline void SysctlSetIRQLatency(uint32_t latency) {
  SYSCON->IRQLATENCY = latency;
}

static inline uint32_t SysctlGetIRQLatency(void) {
  return SYSCON->IRQLATENCY & ~SYSCTL_IRQLATENCY_RESERVED;
}

static inline void SysctlSetNMISource(uint32_t intsrc) {
  /* Disable NMI first */
  uint32_t nmisrcRegister = SYSCON->NMISRC & ~(SYSCTL_NMISRC_ENABLE | SYSCTL_NMISRC_RESERVED);
  SYSCON->NMISRC = nmisrcRegister;

  /* Set new NMI source. */
  SYSCON->NMISRC = intsrc;
}

static inline void SysctlEnableNMISource(void) {
  SYSCON->NMISRC = SYSCTL_NMISRC_ENABLE | (SYSCON->NMISRC & ~SYSCTL_NMISRC_RESERVED);
}

static inline void SysctlDisableNMISource(void) {
  uint32_t nmisrcRegister = SYSCON->NMISRC & ~(SYSCTL_NMISRC_ENABLE | SYSCTL_NMISRC_RESERVED);
  SYSCON->NMISRC = nmisrcRegister;
}

static inline void SysctlSetPinInterrupt(uint32_t intno, uint32_t pin) {
  SYSCON->PINTSEL[intno] = (uint32_t)pin;
}

static inline void SysctlEnablePINTWakeup(uint32_t pin) {
  uint32_t starterp0Register = (1 << pin) | (SYSCON->STARTERP0 & ~SYSCTL_STARTERP0_RESERVED);
  SYSCON->STARTERP0 = starterp0Register;
}

static inline void SysctlDisablePINTWakeup(uint32_t pin) {
  uint32_t starterp0Register = SYSCON->STARTERP0 & ~((1 << pin) | SYSCTL_STARTERP0_RESERVED);
  SYSCON->STARTERP0 = starterp0Register;
}

static inline void SysctlEnablePeriphWakeup(uint32_t periphmask) {
  SYSCON->STARTERP1 = periphmask | (SYSCON->STARTERP0 & ~SYSCTL_STARTERP0_RESERVED);
}

static inline uint32_t SysctlGetDeepSleepPD(void) {
  return SYSCON->PDSLEEPCFG;
}

static inline uint32_t SysctlGetWakeup(void) {
  return SYSCON->PDAWAKECFG;
}

static inline uint32_t SysctlGetPowerStates(void) {
  return SYSCON->PDRUNCFG;
}

static inline uint32_t SysctlGetDeviceID(void) {
  return SYSCON->DEVICEID;
}

static inline void SysctlSetDeepSleepPD(uint32_t sleepmask) {
  SYSCON->PDSLEEPCFG = PDSLEEPWRMASK | (sleepmask & PDSLEEPDATMASK);
}

#endif