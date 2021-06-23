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
LPC800 series common windowed watchdog registers, defines and functions.
*/
#ifndef LPC8XX_WWDT_H
#define LPC8XX_WWDT_H

/* WDT oscillator frequency value */
#define WDT_OSC     (LPC8XX_IRC_FREQ)

typedef struct {
    __IO uint32_t  MOD;     /* basic mode and status register */
    __IO uint32_t  TC;      /* time-out value register */
    __O  uint32_t  FEED;    /* Writing 0xAA followed by 0x55 reloads the Watchdog timer */
    __I  uint32_t  TV;      /* current value of the Watchdog timer */
    __I  uint32_t  RESERVED0;
    __IO uint32_t  WARNINT; /* contains the Watchdog warning interrupt value */
    __IO uint32_t  WINDOW;  /* contains the Watchdog window value. */
} LPC_WWDT_T;

/* Reserved bits masks for registers */
#define WWDT_MOD_RESERVED       (~0x3f)
#define WWDT_TC_RESERVED        0xff000000
#define WWDT_FEED_RESERVED      (~0xff)
#define WWDT_TV_RESERVED        0xff000000
#define WWDT_WARNINT_RESERVED   (~0x3ff)
#define WWDT_WINDOW_RESERVED    0xff000000

/** Watchdog Mode Bitmask */
#define WWDT_WDMOD_BITMASK          ((uint32_t) 0x1F)
/** WWDT interrupt enable bit */
#define WWDT_WDMOD_WDEN             ((uint32_t) (1 << 0))
/** WWDT interrupt enable bit */
#define WWDT_WDMOD_WDRESET          ((uint32_t) (1 << 1))
/** WWDT time out flag bit */
#define WWDT_WDMOD_WDTOF            ((uint32_t) (1 << 2))
/** WDT Time Out flag bit */
#define WWDT_WDMOD_WDINT            ((uint32_t) (1 << 3))

#endif