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
  Pin00, /*!< Pin 0 */
  Pin01, /*!< Pin 1 */
  Pin02, /*!< Pin 2 */
  Pin03, /*!< Pin 3 */
  Pin04, /*!< Pin 4 */
  Pin05, /*!< Pin 5 */
  Pin06, /*!< Pin 6 */
  Pin07, /*!< Pin 7 */
  Pin08, /*!< Pin 8 */
  Pin09, /*!< Pin 9 */
  Pin10, /*!< Pin 10 */
  Pin11, /*!< Pin 11 */
  Pin12, /*!< Pin 12 */
  Pin13, /*!< Pin 13 */
  Pin14, /*!< Pin 14 */
  Pin15, /*!< Pin 15 */
  Pin16, /*!< Pin 16 */
  Pin17, /*!< Pin 17 */
  Pin18, /*!< Pin 18 */
  Pin19, /*!< Pin 19 */
  Pin20, /*!< Pin 20 */
  Pin21, /*!< Pin 21 */
  Pin22, /*!< Pin 22 */
  Pin23, /*!< Pin 23 */
  Pin24, /*!< Pin 24 */
  Pin25, /*!< Pin 25 */
  Pin26, /*!< Pin 26 */
  Pin27, /*!< Pin 27 */
  Pin28, /*!< Pin 28 */
  Pin29, /*!< Pin 29 */
};
/**
 * @brief Available ports on RP2040
 */
enum class IoPorts : std::uint8_t {
  Port0, /*!< Port 0 */
  Qspi,  /*!< port QSPI */
};
/**
 * @brief Available pin functions on RP2040
 */
enum class IoFunctions : std::uint8_t {
  Spi0Rx,      /*!< SPI0 receive */
  Spi0Tx,      /*!< SPI0 transmit */
  Spi0Cs,      /*!< SPI0 Chip select */
  Spi0Sck,     /*!< SPI0 clock */
  Spi1Rx,      /*!< SPI1 receive */
  Spi1Tx,      /*!< SPI1 transmit */
  Spi1Cs,      /*!< SPI1 Chip select */
  Spi1Sck,     /*!< SPI1 clock */
  Uart0Tx,     /*!< UART0 transmit */
  UArt0Rx,     /*!< UART0 receive */
  Uart0Cts,    /*!< UART0 Clear to send */
  Uart0Rts,    /*!< UART0 Request to send */
  Uart1Tx,     /*!< UART1 transmit */
  Uart1Rx,     /*!< UART1 receive */
  Uart1Cts,    /*!< UART1 Clear to send */
  Uart1Rts,    /*!< UART1 Request to send */
  I2c0Scl,     /*!< I2C0 clock */
  I2c0Sda,     /*!< I2C0 data */
  I2c1Scl,     /*!< I2C0 clock */
  I2c1Sda,     /*!< I2C0 data */
  Sio,         /*!< SIO */
  Pio0,        /*!< PIO0 */
  Pio1,        /*!< PIO1 */
  Pwm0A,       /*!< PWM0A */
  Pwm0B,       /*!< PWM0A */
  Pwm1A,       /*!< PWM1A */
  Pwm1B,       /*!< PWM1A */
  Pwm2A,       /*!< PWM2A */
  Pwm2B,       /*!< PWM2A */
  Pwm3A,       /*!< PWM3A */
  Pwm3B,       /*!< PWM3A */
  Pwm4A,       /*!< PWM4A */
  Pwm4B,       /*!< PWM4A */
  Pwm5A,       /*!< PWM5A */
  Pwm5B,       /*!< PWM5A */
  Pwm6A,       /*!< PWM6A */
  Pwm6B,       /*!< PWM6A */
  Pwm7A,       /*!< PWM7A */
  Pwm7B,       /*!< PWM7A */
  ClkGpin0,    /*!< Clock pin in 0 */
  ClkGpout0,   /*!< Clock pin out 0 */
  ClkGpin1,    /*!< Clock pin in 1 */
  ClkGpout1,   /*!< Clock pin out 1 */
  ClkGpout2,   /*!< Clock pin out 2 */
  ClkGpout3,   /*!< Clock pin out 3 */
  UsbOvCurDet, /*!< USB overcurrent detection */
  UsbVbusDet,  /*!< USB bus voltage detection */
  UsbVbusEn,   /*!< USB bus voltage enable */
  XipSck,      /*!< XIP clock */
  XipCs,       /*!< XIP chip select*/
  XipSd0,      /*!< XIP data pin 0 */
  XipSd1,      /*!< XIP data pin 1 */
  XipSd2,      /*!< XIP data pin 2 */
  XipSd3,      /*!< XIP data pin 3 */
};
/**
 * @brief Available pin function selects available on RP2040
 * @todo Need to change to a common gpio namespace
 */
enum class IOfunctSelects : std::uint8_t {
  F1 = libmcuhw::gpio_bank0::CTRL::F1,     /*!< Function 1 selected */
  F2 = libmcuhw::gpio_bank0::CTRL::F2,     /*!< Function 2 selected */
  F3 = libmcuhw::gpio_bank0::CTRL::F3,     /*!< Function 3 selected */
  F4 = libmcuhw::gpio_bank0::CTRL::F4,     /*!< Function 4 selected */
  F5 = libmcuhw::gpio_bank0::CTRL::F5,     /*!< Function 5 selected */
  F6 = libmcuhw::gpio_bank0::CTRL::F6,     /*!< Function 6 selected */
  F7 = libmcuhw::gpio_bank0::CTRL::F7,     /*!< Function 7 selected */
  F8 = libmcuhw::gpio_bank0::CTRL::F8,     /*!< Function 8 selected */
  F9 = libmcuhw::gpio_bank0::CTRL::F9,     /*!< Function 9 selected */
  None = libmcuhw::gpio_bank0::CTRL::NONE, /*!< No Function selected */
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
struct Pin<IoPorts::Port0, IoPins::Pin00, IoFunctions::Spi0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin00, IoFunctions::Uart0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin00, IoFunctions::I2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PWM0 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin00, IoFunctions::Pwm0A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin00, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin00, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin00, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function USB overcurrent detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin00, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 0;
  static constexpr std::uint8_t pin_index = 0u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SPI0 chip select
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01, IoFunctions::Spi0Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01, IoFunctions::UArt0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01, IoFunctions::I2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PWM0 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01, IoFunctions::Pwm0B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 1;
  static constexpr std::uint8_t pin_index = 1u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02, IoFunctions::Spi0Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function UART0 Clear to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02, IoFunctions::Uart0Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02, IoFunctions::I2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PWM1 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02, IoFunctions::Pwm1A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 2;
  static constexpr std::uint8_t pin_index = 2u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03, IoFunctions::Spi0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function UART0 Request to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03, IoFunctions::Uart0Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03, IoFunctions::I2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PWM1 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03, IoFunctions::Pwm1B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function USB Overcurrent detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 3;
  static constexpr std::uint8_t pin_index = 3u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04, IoFunctions::Spi0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04, IoFunctions::Uart1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04, IoFunctions::I2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PWM2 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04, IoFunctions::Pwm2A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 4;
  static constexpr std::uint8_t pin_index = 4u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SPI0 chip select
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05, IoFunctions::Spi0Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05, IoFunctions::Uart1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05, IoFunctions::I2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PWM2 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05, IoFunctions::Pwm2B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 5;
  static constexpr std::uint8_t pin_index = 5u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06, IoFunctions::Spi0Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06, IoFunctions::Uart1Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06, IoFunctions::I2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PWM3 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06, IoFunctions::Pwm3A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 6;
  static constexpr std::uint8_t pin_index = 6u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07, IoFunctions::Spi0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07, IoFunctions::Uart1Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07, IoFunctions::I2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PWM3 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07, IoFunctions::Pwm3B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 7;
  static constexpr std::uint8_t pin_index = 7u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08, IoFunctions::Spi1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08, IoFunctions::Uart1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08, IoFunctions::I2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PWM4 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08, IoFunctions::Pwm4A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 8;
  static constexpr std::uint8_t pin_index = 8u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09, IoFunctions::Spi1Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09, IoFunctions::Uart1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09, IoFunctions::I2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PWM4 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09, IoFunctions::Pwm4B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 9;
  static constexpr std::uint8_t pin_index = 9u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function SPI1 clock
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10, IoFunctions::Spi1Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10, IoFunctions::Uart1Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10, IoFunctions::I2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PWM5 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10, IoFunctions::Pwm5A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 10;
  static constexpr std::uint8_t pin_index = 10u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function SPI1 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11, IoFunctions::Spi1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11, IoFunctions::Uart1Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11, IoFunctions::I2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PWM5 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11, IoFunctions::Pwm5B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 11;
  static constexpr std::uint8_t pin_index = 11u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12, IoFunctions::Spi1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12, IoFunctions::Uart0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12, IoFunctions::I2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PWM6 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12, IoFunctions::Pwm6A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 12;
  static constexpr std::uint8_t pin_index = 12u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13, IoFunctions::Spi1Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13, IoFunctions::UArt0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13, IoFunctions::I2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PWM6 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13, IoFunctions::Pwm6B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 13;
  static constexpr std::uint8_t pin_index = 13u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function SPI1 clock
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14, IoFunctions::Spi1Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function UART0 Clear to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14, IoFunctions::Uart0Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14, IoFunctions::I2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PWM7 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14, IoFunctions::Pwm7A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 14;
  static constexpr std::uint8_t pin_index = 14u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function SPI1 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15, IoFunctions::Spi1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function UART0 Request to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15, IoFunctions::Uart0Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15, IoFunctions::I2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PWM7 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15, IoFunctions::Pwm7B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 15;
  static constexpr std::uint8_t pin_index = 15u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16, IoFunctions::Spi0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16, IoFunctions::Uart0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16, IoFunctions::I2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PWM0 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16, IoFunctions::Pwm0A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 16;
  static constexpr std::uint8_t pin_index = 16u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function SPI0 chip select
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17, IoFunctions::Spi0Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17, IoFunctions::UArt0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17, IoFunctions::I2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PWM0 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17, IoFunctions::Pwm0B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 17;
  static constexpr std::uint8_t pin_index = 17u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin18, IoFunctions::Spi0Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function UART0 Clear to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin18, IoFunctions::Uart0Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin18, IoFunctions::I2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PWM1 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin18, IoFunctions::Pwm1A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin18, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin18, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin18, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin18, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 18;
  static constexpr std::uint8_t pin_index = 18u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin19, IoFunctions::Spi0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function UART0 Request to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin19, IoFunctions::Uart0Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin19, IoFunctions::I2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PWM1 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin19, IoFunctions::Pwm1B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin19, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin19, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin19, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin19, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 19;
  static constexpr std::uint8_t pin_index = 19u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function SPI0 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20, IoFunctions::Spi0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20, IoFunctions::Uart1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20, IoFunctions::I2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PWM2 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20, IoFunctions::Pwm2A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function Clock pin input 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20, IoFunctions::ClkGpin0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 20;
  static constexpr std::uint8_t pin_index = 20u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21, IoFunctions::Spi0Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21, IoFunctions::Uart1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21, IoFunctions::I2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PWM2 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21, IoFunctions::Pwm2B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function Clock pin output 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21, IoFunctions::ClkGpout0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 21;
  static constexpr std::uint8_t pin_index = 21u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function SPI0 clock
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22, IoFunctions::Spi0Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22, IoFunctions::Uart1Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22, IoFunctions::I2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PWM3 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22, IoFunctions::Pwm3A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function Clock pin input 1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22, IoFunctions::ClkGpin1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 22;
  static constexpr std::uint8_t pin_index = 22u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function SPI0 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23, IoFunctions::Spi0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23, IoFunctions::Uart1Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23, IoFunctions::I2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PWM3 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23, IoFunctions::Pwm3B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function Clock pin output 1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23, IoFunctions::ClkGpout1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 23;
  static constexpr std::uint8_t pin_index = 23u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24, IoFunctions::Spi1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function UART1 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24, IoFunctions::Uart1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24, IoFunctions::I2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PWM4 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24, IoFunctions::Pwm4A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function Clock pin output 2
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24, IoFunctions::ClkGpout2> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 24;
  static constexpr std::uint8_t pin_index = 24u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25, IoFunctions::Spi1Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function UART1 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25, IoFunctions::Uart1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25, IoFunctions::I2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PWM4 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25, IoFunctions::Pwm4B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function Clock pin output 3
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25, IoFunctions::ClkGpout3> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F8;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 25;
  static constexpr std::uint8_t pin_index = 25u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function SPI1 clock
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin26, IoFunctions::Spi1Sck> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function UART1 Clear to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin26, IoFunctions::Uart1Cts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function I2C1 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin26, IoFunctions::I2c1Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PWM5 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin26, IoFunctions::Pwm5A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin26, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin26, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin26, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin26, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 26;
  static constexpr std::uint8_t pin_index = 26u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function SPI1 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin27, IoFunctions::Spi1Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function UART1 request to send
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin27, IoFunctions::Uart1Rts> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function I2C1 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin27, IoFunctions::I2c1Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PWM5 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin27, IoFunctions::Pwm5B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin27, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin27, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin27, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin27, IoFunctions::UsbOvCurDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 27;
  static constexpr std::uint8_t pin_index = 27u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function SPI1 receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin28, IoFunctions::Spi1Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function UART0 transmit
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin28, IoFunctions::Uart0Tx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function I2C0 SDA
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin28, IoFunctions::I2c0Sda> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PWM6 A
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin28, IoFunctions::Pwm6A> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin28, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin28, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin28, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function USB VBUS detection
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin28, IoFunctions::UsbVbusDet> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 28;
  static constexpr std::uint8_t pin_index = 28u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function SPI1 Chip select
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin29, IoFunctions::Spi1Cs> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F1;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function UART0 Receive
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin29, IoFunctions::UArt0Rx> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F2;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function I2C0 SCL
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin29, IoFunctions::I2c0Scl> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F3;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PWM6 B
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin29, IoFunctions::Pwm6B> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F4;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function SIO
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin29, IoFunctions::Sio> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F5;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PIO0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin29, IoFunctions::Pio0> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F6;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PIO1
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin29, IoFunctions::Pio1> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F7;
  static constexpr IoPorts port = IoPorts::Port0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function USB VBUS enable
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin29, IoFunctions::UsbVbusEn> : libmcu::PinBase {
  static constexpr std::uint32_t pin_mask = 1 << 29;
  static constexpr std::uint8_t pin_index = 29u;
  static constexpr IOfunctSelects function_select = IOfunctSelects::F9;
  static constexpr IoPorts port = IoPorts::Port0;
};
//! @todo add QSPI port pins
}  // namespace libmcuhw
#endif