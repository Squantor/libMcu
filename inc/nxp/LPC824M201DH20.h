/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the LPC824M201DH20 microcontroller definitions */
#ifndef LPC824M201DH20_H
#define LPC824M201DH20_H

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV 0x0001
#define __MPU_PRESENT 0
#define __VTOR_PRESENT 1
#define __NVIC_PRIO_BITS 2
#define __Vendor_SysTickConfig 0

typedef enum {
  Reset_IRQn = -15,
  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  SVCall_IRQn = -5,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,

  SPI0_IRQn = 0,
  SPI1_IRQn = 1,
  Reserved0_IRQn = 2,
  UART0_IRQn = 3,
  UART1_IRQn = 4,
  UART2_IRQn = 5,
  Reserved1_IRQn = 6,
  I2C1_IRQn = 7,
  I2C0_IRQn = 8,
  I2C_IRQn = 8,
  SCT_IRQn = 9,
  MRT_IRQn = 10,
  CMP_IRQn = 11,
  WDT_IRQn = 12,
  BOD_IRQn = 13,
  FLASH_IRQn = 14,
  WKT_IRQn = 15,
  ADC_SEQA_IRQn = 16,
  ADC_SEQB_IRQn = 17,
  ADC_THCMP_IRQn = 18,
  ADC_OVR_IRQn = 19,
  DMA_IRQn = 20,
  I2C2_IRQn = 21,
  I2C3_IRQn = 22,
  Reserved2_IRQn = 23,
  PININT0_IRQn = 24,
  PININT1_IRQn = 25,
  PININT2_IRQn = 26,
  PININT3_IRQn = 27,
  PININT4_IRQn = 28,
  PININT5_IRQn = 29,
  PININT6_IRQn = 30,
  PININT7_IRQn = 31,
} IRQn_Type;

#include <CMSIS/core_cm0plus.h>

/* Base addresses */
#define FLASH_BASE (0x00000000UL)
#define RAM_BASE (0x10000000UL)
#define ROM_BASE (0x1FFF0000UL)
#define APB0_BASE (0x40000000UL)
#define AHB_BASE (0x50000000UL)

/* APB0 peripherals */
#define WWDT_BASE (0x40000000UL)
#define MRT_BASE (0x40004000UL)
#define WKT_BASE (0x40008000UL)
#define SWM_BASE (0x4000C000UL)
#define ADC_BASE (0x4001C000UL)
#define PMU_BASE (0x40020000UL)
#define CMP_BASE (0x40024000UL)
#define DMATIRGMUX_BASE (0x40028000UL)
#define INMUX_BASE (0x4002C000UL)
#define FMC_BASE (0x40040000UL)
#define IOCON_BASE (0x40044000UL)
#define SYSCON_BASE (0x40048000UL)
#define I2C0_BASE (0x40050000UL)
#define I2C1_BASE (0x40054000UL)
#define SPI0_BASE (0x40058000UL)
#define SPI1_BASE (0x4005C000UL)
#define USART0_BASE (0x40064000UL)
#define USART1_BASE (0x40068000UL)
#define USART2_BASE (0x4006C000UL)
#define I2C2_BASE (0x40070000UL)
#define I2C3_BASE (0x40074000UL)

/* AHB peripherals */
#define CRC_BASE (0x50000000UL)
#define SCT_BASE (0x50004000UL)
#define DMA_BASE (0x50008000UL)

#define GPIO_BASE (0xA0000000UL)
#define PIN_INT_BASE (0xA0004000UL)

#define WWDT ((WWDT_Type *)WWDT_BASE)
#define SPI0 ((SPI_Type *)SPI0_BASE)
#define SPI1 ((SPI_Type *)SPI1_BASE)
#define USART0 ((USART_Type *)USART0_BASE)
#define USART1 ((USART_Type *)USART1_BASE)
#define USART2 ((USART_Type *)USART2_BASE)
#define WKT ((WKT_Type *)WKT_BASE)
#define PMU ((PMU_Type *)PMU_BASE)
#define CRC ((CRC_Type *)CRC_BASE)
#define SCT ((SCT_Type *)SCT_BASE)
#define GPIO ((GPIO_Type *)GPIO_BASE)
#define PININT ((PIN_INT_Type *)PIN_INT_BASE)
#define IOCON ((IOCON_Type *)IOCON_BASE)
#define SWM ((SWM_Type *)SWM_BASE)
#define SYSCON ((SYSCON_Type *)SYSCON_BASE)
#define CMP ((CMP_Type *)CMP_BASE)
#define FMC ((FMC_Type *)FMC_BASE)
#define MRT ((MRT_Type *)MRT_BASE)
#define I2C0 ((I2C_Type *)I2C0_BASE)
#define ADC ((ADC_Type *)ADC_BASE)
#define I2C1 ((I2C_Type *)I2C1_BASE)
#define I2C2 ((I2C_Type *)I2C2_BASE)
#define I2C3 ((I2C_Type *)I2C3_BASE)
#define DMA ((DMA_Type *)DMA_BASE)
#define DMATRIGMUX ((DMATRIGMUX_Type *)DMATIRGMUX_BASE)
#define INMUX ((INMUX_Type *)INMUX_BASE)

/**
 * @brief Translation table from GPIO pin name to IOCON index
 *
 */
typedef enum PINx {
  IOCON_PIO0_0 = 0x11,
  IOCON_PIO0_1 = 0x0B,
  IOCON_PIO0_2 = 0x06,
  IOCON_PIO0_3 = 0x05,
  IOCON_PIO0_4 = 0x04,
  IOCON_PIO0_5 = 0x03,
  IOCON_PIO0_8 = 0x0E,
  IOCON_PIO0_9 = 0x0D,
  IOCON_PIO0_10 = 0x08,
  IOCON_PIO0_11 = 0x07,
  IOCON_PIO0_12 = 0x02,
  IOCON_PIO0_13 = 0x01,
  IOCON_PIO0_14 = 0x12,
  IOCON_PIO0_15 = 0x0A,
  IOCON_PIO0_17 = 0x00,
  IOCON_PIO0_23 = 0x19,
} IOCON_PIN_Type;

/**
 * @brief Translation table from GPIO name to GPIO pin number
 *
 * Used by pinint selection registers, it is device and package specific.
 */
typedef enum {
  GPIO_PIO0_0 = 0,
  GPIO_PIO0_1 = 1,
  GPIO_PIO0_2 = 2,
  GPIO_PIO0_3 = 3,
  GPIO_PIO0_4 = 4,
  GPIO_PIO0_5 = 5,
  GPIO_PIO0_8 = 8,
  GPIO_PIO0_9 = 9,
  GPIO_PIO0_10 = 10,
  GPIO_PIO0_11 = 11,
  GPIO_PIO0_12 = 12,
  GPIO_PIO0_13 = 13,
  GPIO_PIO0_14 = 14,
  GPIO_PIO0_15 = 15,
  GPIO_PIO0_17 = 17,
  GPIO_PIO0_23 = 23,
} GPIO_PIN_Type;

// default configuration options, override with your own!
#include "nxp/LPC8XX/LPC82X_default.h"
// Peripheral definition includes, ordering matters
#include "nxp/LPC8XX/LPC82X_syscon.h"
//#include "nxp/LPC8XX/LPC8XX_clock.h"
#include "nxp/LPC8XX/LPC82X_swm.h"
#include "nxp/LPC8XX/LPC82X_gpio.h"
#include "nxp/LPC8XX/LPC82X_iocon.h"
#include "nxp/LPC8XX/LPC8XX_wwdt.h"
#include "nxp/LPC8XX/LPC8XX_wkt.h"
#include "nxp/LPC8XX/LPC82X_sct.h"
#include "nxp/LPC8XX/LPC8XX_ROM.h"
#include "nxp/LPC8XX/LPC8XX_pmu.h"
#include "nxp/LPC8XX/LPC8XX_pinint.h"
#include "nxp/LPC8XX/LPC8XX_mrt.h"
#include "nxp/LPC8XX/LPC8XX_fmc.h"
#include "nxp/LPC8XX/LPC8XX_irc.h"
#include "nxp/LPC8XX/LPC8XX_crc.h"
#include "nxp/LPC8XX/LPC82X_acmp.h"
#include "nxp/LPC8XX/LPC82X_usart.h"
#include "nxp/LPC8XX/LPC8XX_spi.h"
#include "nxp/LPC8XX/LPC82X_i2c.h"
#include "nxp/LPC8XX/LPC82X_adc.h"
#include "nxp/LPC8XX/LPC82X_dma.h"
#include "nxp/LPC8XX/LPC82X_inmux.h"

#ifdef __cplusplus
}
#endif

#endif