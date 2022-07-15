/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series common ROM defines and functions.
*/
#ifndef LPC8XX_ROM_H
#define LPC8XX_ROM_H

#include "nxp/LPC8XX/LPC8XX_ROM_iap.h"
#include "nxp/LPC8XX/LPC8XX_ROM_error.h"
#include "nxp/LPC8XX/LPC8XX_ROM_i2c.h"
#include "nxp/LPC8XX/LPC8XX_ROM_pwr.h"
#include "nxp/LPC8XX/LPC8XX_ROM_uart.h"

typedef struct ROM_API {
  const uint32_t unused[3];
  const PWRD_API_T *pPWRD; /*!< Power profiles API function table */
  const uint32_t p_dev1;
  const I2CD_API_T *pI2CD; /*!< I2C driver routines functions table */
  const uint32_t p_dev3;
  const uint32_t p_dev4;
  const uint32_t p_dev5;
  const UARTD_API_T *pUARTD; /*!< UART driver routines function table */
} LPC_ROM_API_T;

/* Pointer to ROM API function address */
#define LPC_ROM_API_BASE_LOC 0x1FFF1FF8UL
#define LPC_ROM_API (*(LPC_ROM_API_T **)LPC_ROM_API_BASE_LOC)

/* Pointer to @ref PWRD_API_T functions in ROM */
#define LPC_PWRD_API ((LPC_ROM_API)->pPWRD)

/* Pointer to @ref I2CD_API_T functions in ROM */
#define LPC_I2CD_API ((LPC_ROM_API)->pI2CD)

/* Pointer to @ref UARTD_API_T functions in ROM */
#define LPC_UARTD_API ((LPC_ROM_API)->pUARTD)

#endif