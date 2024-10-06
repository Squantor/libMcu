/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for RP2040 LL include
 */
#ifndef LIBMCURP2040LL_HPP
#define LIBMCURP2040LL_HPP

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
constexpr inline bool present = true; /**< Presence of memory protection unit */
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
  timerIrq0 = 0,
  timerIrq1 = 1,
  timerIrq2 = 2,
  timerIrq3 = 3,
  pwmIrqWrap = 4,
  usbCtrl = 5,
  xip = 6,
  pio0irq0 = 7,
  pio0irq1 = 8,
  pio1irq0 = 9,
  pio1irq1 = 10,
  dmaIrq0 = 11,
  dmaIrq1 = 12,
  ioIrqBank0 = 13,
  ioIrqQspi = 14,
  sioIrqProc0 = 15,
  sioIrqProc1 = 16,
  clocks = 17,
  spi0 = 18,
  spi1 = 19,
  uart0 = 20,
  uart1 = 21,
  adcIrqFifo = 22,
  i2c0 = 23,
  i2c1 = 24,
  rtc = 26,
};
}  // namespace libMcuHw

#include <CortexM/cortex_m0plus.hpp>

namespace libMcuHw {

constexpr inline std::uint32_t peripheralOffsetNormal{0x0000'0000u}; /**< normal peripheral register access offset */
constexpr inline std::uint32_t peripheralOffsetXor{0x0000'1000u};    /**< XORed peripheral register access offset */
constexpr inline std::uint32_t peripheralOffsetSet{0x0000'2000u};    /**< Set peripheral register access offset */
constexpr inline std::uint32_t peripheralOffsetClear{0x0000'3000u};  /**< Clear peripheral register access offset */

constexpr inline libMcu::xipCtrlBaseAddress xipCtrlAddress{0x1400'0000u};             /**< XIP control base address */
constexpr inline libMcu::xipSsiBaseAddress xipSsiAddress{0x1800'0000u};               /**< XIP SSI base address */
constexpr inline libMcu::sysinfoBaseAddress sysinfoAddress{0x4000'0000u};             /**< sysinfo base address */
constexpr inline libMcu::syscfgBaseAddress syscfgAddress{0x4000'4000u};               /**< syscfg base address */
constexpr inline libMcu::clocksBaseAddress clocksAddress{0x4000'8000u};               /**< clocks base address */
constexpr inline libMcu::resetsBaseAddress resetsAddress{0x4000'C000u};               /**< resets base address */
constexpr inline libMcu::psmBaseAddress psmAddress{0x4001'0000u};                     /**< psm base address */
constexpr inline libMcu::ioBank0BaseAddress ioBank0Address{0x4001'4000u};             /**< io bank0 base address */
constexpr inline libMcu::ioQspiBaseAddress ioQspiAddress{0x4001'8000u};               /**< io qspi base address */
constexpr inline libMcu::padsBank0BaseAddress padsBank0Address{0x4001'C000u};         /**< pads bank0 base address */
constexpr inline libMcu::padsQspiBaseAddress padsQspiAddress{0x4002'0000u};           /**< pads qspi base address */
constexpr inline libMcu::xoscBaseAddress xoscAddress{0x4002'4000u};                   /**< Crystal oscillator base address */
constexpr inline libMcu::pllBaseAddress pllSysAddress{0x4002'8000u};                  /**< system PLL base address */
constexpr inline libMcu::pllBaseAddress pllUsbAddress{0x4002'C000u};                  /**< USB PLL base address */
constexpr inline libMcu::busCtrlBaseAddress busCtrlAddress{0x4003'0000u};             /**< Bus control base address */
constexpr inline libMcu::uartBaseAddress uart0Address{0x4003'4000u};                  /**< UART0 base address */
constexpr inline libMcu::uartBaseAddress uart1Address{0x4003'8000u};                  /**< UART1 base address */
constexpr inline libMcu::spiBaseAddress spi0Address{0x400'3C000u};                    /**< SPI0 base address */
constexpr inline libMcu::spiBaseAddress spi1Address{0x4004'0000u};                    /**< SPI1 base address */
constexpr inline libMcu::i2cBaseAddress i2c0Address{0x4004'4000u};                    /**< I2C0 base address */
constexpr inline libMcu::i2cBaseAddress i2c1Address{0x4004'8000u};                    /**< I2C1 base address */
constexpr inline libMcu::adcBaseAddress adcAddress{0x4004'C000u};                     /**< ADC base address */
constexpr inline libMcu::pwmBaseAddress pwmAddress{0x4005'0000u};                     /**< PWM base address */
constexpr inline libMcu::timerBaseAddress timerAddress{0x4005'4000u};                 /**< timer base address */
constexpr inline libMcu::watchdogBaseAddress watchdogAddress{0x4005'8000u};           /**< watchdog base address */
constexpr inline libMcu::rtcBaseAddress rtcAddress{0x4005'C000u};                     /**< RTC base address */
constexpr inline libMcu::roscBaseAddress roscAddress{0x4006'0000u};                   /**< ROSC base address */
constexpr inline libMcu::vregChipResetBaseAddress vregChipResetAddress{0x4006'4000u}; /**< VREG and reset base address */
constexpr inline libMcu::tbmanBaseAddress tbmanAddress{0x4006'C000u};                 /**< tbman base address */
constexpr inline libMcu::dmaBaseAddress dmaAddress{0x5000'0000u};                     /**< DMA base address */
constexpr inline libMcu::usbCtrlDPramBaseAddress usbCtrlDpRamAddress{0x5010'0000u};   /**< USB Dual port RAM base address */
constexpr inline libMcu::usbCtrlRegsBaseAddress usbCtrlRegsAddress{0x5011'0000u};     /**< USB control registers base address */
constexpr inline libMcu::pioBaseAddress pio0Address{0x5020'0000u};                    /**< PIO0 base address */
constexpr inline libMcu::pioBaseAddress pio1Address{0x5030'0000u};                    /**< PIO1 base address */
constexpr inline libMcu::sioBaseAddress sioAddress{0xD000'0000u};                     /**< SIO base address */
constexpr inline libMcu::ppbBaseAddress ppbAddress{0xE000'0000u};                     /**< PPB base address */

}  // namespace libMcuHw

// includes that define the registers namespace go here.
#include "RP2040_HW/RP2040_adc_hw.hpp"
#include "RP2040_HW/RP2040_busctrl_hw.hpp"
#include "RP2040_HW/RP2040_clocks_hw.hpp"
#include "RP2040_HW/RP2040_dma_hw.hpp"
#include "RP2040_HW/RP2040_gpio_bank0_hw.hpp"
#include "RP2040_HW/RP2040_gpio_qspi_hw.hpp"
#include "RP2040_HW/RP2040_i2c_hw.hpp"
#include "RP2040_HW/RP2040_pads_bank0_hw.hpp"
#include "RP2040_HW/RP2040_pads_qspi_hw.hpp"
#include "RP2040_HW/RP2040_pio_hw.hpp"
#include "RP2040_HW/RP2040_pll_hw.hpp"
#include "RP2040_HW/RP2040_ppb_hw.hpp"
#include "RP2040_HW/RP2040_psm_hw.hpp"
#include "RP2040_HW/RP2040_pwm_hw.hpp"
#include "RP2040_HW/RP2040_resets_hw.hpp"
#include "RP2040_HW/RP2040_rosc_hw.hpp"
#include "RP2040_HW/RP2040_rtc_hw.hpp"
#include "RP2040_HW/RP2040_sio_hw.hpp"
#include "RP2040_HW/RP2040_spi_hw.hpp"
#include "RP2040_HW/RP2040_syscfg_hw.hpp"
#include "RP2040_HW/RP2040_sysinfo_hw.hpp"
#include "RP2040_HW/RP2040_tbman_hw.hpp"
#include "RP2040_HW/RP2040_timer_hw.hpp"
#include "RP2040_HW/RP2040_uart_hw.hpp"
#include "RP2040_HW/RP2040_usbctrl_dpram_hw.hpp"
#include "RP2040_HW/RP2040_usbctrl_regs_hw.hpp"
#include "RP2040_HW/RP2040_vreg_chip_reset_hw.hpp"
#include "RP2040_HW/RP2040_watchdog_hw.hpp"
#include "RP2040_HW/RP2040_xip_ctrl_hw.hpp"
#include "RP2040_HW/RP2040_xip_ssi_hw.hpp"
#include "RP2040_HW/RP2040_xosc_hw.hpp"

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here
#include "RP2040_PINS/RP2040_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "RP2040_LL/RP2040_adc_ll.hpp"
#include "RP2040_LL/RP2040_busctrl_ll.hpp"
#include "RP2040_LL/RP2040_clocks_ll.hpp"
#include "RP2040_LL/RP2040_dma_ll.hpp"
#include "RP2040_LL/RP2040_gpio_bank0_ll.hpp"
#include "RP2040_LL/RP2040_gpio_qspi_ll.hpp"
#include "RP2040_LL/RP2040_i2c_ll.hpp"
#include "RP2040_LL/RP2040_pads_bank0_ll.hpp"
#include "RP2040_LL/RP2040_pads_qspi_ll.hpp"
#include "RP2040_LL/RP2040_pio_ll.hpp"
#include "RP2040_LL/RP2040_pll_ll.hpp"
#include "RP2040_LL/RP2040_ppb_ll.hpp"
#include "RP2040_LL/RP2040_psm_ll.hpp"
#include "RP2040_LL/RP2040_pwm_ll.hpp"
#include "RP2040_LL/RP2040_resets_ll.hpp"
#include "RP2040_LL/RP2040_rosc_ll.hpp"
#include "RP2040_LL/RP2040_rtc_ll.hpp"
#include "RP2040_LL/RP2040_sio_gpio_ll.hpp"
#include "RP2040_LL/RP2040_spi_ll.hpp"
#include "RP2040_LL/RP2040_syscfg_ll.hpp"
#include "RP2040_LL/RP2040_sysinfo_ll.hpp"
#include "RP2040_LL/RP2040_tbman_ll.hpp"
#include "RP2040_LL/RP2040_timer_ll.hpp"
#include "RP2040_LL/RP2040_uart_ll.hpp"
#include "RP2040_LL/RP2040_usbctrl_ll.hpp"
#include "RP2040_LL/RP2040_vreg_chip_reset_ll.hpp"
#include "RP2040_LL/RP2040_watchdog_ll.hpp"
#include "RP2040_LL/RP2040_xip_ctrl_ll.hpp"
#include "RP2040_LL/RP2040_xip_ssi_ll.hpp"
#include "RP2040_LL/RP2040_xosc_ll.hpp"

#endif
