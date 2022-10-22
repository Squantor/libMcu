/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file GPIO bank 0 peripheral definitions */
#ifndef IO_BANK0_H
#define IO_BANK0_H

typedef volatile struct {
  struct {
    const uint32_t STATUS; /*!< GPIO status */
    uint32_t CTRL;         /*!< GPIO control */
  } GPIO[30];
  uint32_t INTR[4];              /*!< Raw interrupts */
  uint32_t PROC0_INTE[4];        /*!< Interrupt Enable for proc0 */
  uint32_t PROC0_INTF[4];        /*!< Interrupt Force for proc0 */
  const uint32_t PROC0_INTS[4];  /*!< Interrupt status after masking & forcing for proc0 */
  uint32_t PROC1_INTE[4];        /*!< Interrupt Enable for proc1 */
  uint32_t PROC1_INTF[4];        /*!< Interrupt Force for proc1 */
  const uint32_t PROC1_INTS[4];  /*!< Interrupt status after masking & forcing for proc1 */
  uint32_t DORMANT_WAKE_INTE[4]; /*!< Interrupt Enable for dormant_wake */
  uint32_t DORMANT_WAKE_INTF[4]; /*!< Interrupt Force for dormant_wake */
  uint32_t DORMANT_WAKE_INTS[4]; /*!< Interrupt status after masking & forcing for dormant_wake */
} IO_BANK0_Type;

#endif