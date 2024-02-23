/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the LPC812M101DH20 microcontroller definitions */
#ifndef LPC812M101DH20_HPP
#define LPC812M101DH20_HPP

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
}  // namespace hw
}  // namespace libMcuLL

#include <CortexM/cortex_m0plus.hpp>

namespace libMcuLL {
namespace hw {

// Define peripheral addresses on APB0 bus
// rename these when full c++ functionality is finished, remove _cpp postfix
constexpr inline libMcuLL::WWDTbaseAddress wwdtAddress{0x4000'0000u};     /**< Windowed watchdog base address */
constexpr inline libMcuLL::MRTbaseAddress mrtAddress{0x4000'4000u};       /**< multi rate timer base address */
constexpr inline libMcuLL::WKTbaseAddress wktAddress{0x4000'8000u};       /**< wakeup timer base address */
constexpr inline libMcuLL::SWMbaseAddress swmAddress{0x4000'C000u};       /**< Switch matrix base address */
constexpr inline libMcuLL::PMUbaseAddress pmuAddress{0x4002'0000u};       /**< Power management unit base address */
constexpr inline libMcuLL::ACMPbaseAddress acmpAddress{0x4002'4000u};     /**< Analog comparator base address */
constexpr inline libMcuLL::FMCbaseAddress fmcAddress{0x4004'0000u};       /**< Flash memory controller base address */
constexpr inline libMcuLL::IOCONbaseAddress ioconAddress{0x4004'4000u};   /**< I/O control base address */
constexpr inline libMcuLL::SYSCONbaseAddress sysconAddress{0x4004'8000u}; /**< System control base address */
constexpr inline libMcuLL::I2CbaseAddress i2c0Address{0x4005'0000u};      /**< I2C 0 base address */
constexpr inline libMcuLL::SPIbaseAddress spi0Address{0x4005'8000u};      /**< SPI 0 base address */
constexpr inline libMcuLL::SPIbaseAddress spi1Address{0x4005'C000u};      /**< SPI 1 base address */
constexpr inline libMcuLL::USARTbaseAddress usart0Address{0x4006'4000u};  /**< USART 0 base address */
constexpr inline libMcuLL::USARTbaseAddress usart1Address{0x4006'8000u};  /**< USART 1 base address */
constexpr inline libMcuLL::USARTbaseAddress usart2Address{0x4006'C000u};  /**< USART 2 base address */

/* AHB peripherals */
constexpr inline libMcuLL::CRCbaseAddress crcAddress{0x5000'0000u}; /**< CRC calculator base address */
constexpr inline libMcuLL::SCTbaseAddress sctAddress{0x5000'4000u}; /**< State configurable timer 0 base address */

/* Direct connected peripherals */
constexpr inline libMcuLL::GPIObaseAddress gpioAddress{0xA000'0000u};     /**< General Purpose I/O base address */
constexpr inline libMcuLL::PININTbaseAddress pinintAddress{0xA000'4000u}; /**< Pin interrupt base address */

}  // namespace hw
}  // namespace libMcuLL

// includes that define the registers namespace go here.
#include "LPC8XX.hpp/LPC81X_iocon_hw.hpp"
#include "LPC8XX.hpp/LPC81X_swm_hw.hpp"
#include "LPC8XX.hpp/LPC81X_gpio_hw.hpp"
#include "LPC8XX.hpp/LPC81X_spi_hw.hpp"
#include "LPC8XX.hpp/LPC81X_acmp_hw.hpp"
#include "LPC8XX.hpp/LPC81X_crc_hw.hpp"
#include "LPC8XX.hpp/LPC81X_fmc_hw.hpp"
#include "LPC8XX.hpp/LPC81X_i2c_hw.hpp"
#include "LPC8XX.hpp/LPC81X_mrt_hw.hpp"
#include "LPC8XX.hpp/LPC81X_pin_int_hw.hpp"
#include "LPC8XX.hpp/LPC81X_pmu_hw.hpp"
#include "LPC8XX.hpp/LPC81X_sct_hw.hpp"
#include "LPC8XX.hpp/LPC81X_syscon_hw.hpp"
#include "LPC8XX.hpp/LPC81X_usart_hw.hpp"
#include "LPC8XX.hpp/LPC81X_wkt_hw.hpp"
#include "LPC8XX.hpp/LPC81X_wwdt_hw.hpp"

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here
#include "LPC8XX.hpp/LPC812M101DH20_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "LPC8XX.hpp/LPC81X_iocon_sw.hpp"
#include "LPC8XX.hpp/LPC81X_swm_sw.hpp"
#include "LPC8XX.hpp/LPC81X_gpio_sw.hpp"
#include "LPC8XX.hpp/LPC81X_spi_sw_sync.hpp"
#include "LPC8XX.hpp/LPC81X_spi_sw_async.hpp"
#include "LPC8XX.hpp/LPC81X_acmp_sw.hpp"
#include "LPC8XX.hpp/LPC81X_crc_sw.hpp"
#include "LPC8XX.hpp/LPC81X_fmc_sw.hpp"
#include "LPC8XX.hpp/LPC81X_i2c_sw.hpp"
#include "LPC8XX.hpp/LPC81X_mrt_sw.hpp"
#include "LPC8XX.hpp/LPC81X_pin_int_sw.hpp"
#include "LPC8XX.hpp/LPC81X_pmu_sw.hpp"
#include "LPC8XX.hpp/LPC81X_sct_sw.hpp"
#include "LPC8XX.hpp/LPC81X_syscon_sw.hpp"
#include "LPC8XX.hpp/LPC81X_usart_sw_sync.hpp"
#include "LPC8XX.hpp/LPC81X_usart_sw_async.hpp"
#include "LPC8XX.hpp/LPC81X_wkt_sw.hpp"
#include "LPC8XX.hpp/LPC81X_wwdt_sw.hpp"

#endif