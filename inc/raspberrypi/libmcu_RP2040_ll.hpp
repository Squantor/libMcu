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
#include "../libmcu/general_functions_CM0.hpp"
#include "detail/RP2040_LL_types.hpp"
#include "detail/RP2040_LL_concepts.hpp"

namespace libmcuhw {

// MCU configuration options
namespace core {
constexpr inline std::uint32_t Revision = 0x0001; /*!< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool Present = true; /*!< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool Present = true;                      /*!< presence of vector relocation */
constexpr inline std::uint32_t AddressMask = 0xFFFFFF00UL; /*!< VTOR bit count */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t Variant = 0; /*!< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t PriorityMask = 0x3; /*!< NVIC priority bit mask */
constexpr inline std::uint32_t PriorityBits = 2;   /*!< NVIC priority bit count */
}  // namespace nvic

enum class Interrupts : int8_t {
  Reset = -15,
  NonMaskable = -14,
  HardFault = -13,
  SvCall = -5,
  PendSv = -2,
  Systick = -1,
  TimerIrq0 = 0,
  TimerIrq1 = 1,
  TimerIrq2 = 2,
  TimerIrq3 = 3,
  PwmIrqWrap = 4,
  UsbCtrl = 5,
  Xip = 6,
  Pio0irq0 = 7,
  Pio0irq1 = 8,
  Pio1irq0 = 9,
  Pio1irq1 = 10,
  DmaIrq0 = 11,
  DmaIrq1 = 12,
  IoIrqBank0 = 13,
  IoIrqQspi = 14,
  SioIrqProc0 = 15,
  SioIrqProc1 = 16,
  Clocks = 17,
  Spi0 = 18,
  Spi1 = 19,
  Uart0 = 20,
  Uart1 = 21,
  AdcIrqFifo = 22,
  I2c0 = 23,
  I2c1 = 24,
  Rtc = 26,
};
}  // namespace libmcuhw

#include <CortexM/cortex_m0plus.hpp>

namespace libmcuhw {

constexpr inline std::uint32_t PeripheralOffsetNormal{0x0000'0000u}; /*!< normal peripheral register access offset */
constexpr inline std::uint32_t PeripheralOffsetXor{0x0000'1000u};    /*!< XORed peripheral register access offset */
constexpr inline std::uint32_t PeripheralOffsetSet{0x0000'2000u};    /*!< Set peripheral register access offset */
constexpr inline std::uint32_t PeripheralOffsetClear{0x0000'3000u};  /*!< Clear peripheral register access offset */

constexpr inline libmcu::XipCtrlBaseAddress XipCtrlAddress{0x1400'0000u};             /*!< XIP control base address */
constexpr inline libmcu::XipSsiBaseAddress XipSsiAddress{0x1800'0000u};               /*!< XIP SSI base address */
constexpr inline libmcu::SysinfoBaseAddress SysinfoAddress{0x4000'0000u};             /*!< sysinfo base address */
constexpr inline libmcu::SyscfgBaseAddress SyscfgAddress{0x4000'4000u};               /*!< syscfg base address */
constexpr inline libmcu::ClocksBaseAddress ClocksAddress{0x4000'8000u};               /*!< clocks base address */
constexpr inline libmcu::ResetsBaseAddress ResetsAddress{0x4000'C000u};               /*!< resets base address */
constexpr inline libmcu::PsmBaseAddress PsmAddress{0x4001'0000u};                     /*!< psm base address */
constexpr inline libmcu::IoBank0BaseAddress IoBank0Address{0x4001'4000u};             /*!< io bank0 base address */
constexpr inline libmcu::IoQspiBaseAddress IoQspiAddress{0x4001'8000u};               /*!< io qspi base address */
constexpr inline libmcu::PadsBank0BaseAddress PadsBank0Address{0x4001'C000u};         /*!< pads bank0 base address */
constexpr inline libmcu::PadsQspiBaseAddress PadsQspiAddress{0x4002'0000u};           /*!< pads qspi base address */
constexpr inline libmcu::XoscBaseAddress XoscAddress{0x4002'4000u};                   /*!< Crystal oscillator base address */
constexpr inline libmcu::PllBaseAddress PllSysAddress{0x4002'8000u};                  /*!< system PLL base address */
constexpr inline libmcu::PllBaseAddress PllUsbAddress{0x4002'C000u};                  /*!< USB PLL base address */
constexpr inline libmcu::BusCtrlBaseAddress BusCtrlAddress{0x4003'0000u};             /*!< Bus control base address */
constexpr inline libmcu::UartBaseAddress Uart0Address{0x4003'4000u};                  /*!< UART0 base address */
constexpr inline libmcu::UartBaseAddress Uart1Address{0x4003'8000u};                  /*!< UART1 base address */
constexpr inline libmcu::SpiBaseAddress Spi0Address{0x400'3C000u};                    /*!< SPI0 base address */
constexpr inline libmcu::SpiBaseAddress Spi1Address{0x4004'0000u};                    /*!< SPI1 base address */
constexpr inline libmcu::I2cBaseAddress I2c0Address{0x4004'4000u};                    /*!< I2C0 base address */
constexpr inline libmcu::I2cBaseAddress I2c1Address{0x4004'8000u};                    /*!< I2C1 base address */
constexpr inline libmcu::AdcBaseAddress AdcAddress{0x4004'C000u};                     /*!< ADC base address */
constexpr inline libmcu::PwmBaseAddress PwmAddress{0x4005'0000u};                     /*!< PWM base address */
constexpr inline libmcu::TimerBaseAddress TimerAddress{0x4005'4000u};                 /*!< timer base address */
constexpr inline libmcu::WatchdogBaseAddress WatchdogAddress{0x4005'8000u};           /*!< watchdog base address */
constexpr inline libmcu::RtcBaseAddress RtcAddress{0x4005'C000u};                     /*!< RTC base address */
constexpr inline libmcu::RoscBaseAddress RoscAddress{0x4006'0000u};                   /*!< ROSC base address */
constexpr inline libmcu::VregChipResetBaseAddress VregChipResetAddress{0x4006'4000u}; /*!< VREG and reset base address */
constexpr inline libmcu::TbmanBaseAddress TbmanAddress{0x4006'C000u};                 /*!< tbman base address */
constexpr inline libmcu::DmaBaseAddress DmaAddress{0x5000'0000u};                     /*!< DMA base address */
constexpr inline libmcu::UsbCtrlDPramBaseAddress UsbCtrlDpRamAddress{0x5010'0000u};   /*!< USB Dual port RAM base address */
constexpr inline libmcu::UsbCtrlRegsBaseAddress UsbCtrlRegsAddress{0x5011'0000u};     /*!< USB control registers base address */
constexpr inline libmcu::PioBaseAddress Pio0Address{0x5020'0000u};                    /*!< PIO0 base address */
constexpr inline libmcu::PioBaseAddress Pio1Address{0x5030'0000u};                    /*!< PIO1 base address */
constexpr inline libmcu::SioBaseAddress SioAddress{0xD000'0000u};                     /*!< SIO base address */
constexpr inline libmcu::PpbBaseAddress PpbAddress{0xE000'0000u};                     /*!< PPB base address */

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
#include "RP2040_LL/RP2040_i2c_poll_ll.hpp"
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
#include "RP2040_LL/RP2040_spi_poll_ll.hpp"
#include "RP2040_LL/RP2040_syscfg_ll.hpp"
#include "RP2040_LL/RP2040_sysinfo_ll.hpp"
#include "RP2040_LL/RP2040_tbman_ll.hpp"
#include "RP2040_LL/RP2040_timer_ll.hpp"
#include "RP2040_LL/RP2040_uart_poll_ll.hpp"
#include "RP2040_LL/RP2040_usbctrl_ll.hpp"
#include "RP2040_LL/RP2040_vreg_chip_reset_ll.hpp"
#include "RP2040_LL/RP2040_watchdog_ll.hpp"
#include "RP2040_LL/RP2040_xip_ctrl_ll.hpp"
#include "RP2040_LL/RP2040_xip_ssi_ll.hpp"
#include "RP2040_LL/RP2040_xosc_ll.hpp"

#endif
