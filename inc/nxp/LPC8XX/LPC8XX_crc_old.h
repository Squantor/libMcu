/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC800 series common cyclic redudancy check registers, definitions and
functions.
*/
#ifndef LPC8XX_CRC_OLD_H
#define LPC8XX_CRC_OLD_H

static inline void CrcSetPoly(CRC_POLY_T poly, uint32_t flags) {
  CRC->MODE = (uint32_t)poly | flags;
}

static inline void CrcUseCRC16(void) {
  CRC->MODE = MODE_CFG_CRC16;
  CRC->SEED = CRC_SEED_CRC16;
}

static inline void CrcUseCRC32(void) {
  CRC->MODE = MODE_CFG_CRC32;
  CRC->SEED = CRC_SEED_CRC32;
}

static inline void CrcUseCCITT(void) {
  CRC->MODE = MODE_CFG_CCITT;
  CRC->SEED = CRC_SEED_CCITT;
}

void CrcUseDefaultConfig(CRC_POLY_T poly);

static inline void CrcSetMode(uint32_t mode) {
  CRC->MODE = mode;
}

static inline uint32_t CrcGetMode(void) {
  return CRC->MODE;
}

static inline void CrcSetSeed(uint32_t seed) {
  CRC->SEED = seed;
}

static inline uint32_t CrcGetSeed(void) {
  return CRC->SEED;
}

static inline void CrcWrite8(uint8_t data) {
  CRC->WRDATA8 = data;
}

static inline void CrcWrite16(uint16_t data) {
  CRC->WRDATA16 = data;
}

static inline void CrcWrite32(uint32_t data) {
  CRC->WRDATA32 = data;
}

static inline uint32_t CrcSum(void) {
  return CRC->SUM;
}

static inline uint32_t CrcCRC8(const uint8_t *data, uint32_t bytes) {
  CrcUseCCITT();
  while (bytes > 0) {
    CrcWrite8(*data);
    data++;
    bytes--;
  }
  return CrcSum();
}

static inline uint32_t CrcCRC16(const uint16_t *data, uint32_t hwords) {
  CrcUseCRC16();
  while (hwords > 0) {
    CrcWrite16(*data);
    data++;
    hwords--;
  }
  return CrcSum();
}

static inline uint32_t CrcCRC32(const uint32_t *data, uint32_t words) {
  CrcUseCRC32();
  while (words > 0) {
    CrcWrite32(*data);
    data++;
    words--;
  }
  return CrcSum();
}

#endif