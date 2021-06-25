/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series common flash memory controller registers,definitions 
and functions.
*/
#ifndef LPC8XX_FMC_H
#define LPC8XX_FMC_H

/* FLASH Memory Controller Unit register block structure */
typedef volatile struct {
    const uint32_t RESERVED1[4];
    uint32_t FLASHCFG;              /*!< Flash Configuration register */
    const uint32_t RESERVED2[3];
    uint32_t FMSSTART;              /*!< Signature start address register */
    uint32_t FMSSTOP;               /*!< Signature stop address register */
    const uint32_t RESERVED3;
    const uint32_t FMSW[1];         /*!< Signature word regsiter */
} LPC_FMC_T;

/* Reserved bits masks for registers */
#define FMC_FLASHCFG_RESERVED       (~3)
#define FMC_FMSSTART_RESERVED       0xfffe0000
#define FMC_FMSSTOP_RESERVED        0x7ffe0000

/* FLASH Access time definitions */
typedef enum {
    FLASHTIM_20MHZ_CPU = 0, /* Flash accesses use 1 CPU clocks. Use for up to 20 MHz CPU clock*/
    FLASHTIM_30MHZ_CPU = 1, /* Flash accesses use 2 CPU clocks. Use for up to 30 MHz CPU clock*/
} FMC_FLASHTIM_T;

static inline void FmcSetFlashAccess(FMC_FLASHTIM_T clks)
{
    uint32_t tmp = LPC_FMC->FLASHCFG & (~((0x3)|FMC_FLASHCFG_RESERVED));

    /* Don't alter upper bits */
    LPC_FMC->FLASHCFG = tmp | clks;
}

/* Flash signature start and busy status bit */
#define FMC_FLASHSIG_BUSY    (1UL << 31)

static inline void FmcComputeSignature(uint32_t start, uint32_t stop)
{
    LPC_FMC->FMSSTART = (start >> 4);
    LPC_FMC->FMSSTOP = (stop >> 4) | FMC_FLASHSIG_BUSY;
}

static inline void FmcComputeSignatureBlocks(uint32_t start, uint32_t blocks)
{
    FmcComputeSignature(start, (start + (blocks * 16)));
}

static inline bool FmcIsSignatureBusy(void)
{
    return (bool) ((LPC_FMC->FMSSTOP & FMC_FLASHSIG_BUSY) != 0);
}

static inline uint32_t FmcGetSignature(int index)
{
    return LPC_FMC->FMSW[index];
}

#endif