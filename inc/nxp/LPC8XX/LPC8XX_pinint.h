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
LPC800 series common pin interrupt and pattern match registers,
definitions and functions.
*/
#ifndef LPC8XX_PININT_H
#define LPC8XX_PININT_H

/* LPC8xx Pin Interrupt and Pattern Match register block structure */
typedef struct {            
    volatile uint32_t ISEL;        /* Pin Interrupt Mode register */
    volatile uint32_t IENR;        /* Pin Interrupt Enable (Rising) register */
    volatile uint32_t SIENR;    /* Set Pin Interrupt Enable (Rising) register */
    volatile uint32_t CIENR;    /* Clear Pin Interrupt Enable (Rising) register */
    volatile uint32_t IENF;        /* Pin Interrupt Enable Falling Edge / Active Level register */
    volatile uint32_t SIENF;    /* Set Pin Interrupt Enable Falling Edge / Active Level register */
    volatile uint32_t CIENF;    /* Clear Pin Interrupt Enable Falling Edge / Active Level address */
    volatile uint32_t RISE;        /* Pin Interrupt Rising Edge register */
    volatile uint32_t FALL;        /* Pin Interrupt Falling Edge register */
    volatile uint32_t IST;        /* Pin Interrupt Status register */
    volatile uint32_t PMCTRL;    /* GPIO pattern match interrupt control register          */
    volatile uint32_t PMSRC;    /* GPIO pattern match interrupt bit-slice source register */
    volatile uint32_t PMCFG;    /* GPIO pattern match interrupt bit slice configuration register */
} LPC_PIN_INT_T;

/* Reserved bits masks for registers */
#define PININT_ISEL_RESERVED    (~0xff)
#define PININT_IENR_RESERVED    (~0xff)
#define PININT_SIENR_RESERVED   (~0xff)
#define PININT_CIENR_RESERVED   (~0xff)
#define PININT_IENF_RESERVED    (~0xff)
#define PININT_SIENF_RESERVED   (~0xff)
#define PININT_CIENF_RESERVED   (~0xff)
#define PININT_RISE_RESERVED    (~0xff)
#define PININT_FALL_RESERVED    (~0xff)
#define PININT_IST_RESERVED     (~0xff)
#define PININT_PMCTRL_RESERVED  (~0xff000003)
#define PININT_PMSRC_RESERVED   0xff
#define PININT_PMCFG_RESERVED   (1<<7)

/*
LPC8xx Pin Interrupt and Pattern match engine register bit 
fields and macros
 */
/* PININT interrupt control register */
#define PININT_PMCTRL_PMATCH_SEL (1 << 0) 
#define PININT_PMCTRL_RXEV_ENA   (1 << 1) 

/* PININT Bit slice source register bits */
#define PININT_SRC_BITSOURCE_START  8
#define PININT_SRC_BITSOURCE_MASK   7

/* PININT Bit slice configuration register bits */
#define PININT_SRC_BITCFG_START  8
#define PININT_SRC_BITCFG_MASK   7

/* LPC8xx Pin Interrupt channel values */
#define PININTCH0         (1 << 0)
#define PININTCH1         (1 << 1)
#define PININTCH2         (1 << 2)
#define PININTCH3         (1 << 3)
#define PININTCH4         (1 << 4)
#define PININTCH5         (1 << 5)
#define PININTCH6         (1 << 6)
#define PININTCH7         (1 << 7)
#define PININTCH(ch)      (1 << (ch))

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
    PININT_PATTERNCONST1           = 0x0,    /*!< Contributes to product term match */
    PININT_PATTERNRISING           = 0x1,    /*!< Rising edge */    
    PININT_PATTERNFALLING          = 0x2,    /*!< Falling edge */    
    PININT_PATTERNRISINGRFALLING   = 0x3,    /*!< Rising or Falling edge */    
    PININT_PATTERNHIGH             = 0x4,    /*!< High level */    
    PININT_PATTERNLOW              = 0x5,    /*!< Low level */    
    PININT_PATTERCONST0            = 0x6,    /*!< Never contributes for match */    
    PININT_PATTEREVENT             = 0x7    /*!< Match occurs on event */    
} PININT_BITSLICE_CFG_T;

#pragma GCC diagnostic ignored "-Wunused-parameter"

static inline void PININT_Init(LPC_PIN_INT_T *pPININT) {}

static inline void PININT_DeInit(LPC_PIN_INT_T *pPININT) {}
#pragma GCC diagnostic pop

static inline void PININT_SetPinModeEdge(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->ISEL &= ~(pins | PININT_ISEL_RESERVED);
}

static inline void PININT_SetPinModeLevel(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->ISEL = pins | (pPININT->ISEL & ~PININT_ISEL_RESERVED);
}

static inline uint32_t PININT_GetHighEnabled(LPC_PIN_INT_T *pPININT)
{
    return pPININT->IENR & ~PININT_IENR_RESERVED;
}

static inline void PININT_EnableIntHigh(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->SIENR = pins;
}

static inline void PININT_DisableIntHigh(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->CIENR = pins;
}

static inline uint32_t PININT_GetLowEnabled(LPC_PIN_INT_T *pPININT)
{
    return pPININT->IENF & ~PININT_IENF_RESERVED;
}

static inline void PININT_EnableIntLow(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->SIENF = pins;
}

static inline void PININT_DisableIntLow(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->CIENF = pins;
}

static inline uint32_t PININT_GetRiseStates(LPC_PIN_INT_T *pPININT)
{
    return pPININT->RISE & ~PININT_RISE_RESERVED;
}

static inline void PININT_ClearRiseStates(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
        pPININT->RISE = pins;
}

static inline uint32_t PININT_GetFallStates(LPC_PIN_INT_T *pPININT)
{
    return pPININT->FALL & ~PININT_FALL_RESERVED;
}

static inline void PININT_ClearFallStates(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->FALL = pins;
}

static inline uint32_t PININT_GetIntStatus(LPC_PIN_INT_T *pPININT)
{
    return pPININT->IST& ~PININT_IST_RESERVED;
}

static inline void PININT_ClearIntStatus(LPC_PIN_INT_T *pPININT, uint32_t pins)
{
    pPININT->IST = pins;
}

static inline void PININT_SetPatternMatchSrc(LPC_PIN_INT_T *pPININT, uint8_t chan, PININT_BITSLICE_T slice)
{
    uint32_t pmsrc_reg;
    
    /* Source source for pattern matching */ 
    pmsrc_reg = pPININT->PMSRC & ~((PININT_SRC_BITSOURCE_MASK << (PININT_SRC_BITSOURCE_START + (slice * 3)))
        | PININT_PMSRC_RESERVED);
    pPININT->PMSRC = pmsrc_reg | (chan << (PININT_SRC_BITSOURCE_START + (slice * 3)));
}

static inline void PININT_SetPatternMatchConfig(LPC_PIN_INT_T *pPININT, PININT_BITSLICE_T slice, 
        PININT_BITSLICE_CFG_T slice_cfg, bool end_point)
{
    uint32_t pmcfg_reg;
    
    /* Configure bit slice configuration */
    pmcfg_reg = pPININT->PMCFG & ~((PININT_SRC_BITCFG_MASK << (PININT_SRC_BITCFG_START + (slice * 3)))
        | PININT_PMCFG_RESERVED);
    pPININT->PMCFG = pmcfg_reg | (slice_cfg << (PININT_SRC_BITCFG_START + (slice * 3)));

    /* If end point is true, enable the bits */
    if (end_point == true)
    {
        /* By default slice 7 is final component */
        if (slice != PININTBITSLICE7)
        {
            pPININT->PMCFG = (0x1 << slice) | (pPININT->PMCFG & ~PININT_PMCFG_RESERVED);
        }
    }
}

static inline void PININT_EnablePatternMatch(LPC_PIN_INT_T *pPININT)
{
    pPININT->PMCTRL = PININT_PMCTRL_PMATCH_SEL | (pPININT->PMCTRL & ~PININT_PMCTRL_RESERVED);
}

static inline void PININT_DisablePatternMatch(LPC_PIN_INT_T *pPININT)
{
    pPININT->PMCTRL &= ~(PININT_PMCTRL_PMATCH_SEL | PININT_PMCTRL_RESERVED);
}

static inline void PININT_EnablePatternMatchRxEv(LPC_PIN_INT_T *pPININT)
{
    pPININT->PMCTRL = PININT_PMCTRL_RXEV_ENA | (pPININT->PMCTRL & ~PININT_PMCTRL_RESERVED);
}

static inline void PININT_DisablePatternMatchRxEv(LPC_PIN_INT_T *pPININT)
{
    pPININT->PMCTRL &= ~(PININT_PMCTRL_RXEV_ENA | PININT_PMCTRL_RESERVED);
}

#endif