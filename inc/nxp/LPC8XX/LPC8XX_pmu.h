/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series common power management unit registers, defines and
functions.
*/
#ifndef LPC8XX_PMU_H
#define LPC8XX_PMU_H

/**
 * LPC8xx Power Management Unit register block structure
 */
typedef volatile struct {
  uint32_t PCON;     /**< Power control Register (R/W) */
  uint32_t GPREG[4]; /**< General purpose Registers 0..3 (R/W) */
  uint32_t DPDCTRL;  /**< Deep power-down control register (R/W) */
} PMU_Type;

/* Reserved bits masks for registers */
#define PMU_PCON_RESERVED ((0xf << 4) | (0x6 << 8) | 0xfffff000)
#define PMU_DPDCTRL_RESERVED (~0xf)

/**
 * LPC8xx low power mode type definitions
 */
typedef enum PMU_MCUPOWER {
  PMU_MCU_SLEEP = 0,
  PMU_MCU_DEEP_SLEEP,
  PMU_MCU_POWER_DOWN,
  PMU_MCU_DEEP_PWRDOWN
} PMU_MCUPOWER_T;

/**
 * PMU PCON register bit fields & masks
 */
#define PMU_PCON_PM_SLEEP (0x0)         /* ARM WFI enter sleep mode */
#define PMU_PCON_PM_DEEPSLEEP (0x1)     /* ARM WFI enter Deep-sleep mode */
#define PMU_PCON_PM_POWERDOWN (0x2)     /* ARM WFI enter Power-down mode */
#define PMU_PCON_PM_DEEPPOWERDOWN (0x3) /* ARM WFI enter Deep Power-down mode \
                                         */
#define PMU_PCON_NODPD (1 << 3)         /* Disable deep power-down mode */
#define PMU_PCON_SLEEPFLAG (1 << 8)     /* Sleep mode flag */
#define PMU_PCON_DPDFLAG (1 << 11)      /* Deep power-down flag */

/**
 * PMU DPDCTRL register bit fields & masks
 */
#define PMU_DPDCTRL_WAKEUPPHYS (1 << 0) /* Enable wake-up pin hysteresis */
#define PMU_DPDCTRL_WAKEPAD (1 << 1)    /* Disable the Wake-up */
#define PMU_DPDCTRL_LPOSCEN \
  (1 << 2) /* Enable the low-power oscillator (10 khz self wk) */
#define PMU_DPDCTRL_LPOSCDPDEN \
  (1 << 3) /* Enable the low-power oscillator in deep power-down*/

/* Reserved bits mask for SCR register */
#define SCB_SCR_RESERVED \
  (~(SCB_SCR_SLEEPONEXIT_Msk | SCB_SCR_SLEEPDEEP_Msk | SCB_SCR_SEVONPEND_Msk))

#include "nxp/LPC8XX/LPC8XX_pmu_old.h"

#endif