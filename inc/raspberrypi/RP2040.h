/*
 * SPDX-License-Identifier: MIT
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

/**
 * @brief Bank 0 gpios
 *
 */
typedef enum {
  BANK0_GPIO0 = (0),   /**< bank 0, pin 0 */
  BANK0_GPIO1 = (1),   /**< bank 0, pin 1 */
  BANK0_GPIO2 = (2),   /**< bank 0, pin 2 */
  BANK0_GPIO3 = (3),   /**< bank 0, pin 3 */
  BANK0_GPIO4 = (4),   /**< bank 0, pin 4 */
  BANK0_GPIO5 = (5),   /**< bank 0, pin 5 */
  BANK0_GPIO6 = (6),   /**< bank 0, pin 6 */
  BANK0_GPIO7 = (7),   /**< bank 0, pin 7 */
  BANK0_GPIO8 = (8),   /**< bank 0, pin 8 */
  BANK0_GPIO9 = (9),   /**< bank 0, pin 9 */
  BANK0_GPIO10 = (10), /**< bank 0, pin 10 */
  BANK0_GPIO11 = (11), /**< bank 0, pin 11 */
  BANK0_GPIO12 = (12), /**< bank 0, pin 12 */
  BANK0_GPIO13 = (13), /**< bank 0, pin 13 */
  BANK0_GPIO14 = (14), /**< bank 0, pin 14 */
  BANK0_GPIO15 = (15), /**< bank 0, pin 15 */
  BANK0_GPIO16 = (16), /**< bank 0, pin 16 */
  BANK0_GPIO17 = (17), /**< bank 0, pin 17 */
  BANK0_GPIO18 = (18), /**< bank 0, pin 18 */
  BANK0_GPIO19 = (19), /**< bank 0, pin 19 */
  BANK0_GPIO20 = (20), /**< bank 0, pin 20 */
  BANK0_GPIO21 = (21), /**< bank 0, pin 21 */
  BANK0_GPIO22 = (22), /**< bank 0, pin 22 */
  BANK0_GPIO23 = (23), /**< bank 0, pin 23 */
  BANK0_GPIO24 = (24), /**< bank 0, pin 24 */
  BANK0_GPIO25 = (25), /**< bank 0, pin 25 */
  BANK0_GPIO26 = (26), /**< bank 0, pin 26 */
  BANK0_GPIO27 = (27), /**< bank 0, pin 27 */
  BANK0_GPIO28 = (28), /**< bank 0, pin 28 */
  BANK0_GPIO29 = (29), /**< bank 0, pin 29 */

} BANK0_GPIO_Enum;

/**
 * @brief bank qspi gpios
 *
 */
typedef enum {
  BANK_QSPI_SCK = (0), /**< bank QSPI, pin SCK */
  BANK_QSPI_CS = (1),  /**< bank QSPI, pin CS */
  BANK_QSPI_SD0 = (2), /**< bank QSPI, pin SD0 */
  BANK_QSPI_SD1 = (3), /**< bank QSPI, pin SD1 */
  BANK_QSPI_SD2 = (4), /**< bank QSPI, pin SD2 */
  BANK_QSPI_SD3 = (5), /**< bank QSPI, pin SD3 */
} BANK_QSPI_Enum;

/**
 * @brief Bank0 gpio function selects
 *
 */
typedef enum {
  BANK0_GPIO0_FUNC_JTAG_TCK = (0),      /**< GPIO0 is JTAG TCK */
  BANK0_GPIO0_FUNC_SPI0_RX = (1),       /**< GPIO0 is SPI0 RX */
  BANK0_GPIO0_FUNC_UART0_TX = (2),      /**< GPIO0 is UART0 TX */
  BANK0_GPIO0_FUNC_I2C0_SDA = (3),      /**< GPIO0 is I2C0 SDA */
  BANK0_GPIO0_FUNC_PWM0_A = (4),        /**< GPIO0 is PWM0 A */
  BANK0_GPIO0_FUNC_SIO = (5),           /**< GPIO0 is SIO */
  BANK0_GPIO0_FUNC_PIO0 = (6),          /**< GPIO0 is PIO0 */
  BANK0_GPIO0_FUNC_PIO1 = (7),          /**< GPIO0 is PIO1 */
  BANK0_GPIO0_FUNC_USB_OVCUR_DET = (9), /**< GPIO0 is USB overcurrent detect */
  BANK0_GPIO0_FUNC_NULL = (31),         /**< GPIO0 is not connected */

  BANK0_GPIO1_FUNC_JTAG_TMS = (0),     /**< GPIO1 is JTAG TMS */
  BANK0_GPIO1_FUNC_SPI0_CS = (1),      /**< GPIO1 is SPI0 Chip select */
  BANK0_GPIO1_FUNC_UART0_RX = (2),     /**< GPIO1 is UART0 RX */
  BANK0_GPIO1_FUNC_I2C0_SCL = (3),     /**< GPIO1 is I2C0 SCL */
  BANK0_GPIO1_FUNC_PWM0_B = (4),       /**< GPIO1 is PWM0 B */
  BANK0_GPIO1_FUNC_SIO = (5),          /**< GPIO1 is SIO */
  BANK0_GPIO1_FUNC_PIO0 = (6),         /**< GPIO1 is PIO0 */
  BANK0_GPIO1_FUNC_PIO1 = (7),         /**< GPIO1 is PIO1 */
  BANK0_GPIO1_FUNC_USB_VBUS_DET = (9), /**< GPIO1 is USB VBUS detect */
  BANK0_GPIO1_FUNC_NULL = (31),        /**< GPIO1 is not connected  */

  BANK0_GPIO2_FUNC_JTAG_TDI = (0),    /**< GPIO2 is JTAG TDI */
  BANK0_GPIO2_FUNC_SPI0_SCK = (1),    /**< GPIO2 is SPI0 SCK */
  BANK0_GPIO2_FUNC_UART0_CTS = (2),   /**< GPIO2 is UART0 CTS */
  BANK0_GPIO2_FUNC_I2C1_SDA = (3),    /**< GPIO2 is I2C1 SDA */
  BANK0_GPIO2_FUNC_PWM1_A = (4),      /**< GPIO2 is PWM1 A */
  BANK0_GPIO2_FUNC_SIO = (5),         /**< GPIO2 is SIO */
  BANK0_GPIO2_FUNC_PIO0 = (6),        /**< GPIO2 is PIO0 */
  BANK0_GPIO2_FUNC_PIO1 = (7),        /**< GPIO2 is PIO1 */
  BANK0_GPIO2_FUNC_USB_VBUS_EN = (9), /**< GPIO2 is USB VBUS enable */
  BANK0_GPIO2_FUNC_NULL = (31),       /**< GPIO2 is not connected  */

  BANK0_GPIO3_FUNC_JTAG_TDO = (0),      /**< GPIO3 is JTAG TDO */
  BANK0_GPIO3_FUNC_SPI0_TX = (1),       /**< GPIO3 is SPI0 TX */
  BANK0_GPIO3_FUNC_UART0_RTS = (2),     /**< GPIO3 is UART0 RTS */
  BANK0_GPIO3_FUNC_I2C1_SCL = (3),      /**< GPIO3 is I2C1 SCL */
  BANK0_GPIO3_FUNC_PWM1_B = (4),        /**< GPIO3 is PWM1 B */
  BANK0_GPIO3_FUNC_SIO = (5),           /**< GPIO3 is SIO */
  BANK0_GPIO3_FUNC_PIO0 = (6),          /**< GPIO3 is PIO0 */
  BANK0_GPIO3_FUNC_PIO1 = (7),          /**< GPIO3 is PIO1 */
  BANK0_GPIO3_FUNC_USB_OVCUR_DET = (9), /**< GPIO3 is USB overcurrent detect */
  BANK0_GPIO3_FUNC_NULL = (31),         /**< GPIO3 is not connected  */

  BANK0_GPIO4_FUNC_SPI0_RX = (1),      /**< GPIO4 is SPI0 RX */
  BANK0_GPIO4_FUNC_UART1_TX = (2),     /**< GPIO4 is UART1 TX */
  BANK0_GPIO4_FUNC_I2C0_SDA = (3),     /**< GPIO4 is I2C0 SDA */
  BANK0_GPIO4_FUNC_PWM2_A = (4),       /**< GPIO4 is PWM2 A */
  BANK0_GPIO4_FUNC_SIO = (5),          /**< GPIO4 is SIO */
  BANK0_GPIO4_FUNC_PIO0 = (6),         /**< GPIO4 is PIO0 */
  BANK0_GPIO4_FUNC_PIO1 = (7),         /**< GPIO4 is PIO1 */
  BANK0_GPIO4_FUNC_USB_VBUS_DET = (9), /**< GPIO4 is USB VBUS detect */
  BANK0_GPIO4_FUNC_NULL = (31),        /**< GPIO4 is not connected */

  BANK0_GPIO5_FUNC_SPI0_CS = (1),     /**< GPIO5 is SPI0 Chip select */
  BANK0_GPIO5_FUNC_UART1_RX = (2),    /**< GPIO5 is UART1 RX */
  BANK0_GPIO5_FUNC_I2C0_SCL = (3),    /**< GPIO5 is I2C0 SCL */
  BANK0_GPIO5_FUNC_PWM2_B = (4),      /**< GPIO5 is PWM2 B */
  BANK0_GPIO5_FUNC_SIO = (5),         /**< GPIO5 is SIO */
  BANK0_GPIO5_FUNC_PIO0 = (6),        /**< GPIO5 is PIO0 */
  BANK0_GPIO5_FUNC_PIO1 = (7),        /**< GPIO5 is PIO1 */
  BANK0_GPIO5_FUNC_USB_VBUS_EN = (9), /**< GPIO5 is USB VBUS enable*/
  BANK0_GPIO5_FUNC_NULL = (31),       /**< GPIO5 is not connected */

  BANK0_GPIO6_FUNC_SPI0_SCK = (1),      /**< GPIO6 is SPI0 SCK */
  BANK0_GPIO6_FUNC_UART1_CTS = (2),     /**< GPIO6 is UART1 CTS */
  BANK0_GPIO6_FUNC_I2C1_SDA = (3),      /**< GPIO6 is I2C1 SDA */
  BANK0_GPIO6_FUNC_PWM3_A = (4),        /**< GPIO6 is PWM3 A */
  BANK0_GPIO6_FUNC_SIO = (5),           /**< GPIO6 is SIO */
  BANK0_GPIO6_FUNC_PIO0 = (6),          /**< GPIO6 is PIO0 */
  BANK0_GPIO6_FUNC_PIO1 = (7),          /**< GPIO6 is PIO1 */
  BANK0_GPIO6_FUNC_USB_OVCUR_DET = (9), /**< GPIO6 is USB Overcurrent detect */
  BANK0_GPIO6_FUNC_NULL = (31),         /**< GPIO6 is not connected */

  BANK0_GPIO7_FUNC_SPI0_TX = (1),      /**< GPIO7 is SPI0 TX */
  BANK0_GPIO7_FUNC_UART1_RTS = (2),    /**< GPIO7 is UART1 RTS */
  BANK0_GPIO7_FUNC_I2C1_SCL = (3),     /**< GPIO7 is I2C1 SCL */
  BANK0_GPIO7_FUNC_PWM3_B = (4),       /**< GPIO7 is PWM3 B */
  BANK0_GPIO7_FUNC_SIO = (5),          /**< GPIO7 is SIO */
  BANK0_GPIO7_FUNC_PIO0 = (6),         /**< GPIO7 is PIO0 */
  BANK0_GPIO7_FUNC_PIO1 = (7),         /**< GPIO7 is PIO1 */
  BANK0_GPIO7_FUNC_USB_VBUS_DET = (9), /**< GPIO7 is USB VBUS detect */
  BANK0_GPIO7_FUNC_NULL = (31),        /**< GPIO7 is not connected */

  BANK0_GPIO8_FUNC_SPI1_RX = (1),     /**< GPIO8 is SPI1 RX */
  BANK0_GPIO8_FUNC_UART1_TX = (2),    /**< GPIO8 is UART1 TX */
  BANK0_GPIO8_FUNC_I2C0_SDA = (3),    /**< GPIO8 is I2C0 SDA */
  BANK0_GPIO8_FUNC_PWM4_A = (4),      /**< GPIO8 is PWM4 A */
  BANK0_GPIO8_FUNC_SIO = (5),         /**< GPIO8 is SIO */
  BANK0_GPIO8_FUNC_PIO0 = (6),        /**< GPIO8 is PIO0 */
  BANK0_GPIO8_FUNC_PIO1 = (7),        /**< GPIO8 is PIO1 */
  BANK0_GPIO8_FUNC_USB_VBUS_EN = (9), /**< GPIO8 is USB VBUS enable*/
  BANK0_GPIO8_FUNC_NULL = (31),       /**< GPIO8 is not connected */

  BANK0_GPIO9_FUNC_SPI1_CS = (1),       /**< GPIO9 is SPI1 CS */
  BANK0_GPIO9_FUNC_UART1_RX = (2),      /**< GPIO9 is UART1 RX */
  BANK0_GPIO9_FUNC_I2C0_SCL = (3),      /**< GPIO9 is I2C0 SCL */
  BANK0_GPIO9_FUNC_PWM4_B = (4),        /**< GPIO9 is PWM4 B */
  BANK0_GPIO9_FUNC_SIO = (5),           /**< GPIO9 is SIO */
  BANK0_GPIO9_FUNC_PIO0 = (6),          /**< GPIO9 is PIO0 */
  BANK0_GPIO9_FUNC_PIO1 = (7),          /**< GPIO9 is PIO1 */
  BANK0_GPIO9_FUNC_USB_OVCUR_DET = (9), /**< GPIO9 is USB Overcurrent detect */
  BANK0_GPIO9_FUNC_NULL = (31),         /**< GPIO9 is not connected */

  BANK0_GPIO10_FUNC_SPI1_SCK = (1),     /**< GPIO10 is SPI1 SCK */
  BANK0_GPIO10_FUNC_UART1_CTS = (2),    /**< GPIO10 is UART1 CTS */
  BANK0_GPIO10_FUNC_I2C1_SDA = (3),     /**< GPIO10 is I2C1 SDA */
  BANK0_GPIO10_FUNC_PWM5_A = (4),       /**< GPIO10 is PWM5 A */
  BANK0_GPIO10_FUNC_SIO = (5),          /**< GPIO10 is SIO */
  BANK0_GPIO10_FUNC_PIO0 = (6),         /**< GPIO10 is PIO0 */
  BANK0_GPIO10_FUNC_PIO1 = (7),         /**< GPIO10 is PIO1 */
  BANK0_GPIO10_FUNC_USB_VBUS_DET = (9), /**< GPIO10 is USB VBUS detect*/
  BANK0_GPIO10_FUNC_NULL = (31),        /**< GPIO10 is not connected */

  BANK0_GPIO11_FUNC_SPI1_TX = (1),     /**< GPIO11 is SPI1 TX */
  BANK0_GPIO11_FUNC_UART1_RTS = (2),   /**< GPIO11 is UART1 RTS */
  BANK0_GPIO11_FUNC_I2C1_SCL = (3),    /**< GPIO11 is I2C1 SCL */
  BANK0_GPIO11_FUNC_PWM5_B = (4),      /**< GPIO11 is PWM5 B */
  BANK0_GPIO11_FUNC_SIO = (5),         /**< GPIO11 is SIO */
  BANK0_GPIO11_FUNC_PIO0 = (6),        /**< GPIO11 is PIO0 */
  BANK0_GPIO11_FUNC_PIO1 = (7),        /**< GPIO11 is PIO1 */
  BANK0_GPIO11_FUNC_USB_VBUS_EN = (9), /**< GPIO11 is VBUS enable */
  BANK0_GPIO11_FUNC_NULL = (31),       /**< GPIO11 is not connected */

  BANK0_GPIO12_FUNC_SPI1_RX = (1),         /**< GPIO12 is SPI1 RX */
  BANK0_GPIO12_FUNC_UART0_TX = (2),        /**< GPIO12 is UART0 TX */
  BANK0_GPIO12_FUNC_I2C0_SDA = (3),        /**< GPIO12 is I2C0 SDA */
  BANK0_GPIO12_FUNC_PWM6_A = (4),          /**< GPIO12 is PWM6 A */
  BANK0_GPIO12_FUNC_SIO = (5),             /**< GPIO12 is SIO */
  BANK0_GPIO12_FUNC_PIO0 = (6),            /**< GPIO12 is PIO0 */
  BANK0_GPIO12_FUNC_PIO1 = (7),            /**< GPIO12 is PIO1 */
  BANK0_GPIO12_FUNC_USB_OVERCUR_DET = (9), /**< GPIO12 is USB overcurrent detect */
  BANK0_GPIO12_FUNC_NULL = (31),           /**< GPIO12 is not connected */

  BANK0_GPIO13_FUNC_SPI1_CS = (1),      /**< GPIO13 is SPI1 CS */
  BANK0_GPIO13_FUNC_UART0_RX = (2),     /**< GPIO13 is UART0 RX */
  BANK0_GPIO13_FUNC_I2C0_SCL = (3),     /**< GPIO13 is I2C0 SCL */
  BANK0_GPIO13_FUNC_PWM6_B = (4),       /**< GPIO13 is PWM6 B */
  BANK0_GPIO13_FUNC_SIO = (5),          /**< GPIO13 is SIO */
  BANK0_GPIO13_FUNC_PIO0 = (6),         /**< GPIO13 is PIO0 */
  BANK0_GPIO13_FUNC_PIO1 = (7),         /**< GPIO13 is PIO1 */
  BANK0_GPIO13_FUNC_USB_VBUS_DET = (9), /**< GPIO13 is USB VBUS detect */
  BANK0_GPIO13_FUNC_NULL = (31),        /**< GPIO13 is not connected */

  BANK0_GPIO14_FUNC_SPI1_SCK = (1),    /**< GPIO14 is SPI1 SCK */
  BANK0_GPIO14_FUNC_UART0_CTS = (2),   /**< GPIO14 is UART0 CTS */
  BANK0_GPIO14_FUNC_I2C1_SDA = (3),    /**< GPIO14 is I2C1 SDA */
  BANK0_GPIO14_FUNC_PWM7_A = (4),      /**< GPIO14 is PWM7 A */
  BANK0_GPIO14_FUNC_SIO = (5),         /**< GPIO14 is SIO */
  BANK0_GPIO14_FUNC_PIO0 = (6),        /**< GPIO14 is PIO0 */
  BANK0_GPIO14_FUNC_PIO1 = (7),        /**< GPIO14 is PIO1 */
  BANK0_GPIO14_FUNC_USB_VBUS_EN = (9), /**< GPIO14 is VBUS enable */
  BANK0_GPIO14_FUNC_NULL = (31),       /**< GPIO14 is not connected */

  BANK0_GPIO15_FUNC_SPI1_TX = (1),       /**< GPIO15 is SPI1 TX */
  BANK0_GPIO15_FUNC_UART0_RTS = (2),     /**< GPIO15 is UART0 RTS */
  BANK0_GPIO15_FUNC_I2C1_SCL = (3),      /**< GPIO15 is I2C1 SCL */
  BANK0_GPIO15_FUNC_PWM7_B = (4),        /**< GPIO15 is PWM7 B */
  BANK0_GPIO15_FUNC_SIO = (5),           /**< GPIO15 is SIO */
  BANK0_GPIO15_FUNC_PIO0 = (6),          /**< GPIO15 is PIO0 */
  BANK0_GPIO15_FUNC_PIO1 = (7),          /**< GPIO15 is PIO1 */
  BANK0_GPIO15_FUNC_USB_OVCUR_DET = (9), /**< GPIO15 is USB overcurrent detect */
  BANK0_GPIO15_FUNC_NULL = (31),         /**< GPIO15 is not connected */

  BANK0_GPIO16_FUNC_SPI0_RX = (1),      /**< GPIO16 is SPI0 RX */
  BANK0_GPIO16_FUNC_UART0_TX = (2),     /**< GPIO16 is UART0 TX */
  BANK0_GPIO16_FUNC_I2C0_SDA = (3),     /**< GPIO16 is I2C0 SDA */
  BANK0_GPIO16_FUNC_PWM0_A = (4),       /**< GPIO16 is PWM0 A */
  BANK0_GPIO16_FUNC_SIO = (5),          /**< GPIO16 is SIO */
  BANK0_GPIO16_FUNC_PIO0 = (6),         /**< GPIO16 is PIO0 */
  BANK0_GPIO16_FUNC_PIO1 = (7),         /**< GPIO16 is PIO1 */
  BANK0_GPIO16_FUNC_USB_VBUS_DET = (9), /**< GPIO16 is USB VBUS detect */
  BANK0_GPIO16_FUNC_NULL = (31),        /**< GPIO16 is not connected */

  BANK0_GPIO17_FUNC_SPI0_CS = (1),     /**< GPIO17 is SPI0 CS */
  BANK0_GPIO17_FUNC_UART0_RX = (2),    /**< GPIO17 is UART0 RX */
  BANK0_GPIO17_FUNC_I2C0_SCL = (3),    /**< GPIO17 is I2C0 SCL */
  BANK0_GPIO17_FUNC_PWM0_B = (4),      /**< GPIO17 is PWM0 B */
  BANK0_GPIO17_FUNC_SIO = (5),         /**< GPIO17 is SIO */
  BANK0_GPIO17_FUNC_PIO0 = (6),        /**< GPIO17 is PIO0 */
  BANK0_GPIO17_FUNC_PIO1 = (7),        /**< GPIO17 is PIO1 */
  BANK0_GPIO17_FUNC_USB_VBUS_EN = (9), /**< GPIO17 is USB VBUS enable */
  BANK0_GPIO17_FUNC_NULL = (31),       /**< GPIO17 is not connected */

  BANK0_GPIO18_FUNC_SPI0_SCK = (1),      /**< GPIO18 is SPI0 SCK */
  BANK0_GPIO18_FUNC_UART0_CTS = (2),     /**< GPIO18 is UART0 CTS */
  BANK0_GPIO18_FUNC_I2C1_SDA = (3),      /**< GPIO18 is I2C1 SDA */
  BANK0_GPIO18_FUNC_PWM1_A = (4),        /**< GPIO18 is PWM1 A */
  BANK0_GPIO18_FUNC_SIO = (5),           /**< GPIO18 is SIO */
  BANK0_GPIO18_FUNC_PIO0 = (6),          /**< GPIO18 is PIO0 */
  BANK0_GPIO18_FUNC_PIO1 = (7),          /**< GPIO18 is PIO1 */
  BANK0_GPIO18_FUNC_USB_OVCUR_DET = (9), /**< GPIO18 is USB overcurrent detect */
  BANK0_GPIO18_FUNC_NULL = (31),         /**< GPIO18 is not connected */

  BANK0_GPIO19_FUNC_SPI0_TX = (1),      /**< GPIO19 is SPI0 TX */
  BANK0_GPIO19_FUNC_UART0_RTS = (2),    /**< GPIO19 is UART0 RTS */
  BANK0_GPIO19_FUNC_I2C1_SCL = (3),     /**< GPIO19 is I2C1 SCL */
  BANK0_GPIO19_FUNC_PWM1_B = (4),       /**< GPIO19 is PWM1 B */
  BANK0_GPIO19_FUNC_SIO = (5),          /**< GPIO19 is SIO */
  BANK0_GPIO19_FUNC_PIO0 = (6),         /**< GPIO19 is PIO0 */
  BANK0_GPIO19_FUNC_PIO1 = (7),         /**< GPIO19 is PIO1 */
  BANK0_GPIO19_FUNC_USB_VBUS_DET = (9), /**< GPIO19 is USB VBUS detect */
  BANK0_GPIO19_FUNC_NULL = (31),        /**< GPIO19 is not connected */

  BANK0_GPIO20_FUNC_SPI0_RX = (1),     /**< GPIO20 is SPI0 RX */
  BANK0_GPIO20_FUNC_UART1_TX = (2),    /**< GPIO20 is UART1 TX */
  BANK0_GPIO20_FUNC_I2C0_SDA = (3),    /**< GPIO20 is I2C0 SDA */
  BANK0_GPIO20_FUNC_PWM2_A = (4),      /**< GPIO20 is PWM2 A */
  BANK0_GPIO20_FUNC_SIO = (5),         /**< GPIO20 is SIO */
  BANK0_GPIO20_FUNC_PIO0 = (6),        /**< GPIO20 is PIO0 */
  BANK0_GPIO20_FUNC_PIO1 = (7),        /**< GPIO20 is PIO1 */
  BANK0_GPIO20_FUNC_CLOCK_GPIN0 = (8), /**< GPIO20 is CLOCK GPIN0 */
  BANK0_GPIO20_FUNC_USB_VBUS_EN = (9), /**< GPIO20 is USB VBUS enable*/
  BANK0_GPIO20_FUNC_NULL = (31),       /**< GPIO20 is not connected */

  BANK0_GPIO21_FUNC_SPI0_CS = (1),       /**< GPIO21 is SPI0 CS */
  BANK0_GPIO21_FUNC_UART1_RX = (2),      /**< GPIO21 is UART1 RX */
  BANK0_GPIO21_FUNC_I2C0_SCL = (3),      /**< GPIO21 is I2C0 SCL */
  BANK0_GPIO21_FUNC_PWM2_B = (4),        /**< GPIO21 is PWM2 B */
  BANK0_GPIO21_FUNC_SIO = (5),           /**< GPIO21 is SIO */
  BANK0_GPIO21_FUNC_PIO0 = (6),          /**< GPIO21 is PIO0 */
  BANK0_GPIO21_FUNC_PIO1 = (7),          /**< GPIO21 is PIO1 */
  BANK0_GPIO21_FUNC_CLOCK_GPOUT0 = (8),  /**< GPIO21 is CLOCK GPOUT0 */
  BANK0_GPIO21_FUNC_USB_OVCUR_DET = (9), /**< GPIO21 is USB overcurrent detect */
  BANK0_GPIO21_FUNC_NULL = (31),         /**< GPIO21 is not connected */

  BANK0_GPIO22_FUNC_SPI0_SCK = (1),     /**< GPIO22 is SPI0 SCK */
  BANK0_GPIO22_FUNC_UART1_CTS = (2),    /**< GPIO22 is UART1 CTS */
  BANK0_GPIO22_FUNC_I2C1_SDA = (3),     /**< GPIO22 is I2C1 SDA */
  BANK0_GPIO22_FUNC_PWM3_A = (4),       /**< GPIO22 is PWM3 A */
  BANK0_GPIO22_FUNC_SIO = (5),          /**< GPIO22 is SIO */
  BANK0_GPIO22_FUNC_PIO0 = (6),         /**< GPIO22 is PIO0 */
  BANK0_GPIO22_FUNC_PIO1 = (7),         /**< GPIO22 is PIO1 */
  BANK0_GPIO21_FUNC_CLOCK_GPIN1 = (8),  /**< GPIO22 is CLOCK GPIN1 */
  BANK0_GPIO22_FUNC_USB_VBUS_DET = (9), /**< GPIO22 is USB VBUS detect */
  BANK0_GPIO22_FUNC_NULL = (31),        /**< GPIO22 is not connected */

  BANK0_GPIO23_FUNC_SPI0_TX = (1),      /**< GPIO23 is SPI0 TX */
  BANK0_GPIO23_FUNC_UART1_RTS = (2),    /**< GPIO23 is UART1 RTS */
  BANK0_GPIO23_FUNC_I2C1_SCL = (3),     /**< GPIO23 is I2C1 SCL */
  BANK0_GPIO23_FUNC_PWM3_B = (4),       /**< GPIO23 is PWM3 B */
  BANK0_GPIO23_FUNC_SIO = (5),          /**< GPIO23 is SIO */
  BANK0_GPIO23_FUNC_PIO0 = (6),         /**< GPIO23 is PIO0 */
  BANK0_GPIO23_FUNC_PIO1 = (7),         /**< GPIO23 is PIO1 */
  BANK0_GPIO23_FUNC_CLOCK_GPOUT1 = (8), /**< GPIO23 is CLOCK GPOUT1 */
  BANK0_GPIO23_FUNC_USB_VBUS_EN = (9),  /**< GPIO23 is USB VBUS enable */
  BANK0_GPIO23_FUNC_NULL = (31),        /**< GPIO23 is not connected */

  BANK0_GPIO24_FUNC_SPI1_RX = (1),       /**< GPIO24 is SPI1 RX */
  BANK0_GPIO24_FUNC_UART1_TX = (2),      /**< GPIO24 is UART1 TX */
  BANK0_GPIO24_FUNC_I2C0_SDA = (3),      /**< GPIO24 is I2C0 SDA */
  BANK0_GPIO24_FUNC_PWM4_A = (4),        /**< GPIO24 is PWM4 A */
  BANK0_GPIO24_FUNC_SIO = (5),           /**< GPIO24 is SIO */
  BANK0_GPIO24_FUNC_PIO0 = (6),          /**< GPIO24 is PIO0 */
  BANK0_GPIO24_FUNC_PIO1 = (7),          /**< GPIO24 is PIO1 */
  BANK0_GPIO24_FUNC_CLOCK_GPOUT2 = (8),  /**< GPIO24 is CLOCK GPOUT2 */
  BANK0_GPIO24_FUNC_USB_OVCUR_DET = (9), /**< GPIO24 is USB overcurrent detect */
  BANK0_GPIO24_FUNC_NULL = (31),         /**< GPIO24 is not connected */

  BANK0_GPIO25_FUNC_SPI1_CS = (1),      /**< GPIO25 is SPI1 CS */
  BANK0_GPIO25_FUNC_UART1_RX = (2),     /**< GPIO25 is UART1 RX */
  BANK0_GPIO25_FUNC_I2C0_SCL = (3),     /**< GPIO25 is I2C0 SCL */
  BANK0_GPIO25_FUNC_PWM4_B = (4),       /**< GPIO25 is PWM4 B */
  BANK0_GPIO25_FUNC_SIO = (5),          /**< GPIO25 is SIO */
  BANK0_GPIO25_FUNC_PIO0 = (6),         /**< GPIO25 is PIO0 */
  BANK0_GPIO25_FUNC_PIO1 = (7),         /**< GPIO25 is PIO1 */
  BANK0_GPIO25_FUNC_CLOCK_GPOUT3 = (8), /**< GPIO25 is CLOCK GPOUT3 */
  BANK0_GPIO25_FUNC_USB_VBUS_DET = (9), /**< GPIO25 is USB VBUS detect */
  BANK0_GPIO25_FUNC_NULL = (31),        /**< GPIO25 is not connected */

  BANK0_GPIO26_FUNC_SPI1_SCK = (1),    /**< GPIO26 is SPI1 SCK */
  BANK0_GPIO26_FUNC_UART1_CTS = (2),   /**< GPIO26 is UART1 CTS */
  BANK0_GPIO26_FUNC_I2C1_SDA = (3),    /**< GPIO26 is I2C1 SDA */
  BANK0_GPIO26_FUNC_PWM5_A = (4),      /**< GPIO26 is PWM5 A */
  BANK0_GPIO26_FUNC_SIO = (5),         /**< GPIO26 is SIO */
  BANK0_GPIO26_FUNC_PIO0 = (6),        /**< GPIO26 is PIO0 */
  BANK0_GPIO26_FUNC_PIO1 = (7),        /**< GPIO26 is PIO1 */
  BANK0_GPIO26_FUNC_USB_VBUS_EN = (9), /**< GPIO26 is USB VBUS enable */
  BANK0_GPIO26_FUNC_NULL = (31),       /**< GPIO26 is not connected */

  BANK0_GPIO27_FUNC_SPI1_TX = (1),       /**< GPIO27 is SPI1 TX */
  BANK0_GPIO27_FUNC_UART1_RTS = (2),     /**< GPIO27 is UART1 RTS */
  BANK0_GPIO27_FUNC_I2C1_SCL = (3),      /**< GPIO27 is I2C1 SCL */
  BANK0_GPIO27_FUNC_PWM5_B = (4),        /**< GPIO27 is PWM5 B */
  BANK0_GPIO27_FUNC_SIO = (5),           /**< GPIO27 is SIO */
  BANK0_GPIO27_FUNC_PIO0 = (6),          /**< GPIO27 is PIO0 */
  BANK0_GPIO27_FUNC_PIO1 = (7),          /**< GPIO27 is PIO1 */
  BANK0_GPIO27_FUNC_USB_OVCUR_DET = (9), /**< GPIO27 is USB overcurrent detect */
  BANK0_GPIO27_FUNC_NULL = (31),         /**< GPIO27 is not connected */

  BANK0_GPIO28_FUNC_SPI1_RX = (1),      /**< GPIO28 is SPI1 RX */
  BANK0_GPIO28_FUNC_UART0_TX = (2),     /**< GPIO28 is UART0 TX */
  BANK0_GPIO28_FUNC_I2C0_SDA = (3),     /**< GPIO28 is I2C0 SDA */
  BANK0_GPIO28_FUNC_PWM6_A = (4),       /**< GPIO28 is PWM6 A */
  BANK0_GPIO28_FUNC_SIO = (5),          /**< GPIO28 is SIO */
  BANK0_GPIO28_FUNC_PIO0 = (6),         /**< GPIO28 is PIO0 */
  BANK0_GPIO28_FUNC_PIO1 = (7),         /**< GPIO28 is PIO1 */
  BANK0_GPIO28_FUNC_USB_VBUS_DET = (9), /**< GPIO28 is USB VBUS detect */
  BANK0_GPIO28_FUNC_NULL = (31),        /**< GPIO28 is not connected */

  BANK0_GPIO29_FUNC_SPI1_CS = (1),     /**< GPIO29 is SPI1 CS */
  BANK0_GPIO29_FUNC_UART0_RX = (2),    /**< GPIO29 is UART0 RX */
  BANK0_GPIO29_FUNC_I2C0_SCL = (3),    /**< GPIO29 is I2C0 SCL */
  BANK0_GPIO29_FUNC_PWM6_B = (4),      /**< GPIO29 is PWM6 B */
  BANK0_GPIO29_FUNC_SIO = (5),         /**< GPIO29 is SIO */
  BANK0_GPIO29_FUNC_PIO0 = (6),        /**< GPIO29 is PIO0 */
  BANK0_GPIO29_FUNC_PIO1 = (7),        /**< GPIO29 is PIO1 */
  BANK0_GPIO29_FUNC_USB_VBUS_EN = (9), /**< GPIO29 is USB VBUS enable */
  BANK0_GPIO29_FUNC_NULL = (31),       /**< GPIO29 is not connected */

} IO_BANK0_CTRLN_FUNCSEL_Enum;

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
