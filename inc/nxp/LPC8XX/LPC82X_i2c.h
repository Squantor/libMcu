/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC820 series common I2C bus registers, defines and functions.
*/
#ifndef LPC82X_I2C_H
#define LPC82X_I2C_H

#include "nxp/LPC8XX/LPC8XX_i2c_defs.h"

static inline SYSCTL_PERIPH_RESET_T I2cGetResetID(LPC_I2C_T *pI2C)
{
    uint32_t base = (uint32_t) pI2C;
    switch (base) {
        case LPC_I2C1_BASE:
            return RESET_I2C1;
        case LPC_I2C2_BASE:
            return RESET_I2C2;
        case LPC_I2C3_BASE:
            return RESET_I2C3;
        default:
            return RESET_I2C0;
    }
}

static inline SYSCTL_CLOCK_T I2cGetClockID(LPC_I2C_T *pI2C)
{
    uint32_t base = (uint32_t) pI2C;
    switch (base) {
        case LPC_I2C1_BASE:
            return SYSCTL_CLOCK_I2C1;
        case LPC_I2C2_BASE:
            return SYSCTL_CLOCK_I2C2;
        case LPC_I2C3_BASE:
            return SYSCTL_CLOCK_I2C3;
        default:
            return SYSCTL_CLOCK_I2C0;
    }
}

#include "nxp/LPC8XX/LPC8XX_i2c_funcs.h"

#endif