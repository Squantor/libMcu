/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcu_LPC812M101DH20_ll.hpp
 * @brief include for the LPC812M101DH20 libmcu low level library
 */
#ifndef LIBMCU_LPC812M101DH20_LL_HPP
#define LIBMCU_LPC812M101DH20_LL_HPP

#include "../libmcu/libmcull.hpp"
#include "../libmcu/functions_CM0.hpp"

namespace libmcuhw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t Revision{0x0001}; /*!< Revision number */
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
}  // namespace nvic

enum class Interrupts : int8_t {
  Reset = -15,
  NonMaskable = -14,
  HardFault = -13,
  SvCall = -5,
  PendSv = -2,
  Systick = -1,
  Spi0 = 0,
  Spi1 = 1,
  Uart0 = 3,
  Uart1 = 4,
  Uart2 = 5,
  I2c0 = 8,
  Sct = 9,
  Mrt = 10,
  Acmp = 11,
  Wwdt = 12,
  Bod = 13,
  Wkt = 15,
  Pinint0 = 24,
  PinInt1 = 25,
  PinInt2 = 26,
  PinInt3 = 27,
  PinInt4 = 28,
  PinInt5 = 29,
  PinInt6 = 30,
  PinInt7 = 31,
};
}  // namespace libmcuhw

#include <CortexM/cortex_m0plus.hpp>

namespace libmcuhw {
// Define peripheral addresses on APB0 bus
constexpr inline libmcu::WwdtBaseAddress WwdtAddress{0x4000'0000u};     /*!< Windowed watchdog base address */
constexpr inline libmcu::MrtBaseAddress MrtAddress{0x4000'4000u};       /*!< multi rate timer base address */
constexpr inline libmcu::WktBaseAddress WktAddress{0x4000'8000u};       /*!< wakeup timer base address */
constexpr inline libmcu::SwmBaseAddress SwmAddress{0x4000'C000u};       /*!< Switch matrix base address */
constexpr inline libmcu::PmuBaseAddress PmuAddress{0x4002'0000u};       /*!< Power management unit base address */
constexpr inline libmcu::AcmpBaseAddress AcmpAddress{0x4002'4000u};     /*!< Analog comparator base address */
constexpr inline libmcu::FmcBaseAddress FmcAddress{0x4004'0000u};       /*!< Flash memory controller base address */
constexpr inline libmcu::IoconBaseAddress IoconAddress{0x4004'4000u};   /*!< I/O control base address */
constexpr inline libmcu::SysconBaseAddress SysconAddress{0x4004'8000u}; /*!< System control base address */
constexpr inline libmcu::I2cBaseAddress I2c0Address{0x4005'0000u};      /*!< I2C 0 base address */
constexpr inline libmcu::SpiBaseAddress Spi0Address{0x4005'8000u};      /*!< SPI 0 base address */
constexpr inline libmcu::SpiBaseAddress Spi1Address{0x4005'C000u};      /*!< SPI 1 base address */
constexpr inline libmcu::UartBaseAddress Usart0Address{0x4006'4000u};   /*!< USART 0 base address */
constexpr inline libmcu::UartBaseAddress Usart1Address{0x4006'8000u};   /*!< USART 1 base address */
constexpr inline libmcu::UartBaseAddress Usart2Address{0x4006'C000u};   /*!< USART 2 base address */
/* AHB peripherals */
constexpr inline libmcu::CrcBaseAddress CrcAddress{0x5000'0000u}; /*!< CRC calculator base address */
constexpr inline libmcu::SctBaseAddress SctAddress{0x5000'4000u}; /*!< State configurable timer 0 base address */
/* Direct connected peripherals */
constexpr inline libmcu::GpioBaseAddress GpioAddress{0xA000'0000u};     /*!< General Purpose I/O base address */
constexpr inline libmcu::PinintBaseAddress PinintAddress{0xA000'4000u}; /*!< Pin interrupt base address */
}  // namespace libmcuhw

// includes that define the registers namespace go here.
#include "LPC8XX_HW/LPC81X_iocon_hw.hpp"
#include "LPC8XX_HW/LPC81X_swm_hw.hpp"
#include "LPC8XX_HW/LPC81X_gpio_hw.hpp"
#include "LPC8XX_HW/LPC81X_spi_hw.hpp"
#include "LPC8XX_HW/LPC81X_acmp_hw.hpp"
#include "LPC8XX_HW/LPC81X_crc_hw.hpp"
#include "LPC8XX_HW/LPC81X_fmc_hw.hpp"
#include "LPC8XX_HW/LPC81X_i2c_hw.hpp"
#include "LPC8XX_HW/LPC81X_mrt_hw.hpp"
#include "LPC8XX_HW/LPC81X_pin_int_hw.hpp"
#include "LPC8XX_HW/LPC81X_pmu_hw.hpp"
#include "LPC8XX_HW/LPC81X_sct_hw.hpp"
#include "LPC8XX_HW/LPC81X_syscon_hw.hpp"
#include "LPC8XX_HW/LPC81X_usart_hw.hpp"
#include "LPC8XX_HW/LPC81X_wkt_hw.hpp"
#include "LPC8XX_HW/LPC81X_wwdt_hw.hpp"

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here
#include "LPC8XX_PINS/LPC812M101DH20_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "LPC8XX_LL/LPC81X_iocon_ll.hpp"
#include "LPC8XX_LL/LPC81X_swm_ll.hpp"
#include "LPC8XX_LL/LPC81X_gpio_ll.hpp"
#include "LPC8XX_LL/LPC81X_spi_poll_ll.hpp"
#include "LPC8XX_LL/LPC81X_spi_async_ll.hpp"
#include "LPC8XX_LL/LPC81X_acmp_ll.hpp"
#include "LPC8XX_LL/LPC81X_crc_ll.hpp"
#include "LPC8XX_LL/LPC81X_fmc_ll.hpp"
#include "LPC8XX_LL/LPC81X_i2c_poll_ll.hpp"
#include "LPC8XX_LL/LPC81X_mrt_ll.hpp"
#include "LPC8XX_LL/LPC81X_pin_int_ll.hpp"
#include "LPC8XX_LL/LPC81X_pmu_ll.hpp"
#include "LPC8XX_LL/LPC81X_sct_ll.hpp"
#include "LPC8XX_LL/LPC81X_syscon_ll.hpp"
#include "LPC8XX_LL/LPC81X_usart_poll_ll.hpp"
#include "LPC8XX_LL/LPC81X_usart_async_ll.hpp"  //! @todo refactor to interrupt based async uart
#include "LPC8XX_LL/LPC81X_wkt_ll.hpp"
#include "LPC8XX_LL/LPC81X_wwdt_ll.hpp"

#endif