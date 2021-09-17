/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series common pin interrupt and pattern match registers, 
defines and functions.
*/
#ifndef LPC8XX_PININT_H
#define LPC8XX_PININT_H

/* LPC8xx Pin Interrupt and Pattern Match register block structure */
typedef volatile struct {            
    uint32_t ISEL;     /**< Pin Interrupt Mode register */
    uint32_t IENR;     /**< Pin Interrupt Enable (Rising) register */
    uint32_t SIENR;    /**< Set Pin Interrupt Enable (Rising) register */
    uint32_t CIENR;    /**< Clear Pin Interrupt Enable (Rising) register */
    uint32_t IENF;     /**< Pin Interrupt Enable Falling Edge / Active Level register */
    uint32_t SIENF;    /**< Set Pin Interrupt Enable Falling Edge / Active Level register */
    uint32_t CIENF;    /**< Clear Pin Interrupt Enable Falling Edge / Active Level address */
    uint32_t RISE;     /**< Pin Interrupt Rising Edge register */
    uint32_t FALL;     /**< Pin Interrupt Falling Edge register */
    uint32_t IST;      /**< Pin Interrupt Status register */
    uint32_t PMCTRL;   /**< GPIO pattern match interrupt control register */
    uint32_t PMSRC;    /**< GPIO pattern match interrupt bit-slice source register */
    uint32_t PMCFG;    /**< GPIO pattern match interrupt bit slice configuration register */
} PIN_INT_Type;

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
#define PININT_PMSRC_RESERVED   (0xff)
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

#endif