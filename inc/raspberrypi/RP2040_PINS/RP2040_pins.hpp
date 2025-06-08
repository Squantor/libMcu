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
  PORT0, /*!< Port 0 */
  QSPI,  /*!< port QSPI */
};

/**
 * @brief Available pin functions on RP2040
 */
enum class IOfuncts : std::uint8_t {
  SPI0_RX,       /*!< SPI0 receive */
  SPI0_TX,       /*!< SPI0 transmit */
  SPI0_CS,       /*!< SPI0 Chip select */
  SPI0_SCK,      /*!< SPI0 clock */
  SPI1_RX,       /*!< SPI1 receive */
  SPI1_TX,       /*!< SPI1 transmit */
  SPI1_CS,       /*!< SPI1 Chip select */
  SPI1_SCK,      /*!< SPI1 clock */
  UART0_TX,      /*!< UART0 transmit */
  UART0_RX,      /*!< UART0 receive */
  UART0_CTS,     /*!< UART0 Clear to send */
  UART0_RTS,     /*!< UART0 Request to send */
  UART1_TX,      /*!< UART1 transmit */
  UART1_RX,      /*!< UART1 receive */
  UART1_CTS,     /*!< UART1 Clear to send */
  UART1_RTS,     /*!< UART1 Request to send */
  I2C0_SCL,      /*!< I2C0 clock */
  I2C0_SDA,      /*!< I2C0 data */
  I2C1_SCL,      /*!< I2C0 clock */
  I2C1_SDA,      /*!< I2C0 data */
  SIO,           /*!< SIO */
  PIO0,          /*!< PIO0 */
  PIO1,          /*!< PIO1 */
  PWM0A,         /*!< PWM0A */
  PWM0B,         /*!< PWM0A */
  PWM1A,         /*!< PWM1A */
  PWM1B,         /*!< PWM1A */
  PWM2A,         /*!< PWM2A */
  PWM2B,         /*!< PWM2A */
  PWM3A,         /*!< PWM3A */
  PWM3B,         /*!< PWM3A */
  PWM4A,         /*!< PWM4A */
  PWM4B,         /*!< PWM4A */
  PWM5A,         /*!< PWM5A */
  PWM5B,         /*!< PWM5A */
  PWM6A,         /*!< PWM6A */
  PWM6B,         /*!< PWM6A */
  PWM7A,         /*!< PWM7A */
  PWM7B,         /*!< PWM7A */
  CLK_GPIN0,     /*!< Clock pin in 0 */
  CLK_GPOUT0,    /*!< Clock pin out 0 */
  CLK_GPIN1,     /*!< Clock pin in 1 */
  CLK_GPOUT1,    /*!< Clock pin out 1 */
  CLK_GPOUT2,    /*!< Clock pin out 2 */
  CLK_GPOUT3,    /*!< Clock pin out 3 */
  USB_OVCUR_DET, /*!< USB overcurrent detection */
  USB_VBUS_DET,  /*!< USB bus voltage detection */
  USB_VBUS_EN,   /*!< USB bus voltage enable */
  XIP_SCK,       /*!< XIP clock */
  XIP_CS,        /*!< XIP chip select*/
  XIP_SD0,       /*!< XIP data pin 0 */
  XIP_SD1,       /*!< XIP data pin 1 */
  XIP_SD2,       /*!< XIP data pin 2 */
  XIP_SD3,       /*!< XIP data pin 3 */
};

/**
 * @brief Available pin function selects available
 *
 * TODO: Need to change to a common gpio namespace
 */
enum class IOfunctSelects : std::uint8_t {
  F1 = libmcuhw::gpioBank0::CTRL::F1,     /*!< Function 1 selected */
  F2 = libmcuhw::gpioBank0::CTRL::F2,     /*!< Function 2 selected */
  F3 = libmcuhw::gpioBank0::CTRL::F3,     /*!< Function 3 selected */
  F4 = libmcuhw::gpioBank0::CTRL::F4,     /*!< Function 4 selected */
  F5 = libmcuhw::gpioBank0::CTRL::F5,     /*!< Function 5 selected */
  F6 = libmcuhw::gpioBank0::CTRL::F6,     /*!< Function 6 selected */
  F7 = libmcuhw::gpioBank0::CTRL::F7,     /*!< Function 7 selected */
  F8 = libmcuhw::gpioBank0::CTRL::F8,     /*!< Function 8 selected */
  F9 = libmcuhw::gpioBank0::CTRL::F9,     /*!< Function 9 selected */
  NONE = libmcuhw::gpioBank0::CTRL::NONE, /*!< No Function selected */
};

/**
 * @brief base I/O pin template
 * @tparam T_PORT   IO port
 * @tparam T_PIN    IO pin
 * @tparam T_FUNCT  IO function
 */
template <IoPorts T_PORT, IoPins T_PIN, IOfuncts T_FUNCT, bool DUMMY = false>
struct Pin : libmcu::PinBase {
  static_assert(DUMMY, "This I/O pin configuration is invalid!");
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin00, IOfuncts::SPI0_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin00, IOfuncts::UART0_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin00, IOfuncts::I2C0_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PWM0 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin00, IOfuncts::PWM0A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin00, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin00, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin00, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function USB overcurrent detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin00, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SPI0 chip select
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin01, IOfuncts::SPI0_CS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin01, IOfuncts::UART0_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin01, IOfuncts::I2C0_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PWM0 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin01, IOfuncts::PWM0B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin01, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin01, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin01, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin01, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin02, IOfuncts::SPI0_SCK> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function UART0 Clear to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin02, IOfuncts::UART0_CTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin02, IOfuncts::I2C1_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PWM1 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin02, IOfuncts::PWM1A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin02, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin02, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin02, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin02, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin03, IOfuncts::SPI0_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function UART0 Request to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin03, IOfuncts::UART0_RTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin03, IOfuncts::I2C1_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PWM1 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin03, IOfuncts::PWM1B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin03, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin03, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin03, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function USB Overcurrent detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin03, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin04, IOfuncts::SPI0_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin04, IOfuncts::UART1_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin04, IOfuncts::I2C0_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PWM2 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin04, IOfuncts::PWM2A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin04, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin04, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin04, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin04, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SPI0 chip select
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin05, IOfuncts::SPI0_CS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin05, IOfuncts::UART1_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin05, IOfuncts::I2C0_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PWM2 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin05, IOfuncts::PWM2B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin05, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin05, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin05, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin05, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin06, IOfuncts::SPI0_SCK> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin06, IOfuncts::UART1_CTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin06, IOfuncts::I2C1_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PWM3 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin06, IOfuncts::PWM3A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin06, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin06, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin06, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin06, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin07, IOfuncts::SPI0_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin07, IOfuncts::UART1_RTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin07, IOfuncts::I2C1_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PWM3 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin07, IOfuncts::PWM3B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin07, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin07, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin07, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin07, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin08, IOfuncts::SPI1_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin08, IOfuncts::UART1_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin08, IOfuncts::I2C0_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PWM4 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin08, IOfuncts::PWM4A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin08, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin08, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin08, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin08, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin09, IOfuncts::SPI1_CS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin09, IOfuncts::UART1_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin09, IOfuncts::I2C0_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PWM4 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin09, IOfuncts::PWM4B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin09, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin09, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin09, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin09, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function SPI1 clock
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin10, IOfuncts::SPI1_SCK> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin10, IOfuncts::UART1_CTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin10, IOfuncts::I2C1_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PWM5 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin10, IOfuncts::PWM5A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin10, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin10, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin10, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin10, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function SPI1 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin11, IOfuncts::SPI1_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin11, IOfuncts::UART1_RTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin11, IOfuncts::I2C1_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PWM5 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin11, IOfuncts::PWM5B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin11, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin11, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin11, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin11, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin12, IOfuncts::SPI1_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin12, IOfuncts::UART0_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin12, IOfuncts::I2C0_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PWM6 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin12, IOfuncts::PWM6A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin12, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin12, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin12, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin12, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin13, IOfuncts::SPI1_CS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin13, IOfuncts::UART0_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin13, IOfuncts::I2C0_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PWM6 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin13, IOfuncts::PWM6B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin13, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin13, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin13, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin13, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function SPI1 clock
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin14, IOfuncts::SPI1_SCK> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function UART0 Clear to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin14, IOfuncts::UART0_CTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin14, IOfuncts::I2C1_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PWM7 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin14, IOfuncts::PWM7A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin14, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin14, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin14, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin14, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function SPI1 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin15, IOfuncts::SPI1_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function UART0 Request to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin15, IOfuncts::UART0_RTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin15, IOfuncts::I2C1_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PWM7 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin15, IOfuncts::PWM7B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin15, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin15, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin15, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin15, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin16, IOfuncts::SPI0_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin16, IOfuncts::UART0_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin16, IOfuncts::I2C0_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PWM0 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin16, IOfuncts::PWM0A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin16, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin16, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin16, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin16, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function SPI0 chip select
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin17, IOfuncts::SPI0_CS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin17, IOfuncts::UART0_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin17, IOfuncts::I2C0_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PWM0 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin17, IOfuncts::PWM0B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin17, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin17, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin17, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin17, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin18, IOfuncts::SPI0_SCK> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function UART0 Clear to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin18, IOfuncts::UART0_CTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin18, IOfuncts::I2C1_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PWM1 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin18, IOfuncts::PWM1A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin18, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin18, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin18, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin18, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin19, IOfuncts::SPI0_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function UART0 Request to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin19, IOfuncts::UART0_RTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin19, IOfuncts::I2C1_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PWM1 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin19, IOfuncts::PWM1B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin19, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin19, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin19, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin19, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20, IOfuncts::SPI0_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20, IOfuncts::UART1_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20, IOfuncts::I2C0_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PWM2 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20, IOfuncts::PWM2A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function Clock pin input 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20, IOfuncts::CLK_GPIN0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21, IOfuncts::SPI0_CS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21, IOfuncts::UART1_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21, IOfuncts::I2C0_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PWM2 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21, IOfuncts::PWM2B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function Clock pin output 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21, IOfuncts::CLK_GPOUT0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22, IOfuncts::SPI0_SCK> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22, IOfuncts::UART1_CTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22, IOfuncts::I2C1_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PWM3 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22, IOfuncts::PWM3A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function Clock pin input 1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22, IOfuncts::CLK_GPIN1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23, IOfuncts::SPI0_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23, IOfuncts::UART1_RTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23, IOfuncts::I2C1_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PWM3 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23, IOfuncts::PWM3B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function Clock pin output 1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23, IOfuncts::CLK_GPOUT1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24, IOfuncts::SPI1_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24, IOfuncts::UART1_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24, IOfuncts::I2C0_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PWM4 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24, IOfuncts::PWM4A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function Clock pin output 2
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24, IOfuncts::CLK_GPOUT2> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25, IOfuncts::SPI1_CS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25, IOfuncts::UART1_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25, IOfuncts::I2C0_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PWM4 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25, IOfuncts::PWM4B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function Clock pin output 3
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25, IOfuncts::CLK_GPOUT3> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function SPI1 clock
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin26, IOfuncts::SPI1_SCK> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin26, IOfuncts::UART1_CTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin26, IOfuncts::I2C1_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PWM5 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin26, IOfuncts::PWM5A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin26, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin26, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin26, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin26, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function SPI1 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin27, IOfuncts::SPI1_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin27, IOfuncts::UART1_RTS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin27, IOfuncts::I2C1_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PWM5 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin27, IOfuncts::PWM5B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin27, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin27, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin27, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin27, IOfuncts::USB_OVCUR_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin28, IOfuncts::SPI1_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin28, IOfuncts::UART0_TX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin28, IOfuncts::I2C0_SDA> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PWM6 A
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin28, IOfuncts::PWM6A> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin28, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin28, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin28, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin28, IOfuncts::USB_VBUS_DET> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin29, IOfuncts::SPI1_CS> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin29, IOfuncts::UART0_RX> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin29, IOfuncts::I2C0_SCL> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PWM6 B
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin29, IOfuncts::PWM6B> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin29, IOfuncts::SIO> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin29, IOfuncts::PIO0> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin29, IOfuncts::PIO1> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin29, IOfuncts::USB_VBUS_EN> : libmcu::PinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::PORT0;
};
// TODO QSPI pins
}  // namespace libmcuhw
#endif