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

#define XOSC_CTRL_EN (0xfab << 12)                 /**< Enable crystal oscillator */
#define XOSC_CTRL_DIS (0xd1e << 12)                /**< Disable crystal oscillator */
#define XOSC_CTRL_FREQ_RANGE_1_15MHZ (0xaa0)       /**< crystal oscillator range 1 to 15MHz */
#define XOSC_STATUS_FREQ_RANGE (0x03 << 0)         /**< Frequency range */
#define XOSC_STATUS_ENABLED_MASK (1 << 12)         /**< Oscillator is enabled */
#define XOSC_STATUS_BADWRITE_MASK (1 << 24)        /**< Invalid value written to ENABLE, RANGE, DORMANT */
#define XOSC_STATUS_STABLE_MASK (1 << 31)          /**< Oscillator is stable flag */
#define XOSC_STARTUP_DELAY(count) (count & 0x3FFF) /**< Oscillator startup delay*/

/**
 * @brief Starts the crystal oscillator
 *
 * Starts the crystal oscllator with the delay value with a given timeout value
 *
 * @param delay       delay value to set in XOSC
 * @param timeout     how many times to check if the status set
 * @return uint32_t   returns zero when timed out not zero of crystal oscillator is enabled
 */
static inline uint32_t xoscStart(uint32_t delay, uint32_t timeout) {
  uint32_t count = timeout;
  XOSC->CTRL = XOSC_CTRL_FREQ_RANGE_1_15MHZ;
  XOSC->STARTUP = XOSC_STARTUP_DELAY(delay);
  XOSC_SET->CTRL = XOSC_CTRL_EN;
  while (0 == (XOSC->STATUS & XOSC_STATUS_ENABLED_MASK) && (count > 0)) count--;
  return count;
}

#endif