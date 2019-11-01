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
LPC800 series common flash memory controller registers,definitions 
and functions.
*/
#ifndef LPC8XX_FMC_H
#define LPC8XX_FMC_H

/* FLASH Memory Controller Unit register block structure */
typedef struct {
    __I  uint32_t RESERVED1[4];
    __IO uint32_t FLASHCFG;        /*!< Flash Configuration register */
    __I  uint32_t RESERVED2[3];
    __IO uint32_t FMSSTART;        /*!< Signature start address register */
    __IO uint32_t FMSSTOP;            /*!< Signature stop address register */
    __I  uint32_t RESERVED3;
    __I  uint32_t FMSW[1];            /*!< Signature word regsiter */
} LPC_FMC_T;

/* Reserved bits masks for registers */
#define FMC_FLASHCFG_RESERVED       (~3)
#define FMC_FMSSTART_RESERVED       0xfffe0000
#define FMC_FMSSTOP_RESERVED        0x7ffe0000

/* FLASH Access time definitions */
typedef enum {
    FLASHTIM_20MHZ_CPU = 0,        /* Flash accesses use 1 CPU clocks. Use for up to 20 MHz CPU clock*/
    FLASHTIM_30MHZ_CPU = 1,     /* Flash accesses use 2 CPU clocks. Use for up to 30 MHz CPU clock*/
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