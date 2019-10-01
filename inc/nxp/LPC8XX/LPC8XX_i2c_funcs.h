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
LPC800 series common I2C bus registers, defines and functions.
*/
#ifndef LPC8XX_I2C_FUNCS_H
#define LPC8XX_I2C_FUNCS_H

static inline void I2cInit(LPC_I2C_T *pI2C)
{
    ClockEnablePeriphClock(I2cGetClockID(pI2C));
    SYSCTL_PeriphReset(I2cGetResetID(pI2C));    
}

static inline void I2cDeInit(LPC_I2C_T *pI2C)
{
    ClockDisablePeriphClock(I2cGetClockID(pI2C));
}

static inline void I2cSetClockDiv(LPC_I2C_T *pI2C, uint32_t clkdiv)
{
    if ((clkdiv >= 1) && (clkdiv <= 65536)) {
        pI2C->CLKDIV = clkdiv - 1;
    }
    else {
        pI2C->CLKDIV = 0;
    }
}

static inline uint32_t I2cGetClockDiv(LPC_I2C_T *pI2C)
{
    return (pI2C->CLKDIV & 0xFFFF) + 1;
}

static inline void I2cEnableInt(LPC_I2C_T *pI2C, uint32_t intEn)
{
    pI2C->INTENSET = intEn;
}

static inline void I2cDisableInt(LPC_I2C_T *pI2C, uint32_t intClr)
{
    pI2C->INTENCLR = intClr;
}

static inline void I2cClearInt(LPC_I2C_T *pI2C, uint32_t intClr)
{
    I2cDisableInt(pI2C, intClr);
}

static inline uint32_t I2cGetPendingInt(LPC_I2C_T *pI2C)
{
    return pI2C->INTSTAT & ~I2C_INTSTAT_RESERVED;
}

#endif