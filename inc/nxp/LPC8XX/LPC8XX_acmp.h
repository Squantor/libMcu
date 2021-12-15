/*
SPDX-License-Identifier: Unlicense
Copyright (c) 2020 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series common analog comparator registers,definitions and 
functions.
*/
#ifndef LPC8XX_ACMP_H
#define LPC8XX_ACMP_H

typedef volatile struct {   /* ACMP Structure */
    uint32_t  CTRL;         /* Comparator control register */
    uint32_t  LAD;          /* Voltage ladder register */
} CMP_Type;

/*
Definitions for the Analog comparator control register
*/
#define ACMP_CTRL_RESERVED      (7|(1<<5)|(1<<7)|(0x3f<<14)|(1<<22)|(1<<24)|(0x1fu<<27))
#define ACMP_CTRL_COMPSA_DIR    (0 << 6)    /* Comparator output directly used*/
#define ACMP_CTRL_COMPSA_SYNC   (1 << 6)    /* Comparator output synchronized to bus clock */
#define ACMP_EDGECLR_BIT        (1 << 20)   /* Interrupt clear bit */
#define ACMP_COMPSTAT_BIT       (1 << 21)   /* Comparator status, reflects the state of the comparator output */
#define ACMP_COMPEDGE_BIT       (1 << 23)   /* Comparator edge-detect status */

#define ACMP_COMPVPSEL_MASK     (0x7 << 8)
#define ACMP_COMPVMSEL_MASK     (0x7 << 11)
#define ACMP_HYSTERESIS_MASK    (0x3 << 25)
#define ACMP_LADSEL_MASK        (0x1F << 1)
#define ACMP_LADREF_MASK        (0x1 << 6)

/** Edge selection for comparator */
typedef enum {
    ACMP_EDGESEL_FALLING = (0 << 3),    /* Set the COMPEDGE bit on falling edge */
    ACMP_EDGESEL_RISING  = (1 << 3),    /* Set the COMPEDGE bit on rising edge */
    ACMP_EDGESEL_BOTH    = (2 << 3)     /* Set the COMPEDGE bit on falling and rising edges */
} ACMP_EDGESEL_T;

/** Hysteresis selection for comparator */
typedef enum {
    ACMP_HYS_NONE = (0 << 25),  /* No hysteresis (the output will switch as the voltages cross) */
    ACMP_HYS_5MV  = (1 << 25),  /* 5mV hysteresis */
    ACMP_HYS_10MV = (2 << 25),  /* 10mV hysteresis */
    ACMP_HYS_20MV = (3 << 25)   /* 20mV hysteresis */
} ACMP_HYS_T;

/*
Definitions for the Analog comparator resistor ladder register
*/
#define ACMP_LAD_RESERVED   (~0x7f)
#define ACMP_LAD_ENABLE     (1<<0)      /* Resistor ladder enable */
#define ACMP_LADSEL(x)      ((x) << 1)  /* Resistor ladder tap setting */
#define ACMP_LADREF_VDD     (0 << 6)    /* Resistor ladder reference is VDD */
#define ACMP_LADREF_VDDCMP  (1 << 6)    /* Resistor ladder reference is VDDCMP */


static inline void AcmpControl(CMP_Type *acmp, uint32_t value)
{
    acmp->CTRL = value;
}

static inline uint32_t AcmpControlGet(CMP_Type *acmp)
{
    return acmp->CTRL;
}

static inline void AcmpControlSet(CMP_Type *acmp, uint32_t value)
{
    acmp->CTRL = value | acmp->CTRL;
}

static inline void AcmpControlClr(CMP_Type *acmp, uint32_t value)
{
    uint32_t ctrlRegister = acmp->CTRL & ~value;
    acmp->CTRL = ctrlRegister;
}

static inline void AcmpLadder(CMP_Type *acmp, uint32_t value)
{
    acmp->LAD = value;
}

static inline void AcmpEdgeClear(CMP_Type *pACMP)
{
    uint32_t reg = pACMP->CTRL & ~ACMP_CTRL_RESERVED;
    pACMP->CTRL = reg | ACMP_EDGECLR_BIT;
    pACMP->CTRL = reg & ~ACMP_EDGECLR_BIT;
}

static inline void AcmpSetPosVoltRef(CMP_Type *pACMP, ACMP_POS_INPUT_T Posinput)
{
    uint32_t reg = pACMP->CTRL & ~(ACMP_COMPVPSEL_MASK | ACMP_CTRL_RESERVED);
    pACMP->CTRL = reg | (uint32_t) Posinput;
}

static inline void AcmpSetNegVoltRef(CMP_Type *pACMP, ACMP_NEG_INPUT_T Neginput)
{
    uint32_t reg = pACMP->CTRL & ~(ACMP_COMPVMSEL_MASK | ACMP_CTRL_RESERVED);
    pACMP->CTRL = reg | (uint32_t) Neginput;
}

static inline void AcmpSetHysteresis(CMP_Type *pACMP, ACMP_HYS_T hys)
{
    uint32_t reg = pACMP->CTRL & ~(ACMP_HYSTERESIS_MASK | ACMP_CTRL_RESERVED);
    pACMP->CTRL = reg | (uint32_t) hys;
}

static inline void AcmpSetupVoltLadder(CMP_Type *pACMP, uint32_t ladsel, bool ladrefVDDCMP)
{
    uint32_t reg = pACMP->LAD & ~(ACMP_LADSEL_MASK | ACMP_LADREF_MASK | ACMP_LAD_RESERVED);
    if(ladrefVDDCMP)
        reg |= ACMP_LADREF_MASK;
    pACMP->LAD = reg | (ladsel << 1);
}

#endif