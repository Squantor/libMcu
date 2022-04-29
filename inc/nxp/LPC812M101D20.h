/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the LPC812M101D20 microcontroller definitions */
#ifndef LPC812M101D20_H
#define LPC812M101D20_H

/*
Most information here derived/copied over from the LPCopen libraries.
*/

#ifdef __cplusplus
extern "C" {
#endif

#warning "Microcontroller LPC812M101D20 support is WIP"

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
  Reserved2_IRQn = 7,
  I2C0_IRQn = 8,
  SCT_IRQn = 9,
  MRT_IRQn = 10,
  CMP_IRQn = 11,
  WDT_IRQn = 12,
  BOD_IRQn = 13,
  Reserved3_IRQn = 14,
  WKT_IRQn = 15,
  Reserved4_IRQn = 16,
  Reserved5_IRQn = 17,
  Reserved6_IRQn = 18,
  Reserved7_IRQn = 19,
  Reserved8_IRQn = 20,
  Reserved9_IRQn = 21,
  Reserved10_IRQn = 22,
  Reserved11_IRQn = 23,
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

// Define peripheral addresses on APB0 bus
#define LPC_WWDT_BASE (0x40000000UL)
#define LPC_MRT_BASE (0x40004000UL)
#define LPC_WKT_BASE (0x40008000UL)
#define LPC_SWM_BASE (0x4000C000UL)
#define LPC_PMU_BASE (0x40020000UL)
#define LPC_CMP_BASE (0x40024000UL)

#define LPC_FMC_BASE (0x40040000UL)
#define LPC_IOCON_BASE (0x40044000UL)
#define LPC_SYSCTL_BASE (0x40048000UL)
#define LPC_I2C0_BASE (0x40050000UL)
#define LPC_SPI0_BASE (0x40058000UL)
#define LPC_SPI1_BASE (0x4005C000UL)
#define LPC_USART0_BASE (0x40064000UL)
#define LPC_USART1_BASE (0x40068000UL)
#define LPC_USART2_BASE (0x4006C000UL)

/* AHB peripherals */
#define LPC_CRC_BASE (0x50000000UL)
#define LPC_SCT_BASE (0x50004000UL)

#define LPC_GPIO_PORT_BASE (0xA0000000UL)
#define LPC_PIN_INT_BASE (0xA0004000UL)

// Define peripherals
#define LPC_WWDT ((LPC_WWDT_T *)LPC_WWDT_BASE)
#define LPC_SPI0 ((LPC_SPI_T *)LPC_SPI0_BASE)
#define LPC_USART0 ((LPC_USART_T *)LPC_USART0_BASE)
#define LPC_USART1 ((LPC_USART_T *)LPC_USART1_BASE)
#define LPC_WKT ((LPC_WKT_T *)LPC_WKT_BASE)
#define LPC_PMU ((LPC_PMU_T *)LPC_PMU_BASE)
#define LPC_CRC ((LPC_CRC_T *)LPC_CRC_BASE)
#define LPC_SCT ((LPC_SCT_T *)LPC_SCT_BASE)
#define LPC_GPIO_PORT ((LPC_GPIO_T *)LPC_GPIO_PORT_BASE)
#define LPC_PININT ((LPC_PIN_INT_T *)LPC_PIN_INT_BASE)
#define LPC_IOCON ((LPC_IOCON_T *)LPC_IOCON_BASE)
#define LPC_SWM ((LPC_SWM_T *)LPC_SWM_BASE)
#define LPC_SYSCTL ((LPC_SYSCTL_T *)LPC_SYSCTL_BASE)
#define LPC_CMP ((LPC_CMP_T *)LPC_CMP_BASE)
#define LPC_FMC ((LPC_FMC_T *)LPC_FMC_BASE)
#define LPC_MRT ((LPC_MRT_T *)LPC_MRT_BASE)
#define LPC_I2C0 ((LPC_I2C_T *)LPC_I2C0_BASE)

// package specific structures
typedef enum PINx {
  IOCON_PIO0 = 0x11,
  IOCON_PIO1 = 0x0B,
  IOCON_PIO2 = 0x06,
  IOCON_PIO3 = 0x05,
  IOCON_PIO4 = 0x04,
  IOCON_PIO5 = 0x03,
  IOCON_PIO6 = 0x10,
  IOCON_PIO7 = 0x0F,
  IOCON_PIO8 = 0x0E,
  IOCON_PIO9 = 0x0D,
  IOCON_PIO10 = 0x08,
  IOCON_PIO11 = 0x07,
  IOCON_PIO12 = 0x02,
  IOCON_PIO13 = 0x01,
  IOCON_PIO14 = 0x12,
  IOCON_PIO15 = 0x0A,
  IOCON_PIO16 = 0x09,
  IOCON_PIO17 = 0x00,
} IOCON_PIN_Type;

/**
 * @brief Translation table from GPIO pin name to IOCON index
 *
 */
typedef enum {
  GPIO_PIO0_0 = 0,
  GPIO_PIO0_1 = 1,
  GPIO_PIO0_2 = 2,
  GPIO_PIO0_3 = 3,
  GPIO_PIO0_4 = 4,
  GPIO_PIO0_5 = 5,
  GPIO_PIO0_6 = 6,
  GPIO_PIO0_7 = 7,
  GPIO_PIO0_8 = 8,
  GPIO_PIO0_9 = 9,
  GPIO_PIO0_10 = 10,
  GPIO_PIO0_11 = 11,
  GPIO_PIO0_12 = 12,
  GPIO_PIO0_13 = 13,
  GPIO_PIO0_14 = 14,
  GPIO_PIO0_15 = 15,
  GPIO_PIO0_16 = 16,
  GPIO_PIO0_17 = 17,
} GPIO_PIN_Type;

// default configuration options, override with your own!
#include "nxp/LPC8XX/LPC81X_default.h"
// Peripheral definition includes, ordering matters
#include "nxp/LPC8XX/LPC81X_syscon.h"
#include "nxp/LPC8XX/LPC8XX_clock.h"
#include "nxp/LPC8XX/LPC81X_swm.h"
#include "nxp/LPC8XX/LPC81X_gpio.h"
#include "nxp/LPC8XX/LPC8XX_iocon.h"
#include "nxp/LPC8XX/LPC8XX_wwdt.h"
#include "nxp/LPC8XX/LPC8XX_wkt.h"
#include "nxp/LPC8XX/LPC8XX_sct.h"
#include "nxp/LPC8XX/LPC8XX_ROM.h"
#include "nxp/LPC8XX/LPC8XX_pmu.h"
#include "nxp/LPC8XX/LPC8XX_pinint.h"
#include "nxp/LPC8XX/LPC8XX_mrt.h"
#include "nxp/LPC8XX/LPC8XX_fmc.h"
#include "nxp/LPC8XX/LPC8XX_irc.h"
#include "nxp/LPC8XX/LPC8XX_crc.h"
#include "nxp/LPC8XX/LPC81X_acmp.h"
#include "nxp/LPC8XX/LPC81X_usart.h"
#include "nxp/LPC8XX/LPC8XX_spi.h"
#include "nxp/LPC8XX/LPC81X_i2c.h"

#ifdef __cplusplus
}
#endif

#endif