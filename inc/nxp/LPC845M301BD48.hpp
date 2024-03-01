/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for the LPC845M301BD48 microcontroller definitions
 */
#ifndef LPC845M301BD48_HPP
#define LPC845M301BD48_HPP

namespace libMcuLL {
namespace hw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t revision = 0x0001; /**< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool present = false; /**< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool present = true;                      /**< presence of vector relocation */
constexpr inline std::uint32_t addressMask = 0xFFFFFF00UL; /**< VTOR bit count */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t variant = 0; /**< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t priorityMask = 0x3; /**< NVIC priority bit mask */
constexpr inline std::uint32_t priorityBits = 2;   /**< NVIC priority bit count */
constexpr inline std::uint32_t vectorCount = 48;   /**< amount of interrupt vectors */
}  // namespace nvic

enum class interrupts : int8_t {
  reset = -15,
  nonMaskable = -14,
  hardFault = -13,
  svCall = -5,
  pendSv = -2,
  systick = -1,
  spi0 = 0,           /**< SPI0 interrupt */
  spi1 = 1,           /**< SPI1 interrupt */
  dac0 = 2,           /**< DAC0 interrupt */
  uart0 = 3,          /**< USART0 interrupt */
  uart1 = 4,          /**< USART1 interrupt */
  uart2 = 5,          /**< USART2 interrupt */
  i2c1 = 7,           /**< I2C1 interrupt */
  i2c0 = 8,           /**< I2C0 interrupt */
  sct0 = 9,           /**< State configurable timer interrupt */
  mrt0 = 10,          /**< Multi-rate timer interrupt */
  acmp0 = 11,         /**< Analog comparator interrupt or Capacitive Touch interrupt */
  wdt = 12,           /**< Windowed watchdog timer interrupt */
  bod = 13,           /**< BOD interrupts */
  flash = 14,         /**< flash interrupt */
  wkt = 15,           /**< Self-wake-up timer interrupt */
  adc0_seqA = 16,     /**< ADC0 sequence A completion. */
  adc0_seqB = 17,     /**< ADC0 sequence B completion. */
  adc0_thcmp = 18,    /**< ADC0 threshold compare and error. */
  adc0_ovr = 19,      /**< ADC0 overrun */
  dma = 20,           /**< DMA0 interrupt */
  i2c2 = 21,          /**< I2C2 interrupt */
  i2c3 = 22,          /**< I2C3 interrupt */
  ctimer0 = 23,       /**< Timer interrupt */
  pinint0 = 24,       /**< Pin interrupt 0 or pattern match engine slice 0 interrupt */
  pinint1 = 25,       /**< Pin interrupt 1 or pattern match engine slice 1 interrupt */
  pinint2 = 26,       /**< Pin interrupt 2 or pattern match engine slice 2 interrupt */
  pinint3 = 27,       /**< Pin interrupt 3 or pattern match engine slice 3 interrupt */
  pinint4 = 28,       /**< Pin interrupt 4 or pattern match engine slice 4 interrupt */
  pinint5_dac1 = 29,  /**< Pin interrupt 5 or pattern match engine slice 5 interrupt or DAC1 interrupt */
  pinint6_uart3 = 30, /**< Pin interrupt 6 or pattern match engine slice 6 interrupt or UART3 interrupt */
  pinint7_uart4 = 31  /**< Pin interrupt 7 or pattern match engine slice 7 interrupt or UART4 interrupt */
};
}  // namespace hw
}  // namespace libMcuLL

#include <CortexM/cortex_m0plus.hpp>

#ifdef __cplusplus
extern "C" {
#endif

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
#define DAC0 ((DAC_Type *)DAC0_BASE)
#define DAC1 ((DAC_Type *)DAC1_BASE)
#define ADC0 ((ADC_Type *)ADC0_BASE)
#define PMU ((PMU_Type *)PMU_BASE)
#define ACOMP ((ACOMP_Type *)ACOMP_BASE)
#define INPUTMUX ((INPUTMUX_Type *)INPUTMUX_BASE)
#define I2C2 ((I2C_Type *)I2C2_BASE)
#define I2C3 ((I2C_Type *)I2C3_BASE)
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
#define USART2 ((USART_Type *)USART2_BASE)
#define USART3 ((USART_Type *)USART3_BASE)
#define CRC ((CRC_Type *)CRC_BASE)
#define SCT0 ((SCT_Type *)SCT0) _BASE
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
  kDmaRequestUSART2_RX_DMA = 4U, /**< USART2 RX DMA  */
  kDmaRequestUSART2_TX_DMA = 5U, /**< USART2 TX DMA  */
  kDmaRequestUSART3_RX_DMA = 6U, /**< USART3 RX DMA  */
  kDmaRequestUSART3_TX_DMA = 7U, /**< USART3 TX DMA  */
  kDmaRequestUSART4_RX_DMA = 8U, /**< USART4 RX DMA  */
  kDmaRequestUSART4_TX_DMA = 9U, /**< USART4 TX DMA  */
  kDmaRequestSPI0_RX_DMA = 10U,  /**< SPI0 RX DMA  */
  kDmaRequestSPI0_TX_DMA = 11U,  /**< SPI0 TX DMA  */
  kDmaRequestSPI1_RX_DMA = 12U,  /**< SPI1 RX DMA  */
  kDmaRequestSPI1_TX_DMA = 13U,  /**< SPI1 TX DMA  */
  kDmaRequestI2C0_SLV_DMA = 14U, /**< I2C0 SLAVE DMA  */
  kDmaRequestI2C0_MST_DMA = 15U, /**< I2C0 MASTER DMA  */
  kDmaRequestI2C1_SLV_DMA = 16U, /**< I2C1 SLAVE DMA  */
  kDmaRequestI2C1_MST_DMA = 17U, /**< I2C1 MASTER DMA  */
  kDmaRequestI2C2_SLV_DMA = 18U, /**< I2C2 SLAVE DMA  */
  kDmaRequestI2C2_MST_DMA = 19U, /**< I2C2 MASTER DMA  */
  kDmaRequestI2C3_SLV_DMA = 20U, /**< I2C3 SLAVE DMA  */
  kDmaRequestI2C3_MST_DMA = 21U, /**< I2C3 MASTER DMA  */
  kDmaRequestDAC0_DMAREQ = 22U,  /**< DAC0 DMA REQUEST  */
  kDmaRequestDAC1_DMAREQ = 23U,  /**< DAC1 DMA REQUEST  */
  kDmaRequestCAPT_DMA = 24U,     /**< CAPT DMA  */
} dmaRequestSource_t;

/**
 * @brief Translation table from GPIO pin name to IOCON index
 *
 */
typedef enum {
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
#include "LPC8XX/LPC84X_default.h"
// Peripheral specific includes
#include "LPC8XX/LPC84X_wwdt.h"
#include "LPC8XX/LPC84X_mrt.h"
#include "LPC8XX/LPC84X_wkt.h"
#include "LPC8XX/LPC84X_swm.h"
#include "LPC8XX/LPC84X_dac.h"
#include "LPC8XX/LPC84X_adc.h"
#include "LPC8XX/LPC84X_pmu.h"
#include "LPC8XX/LPC84X_acomp.h"
#include "LPC8XX/LPC84X_inputmux.h"
#include "LPC8XX/LPC84X_i2c.h"
#include "LPC8XX/LPC84X_ctimer.h"
#include "LPC8XX/LPC84X_flash_ctrl.h"
#include "LPC8XX/LPC84X_iocon.h"
#include "LPC8XX/LPC84X_syscon.h"
#include "LPC8XX/LPC84X_spi.h"
#include "LPC8XX/LPC84X_capt.h"
#include "LPC8XX/LPC84X_usart.h"
#include "LPC8XX/LPC84X_crc.h"
#include "LPC8XX/LPC84X_sct.h"
#include "LPC8XX/LPC84X_dma.h"
#include "LPC8XX/LPC84X_mtb.h"
#include "LPC8XX/LPC84X_gpio.h"
#include "LPC8XX/LPC84X_pint.h"

#ifdef __cplusplus
}
#endif

/*
Copied orignally from the C header, the idea is to move more and more from
C definitions to C++. Step by step, C++ bits will go below
*/

namespace peripherals {
constexpr static inline uint32_t SPI0_cpp = 0x4005'8000u; /**< TODO, rename to their names when refactoring is done */
constexpr static inline uint32_t SPI1_cpp = 0x4005'C000u; /**< TODO, rename to their names when refactoring is done */
}  // namespace peripherals

// includes that define the registers namespace go here.
#include "LPC8XX.hpp/LPC8XX_spi_hw.hpp"

// includes that use the registers namespace go here
#include "LPC8XX.hpp/LPC84X_spi_sw.hpp"

#endif
