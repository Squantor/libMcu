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
    const uint32_t STATUS; /**< GPIO status */
    uint32_t CTRL;         /**< GPIO control */
  } GPIO[30];
  uint32_t INTR[4];              /**< Raw interrupts */
  uint32_t PROC0_INTE[4];        /**< Interrupt Enable for proc0 */
  uint32_t PROC0_INTF[4];        /**< Interrupt Force for proc0 */
  const uint32_t PROC0_INTS[4];  /**< Interrupt status after masking & forcing for proc0 */
  uint32_t PROC1_INTE[4];        /**< Interrupt Enable for proc1 */
  uint32_t PROC1_INTF[4];        /**< Interrupt Force for proc1 */
  const uint32_t PROC1_INTS[4];  /**< Interrupt status after masking & forcing for proc1 */
  uint32_t DORMANT_WAKE_INTE[4]; /**< Interrupt Enable for dormant_wake */
  uint32_t DORMANT_WAKE_INTF[4]; /**< Interrupt Force for dormant_wake */
  uint32_t DORMANT_WAKE_INTS[4]; /**< Interrupt status after masking & forcing for dormant_wake */
} IO_BANK0_Type;

#define IO_BANK0_STATUS_RESERVED (0xFAF5CCFF)            /**< GPIO status reserved bits */
#define IO_BANK0_CTRL_RESERVED (0xCFFCCCE0)              /**< GPIO controlreserved bits */
#define IO_BANK0_INTR_RESERVED (0x00000000)              /**< Raw interrupts reserved bits */
#define IO_BANK0_PROC0_INTE_RESERVED (0x00000000)        /**< Interrupt Enable for proc0 reserved bits */
#define IO_BANK0_PROC0_INTF_RESERVED (0x00000000)        /**< Interrupt Force for proc0 reserved bits */
#define IO_BANK0_PROC0_INTS_RESERVED (0x00000000)        /**< Interrupt status for proc0 reserved bits */
#define IO_BANK0_PROC1_INTE_RESERVED (0x00000000)        /**< Interrupt Enable for proc1 reserved bits */
#define IO_BANK0_PROC1_INTF_RESERVED (0x00000000)        /**< Interrupt Force for proc1 reserved bits */
#define IO_BANK0_PROC1_INTS_RESERVED (0x00000000)        /**< Interrupt status for proc1 reserved bits */
#define IO_BANK0_DORMANT_WAKE_INTE_RESERVED (0x00000000) /**< Interrupt Enable for dormant_wake reserved bits */
#define IO_BANK0_DORMANT_WAKE_INTF_RESERVED (0x00000000) /**< Interrupt Force for dormant_wake reserved bits */
#define IO_BANK0_DORMANT_WAKE_INTS_RESERVED (0x00000000) /**< Interrupt status reserved bits */

#endif