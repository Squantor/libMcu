/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series common IOCON registers, defines and functions.
*/
#ifndef LPC8XX_IOCON_H
#define LPC8XX_IOCON_H

typedef volatile struct {
    uint32_t PIO0[31];
} IOCON_Type;

#include "nxp/LPC8XX/LPC8XX_iocon_old.h"

#endif