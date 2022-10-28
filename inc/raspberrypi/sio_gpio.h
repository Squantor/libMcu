/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file Single-Cyle I/O gpio function definitions */
#ifndef SIO_GPIO_H
#define SIO_GPIO_H

/**
 * @brief Clear output enable pin
 *
 * @param peripheral  SIO peripheral
 * @param setting     gpio bits to clear
 */
static inline void sioGpioOeClr(SIO_Type* const peripheral, uint32_t setting) {
  peripheral->GPIO_OE_CLR = setting;
}

/**
 * @brief Set output enable pin
 *
 * @param peripheral  SIO peripheral
 * @param setting     gpio bits to set
 */
static inline void sioGpioOeSet(SIO_Type* const peripheral, uint32_t setting) {
  peripheral->GPIO_OE_SET = setting;
}

/**
 * @brief Configure output pins in one go
 *
 * @param peripheral  SIO peripheral
 * @param setting     set all the gpio pins in one go
 */
static inline void sioGpioOut(SIO_Type* const peripheral, uint32_t setting) {
  peripheral->GPIO_OUT = setting;
}

/**
 * @brief set output pins with mask
 *
 * @param peripheral  SIO peripheral
 * @param mask        mask of pins to set
 */
static inline void sioGpioOutSet(SIO_Type* const peripheral, uint32_t mask) {
  peripheral->GPIO_OUT_SET = mask;
}

/**
 * @brief clear output pins with mask
 *
 * @param peripheral  SIO peripheral
 * @param mask        mask of pins to clear
 */
static inline void sioGpioOutClr(SIO_Type* const peripheral, uint32_t mask) {
  peripheral->GPIO_OUT_CLR = mask;
}

/**
 * @brief toggle output pins with mask
 *
 * @param peripheral  SIO peripheral
 * @param mask        mask of pins to toggle
 */
static inline void sioGpioOutXor(SIO_Type* const peripheral, uint32_t mask) {
  peripheral->GPIO_OUT_XOR = mask;
}

#endif