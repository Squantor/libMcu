/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2022 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/**
 * @brief series pin interrupt and pattern match registers, defines and functions.
 */
#ifndef LPC82X_PININT_H
#define LPC82X_PININT_H

/**
 * @brief Pin interrupt hardware registers
 *
 */
typedef volatile struct {
  uint32_t ISEL;   /*!< Pin Interrupt Mode register */
  uint32_t IENR;   /*!< Pin Interrupt level or rising edge enable register */
  uint32_t SIENR;  /*!< Pin Interrupt level or rising edge set register  */
  uint32_t CIENR;  /*!< Pin Interrupt level or rising edge clear register */
  uint32_t IENF;   /*!< Pin Interrupt active level or falling edge enable register */
  uint32_t SIENF;  /*!< Pin Interrupt active level or falling edge set register */
  uint32_t CIENF;  /*!< Pin Interrupt active level or falling edge clear register */
  uint32_t RISE;   /*!< Pin Interrupt Rising Edge register */
  uint32_t FALL;   /*!< Pin Interrupt Falling Edge register */
  uint32_t IST;    /*!< Pin Interrupt Status register */
  uint32_t PMCTRL; /*!< Pattern match interrupt control register */
  uint32_t PMSRC;  /*!< Pattern match interrupt bit-slice source register */
  uint32_t PMCFG;  /*!< Pattern match interrupt bit slice configuration register */
} PIN_INT_Type;



#include <nxp/LPC8XX/LPC8XX_pinint.h>
#include <nxp/LPC8XX/LPC8XX_pinint_old.h>

#endif