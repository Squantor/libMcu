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
LPC800 series wakeup timer functions
*/
#ifndef LPC8XX_WKT_H
#define LPC8XX_WKT_H

typedef struct {
    __IO uint32_t  CTRL;    /* Alarm/Wakeup Timer Control register */
    uint32_t  Reserved[2];
    __IO uint32_t  COUNT;   /* Alarm/Wakeup Timer Counter register */
} LPC_WKT_T;

#define WKT_CTRL_RESERVED (~7)

/**
 * WKT Control register bit fields & masks
 */
#define WKT_CTRL_CLKSEL        ((uint32_t) (1 << 0))    /*!< Select the self wake-up timer clock source */
#define WKT_CTRL_ALARMFLAG     ((uint32_t) (1 << 1))    /*!< Wake-up or alarm timer flag */
#define WKT_CTRL_CLEARCTR      ((uint32_t) (1 << 2))    /*!< Clears the self wake-up timer */

/**
 * WKT Clock source values enum
 */
typedef enum  {
    WKT_CLKSRC_DIVIRC = 0,  /* Divided IRC clock - runs at 750kHz */
    WKT_CLKSRC_10KHZ = 1    /* Low power clock - runs at 10kHz */
} WKT_CLKSRC_T;

static inline WKT_CLKSRC_T WKT_GetClockSource(LPC_WKT_T *pWKT)
{
    return (WKT_CLKSRC_T) (pWKT->CTRL & WKT_CTRL_CLKSEL);
}

static inline void WKT_SetClockSource(LPC_WKT_T *pWKT, WKT_CLKSRC_T clkSrc)
{
        if (clkSrc == WKT_CLKSRC_10KHZ) {
        pWKT->CTRL |= WKT_CTRL_CLKSEL;    /* using Low Power clock 10kHz */
    }
    else {
        pWKT->CTRL &= ~WKT_CTRL_CLKSEL;    /* using Divided IRC clock 750kHz */
    }
}

static inline uint32_t WKT_GetClockRate(LPC_WKT_T *pWKT)
{
    if (WKT_GetClockSource(pWKT) == WKT_CLKSRC_DIVIRC) {
        /* Approximately 750KHz */
        return (750 * 1000);
    }
    else {
        /* Approximately 10KHz */
        return (10 * 1000);
    }    
}

static inline bool WKT_GetIntStatus(LPC_WKT_T *pWKT)
{
    return (bool) ((pWKT->CTRL & WKT_CTRL_ALARMFLAG) != 0);
}

static inline void WKT_ClearIntStatus(LPC_WKT_T *pWKT)
{
    pWKT->CTRL = WKT_CTRL_ALARMFLAG | (pWKT->CTRL & ~WKT_CTRL_RESERVED);
}

static inline void WKT_Stop(LPC_WKT_T *pWKT)
{
    pWKT->CTRL = WKT_CTRL_CLEARCTR | (pWKT->CTRL & ~WKT_CTRL_RESERVED);
}

static inline void WKT_LoadCount(LPC_WKT_T *pWKT, uint32_t count)
{
    pWKT->COUNT = count;
}

static inline void WKT_Start(LPC_WKT_T *pWKT, WKT_CLKSRC_T clkSrc, uint32_t cntVal)
{
    WKT_SetClockSource(pWKT, (WKT_CLKSRC_T) clkSrc);
    pWKT->COUNT = cntVal;    
}

#endif