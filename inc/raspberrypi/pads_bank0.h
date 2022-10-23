/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file bank0 pads peripheral definitions */
#ifndef PADS_BANK0_H
#define PADS_BANK0_H

/**
 * @brief
 *
 */
typedef volatile struct {
  uint32_t VOLTAGE_SELECT; /**< Voltage select. Per bank control */
  uint32_t GPIO[30];       /**< Pad control register */
  uint32_t SWCLK;          /**< Pad control register */
  uint32_t SWD;            /**< Pad control register */
} PADS_BANK0_Type;

#endif