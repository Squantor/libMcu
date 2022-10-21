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
#define PSM ((PSM_Type *)PSM_BASE)
#define PSM_XOR ((PSM_Type *)PSM_BASE + 0x1000)
#define PSM_SET ((PSM_Type *)PSM_BASE + 0x2000)
#define PSM_CLR ((PSM_Type *)PSM_BASE + 0x3000)
#define IO_BANK0 ((IO_BANK0_Type *)IO_BANK0_BASE)
#define IO_BANK0_XOR ((IO_BANK0_Type *)IO_BANK0_BASE + 0x1000)
#define IO_BANK0_SET ((IO_BANK0_Type *)IO_BANK0_BASE + 0x2000)
#define IO_BANK0_CLR ((IO_BANK0_Type *)IO_BANK0_BASE + 0x3000)
#define IO_QSPI ((IO_QSPI_Type *)IO_QSPI_BASE)
#define IO_QSPI_XOR ((IO_QSPI_Type *)IO_QSPI_BASE + 0x1000)
#define IO_QSPI_SET ((IO_QSPI_Type *)IO_QSPI_BASE + 0x2000)
#define IO_QSPI_CLR ((IO_QSPI_Type *)IO_QSPI_BASE + 0x3000)
#define PADS_BANK0 ((PADS_BANK0_Type *)PADS_BANK0_BASE)
#define PADS_BANK0_XOR ((PADS_BANK0_Type *)PADS_BANK0_BASE + 0x1000)
#define PADS_BANK0_SET ((PADS_BANK0_Type *)PADS_BANK0_BASE + 0x2000)
#define PADS_BANK0_CLR ((PADS_BANK0_Type *)PADS_BANK0_BASE + 0x3000)
#define PADS_QSPI ((PADS_QSPI_Type *)PADS_QSPI_BASE)
#define PADS_QSPI_XOR ((PADS_QSPI_Type *)PADS_QSPI_BASE + 0x1000)
#define PADS_QSPI_SET ((PADS_QSPI_Type *)PADS_QSPI_BASE + 0x2000)
#define PADS_QSPI_CLR ((PADS_QSPI_Type *)PADS_QSPI_BASE + 0x3000)
#define XOSC ((XOSC_Type *)XOSC_BASE)
#define XOSC_XOR ((XOSC_Type *)XOSC_BASE + 0x1000)
#define XOSC_SET ((XOSC_Type *)XOSC_BASE + 0x2000)
#define XOSC_CLR ((XOSC_Type *)XOSC_BASE + 0x3000)
#define PLL_SYS ((PLL_SYS_Type *)PLL_SYS_BASE)
#define PLL_SYS_XOR ((PLL_SYS_Type *)PLL_SYS_BASE + 0x1000)
#define PLL_SYS_SET ((PLL_SYS_Type *)PLL_SYS_BASE + 0x2000)
#define PLL_SYS_CLR ((PLL_SYS_Type *)PLL_SYS_BASE + 0x3000)
#define PLL_USB ((PLL_USB_Type *)PLL_USB_BASE)
#define PLL_USB_XOR ((PLL_USB_Type *)PLL_USB_BASE + 0x1000)
#define PLL_USB_SET ((PLL_USB_Type *)PLL_USB_BASE + 0x2000)
#define PLL_USB_CLR ((PLL_USB_Type *)PLL_USB_BASE + 0x3000)
#define BUSCTRL ((BUSCTRL_Type *)BUSCTRL_BASE)
#define BUSCTRL_XOR ((BUSCTRL_Type *)BUSCTRL_BASE + 0x1000)
#define BUSCTRL_SET ((BUSCTRL_Type *)BUSCTRL_BASE + 0x2000)
#define BUSCTRL_CLR ((BUSCTRL_Type *)BUSCTRL_BASE + 0x3000)
#define UART0 ((UART_Type *)UART0_BASE)
#define UART0_XOR ((UART_Type *)UART0_BASE + 0x1000)
#define UART0_SET ((UART_Type *)UART0_BASE + 0x2000)
#define UART0_CLR ((UART_Type *)UART0_BASE + 0x3000)
#define UART1 ((UART_Type *)UART1_BASE)
#define UART1_XOR ((UART_Type *)UART1_BASE + 0x1000)
#define UART1_SET ((UART_Type *)UART1_BASE + 0x2000)
#define UART1_CLR ((UART_Type *)UART1_BASE + 0x3000)
#define SPI0 ((SPI_Type *)SPI0_BASE)
#define SPI0_XOR ((SPI_Type *)SPI0_BASE + 0x1000)
#define SPI0_SET ((SPI_Type *)SPI0_BASE + 0x2000)
#define SPI0_CLR ((SPI_Type *)SPI0_BASE + 0x3000)
#define SPI1 ((SPI_Type *)SPI1_BASE)
#define SPI1_XOR ((SPI_Type *)SPI1_BASE + 0x1000)
#define SPI1_SET ((SPI_Type *)SPI1_BASE + 0x2000)
#define SPI1_CLR ((SPI_Type *)SPI1_BASE + 0x3000)
#define I2C0 ((I2C_Type *)I2C0_BASE)
#define I2C0_XOR ((I2C_Type *)I2C0_BASE + 0x1000)
#define I2C0_SET ((I2C_Type *)I2C0_BASE + 0x2000)
#define I2C0_CLR ((I2C_Type *)I2C0_BASE + 0x3000)
#define I2C1 ((I2C_Type *)I2C1_BASE)
#define I2C1_XOR ((I2C_Type *)I2C1_BASE + 0x1000)
#define I2C1_SET ((I2C_Type *)I2C1_BASE + 0x2000)
#define I2C1_CLR ((I2C_Type *)I2C1_BASE + 0x3000)
#define ADC ((ADC_Type *)ADC_BASE)
#define ADC_XOR ((ADC_Type *)ADC_BASE + 0x1000)
#define ADC_SET ((ADC_Type *)ADC_BASE + 0x2000)
#define ADC_CLR ((ADC_Type *)ADC_BASE + 0x3000)
#define PWM ((PWM_Type *)PWM_BASE)
#define PWM_XOR ((PWM_Type *)PWM_BASE + 0x1000)
#define PWM_SET ((PWM_Type *)PWM_BASE + 0x2000)
#define PWM_CLR ((PWM_Type *)PWM_BASE + 0x3000)
#define TIMER ((TIMER_Type *)TIMER_BASE)
#define TIMER_XOR ((TIMER_Type *)TIMER_BASE + 0x1000)
#define TIMER_SET ((TIMER_Type *)TIMER_BASE + 0x2000)
#define TIMER_CLR ((TIMER_Type *)TIMER_BASE + 0x3000)
#define WATCHDOG ((WATCHDOG_Type *)WATCHDOG_BASE)
#define WATCHDOG_XOR ((WATCHDOG_Type *)WATCHDOG_BASE + 0x1000)
#define WATCHDOG_SET ((WATCHDOG_Type *)WATCHDOG_BASE + 0x2000)
#define WATCHDOG_CLR ((WATCHDOG_Type *)WATCHDOG_BASE + 0x3000)
#define RTC ((RTC_Type *)RTC_BASE)
#define RTC_XOR ((RTC_Type *)RTC_BASE + 0x1000)
#define RTC_SET ((RTC_Type *)RTC_BASE + 0x2000)
#define RTC_CLR ((RTC_Type *)RTC_BASE + 0x3000)
#define ROSC ((ROSC_Type *)ROSC_BASE)
#define ROSC_XOR ((ROSC_Type *)ROSC_BASE + 0x1000)
#define ROSC_SET ((ROSC_Type *)ROSC_BASE + 0x2000)
#define ROSC_CLR ((ROSC_Type *)ROSC_BASE + 0x3000)
#define VREG_AND_CHIP_RESET ((VREG_AND_CHIP_RESET_Type *)VREG_AND_CHIP_RESET_BASE)
#define VREG_AND_CHIP_RESET_XOR ((VREG_AND_CHIP_RESET_Type *)VREG_AND_CHIP_RESET_BASE + 0x1000)
#define VREG_AND_CHIP_RESET_SET ((VREG_AND_CHIP_RESET_Type *)VREG_AND_CHIP_RESET_BASE + 0x2000)
#define VREG_AND_CHIP_RESET_CLR ((VREG_AND_CHIP_RESET_Type *)VREG_AND_CHIP_RESET_BASE + 0x3000)
#define TBMAN ((TBMAN_Type *)TBMAN_BASE)
#define TBMAN_XOR ((TBMAN_Type *)TBMAN_BASE + 0x1000)
#define TBMAN_SET ((TBMAN_Type *)TBMAN_BASE + 0x2000)
#define TBMAN_CLR ((TBMAN_Type *)TBMAN_BASE + 0x3000)
#define DMA ((DMA_Type *)DMA_BASE)
#define DMA_XOR ((DMA_Type *)DMA_BASE + 0x1000)
#define DMA_SET ((DMA_Type *)DMA_BASE + 0x2000)
#define DMA_CLR ((DMA_Type *)DMA_BASE + 0x3000)
#define USBCTRL_DPRAM ((USBCTRL_DPRAM_Type *)USBCTRL_DPRAM_BASE)
#define USBCTRL_DPRAM_XOR ((USBCTRL_DPRAM_Type *)USBCTRL_DPRAM_BASE + 0x1000)
#define USBCTRL_DPRAM_SET ((USBCTRL_DPRAM_Type *)USBCTRL_DPRAM_BASE + 0x2000)
#define USBCTRL_DPRAM_CLR ((USBCTRL_DPRAM_Type *)USBCTRL_DPRAM_BASE + 0x3000)
#define USBCTRL_REGS ((USBCTRL_REGS_Type *)USBCTRL_REGS_BASE)
#define USBCTRL_REGS_XOR ((USBCTRL_REGS_Type *)USBCTRL_REGS_BASE + 0x1000)
#define USBCTRL_REGS_SET ((USBCTRL_REGS_Type *)USBCTRL_REGS_BASE + 0x2000)
#define USBCTRL_REGS_CLR ((USBCTRL_REGS_Type *)USBCTRL_REGS_BASE + 0x3000)
#define PIO0 ((PIO_Type *)PIO0_BASE)
#define PIO0_XOR ((PIO_Type *)PIO0_BASE + 0x1000)
#define PIO0_SET ((PIO_Type *)PIO0_BASE + 0x2000)
#define PIO0_CLR ((PIO_Type *)PIO0_BASE + 0x3000)
#define PIO1 ((PIO_Type *)PIO1_BASE)
#define PIO1_XOR ((PIO_Type *)PIO1_BASE + 0x1000)
#define PIO1_SET ((PIO_Type *)PIO1_BASE + 0x2000)
#define PIO1_CLR ((PIO_Type *)PIO1_BASE + 0x3000)
#define SIO ((SIO_Type *)SIO_BASE)
#define SIO_XOR ((SIO_Type *)SIO_BASE + 0x1000)
#define SIO_SET ((SIO_Type *)SIO_BASE + 0x2000)
#define SIO_CLR ((SIO_Type *)SIO_BASE + 0x3000)
#define PPB ((PPB_Type *)PPB_BASE)
#define PPB_XOR ((PPB_Type *)PPB_BASE + 0x1000)
#define PPB_SET ((PPB_Type *)PPB_BASE + 0x2000)
#define PPB_CLR ((PPB_Type *)PPB_BASE + 0x3000)

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
