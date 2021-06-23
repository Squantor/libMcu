/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series common power management unit registers, defines and 
functions.
*/
#ifndef LPC8XX_PMU_OLD_H
#define LPC8XX_PMU_OLD_H

static inline void PmuWriteGPREG(LPC_PMU_T *pPMU, uint8_t regIndex, uint32_t value)
{
    pPMU->GPREG[regIndex] = value;
}

static inline uint32_t PmuReadGPREG(LPC_PMU_T *pPMU, uint8_t regIndex)
{
    return pPMU->GPREG[regIndex];
}

static inline void PmuSleepState(LPC_PMU_T *pPMU)
{
    SCB->SCR = ~(1UL << SCB_SCR_SLEEPDEEP_Pos) & (SCB->SCR & ~SCB_SCR_RESERVED);
    pPMU->PCON = PMU_PCON_PM_SLEEP;

    __WFI();
}

static inline void PmuDeepSleepState(LPC_PMU_T *pPMU)
{
    SCB->SCR = (1UL << SCB_SCR_SLEEPDEEP_Pos) | (SCB->SCR & ~SCB_SCR_RESERVED);
    pPMU->PCON = PMU_PCON_PM_DEEPSLEEP;

    __WFI();
}

static inline void PmuPowerDownState(LPC_PMU_T *pPMU)
{
    SCB->SCR = (1UL << SCB_SCR_SLEEPDEEP_Pos) | (SCB->SCR & ~SCB_SCR_RESERVED);
    pPMU->PCON = PMU_PCON_PM_POWERDOWN;

    __WFI();
}

static inline void PmuDeepPowerDownState(LPC_PMU_T *pPMU)
{
    SCB->SCR = (1UL << SCB_SCR_SLEEPDEEP_Pos) | (SCB->SCR & ~SCB_SCR_RESERVED);
    pPMU->PCON = PMU_PCON_PM_DEEPPOWERDOWN;

    __WFI();
}

static inline void PmuSleep(LPC_PMU_T *pPMU, PMU_MCUPOWER_T SleepMode)
{
    if (SleepMode == PMU_MCU_DEEP_SLEEP) {
        PmuDeepSleepState(pPMU);
    }
    else if (SleepMode == PMU_MCU_POWER_DOWN) {
        PmuPowerDownState(pPMU);
    }
    else if (SleepMode == PMU_MCU_DEEP_PWRDOWN) {
        PmuDeepPowerDownState(pPMU);
    }
    else {
        /* PMU_MCU_SLEEP */
        PmuSleepState(pPMU);
    }
}

static inline void PmuDisableDeepPowerDown(LPC_PMU_T *pPMU)
{
    pPMU->PCON = PMU_PCON_NODPD | (pPMU->PCON & ~PMU_PCON_RESERVED);
}

static inline uint32_t PmuGetSleepFlags(LPC_PMU_T *pPMU)
{
    return (pPMU->PCON & (PMU_PCON_SLEEPFLAG | PMU_PCON_DPDFLAG));
}

static inline void PmuClearSleepFlags(LPC_PMU_T *pPMU, uint32_t flags)
{
    uint32_t pconRegister = pPMU->PCON | (flags & (~PMU_PCON_RESERVED));
    pPMU->PCON = pconRegister;
}

static inline void PmuSetPowerDownControl(LPC_PMU_T *pPMU, uint32_t flags)
{
    uint32_t dpdctrlRegister = flags | (pPMU->DPDCTRL & ~PMU_DPDCTRL_RESERVED);
    pPMU->DPDCTRL = dpdctrlRegister;
}

static inline void PmuClearPowerDownControl(LPC_PMU_T *pPMU, uint32_t flags)
{
    uint32_t dpdctrlRegister = pPMU->DPDCTRL & ~(flags | PMU_DPDCTRL_RESERVED);
    pPMU->DPDCTRL = dpdctrlRegister;
}

#endif