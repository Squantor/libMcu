/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcu_RP2040_ll.hpp
 * @brief include for the RP2040 libmcu low level library
 */
#ifndef LIBMCURP2040LL_HPP
#define LIBMCURP2040LL_HPP

#include "../libmcu/libmcull.hpp"
#include "../libmcu/libmcu_functions_CM0.hpp"

namespace libmcuhw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t kRevision = 0x0001; /*!< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool kPresent = true; /*!< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool kPresent = true;                      /*!< presence of vector relocation */
constexpr inline std::uint32_t kAddressMask = 0xFFFFFF00UL; /*!< VTOR bit count */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t kVariant = 0; /*!< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t kPriorityMask = 0x3; /*!< NVIC priority bit mask */
constexpr inline std::uint32_t kPriorityBits = 2;   /*!< NVIC priority bit count */
}  // namespace nvic

enum class Interrupts : int8_t {
  kReset = -15,
  kNonMaskable = -14,
  kHardFault = -13,
  kSvCall = -5,
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
}  // namespace libmcuhw

#include <CortexM/cortex_m0plus.hpp>

namespace libmcuhw {

constexpr inline std::uint32_t peripheralOffsetNormal{0x0000'0000u}; /*!< normal peripheral register access offset */
constexpr inline std::uint32_t peripheralOffsetXor{0x0000'1000u};    /*!< XORed peripheral register access offset */
constexpr inline std::uint32_t peripheralOffsetSet{0x0000'2000u};    /*!< Set peripheral register access offset */
constexpr inline std::uint32_t peripheralOffsetClear{0x0000'3000u};  /*!< Clear peripheral register access offset */

constexpr inline libmcu::XipCtrlBaseAddress xipCtrlAddress{0x1400'0000u};             /*!< XIP control base address */
constexpr inline libmcu::XipSsiBaseAddress xipSsiAddress{0x1800'0000u};               /*!< XIP SSI base address */
constexpr inline libmcu::SysinfoBaseAddress sysinfoAddress{0x4000'0000u};             /*!< sysinfo base address */
constexpr inline libmcu::SyscfgBaseAddress syscfgAddress{0x4000'4000u};               /*!< syscfg base address */
constexpr inline libmcu::ClocksBaseAddress clocksAddress{0x4000'8000u};               /*!< clocks base address */
constexpr inline libmcu::ResetsBaseAddress resetsAddress{0x4000'C000u};               /*!< resets base address */
constexpr inline libmcu::PsmBaseAddress psmAddress{0x4001'0000u};                     /*!< psm base address */
constexpr inline libmcu::IoBank0BaseAddress ioBank0Address{0x4001'4000u};             /*!< io bank0 base address */
constexpr inline libmcu::IoQspiBaseAddress ioQspiAddress{0x4001'8000u};               /*!< io qspi base address */
constexpr inline libmcu::PadsBank0BaseAddress padsBank0Address{0x4001'C000u};         /*!< pads bank0 base address */
constexpr inline libmcu::PadsQspiBaseAddress padsQspiAddress{0x4002'0000u};           /*!< pads qspi base address */
constexpr inline libmcu::XoscBaseAddress xoscAddress{0x4002'4000u};                   /*!< Crystal oscillator base address */
constexpr inline libmcu::PllBaseAddress pllSysAddress{0x4002'8000u};                  /*!< system PLL base address */
constexpr inline libmcu::PllBaseAddress pllUsbAddress{0x4002'C000u};                  /*!< USB PLL base address */
constexpr inline libmcu::BusCtrlBaseAddress busCtrlAddress{0x4003'0000u};             /*!< Bus control base address */
constexpr inline libmcu::UartBaseAddress uart0Address{0x4003'4000u};                  /*!< UART0 base address */
constexpr inline libmcu::UartBaseAddress uart1Address{0x4003'8000u};                  /*!< UART1 base address */
constexpr inline libmcu::SpiBaseAddress spi0Address{0x400'3C000u};                    /*!< SPI0 base address */
constexpr inline libmcu::SpiBaseAddress spi1Address{0x4004'0000u};                    /*!< SPI1 base address */
constexpr inline libmcu::I2cBaseAddress i2c0Address{0x4004'4000u};                    /*!< I2C0 base address */
constexpr inline libmcu::I2cBaseAddress i2c1Address{0x4004'8000u};                    /*!< I2C1 base address */
constexpr inline libmcu::AdcBaseAddress adcAddress{0x4004'C000u};                     /*!< ADC base address */
constexpr inline libmcu::PwmBaseAddress pwmAddress{0x4005'0000u};                     /*!< PWM base address */
constexpr inline libmcu::TimerBaseAddress timerAddress{0x4005'4000u};                 /*!< timer base address */
constexpr inline libmcu::WatchdogBaseAddress watchdogAddress{0x4005'8000u};           /*!< watchdog base address */
constexpr inline libmcu::RtcBaseAddress rtcAddress{0x4005'C000u};                     /*!< RTC base address */
constexpr inline libmcu::RoscBaseAddress roscAddress{0x4006'0000u};                   /*!< ROSC base address */
constexpr inline libmcu::VregChipResetBaseAddress vregChipResetAddress{0x4006'4000u}; /*!< VREG and reset base address */
constexpr inline libmcu::TbmanBaseAddress tbmanAddress{0x4006'C000u};                 /*!< tbman base address */
constexpr inline libmcu::DmaBaseAddress dmaAddress{0x5000'0000u};                     /*!< DMA base address */
constexpr inline libmcu::UsbCtrlDPramBaseAddress usbCtrlDpRamAddress{0x5010'0000u};   /*!< USB Dual port RAM base address */
constexpr inline libmcu::UsbCtrlRegsBaseAddress usbCtrlRegsAddress{0x5011'0000u};     /*!< USB control registers base address */
constexpr inline libmcu::PioBaseAddress pio0Address{0x5020'0000u};                    /*!< PIO0 base address */
constexpr inline libmcu::PioBaseAddress pio1Address{0x5030'0000u};                    /*!< PIO1 base address */
constexpr inline libmcu::SioBaseAddress sioAddress{0xD000'0000u};                     /*!< SIO base address */
constexpr inline libmcu::PpbBaseAddress ppbAddress{0xE000'0000u};                     /*!< PPB base address */

}  // namespace libmcuhw

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
