/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file System Configuration peripheral definitions */
#ifndef SYSCFG_H
#define SYSCFG_H

typedef volatile struct {
  uint32_t PROC0_NMI_MASK;         /*!< Processor core 0 NMI source mask */
  uint32_t PROC1_NMI_MASK;         /*!< Processor core 1 NMI source mask */
  uint32_t PROC_CONFIG;            /*!< Configuration for processors */
  uint32_t PROC_IN_SYNC_BYPASS;    /*!< bypass GPIO input synchroniser and SIO */
  uint32_t PROC_IN_SYNC_BYPASS_HI; /*!< bypass QSPI GPIO input synchroniser and SIO */
  uint32_t DBGFORCE;               /*!< Control the SWD debug port of either processor */
  uint32_t MEMPOWERDOWN;           /*!< Control power downs to memories */
} SYSCFG_Type;

#endif