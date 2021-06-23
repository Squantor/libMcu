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

static inline WKT_CLKSRC_T WktGetClockSource(LPC_WKT_T *pWKT)
{
    return (WKT_CLKSRC_T) (pWKT->CTRL & WKT_CTRL_CLKSEL);
}

static inline void WktSetClockSource(LPC_WKT_T *pWKT, WKT_CLKSRC_T clkSrc)
{
    if (clkSrc == WKT_CLKSRC_10KHZ)
        pWKT->CTRL |= WKT_CTRL_CLKSEL;    /* using Low Power clock 10kHz */
    else
        pWKT->CTRL &= ~WKT_CTRL_CLKSEL;    /* using Divided IRC clock 750kHz */
}

static inline uint32_t WktGetClockRate(LPC_WKT_T *pWKT)
{
    if (WktGetClockSource(pWKT) == WKT_CLKSRC_DIVIRC)
        /* Approximately 750KHz */
        return (750 * 1000);
    else
        /* Approximately 10KHz */
        return (10 * 1000);
}

static inline bool WktGetIntStatus(LPC_WKT_T *pWKT)
{
    return (bool) ((pWKT->CTRL & WKT_CTRL_ALARMFLAG) != 0);
}

static inline void WktClearIntStatus(LPC_WKT_T *pWKT)
{
    pWKT->CTRL = WKT_CTRL_ALARMFLAG | (pWKT->CTRL & ~WKT_CTRL_RESERVED);
}

static inline void WktStop(LPC_WKT_T *pWKT)
{
    pWKT->CTRL = WKT_CTRL_CLEARCTR | (pWKT->CTRL & ~WKT_CTRL_RESERVED);
}

static inline void WktLoadCount(LPC_WKT_T *pWKT, uint32_t count)
{
    pWKT->COUNT = count;
}

static inline void WktStart(LPC_WKT_T *pWKT, WKT_CLKSRC_T clkSrc, uint32_t cntVal)
{
    WktSetClockSource(pWKT, (WKT_CLKSRC_T) clkSrc);
    pWKT->COUNT = cntVal;    
}

#endif