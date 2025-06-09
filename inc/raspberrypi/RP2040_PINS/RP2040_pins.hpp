/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_pins.hpp
 * @brief RP2040 pin definitions
 *
 * Inspired by: https://cppformortals.com/2020/03/06/traits-for-stm32-pin-functions/
 */
#ifndef RP2040_PINS_HPP
#define RP2040_PINS_HPP

namespace libmcuhw {
/**
 * @brief Available pins on RP2040
 */
enum class IoPins : std::uint8_t {
  kPin00, /*!< Pin 0 */
  kPin01, /*!< Pin 1 */
  kPin02, /*!< Pin 2 */
  kPin03, /*!< Pin 3 */
  kPin04, /*!< Pin 4 */
  kPin05, /*!< Pin 5 */
  kPin06, /*!< Pin 6 */
  kPin07, /*!< Pin 7 */
  kPin08, /*!< Pin 8 */
  kPin09, /*!< Pin 9 */
  kPin10, /*!< Pin 10 */
  kPin11, /*!< Pin 11 */
  kPin12, /*!< Pin 12 */
  kPin13, /*!< Pin 13 */
  kPin14, /*!< Pin 14 */
  kPin15, /*!< Pin 15 */
  kPin16, /*!< Pin 16 */
  kPin17, /*!< Pin 17 */
  kPin18, /*!< Pin 18 */
  kPin19, /*!< Pin 19 */
  kPin20, /*!< Pin 20 */
  kPin21, /*!< Pin 21 */
  kPin22, /*!< Pin 22 */
  kPin23, /*!< Pin 23 */
  kPin24, /*!< Pin 24 */
  kPin25, /*!< Pin 25 */
  kPin26, /*!< Pin 26 */
  kPin27, /*!< Pin 27 */
  kPin28, /*!< Pin 28 */
  kPin29, /*!< Pin 29 */
};
/**
 * @brief Available ports on RP2040
 */
enum class IoPorts : std::uint8_t {
  kPort0, /*!< Port 0 */
  kQspi,  /*!< port QSPI */
};
/**
 * @brief Available pin functions on RP2040
 */
enum class IoFunctions : std::uint8_t {
  kSpi0Rx,      /*!< SPI0 receive */
  kSpi0Tx,      /*!< SPI0 transmit */
  kSpi0Cs,      /*!< SPI0 Chip select */
  kSpi0Sck,     /*!< SPI0 clock */
  kSpi1Rx,      /*!< SPI1 receive */
  kSpi1Tx,      /*!< SPI1 transmit */
  kSpi1Cs,      /*!< SPI1 Chip select */
  kSpi1Sck,     /*!< SPI1 clock */
  kUart0Tx,     /*!< UART0 transmit */
  kUArt0Rx,     /*!< UART0 receive */
  kUart0Cts,    /*!< UART0 Clear to send */
  kUart0Rts,    /*!< UART0 Request to send */
  kUart1Tx,     /*!< UART1 transmit */
  kUart1Rx,     /*!< UART1 receive */
  kUart1Cts,    /*!< UART1 Clear to send */
  kUart1Rts,    /*!< UART1 Request to send */
  kI2c0Scl,     /*!< I2C0 clock */
  kI2c0Sda,     /*!< I2C0 data */
  kI2c1Scl,     /*!< I2C0 clock */
  kI2c1Sda,     /*!< I2C0 data */
  kSio,         /*!< SIO */
  kPio0,        /*!< PIO0 */
  kPio1,        /*!< PIO1 */
  kPwm0A,       /*!< PWM0A */
  kPwm0B,       /*!< PWM0A */
  kPwm1A,       /*!< PWM1A */
  kPwm1B,       /*!< PWM1A */
  kPwm2A,       /*!< PWM2A */
  kPwm2B,       /*!< PWM2A */
  kPwm3A,       /*!< PWM3A */
  kPwm3B,       /*!< PWM3A */
  kPwm4A,       /*!< PWM4A */
  kPwm4B,       /*!< PWM4A */
  kPwm5A,       /*!< PWM5A */
  kPwm5B,       /*!< PWM5A */
  kPwm6A,       /*!< PWM6A */
  kPwm6B,       /*!< PWM6A */
  kPwm7A,       /*!< PWM7A */
  kPwm7B,       /*!< PWM7A */
  kClkGpin0,    /*!< Clock pin in 0 */
  kClkGpout0,   /*!< Clock pin out 0 */
  kClkGpin1,    /*!< Clock pin in 1 */
  kClkGpout1,   /*!< Clock pin out 1 */
  kClkGpout2,   /*!< Clock pin out 2 */
  kClkGpout3,   /*!< Clock pin out 3 */
  kUsbOvCurDet, /*!< USB overcurrent detection */
  kUsbVbusDet,  /*!< USB bus voltage detection */
  kUsbVbusEn,   /*!< USB bus voltage enable */
  kXipSck,      /*!< XIP clock */
  kXipCs,       /*!< XIP chip select*/
  kXipSd0,      /*!< XIP data pin 0 */
  kXipSd1,      /*!< XIP data pin 1 */
  kXipSd2,      /*!< XIP data pin 2 */
  kXipSd3,      /*!< XIP data pin 3 */
};
/**
 * @brief Available pin function selects available on RP2040
 * @todo Need to change to a common gpio namespace
 */
enum class IOfunctSelects : std::uint8_t {
  kF1 = libmcuhw::gpio_bank0::CTRL::F1,     /*!< Function 1 selected */
  kF2 = libmcuhw::gpio_bank0::CTRL::F2,     /*!< Function 2 selected */
  kF3 = libmcuhw::gpio_bank0::CTRL::F3,     /*!< Function 3 selected */
  kF4 = libmcuhw::gpio_bank0::CTRL::F4,     /*!< Function 4 selected */
  kF5 = libmcuhw::gpio_bank0::CTRL::F5,     /*!< Function 5 selected */
  kF6 = libmcuhw::gpio_bank0::CTRL::F6,     /*!< Function 6 selected */
  kF7 = libmcuhw::gpio_bank0::CTRL::F7,     /*!< Function 7 selected */
  kF8 = libmcuhw::gpio_bank0::CTRL::F8,     /*!< Function 8 selected */
  kF9 = libmcuhw::gpio_bank0::CTRL::F9,     /*!< Function 9 selected */
  kNone = libmcuhw::gpio_bank0::CTRL::NONE, /*!< No Function selected */
};
/**
 * @brief base I/O pin template
 * @tparam T_PORT   IO port
 * @tparam T_PIN    IO pin
 * @tparam T_FUNCT  IO function
 */
template <IoPorts port, IoPins pin, IoFunctions function, bool dummy = false>
struct Pin : libmcu::PinBase {
  static_assert(dummy, "This I/O pin configuration is invalid!");
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin00, IoFunctions::kSpi0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin00, IoFunctions::kUart0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin00, IoFunctions::kI2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PWM0 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin00, IoFunctions::kPwm0A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin00, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin00, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin00, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function USB overcurrent detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin00, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SPI0 chip select
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin01, IoFunctions::kSpi0Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin01, IoFunctions::kUArt0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin01, IoFunctions::kI2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PWM0 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin01, IoFunctions::kPwm0B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin01, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin01, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin01, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin01, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin02, IoFunctions::kSpi0Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function UART0 Clear to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin02, IoFunctions::kUart0Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin02, IoFunctions::kI2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PWM1 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin02, IoFunctions::kPwm1A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin02, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin02, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin02, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin02, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin03, IoFunctions::kSpi0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function UART0 Request to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin03, IoFunctions::kUart0Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin03, IoFunctions::kI2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PWM1 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin03, IoFunctions::kPwm1B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin03, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin03, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin03, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function USB Overcurrent detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin03, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin04, IoFunctions::kSpi0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin04, IoFunctions::kUart1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin04, IoFunctions::kI2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PWM2 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin04, IoFunctions::kPwm2A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin04, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin04, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin04, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin04, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SPI0 chip select
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin05, IoFunctions::kSpi0Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin05, IoFunctions::kUart1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin05, IoFunctions::kI2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PWM2 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin05, IoFunctions::kPwm2B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin05, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin05, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin05, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin05, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin06, IoFunctions::kSpi0Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin06, IoFunctions::kUart1Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin06, IoFunctions::kI2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PWM3 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin06, IoFunctions::kPwm3A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin06, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin06, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin06, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin06, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin07, IoFunctions::kSpi0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin07, IoFunctions::kUart1Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin07, IoFunctions::kI2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PWM3 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin07, IoFunctions::kPwm3B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin07, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin07, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin07, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin07, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin08, IoFunctions::kSpi1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin08, IoFunctions::kUart1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin08, IoFunctions::kI2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PWM4 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin08, IoFunctions::kPwm4A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin08, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin08, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin08, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin08, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin09, IoFunctions::kSpi1Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin09, IoFunctions::kUart1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin09, IoFunctions::kI2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PWM4 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin09, IoFunctions::kPwm4B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin09, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin09, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin09, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin09, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function SPI1 clock
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin10, IoFunctions::kSpi1Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin10, IoFunctions::kUart1Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin10, IoFunctions::kI2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PWM5 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin10, IoFunctions::kPwm5A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin10, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin10, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin10, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin10, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function SPI1 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin11, IoFunctions::kSpi1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin11, IoFunctions::kUart1Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin11, IoFunctions::kI2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PWM5 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin11, IoFunctions::kPwm5B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin11, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin11, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin11, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin11, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin12, IoFunctions::kSpi1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin12, IoFunctions::kUart0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin12, IoFunctions::kI2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PWM6 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin12, IoFunctions::kPwm6A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin12, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin12, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin12, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin12, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin13, IoFunctions::kSpi1Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin13, IoFunctions::kUArt0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin13, IoFunctions::kI2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PWM6 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin13, IoFunctions::kPwm6B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin13, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin13, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin13, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin13, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function SPI1 clock
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin14, IoFunctions::kSpi1Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function UART0 Clear to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin14, IoFunctions::kUart0Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin14, IoFunctions::kI2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PWM7 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin14, IoFunctions::kPwm7A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin14, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin14, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin14, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin14, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function SPI1 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin15, IoFunctions::kSpi1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function UART0 Request to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin15, IoFunctions::kUart0Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin15, IoFunctions::kI2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PWM7 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin15, IoFunctions::kPwm7B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin15, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin15, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin15, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin15, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin16, IoFunctions::kSpi0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin16, IoFunctions::kUart0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin16, IoFunctions::kI2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PWM0 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin16, IoFunctions::kPwm0A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin16, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin16, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin16, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin16, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function SPI0 chip select
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin17, IoFunctions::kSpi0Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin17, IoFunctions::kUArt0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin17, IoFunctions::kI2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PWM0 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin17, IoFunctions::kPwm0B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin17, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin17, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin17, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin17, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin18, IoFunctions::kSpi0Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function UART0 Clear to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin18, IoFunctions::kUart0Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin18, IoFunctions::kI2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PWM1 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin18, IoFunctions::kPwm1A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin18, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin18, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin18, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin18, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin19, IoFunctions::kSpi0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function UART0 Request to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin19, IoFunctions::kUart0Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin19, IoFunctions::kI2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PWM1 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin19, IoFunctions::kPwm1B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin19, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin19, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin19, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin19, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin20, IoFunctions::kSpi0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin20, IoFunctions::kUart1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin20, IoFunctions::kI2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PWM2 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin20, IoFunctions::kPwm2A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin20, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin20, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin20, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function Clock pin input 0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin20, IoFunctions::kClkGpin0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF8;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin20, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin21, IoFunctions::kSpi0Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin21, IoFunctions::kUart1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin21, IoFunctions::kI2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PWM2 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin21, IoFunctions::kPwm2B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin21, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin21, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin21, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function Clock pin output 0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin21, IoFunctions::kClkGpout0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF8;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin21, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin22, IoFunctions::kSpi0Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin22, IoFunctions::kUart1Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin22, IoFunctions::kI2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PWM3 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin22, IoFunctions::kPwm3A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin22, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin22, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin22, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function Clock pin input 1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin22, IoFunctions::kClkGpin1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF8;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin22, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin23, IoFunctions::kSpi0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin23, IoFunctions::kUart1Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin23, IoFunctions::kI2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PWM3 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin23, IoFunctions::kPwm3B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin23, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin23, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin23, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function Clock pin output 1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin23, IoFunctions::kClkGpout1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF8;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin23, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin24, IoFunctions::kSpi1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin24, IoFunctions::kUart1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin24, IoFunctions::kI2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PWM4 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin24, IoFunctions::kPwm4A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin24, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin24, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin24, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function Clock pin output 2
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin24, IoFunctions::kClkGpout2> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF8;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin24, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin25, IoFunctions::kSpi1Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin25, IoFunctions::kUart1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin25, IoFunctions::kI2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PWM4 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin25, IoFunctions::kPwm4B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin25, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin25, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin25, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function Clock pin output 3
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin25, IoFunctions::kClkGpout3> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF8;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin25, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function SPI1 clock
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin26, IoFunctions::kSpi1Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin26, IoFunctions::kUart1Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin26, IoFunctions::kI2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PWM5 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin26, IoFunctions::kPwm5A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin26, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin26, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin26, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin26, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function SPI1 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin27, IoFunctions::kSpi1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin27, IoFunctions::kUart1Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin27, IoFunctions::kI2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PWM5 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin27, IoFunctions::kPwm5B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin27, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin27, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin27, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin27, IoFunctions::kUsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin28, IoFunctions::kSpi1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin28, IoFunctions::kUart0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin28, IoFunctions::kI2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PWM6 A
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin28, IoFunctions::kPwm6A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin28, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin28, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin28, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin28, IoFunctions::kUsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin29, IoFunctions::kSpi1Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF1;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin29, IoFunctions::kUArt0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF2;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin29, IoFunctions::kI2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF3;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PWM6 B
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin29, IoFunctions::kPwm6B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF4;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin29, IoFunctions::kSio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF5;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin29, IoFunctions::kPio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF6;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin29, IoFunctions::kPio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF7;
  static constexpr IoPorts port = IoPorts::kPort0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::kPort0, IoPins::kPin29, IoFunctions::kUsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::kF9;
  static constexpr IoPorts port = IoPorts::kPort0;
};
//! @todo add QSPI port pins
}  // namespace libmcuhw
#endif