/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the LPC812M101DH20 microcontroller definitions */
#ifndef LIBMCU_LPC812M101DH20_LL_HPP
#define LIBMCU_LPC812M101DH20_LL_HPP

#include <cstdint>
#include <cstddef>
#include <array>
#include <span>
#include <type_traits>
#include <limits>
#include "../libmcu/libmcu_results.hpp"
#include "../libmcu/libmcu_types.hpp"
#include "../libmcu/libmcu_functions.hpp"
#include "../libmcu/libmcull_types.hpp"
#include "../libmcu/ringbuffer.hpp"

namespace libMcuHw {

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
}  // namespace nvic

enum class interrupts : int8_t {
  reset = -15,
  nonMaskable = -14,
  hardFault = -13,
  svCall = -5,
  pendSv = -2,
  systick = -1,
  spi0 = 0,
  spi1 = 1,
  uart0 = 3,
  uart1 = 4,
  uart2 = 5,
  i2c0 = 8,
  sct = 9,
  mrt = 10,
  acmp = 11,
  wwdt = 12,
  bod = 13,
  wkt = 15,
  pinint0 = 24,
  PININT1 = 25,
  PININT2 = 26,
  PININT3 = 27,
  PININT4 = 28,
  PININT5 = 29,
  PININT6 = 30,
  PININT7 = 31,
};
}  // namespace libMcuHw

#include <CortexM/cortex_m0plus.hpp>

namespace libMcuHw {
// Define peripheral addresses on APB0 bus
// rename these when full c++ functionality is finished, remove _cpp postfix
constexpr inline libMcu::wwdtBaseAddress wwdtAddress{0x4000'0000u};     /**< Windowed watchdog base address */
constexpr inline libMcu::mrtBaseAddress mrtAddress{0x4000'4000u};       /**< multi rate timer base address */
constexpr inline libMcu::wktBaseAddress wktAddress{0x4000'8000u};       /**< wakeup timer base address */
constexpr inline libMcu::swmBaseAddress swmAddress{0x4000'C000u};       /**< Switch matrix base address */
constexpr inline libMcu::pmuBaseAddress pmuAddress{0x4002'0000u};       /**< Power management unit base address */
constexpr inline libMcu::acmpBaseAddress acmpAddress{0x4002'4000u};     /**< Analog comparator base address */
constexpr inline libMcu::fmcBaseAddress fmcAddress{0x4004'0000u};       /**< Flash memory controller base address */
constexpr inline libMcu::ioconBaseAddress ioconAddress{0x4004'4000u};   /**< I/O control base address */
constexpr inline libMcu::sysconBaseAddress sysconAddress{0x4004'8000u}; /**< System control base address */
constexpr inline libMcu::i2cBaseAddress i2c0Address{0x4005'0000u};      /**< I2C 0 base address */
constexpr inline libMcu::spiBaseAddress spi0Address{0x4005'8000u};      /**< SPI 0 base address */
constexpr inline libMcu::spiBaseAddress spi1Address{0x4005'C000u};      /**< SPI 1 base address */
constexpr inline libMcu::uartBaseAddress usart0Address{0x4006'4000u};   /**< USART 0 base address */
constexpr inline libMcu::uartBaseAddress usart1Address{0x4006'8000u};   /**< USART 1 base address */
constexpr inline libMcu::uartBaseAddress usart2Address{0x4006'C000u};   /**< USART 2 base address */
/* AHB peripherals */
constexpr inline libMcu::crcBaseAddress crcAddress{0x5000'0000u}; /**< CRC calculator base address */
constexpr inline libMcu::sctBaseAddress sctAddress{0x5000'4000u}; /**< State configurable timer 0 base address */
/* Direct connected peripherals */
constexpr inline libMcu::gpioBaseAddress gpioAddress{0xA000'0000u};     /**< General Purpose I/O base address */
constexpr inline libMcu::pinintBaseAddress pinintAddress{0xA000'4000u}; /**< Pin interrupt base address */
}  // namespace libMcuHw

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
#include "LPC8XX_LL/LPC81X_spi_ll_sync.hpp"
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