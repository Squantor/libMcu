/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for the raspberry RP2040 Low level microcontroller definitions
 */
#ifndef RP2040_LL_HPP
#define RP2040_LL_HPP

namespace libMcuLL {
namespace hw {

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
}  // namespace hw
}  // namespace libMcuLL

#include <CortexM/cortex_m0plus.hpp>

namespace libMcuLL {
namespace hw {

constexpr inline std::uint32_t peripheralOffsetNormal{0x0000'0000u}; /**< normal peripheral register access offset */
constexpr inline std::uint32_t peripheralOffsetXor{0x0000'1000u};    /**< XORed peripheral register access offset */
constexpr inline std::uint32_t peripheralOffsetSet{0x0000'2000u};    /**< Set peripheral register access offset */
constexpr inline std::uint32_t peripheralOffsetClear{0x0000'3000u};  /**< Clear peripheral register access offset */

constexpr inline libMcuLL::xipCtrlBaseAddress xipCtrlAddress{0x1400'0000u};             /**< XIP control base address */
constexpr inline libMcuLL::xipSsiBaseAddress xipSsiAddress{0x1800'0000u};               /**< XIP SSI base address */
constexpr inline libMcuLL::sysinfoBaseAddress sysinfoAddress{0x4000'0000u};             /**< sysinfo base address */
constexpr inline libMcuLL::syscfgBaseAddress syscfgAddress{0x4000'4000u};               /**< syscfg base address */
constexpr inline libMcuLL::clocksBaseAddress clocksAddress{0x4000'8000u};               /**< clocks base address */
constexpr inline libMcuLL::resetsBaseAddress resetsAddress{0x4000'C000u};               /**< resets base address */
constexpr inline libMcuLL::psmBaseAddress psmAddress{0x4001'0000u};                     /**< psm base address */
constexpr inline libMcuLL::ioBank0BaseAddress ioBank0Address{0x4001'4000u};             /**< io bank0 base address */
constexpr inline libMcuLL::ioQspiBaseAddress ioQspiAddress{0x4001'8000u};               /**< io qspi base address */
constexpr inline libMcuLL::padsBank0BaseAddress padsBank0Address{0x4001'C000u};         /**< pads bank0 base address */
constexpr inline libMcuLL::padsQspiBaseAddress padsQspiAddress{0x4002'0000u};           /**< pads qspi base address */
constexpr inline libMcuLL::xoscBaseAddress xoscAddress{0x4002'4000u};                   /**< Crystal oscillator base address */
constexpr inline libMcuLL::pllBaseAddress pllSysAddress{0x4002'8000u};                  /**< system PLL base address */
constexpr inline libMcuLL::pllBaseAddress pllUsbAddress{0x4002'C000u};                  /**< USB PLL base address */
constexpr inline libMcuLL::busCtrlBaseAddress busCtrlAddress{0x4003'0000u};             /**< Bus control base address */
constexpr inline libMcuLL::uartBaseAddress uart0Address{0x4003'4000u};                  /**< UART0 base address */
constexpr inline libMcuLL::uartBaseAddress uart1Address{0x4003'8000u};                  /**< UART1 base address */
constexpr inline libMcuLL::spiBaseAddress spi0Address{0x400'3C000u};                    /**< SPI0 base address */
constexpr inline libMcuLL::spiBaseAddress spi1Address{0x4004'0000u};                    /**< SPI1 base address */
constexpr inline libMcuLL::i2cBaseAddress i2c0Address{0x4004'4000u};                    /**< I2C0 base address */
constexpr inline libMcuLL::i2cBaseAddress i2c1Address{0x4004'8000u};                    /**< I2C1 base address */
constexpr inline libMcuLL::adcBaseAddress adcAddress{0x4004'C000u};                     /**< ADC base address */
constexpr inline libMcuLL::pwmBaseAddress pwmAddress{0x4005'0000u};                     /**< PWM base address */
constexpr inline libMcuLL::timerBaseAddress timerAddress{0x4005'4000u};                 /**< timer base address */
constexpr inline libMcuLL::watchdogBaseAddress watchdogAddress{0x4005'8000u};           /**< watchdog base address */
constexpr inline libMcuLL::rtcBaseAddress rtcAddress{0x4005'C000u};                     /**< RTC base address */
constexpr inline libMcuLL::roscBaseAddress roscAddress{0x4006'0000u};                   /**< ROSC base address */
constexpr inline libMcuLL::vregChipResetBaseAddress vregChipResetAddress{0x4006'4000u}; /**< VREG and reset base address */
constexpr inline libMcuLL::tbmanBaseAddress tbmanAddress{0x4006'C000u};                 /**< tbman base address */
constexpr inline libMcuLL::dmaBaseAddress dmaAddress{0x5000'0000u};                     /**< DMA base address */
constexpr inline libMcuLL::usbCtrlDPramBaseAddress usbCtrlDpRamAddress{0x5010'0000u};   /**< USB Dual port RAM base address */
constexpr inline libMcuLL::usbCtrlRegsBaseAddress usbCtrlRegsAddress{0x5011'0000u};     /**< USB control registers base address */
constexpr inline libMcuLL::pioBaseAddress pio0Address{0x5020'0000u};                    /**< PIO0 base address */
constexpr inline libMcuLL::pioBaseAddress pio1Address{0x5030'0000u};                    /**< PIO1 base address */
constexpr inline libMcuLL::sioBaseAddress sioAddress{0xD000'0000u};                     /**< SIO base address */
constexpr inline libMcuLL::ppbBaseAddress ppbAddress{0xE000'0000u};                     /**< PPB base address */

}  // namespace hw
}  // namespace libMcuLL

// includes that define the registers namespace go here.
#include "raspberrypi/peripherals.hpp/RP2040_adc_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_busctrl_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_clocks_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_dma_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_gpio_bank0_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_gpio_qspi_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_i2c_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pads_bank0_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pads_qspi_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pio_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pll_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_ppb_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_psm_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pwm_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_resets_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_rosc_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_rtc_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_sio_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_spi_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_syscfg_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_sysinfo_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_tbman_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_timer_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_uart_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_usbctrl_dpram_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_usbctrl_regs_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_vreg_chip_reset_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_watchdog_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_xip_ctrl_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_xip_ssi_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_xosc_hw.hpp"

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here
#include "RP2040_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "raspberrypi/peripherals.hpp/RP2040_adc_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_busctrl_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_clocks_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_dma_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_gpio_bank0_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_gpio_qspi_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_i2c_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pads_bank0_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pads_qspi_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pio_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pll_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_ppb_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_psm_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_pwm_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_resets_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_rosc_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_rtc_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_sio_gpio_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_spi_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_syscfg_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_sysinfo_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_tbman_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_timer_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_uart_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_usbctrl_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_vreg_chip_reset_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_watchdog_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_xip_ctrl_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_xip_ssi_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_xosc_sw.hpp"

namespace libMcuLL {

// predefined peripheral types
using padsBank0PeripheralType = sw::padsBank0::padsBank0<hw::padsBank0Address>;
using gpioBank0PeripheralType = sw::gpioBank0::gpioBank0<hw::ioBank0Address>;
using resetsPeripheralType = sw::resets::resets<hw::resetsAddress>;
using sioGpioPeripheralType = sw::sioGpio::sioGpio<hw::sioAddress>;
using uart0PeripheralType = sw::uart::uart<hw::uart0Address>;
using uart1PeripheralType = sw::uart::uart<hw::uart1Address>;
using spi0PeripheralType = sw::spi::spi<hw::spi0Address>;
using spi1PeripheralType = sw::spi::spi<hw::spi1Address>;
using i2c0PeripheralType = sw::i2c::i2c<hw::i2c0Address>;
using i2c1PeripheralType = sw::i2c::i2c<hw::i2c1Address>;

}  // namespace libMcuLL

#endif
