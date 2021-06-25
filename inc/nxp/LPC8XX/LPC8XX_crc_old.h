/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series common cyclic redudancy check registers, definitions and 
functions.
*/
#ifndef LPC8XX_CRC_OLD_H
#define LPC8XX_CRC_OLD_H

static inline void CrcInit(void)
{
    ClockEnablePeriphClock(SYSCTL_CLOCK_CRC);
}

static inline void CrcDeinit(void)
{
    ClockDisablePeriphClock(SYSCTL_CLOCK_CRC);
}

static inline void CrcSetPoly(CRC_POLY_T poly, uint32_t flags)
{
    LPC_CRC->MODE = (uint32_t) poly | flags;
}

static inline void CrcUseCRC16(void)
{
    LPC_CRC->MODE = MODE_CFG_CRC16;
    LPC_CRC->SEED = CRC_SEED_CRC16;
}

static inline void CrcUseCRC32(void)
{
    LPC_CRC->MODE = MODE_CFG_CRC32;
    LPC_CRC->SEED = CRC_SEED_CRC32;
}

static inline void CrcUseCCITT(void)
{
    LPC_CRC->MODE = MODE_CFG_CCITT;
    LPC_CRC->SEED = CRC_SEED_CCITT;
}

void CrcUseDefaultConfig(CRC_POLY_T poly);

static inline void CrcSetMode(uint32_t mode)
{
    LPC_CRC->MODE = mode;
}

static inline uint32_t CrcGetMode(void)
{
    return LPC_CRC->MODE;
}

static inline void CrcSetSeed(uint32_t seed)
{
    LPC_CRC->SEED = seed;
}

static inline uint32_t CrcGetSeed(void)
{
    return LPC_CRC->SEED;
}

static inline void CrcWrite8(uint8_t data)
{
    LPC_CRC->WRDATA8 = data;
}

static inline void CrcWrite16(uint16_t data)
{
    LPC_CRC->WRDATA16 = data;
}

static inline void CrcWrite32(uint32_t data)
{
    LPC_CRC->WRDATA32 = data;
}

static inline uint32_t CrcSum(void)
{
    return LPC_CRC->SUM;
}

static inline uint32_t CrcCRC8(const uint8_t *data, uint32_t bytes)
{
    CrcUseCCITT();
    while (bytes > 0) {
        CrcWrite8(*data);
        data++;
        bytes--;
    }
    return CrcSum();
}

static inline uint32_t CrcCRC16(const uint16_t *data, uint32_t hwords)
{
    CrcUseCRC16();
    while (hwords > 0) {
        CrcWrite16(*data);
        data++;
        hwords--;
    }
    return CrcSum();
}

static inline uint32_t CrcCRC32(const uint32_t *data, uint32_t words)
{
    CrcUseCRC32();
    while (words > 0) {
        CrcWrite32(*data);
        data++;
        words--;
    }
    return CrcSum();
}

#endif