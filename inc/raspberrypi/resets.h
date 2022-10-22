/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file Resets peripheral definitions */
#ifndef RESETS_H
#define RESETS_H

typedef volatile struct {
  uint32_t RESET;      /*!< Reset control. set means the peripheral in reset, unset means deasserted. */
  uint32_t WDSEL;      /*!< Watchdog select. If a bit is set, the watchdog will reset that peripheral */
  uint32_t RESET_DONE; /*!< Reset done. If bit is set, reset is done and peripheral can be accessed */
} RESETS_Type;

#endif