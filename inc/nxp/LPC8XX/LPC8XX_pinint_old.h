/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series common pin interrupt and pattern match registers,
defines and functions.
*/
#ifndef LPC8XX_PININT_OLD_H
#define LPC8XX_PININT_OLD_H

/* PININT interrupt control register */
#define PININT_PMCTRL_PMATCH_SEL (1 << 0)
#define PININT_PMCTRL_RXEV_ENA (1 << 1)

/* PININT Bit slice source register bits */
#define PININT_SRC_BITSOURCE_START 8
#define PININT_SRC_BITSOURCE_MASK 7

/* PININT Bit slice configuration register bits */
#define PININT_SRC_BITCFG_START 8
#define PININT_SRC_BITCFG_MASK 7

/* LPC8xx Pin Interrupt channel values */
#define PININTCH0 (1 << 0)
#define PININTCH1 (1 << 1)
#define PININTCH2 (1 << 2)
#define PININTCH3 (1 << 3)
#define PININTCH4 (1 << 4)
#define PININTCH5 (1 << 5)
#define PININTCH6 (1 << 6)
#define PININTCH7 (1 << 7)
#define PININTCH(ch) (1 << (ch))

/* LPC8xx Pin Matching Interrupt bit slice enum values */
typedef enum PININT_BITSLICE {
  PININTBITSLICE0 = 0,
  PININTBITSLICE1 = 1,
  PININTBITSLICE2 = 2,
  PININTBITSLICE3 = 3,
  PININTBITSLICE4 = 4,
  PININTBITSLICE5 = 5,
  PININTBITSLICE6 = 6,
  PININTBITSLICE7 = 7
} PININT_BITSLICE_T;

/* LPC8xx Pin Matching Interrupt bit slice configuration enum values */
typedef enum PININT_BITSLICE_CFG {
  PININT_PATTERNCONST1 = 0x0,         /*!< Contributes to product term match */
  PININT_PATTERNRISING = 0x1,         /*!< Rising edge */
  PININT_PATTERNFALLING = 0x2,        /*!< Falling edge */
  PININT_PATTERNRISINGRFALLING = 0x3, /*!< Rising or Falling edge */
  PININT_PATTERNHIGH = 0x4,           /*!< High level */
  PININT_PATTERNLOW = 0x5,            /*!< Low level */
  PININT_PATTERCONST0 = 0x6,          /*!< Never contributes for match */
  PININT_PATTEREVENT = 0x7            /*!< Match occurs on event */
} PININT_BITSLICE_CFG_T;

static inline void PinintSetPatternMatchSrc(PIN_INT_Type *pPININT, uint8_t chan, PININT_BITSLICE_T slice) {
  uint32_t pmsrc_reg;

  /* Source source for pattern matching */
  pmsrc_reg = pPININT->PMSRC & ~((PININT_SRC_BITSOURCE_MASK << (PININT_SRC_BITSOURCE_START + (slice * 3))) | PININT_PMSRC_RESERVED);
  pPININT->PMSRC = pmsrc_reg | (chan << (PININT_SRC_BITSOURCE_START + (slice * 3)));
}

static inline void PinintSetPatternMatchConfig(PIN_INT_Type *pPININT, PININT_BITSLICE_T slice, PININT_BITSLICE_CFG_T slice_cfg,
                                               bool end_point) {
  uint32_t pmcfg_reg;

  /* Configure bit slice configuration */
  pmcfg_reg = pPININT->PMCFG & ~((PININT_SRC_BITCFG_MASK << (PININT_SRC_BITCFG_START + (slice * 3))) | PININT_PMCFG_RESERVED);
  pPININT->PMCFG = pmcfg_reg | (slice_cfg << (PININT_SRC_BITCFG_START + (slice * 3)));

  /* If end point is true, enable the bits */
  if (end_point == true) /* By default slice 7 is final component */
    if (slice != PININTBITSLICE7) pPININT->PMCFG = (0x1 << slice) | (pPININT->PMCFG & ~PININT_PMCFG_RESERVED);
}

static inline void PinintEnablePatternMatch(PIN_INT_Type *pPININT) {
  pPININT->PMCTRL = PININT_PMCTRL_PMATCH_SEL | (pPININT->PMCTRL & ~PININT_PMCTRL_RESERVED);
}

static inline void PinintDisablePatternMatch(PIN_INT_Type *pPININT) {
  uint32_t pmctrlRegister = pPININT->PMCTRL & ~(PININT_PMCTRL_PMATCH_SEL | PININT_PMCTRL_RESERVED);
  pPININT->PMCTRL = pmctrlRegister;
}

static inline void PinintEnablePatternMatchRxEv(PIN_INT_Type *pPININT) {
  pPININT->PMCTRL = PININT_PMCTRL_RXEV_ENA | (pPININT->PMCTRL & ~PININT_PMCTRL_RESERVED);
}

static inline void PinintDisablePatternMatchRxEv(PIN_INT_Type *pPININT) {
  uint32_t pmctrlRegister = pPININT->PMCTRL & ~(PININT_PMCTRL_RXEV_ENA | PININT_PMCTRL_RESERVED);
  pPININT->PMCTRL = pmctrlRegister;
}

#endif