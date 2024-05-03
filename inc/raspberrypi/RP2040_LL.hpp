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

constexpr inline std::uint32_t xipCtrlBase{0x1400'0000u};       /**< XIP control base address */
constexpr inline std::uint32_t xipSsiBase{0x1800'0000u};        /**< XIP SSI base address */
constexpr inline std::uint32_t sysinfoBase{0x4000'0000u};       /**< Sysinfo base address */
constexpr inline std::uint32_t syscfgBase{0x4000'4000u};        /**< System configuration base address */
constexpr inline std::uint32_t clocksBase{0x4000'8000u};        /**< clocks base address */
constexpr inline std::uint32_t resetsBase{0x4000'C000u};        /**< resets base address */
constexpr inline std::uint32_t psmBase{0x4001'0000u};           /**< PSM base address */
constexpr inline std::uint32_t gpioBank0Base{0x4001'4000u};     /**< IO bank0 base address */
constexpr inline std::uint32_t gpioQspiBase{0x4001'8000u};      /**< IO QSPI base address */
constexpr inline std::uint32_t padsBank0Base{0x4001'C000u};     /**< pads Bank0 base address */
constexpr inline std::uint32_t padsQspiBase{0x4002'0000u};      /**< pads QSPI base address */
constexpr inline std::uint32_t xoscBase{0x4002'4000u};          /**< Crystal oscillator base address */
constexpr inline std::uint32_t pllSysBase{0x4002'8000u};        /**< system PLL base address */
constexpr inline std::uint32_t pllUsbBase{0x4002'C000u};        /**< USB PLL base address */
constexpr inline std::uint32_t busctrlBase{0x4003'0000u};       /**< Bus control base address */
constexpr inline std::uint32_t uart0Base{0x4003'4000u};         /**< UART0 base address */
constexpr inline std::uint32_t uart1Base{0x4003'8000u};         /**< UART1 base address */
constexpr inline std::uint32_t spi0Base{0x400'3C000u};          /**< SPI0 base address */
constexpr inline std::uint32_t spi1Base{0x4004'0000u};          /**< SPI1 base address */
constexpr inline std::uint32_t i2c0Base{0x4004'4000u};          /**< I2C0 base address */
constexpr inline std::uint32_t i2c1Base{0x4004'8000u};          /**< I2C1 base address */
constexpr inline std::uint32_t adcBase{0x4004'C000u};           /**< ADC base address */
constexpr inline std::uint32_t pwmBase{0x4005'0000u};           /**< PWM base address */
constexpr inline std::uint32_t timerBase{0x4005'4000u};         /**< timer base address */
constexpr inline std::uint32_t watchdogBase{0x4005'8000u};      /**< watchdog base address */
constexpr inline std::uint32_t rtcBase{0x4005'C000u};           /**< RTC base address */
constexpr inline std::uint32_t roscBase{0x4006'0000u};          /**< ROSC base address */
constexpr inline std::uint32_t vregChipResetBase{0x4006'4000u}; /**< Voltage regulator and chip reset base address */
constexpr inline std::uint32_t tbmanBase{0x4006'C000u};         /**< tbman base address */
constexpr inline std::uint32_t dmaBase{0x5000'0000u};           /**< DMA base address */
constexpr inline std::uint32_t usbCtrlDPramBase{0x5010'0000u};  /**< USB Dual port RAM base address */
constexpr inline std::uint32_t usbCtrlRegsBase{0x5011'0000u};   /**< USB control registers base address */
constexpr inline std::uint32_t pio0Base{0x5020'0000u};          /**< PIO0 base address */
constexpr inline std::uint32_t pio1Base{0x5030'0000u};          /**< PIO1 base address */
constexpr inline std::uint32_t sioBase{0xD000'0000u};           /**< SIO base address */
constexpr inline std::uint32_t ppbBase{0xE000'0000u};           /**< PPB base address */

constexpr inline libMcuLL::xipCtrlBaseAddress xipCtrlAddress{xipCtrlBase + peripheralOffsetNormal};
// #define XIP_SSI ((XIP_SSI_Type *)(XIP_SSI_BASE + OFFSET_NORMAL))
// #define SYSINFO ((SYSINFO_Type *)(SYSINFO_BASE + OFFSET_NORMAL))
// #define SYSCFG ((SYSCFG_Type *)(SYSCFG_BASE + OFFSET_NORMAL))
// #define CLOCKS ((CLOCKS_Type *)(CLOCKS_BASE + OFFSET_NORMAL))
// #define RESETS ((RESETS_Type *)(RESETS_BASE + OFFSET_NORMAL))
constexpr inline libMcuLL::resetsBaseAddress resetsAddress{resetsBase + peripheralOffsetNormal};
// #define PSM ((PSM_Type *)(PSM_BASE + OFFSET_NORMAL))
// #define IO_BANK0 ((IO_BANK0_Type *)(IO_BANK0_BASE + OFFSET_NORMAL))
constexpr inline libMcuLL::ioBank0BaseAddress gpioBank0Address{gpioBank0Base + peripheralOffsetNormal};
// #define IO_QSPI ((IO_QSPI_Type *)(IO_QSPI_BASE + OFFSET_NORMAL))
// #define PADS_BANK0 ((PADS_BANK0_Type *)(PADS_BANK0_BASE + OFFSET_NORMAL))
constexpr inline libMcuLL::padsBank0BaseAddress padsBank0Address{padsBank0Base + peripheralOffsetNormal};
// #define PADS_QSPI ((PADS_QSPI_Type *)(PADS_QSPI_BASE + OFFSET_NORMAL))
// #define XOSC ((XOSC_Type *)(XOSC_BASE + OFFSET_NORMAL))
// #define PLL_SYS ((PLL_Type *)(PLL_SYS_BASE + OFFSET_NORMAL))
// #define PLL_USB ((PLL_Type *)(PLL_USB_BASE + OFFSET_NORMAL))
// #define BUSCTRL ((BUSCTRL_Type *)(BUSCTRL_BASE + OFFSET_NORMAL))
// #define UART0 ((UART_Type *)(UART0_BASE + OFFSET_NORMAL))
// #define UART1 ((UART_Type *)(UART1_BASE + OFFSET_NORMAL))
// #define SPI0 ((SPI_Type *)(SPI0_BASE + OFFSET_NORMAL))
// #define SPI1 ((SPI_Type *)(SPI1_BASE + OFFSET_NORMAL))
// #define I2C0 ((I2C_Type *)(I2C0_BASE + OFFSET_NORMAL))
// #define I2C1 ((I2C_Type *)(I2C1_BASE + OFFSET_NORMAL))
// #define ADC ((ADC_Type *)(ADC_BASE + OFFSET_NORMAL))
// #define PWM ((PWM_Type *)(PWM_BASE + OFFSET_NORMAL))
// #define TIMER ((TIMER_Type *)(TIMER_BASE + OFFSET_NORMAL))
// #define WATCHDOG ((WATCHDOG_Type *)(WATCHDOG_BASE + OFFSET_NORMAL))
// #define RTC ((RTC_Type *)(RTC_BASE + OFFSET_NORMAL))
// #define ROSC ((ROSC_Type *)(ROSC_BASE + OFFSET_NORMAL))
// #define VREG_AND_CHIP_RESET ((VREG_AND_CHIP_RESET_Type *)(VREG_AND_CHIP_RESET_BASE + OFFSET_NORMAL))
// #define TBMAN ((TBMAN_Type *)(TBMAN_BASE + OFFSET_NORMAL))
// #define DMA ((DMA_Type *)(DMA_BASE + OFFSET_NORMAL))
// #define USBCTRL_DPRAM ((USBCTRL_DPRAM_Type *)(USBCTRL_DPRAM_BASE + OFFSET_NORMAL))
// #define USBCTRL_REGS ((USBCTRL_REGS_Type *)(USBCTRL_REGS_BASE + OFFSET_NORMAL))
// #define PIO0 ((PIO_Type *)(PIO0_BASE + OFFSET_NORMAL))
// #define PIO1 ((PIO_Type *)(PIO1_BASE + OFFSET_NORMAL))
// #define SIO ((SIO_Type *)(SIO_BASE + OFFSET_NORMAL))
constexpr inline libMcuLL::sioBaseAddress sioAddress{sioBase + peripheralOffsetNormal};
// #define PPB ((PPB_Type *)(PPB_BASE + OFFSET_NORMAL))

}  // namespace hw
}  // namespace libMcuLL

#ifdef __cplusplus
extern "C" {
#endif

// default configuration options, override with your own!
// #include "RP2040_default.h"

// Peripheral definition includes
// #include "xip_ctrl.h"
// #include "xip_ssi.h"
// #include "sysinfo.h"
// #include "syscfg.h"
// #include "clocks.h"
// #include "resets.h"
// #include "psm.h"
// #include "io_bank0.h"
// #include "io_qspi.h"
// #include "pads_bank0.h"
// #include "pads_qspi.h"
// #include "xosc.h"
// #include "pll.h"
// #include "busctrl.h"
// #include "uart.h"
// #include "spi.h"
// #include "i2c.h"
// #include "adc.h"
// #include "pwm.h"
// #include "timer.h"
// #include "watchdog.h"
// #include "rtc.h"
// #include "rosc.h"
// #include "vreg_and_chip_reset.h"
// #include "tbman.h"
// #include "dma.h"
// #include "usbctrl_dpram.h"
// #include "usbctrl_regs.h"
// #include "pio.h"
// #include "raspberrypi/peripherals.h/sio.h"
// #include "ppb.h"

#ifdef __cplusplus
}
#endif

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

#endif
