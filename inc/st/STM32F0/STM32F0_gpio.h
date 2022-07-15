/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
STM32F0 series GPIO registers, defines and functions.
*/
#ifndef STM32F0_GPIO_H
#define STM32F0_GPIO_H

typedef volatile struct {
  uint32_t MODER;     /*!< GPIO port mode register */
  uint16_t OTYPER;    /*!< GPIO port output type register */
  uint16_t RESERVED0; /*!< Reserved */
  uint32_t OSPEEDR;   /*!< GPIO port output speed register */
  uint32_t PUPDR;     /*!< GPIO port pull-up/pull-down register */
  uint16_t IDR;       /*!< GPIO port input data register */
  uint16_t RESERVED1; /*!< Reserved */
  uint16_t ODR;       /*!< GPIO port output data register */
  uint16_t RESERVED2; /*!< Reserved */
  uint32_t BSRR;      /*!< GPIO port bit set/reset registerBSRR */
  uint32_t LCKR;      /*!< GPIO port configuration lock register */
  uint32_t AFR[2];    /*!< GPIO alternate function low register */
  uint16_t BRR;       /*!< GPIO bit reset register */
  uint16_t RESERVED3; /*!< Reserved */
} GPIO_Type;

#endif