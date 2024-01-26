/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the LPC812M101DH20 microcontroller definitions */
#ifndef LPC812M101DH20_HPP
#define LPC812M101DH20_HPP

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV 0x0001
#define __MPU_PRESENT 0
#define __VTOR_PRESENT 1
#define __NVIC_PRIO_BITS 2
#define __Vendor_SysTickConfig 0

typedef enum {
  Reset_IRQn = -15,
  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  SVCall_IRQn = -5,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,
  SPI0_IRQn = 0,
  SPI1_IRQn = 1,
  Reserved0_IRQn = 2,
  UART0_IRQn = 3,
  UART1_IRQn = 4,
  UART2_IRQn = 5,
  Reserved1_IRQn = 6,
  Reserved2_IRQn = 7,
  I2C0_IRQn = 8,
  SCT_IRQn = 9,
  MRT_IRQn = 10,
  CMP_IRQn = 11,
  WDT_IRQn = 12,
  BOD_IRQn = 13,
  Reserved3_IRQn = 14,
  WKT_IRQn = 15,
  Reserved4_IRQn = 16,
  Reserved5_IRQn = 17,
  Reserved6_IRQn = 18,
  Reserved7_IRQn = 19,
  Reserved8_IRQn = 20,
  Reserved9_IRQn = 21,
  Reserved10_IRQn = 22,
  Reserved11_IRQn = 23,
  PININT0_IRQn = 24,
  PININT1_IRQn = 25,
  PININT2_IRQn = 26,
  PININT3_IRQn = 27,
  PININT4_IRQn = 28,
  PININT5_IRQn = 29,
  PININT6_IRQn = 30,
  PININT7_IRQn = 31,
} IRQn_Type;

#include <CMSIS/core_cm0plus.h>

#ifdef __cplusplus
}
#endif

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
constexpr inline libMcuLL::CRCbaseAddress CRC_cpp{0x5000'0000u};  /**< CRC calculator base address */
constexpr inline libMcuLL::SCTbaseAddress SCT0_cpp{0x5000'4000u}; /**< State configurable timer 0 base address */

/* Direct connected peripherals */
constexpr inline libMcuLL::GPIObaseAddress GPIO_cpp{0xA000'0000u};      /**< General Purpose I/O base address */
constexpr inline libMcuLL::PININTbaseAddress PIN_INT_cpp{0xA000'4000u}; /**< Pin interrupt base address */

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