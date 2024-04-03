/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for the raspberry RP2040 microcontroller definitions
 */
#ifndef RP2040_HPP
#define RP2040_HPP

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
constexpr inline std::uint32_t ioBank0Base{0x4001'4000u};       /**< IO bank0 base address */
constexpr inline std::uint32_t ioQspiBase{0x4001'8000u};        /**< IO QSPI base address */
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

constexpr inline libMcuLL::WWDTbaseAddress wwdtAddress{0x4000'0000u}; /**< Windowed watchdog base address */
constexpr inline libMcuLL::xipCtrlBaseAddress xipCtrlAddress{xipCtrlBase + peripheralOffsetNormal};
constexpr inline libMcuLL::xipCtrlBaseAddress xipCtrlXorAddress{xipCtrlBase + peripheralOffsetXor};
constexpr inline libMcuLL::xipCtrlBaseAddress xipCtrlSetAddress{xipCtrlBase + peripheralOffsetSet};
constexpr inline libMcuLL::xipCtrlBaseAddress xipCtrlClrAddress{xipCtrlBase + peripheralOffsetClear};
// #define XIP_SSI ((XIP_SSI_Type *)(XIP_SSI_BASE + OFFSET_NORMAL))
// #define XIP_SSI_XOR ((XIP_SSI_Type *)(XIP_SSI_BASE + OFFSET_XOR))
// #define XIP_SSI_SET ((XIP_SSI_Type *)(XIP_SSI_BASE + OFFSET_SET))
// #define XIP_SSI_CLR ((XIP_SSI_Type *)(XIP_SSI_BASE + OFFSET_CLR))
// #define SYSINFO ((SYSINFO_Type *)(SYSINFO_BASE + OFFSET_NORMAL))
// #define SYSCFG ((SYSCFG_Type *)(SYSCFG_BASE + OFFSET_NORMAL))
// #define SYSCFG_XOR ((SYSCFG_Type *)(SYSCFG_BASE + OFFSET_XOR))
// #define SYSCFG_SET ((SYSCFG_Type *)(SYSCFG_BASE + OFFSET_SET))
// #define SYSCFG_CLR ((SYSCFG_Type *)(SYSCFG_BASE + OFFSET_CLR))
// #define CLOCKS ((CLOCKS_Type *)(CLOCKS_BASE + OFFSET_NORMAL))
// #define CLOCKS_XOR ((CLOCKS_Type *)(CLOCKS_BASE + OFFSET_XOR))
// #define CLOCKS_SET ((CLOCKS_Type *)(CLOCKS_BASE + OFFSET_SET))
// #define CLOCKS_CLR ((CLOCKS_Type *)(CLOCKS_BASE + OFFSET_CLR))
// #define RESETS ((RESETS_Type *)(RESETS_BASE + OFFSET_NORMAL))
// #define RESETS_XOR ((RESETS_Type *)(RESETS_BASE + OFFSET_XOR))
// #define RESETS_SET ((RESETS_Type *)(RESETS_BASE + OFFSET_SET))
// #define RESETS_CLR ((RESETS_Type *)(RESETS_BASE + OFFSET_CLR))
// #define PSM ((PSM_Type *)(PSM_BASE + OFFSET_NORMAL))
// #define PSM_XOR ((PSM_Type *)(PSM_BASE + OFFSET_XOR))
// #define PSM_SET ((PSM_Type *)(PSM_BASE + OFFSET_SET))
// #define PSM_CLR ((PSM_Type *)(PSM_BASE + OFFSET_CLR))
// #define IO_BANK0 ((IO_BANK0_Type *)(IO_BANK0_BASE + OFFSET_NORMAL))
// #define IO_BANK0_XOR ((IO_BANK0_Type *)(IO_BANK0_BASE + OFFSET_XOR))
// #define IO_BANK0_SET ((IO_BANK0_Type *)(IO_BANK0_BASE + OFFSET_SET))
// #define IO_BANK0_CLR ((IO_BANK0_Type *)(IO_BANK0_BASE + OFFSET_CLR))
// #define IO_QSPI ((IO_QSPI_Type *)(IO_QSPI_BASE + OFFSET_NORMAL))
// #define IO_QSPI_XOR ((IO_QSPI_Type *)(IO_QSPI_BASE + OFFSET_XOR))
// #define IO_QSPI_SET ((IO_QSPI_Type *)(IO_QSPI_BASE + OFFSET_SET))
// #define IO_QSPI_CLR ((IO_QSPI_Type *)(IO_QSPI_BASE + OFFSET_CLR))
// #define PADS_BANK0 ((PADS_BANK0_Type *)(PADS_BANK0_BASE + OFFSET_NORMAL))
// #define PADS_BANK0_XOR ((PADS_BANK0_Type *)(PADS_BANK0_BASE + OFFSET_XOR))
// #define PADS_BANK0_SET ((PADS_BANK0_Type *)(PADS_BANK0_BASE + OFFSET_SET))
// #define PADS_BANK0_CLR ((PADS_BANK0_Type *)(PADS_BANK0_BASE + OFFSET_CLR))
// #define PADS_QSPI ((PADS_QSPI_Type *)(PADS_QSPI_BASE + OFFSET_NORMAL))
// #define PADS_QSPI_XOR ((PADS_QSPI_Type *)(PADS_QSPI_BASE + OFFSET_XOR))
// #define PADS_QSPI_SET ((PADS_QSPI_Type *)(PADS_QSPI_BASE + OFFSET_SET))
// #define PADS_QSPI_CLR ((PADS_QSPI_Type *)(PADS_QSPI_BASE + OFFSET_CLR))
// #define XOSC ((XOSC_Type *)(XOSC_BASE + OFFSET_NORMAL))
// #define XOSC_XOR ((XOSC_Type *)(XOSC_BASE + OFFSET_XOR))
// #define XOSC_SET ((XOSC_Type *)(XOSC_BASE + OFFSET_SET))
// #define XOSC_CLR ((XOSC_Type *)(XOSC_BASE + OFFSET_CLR))
// #define PLL_SYS ((PLL_Type *)(PLL_SYS_BASE + OFFSET_NORMAL))
// #define PLL_SYS_XOR ((PLL_Type *)(PLL_SYS_BASE + OFFSET_XOR))
// #define PLL_SYS_SET ((PLL_Type *)(PLL_SYS_BASE + OFFSET_SET))
// #define PLL_SYS_CLR ((PLL_Type *)(PLL_SYS_BASE + OFFSET_CLR))
// #define PLL_USB ((PLL_Type *)(PLL_USB_BASE + OFFSET_NORMAL))
// #define PLL_USB_XOR ((PLL_Type *)(PLL_USB_BASE + OFFSET_XOR))
// #define PLL_USB_SET ((PLL_Type *)(PLL_USB_BASE + OFFSET_SET))
// #define PLL_USB_CLR ((PLL_Type *)(PLL_USB_BASE + OFFSET_CLR))
// #define BUSCTRL ((BUSCTRL_Type *)(BUSCTRL_BASE + OFFSET_NORMAL))
// #define BUSCTRL_XOR ((BUSCTRL_Type *)(BUSCTRL_BASE + OFFSET_XOR))
// #define BUSCTRL_SET ((BUSCTRL_Type *)(BUSCTRL_BASE + OFFSET_SET))
// #define BUSCTRL_CLR ((BUSCTRL_Type *)(BUSCTRL_BASE + OFFSET_CLR))
// #define UART0 ((UART_Type *)(UART0_BASE + OFFSET_NORMAL))
// #define UART0_XOR ((UART_Type *)(UART0_BASE + OFFSET_XOR))
// #define UART0_SET ((UART_Type *)(UART0_BASE + OFFSET_SET))
// #define UART0_CLR ((UART_Type *)(UART0_BASE + OFFSET_CLR))
// #define UART1 ((UART_Type *)(UART1_BASE + OFFSET_NORMAL))
// #define UART1_XOR ((UART_Type *)(UART1_BASE + OFFSET_XOR))
// #define UART1_SET ((UART_Type *)(UART1_BASE + OFFSET_SET))
// #define UART1_CLR ((UART_Type *)(UART1_BASE + OFFSET_CLR))
// #define SPI0 ((SPI_Type *)(SPI0_BASE + OFFSET_NORMAL))
// #define SPI0_XOR ((SPI_Type *)(SPI0_BASE + OFFSET_XOR))
// #define SPI0_SET ((SPI_Type *)(SPI0_BASE + OFFSET_SET))
// #define SPI0_CLR ((SPI_Type *)(SPI0_BASE + OFFSET_CLR))
// #define SPI1 ((SPI_Type *)(SPI1_BASE + OFFSET_NORMAL))
// #define SPI1_XOR ((SPI_Type *)(SPI1_BASE + OFFSET_XOR))
// #define SPI1_SET ((SPI_Type *)(SPI1_BASE + OFFSET_SET))
// #define SPI1_CLR ((SPI_Type *)(SPI1_BASE + OFFSET_CLR))
// #define I2C0 ((I2C_Type *)(I2C0_BASE + OFFSET_NORMAL))
// #define I2C0_XOR ((I2C_Type *)(I2C0_BASE + OFFSET_XOR))
// #define I2C0_SET ((I2C_Type *)(I2C0_BASE + OFFSET_SET))
// #define I2C0_CLR ((I2C_Type *)(I2C0_BASE + OFFSET_CLR))
// #define I2C1 ((I2C_Type *)(I2C1_BASE + OFFSET_NORMAL))
// #define I2C1_XOR ((I2C_Type *)(I2C1_BASE + OFFSET_XOR))
// #define I2C1_SET ((I2C_Type *)(I2C1_BASE + OFFSET_SET))
// #define I2C1_CLR ((I2C_Type *)(I2C1_BASE + OFFSET_CLR))
// #define ADC ((ADC_Type *)(ADC_BASE + OFFSET_NORMAL))
// #define ADC_XOR ((ADC_Type *)(ADC_BASE + OFFSET_XOR))
// #define ADC_SET ((ADC_Type *)(ADC_BASE + OFFSET_SET))
// #define ADC_CLR ((ADC_Type *)(ADC_BASE + OFFSET_CLR))
// #define PWM ((PWM_Type *)(PWM_BASE + OFFSET_NORMAL))
// #define PWM_XOR ((PWM_Type *)(PWM_BASE + OFFSET_XOR))
// #define PWM_SET ((PWM_Type *)(PWM_BASE + OFFSET_SET))
// #define PWM_CLR ((PWM_Type *)(PWM_BASE + OFFSET_CLR))
// #define TIMER ((TIMER_Type *)(TIMER_BASE + OFFSET_NORMAL))
// #define TIMER_XOR ((TIMER_Type *)(TIMER_BASE + OFFSET_XOR))
// #define TIMER_SET ((TIMER_Type *)(TIMER_BASE + OFFSET_SET))
// #define TIMER_CLR ((TIMER_Type *)(TIMER_BASE + OFFSET_CLR))
// #define WATCHDOG ((WATCHDOG_Type *)(WATCHDOG_BASE + OFFSET_NORMAL))
// #define WATCHDOG_XOR ((WATCHDOG_Type *)(WATCHDOG_BASE + OFFSET_XOR))
// #define WATCHDOG_SET ((WATCHDOG_Type *)(WATCHDOG_BASE + OFFSET_SET))
// #define WATCHDOG_CLR ((WATCHDOG_Type *)(WATCHDOG_BASE + OFFSET_CLR))
// #define RTC ((RTC_Type *)(RTC_BASE + OFFSET_NORMAL))
// #define RTC_XOR ((RTC_Type *)(RTC_BASE + OFFSET_XOR))
// #define RTC_SET ((RTC_Type *)(RTC_BASE + OFFSET_SET))
// #define RTC_CLR ((RTC_Type *)(RTC_BASE + OFFSET_CLR))
// #define ROSC ((ROSC_Type *)(ROSC_BASE + OFFSET_NORMAL))
// #define ROSC_XOR ((ROSC_Type *)(ROSC_BASE + OFFSET_XOR))
// #define ROSC_SET ((ROSC_Type *)(ROSC_BASE + OFFSET_SET))
// #define ROSC_CLR ((ROSC_Type *)(ROSC_BASE + OFFSET_CLR))
// #define VREG_AND_CHIP_RESET ((VREG_AND_CHIP_RESET_Type *)(VREG_AND_CHIP_RESET_BASE + OFFSET_NORMAL))
// #define VREG_AND_CHIP_RESET_XOR ((VREG_AND_CHIP_RESET_Type *)(VREG_AND_CHIP_RESET_BASE + OFFSET_XOR))
// #define VREG_AND_CHIP_RESET_SET ((VREG_AND_CHIP_RESET_Type *)(VREG_AND_CHIP_RESET_BASE + OFFSET_SET))
// #define VREG_AND_CHIP_RESET_CLR ((VREG_AND_CHIP_RESET_Type *)(VREG_AND_CHIP_RESET_BASE + OFFSET_CLR))
// #define TBMAN ((TBMAN_Type *)(TBMAN_BASE + OFFSET_NORMAL))
// #define TBMAN_XOR ((TBMAN_Type *)(TBMAN_BASE + OFFSET_XOR))
// #define TBMAN_SET ((TBMAN_Type *)(TBMAN_BASE + OFFSET_SET))
// #define TBMAN_CLR ((TBMAN_Type *)(TBMAN_BASE + OFFSET_CLR))
// #define DMA ((DMA_Type *)(DMA_BASE + OFFSET_NORMAL))
// #define DMA_XOR ((DMA_Type *)(DMA_BASE + OFFSET_XOR))
// #define DMA_SET ((DMA_Type *)(DMA_BASE + OFFSET_SET))
// #define DMA_CLR ((DMA_Type *)(DMA_BASE + OFFSET_CLR))
// #define USBCTRL_DPRAM ((USBCTRL_DPRAM_Type *)(USBCTRL_DPRAM_BASE + OFFSET_NORMAL))
// #define USBCTRL_DPRAM_XOR ((USBCTRL_DPRAM_Type *)(USBCTRL_DPRAM_BASE + OFFSET_XOR))
// #define USBCTRL_DPRAM_SET ((USBCTRL_DPRAM_Type *)(USBCTRL_DPRAM_BASE + OFFSET_SET))
// #define USBCTRL_DPRAM_CLR ((USBCTRL_DPRAM_Type *)(USBCTRL_DPRAM_BASE + OFFSET_CLR))
// #define USBCTRL_REGS ((USBCTRL_REGS_Type *)(USBCTRL_REGS_BASE + OFFSET_NORMAL))
// #define USBCTRL_REGS_XOR ((USBCTRL_REGS_Type *)(USBCTRL_REGS_BASE + OFFSET_XOR))
// #define USBCTRL_REGS_SET ((USBCTRL_REGS_Type *)(USBCTRL_REGS_BASE + OFFSET_SET))
// #define USBCTRL_REGS_CLR ((USBCTRL_REGS_Type *)(USBCTRL_REGS_BASE + OFFSET_CLR))
// #define PIO0 ((PIO_Type *)(PIO0_BASE + OFFSET_NORMAL))
// #define PIO0_XOR ((PIO_Type *)(PIO0_BASE + OFFSET_XOR))
// #define PIO0_SET ((PIO_Type *)(PIO0_BASE + OFFSET_SET))
// #define PIO0_CLR ((PIO_Type *)(PIO0_BASE + OFFSET_CLR))
// #define PIO1 ((PIO_Type *)(PIO1_BASE + OFFSET_NORMAL))
// #define PIO1_XOR ((PIO_Type *)(PIO1_BASE + OFFSET_XOR))
// #define PIO1_SET ((PIO_Type *)(PIO1_BASE + OFFSET_SET))
// #define PIO1_CLR ((PIO_Type *)(PIO1_BASE + OFFSET_CLR))
// #define SIO ((SIO_Type *)(SIO_BASE + OFFSET_NORMAL))
// #define SIO_XOR ((SIO_Type *)(SIO_BASE + OFFSET_XOR))
// #define SIO_SET ((SIO_Type *)(SIO_BASE + OFFSET_SET))
// #define SIO_CLR ((SIO_Type *)(SIO_BASE + OFFSET_CLR))
constexpr inline libMcuLL::sioBaseAddress sioAddress{xipCtrlBase + peripheralOffsetNormal};
constexpr inline libMcuLL::sioBaseAddress sioXorAddress{xipCtrlBase + peripheralOffsetXor};
constexpr inline libMcuLL::sioBaseAddress sioSetAddress{xipCtrlBase + peripheralOffsetSet};
constexpr inline libMcuLL::sioBaseAddress sioClrAddress{xipCtrlBase + peripheralOffsetClear};
// #define PPB ((PPB_Type *)(PPB_BASE + OFFSET_NORMAL))
// #define PPB_XOR ((PPB_Type *)(PPB_BASE + OFFSET_XOR))
// #define PPB_SET ((PPB_Type *)(PPB_BASE + OFFSET_SET))
// #define PPB_CLR ((PPB_Type *)(PPB_BASE + OFFSET_CLR))

}  // namespace hw
}  // namespace libMcuLL

#ifdef __cplusplus
extern "C" {
#endif

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
 * @brief Bank 0 gpios masks
 *
 */
typedef enum {
  BANK0_GPIO0_MASK = (1 << 0),   /**< bank 0, pin 0 */
  BANK0_GPIO1_MASK = (1 << 1),   /**< bank 0, pin 1 */
  BANK0_GPIO2_MASK = (1 << 2),   /**< bank 0, pin 2 */
  BANK0_GPIO3_MASK = (1 << 3),   /**< bank 0, pin 3 */
  BANK0_GPIO4_MASK = (1 << 4),   /**< bank 0, pin 4 */
  BANK0_GPIO5_MASK = (1 << 5),   /**< bank 0, pin 5 */
  BANK0_GPIO6_MASK = (1 << 6),   /**< bank 0, pin 6 */
  BANK0_GPIO7_MASK = (1 << 7),   /**< bank 0, pin 7 */
  BANK0_GPIO8_MASK = (1 << 8),   /**< bank 0, pin 8 */
  BANK0_GPIO9_MASK = (1 << 9),   /**< bank 0, pin 9 */
  BANK0_GPIO10_MASK = (1 << 10), /**< bank 0, pin 10 */
  BANK0_GPIO11_MASK = (1 << 11), /**< bank 0, pin 11 */
  BANK0_GPIO12_MASK = (1 << 12), /**< bank 0, pin 12 */
  BANK0_GPIO13_MASK = (1 << 13), /**< bank 0, pin 13 */
  BANK0_GPIO14_MASK = (1 << 14), /**< bank 0, pin 14 */
  BANK0_GPIO15_MASK = (1 << 15), /**< bank 0, pin 15 */
  BANK0_GPIO16_MASK = (1 << 16), /**< bank 0, pin 16 */
  BANK0_GPIO17_MASK = (1 << 17), /**< bank 0, pin 17 */
  BANK0_GPIO18_MASK = (1 << 18), /**< bank 0, pin 18 */
  BANK0_GPIO19_MASK = (1 << 19), /**< bank 0, pin 19 */
  BANK0_GPIO20_MASK = (1 << 20), /**< bank 0, pin 20 */
  BANK0_GPIO21_MASK = (1 << 21), /**< bank 0, pin 21 */
  BANK0_GPIO22_MASK = (1 << 22), /**< bank 0, pin 22 */
  BANK0_GPIO23_MASK = (1 << 23), /**< bank 0, pin 23 */
  BANK0_GPIO24_MASK = (1 << 24), /**< bank 0, pin 24 */
  BANK0_GPIO25_MASK = (1 << 25), /**< bank 0, pin 25 */
  BANK0_GPIO26_MASK = (1 << 26), /**< bank 0, pin 26 */
  BANK0_GPIO27_MASK = (1 << 27), /**< bank 0, pin 27 */
  BANK0_GPIO28_MASK = (1 << 28), /**< bank 0, pin 28 */
  BANK0_GPIO29_MASK = (1 << 29), /**< bank 0, pin 29 */
} BANK0_GPIO_MASKS_Enum;

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
#include "raspberrypi/peripherals.h/sio.h"
// #include "ppb.h"

#ifdef __cplusplus
}
#endif

// includes that define the registers namespace go here.
#include "raspberrypi/peripherals.hpp/RP2040_sio_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_xosc_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_rosc_hw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_sysinfo_hw.hpp"

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here
#include "RP2040_pins.hpp"

// includes that use the registers namespace go here
// need to go after registers namespaces and device specific headers
#include "peripherals.hpp/RP2040_sio_sw_gpio.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_xosc_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_rosc_sw.hpp"
#include "raspberrypi/peripherals.hpp/RP2040_sysinfo_sw.hpp"

#endif
