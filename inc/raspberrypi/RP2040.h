/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* Main entry point for the raspberry RP2040 microcontroller */
#ifndef RP2040_H
#define RP2040_H

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of the Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV 0x0001
#define __MPU_PRESENT 1
#define __FPU_PRESENT 0
#define __VTOR_PRESENT 0
#define __NVIC_PRIO_BITS 2
#define __Vendor_SysTickConfig 0

typedef enum {
  Reset_IRQn = -15,
  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  SVCall_IRQn = -5,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,
  // TODO: Interrupts
} IRQn_Type;

#include <CMSIS/core_cm0plus.h>

// TODO: Peripheral addresses

#define XIP_CTRL_BASE (0x14000000UL)
#define XIP_SSI_BASE (0x18000000UL)
#define SYSINFO_BASE (0x40000000UL)
#define SYSCFG_BASE (0x40004000UL)
#define CLOCKS_BASE (0x40008000UL)
#define RESETS_BASE (0x4000C000UL)
#define PSM_BASE (0x40010000UL)
#define IO_BANK0_BASE (0x40014000UL)
#define IO_QSPI_BASE (0x40018000UL)
#define PADS_BANK0_BASE (0x4001C000UL)
#define PADS_QSPI_BASE (0x40020000UL)
#define XOSC_BASE (0x40024000UL)
#define PLL_SYS_BASE (0x40028000UL)
#define PLL_USB_BASE (0x4002C000UL)
#define BUSCTRL_BASE (0x40030000UL)
#define UART0_BASE (0x40034000UL)
#define UART1_BASE (0x40038000UL)
#define SPI0_BASE (0x4003C000UL)
#define SPI1_BASE (0x40040000UL)
#define I2C0_BASE (0x40044000UL)
#define I2C1_BASE (0x40048000UL)
#define ADC_BASE (0x4004C000UL)
#define PWM_BASE (0x40050000UL)
#define TIMER_BASE (0x40054000UL)
#define WATCHDOG_BASE (0x40058000UL)
#define RTC_BASE (0x4005C000UL)
#define ROSC_BASE (0x40060000UL)
#define VREG_AND_CHIP_RESET_BASE (0x40064000UL)
#define TBMAN_BASE (0x4006C000UL)
#define DMA_BASE (0x50000000UL)
#define USBCTRL_DPRAM_BASE (0x50100000UL)
#define USBCTRL_REGS_BASE (0x50110000UL)
#define PIO0_BASE (0x50200000UL)
#define PIO1_BASE (0x50300000UL)
#define SIO_BASE (0xD0000000UL)
#define PPB_BASE (0xE0000000UL)

#define XIP_CTRL ((XIP_CTRL_Type *)XIP_CTRL_BASE)
#define XIP_CTRL_XOR ((XIP_CTRL_Type *)XIP_CTRL_BASE + 0x1000)
#define XIP_CTRL_SET ((XIP_CTRL_Type *)XIP_CTRL_BASE + 0x2000)
#define XIP_CTRL_CLR ((XIP_CTRL_Type *)XIP_CTRL_BASE + 0x3000)
#define XIP_SSI ((XIP_SSI_Type *)XIP_SSI_BASE)
#define XIP_SSI_XOR ((XIP_SSI_Type *)XIP_SSI_BASE + 0x1000)
#define XIP_SSI_SET ((XIP_SSI_Type *)XIP_SSI_BASE + 0x2000)
#define XIP_SSI_CLR ((XIP_SSI_Type *)XIP_SSI_BASE + 0x3000)
#define SYSINFO ((SYSINFO_Type *)SYSINFO_BASE)
// There is no sense in making a XOR,SET,CLR definition for SYSINFO
#define SYSCFG ((SYSCFG_Type *)SYSCFG_BASE)
#define SYSCFG_XOR ((SYSCFG_Type *)SYSCFG_BASE + 0x1000)
#define SYSCFG_SET ((SYSCFG_Type *)SYSCFG_BASE + 0x2000)
#define SYSCFG_CLR ((SYSCFG_Type *)SYSCFG_BASE + 0x3000)
#define CLOCKS ((CLOCKS_Type *)CLOCKS_BASE)
#define CLOCKS_XOR ((CLOCKS_Type *)CLOCKS_BASE + 0x1000)
#define CLOCKS_SET ((CLOCKS_Type *)CLOCKS_BASE + 0x2000)
#define CLOCKS_CLR ((CLOCKS_Type *)CLOCKS_BASE + 0x3000)
#define RESETS ((RESETS_Type *)RESETS_BASE)
#define RESETS_XOR ((RESETS_Type *)RESETS_BASE + 0x1000)
#define RESETS_SET ((RESETS_Type *)RESETS_BASE + 0x2000)
#define RESETS_CLR ((RESETS_Type *)RESETS_BASE + 0x3000)

#define IO_BANK0 ((IO_BANK0_Type *)IO_BANK0_BASE)
#define IO_BANK0_XOR ((IO_BANK0_Type *)IO_BANK0_BASE + 0x1000)
#define IO_BANK0_SET ((IO_BANK0_Type *)IO_BANK0_BASE + 0x2000)
#define IO_BANK0_CLR ((IO_BANK0_Type *)IO_BANK0_BASE + 0x3000)

// default configuration options, override with your own!
#include "raspberrypi/RP2040_default.h"

// Peripheral definition includes
#include "raspberrypi/xip_ctrl.h"
#include "raspberrypi/xip_ssi.h"
#include "raspberrypi/sysinfo.h"
#include "raspberrypi/syscfg.h"
#include "raspberrypi/clocks.h"
#include "raspberrypi/resets.h"
#include "raspberrypi/psm.h"
#include "raspberrypi/io_bank0.h"
#include "raspberrypi/io_qspi.h"
#include "raspberrypi/pads_bank0.h"
#include "raspberrypi/pads_qspi.h"
#include "raspberrypi/xosc.h"
#include "raspberrypi/pll_sys.h"
#include "raspberrypi/pll_usb.h"
#include "raspberrypi/busctrl.h"
#include "raspberrypi/uart.h"
#include "raspberrypi/spi.h"
#include "raspberrypi/i2c.h"
#include "raspberrypi/adc.h"
#include "raspberrypi/pwm.h"
#include "raspberrypi/timer.h"
#include "raspberrypi/watchdog.h"
#include "raspberrypi/rtc.h"
#include "raspberrypi/rosc.h"
#include "raspberrypi/vreg_and_chip_reset.h"
#include "raspberrypi/tbman.h"
#include "raspberrypi/dma.h"
#include "raspberrypi/usbctrl_dpram.h"
#include "raspberrypi/usbctrl_regs.h"
#include "raspberrypi/pio.h"
#include "raspberrypi/sio.h"
#include "raspberrypi/ppb.h"

#ifdef __cplusplus
}
#endif

#endif
