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

enum class interrupts : std::int8_t {
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

namespace libMcuLL {
namespace hw {

/* Base addresses */
constexpr inline libMcuLL::memoryAddress flashBaseAddress{0x0000'0000u};
constexpr inline libMcuLL::memoryAddress ramBaseAddress{0x1000'0000u};
constexpr inline libMcuLL::memoryAddress romBaseAddress{0xF001'FF10u};
constexpr inline libMcuLL::memoryAddress apb0BaseAddress{0x4000'0000u};
constexpr inline libMcuLL::memoryAddress ahbBaseAddress{0x5000'0000u};

/* APB peripherals, see UM11029 2.2.1 */
constexpr inline libMcuLL::WWDTbaseAddress wwdtAddress{0x4000'0000u};         /**< Windowed watchdog base address */
constexpr inline libMcuLL::MRTbaseAddress mrt0Address{0x4000'4000u};          /**< multi rate timer base address */
constexpr inline libMcuLL::WKTbaseAddress wktAddress{0x4000'8000u};           /**< wakeup timer base address */
constexpr inline libMcuLL::SWMbaseAddress swmAddress{0x4000'C000u};           /**< Switch matrix base address */
constexpr inline libMcuLL::faimBaseAddress faimAddress{0x4001'0000u};         /**< Fast memory init base address */
constexpr inline libMcuLL::dacBaseAddress dac0Address{0x4001'4000u};          /**< DAC 0 base address */
constexpr inline libMcuLL::dacBaseAddress dac1Address{0x4001'8000u};          /**< DAC 1 base address */
constexpr inline libMcuLL::adcBaseAddress adc0Address{0x4001'C000u};          /**< ADC 0 matrix base address */
constexpr inline libMcuLL::PMUbaseAddress pmuAddress{0x4002'0000u};           /**< Power management unit base address */
constexpr inline libMcuLL::ACMPbaseAddress acmpAddress{0x4002'4000u};         /**< Analog comparator base address */
constexpr inline libMcuLL::inputMuxBaseAddress inputMuxAddress{0x4002'C000u}; /**< Flash memory controller base address */
constexpr inline libMcuLL::I2CbaseAddress i2c2Address{0x4003'0000u};          /**< I2C 2 base address */
constexpr inline libMcuLL::I2CbaseAddress i2c3Address{0x4003'4000u};          /**< I2C 3 base address */
constexpr inline libMcuLL::ctimerBaseAddress ctimer0Address{0x4003'8000u};    /**< standard counter/timer 0 base address */
constexpr inline libMcuLL::FMCbaseAddress fmcAddress{0x4004'0000u};           /**< Flash memory controller base address */
constexpr inline libMcuLL::IOCONbaseAddress ioconAddress{0x4004'4000u};       /**< I/O control base address */
constexpr inline libMcuLL::SYSCONbaseAddress sysconAddress{0x4004'8000u};     /**< System control base address */
constexpr inline libMcuLL::I2CbaseAddress i2c0Address{0x4005'0000u};          /**< I2C 0 base address */
constexpr inline libMcuLL::I2CbaseAddress i2c1Address{0x4005'4000u};          /**< I2C 1 base address */
constexpr inline libMcuLL::SPIbaseAddress spi0Address{0x4005'8000u};          /**< SPI 0 base address */
constexpr inline libMcuLL::SPIbaseAddress spi1Address{0x4005'C000u};          /**< SPI 1 base address */
constexpr inline libMcuLL::captBaseAddress capt0Address{0x4006'0000u};        /**< Capacitive touch 0 base address */
constexpr inline libMcuLL::USARTbaseAddress usart0Address{0x4006'4000u};      /**< USART 0 base address */
constexpr inline libMcuLL::USARTbaseAddress usart1Address{0x4006'8000u};      /**< USART 1 base address */
constexpr inline libMcuLL::USARTbaseAddress usart2Address{0x4006'C000u};      /**< USART 2 base address */
constexpr inline libMcuLL::USARTbaseAddress usart3Address{0x4007'0000u};      /**< USART 3 base address */

/* AHB peripherals, see UM11029 2.2.1 */
constexpr inline libMcuLL::CRCbaseAddress crcAddress{0x5000'0000u};  /**< CRC calculator base address */
constexpr inline libMcuLL::SCTbaseAddress sct0Address{0x5000'4000u}; /**< State configurable timer 0 base address */
constexpr inline libMcuLL::dmaBaseAddress dmaAddress{0x5000'8000u};  /**< DMA 0 base address */
constexpr inline libMcuLL::mtbBaseAddress mtbAddress{0x5000'C000u};  /**< MTB base address */

/* Direct connected peripherals */
constexpr inline libMcuLL::GPIObaseAddress gpioAddress{0xA000'0000u};     /**< General Purpose I/O base address */
constexpr inline libMcuLL::PININTbaseAddress pinintAddress{0xA000'4000u}; /**< Pin interrupt base address */

}  // namespace hw
namespace dma {
/*!
 * @brief Enumeration for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
enum class dmaRequestSources : std::uint8_t {
  usart0rx = 0U,    /**< USART0 RX DMA  */
  usart0tx = 1U,    /**< USART0 TX DMA  */
  usart1rx = 2U,    /**< USART1 RX DMA  */
  usart1tx = 3U,    /**< USART1 TX DMA  */
  usart2rx = 4U,    /**< USART2 RX DMA  */
  usart2tx = 5U,    /**< USART2 TX DMA  */
  usart3rx = 6U,    /**< USART3 RX DMA  */
  usart3tx = 7U,    /**< USART3 TX DMA  */
  usart4rx = 8U,    /**< USART4 RX DMA  */
  usart4tx = 9U,    /**< USART4 TX DMA  */
  spi0rx = 10U,     /**< SPI0 RX DMA  */
  spi0tx = 11U,     /**< SPI0 TX DMA  */
  spi1rx = 12U,     /**< SPI1 RX DMA  */
  spi1tx = 13U,     /**< SPI1 TX DMA  */
  i2c0slave = 14U,  /**< I2C0 SLAVE DMA  */
  i2c0master = 15U, /**< I2C0 MASTER DMA  */
  i2c1slave = 16U,  /**< I2C1 SLAVE DMA  */
  i2c1master = 17U, /**< I2C1 MASTER DMA  */
  i2c2slave = 18U,  /**< I2C2 SLAVE DMA  */
  i2c2master = 19U, /**< I2C2 MASTER DMA  */
  i2c3slave = 20U,  /**< I2C3 SLAVE DMA  */
  i2c3master = 21U, /**< I2C3 MASTER DMA  */
  dac0 = 22U,       /**< DAC0 DMA REQUEST  */
  dac1 = 23U,       /**< DAC1 DMA REQUEST  */
  capt = 24U,       /**< CAPT DMA  */
};
}  // namespace dma
}  // namespace libMcuLL

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

// includes that define the registers namespace go here.
#include "LPC8XX.hpp/LPC84X_iocon_hw.hpp"
#include "LPC8XX.hpp/LPC84X_swm_hw.hpp"
#include "LPC8XX.hpp/LPC84X_gpio_hw.hpp"
#include "LPC8XX.hpp/LPC84X_syscon_hw.hpp"

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here
#include "LPC8XX.hpp/LPC845M301BD48_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "LPC8XX.hpp/LPC84X_iocon_sw.hpp"
#include "LPC8XX.hpp/LPC84X_swm_sw.hpp"
#include "LPC8XX.hpp/LPC84X_gpio_sw.hpp"
#include "LPC8XX.hpp/LPC84X_syscon_sw.hpp"

#endif
