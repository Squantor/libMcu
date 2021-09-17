/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series wakeup timer registers, defines and functions.
*/
#ifndef LPC8XX_WKT_OLD_H
#define LPC8XX_WKT_OLD_H

static inline WKT_CLKSRC_T WktGetClockSource(WKT_Type *pWKT)
{
    return (WKT_CLKSRC_T) (pWKT->CTRL & WKT_CTRL_CLKSEL);
}

static inline void WktSetClockSource(WKT_Type *pWKT, WKT_CLKSRC_T clkSrc)
{
    uint32_t ctrlRegister;
    if (clkSrc == WKT_CLKSRC_10KHZ)
        ctrlRegister = pWKT->CTRL | WKT_CTRL_CLKSEL;    /* using Low Power clock 10kHz */
    else
        ctrlRegister = pWKT->CTRL & ~WKT_CTRL_CLKSEL;    /* using Divided IRC clock 750kHz */
    pWKT->CTRL = ctrlRegister;
}

static inline uint32_t WktGetClockRate(WKT_Type *pWKT)
{
    if (WktGetClockSource(pWKT) == WKT_CLKSRC_DIVIRC)
        /* Approximately 750KHz */
        return (750 * 1000);
    else
        /* Approximately 10KHz */
        return (10 * 1000);
}

static inline bool WktGetIntStatus(WKT_Type *pWKT)
{
    return (bool) ((pWKT->CTRL & WKT_CTRL_ALARMFLAG) != 0);
}

static inline void WktClearIntStatus(WKT_Type *pWKT)
{
    pWKT->CTRL = WKT_CTRL_ALARMFLAG | (pWKT->CTRL & ~WKT_CTRL_RESERVED);
}

static inline void WktStop(WKT_Type *pWKT)
{
    pWKT->CTRL = WKT_CTRL_CLEARCTR | (pWKT->CTRL & ~WKT_CTRL_RESERVED);
}

static inline void WktLoadCount(WKT_Type *pWKT, uint32_t count)
{
    pWKT->COUNT = count;
}

static inline void WktStart(WKT_Type *pWKT, WKT_CLKSRC_T clkSrc, uint32_t cntVal)
{
    WktSetClockSource(pWKT, (WKT_CLKSRC_T) clkSrc);
    pWKT->COUNT = cntVal;    
}

#endif