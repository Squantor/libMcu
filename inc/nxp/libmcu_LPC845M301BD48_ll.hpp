/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcu_LPC845M301BD48_ll.hpp
 * @brief include for the LPC845M301BD48 libmcu low level library
 */
#ifndef LIBMCU_LPC845M301BD48_LL_HPP
#define LIBMCU_LPC845M301BD48_LL_HPP

#include "../libmcu/libmcull.hpp"
#include "../libmcu/functions_CM0.hpp"

namespace libmcuhw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t Revision{0x0000}; /*!< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool Present{false}; /*!< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool Present{true};                      /*!< presence of vector relocation */
constexpr inline std::uint32_t AddressMask{0xFFFFFF00UL}; /*!< VTOR bit count */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t Variant{0}; /*!< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t PriorityMask{0x3}; /*!< NVIC priority bit mask */
constexpr inline std::uint32_t PriorityBits{2};   /*!< NVIC priority bit count */
constexpr inline std::uint32_t VectorCount{48};   /*!< amount of interrupt vectors */
}  // namespace nvic
/**
 * @brief Interrupts available for the LPC845M301BD48
 * @todo switch from enum class to normal enum
 */
enum class Interrupts : std::int8_t {
  Reset = -15,       /*!< Reset interrupt */
  NonMaskable = -14, /*!< Non maskable interrupt */
  HardFault = -13,   /*!< Hard fault interrupt */
  SvCall = -5,       /*!< Supervisor call interrupt */
  PendSv = -2,       /*!< Pendable request interrupt */
  Systick = -1,      /*!< SysTick interrupt */
  Spi0 = 0,          /*!< SPI0 interrupt */
  Spi1 = 1,          /*!< SPI1 interrupt */
  Dac0 = 2,          /*!< DAC0 interrupt */
  Uart0 = 3,         /*!< USART0 interrupt */
  Uart1 = 4,         /*!< USART1 interrupt */
  Uart2 = 5,         /*!< USART2 interrupt */
  I2c1 = 7,          /*!< I2C1 interrupt */
  I2c0 = 8,          /*!< I2C0 interrupt */
  Sct0 = 9,          /*!< State configurable timer interrupt */
  Mrt0 = 10,         /*!< Multi-rate timer interrupt */
  Acmp0 = 11,        /*!< Analog comparator interrupt or Capacitive Touch interrupt */
  Wwdt = 12,         /*!< Windowed watchdog timer interrupt */
  Bod = 13,          /*!< BOD interrupts */
  Flash = 14,        /*!< flash interrupt */
  Wkt = 15,          /*!< Self-wake-up timer interrupt */
  Adc0SeqA = 16,     /*!< ADC0 sequence A completion. */
  Adc0SeqB = 17,     /*!< ADC0 sequence B completion. */
  Adc0ThCmp = 18,    /*!< ADC0 threshold compare and error. */
  Adc0Ovr = 19,      /*!< ADC0 overrun */
  Dma = 20,          /*!< DMA0 interrupt */
  I2c2 = 21,         /*!< I2C2 interrupt */
  I2c3 = 22,         /*!< I2C3 interrupt */
  Ctimer0 = 23,      /*!< Timer interrupt */
  Pinint0 = 24,      /*!< Pin interrupt 0 or pattern match engine slice 0 interrupt */
  Pinint1 = 25,      /*!< Pin interrupt 1 or pattern match engine slice 1 interrupt */
  Pinint2 = 26,      /*!< Pin interrupt 2 or pattern match engine slice 2 interrupt */
  Pinint3 = 27,      /*!< Pin interrupt 3 or pattern match engine slice 3 interrupt */
  Pinint4 = 28,      /*!< Pin interrupt 4 or pattern match engine slice 4 interrupt */
  Pinint5Dac1 = 29,  /*!< Pin interrupt 5 or pattern match engine slice 5 interrupt or DAC1 interrupt */
  Pinint6Uart3 = 30, /*!< Pin interrupt 6 or pattern match engine slice 6 interrupt or UART3 interrupt */
  Pinint7Uart4 = 31  /*!< Pin interrupt 7 or pattern match engine slice 7 interrupt or UART4 interrupt */
};
}  // namespace libmcuhw

#include <CortexM/cortex_m0plus.hpp>

namespace libmcuhw {
/* Base addresses */
constexpr inline libmcu::MemoryAddress FlashBaseAddress{0x0000'0000u};
constexpr inline libmcu::MemoryAddress RamBaseAddress{0x1000'0000u};
constexpr inline libmcu::MemoryAddress RomBaseAddress{0xF001'FF10u};
constexpr inline libmcu::MemoryAddress Apb0BaseAddress{0x4000'0000u};
constexpr inline libmcu::MemoryAddress AhbBaseAddress{0x5000'0000u};
/* APB peripherals, see UM11029 2.2.1 */
constexpr inline libmcu::WwdtBaseAddress WwdtAddress{0x4000'0000u};      /*!< Windowed watchdog base address */
constexpr inline libmcu::MrtBaseAddress Mrt0Address{0x4000'4000u};       /*!< Multi rate timer base address */
constexpr inline libmcu::WktBaseAddress WktAddress{0x4000'8000u};        /*!< Wakeup timer base address */
constexpr inline libmcu::SwmBaseAddress SwmAddress{0x4000'C000u};        /*!< Switch matrix base address */
constexpr inline libmcu::FaimBaseAddress FaimAddress{0x4001'0000u};      /*!< Fast memory init base address */
constexpr inline libmcu::DacBaseAddress Dac0Address{0x4001'4000u};       /*!< DAC 0 base address */
constexpr inline libmcu::DacBaseAddress Dac1Address{0x4001'8000u};       /*!< DAC 1 base address */
constexpr inline libmcu::AdcBaseAddress Adc0Address{0x4001'C000u};       /*!< ADC 0 matrix base address */
constexpr inline libmcu::PmuBaseAddress PmuAddress{0x4002'0000u};        /*!< Power management unit base address */
constexpr inline libmcu::AcmpBaseAddress AcmpAddress{0x4002'4000u};      /*!< Analog comparator base address */
constexpr inline libmcu::InmuxBaseAddress InmuxAddress{0x4002'C000u};    /*!< Input multiplexer base address */
constexpr inline libmcu::I2cBaseAddress I2c2Address{0x4003'0000u};       /*!< I2C 2 base address */
constexpr inline libmcu::I2cBaseAddress I2c3Address{0x4003'4000u};       /*!< I2C 3 base address */
constexpr inline libmcu::CtimerBaseAddress Ctimer0Address{0x4003'8000u}; /*!< Standard counter/timer 0 base address */
constexpr inline libmcu::FmcBaseAddress FmcAddress{0x4004'0000u};        /*!< Flash memory controller base address */
constexpr inline libmcu::IoconBaseAddress IoconAddress{0x4004'4000u};    /*!< I/O control base address */
constexpr inline libmcu::SysconBaseAddress SysconAddress{0x4004'8000u};  /*!< System control base address */
constexpr inline libmcu::I2cBaseAddress I2c0Address{0x4005'0000u};       /*!< I2C 0 base address */
constexpr inline libmcu::I2cBaseAddress I2c1Address{0x4005'4000u};       /*!< I2C 1 base address */
constexpr inline libmcu::SpiBaseAddress Spi0Address{0x4005'8000u};       /*!< SPI 0 base address */
constexpr inline libmcu::SpiBaseAddress Spi1Address{0x4005'C000u};       /*!< SPI 1 base address */
constexpr inline libmcu::CaptBaseAddress Capt0Address{0x4006'0000u};     /*!< Capacitive touch 0 base address */
constexpr inline libmcu::UartBaseAddress Usart0Address{0x4006'4000u};    /*!< USART 0 base address */
constexpr inline libmcu::UartBaseAddress Usart1Address{0x4006'8000u};    /*!< USART 1 base address */
constexpr inline libmcu::UartBaseAddress Usart2Address{0x4006'C000u};    /*!< USART 2 base address */
constexpr inline libmcu::UartBaseAddress Usart3Address{0x4007'0000u};    /*!< USART 3 base address */
/* AHB peripherals, see UM11029 2.2.1 */
constexpr inline libmcu::CrcBaseAddress CrcAddress{0x5000'0000u};  /*!< CRC calculator base address */
constexpr inline libmcu::SctBaseAddress Sct0Address{0x5000'4000u}; /*!< State configurable timer 0 base address */
constexpr inline libmcu::DmaBaseAddress DmaAddress{0x5000'8000u};  /*!< DMA 0 base address */
constexpr inline libmcu::MtbBaseAddress MtbAddress{0x5000'C000u};  /*!< MTB base address */
/* Direct connected peripherals */
constexpr inline libmcu::GpioBaseAddress GpioAddress{0xA000'0000u};     /*!< General Purpose I/O base address */
constexpr inline libmcu::PinintBaseAddress PinintAddress{0xA000'4000u}; /*!< Pin interrupt base address */
}  // namespace libmcuhw

namespace libmcuhw::dma {
/*!
 * @brief Enumeration for the DMA hardware request
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request to trigger the DMA transfer accordingly. The index of the hardware request varies according to MCU .
 */
enum class DmaRequestSources : std::uint8_t {
  Usart0Rx = 0u,    /*!< USART0 RX DMA  */
  Usart0Tx = 1u,    /*!< USART0 TX DMA  */
  Usart1Rx = 2u,    /*!< USART1 RX DMA  */
  Usart1Tx = 3u,    /*!< USART1 TX DMA  */
  Usart2Rx = 4u,    /*!< USART2 RX DMA  */
  Usart2Tx = 5u,    /*!< USART2 TX DMA  */
  Usart3Rx = 6u,    /*!< USART3 RX DMA  */
  Usart3Tx = 7u,    /*!< USART3 TX DMA  */
  Usart4Rx = 8u,    /*!< USART4 RX DMA  */
  Usart4Tx = 9u,    /*!< USART4 TX DMA  */
  Spi0Rx = 10u,     /*!< SPI0 RX DMA  */
  Spi0Tx = 11u,     /*!< SPI0 TX DMA  */
  Spi1Rx = 12u,     /*!< SPI1 RX DMA  */
  Spi1Tx = 13u,     /*!< SPI1 TX DMA  */
  I2c0Slave = 14u,  /*!< I2C0 SLAVE DMA  */
  I2c0Master = 15u, /*!< I2C0 MASTER DMA  */
  I2c1Slave = 16u,  /*!< I2C1 SLAVE DMA  */
  I2c1Master = 17u, /*!< I2C1 MASTER DMA  */
  I2c2Slave = 18u,  /*!< I2C2 SLAVE DMA  */
  I2c2Master = 19u, /*!< I2C2 MASTER DMA  */
  I2c3Slave = 20u,  /*!< I2C3 SLAVE DMA  */
  I2c3Master = 21u, /*!< I2C3 MASTER DMA  */
  Dac0 = 22u,       /*!< DAC0 DMA REQUEST  */
  Dac1 = 23u,       /*!< DAC1 DMA REQUEST  */
  Capt = 24u,       /*!< CAPT DMA  */
};
}  // namespace libmcuhw::dma

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
#include "LPC8XX_CLOCK/LPC84X_clock_hw.hpp"
#include "LPC8XX_PINS/LPC845M301BD48_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "LPC8XX_LL/LPC84X_syscon_ll.hpp"
#include "LPC8XX_LL/LPC84X_swm_ll.hpp"
#include "LPC8XX_LL/LPC84X_iocon_ll.hpp"
#include "LPC8XX_LL/LPC84X_gpio_ll.hpp"
#include "LPC8XX_LL/LPC84X_adc_ll.hpp"
#include "LPC8XX_LL/LPC84X_i2c_poll_ll.hpp"
#include "LPC8XX_LL/LPC84X_i2c_int_ll.hpp"
#include "LPC8XX_LL/LPC84X_spi_poll_ll.hpp"
#include "LPC8XX_LL/LPC84X_sct_ll.hpp"
#include "LPC8XX_LL/LPC84X_inmux_ll.hpp"
#include "LPC8XX_LL/LPC84X_dma_ll.hpp"
#include "LPC8XX_LL/LPC84X_usart_poll_ll.hpp"
#include "LPC8XX_LL/LPC84X_usart_int_ll.hpp"
#include "LPC8XX_LL/LPC84X_pin_int_ll.hpp"

#include "LPC8XX_CLOCK/LPC84X_clock.hpp"

#endif
