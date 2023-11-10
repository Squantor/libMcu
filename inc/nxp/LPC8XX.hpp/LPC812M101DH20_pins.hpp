/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC812M101DH20 pin definitions
 */

#ifndef LPC812M101DH20_PINS_HPP
#define LPC812M101DH20_PINS_HPP
namespace libMcuLL {
namespace hw {

enum pinTypeFlags : std::uint8_t {
  NORMAL = 0,           /**< Normal pin without any special handling */
  IOCON_I2C = (1 << 0), /**< IOCON special handling for I2C */
};

/**
 * @brief Available pins on LPC812M101DH20
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
};

/**
 * @brief Available ports on LPC812M101DH20
 *
 */
enum class IOports : std::uint8_t {
  PORT0, /**< Port 0 */
};

/**
 * @brief base I/O pin template
 *
 * @tparam T_PORT IO port
 * @tparam T_PIN  IO pin
 */
template <IOports T_PORT, IOpins T_PIN, bool DUMMY = false>
struct pin {
  static_assert(DUMMY, "This I/O pin configuration is invalid!");
};

/**
 * @brief Specialization for Pin 0 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 17;
  static constexpr std::uint8_t gpioPinIndex = 0;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_0;
};

/**
 * @brief Specialization for Pin 1 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 11;
  static constexpr std::uint8_t gpioPinIndex = 1;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_1;
};

/**
 * @brief Specialization for Pin 2 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 6;
  static constexpr std::uint8_t gpioPinIndex = 2;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_2;
};

/**
 * @brief Specialization for Pin 3 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 5;
  static constexpr std::uint8_t gpioPinIndex = 3;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_3;
};

/**
 * @brief Specialization for Pin 4 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 4;
  static constexpr std::uint8_t gpioPinIndex = 4;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_4;
};

/**
 * @brief Specialization for Pin 5 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 3;
  static constexpr std::uint8_t gpioPinIndex = 5;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_5;
};

/**
 * @brief Specialization for Pin 6 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 16;
  static constexpr std::uint8_t gpioPinIndex = 6;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_6;
};

/**
 * @brief Specialization for Pin 7 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 15;
  static constexpr std::uint8_t gpioPinIndex = 7;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_7;
};

/**
 * @brief Specialization for Pin 8 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 14;
  static constexpr std::uint8_t gpioPinIndex = 8;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_8;
};

/**
 * @brief Specialization for Pin 9 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 13;
  static constexpr std::uint8_t gpioPinIndex = 9;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_9;
};

/**
 * @brief Specialization for Pin 10 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::IOCON_I2C;
  static constexpr std::uint8_t ioconIndex = 8;
  static constexpr std::uint8_t gpioPinIndex = 10;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_10;
};

/**
 * @brief Specialization for Pin 11 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::IOCON_I2C;
  static constexpr std::uint8_t ioconIndex = 7;
  static constexpr std::uint8_t gpioPinIndex = 11;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_11;
};

/**
 * @brief Specialization for Pin 12 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 2;
  static constexpr std::uint8_t gpioPinIndex = 12;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_12;
};

/**
 * @brief Specialization for Pin 13 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 1;
  static constexpr std::uint8_t gpioPinIndex = 13;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_13;
};

/**
 * @brief Specialization for Pin 14 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 18;
  static constexpr std::uint8_t gpioPinIndex = 14;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_14;
};

/**
 * @brief Specialization for Pin 15 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 10;
  static constexpr std::uint8_t gpioPinIndex = 15;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_15;
};

/**
 * @brief Specialization for Pin 16 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 9;
  static constexpr std::uint8_t gpioPinIndex = 16;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_16;
};

/**
 * @brief Specialization for Pin 17 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 0;
  static constexpr std::uint8_t gpioPinIndex = 17;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_17;
};

/**
 * @brief base I/O port template
 *
 * @tparam T_PORT IO port
 */
template <IOports T_PORT, bool DUMMY = false>
struct port {
  static_assert(DUMMY, "This I/O port configuration is invalid!");
};

/**
 * @brief Specialization for Port 0
 *
 */
template <>
struct port<IOports::PORT0> {
  static constexpr std::uint8_t gpioPortIndex = 0;
};

}  // namespace hw
}  // namespace libMcuLL

#endif