/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for the LPC845M301BD48 microcontroller definitions
 */
#ifndef LIBMCU_LPC845M301BD48_LL_HPP
#define LIBMCU_LPC845M301BD48_LL_HPP

#include "../libmcu/libmcu.hpp"

namespace libMcuHw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t revision{0x0000}; /**< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool present{false}; /**< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool present{true};                      /**< presence of vector relocation */
constexpr inline std::uint32_t addressMask{0xFFFFFF00UL}; /**< VTOR bit count */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t variant{0}; /**< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t priorityMask{0x3}; /**< NVIC priority bit mask */
constexpr inline std::uint32_t priorityBits{2};   /**< NVIC priority bit count */
constexpr inline std::uint32_t vectorCount{48};   /**< amount of interrupt vectors */
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
}  // namespace libMcuHw

#include <CortexM/cortex_m0plus.hpp>

namespace libMcuHw {
/* Base addresses */
constexpr inline libMcu::memoryAddress flashBaseAddress{0x0000'0000u};
constexpr inline libMcu::memoryAddress ramBaseAddress{0x1000'0000u};
constexpr inline libMcu::memoryAddress romBaseAddress{0xF001'FF10u};
constexpr inline libMcu::memoryAddress apb0BaseAddress{0x4000'0000u};
constexpr inline libMcu::memoryAddress ahbBaseAddress{0x5000'0000u};
/* APB peripherals, see UM11029 2.2.1 */
constexpr inline libMcu::wwdtBaseAddress wwdtAddress{0x4000'0000u};         /**< Windowed watchdog base address */
constexpr inline libMcu::mrtBaseAddress mrt0Address{0x4000'4000u};          /**< Multi rate timer base address */
constexpr inline libMcu::wktBaseAddress wktAddress{0x4000'8000u};           /**< Wakeup timer base address */
constexpr inline libMcu::swmBaseAddress swmAddress{0x4000'C000u};           /**< Switch matrix base address */
constexpr inline libMcu::faimBaseAddress faimAddress{0x4001'0000u};         /**< Fast memory init base address */
constexpr inline libMcu::dacBaseAddress dac0Address{0x4001'4000u};          /**< DAC 0 base address */
constexpr inline libMcu::dacBaseAddress dac1Address{0x4001'8000u};          /**< DAC 1 base address */
constexpr inline libMcu::adcBaseAddress adc0Address{0x4001'C000u};          /**< ADC 0 matrix base address */
constexpr inline libMcu::pmuBaseAddress pmuAddress{0x4002'0000u};           /**< Power management unit base address */
constexpr inline libMcu::acmpBaseAddress acmpAddress{0x4002'4000u};         /**< Analog comparator base address */
constexpr inline libMcu::inputMuxBaseAddress inputMuxAddress{0x4002'C000u}; /**< Input multiplexer base address */
constexpr inline libMcu::i2cBaseAddress i2c2Address{0x4003'0000u};          /**< I2C 2 base address */
constexpr inline libMcu::i2cBaseAddress i2c3Address{0x4003'4000u};          /**< I2C 3 base address */
constexpr inline libMcu::ctimerBaseAddress ctimer0Address{0x4003'8000u};    /**< Standard counter/timer 0 base address */
constexpr inline libMcu::fmcBaseAddress fmcAddress{0x4004'0000u};           /**< Flash memory controller base address */
constexpr inline libMcu::ioconBaseAddress ioconAddress{0x4004'4000u};       /**< I/O control base address */
constexpr inline libMcu::sysconBaseAddress sysconAddress{0x4004'8000u};     /**< System control base address */
constexpr inline libMcu::i2cBaseAddress i2c0Address{0x4005'0000u};          /**< I2C 0 base address */
constexpr inline libMcu::i2cBaseAddress i2c1Address{0x4005'4000u};          /**< I2C 1 base address */
constexpr inline libMcu::spiBaseAddress spi0Address{0x4005'8000u};          /**< SPI 0 base address */
constexpr inline libMcu::spiBaseAddress spi1Address{0x4005'C000u};          /**< SPI 1 base address */
constexpr inline libMcu::captBaseAddress capt0Address{0x4006'0000u};        /**< Capacitive touch 0 base address */
constexpr inline libMcu::uartBaseAddress usart0Address{0x4006'4000u};       /**< USART 0 base address */
constexpr inline libMcu::uartBaseAddress usart1Address{0x4006'8000u};       /**< USART 1 base address */
constexpr inline libMcu::uartBaseAddress usart2Address{0x4006'C000u};       /**< USART 2 base address */
constexpr inline libMcu::uartBaseAddress usart3Address{0x4007'0000u};       /**< USART 3 base address */
/* AHB peripherals, see UM11029 2.2.1 */
constexpr inline libMcu::crcBaseAddress crcAddress{0x5000'0000u};  /**< CRC calculator base address */
constexpr inline libMcu::sctBaseAddress sct0Address{0x5000'4000u}; /**< State configurable timer 0 base address */
constexpr inline libMcu::dmaBaseAddress dmaAddress{0x5000'8000u};  /**< DMA 0 base address */
constexpr inline libMcu::mtbBaseAddress mtbAddress{0x5000'C000u};  /**< MTB base address */
/* Direct connected peripherals */
constexpr inline libMcu::gpioBaseAddress gpioAddress{0xA000'0000u};     /**< General Purpose I/O base address */
constexpr inline libMcu::pinintBaseAddress pinintAddress{0xA000'4000u}; /**< Pin interrupt base address */
}  // namespace libMcuHw

namespace libMcuHw::dma {
/*!
 * @brief Enumeration for the DMA hardware request
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request to trigger the DMA transfer accordingly. The index of the hardware request varies according to MCU .
 */
enum class dmaRequestSources : std::uint8_t {
  usart0rx = 0u,    /**< USART0 RX DMA  */
  usart0tx = 1u,    /**< USART0 TX DMA  */
  usart1rx = 2u,    /**< USART1 RX DMA  */
  usart1tx = 3u,    /**< USART1 TX DMA  */
  usart2rx = 4u,    /**< USART2 RX DMA  */
  usart2tx = 5u,    /**< USART2 TX DMA  */
  usart3rx = 6u,    /**< USART3 RX DMA  */
  usart3tx = 7u,    /**< USART3 TX DMA  */
  usart4rx = 8u,    /**< USART4 RX DMA  */
  usart4tx = 9u,    /**< USART4 TX DMA  */
  spi0rx = 10u,     /**< SPI0 RX DMA  */
  spi0tx = 11u,     /**< SPI0 TX DMA  */
  spi1rx = 12u,     /**< SPI1 RX DMA  */
  spi1tx = 13u,     /**< SPI1 TX DMA  */
  i2c0slave = 14u,  /**< I2C0 SLAVE DMA  */
  i2c0master = 15u, /**< I2C0 MASTER DMA  */
  i2c1slave = 16u,  /**< I2C1 SLAVE DMA  */
  i2c1master = 17u, /**< I2C1 MASTER DMA  */
  i2c2slave = 18u,  /**< I2C2 SLAVE DMA  */
  i2c2master = 19u, /**< I2C2 MASTER DMA  */
  i2c3slave = 20u,  /**< I2C3 SLAVE DMA  */
  i2c3master = 21u, /**< I2C3 MASTER DMA  */
  dac0 = 22u,       /**< DAC0 DMA REQUEST  */
  dac1 = 23u,       /**< DAC1 DMA REQUEST  */
  capt = 24u,       /**< CAPT DMA  */
};
}  // namespace libMcuHw::dma

// includes that define the registers namespace go here.
#include "LPC8XX_HW/LPC84X_wwdt_hw.hpp"
#include "LPC8XX_HW/LPC84X_mrt_hw.hpp"
#include "LPC8XX_HW/LPC84X_wkt_hw.hpp"
#include "LPC8XX_HW/LPC84X_swm_hw.hpp"
#include "LPC8XX_HW/LPC84X_faim_hw.hpp"
#include "LPC8XX_HW/LPC84X_dac_hw.hpp"
#include "LPC8XX_HW/LPC84X_adc_hw.hpp"
#include "LPC8XX_HW/LPC84X_pmu_hw.hpp"
#include "LPC8XX_HW/LPC84X_acmp_hw.hpp"
#include "LPC8XX_HW/LPC84X_inmux_hw.hpp"
#include "LPC8XX_HW/LPC84X_i2c_hw.hpp"
#include "LPC8XX_HW/LPC84X_ctimer_hw.hpp"
#include "LPC8XX_HW/LPC84X_fmc_hw.hpp"
#include "LPC8XX_HW/LPC84X_iocon_hw.hpp"
#include "LPC8XX_HW/LPC84X_syscon_hw.hpp"
#include "LPC8XX_HW/LPC84X_spi_hw.hpp"
#include "LPC8XX_HW/LPC84X_capt_hw.hpp"
#include "LPC8XX_HW/LPC84X_usart_hw.hpp"
#include "LPC8XX_HW/LPC84X_crc_hw.hpp"
#include "LPC8XX_HW/LPC84X_sct_hw.hpp"
#include "LPC8XX_HW/LPC84X_dma_hw.hpp"
#include "LPC8XX_HW/LPC84X_mtb_hw.hpp"
#include "LPC8XX_HW/LPC84X_gpio_hw.hpp"
#include "LPC8XX_HW/LPC84X_pinint_hw.hpp"

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here
#include "LPC8XX_PINS/LPC845M301BD48_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "LPC8XX_LL/LPC84X_swm_ll.hpp"
#include "LPC8XX_LL/LPC84X_iocon_ll.hpp"
#include "LPC8XX_LL/LPC84X_syscon_ll.hpp"
#include "LPC8XX_LL/LPC84X_usart_ll.hpp"
#include "LPC8XX_LL/LPC84X_gpio_ll.hpp"
#include "LPC8XX_LL/LPC84X_adc_ll.hpp"

#include "LPC8XX_CLOCK/LPC84X_clock.hpp"

#endif
