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
LPC800 series common power management unit functions
*/
#ifndef LPC8XX_PMU_H
#define LPC8XX_PMU_H

/**
 * LPC8xx Power Management Unit register block structure
 */
typedef struct {
    volatile uint32_t PCON;        /* Power control Register (R/W) */
    volatile uint32_t GPREG[4];    /* General purpose Registers 0..3 (R/W) */
    volatile uint32_t DPDCTRL;    /* Deep power-down control register (R/W) */
} LPC_PMU_T;

/* Reserved bits masks for registers */
#define PMU_PCON_RESERVED      ((0xf<<4)|(0x6<<8)|0xfffff000)
#define PMU_DPDCTRL_RESERVED   (~0xf)

/**
 * LPC8xx low power mode type definitions
 */
typedef enum CHIP_PMU_MCUPOWER {
    PMU_MCU_SLEEP = 0,
    PMU_MCU_DEEP_SLEEP,
    PMU_MCU_POWER_DOWN,
    PMU_MCU_DEEP_PWRDOWN
} CHIP_PMU_MCUPOWER_T;

/**
 * PMU PCON register bit fields & masks
 */
#define PMU_PCON_PM_SLEEP           (0x0)       /* ARM WFI enter sleep mode */
#define PMU_PCON_PM_DEEPSLEEP       (0x1)       /* ARM WFI enter Deep-sleep mode */
#define PMU_PCON_PM_POWERDOWN       (0x2)       /* ARM WFI enter Power-down mode */
#define PMU_PCON_PM_DEEPPOWERDOWN   (0x3)       /* ARM WFI enter Deep Power-down mode */
#define PMU_PCON_NODPD              (1 << 3)    /* Disable deep power-down mode */
#define PMU_PCON_SLEEPFLAG          (1 << 8)    /* Sleep mode flag */
#define PMU_PCON_DPDFLAG            (1 << 11)   /* Deep power-down flag */

/**
 * PMU DPDCTRL register bit fields & masks
 */
#define PMU_DPDCTRL_WAKEUPPHYS      (1 << 0)    /* Enable wake-up pin hysteresis */
#define PMU_DPDCTRL_WAKEPAD         (1 << 1)    /* Disable the Wake-up */
#define PMU_DPDCTRL_LPOSCEN         (1 << 2)    /* Enable the low-power oscillator (10 khz self wk) */
#define PMU_DPDCTRL_LPOSCDPDEN      (1 << 3)    /* Enable the low-power oscillator in deep power-down*/

/* Reserved bits mask for SCR register */
#define SCB_SCR_RESERVED (~(SCB_SCR_SLEEPONEXIT_Msk|SCB_SCR_SLEEPDEEP_Msk|SCB_SCR_SEVONPEND_Msk))

static inline void Chip_PMU_WriteGPREG(LPC_PMU_T *pPMU, uint8_t regIndex, uint32_t value)
{
    pPMU->GPREG[regIndex] = value;
}

static inline uint32_t Chip_PMU_ReadGPREG(LPC_PMU_T *pPMU, uint8_t regIndex)
{
    return pPMU->GPREG[regIndex];
}

static inline void Chip_PMU_SleepState(LPC_PMU_T *pPMU)
{
    SCB->SCR = ~(1UL << SCB_SCR_SLEEPDEEP_Pos) & (SCB->SCR & ~SCB_SCR_RESERVED);
    pPMU->PCON = PMU_PCON_PM_SLEEP;

    __WFI();
}

static inline void Chip_PMU_DeepSleepState(LPC_PMU_T *pPMU)
{
    SCB->SCR = (1UL << SCB_SCR_SLEEPDEEP_Pos) | (SCB->SCR & ~SCB_SCR_RESERVED);
    pPMU->PCON = PMU_PCON_PM_DEEPSLEEP;

    __WFI();
}

static inline void Chip_PMU_PowerDownState(LPC_PMU_T *pPMU)
{
    SCB->SCR = (1UL << SCB_SCR_SLEEPDEEP_Pos) | (SCB->SCR & ~SCB_SCR_RESERVED);
    pPMU->PCON = PMU_PCON_PM_POWERDOWN;

    __WFI();
}

static inline void Chip_PMU_DeepPowerDownState(LPC_PMU_T *pPMU)
{
    SCB->SCR = (1UL << SCB_SCR_SLEEPDEEP_Pos) | (SCB->SCR & ~SCB_SCR_RESERVED);
    pPMU->PCON = PMU_PCON_PM_DEEPPOWERDOWN;

    __WFI();
}

static inline void Chip_PMU_Sleep(LPC_PMU_T *pPMU, CHIP_PMU_MCUPOWER_T SleepMode)
{
    if (SleepMode == PMU_MCU_DEEP_SLEEP) {
        Chip_PMU_DeepSleepState(pPMU);
    }
    else if (SleepMode == PMU_MCU_POWER_DOWN) {
        Chip_PMU_PowerDownState(pPMU);
    }
    else if (SleepMode == PMU_MCU_DEEP_PWRDOWN) {
        Chip_PMU_DeepPowerDownState(pPMU);
    }
    else {
        /* PMU_MCU_SLEEP */
        Chip_PMU_SleepState(pPMU);
    }
}

static inline void Chip_PMU_DisableDeepPowerDown(LPC_PMU_T *pPMU)
{
    pPMU->PCON = PMU_PCON_NODPD | (pPMU->PCON & ~PMU_PCON_RESERVED);
}

static inline uint32_t Chip_PMU_GetSleepFlags(LPC_PMU_T *pPMU)
{
    return (pPMU->PCON & (PMU_PCON_SLEEPFLAG | PMU_PCON_DPDFLAG));
}

static inline void Chip_PMU_ClearSleepFlags(LPC_PMU_T *pPMU, uint32_t flags)
{
    pPMU->PCON |= (flags & (~PMU_PCON_RESERVED));
}

static inline void Chip_PMU_SetPowerDownControl(LPC_PMU_T *pPMU, uint32_t flags)
{
    pPMU->DPDCTRL = flags | (pPMU->DPDCTRL & ~PMU_DPDCTRL_RESERVED);
}

static inline void Chip_PMU_ClearPowerDownControl(LPC_PMU_T *pPMU, uint32_t flags)
{
    pPMU->DPDCTRL &= ~(flags | PMU_DPDCTRL_RESERVED);
}

#endif