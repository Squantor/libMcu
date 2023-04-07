/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the LPC845M301BD48 microcontroller definitions */
#ifndef LPC844M201BD64_HPP
#define LPC844M201BD64_HPP

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV 0x0001
#define __MPU_PRESENT 0
#define __VTOR_PRESENT 1
#define __NVIC_PRIO_BITS 2
#define __Vendor_SysTickConfig 0

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48 /**< Number of interrupts in the Vector table */

typedef enum {
  Reset_IRQn = -15,          /**< Reset entry  */
  NonMaskableInt_IRQn = -14, /**< Non Maskable Interrupt */
  HardFault_IRQn = -13,      /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn = -5,          /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn = -2,          /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn = -1,         /**< Cortex-M0 System Tick Interrupt */
  SPI0_IRQn = 0,             /**< SPI0 interrupt */
  SPI1_IRQn = 1,             /**< SPI1 interrupt */
  UART0_IRQn = 3,            /**< USART0 interrupt */
  UART1_IRQn = 4,            /**< USART1 interrupt */
  I2C1_IRQn = 7,             /**< I2C1 interrupt */
  I2C0_IRQn = 8,             /**< I2C0 interrupt */
  SCT_IRQn = 9,              /**< State configurable timer interrupt */
  MRT_IRQn = 10,             /**< Multi-rate timer interrupt */
  CMP_IRQn = 11,             /**< Analog comparator interrupt or Capacitive Touch interrupt */
  WDT_IRQn = 12,             /**< Windowed watchdog timer interrupt */
  BOD_IRQn = 13,             /**< BOD interrupts */
  FLASH_IRQn = 14,           /**< flash interrupt */
  WKT_IRQn = 15,             /**< Self-wake-up timer interrupt */
  ADC_SEQA_IRQn = 16,        /**< ADC0 sequence A completion. */
  ADC_SEQB_IRQn = 17,        /**< ADC0 sequence B completion. */
  ADC_THCMP_IRQn = 18,       /**< ADC0 threshold compare and error. */
  ADC_OVR_IRQn = 19,         /**< ADC0 overrun */
  DMA_IRQn = 20,             /**< DMA0 interrupt */
  CTIMER0_IRQn = 23,         /**< Timer interrupt */
  PIN_INT0_IRQn = 24,        /**< Pin interrupt 0 or pattern match engine slice 0 interrupt */
  PIN_INT1_IRQn = 25,        /**< Pin interrupt 1 or pattern match engine slice 1 interrupt */
  PIN_INT2_IRQn = 26,        /**< Pin interrupt 2 or pattern match engine slice 2 interrupt */
  PIN_INT3_IRQn = 27,        /**< Pin interrupt 3 or pattern match engine slice 3 interrupt */
  PIN_INT4_IRQn = 28,        /**< Pin interrupt 4 or pattern match engine slice 4 interrupt */
  PIN_INT5_IRQn = 29,        /**< Pin interrupt 5 or pattern match engine slice 5 interrupt */
  PIN_INT6_IRQn = 30,        /**< Pin interrupt 6 or pattern match engine slice 6 interrupt */
  PIN_INT7_IRQn = 31         /**< Pin interrupt 7 or pattern match engine slice 7 interrupt */
} IRQn_Type;

#include <CMSIS/core_cm0plus.h> /* Core Peripheral Access Layer */

/* Base addresses */
#define FLASH_BASE (0x00000000u)
#define RAM_BASE (0x10000000u)
#define ROM_BASE (0x0F001FF1u)
#define APB0_BASE (0x40000000u)
#define AHB_BASE (0x50000000u)

/* APB peripherals, see UM11029 2.2.1 */
#define WWDT_BASE (0x40000000u)
#define MRT0_BASE (0x40004000u)
#define WKT_BASE (0x40008000u)
#define SWM_BASE (0x4000C000u)
#define FAIM_BASE (0x40010000u)
#define DAC0_BASE (0x40014000u)
#define DAC1_BASE (0x40018000u)
#define ADC0_BASE (0x4001C000u)
#define PMU_BASE (0x40020000u)
#define ACOMP_BASE (0x40024000u)
#define INPUTMUX_BASE (0x4002C000u)
#define I2C2_BASE (0x40030000u)
#define I2C3_BASE (0x40034000u)
#define CTIMER0_BASE (0x40038000u)
#define FLASH_CTRL_BASE (0x40040000u)
#define IOCON_BASE (0x40044000u)
#define SYSCON_BASE (0x40048000u)
#define I2C0_BASE (0x40050000u)
#define I2C1_BASE (0x40054000u)
#define SPI0_BASE (0x40058000u)
#define SPI1_BASE (0x4005C000u)
#define CAPT_BASE (0x40060000u)
#define USART0_BASE (0x40064000u)
#define USART1_BASE (0x40068000u)
#define USART2_BASE (0x4006C000u)
#define USART3_BASE (0x40070000u)

/* AHB peripherals, see UM11029 2.2.1 */
#define CRC_BASE (0x50000000u)
#define SCT0_BASE (0x50004000u)
#define DMA0_BASE (0x50008000u)
#define MTB_SFR_BASE (0x5000C000u)

/* Other peripheral section */
#define GPIO_BASE (0xA0000000u)
#define PINT_BASE (0xA0004000u)

#define WWDT ((WWDT_Type *)WWDT_BASE)
#define MRT0 ((MRT_Type *)MRT0_BASE)
#define WKT ((WKT_Type *)WKT_BASE)
#define SWM ((SWM_Type *)SWM_BASE)
#define ADC0 ((ADC_Type *)ADC0_BASE)
#define PMU ((PMU_Type *)PMU_BASE)
#define ACOMP ((ACOMP_Type *)ACOMP_BASE)
#define INPUTMUX ((INPUTMUX_Type *)INPUTMUX_BASE)
#define CTIMER0 ((CTIMER_Type *)CTIMER0_BASE)
#define FLASH_CTRL ((FLASH_CTRL_Type *)FLASH_CTRL_BASE)
#define IOCON ((IOCON_Type *)IOCON_BASE)
#define SYSCON ((SYSCON_Type *)SYSCON_BASE)
#define I2C0 ((I2C_Type *)I2C0_BASE)
#define I2C1 ((I2C_Type *)I2C1_BASE)
#define SPI0 ((SPI_Type *)SPI0_BASE)
#define SPI1 ((SPI_Type *)SPI1_BASE)
#define CAPT ((CAPT_Type *)CAPT_BASE)
#define USART0 ((USART_Type *)USART0_BASE)
#define USART1 ((USART_Type *)USART1_BASE)
#define CRC ((CRC_Type *)CRC_BASE)
#define SCT0 ((SCT_Type *)SCT0_BASE)
#define DMA0 ((DMA_Type *)DMA0_BASE)
#define MTB_SFR ((MTB_Type *)MTB_SFR_BASE)
#define GPIO ((GPIO_Type *)GPIO_BASE)
#define PINT ((PINT_Type *)PINT_BASE)

/*!
 * @brief Enumeration for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum dmaRequestSource {
  kDmaRequestUSART0_RX_DMA = 0U, /**< USART0 RX DMA  */
  kDmaRequestUSART0_TX_DMA = 1U, /**< USART0 TX DMA  */
  kDmaRequestUSART1_RX_DMA = 2U, /**< USART1 RX DMA  */
  kDmaRequestUSART1_TX_DMA = 3U, /**< USART1 TX DMA  */
  kDmaRequestSPI0_RX_DMA = 10U,  /**< SPI0 RX DMA  */
  kDmaRequestSPI0_TX_DMA = 11U,  /**< SPI0 TX DMA  */
  kDmaRequestSPI1_RX_DMA = 12U,  /**< SPI1 RX DMA  */
  kDmaRequestSPI1_TX_DMA = 13U,  /**< SPI1 TX DMA  */
  kDmaRequestI2C0_SLV_DMA = 14U, /**< I2C0 SLAVE DMA  */
  kDmaRequestI2C0_MST_DMA = 15U, /**< I2C0 MASTER DMA  */
  kDmaRequestI2C1_SLV_DMA = 16U, /**< I2C1 SLAVE DMA  */
  kDmaRequestI2C1_MST_DMA = 17U, /**< I2C1 MASTER DMA  */
  kDmaRequestCAPT_DMA = 24U,     /**< CAPT DMA  */
} dmaRequestSource_t;

/**
 * @brief Translation table from GPIO pin name to IOCON index
 *
 */
typedef enum IOCON_PIN {
  IOCON_PIO0_0 = 17,
  IOCON_PIO0_1 = 11,
  IOCON_PIO0_2 = 6,
  IOCON_PIO0_3 = 5,
  IOCON_PIO0_4 = 4,
  IOCON_PIO0_5 = 3,
  IOCON_PIO0_6 = 16,
  IOCON_PIO0_7 = 15,
  IOCON_PIO0_8 = 14,
  IOCON_PIO0_9 = 13,
  IOCON_PIO0_10 = 8,
  IOCON_PIO0_11 = 7,
  IOCON_PIO0_12 = 2,
  IOCON_PIO0_13 = 1,
  IOCON_PIO0_14 = 18,
  IOCON_PIO0_15 = 10,
  IOCON_PIO0_16 = 9,
  IOCON_PIO0_17 = 0,
  IOCON_PIO0_18 = 30,
  IOCON_PIO0_19 = 29,
  IOCON_PIO0_20 = 28,
  IOCON_PIO0_21 = 27,
  IOCON_PIO0_22 = 26,
  IOCON_PIO0_23 = 25,
  IOCON_PIO0_24 = 24,
  IOCON_PIO0_25 = 23,
  IOCON_PIO0_26 = 22,
  IOCON_PIO0_27 = 21,
  IOCON_PIO0_28 = 20,
  IOCON_PIO0_29 = 50,
  IOCON_PIO0_30 = 51,
  IOCON_PIO0_31 = 35,
  IOCON_PIO1_0 = 36,
  IOCON_PIO1_1 = 37,
  IOCON_PIO1_2 = 38,
  IOCON_PIO1_3 = 41,
  IOCON_PIO1_4 = 42,
  IOCON_PIO1_5 = 43,
  IOCON_PIO1_6 = 46,
  IOCON_PIO1_7 = 49,
  IOCON_PIO1_8 = 31,
  IOCON_PIO1_9 = 32,
  IOCON_PIO1_10 = 55,
  IOCON_PIO1_11 = 54,
  IOCON_PIO1_12 = 33,
  IOCON_PIO1_13 = 34,
  IOCON_PIO1_14 = 39,
  IOCON_PIO1_15 = 40,
  IOCON_PIO1_16 = 44,
  IOCON_PIO1_17 = 45,
  IOCON_PIO1_18 = 47,
  IOCON_PIO1_19 = 48,
  IOCON_PIO1_20 = 52,
  IOCON_PIO1_21 = 53,
} IOCON_PIN_Type;

/*!
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
  GPIO_PIO0_18 = 18,
  GPIO_PIO0_19 = 19,
  GPIO_PIO0_20 = 20,
  GPIO_PIO0_21 = 21,
  GPIO_PIO0_22 = 22,
  GPIO_PIO0_23 = 23,
  GPIO_PIO0_24 = 24,
  GPIO_PIO0_25 = 25,
  GPIO_PIO0_26 = 26,
  GPIO_PIO0_27 = 27,
  GPIO_PIO0_28 = 28,
  GPIO_PIO0_29 = 29,
  GPIO_PIO0_30 = 30,
  GPIO_PIO0_31 = 31,
  GPIO_PIO1_0 = 32,
  GPIO_PIO1_1 = 33,
  GPIO_PIO1_2 = 34,
  GPIO_PIO1_3 = 35,
  GPIO_PIO1_4 = 36,
  GPIO_PIO1_5 = 37,
  GPIO_PIO1_6 = 38,
  GPIO_PIO1_7 = 39,
  GPIO_PIO1_8 = 40,
  GPIO_PIO1_9 = 41,
  GPIO_PIO1_10 = 42,
  GPIO_PIO1_11 = 43,
  GPIO_PIO1_12 = 44,
  GPIO_PIO1_13 = 45,
  GPIO_PIO1_14 = 46,
  GPIO_PIO1_15 = 47,
  GPIO_PIO1_16 = 48,
  GPIO_PIO1_17 = 49,
  GPIO_PIO1_18 = 50,
  GPIO_PIO1_19 = 51,
  GPIO_PIO1_20 = 52,
  GPIO_PIO1_21 = 53,
} GPIO_PIN_Type;

// default configuration options, override with your own!
#include "nxp/LPC8XX/LPC84X_default.h"
// Peripheral specific includes
#include "nxp/LPC8XX/LPC84X_wwdt.h"
#include "nxp/LPC8XX/LPC84X_mrt.h"
#include "nxp/LPC8XX/LPC84X_wkt.h"
#include "nxp/LPC8XX/LPC84X_swm.h"
#include "nxp/LPC8XX/LPC84X_dac.h"
#include "nxp/LPC8XX/LPC84X_adc.h"
#include "nxp/LPC8XX/LPC84X_pmu.h"
#include "nxp/LPC8XX/LPC84X_acomp.h"
#include "nxp/LPC8XX/LPC84X_inputmux.h"
#include "nxp/LPC8XX/LPC84X_i2c.h"
#include "nxp/LPC8XX/LPC84X_ctimer.h"
#include "nxp/LPC8XX/LPC84X_flash_ctrl.h"
#include "nxp/LPC8XX/LPC84X_iocon.h"
#include "nxp/LPC8XX/LPC84X_syscon.h"
#include "nxp/LPC8XX/LPC84X_spi.h"
#include "nxp/LPC8XX/LPC84X_capt.h"
#include "nxp/LPC8XX/LPC84X_usart.h"
#include "nxp/LPC8XX/LPC84X_crc.h"
#include "nxp/LPC8XX/LPC84X_sct.h"
#include "nxp/LPC8XX/LPC84X_dma.h"
#include "nxp/LPC8XX/LPC84X_mtb.h"
#include "nxp/LPC8XX/LPC84X_gpio.h"
#include "nxp/LPC8XX/LPC84X_pint.h"

#ifdef __cplusplus
}
#endif

/*
Copied orignally from the C header, the idea is to move more and more from
C definitions to C++. Step by step, C++ bits will go below
*/

namespace LPC844M201BD64 {

namespace peripherals {
constexpr static inline uint32_t SPI0_cpp = 0x4005'8000u; /**< TODO, rename to their names when refactoring is done */
constexpr static inline uint32_t SPI1_cpp = 0x4005'C000u; /**< TODO, rename to their names when refactoring is done */
}  // namespace peripherals

#include "nxp/LPC8XX.hpp/LPC8XX_spi_regs.hpp"
#include "nxp/LPC8XX.hpp/LPC84X_spi.hpp"
}  // namespace LPC844M201BD64

#endif
