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
#include "../libmcu/libmcu_functions_CM0.hpp"

namespace libmcuhw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t kRevision{0x0001}; /*!< Revision number */
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
}  // namespace nvic

enum class Interrupts : int8_t {
  kReset = -15,
  kNonMaskable = -14,
  kHardFault = -13,
  kSvCall = -5,
  kPendSv = -2,
  kSystick = -1,
  kSpi0 = 0,
  kSpi1 = 1,
  kUart0 = 3,
  kUart1 = 4,
  kUart2 = 5,
  kI2c0 = 8,
  kSct = 9,
  kMrt = 10,
  kAcmp = 11,
  kWwdt = 12,
  kBod = 13,
  kWkt = 15,
  kPinint0 = 24,
  kPinInt1 = 25,
  kPinInt2 = 26,
  kPinInt3 = 27,
  kPinInt4 = 28,
  kPinInt5 = 29,
  kPinInt6 = 30,
  kPinInt7 = 31,
};
}  // namespace libmcuhw

#include <CortexM/cortex_m0plus.hpp>

namespace libmcuhw {
// Define peripheral addresses on APB0 bus
constexpr inline libmcu::WwdtBaseAddress kWwdtAddress{0x4000'0000u};     /*!< Windowed watchdog base address */
constexpr inline libmcu::MrtBaseAddress kMrtAddress{0x4000'4000u};       /*!< multi rate timer base address */
constexpr inline libmcu::WktBaseAddress kWktAddress{0x4000'8000u};       /*!< wakeup timer base address */
constexpr inline libmcu::SwmBaseAddress kSwmAddress{0x4000'C000u};       /*!< Switch matrix base address */
constexpr inline libmcu::PmuBaseAddress kPmuAddress{0x4002'0000u};       /*!< Power management unit base address */
constexpr inline libmcu::AcmpBaseAddress kAcmpAddress{0x4002'4000u};     /*!< Analog comparator base address */
constexpr inline libmcu::FmcBaseAddress kFmcAddress{0x4004'0000u};       /*!< Flash memory controller base address */
constexpr inline libmcu::IoconBaseAddress kIoconAddress{0x4004'4000u};   /*!< I/O control base address */
constexpr inline libmcu::SysconBaseAddress kSysconAddress{0x4004'8000u}; /*!< System control base address */
constexpr inline libmcu::I2cBaseAddress kI2c0Address{0x4005'0000u};      /*!< I2C 0 base address */
constexpr inline libmcu::SpiBaseAddress kSpi0Address{0x4005'8000u};      /*!< SPI 0 base address */
constexpr inline libmcu::SpiBaseAddress kSpi1Address{0x4005'C000u};      /*!< SPI 1 base address */
constexpr inline libmcu::UartBaseAddress kUsart0Address{0x4006'4000u};   /*!< USART 0 base address */
constexpr inline libmcu::UartBaseAddress kUsart1Address{0x4006'8000u};   /*!< USART 1 base address */
constexpr inline libmcu::UartBaseAddress kUsart2Address{0x4006'C000u};   /*!< USART 2 base address */
/* AHB peripherals */
constexpr inline libmcu::CrcBaseAddress kCrcAddress{0x5000'0000u}; /*!< CRC calculator base address */
constexpr inline libmcu::SctBaseAddress kSctAddress{0x5000'4000u}; /*!< State configurable timer 0 base address */
/* Direct connected peripherals */
constexpr inline libmcu::GpioBaseAddress kGpioAddress{0xA000'0000u};     /*!< General Purpose I/O base address */
constexpr inline libmcu::PinintBaseAddress kPinintAddress{0xA000'4000u}; /*!< Pin interrupt base address */
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
#include "LPC8XX_LL/LPC81X_spi_ll_polled.hpp"
#include "LPC8XX_LL/LPC81X_spi_ll_async.hpp"
#include "LPC8XX_LL/LPC81X_acmp_ll.hpp"
#include "LPC8XX_LL/LPC81X_crc_ll.hpp"
#include "LPC8XX_LL/LPC81X_fmc_ll.hpp"
#include "LPC8XX_LL/LPC81X_i2c_ll.hpp"
#include "LPC8XX_LL/LPC81X_mrt_ll.hpp"
#include "LPC8XX_LL/LPC81X_pin_int_ll.hpp"
#include "LPC8XX_LL/LPC81X_pmu_ll.hpp"
#include "LPC8XX_LL/LPC81X_sct_ll.hpp"
#include "LPC8XX_LL/LPC81X_syscon_ll.hpp"
#include "LPC8XX_LL/LPC81X_usart_ll_sync.hpp"
#include "LPC8XX_LL/LPC81X_usart_ll_async.hpp"
#include "LPC8XX_LL/LPC81X_wkt_ll.hpp"
#include "LPC8XX_LL/LPC81X_wwdt_ll.hpp"

#endif