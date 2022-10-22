/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for STM32F030K6 microcontroller */
#ifndef STM32F030K6_H
#define STM32F030K6_H

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __CM0_REV 0x0000
#define __NVIC_PRIO_BITS 2
#define __Vendor_SysTickConfig 0

typedef enum {
  Reset_IRQn = -15,
  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  SVCall_IRQn = -5,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,
  WWDG_IRQn = 0,                 /*!< Window WatchDog Interrupt */
  RTC_IRQn = 2,                  /*!< RTC through EXTI Line Interrupt */
  FLASH_IRQn = 3,                /*!< FLASH Interrupt */
  RCC_IRQn = 4,                  /*!< RCC Interrupt */
  EXTI0_1_IRQn = 5,              /*!< EXTI Line 0 and 1 Interrupts */
  EXTI2_3_IRQn = 6,              /*!< EXTI Line 2 and 3 Interrupts */
  EXTI4_15_IRQn = 7,             /*!< EXTI Line 4 to 15 Interrupts */
  DMA1_Channel1_IRQn = 9,        /*!< DMA1 Channel 1 Interrupt */
  DMA1_Channel2_3_IRQn = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts */
  DMA1_Channel4_5_IRQn = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupts */
  ADC1_IRQn = 12,                /*!< ADC1 Interrupt */
  TIM1_BRK_UP_TRG_COM_IRQn = 13, /*!< TIM1 Break, Update, Trigger and Commutation Interrupts  */
  TIM1_CC_IRQn = 14,             /*!< TIM1 Capture Compare Interrupt */
  TIM3_IRQn = 16,                /*!< TIM3 Interrupt */
  TIM14_IRQn = 19,               /*!< TIM14 Interrupt */
  TIM15_IRQn = 20,               /*!< TIM15 Interrupt */
  TIM16_IRQn = 21,               /*!< TIM16 Interrupt */
  TIM17_IRQn = 22,               /*!< TIM17 Interrupt */
  I2C1_IRQn = 23,                /*!< I2C1 Interrupt */
  I2C2_IRQn = 24,                /*!< I2C2 Interrupt */
  SPI1_IRQn = 25,                /*!< SPI1 Interrupt */
  SPI2_IRQn = 26,                /*!< SPI2 Interrupt */
  USART1_IRQn = 27,              /*!< USART1 Interrupt */
  USART2_IRQn = 28               /*!< USART2 Interrupt */
} IRQn_Type;

#include <CMSIS/core_cm0.h>

#define GPIOA_BASE (0x48000000UL) /*!< GPIOA base address */
#define GPIOB_BASE (0x48000400UL) /*!< GPIOB base address */
#define GPIOC_BASE (0x48000800UL) /*!< GPIOC base address */
#define GPIOD_BASE (0x48000C00UL) /*!< GPIOD base address */
#define GPIOF_BASE (0x48001400UL) /*!< GPIOF base address */
#define CRC_BASE (0x40023000)     /*!< CRC base address */
#define FLASH_BASE (0x40022000)   /*!< Flash base address */
#define RCC_BASE (0x40021000)     /*!< RCC base address */
#define DMA_BASE (0x40020000)     /*!< DMA base address */
#define DBGMCU_BASE (0x40015C00)  /*!< DBGMCU base address */
#define SYSCFG_BASE (0x40010000)  /*!< SYSCFG base address */

#define GPIOA ((GPIO_Type *)GPIOA_BASE) /*!< GPIOA mapping */
#define GPIOB ((GPIO_Type *)GPIOB_BASE) /*!< GPIOB mapping */
#define GPIOC ((GPIO_Type *)GPIOC_BASE) /*!< GPIOC mapping */
#define GPIOD ((GPIO_Type *)GPIOD_BASE) /*!< GPIOD mapping */
#define GPIOF ((GPIO_Type *)GPIOF_BASE) /*!< GPIOF mapping */
#define RCC ((RCC_Type *)RCC_BASE)      /*!< RCC mapping */

#include <st/STM32F0/STM32F0_gpio.h>
#include <st/STM32F0/STM32F0_rcc.h>

#ifdef __cplusplus
}
#endif

#endif
