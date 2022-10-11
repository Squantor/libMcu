/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file Sysinfo peripheral definitions */
#ifndef SYSINFO_H
#define SYSINFO_H

typedef volatile struct {
  const uint32_t CHIP_ID;       /*!< JEDEC JEP-106 compliant chip identifier */
  const uint32_t PLATFORM;      /*!< Platform register */
  const uint32_t GITREF_RP2040; /*!< Git hash of the chip source */
} SYSINFO_Type;

#endif