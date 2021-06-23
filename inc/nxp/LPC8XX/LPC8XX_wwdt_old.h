/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series common windowed watchdog registers, defines and functions.
*/
#ifndef LPC8XX_WWDT_OLD_H
#define LPC8XX_WWDT_OLD_H

static inline void WwdtInit(LPC_WWDT_T *pWWDT)
{
    ClockEnablePeriphClock(SYSCTL_CLOCK_WWDT);

    /* Disable watchdog */
    pWWDT->MOD       = 0;
    pWWDT->TC        = 0xFF;
    pWWDT->WARNINT   = 0xFFFF;
    pWWDT->WINDOW    = 0xFFFFFF;
}

static inline void WwdtDeInit(void)
{
    ClockDisablePeriphClock(SYSCTL_CLOCK_WWDT);
}

static inline void WwdtSetTimeOut(LPC_WWDT_T *pWWDT, uint32_t timeout)
{
    pWWDT->TC = timeout;
}

static inline void WwdtFeed(LPC_WWDT_T *pWWDT)
{
    pWWDT->FEED = 0xAA;
    pWWDT->FEED = 0x55;
}

static inline void WwdtSetWarning(LPC_WWDT_T *pWWDT, uint32_t timeout)
{
    pWWDT->WARNINT = timeout;
}

static inline void WwdtSetWindow(LPC_WWDT_T *pWWDT, uint32_t timeout)
{
    pWWDT->WINDOW = timeout;
}

static inline void WwdtSetOption(LPC_WWDT_T *pWWDT, uint32_t options)
{
    uint32_t modRegister = options | (pWWDT->MOD & ~WWDT_MOD_RESERVED);
    pWWDT->MOD = modRegister;
}

static inline void WwdtUnsetOption(LPC_WWDT_T *pWWDT, uint32_t options)
{
    uint32_t modRegister = pWWDT->MOD & (~options) & WWDT_WDMOD_BITMASK;
    pWWDT->MOD = modRegister;
}

static inline void WwdtStart(LPC_WWDT_T *pWWDT)
{
    WwdtSetOption(pWWDT, WWDT_WDMOD_WDEN);
    WwdtFeed(pWWDT);
}

static inline uint32_t WwdtGetStatus(LPC_WWDT_T *pWWDT)
{
    return pWWDT->MOD;
}

static inline void WwdtClearStatusFlag(LPC_WWDT_T *pWWDT, uint32_t status)
{
    uint32_t modRegister;
    if(status & WWDT_WDMOD_WDTOF) 
        modRegister = pWWDT->MOD & (~WWDT_WDMOD_WDTOF) & WWDT_WDMOD_BITMASK;

    if(status & WWDT_WDMOD_WDINT)
        modRegister = WWDT_WDMOD_WDINT | (pWWDT->MOD & ~WWDT_MOD_RESERVED);
    pWWDT->MOD = modRegister;
}

static inline uint32_t WwdtGetCurrentCount(LPC_WWDT_T *pWWDT)
{
    return pWWDT->TV;
}

#endif