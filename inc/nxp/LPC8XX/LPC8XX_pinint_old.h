/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
LPC800 series common pin interrupt and pattern match registers, 
defines and functions.
*/
#ifndef LPC8XX_PININT_OLD_H
#define LPC8XX_PININT_OLD_H

static inline void PinintInit(void) {}

static inline void PinintDeInit(void) {}

static inline void PinintSetPinModeEdge(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->ISEL &= ~(pins | PININT_ISEL_RESERVED);
}

static inline void PinintSetPinModeLevel(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->ISEL = pins | (pPININT->ISEL & ~PININT_ISEL_RESERVED);
}

static inline uint32_t PinintGetHighEnabled(LPC_PIN_INT_T *pPININT)
{
    return pPININT->IENR & ~PININT_IENR_RESERVED;
}

static inline void PinintEnableIntHigh(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->SIENR = pins;
}

static inline void PinintDisableIntHigh(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->CIENR = pins;
}

static inline uint32_t PinintGetLowEnabled(LPC_PIN_INT_T *pPININT)
{
    return pPININT->IENF & ~PININT_IENF_RESERVED;
}

static inline void PinintEnableIntLow(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->SIENF = pins;
}

static inline void PinintDisableIntLow(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->CIENF = pins;
}

static inline uint32_t PinintGetRiseStates(LPC_PIN_INT_T *pPININT)
{
    return pPININT->RISE & ~PININT_RISE_RESERVED;
}

static inline void PinintClearRiseStates(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
        pPININT->RISE = pins;
}

static inline uint32_t PinintGetFallStates(LPC_PIN_INT_T *pPININT)
{
    return pPININT->FALL & ~PININT_FALL_RESERVED;
}

static inline void PinintClearFallStates(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->FALL = pins;
}

static inline uint32_t PinintGetIntStatus(LPC_PIN_INT_T *pPININT)
{
    return pPININT->IST& ~PININT_IST_RESERVED;
}

static inline void PinintClearIntStatus(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->IST = pins;
}

static inline void PinintSetPatternMatchSrc(LPC_PIN_INT_T *pPININT, uint8_t chan, PININT_BITSLICE_T slice)
{
    uint32_t pmsrc_reg;
    
    /* Source source for pattern matching */ 
    pmsrc_reg = pPININT->PMSRC & ~((PININT_SRC_BITSOURCE_MASK << (PININT_SRC_BITSOURCE_START + (slice * 3)))
        | PININT_PMSRC_RESERVED);
    pPININT->PMSRC = pmsrc_reg | (chan << (PININT_SRC_BITSOURCE_START + (slice * 3)));
}

static inline void PinintSetPatternMatchConfig(LPC_PIN_INT_T *pPININT, PININT_BITSLICE_T slice, 
        PININT_BITSLICE_CFG_T slice_cfg, bool end_point)
{
    uint32_t pmcfg_reg;
    
    /* Configure bit slice configuration */
    pmcfg_reg = pPININT->PMCFG & ~((PININT_SRC_BITCFG_MASK << (PININT_SRC_BITCFG_START + (slice * 3)))
        | PININT_PMCFG_RESERVED);
    pPININT->PMCFG = pmcfg_reg | (slice_cfg << (PININT_SRC_BITCFG_START + (slice * 3)));

    /* If end point is true, enable the bits */
    if (end_point == true)
        /* By default slice 7 is final component */
        if (slice != PININTBITSLICE7)
            pPININT->PMCFG = (0x1 << slice) | (pPININT->PMCFG & ~PININT_PMCFG_RESERVED);
}

static inline void PinintEnablePatternMatch(LPC_PIN_INT_T *pPININT)
{
    pPININT->PMCTRL = PININT_PMCTRL_PMATCH_SEL | (pPININT->PMCTRL & ~PININT_PMCTRL_RESERVED);
}

static inline void PinintDisablePatternMatch(LPC_PIN_INT_T *pPININT)
{
    pPININT->PMCTRL &= ~(PININT_PMCTRL_PMATCH_SEL | PININT_PMCTRL_RESERVED);
}

static inline void PinintEnablePatternMatchRxEv(LPC_PIN_INT_T *pPININT)
{
    pPININT->PMCTRL = PININT_PMCTRL_RXEV_ENA | (pPININT->PMCTRL & ~PININT_PMCTRL_RESERVED);
}

static inline void PinintDisablePatternMatchRxEv(LPC_PIN_INT_T *pPININT)
{
    pPININT->PMCTRL &= ~(PININT_PMCTRL_RXEV_ENA | PININT_PMCTRL_RESERVED);
}

#endif