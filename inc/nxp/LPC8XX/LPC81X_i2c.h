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
LPC810 series common I2C bus registers, defines and functions.
*/
#ifndef LPC81X_I2C_H
#define LPC81X_I2C_H

#include "nxp/LPC8XX/LPC8XX_i2c_defs.h"

/* we cant avoid this pragma as this parameter is used for the LPC82X */
#pragma GCC diagnostic ignored "-Wunused-parameter"

static inline SYSCTL_PERIPH_RESET_T I2C_GetResetID(LPC_I2C_T *pI2C)
{
    return RESET_I2C0;
}

static inline SYSCTL_CLOCK_T I2C_GetClockID(LPC_I2C_T *pI2C)
{
    return SYSCTL_CLOCK_I2C0;
}

#pragma GCC diagnostic pop

#include "nxp/LPC8XX/LPC8XX_i2c_funcs.h"

#endif