/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
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

typedef enum {
  PININT_CHAN0 = (1 << 0),
  PININT_CHAN1 = (1 << 1),
  PININT_CHAN2 = (1 << 2),
  PININT_CHAN3 = (1 << 3),
  PININT_CHAN4 = (1 << 4),
  PININT_CHAN5 = (1 << 5),
  PININT_CHAN6 = (1 << 6),
  PININT_CHAN7 = (1 << 7),
} PININT_CHAN_Type;

#define PININT_ISEL_RESERVED (0xFFFFFF00)
#define PININT_IENR_RESERVED (0xFFFFFF00)
#define PININT_SIENR_RESERVED (0xFFFFFF00)
#define PININT_CIENR_RESERVED (0xFFFFFF00)
#define PININT_IENF_RESERVED (0xFFFFFF00)
#define PININT_SIENF_RESERVED (0xFFFFFF00)
#define PININT_CIENF_RESERVED (0xFFFFFF00)
#define PININT_RISE_RESERVED (0xFFFFFF00)
#define PININT_FALL_RESERVED (0xFFFFFF00)
#define PININT_IST_RESERVED (0xFFFFFF00)
#define PININT_PMCTRL_RESERVED (0x00FFFFFFC)
#define PININT_PMSRC_RESERVED (0xFFFFFF00)
#define PININT_PMCFG_RESERVED (0x00000080)

static inline void pinintSetPinModeEdge(PIN_INT_Type *peripheral, uint32_t pins) {
  uint32_t iselRegister = peripheral->ISEL & ~(pins | PININT_ISEL_RESERVED);
  peripheral->ISEL = iselRegister;
}

static inline void pinintSetPinModeLevel(PIN_INT_Type *peripheral, uint32_t pins) {
  peripheral->ISEL = pins | (peripheral->ISEL & ~PININT_ISEL_RESERVED);
}

static inline uint32_t pinintGetHighEnabled(PIN_INT_Type *peripheral) {
  return peripheral->IENR & ~PININT_IENR_RESERVED;
}

static inline void pinintEnableIntHigh(PIN_INT_Type *peripheral, uint32_t pins) {
  peripheral->SIENR = pins;
}

static inline void pinintDisableIntHigh(PIN_INT_Type *peripheral, uint32_t pins) {
  peripheral->CIENR = pins;
}

static inline uint32_t pinintGetLowEnabled(PIN_INT_Type *peripheral) {
  return peripheral->IENF & ~PININT_IENF_RESERVED;
}

static inline void pinintEnableIntLow(PIN_INT_Type *peripheral, uint32_t pins) {
  peripheral->SIENF = pins;
}

static inline void pinintDisableIntLow(PIN_INT_Type *peripheral, uint32_t pins) {
  peripheral->CIENF = pins;
}

static inline uint32_t pinintGetRiseStates(PIN_INT_Type *peripheral) {
  return peripheral->RISE & ~PININT_RISE_RESERVED;
}

static inline void pinintClearRiseStates(PIN_INT_Type *peripheral, uint32_t pins) {
  peripheral->RISE = pins;
}

static inline uint32_t pinintGetFallStates(PIN_INT_Type *peripheral) {
  return peripheral->FALL & ~PININT_FALL_RESERVED;
}

static inline void pinintClearFallStates(PIN_INT_Type *peripheral, uint32_t pins) {
  peripheral->FALL = pins;
}

static inline uint32_t pinintGetIntStatus(PIN_INT_Type *peripheral) {
  return peripheral->IST & ~PININT_IST_RESERVED;
}

static inline void pinintClearIntStatus(PIN_INT_Type *peripheral, uint32_t pins) {
  peripheral->IST = pins;
}

#include <nxp/LPC8XX/LPC8XX_pinint.h>
#include <nxp/LPC8XX/LPC8XX_pinint_old.h>

#endif