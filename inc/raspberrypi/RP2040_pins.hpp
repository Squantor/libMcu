/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 pin interface register interface
 *
 * Inspired by: https://cppformortals.com/2020/03/06/traits-for-stm32-pin-functions/
 *
 */
#ifndef RP2040_PINS_HPP
#define RP2040_PINS_HPP

namespace libMcuLL {
namespace hw {

/**
 * @brief Available pins on RP2040
 *
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
 *
 */
enum class IOports : std::uint8_t {
  PORT0, /**< Port 0 */
  QSPI,  /**< port QSPI */
};

/**
 * @brief Available pin functions on RP2040
 *
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
 */
enum class IOfunctSelects : std::uint8_t {
  F1 = 0x0,    /**< Function 1 selected */
  F2 = 0x1,    /**< Function 2 selected */
  F3 = 0x2,    /**< Function 3 selected */
  F4 = 0x3,    /**< Function 4 selected */
  F5 = 0x4,    /**< Function 5 selected */
  F6 = 0x5,    /**< Function 6 selected */
  F7 = 0x6,    /**< Function 7 selected */
  F8 = 0x7,    /**< Function 8 selected */
  F9 = 0x8,    /**< Function 9 selected */
  NONE = 0x1F, /**< No Function selected */
};

/**
 * @brief base I/O pin template
 *
 * @tparam T_PORT   IO port
 * @tparam T_PIN    IO pin
 * @tparam T_FUNCT  IO function
 */
template <IOports T_PORT, IOpins T_PIN, IOfuncts T_FUNCT, bool DUMMY = false>
struct pin {
  static_assert(DUMMY, "This I/O pin configuration is invalid!");
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function SPI0 RX
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::SPI0_RX> {
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function UART0 transmit
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::UART0_TX> {
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function I2C0 SDA
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::I2C0_SDA> {
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PWM0 A
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::PWM0A> {
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function SIO
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::SIO> {
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::PIO0> {
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function PIO1
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::PIO1> {
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
};
/**
 * @brief Specialization for Pin 0 on Port 0 with function USB overcurrent detection
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00, IOfuncts::USB_OVCUR_DET> {
  static constexpr std::uint8_t pinIndex = 0u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SPI0 chip select
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::SPI0_CS> {
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function UART0 Receive
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::UART0_RX> {
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function I2C0 SCL
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::I2C0_SCL> {
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PWM0 A
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::PWM0B> {
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function SIO
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::SIO> {
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::PIO0> {
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function PIO1
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::PIO1> {
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
};
/**
 * @brief Specialization for Pin 1 on Port 0 with function USB overcurrent detection
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01, IOfuncts::USB_VBUS_DET> {
  static constexpr std::uint8_t pinIndex = 1u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SPI0 clock
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::SPI0_SCK> {
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function UART0 Clear to send
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::UART0_CTS> {
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function I2C1 SDA
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::I2C1_SDA> {
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PWM1 A
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::PWM1A> {
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function SIO
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::SIO> {
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::PIO0> {
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function PIO1
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::PIO1> {
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
};
/**
 * @brief Specialization for Pin 2 on Port 0 with function USB VBUS enable
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02, IOfuncts::USB_VBUS_EN> {
  static constexpr std::uint8_t pinIndex = 2u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SPI0 transmit
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::SPI0_TX> {
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function UART0 Request to send
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::UART0_RTS> {
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function I2C1 SCL
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::I2C1_SCL> {
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PWM1 B
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::PWM1B> {
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function SIO
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::SIO> {
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::PIO0> {
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function PIO1
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::PIO1> {
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
};
/**
 * @brief Specialization for Pin 3 on Port 0 with function USB Overcurrent detection
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03, IOfuncts::USB_OVCUR_DET> {
  static constexpr std::uint8_t pinIndex = 3u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SPI0 receive
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::SPI0_RX> {
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function UART1 transmit
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::UART1_TX> {
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function I2C0 SDA
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::I2C0_SDA> {
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PWM2 A
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::PWM2A> {
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function SIO
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::SIO> {
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::PIO0> {
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function PIO1
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::PIO1> {
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
};
/**
 * @brief Specialization for Pin 4 on Port 0 with function USB VBUS detection
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04, IOfuncts::USB_VBUS_DET> {
  static constexpr std::uint8_t pinIndex = 4u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SPI0 chip select
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::SPI0_CS> {
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function UART1 receive
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::UART1_RX> {
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function I2C0 SCL
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::I2C0_SCL> {
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PWM2 B
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::PWM2B> {
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function SIO
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::SIO> {
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::PIO0> {
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function PIO1
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::PIO1> {
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
};
/**
 * @brief Specialization for Pin 5 on Port 0 with function USB VBUS enable
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05, IOfuncts::USB_VBUS_EN> {
  static constexpr std::uint8_t pinIndex = 5u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SPI0 clock
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::SPI0_SCK> {
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F1;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function UART1 Clear to send
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::UART1_CTS> {
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F2;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function I2C1 SDA
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::I2C1_SDA> {
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F3;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PWM3 A
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::PWM3A> {
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F4;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function SIO
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::SIO> {
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F5;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::PIO0> {
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F6;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function PIO1
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::PIO1> {
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F7;
};
/**
 * @brief Specialization for Pin 6 on Port 0 with function USB Overcurrent Detect
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06, IOfuncts::USB_OVCUR_DET> {
  static constexpr std::uint8_t pinIndex = 6u;
  static constexpr std::uint32_t pinMask = 1 << pinIndex;
  static constexpr std::uint8_t portIndex = 0u;
  static constexpr IOfunctSelects functionSelect = IOfunctSelects::F9;
};

}  // namespace hw
}  // namespace libMcuLL
#endif