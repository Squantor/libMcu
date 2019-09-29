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
LPC800 series common analog comparator registers,definitions and 
functions.
*/
#ifndef LPC8XX_ACMP_H
#define LPC8XX_ACMP_H

typedef struct {            /* ACMP Structure */
    __IO uint32_t  CTRL;    /* Comparator control register */
    __IO uint32_t  LAD;     /* Voltage ladder register */
} LPC_CMP_T;

/* Reserved bits masks for registers */
#define ACMP_CTRL_RESERVED  (7|(1<<5)|(1<<7)|(0x3f<<14)|(1<<22)|(1<<24)|(0x1fu<<27))
#define ACMP_LAD_RESERVED   (~0x7f)

#define ACMP_COMPSA_BIT     (1 << 6)    /* Comparator output control bit */
#define ACMP_COMPSTAT_BIT   (1 << 21)   /* Comparator status, reflects the state of the comparator output */
#define ACMP_COMPEDGE_BIT   (1 << 23)   /* Comparator edge-detect status */
#define ACMP_LADENAB_BIT    (1 << 0)    /* Voltage ladder enable bit */

/* EDGECLR interrupt clear bit, write 1, then 0 */
#define ACMP_EDGECLR_BIT        (1 << 20)
#define ACMP_EDGESEL_MASK       (0x3 << 3)
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

static inline void AcmpInit(void)
{
    SYSCTL_PowerUp(SYSCTL_SLPWAKE_ACMP_PD);
    ClockEnablePeriphClock(SYSCTL_CLOCK_ACOMP);
}

static inline void AcmpDeinit(void)
{
    ClockDisablePeriphClock(SYSCTL_CLOCK_ACOMP);
    SYSCTL_PowerDown(SYSCTL_SLPWAKE_ACMP_PD);
}

static inline uint32_t AcmpGetCompStatus(LPC_CMP_T *pACMP)
{
    return pACMP->CTRL & (ACMP_COMPSTAT_BIT | ACMP_COMPEDGE_BIT);
}

static inline void AcmpEdgeClear(LPC_CMP_T *pACMP)
{
    uint32_t reg = pACMP->CTRL & ~ACMP_CTRL_RESERVED;
    pACMP->CTRL = reg | ACMP_EDGECLR_BIT;
    pACMP->CTRL = reg & ~ACMP_EDGECLR_BIT;
}

static inline void AcmpSetEdgeSelection(LPC_CMP_T *pACMP, ACMP_EDGESEL_T edgeSel)
{
    uint32_t reg = pACMP->CTRL & ~(ACMP_EDGESEL_MASK | ACMP_CTRL_RESERVED);
    pACMP->CTRL = reg | (uint32_t) edgeSel;
}

static inline void AcmpEnableSyncCompOut(LPC_CMP_T *pACMP)
{
    pACMP->CTRL = ACMP_COMPSA_BIT | (pACMP->CTRL & ~ACMP_CTRL_RESERVED);
}

static inline void AcmpDisableSyncCompOut(LPC_CMP_T *pACMP)
{
    pACMP->CTRL &= ~(ACMP_COMPSA_BIT | ACMP_CTRL_RESERVED);
}

static inline void AcmpSetPosVoltRef(LPC_CMP_T *pACMP, ACMP_POS_INPUT_T Posinput)
{
    uint32_t reg = pACMP->CTRL & ~(ACMP_COMPVPSEL_MASK | ACMP_CTRL_RESERVED);
    pACMP->CTRL = reg | (uint32_t) Posinput;
}

static inline void AcmpSetNegVoltRef(LPC_CMP_T *pACMP, ACMP_NEG_INPUT_T Neginput)
{
    uint32_t reg = pACMP->CTRL & ~(ACMP_COMPVMSEL_MASK | ACMP_CTRL_RESERVED);
    pACMP->CTRL = reg | (uint32_t) Neginput;
}

static inline void AcmpSetHysteresis(LPC_CMP_T *pACMP, ACMP_HYS_T hys)
{
    uint32_t reg = pACMP->CTRL & ~(ACMP_HYSTERESIS_MASK | ACMP_CTRL_RESERVED);
    pACMP->CTRL = reg | (uint32_t) hys;
}

static inline void AcmpSetupAMCPRefs(LPC_CMP_T *pACMP, ACMP_EDGESEL_T edgeSel,
                             ACMP_POS_INPUT_T Posinput, ACMP_NEG_INPUT_T Neginput,
                             ACMP_HYS_T hys)
{
    uint32_t reg = pACMP->CTRL & ~(ACMP_HYSTERESIS_MASK | ACMP_CTRL_RESERVED |
                                   ACMP_COMPVMSEL_MASK | ACMP_COMPVPSEL_MASK | ACMP_EDGESEL_MASK);
    pACMP->CTRL = reg | (uint32_t) edgeSel | (uint32_t) Posinput |
                  (uint32_t) Neginput | (uint32_t) hys;
}

static inline void AcmpSetupVoltLadder(LPC_CMP_T *pACMP, uint32_t ladsel, bool ladrefVDDCMP)
{
    uint32_t reg = pACMP->LAD & ~(ACMP_LADSEL_MASK | ACMP_LADREF_MASK | ACMP_LAD_RESERVED);
    if(ladrefVDDCMP)
        reg |= ACMP_LADREF_MASK;
    pACMP->LAD = reg | (ladsel << 1);
}

static inline void AcmpEnableVoltLadder(LPC_CMP_T *pACMP)
{
    pACMP->LAD = ACMP_LADENAB_BIT | (pACMP->LAD & ~ACMP_LAD_RESERVED);
}

static inline void AcmpDisableVoltLadder(LPC_CMP_T *pACMP)
{
    pACMP->LAD &= ~(ACMP_LADENAB_BIT | ACMP_LAD_RESERVED);
}

#endif