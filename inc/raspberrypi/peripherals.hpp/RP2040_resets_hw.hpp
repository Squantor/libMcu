/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Resets register interface
 */
#ifndef RP2040_RESETS_HW_HPP
#define RP2040_RESETS_HW_HPP

namespace libMcuHw::resets {
/**
 * @brief resets register definitions
 */
struct resets {
  volatile std::uint32_t RESET;      /**< Reset control */
  volatile std::uint32_t WDSEL;      /**< Watchdog select */
  volatile std::uint32_t RESET_DONE; /**< Reset done */
};
namespace RESET {
constexpr inline std::uint32_t RESERVED_MASK{0x01FF'FFFFu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t USBCTRL{1u << 24};           /**< USB controller reset bit */
constexpr inline std::uint32_t UART1{1u << 23};             /**< UART 1 reset bit */
constexpr inline std::uint32_t UART0{1u << 22};             /**< UART 0 reset bit */
constexpr inline std::uint32_t TIMER{1u << 21};             /**< Timer reset bit */
constexpr inline std::uint32_t TBMAN{1u << 20};             /**< Test Bench manager reset bit */
constexpr inline std::uint32_t SYSINFO{1u << 19};           /**< System information reset bit */
constexpr inline std::uint32_t SYSCFG{1u << 18};            /**< System configuration reset bit */
constexpr inline std::uint32_t SPI1{1u << 17};              /**< SPI 1 reset bit */
constexpr inline std::uint32_t SPI0{1u << 16};              /**< SPI 0 reset bit */
constexpr inline std::uint32_t RTC{1u << 15};               /**< RTC reset bit */
constexpr inline std::uint32_t PWM{1u << 14};               /**< PWM reset bit */
constexpr inline std::uint32_t PLL_USB{1u << 13};           /**< USB PLL reset bit */
constexpr inline std::uint32_t PLL_SYS{1u << 12};           /**< System PLL reset bit */
constexpr inline std::uint32_t PIO1{1u << 11};              /**< PIO1 reset bit */
constexpr inline std::uint32_t PIO0{1u << 10};              /**< PIO0 reset bit */
constexpr inline std::uint32_t PADS_QSPI{1u << 9};          /**< Pads QSPI reset bit */
constexpr inline std::uint32_t PADS_BANK0{1u << 8};         /**< Pads Bank0 reset bit */
constexpr inline std::uint32_t JTAG{1u << 7};               /**< JTAG reset bit */
constexpr inline std::uint32_t IO_QSPI{1u << 6};            /**< IO QSPI reset bit */
constexpr inline std::uint32_t IO_BANK0{1u << 5};           /**< IO BANK0 reset bit */
constexpr inline std::uint32_t I2C1{1u << 4};               /**< I2C 1 reset bit */
constexpr inline std::uint32_t I2C0{1u << 3};               /**< I2C 0 reset bit */
constexpr inline std::uint32_t DMA{1u << 2};                /**< DMA reset bit */
constexpr inline std::uint32_t BUSCTRL{1u << 1};            /**< Buscontrol reset bit */
constexpr inline std::uint32_t ADC{1u << 0};                /**< ADC reset bit */
}  // namespace RESET
namespace WDSEL {
constexpr inline std::uint32_t RESERVED_MASK{0x01FF'FFFFu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t USBCTRL{1u << 24};           /**< USB controller reset bit */
constexpr inline std::uint32_t UART1{1u << 23};             /**< UART 1 reset bit */
constexpr inline std::uint32_t UART0{1u << 22};             /**< UART 0 reset bit */
constexpr inline std::uint32_t TIMER{1u << 21};             /**< Timer reset bit */
constexpr inline std::uint32_t TBMAN{1u << 20};             /**< Test Bench manager reset bit */
constexpr inline std::uint32_t SYSINFO{1u << 19};           /**< System information reset bit */
constexpr inline std::uint32_t SYSCFG{1u << 18};            /**< System configuration reset bit */
constexpr inline std::uint32_t SPI1{1u << 17};              /**< SPI 1 reset bit */
constexpr inline std::uint32_t SPI0{1u << 16};              /**< SPI 0 reset bit */
constexpr inline std::uint32_t RTC{1u << 15};               /**< RTC reset bit */
constexpr inline std::uint32_t PWM{1u << 14};               /**< PWM reset bit */
constexpr inline std::uint32_t PLL_USB{1u << 13};           /**< USB PLL reset bit */
constexpr inline std::uint32_t PLL_SYS{1u << 12};           /**< System PLL reset bit */
constexpr inline std::uint32_t PIO1{1u << 11};              /**< PIO1 reset bit */
constexpr inline std::uint32_t PIO0{1u << 10};              /**< PIO0 reset bit */
constexpr inline std::uint32_t PADS_QSPI{1u << 9};          /**< Pads QSPI reset bit */
constexpr inline std::uint32_t PADS_BANK0{1u << 8};         /**< Pads Bank0 reset bit */
constexpr inline std::uint32_t JTAG{1u << 7};               /**< JTAG reset bit */
constexpr inline std::uint32_t IO_QSPI{1u << 6};            /**< IO QSPI reset bit */
constexpr inline std::uint32_t IO_BANK0{1u << 5};           /**< IO BANK0 reset bit */
constexpr inline std::uint32_t I2C1{1u << 4};               /**< I2C 1 reset bit */
constexpr inline std::uint32_t I2C0{1u << 3};               /**< I2C 0 reset bit */
constexpr inline std::uint32_t DMA{1u << 2};                /**< DMA reset bit */
constexpr inline std::uint32_t BUSCTRL{1u << 1};            /**< Buscontrol reset bit */
constexpr inline std::uint32_t ADC{1u << 0};                /**< ADC reset bit */
}  // namespace WDSEL
namespace RESET_DONE {
constexpr inline std::uint32_t RESERVED_MASK{0x01FF'FFFFu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t USBCTRL{1u << 24};           /**< USB controller reset bit */
constexpr inline std::uint32_t UART1{1u << 23};             /**< UART 1 reset bit */
constexpr inline std::uint32_t UART0{1u << 22};             /**< UART 0 reset bit */
constexpr inline std::uint32_t TIMER{1u << 21};             /**< Timer reset bit */
constexpr inline std::uint32_t TBMAN{1u << 20};             /**< Test Bench manager reset bit */
constexpr inline std::uint32_t SYSINFO{1u << 19};           /**< System information reset bit */
constexpr inline std::uint32_t SYSCFG{1u << 18};            /**< System configuration reset bit */
constexpr inline std::uint32_t SPI1{1u << 17};              /**< SPI 1 reset bit */
constexpr inline std::uint32_t SPI0{1u << 16};              /**< SPI 0 reset bit */
constexpr inline std::uint32_t RTC{1u << 15};               /**< RTC reset bit */
constexpr inline std::uint32_t PWM{1u << 14};               /**< PWM reset bit */
constexpr inline std::uint32_t PLL_USB{1u << 13};           /**< USB PLL reset bit */
constexpr inline std::uint32_t PLL_SYS{1u << 12};           /**< System PLL reset bit */
constexpr inline std::uint32_t PIO1{1u << 11};              /**< PIO1 reset bit */
constexpr inline std::uint32_t PIO0{1u << 10};              /**< PIO0 reset bit */
constexpr inline std::uint32_t PADS_QSPI{1u << 9};          /**< Pads QSPI reset bit */
constexpr inline std::uint32_t PADS_BANK0{1u << 8};         /**< Pads Bank0 reset bit */
constexpr inline std::uint32_t JTAG{1u << 7};               /**< JTAG reset bit */
constexpr inline std::uint32_t IO_QSPI{1u << 6};            /**< IO QSPI reset bit */
constexpr inline std::uint32_t IO_BANK0{1u << 5};           /**< IO BANK0 reset bit */
constexpr inline std::uint32_t I2C1{1u << 4};               /**< I2C 1 reset bit */
constexpr inline std::uint32_t I2C0{1u << 3};               /**< I2C 0 reset bit */
constexpr inline std::uint32_t DMA{1u << 2};                /**< DMA reset bit */
constexpr inline std::uint32_t BUSCTRL{1u << 1};            /**< Buscontrol reset bit */
constexpr inline std::uint32_t ADC{1u << 0};                /**< ADC reset bit */
}  // namespace RESET_DONE
}  // namespace libMcuHw::resets
#endif