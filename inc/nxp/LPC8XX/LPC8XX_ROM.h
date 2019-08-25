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
LPC800 series common ROM functions
*/
#ifndef LPC8XX_ROM_H
#define LPC8XX_ROM_H

#include "nxp/LPC8XX/LPC8XX_ROM_iap.h"
#include "nxp/LPC8XX/LPC8XX_ROM_error.h"
#include "nxp/LPC8XX/LPC8XX_ROM_i2c.h"
#include "nxp/LPC8XX/LPC8XX_ROM_pwr.h"
#include "nxp/LPC8XX/LPC8XX_ROM_uart.h"

typedef struct ROM_API {
    const uint32_t    unused[3];
    const PWRD_API_T  *pPWRD;    /*!< Power profiles API function table */
    const uint32_t    p_dev1;
    const I2CD_API_T  *pI2CD;    /*!< I2C driver routines functions table */
    const uint32_t    p_dev3;
    const uint32_t    p_dev4;
    const uint32_t    p_dev5;
    const UARTD_API_T *pUARTD;    /*!< UART driver routines function table */
} LPC_ROM_API_T;

/* Pointer to ROM API function address */
#define LPC_ROM_API_BASE_LOC    0x1FFF1FF8UL
#define LPC_ROM_API        (*(LPC_ROM_API_T * *) LPC_ROM_API_BASE_LOC)

/* Pointer to @ref PWRD_API_T functions in ROM */
#define LPC_PWRD_API    ((LPC_ROM_API)->pPWRD)

/* Pointer to @ref I2CD_API_T functions in ROM */
#define LPC_I2CD_API    ((LPC_ROM_API)->pI2CD)

/* Pointer to @ref UARTD_API_T functions in ROM */
#define LPC_UARTD_API   ((LPC_ROM_API)->pUARTD)

#endif