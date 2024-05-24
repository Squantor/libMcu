/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 pin definitions
 *
 * Inspired by: https://cppformortals.com/2020/03/06/traits-for-stm32-pin-functions/
 */
#ifndef RP2040_PINS_HPP
#define RP2040_PINS_HPP

namespace libMcuLL::hw {

/**
 * @brief Available pins on RP2040
 */
enum class IOpins : std::uint8_t {
  PIN00, /**< Pin 0 */
  PIN01, /**< Pin 1 */
  PIN02, /**< Pin 2 */
  PIN03, /**< Pin 3 */
  PIN04, /**< Pin 4 */
  PIN05, /**< Pin 5 */
  PIN06, /**< Pin 6 */
  PIN07, /**< Pin 7 */
  PIN08, /**< Pin 8 */
  PIN09, /**< Pin 9 */
  PIN10, /**< Pin 10 */
  PIN11, /**< Pin 11 */
  PIN12, /**< Pin 12 */
  PIN13, /**< Pin 13 */
  PIN14, /**< Pin 14 */
  PIN15, /**< Pin 15 */
  PIN16, /**< Pin 16 */
  PIN17, /**< Pin 17 */
  PIN18, /**< Pin 18 */
  PIN19, /**< Pin 19 */
  PIN20, /**< Pin 20 */
  PIN21, /**< Pin 21 */
  PIN22, /**< Pin 22 */
  PIN23, /**< Pin 23 */
  PIN24, /**< Pin 24 */
  PIN25, /**< Pin 25 */
  PIN26, /**< Pin 26 */
  PIN27, /**< Pin 27 */
  PIN28, /**< Pin 28 */
  PIN29, /**< Pin 29 */
};

/**
 * @brief Available ports on RP2040
 */
enum class IOports : std::uint8_t {
  PORT0, /**< Port 0 */
  QSPI,  /**< port QSPI */
};

/**
 * @brief Available pin functions on RP2040
 */
enum class IOfuncts : std::uint8_t {
  SPI0_RX,       /**< SPI0 receive */
  SPI0_TX,       /**< SPI0 transmit */
  SPI0_CS,       /**< SPI0 Chip select */
  SPI0_SCK,      /**< SPI0 clock */
  SPI1_RX,       /**< SPI1 receive */
  SPI1_TX,       /**< SPI1 transmit */
  SPI1_CS,       /**< SPI1 Chip select */
  SPI1_SCK,      /**< SPI1 clock */
  UART0_TX,      /**< UART0 transmit */
  UART0_RX,      /**< UART0 receive */
  UART0_CTS,     /**< UART0 Clear to send */
  UART0_RTS,     /**< UART0 Request to send */
  UART1_TX,      /**< UART1 transmit */
  UART1_RX,      /**< UART1 receive */
  UART1_CTS,     /**< UART1 Clear to send */
  UART1_RTS,     /**< UART1 Request to send */
  I2C0_SCL,      /**< I2C0 clock */
  I2C0_SDA,      /**< I2C0 data */
  I2C1_SCL,      /**< I2C0 clock */
  I2C1_SDA,      /**< I2C0 data */
  SIO,           /**< SIO */
  PIO0,          /**< PIO0 */
  PIO1,          /**< PIO1 */
  PWM0A,         /**< PWM0A */
  PWM0B,         /**< PWM0A */
  PWM1A,         /**< PWM1A */
  PWM1B,         /**< PWM1A */
  PWM2A,         /**< PWM2A */
  PWM2B,         /**< PWM2A */
  PWM3A,         /**< PWM3A */
  PWM3B,         /**< PWM3A */
  PWM4A,         /**< PWM4A */
  PWM4B,         /**< PWM4A */
  PWM5A,         /**< PWM5A */
  PWM5B,         /**< PWM5A */
  PWM6A,         /**< PWM6A */
  PWM6B,         /**< PWM6A */
  PWM7A,         /**< PWM7A */
  PWM7B,         /**< PWM7A */
  CLK_GPIN0,     /**< Clock pin in 0 */
  CLK_GPOUT0,    /**< Clock pin out 0 */
  CLK_GPIN1,     /**< Clock pin in 1 */
  CLK_GPOUT1,    /**< Clock pin out 1 */
  CLK_GPOUT2,    /**< Clock pin out 2 */
  CLK_GPOUT3,    /**< Clock pin out 3 */
  USB_OVCUR_DET, /**< USB overcurrent detection */
  USB_VBUS_DET,  /**< USB bus voltage detection */
  USB_VBUS_EN,   /**< USB bus voltage enable */
  XIP_SCK,       /**< XIP clock */
  XIP_CS,        /**< XIP chip select*/
  XIP_SD0,       /**< XIP data pin 0 */
  XIP_SD1,       /**< XIP data pin 1 */
  XIP_SD2,       /**< XIP data pin 2 */
  XIP_SD3,       /**< XIP data pin 3 */
};

/**
 * @brief Available pin function selects available
 *
 * TODO: Need to change to a common gpio namespace
 */
enum class IOfunctSelects : std::uint8_t {
  F1 = libMcuLL::hw::gpioBank0::CTRL::F1,     /**< Function 1 selected */
  F2 = libMcuLL::hw::gpioBank0::CTRL::F2,     /**< Function 2 selected */
  F3 = libMcuLL::hw::gpioBank0::CTRL::F3,     /**< Function 3 selected */
  F4 = libMcuLL::hw::gpioBank0::CTRL::F4,     /**< Function 4 selected */
  F5 = libMcuLL::hw::gpioBank0::CTRL::F5,     /**< Function 5 selected */
  F6 = libMcuLL::hw::gpioBank0::CTRL::F6,     /**< Function 6 selected */
  F7 = libMcuLL::hw::gpioBank0::CTRL::F7,     /**< Function 7 selected */
  F8 = libMcuLL::hw::gpioBank0::CTRL::F8,     /**< Function 8 selected */
  F9 = libMcuLL::hw::gpioBank0::CTRL::F9,     /**< Function 9 selected */
  NONE = libMcuLL::hw::gpioBank0::CTRL::NONE, /**< No Function selected */
};

/**
 * @brief base I/O pin template
 *
 * @tparam T_PORT   IO port
 * @tparam T_PIN    IO pin
 * @tparam T_FUNCT  IO function
 */
template <IOports T_PORT, IOpins T_PIN, IOfuncts T_FUNCT, bool DUMMY = false>
struct pin : libMcu::pinBase {
  static_assert(DUMMY, "This I/O pin configuration is invalid!");
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function SPI0 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::SPI0_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function UART0 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::UART0_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function I2C0 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::I2C0_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PWM0 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::PWM0A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function USB overcurrent detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 0;
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SPI0 chip select
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::SPI0_CS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function UART0 Receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::UART0_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function I2C0 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::I2C0_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PWM0 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::PWM0B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 1;
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SPI0 clock
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::SPI0_SCK> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function UART0 Clear to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::UART0_CTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function I2C1 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::I2C1_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PWM1 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::PWM1A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 2;
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SPI0 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::SPI0_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function UART0 Request to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::UART0_RTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function I2C1 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::I2C1_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PWM1 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::PWM1B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function USB Overcurrent detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 3;
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SPI0 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::SPI0_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function UART1 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::UART1_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function I2C0 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::I2C0_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PWM2 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::PWM2A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 4;
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SPI0 chip select
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::SPI0_CS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function UART1 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::UART1_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function I2C0 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::I2C0_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PWM2 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::PWM2B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 5;
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SPI0 clock
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::SPI0_SCK> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function UART1 Clear to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::UART1_CTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function I2C1 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::I2C1_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PWM3 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::PWM3A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 6;
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function SPI0 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07, IOfuncts::SPI0_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function UART1 request to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07, IOfuncts::UART1_RTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function I2C1 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07, IOfuncts::I2C1_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PWM3 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07, IOfuncts::PWM3B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 7 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 7;
  static constexpr std::uint8_t pinIndex = 7u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function SPI1 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08, IOfuncts::SPI1_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function UART1 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08, IOfuncts::UART1_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function I2C0 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08, IOfuncts::I2C0_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PWM4 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08, IOfuncts::PWM4A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 8 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 8;
  static constexpr std::uint8_t pinIndex = 8u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function SPI1 Chip select
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09, IOfuncts::SPI1_CS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function UART1 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09, IOfuncts::UART1_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function I2C0 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09, IOfuncts::I2C0_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PWM4 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09, IOfuncts::PWM4B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 9 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 9;
  static constexpr std::uint8_t pinIndex = 9u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function SPI1 clock
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10, IOfuncts::SPI1_SCK> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function UART1 Clear to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10, IOfuncts::UART1_CTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function I2C1 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10, IOfuncts::I2C1_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PWM5 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10, IOfuncts::PWM5A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 10 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 10;
  static constexpr std::uint8_t pinIndex = 10u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function SPI1 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11, IOfuncts::SPI1_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function UART1 request to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11, IOfuncts::UART1_RTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function I2C1 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11, IOfuncts::I2C1_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PWM5 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11, IOfuncts::PWM5B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 11 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 11;
  static constexpr std::uint8_t pinIndex = 11u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function SPI1 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12, IOfuncts::SPI1_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function UART0 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12, IOfuncts::UART0_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function I2C0 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12, IOfuncts::I2C0_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PWM6 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12, IOfuncts::PWM6A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 12 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 12;
  static constexpr std::uint8_t pinIndex = 12u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function SPI1 Chip select
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13, IOfuncts::SPI1_CS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function UART0 Receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13, IOfuncts::UART0_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function I2C0 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13, IOfuncts::I2C0_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PWM6 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13, IOfuncts::PWM6B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 13 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 13;
  static constexpr std::uint8_t pinIndex = 13u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function SPI1 clock
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14, IOfuncts::SPI1_SCK> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function UART0 Clear to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14, IOfuncts::UART0_CTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function I2C1 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14, IOfuncts::I2C1_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PWM7 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14, IOfuncts::PWM7A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 14 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 14;
  static constexpr std::uint8_t pinIndex = 14u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function SPI1 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15, IOfuncts::SPI1_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function UART0 Request to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15, IOfuncts::UART0_RTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function I2C1 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15, IOfuncts::I2C1_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PWM7 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15, IOfuncts::PWM7B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 15 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 15;
  static constexpr std::uint8_t pinIndex = 15u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function SPI0 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16, IOfuncts::SPI0_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function UART0 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16, IOfuncts::UART0_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function I2C0 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16, IOfuncts::I2C0_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PWM0 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16, IOfuncts::PWM0A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 16 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 16;
  static constexpr std::uint8_t pinIndex = 16u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function SPI0 chip select
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17, IOfuncts::SPI0_CS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function UART0 Receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17, IOfuncts::UART0_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function I2C0 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17, IOfuncts::I2C0_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PWM0 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17, IOfuncts::PWM0B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 17 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 17;
  static constexpr std::uint8_t pinIndex = 17u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function SPI0 clock
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN18, IOfuncts::SPI0_SCK> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function UART0 Clear to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN18, IOfuncts::UART0_CTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function I2C1 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN18, IOfuncts::I2C1_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PWM1 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN18, IOfuncts::PWM1A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN18, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN18, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN18, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 18 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN18, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 18;
  static constexpr std::uint8_t pinIndex = 18u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function SPI0 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN19, IOfuncts::SPI0_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function UART0 Request to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN19, IOfuncts::UART0_RTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function I2C1 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN19, IOfuncts::I2C1_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PWM1 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN19, IOfuncts::PWM1B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN19, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN19, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN19, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 19 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN19, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 19;
  static constexpr std::uint8_t pinIndex = 19u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function SPI0 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20, IOfuncts::SPI0_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function UART1 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20, IOfuncts::UART1_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function I2C0 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20, IOfuncts::I2C0_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PWM2 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20, IOfuncts::PWM2A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function Clock pin input 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20, IOfuncts::CLK_GPIN0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 20 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 20;
  static constexpr std::uint8_t pinIndex = 20u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function SPI0 clock
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21, IOfuncts::SPI0_CS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function UART1 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21, IOfuncts::UART1_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function I2C0 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21, IOfuncts::I2C0_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PWM2 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21, IOfuncts::PWM2B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function Clock pin output 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21, IOfuncts::CLK_GPOUT0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 21 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 21;
  static constexpr std::uint8_t pinIndex = 21u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function SPI0 clock
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22, IOfuncts::SPI0_SCK> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function UART1 Clear to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22, IOfuncts::UART1_CTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function I2C1 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22, IOfuncts::I2C1_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PWM3 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22, IOfuncts::PWM3A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function Clock pin input 1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22, IOfuncts::CLK_GPIN1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 22 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 22;
  static constexpr std::uint8_t pinIndex = 22u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function SPI0 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23, IOfuncts::SPI0_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function UART1 request to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23, IOfuncts::UART1_RTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function I2C1 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23, IOfuncts::I2C1_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PWM3 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23, IOfuncts::PWM3B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function Clock pin output 1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23, IOfuncts::CLK_GPOUT1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 23 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 23;
  static constexpr std::uint8_t pinIndex = 23u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function SPI1 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24, IOfuncts::SPI1_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function UART1 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24, IOfuncts::UART1_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function I2C0 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24, IOfuncts::I2C0_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PWM4 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24, IOfuncts::PWM4A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function Clock pin output 2
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24, IOfuncts::CLK_GPOUT2> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 24 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 24;
  static constexpr std::uint8_t pinIndex = 24u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function SPI1 Chip select
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25, IOfuncts::SPI1_CS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function UART1 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25, IOfuncts::UART1_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function I2C0 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25, IOfuncts::I2C0_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PWM4 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25, IOfuncts::PWM4B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function Clock pin output 3
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25, IOfuncts::CLK_GPOUT3> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F8;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 25 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 25;
  static constexpr std::uint8_t pinIndex = 25u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function SPI1 clock
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN26, IOfuncts::SPI1_SCK> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function UART1 Clear to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN26, IOfuncts::UART1_CTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function I2C1 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN26, IOfuncts::I2C1_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PWM5 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN26, IOfuncts::PWM5A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN26, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN26, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN26, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 26 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN26, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 26;
  static constexpr std::uint8_t pinIndex = 26u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function SPI1 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN27, IOfuncts::SPI1_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function UART1 request to send
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN27, IOfuncts::UART1_RTS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function I2C1 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN27, IOfuncts::I2C1_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PWM5 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN27, IOfuncts::PWM5B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN27, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN27, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN27, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 27 on Port 0 with function USB Overcurrent Detect
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN27, IOfuncts::USB_OVCUR_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 27;
  static constexpr std::uint8_t pinIndex = 27u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function SPI1 receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN28, IOfuncts::SPI1_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function UART0 transmit
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN28, IOfuncts::UART0_TX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function I2C0 SDA
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN28, IOfuncts::I2C0_SDA> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PWM6 A
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN28, IOfuncts::PWM6A> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN28, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN28, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN28, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 28 on Port 0 with function USB VBUS detection
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN28, IOfuncts::USB_VBUS_DET> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 28;
  static constexpr std::uint8_t pinIndex = 28u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function SPI1 Chip select
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN29, IOfuncts::SPI1_CS> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function UART0 Receive
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN29, IOfuncts::UART0_RX> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function I2C0 SCL
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN29, IOfuncts::I2C0_SCL> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PWM6 B
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN29, IOfuncts::PWM6B> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function SIO
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN29, IOfuncts::SIO> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PIO0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN29, IOfuncts::PIO0> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function PIO1
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN29, IOfuncts::PIO1> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
  static constexpr IOports port = IOports::PORT0;
};
/**
 * @brief Specialization for Pin 29 on Port 0 with function USB VBUS enable
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN29, IOfuncts::USB_VBUS_EN> : libMcu::pinBase {
  static constexpr std::uint32_t pinMask = 1 << 29;
  static constexpr std::uint8_t pinIndex = 29u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
  static constexpr IOports port = IOports::PORT0;
};
// TODO QSPI pins
}  // namespace libMcuLL::hw
#endif