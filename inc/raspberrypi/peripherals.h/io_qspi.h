/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file QSPI GPIO peripheral definitions */
#ifndef IO_QSPI_H
#define IO_QSPI_H

typedef volatile struct {
} IO_QSPI_Type;

/**
 * @brief bank qspi gpios
 *
 */
typedef enum {
  BANK_QSPI_SCK = (0), /**< bank QSPI, pin SCK */
  BANK_QSPI_CS = (1),  /**< bank QSPI, pin CS */
  BANK_QSPI_SD0 = (2), /**< bank QSPI, pin SD0 */
  BANK_QSPI_SD1 = (3), /**< bank QSPI, pin SD1 */
  BANK_QSPI_SD2 = (4), /**< bank QSPI, pin SD2 */
  BANK_QSPI_SD3 = (5), /**< bank QSPI, pin SD3 */
} BANK_QSPI_Enum;

#endif