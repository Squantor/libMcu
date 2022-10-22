/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file Clocks peripheral definitions */
#ifndef CLOCKS_H
#define CLOCKS_H

typedef volatile struct {
  uint32_t CLK_GPOUT0_CTRL;            /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t CLK_GPOUT0_DIV;             /*!< Clock divisor, can be changed on-the-fly */
  const uint32_t CLK_GPOUT0_SELECTED;  /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_GPOUT1_CTRL;            /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t CLK_GPOUT1_DIV;             /*!< Clock divisor, can be changed on-the-fly */
  const uint32_t CLK_GPOUT1_SELECTED;  /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_GPOUT2_CTRL;            /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t CLK_GPOUT2_DIV;             /*!< Clock divisor, can be changed on-the-fly */
  const uint32_t CLK_GPOUT2_SELECTED;  /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_GPOUT3_CTRL;            /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t CLK_GPOUT3_DIV;             /*!< Clock divisor, can be changed on-the-fly */
  const uint32_t CLK_GPOUT3_SELECTED;  /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_REF_CTRL;               /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t CLK_REF_DIV;                /*!< Clock divisor, can be changed on-the-fly */
  const uint32_t CLK_REF_SELECTED;     /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_SYS_CTRL;               /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t CLK_SYS_DIV;                /*!< Clock divisor, can be changed on-the-fly */
  const uint32_t CLK_SYS_SELECTED;     /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_PERI_CTRL;              /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t RESERVED[1];                /*!< Not documented, weird that we have this hole here*/
  const uint32_t CLK_PERI_SELECTED;    /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_USB_CTRL;               /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t CLK_USB_DIV;                /*!< Clock divisor, can be changed on-the-fly */
  const uint32_t CLK_USB_SELECTED;     /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_ADC_CTRL;               /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t CLK_ADC_DIV;                /*!< Clock divisor, can be changed on-the-fly */
  const uint32_t CLK_ADC_SELECTED;     /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_RTC_CTRL;               /*!< Clock control, can be changed on-the-fly (except for auxsrc) */
  uint32_t CLK_RTC_DIV;                /*!< Clock divisor, can be changed on-the-fly */
  const uint32_t CLK_RTC_SELECTED;     /*!< Indicates which SRC is currently selected by the glitchless mux (one-hot). */
  uint32_t CLK_SYS_RESUS_CTRL;         /*!<  */
  const uint32_t CLK_SYS_RESUS_STATUS; /*!<  */
  uint32_t FC0_REF_KHZ;                /*!<  */
  uint32_t FC0_MIN_KHZ;                /*!<  */
  uint32_t FC0_MAX_KHZ;                /*!<  */
  uint32_t FC0_DELAY;                  /*!<  */
  uint32_t FC0_INTERVAL;               /*!<  */
  uint32_t FC0_SRC;                    /*!<  */
  const uint32_t FC0_STATUS;           /*!< Frequency counter status */
  const uint32_t FC0_RESULT;           /*!< Result of frequency measurement, only valid when status_done=1 */
  uint32_t WAKE_EN0;                   /*!< enable clock in wake mode */
  uint32_t WAKE_EN1;                   /*!< enable clock in wake mode */
  uint32_t SLEEP_EN0;                  /*!< enable clock in sleep mode */
  uint32_t SLEEP_EN1;                  /*!< enable clock in sleep mode */
  const uint32_t ENABLED0;             /*!< indicates the state of the clock enable */
  const uint32_t ENABLED1;             /*!< indicates the state of the clock enable */
  const uint32_t INTR;                 /*!< Raw Interrupts */
  uint32_t INTE;                       /*!< Interrupt Enable */
  uint32_t INTF;                       /*!< Interrupt Force */
  const uint32_t INTS;                 /*!< Interrupt status after masking & forcing */
} CLOCKS_Type;

#endif