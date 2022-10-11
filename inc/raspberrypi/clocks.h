/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file Clocks peripheral definitions */
#ifndef CLOCKS_H
#define CLOCKS_H

typedef volatile struct {
  uint32_t CLK_GPOUT0_CTRL;     /*!<  */
  uint32_t CLK_GPOUT0_DIV;      /*!<  */
  uint32_t CLK_GPOUT0_SELECTED; /*!<  */
  uint32_t CLK_GPOUT1_CTRL;     /*!<  */
  uint32_t CLK_GPOUT1_DIV;      /*!<  */
  uint32_t CLK_GPOUT1_SELECTED; /*!<  */
  uint32_t CLK_GPOUT2_CTRL;     /*!<  */
  uint32_t CLK_GPOUT2_DIV;      /*!<  */
  uint32_t CLK_GPOUT2_SELECTED; /*!<  */
  uint32_t CLK_GPOUT3_CTRL;     /*!<  */
  uint32_t CLK_GPOUT3_DIV;      /*!<  */
  uint32_t CLK_GPOUT3_SELECTED; /*!<  */
  uint32_t CLK_REF_CTRL;        /*!<  */
  uint32_t CLK_REF_DIV;         /*!<  */
  uint32_t CLK_REF_SELECTED;    /*!<  */
  uint32_t CLK_SYS_CTRL;        /*!<  */
  uint32_t CLK_SYS_DIV;         /*!<  */
  uint32_t CLK_SYS_SELECTED;    /*!<  */

} CLOCKS_Type;

#endif