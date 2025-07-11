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
#include "../libmcu/general_functions_CM0.hpp"

namespace libmcuhw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t kRevision{0x0000}; /*!< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool kPresent{false}; /*!< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool kPresent{true};                      /*!< presence of vector relocation */
constexpr inline std::uint32_t kAddressMask{0xFFFFFF00UL}; /*!< VTOR bit count */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t kVariant{0}; /*!< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t kPriorityMask{0x3}; /*!< NVIC priority bit mask */
constexpr inline std::uint32_t kPriorityBits{2};   /*!< NVIC priority bit count */
constexpr inline std::uint32_t kVectorCount{48};   /*!< amount of interrupt vectors */
}  // namespace nvic
/**
 * @brief Interrupts available for the LPC845M301BD48
 */
enum class Interrupts : std::int8_t {
  kReset = -15,       /*!< Reset interrupt */
  kNonMaskable = -14, /*!< Non maskable interrupt */
  kHardFault = -13,   /*!< Hard fault interrupt */
  kSvCall = -5,       /*!< Supervisor call interrupt */
  kPendSv = -2,       /*!< Pendable request interrupt */
  kSystick = -1,      /*!< SysTick interrupt */
  kSpi0 = 0,          /*!< SPI0 interrupt */
  kSpi1 = 1,          /*!< SPI1 interrupt */
  kDac0 = 2,          /*!< DAC0 interrupt */
  kUart0 = 3,         /*!< USART0 interrupt */
  kUart1 = 4,         /*!< USART1 interrupt */
  kUart2 = 5,         /*!< USART2 interrupt */
  kI2c1 = 7,          /*!< I2C1 interrupt */
  kI2c0 = 8,          /*!< I2C0 interrupt */
  kSct0 = 9,          /*!< State configurable timer interrupt */
  kMrt0 = 10,         /*!< Multi-rate timer interrupt */
  kAcmp0 = 11,        /*!< Analog comparator interrupt or Capacitive Touch interrupt */
  kWwdt = 12,         /*!< Windowed watchdog timer interrupt */
  kBod = 13,          /*!< BOD interrupts */
  kFlash = 14,        /*!< flash interrupt */
  kWkt = 15,          /*!< Self-wake-up timer interrupt */
  kAdc0SeqA = 16,     /*!< ADC0 sequence A completion. */
  kAdc0SeqB = 17,     /*!< ADC0 sequence B completion. */
  kAdc0ThCmp = 18,    /*!< ADC0 threshold compare and error. */
  kAdc0Ovr = 19,      /*!< ADC0 overrun */
  kDma = 20,          /*!< DMA0 interrupt */
  kI2c2 = 21,         /*!< I2C2 interrupt */
  kI2c3 = 22,         /*!< I2C3 interrupt */
  kCtimer0 = 23,      /*!< Timer interrupt */
  kPinint0 = 24,      /*!< Pin interrupt 0 or pattern match engine slice 0 interrupt */
  kPinint1 = 25,      /*!< Pin interrupt 1 or pattern match engine slice 1 interrupt */
  kPinint2 = 26,      /*!< Pin interrupt 2 or pattern match engine slice 2 interrupt */
  kPinint3 = 27,      /*!< Pin interrupt 3 or pattern match engine slice 3 interrupt */
  kPinint4 = 28,      /*!< Pin interrupt 4 or pattern match engine slice 4 interrupt */
  kPinint5Dac1 = 29,  /*!< Pin interrupt 5 or pattern match engine slice 5 interrupt or DAC1 interrupt */
  kPinint6Uart3 = 30, /*!< Pin interrupt 6 or pattern match engine slice 6 interrupt or UART3 interrupt */
  kPinint7Uart4 = 31  /*!< Pin interrupt 7 or pattern match engine slice 7 interrupt or UART4 interrupt */
};
}  // namespace libmcuhw

#include <CortexM/cortex_m0plus.hpp>

namespace libmcuhw {
/* Base addresses */
constexpr inline libmcu::MemoryAddress kFlashBaseAddress{0x0000'0000u};
constexpr inline libmcu::MemoryAddress kRamBaseAddress{0x1000'0000u};
constexpr inline libmcu::MemoryAddress kRomBaseAddress{0xF001'FF10u};
constexpr inline libmcu::MemoryAddress kApb0BaseAddress{0x4000'0000u};
constexpr inline libmcu::MemoryAddress kAhbBaseAddress{0x5000'0000u};
/* APB peripherals, see UM11029 2.2.1 */
constexpr inline libmcu::WwdtBaseAddress kWwdtAddress{0x4000'0000u};      /*!< Windowed watchdog base address */
constexpr inline libmcu::MrtBaseAddress kMrt0Address{0x4000'4000u};       /*!< Multi rate timer base address */
constexpr inline libmcu::WktBaseAddress kWktAddress{0x4000'8000u};        /*!< Wakeup timer base address */
constexpr inline libmcu::SwmBaseAddress kSwmAddress{0x4000'C000u};        /*!< Switch matrix base address */
constexpr inline libmcu::FaimBaseAddress kFaimAddress{0x4001'0000u};      /*!< Fast memory init base address */
constexpr inline libmcu::DacBaseAddress kDac0Address{0x4001'4000u};       /*!< DAC 0 base address */
constexpr inline libmcu::DacBaseAddress kDac1Address{0x4001'8000u};       /*!< DAC 1 base address */
constexpr inline libmcu::AdcBaseAddress kAdc0Address{0x4001'C000u};       /*!< ADC 0 matrix base address */
constexpr inline libmcu::PmuBaseAddress kPmuAddress{0x4002'0000u};        /*!< Power management unit base address */
constexpr inline libmcu::AcmpBaseAddress kAcmpAddress{0x4002'4000u};      /*!< Analog comparator base address */
constexpr inline libmcu::InmuxBaseAddress kInmuxAddress{0x4002'C000u};    /*!< Input multiplexer base address */
constexpr inline libmcu::I2cBaseAddress kI2c2Address{0x4003'0000u};       /*!< I2C 2 base address */
constexpr inline libmcu::I2cBaseAddress kI2c3Address{0x4003'4000u};       /*!< I2C 3 base address */
constexpr inline libmcu::CtimerBaseAddress kCtimer0Address{0x4003'8000u}; /*!< Standard counter/timer 0 base address */
constexpr inline libmcu::FmcBaseAddress kFmcAddress{0x4004'0000u};        /*!< Flash memory controller base address */
constexpr inline libmcu::IoconBaseAddress kIoconAddress{0x4004'4000u};    /*!< I/O control base address */
constexpr inline libmcu::SysconBaseAddress kSysconAddress{0x4004'8000u};  /*!< System control base address */
constexpr inline libmcu::I2cBaseAddress kI2c0Address{0x4005'0000u};       /*!< I2C 0 base address */
constexpr inline libmcu::I2cBaseAddress kI2c1Address{0x4005'4000u};       /*!< I2C 1 base address */
constexpr inline libmcu::SpiBaseAddress kSpi0Address{0x4005'8000u};       /*!< SPI 0 base address */
constexpr inline libmcu::SpiBaseAddress kSpi1Address{0x4005'C000u};       /*!< SPI 1 base address */
constexpr inline libmcu::CaptBaseAddress kCapt0Address{0x4006'0000u};     /*!< Capacitive touch 0 base address */
constexpr inline libmcu::UartBaseAddress kUsart0Address{0x4006'4000u};    /*!< USART 0 base address */
constexpr inline libmcu::UartBaseAddress kUsart1Address{0x4006'8000u};    /*!< USART 1 base address */
constexpr inline libmcu::UartBaseAddress kUsart2Address{0x4006'C000u};    /*!< USART 2 base address */
constexpr inline libmcu::UartBaseAddress kUsart3Address{0x4007'0000u};    /*!< USART 3 base address */
/* AHB peripherals, see UM11029 2.2.1 */
constexpr inline libmcu::CrcBaseAddress kCrcAddress{0x5000'0000u};  /*!< CRC calculator base address */
constexpr inline libmcu::SctBaseAddress kSct0Address{0x5000'4000u}; /*!< State configurable timer 0 base address */
constexpr inline libmcu::DmaBaseAddress kDmaAddress{0x5000'8000u};  /*!< DMA 0 base address */
constexpr inline libmcu::MtbBaseAddress kMtbAddress{0x5000'C000u};  /*!< MTB base address */
/* Direct connected peripherals */
constexpr inline libmcu::GpioBaseAddress kGpioAddress{0xA000'0000u};     /*!< General Purpose I/O base address */
constexpr inline libmcu::PinintBaseAddress kPinintAddress{0xA000'4000u}; /*!< Pin interrupt base address */
}  // namespace libmcuhw

namespace libmcuhw::dma {
/*!
 * @brief Enumeration for the DMA hardware request
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request to trigger the DMA transfer accordingly. The index of the hardware request varies according to MCU .
 */
enum class DmaRequestSources : std::uint8_t {
  kUsart0Rx = 0u,    /*!< USART0 RX DMA  */
  kUsart0Tx = 1u,    /*!< USART0 TX DMA  */
  kUsart1Rx = 2u,    /*!< USART1 RX DMA  */
  kUsart1Tx = 3u,    /*!< USART1 TX DMA  */
  kUsart2Rx = 4u,    /*!< USART2 RX DMA  */
  kUsart2Tx = 5u,    /*!< USART2 TX DMA  */
  kUsart3Rx = 6u,    /*!< USART3 RX DMA  */
  kUsart3Tx = 7u,    /*!< USART3 TX DMA  */
  kUsart4Rx = 8u,    /*!< USART4 RX DMA  */
  kUsart4Tx = 9u,    /*!< USART4 TX DMA  */
  kSpi0Rx = 10u,     /*!< SPI0 RX DMA  */
  kSpi0Tx = 11u,     /*!< SPI0 TX DMA  */
  kSpi1Rx = 12u,     /*!< SPI1 RX DMA  */
  kSpi1Tx = 13u,     /*!< SPI1 TX DMA  */
  kI2c0Slave = 14u,  /*!< I2C0 SLAVE DMA  */
  kI2c0Master = 15u, /*!< I2C0 MASTER DMA  */
  kI2c1Slave = 16u,  /*!< I2C1 SLAVE DMA  */
  kI2c1Master = 17u, /*!< I2C1 MASTER DMA  */
  kI2c2Slave = 18u,  /*!< I2C2 SLAVE DMA  */
  kI2c2Master = 19u, /*!< I2C2 MASTER DMA  */
  kI2c3Slave = 20u,  /*!< I2C3 SLAVE DMA  */
  kI2c3Master = 21u, /*!< I2C3 MASTER DMA  */
  kDac0 = 22u,       /*!< DAC0 DMA REQUEST  */
  kDac1 = 23u,       /*!< DAC1 DMA REQUEST  */
  kCapt = 24u,       /*!< CAPT DMA  */
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
#include "LPC8XX_LL/LPC84X_swm_ll.hpp"
#include "LPC8XX_LL/LPC84X_iocon_ll.hpp"
#include "LPC8XX_LL/LPC84X_syscon_ll.hpp"
#include "LPC8XX_LL/LPC84X_gpio_ll.hpp"
#include "LPC8XX_LL/LPC84X_adc_ll.hpp"
#include "LPC8XX_LL/LPC84X_i2c_poll_ll.hpp"
#include "LPC8XX_LL/LPC84X_i2c_int_ll.hpp"
#include "LPC8XX_LL/LPC84X_spi_poll_ll.hpp"
#include "LPC8XX_LL/LPC84X_sct_ll.hpp"
#include "LPC8XX_LL/LPC84X_inmux_ll.hpp"
#include "LPC8XX_LL/LPC84X_dma_ll.hpp"
#include "LPC8XX_LL/LPC84X_usart_poll_ll.hpp"

#include "LPC8XX_CLOCK/LPC84X_clock.hpp"

#endif
