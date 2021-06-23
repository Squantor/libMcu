/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC820 series common analog comparator registers, defines and 
functions.
*/
#ifndef LPC82X_ACMP_H
#define LPC82X_ACMP_H

/**
 * Analog Comparator positive input values
 */
typedef enum ACMP_POS_INPUT {
    ACMP_POSIN_VLO      = (0 << 8), /* Voltage ladder output */
    ACMP_POSIN_ACMP_I1  = (1 << 8), /* ACMP_I1 pin */
    ACMP_POSIN_ACMP_I2  = (2 << 8), /* ACMP_I2 pin */
    ACMP_POSIN_ACMP_I3  = (3 << 8), /* ACMP_I3 pin */
    ACMP_POSIN_ACMP_I4  = (4 << 8), /* ACMP_I4 pin */
    ACMP_POSIN_INT_REF  = (5 << 8), /* Internal reference voltage */
    ACMP_POSIN_ADC_0    = (6 << 8), /* ADC_0 Input */
} ACMP_POS_INPUT_T;

/**
 * Analog Comparator negative input values
 */
typedef enum ACMP_NEG_INPUT {
    ACMP_NEGIN_VLO     = (0 << 11),    /* Voltage ladder output */
    ACMP_NEGIN_ACMP_I1 = (1 << 11),    /* ACMP_I1 pin */
    ACMP_NEGIN_ACMP_I2 = (2 << 11),    /* ACMP_I2 pin */
    ACMP_NEGIN_ACMP_I3 = (3 << 11),    /* ACMP_I3 pin */
    ACMP_NEGIN_ACMP_I4 = (4 << 11),    /* ACMP_I4 pin */
    ACMP_NEGIN_INT_REF = (5 << 11),    /* Internal reference voltage */
    ACMP_NEGIN_ADC_0   = (6 << 11),    /* ADC_0 Input */
} ACMP_NEG_INPUT_T;

#include "nxp/LPC8XX/LPC8XX_acmp.h"

#endif