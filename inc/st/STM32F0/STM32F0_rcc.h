/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
STM32F0 series RCC registers, defines and functions.
*/
#ifndef STM32F0_RCC_H
#define STM32F0_RCC_H

/**
 * @brief Reset and Clock Control
 */
typedef volatile struct {
  uint32_t CR;       /*!< RCC clock control register*/
  uint32_t CFGR;     /*!< RCC clock configuration register*/
  uint32_t CIR;      /*!< RCC clock interrupt register */
  uint32_t APB2RSTR; /*!< RCC APB2 peripheral reset register */
  uint32_t APB1RSTR; /*!< RCC APB1 peripheral reset register */
  uint32_t AHBENR;   /*!< RCC AHB peripheral clock register */
  uint32_t APB2ENR;  /*!< RCC APB2 peripheral clock enable register */
  uint32_t APB1ENR;  /*!< RCC APB1 peripheral clock enable register */
  uint32_t BDCR;     /*!< RCC Backup domain control register */
  uint32_t CSR;      /*!< RCC clock control & status register */
  uint32_t AHBRSTR;  /*!< RCC AHB peripheral reset register */
  uint32_t CFGR2;    /*!< RCC clock configuration register 2 */
  uint32_t CFGR3;    /*!< RCC clock configuration register 3 */
  uint32_t CR2;      /*!< RCC clock control register 2 */
} RCC_Type;

/**
 * @brief AHB control bits
 */
typedef enum {
  AHB_CLK_None = 0,         /*!< no clock to configure */
  AHB_CLK_DMA = (1 << 0),   /*!< DMA controller AHB clock enable */
  AHB_CLK_SRAM = (1 << 2),  /*!< SRAM AHB clock enable */
  AHB_CLK_FLITF = (1 << 4), /*!< FLITF AHB clock enable */
  AHB_CLK_CRC = (1 << 6),   /*!< CRC AHB clock enable */
  AHB_CLK_IOPA = (1 << 17), /*!< GPIOA AHB clock enable */
  AHB_CLK_IOPB = (1 << 18), /*!< GPIOB AHB clock enable */
  AHB_CLK_IOPC = (1 << 19), /*!< GPIOC AHB clock enable */
  AHB_CLK_IOPD = (1 << 20), /*!< GPIOD AHB clock enable */
  AHB_CLK_IOPF = (1 << 22), /*!< GPIOF AHB clock enable */
} RCC_CLKCTRL_AHB_Type;

/**
 * @brief APB1 control bits
 */
typedef enum {
  APB1_CLK_None = 0,        /*!< no clock to configure */
  APB1_CLK_TIM3 = (1 << 1), /*!< Timer 3 APB1 clock enable */
} RCC_CLKCTRL_APB1_Type;

/**
 * @brief APB2 control bits
 */
typedef enum {
  APB2_CLK_None = 0,          /*!< no clock to configure */
  APB2_CLK_SYSCFG = (1 << 1), /*!< SYSCFG APB2 clock enable */
} RCC_CLKCTRL_APB2_Type;

/**
 * @brief   Enables clocks to various peripherals
 * @param   peripheral  base address of RCC peripheral
 * @param   APB1setting APB1 settings, see RCC_CLKCTRL_APB1_Type
 * @param   APB2setting APB2 settings, see RCC_CLKCTRL_APB2_Type
 * @param   AHBsetting AHB settings, see RCC_CLKCTRL_AHB_Type
 * @return  Nothing
 */
static inline void rccEnableClocks(RCC_Type *peripheral, uint32_t APB1setting,
                                   uint32_t APB2setting, uint32_t AHBsetting) {
  peripheral->AHBENR = AHBsetting | peripheral->AHBENR;
  peripheral->APB1ENR = APB1setting | peripheral->APB1ENR;
  peripheral->APB2ENR = APB2setting | peripheral->APB2ENR;
}

/**
 * @brief   Disables clocks to various peripherals
 * @param   peripheral  base address of RCC peripheral
 * @param   APB1setting APB1 settings, see RCC_CLKCTRL_APB1_Type
 * @param   APB2setting APB2 settings, see RCC_CLKCTRL_APB2_Type
 * @param   AHBsetting AHB settings, see RCC_CLKCTRL_AHB_Type
 * @return  Nothing
 */
static inline void rccDisableClocks(RCC_Type *peripheral, uint32_t APB1setting,
                                    uint32_t APB2setting, uint32_t AHBsetting) {
  peripheral->AHBENR = ~AHBsetting & peripheral->AHBENR;
  peripheral->APB1ENR = ~APB1setting & peripheral->APB1ENR;
  peripheral->APB2ENR = ~APB2setting & peripheral->APB2ENR;
}

#endif