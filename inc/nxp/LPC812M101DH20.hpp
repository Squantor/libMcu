/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the LPC812M101DH20 microcontroller definitions */
#ifndef LPC812M101DH20_HPP
#define LPC812M101DH20_HPP

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
#define WWDT_BASE (0x40000000UL)
#define MRT_BASE (0x40004000UL)
#define WKT_BASE (0x40008000UL)
#define SWM_BASE (0x4000C000UL)
#define PMU_BASE (0x40020000UL)
#define CMP_BASE (0x40024000UL)

#define FMC_BASE (0x40040000UL)
#define IOCON_BASE (0x40044000UL)
#define SYSCTL_BASE (0x40048000UL)
#define I2C0_BASE (0x40050000UL)
#define SPI0_BASE (0x40058000UL)
#define SPI1_BASE (0x4005C000UL)
#define USART0_BASE (0x40064000UL)
#define USART1_BASE (0x40068000UL)
#define USART2_BASE (0x4006C000UL)

/* AHB peripherals */
#define CRC_BASE (0x50000000UL)
#define SCT0_BASE (0x50004000UL)

#define GPIO_BASE (0xA0000000UL)
#define PIN_INT_BASE (0xA0004000UL)

// Define peripherals
#define WWDT ((WWDT_Type *)WWDT_BASE)
#define SPI0 ((SPI_Type *)SPI0_BASE)
#define SPI1 ((SPI_Type *)SPI1_BASE)
#define USART0 ((USART_Type *)USART0_BASE)
#define USART1 ((USART_Type *)USART1_BASE)
#define USART2 ((USART_Type *)USART2_BASE)
#define WKT ((WKT_Type *)WKT_BASE)
#define PMU ((PMU_Type *)PMU_BASE)
#define CRC ((CRC_Type *)CRC_BASE)
#define SCT0 ((SCT_Type *)SCT0_BASE)
#define GPIO ((GPIO_Type *)GPIO_BASE)
#define PININT ((PIN_INT_Type *)PIN_INT_BASE)
#define IOCON ((IOCON_Type *)IOCON_BASE)
#define SWM ((SWM_Type *)SWM_BASE)
#define SYSCON ((SYSCON_Type *)SYSCTL_BASE)
#define CMP ((CMP_Type *)CMP_BASE)
#define FMC ((FMC_Type *)FMC_BASE)
#define MRT ((MRT_Type *)MRT_BASE)
#define I2C0 ((I2C_Type *)I2C0_BASE)

// package specific structures
typedef enum PINx {
  IOCON_PIO0_0 = 0x11,
  IOCON_PIO0_1 = 0x0B,
  IOCON_PIO0_2 = 0x06,
  IOCON_PIO0_3 = 0x05,
  IOCON_PIO0_4 = 0x04,
  IOCON_PIO0_5 = 0x03,
  IOCON_PIO0_6 = 0x10,
  IOCON_PIO0_7 = 0x0F,
  IOCON_PIO0_8 = 0x0E,
  IOCON_PIO0_9 = 0x0D,
  IOCON_PIO0_10 = 0x08,
  IOCON_PIO0_11 = 0x07,
  IOCON_PIO0_12 = 0x02,
  IOCON_PIO0_13 = 0x01,
  IOCON_PIO0_14 = 0x12,
  IOCON_PIO0_15 = 0x0A,
  IOCON_PIO0_16 = 0x09,
  IOCON_PIO0_17 = 0x00,
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
// #include "nxp/LPC8XX/LPC8XX_clock.h"
#include "nxp/LPC8XX/LPC81X_swm.h"
#include "nxp/LPC8XX/LPC81X_gpio.h"
#include "nxp/LPC8XX/LPC81X_iocon.h"
#include "nxp/LPC8XX/LPC8XX_wwdt.h"
#include "nxp/LPC8XX/LPC8XX_wkt.h"
#include "nxp/LPC8XX/LPC81X_sct.h"
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

namespace peripherals {

// Define peripheral addresses on APB0 bus
// rename these when full c++ functionality is finished, remove _cpp postfix
constexpr static inline uint32_t WWDT_cpp = 0x4000'0000u;   /**< Windowed watchdog base address */
constexpr static inline uint32_t MRT_cpp = 0x4000'4000u;    /**< multi rate timer base address */
constexpr static inline uint32_t WKT_cpp = 0x4000'8000u;    /**< wakeup timer base address */
constexpr static inline uint32_t SWM_cpp = 0x4000'C000u;    /**< Switch matrix base address */
constexpr static inline uint32_t PMU_cpp = 0x4002'0000u;    /**< Power management unit base address */
constexpr static inline uint32_t ACMP_cpp = 0x4002'4000u;   /**< Analog comparator base address */
constexpr static inline uint32_t FMC_cpp = 0x4004'0000u;    /**< Flash memory controller base address */
constexpr static inline uint32_t IOCON_cpp = 0x4004'4000u;  /**< I/O control base address */
constexpr static inline uint32_t SYSCTL_cpp = 0x4004'8000u; /**< System control base address */
constexpr static inline uint32_t I2C0_cpp = 0x4005'0000u;   /**< I2C 0 base address */
constexpr static inline uint32_t SPI0_cpp = 0x4005'8000u;   /**< SPI 0 base address */
constexpr static inline uint32_t SPI1_cpp = 0x4005'C000u;   /**< SPI 1 base address */
constexpr static inline uint32_t USART0_cpp = 0x4006'4000u; /**< USART 0 base address */
constexpr static inline uint32_t USART1_cpp = 0x4006'8000u; /**< USART 1 base address */
constexpr static inline uint32_t USART2_cpp = 0x4006'C000u; /**< USART 2 base address */

/* AHB peripherals */
constexpr static inline uint32_t CRC_cpp = 0x5000'0000u;  /**< CRC calculator base address */
constexpr static inline uint32_t SCT0_cpp = 0x5000'4000u; /**< State configurable timer 0 base address */

/* Direct connected peripherals */
constexpr static inline uint32_t GPIO_cpp = 0xA000'0000u;    /**< General Purpose I/O base address */
constexpr static inline uint32_t PIN_INT_cpp = 0xA000'4000u; /**< Pin interrupt base address */

}  // namespace peripherals

// includes that define the registers namespace go here.
#include "nxp/LPC8XX.hpp/LPC81X_iocon_regs.hpp"
#include "nxp/LPC8XX.hpp/LPC81X_swm_regs.hpp"
#include "nxp/LPC8XX.hpp/LPC81X_gpio_regs.hpp"
#include "nxp/LPC8XX.hpp/LPC81X_spi_regs.hpp"

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here
#include "nxp/LPC8XX.hpp/LPC812M101DH20_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "nxp/LPC8XX.hpp/LPC81X_iocon.hpp"
#include "nxp/LPC8XX.hpp/LPC81X_swm.hpp"
#include "nxp/LPC8XX.hpp/LPC81X_gpio.hpp"
#include "nxp/LPC8XX.hpp/LPC81X_spi.hpp"

#endif