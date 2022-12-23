/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file Crystal oscillator peripheral definitions */
#ifndef XOSC_H
#define XOSC_H

typedef volatile struct {
  uint32_t CTRL;    /**< Crystal Oscillator Control */
  uint32_t STATUS;  /**< Crystal Oscillator Status */
  uint32_t DORMANT; /**< Crystal Oscillator pause control */
  uint32_t STARTUP; /**< Controls the startup delay */
  uint32_t COUNT;   /**< A down counter running at the XOSC frequency which counts to
  zero and stops. */
} XOSC_Type;

#define XOSC_CTRL_EN (0xfab << 12)           /**< Enable crystal oscillator */
#define XOSC_CTRL_DIS (0xd1e << 12)          /**< Disable crystal oscillator */
#define XOSC_CTRL_FREQ_RANGE_1_15MHZ (0xaa0) /**< crystal oscillator range 1 to 15MHz */
#define XOSC_FREQ_RANGE (0x03 << 0)          /**< Frequency range */
#define XOSC_STATUS_ENABLED_MASK (1 << 12)   /**< Oscillator is enabled */
#define XOSC_STATUS_BADWRITE_MASK (1 << 24)  /**< Invalid value written to ENABLE, RANGE, DORMANT */
#define XOSC_STATUS_STABLE_MASK (1 << 31)    /**< Oscillator is stable flag */

#endif