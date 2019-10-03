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
LPC800 series common ROM power control driver defines and functions.
*/
#ifndef LPC8XX_ROM_PWR_H
#define LPC8XX_ROM_PWR_H

/**
 * LPC8xx Power ROM APIs - set_pll mode options
 */
#define CPU_FREQ_EQU    0
#define CPU_FREQ_LTE    1
#define CPU_FREQ_GTE    2
#define CPU_FREQ_APPROX 3

/**
 * LPC8xx Power ROM APIs - set_pll response0 options
 */
#define PLL_CMD_SUCCESS    0
#define PLL_INVALID_FREQ   1
#define PLL_INVALID_MODE   2
#define PLL_FREQ_NOT_FOUND 3
#define PLL_NOT_LOCKED     4

/**
 * LPC8xx Power ROM APIs - set_power mode options
 */
#define PWR_DEFAULT         0
#define PWR_CPU_PERFORMANCE 1
#define PWR_EFFICIENCY      2
#define PWR_LOW_CURRENT     3

/**
 * LPC8xx Power ROM APIs - set_power response0 options
 */
#define PWR_CMD_SUCCESS  0
#define PWR_INVALID_FREQ 1
#define PWR_INVALID_MODE 2

/**
 * LPC8XX Power ROM API structure
 */
typedef struct PWRD_API {
    void (*setPll)(uint32_t cmd[], uint32_t resp[]);    /*!< Set PLL function */
    void (*setPower)(uint32_t cmd[], uint32_t resp[]);    /*!< Set power function */
} PWRD_API_T;

#endif