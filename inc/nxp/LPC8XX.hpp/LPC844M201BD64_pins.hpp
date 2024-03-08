/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 20234 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC844M201BD64 pin definitions
 */

#ifndef LPC844M201BD64_PINS_HPP
#define LPC844M201BD64_PINS_HPP
namespace libMcuLL {
namespace hw {

enum pinTypeFlags : std::uint8_t {
  NORMAL = 0u,          /**< Normal pin without any special handling */
  IOCON_I2C = (1 << 0), /**< IOCON special handling for I2C */
};
/**
 * @brief Available pins on LPC845M301BD48
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
  PIN30, /**< Pin 30 */
  PIN31, /**< Pin 31 */
};
/**
 * @brief Available ports on LPC845M301BD48
 *
 */
enum class IOports : std::uint8_t {
  PORT0, /**< Port 0 */
  PORT1, /**< Port 1 */
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
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN00> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 17u;
  static constexpr std::uint8_t gpioPinIndex = 0u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_0;
};
/**
 * @brief Specialization for Pin 1 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN01> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 11u;
  static constexpr std::uint8_t gpioPinIndex = 1u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_1;
};
/**
 * @brief Specialization for Pin 2 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN02> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 6u;
  static constexpr std::uint8_t gpioPinIndex = 2u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_2;
};
/**
 * @brief Specialization for Pin 3 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN03> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 5u;
  static constexpr std::uint8_t gpioPinIndex = 3u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_3;
};
/**
 * @brief Specialization for Pin 4 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN04> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 4u;
  static constexpr std::uint8_t gpioPinIndex = 4u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_4;
};
/**
 * @brief Specialization for Pin 5 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN05> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 3u;
  static constexpr std::uint8_t gpioPinIndex = 5u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_5;
};
/**
 * @brief Specialization for Pin 6 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN06> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 16u;
  static constexpr std::uint8_t gpioPinIndex = 6u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_6;
};
/**
 * @brief Specialization for Pin 7 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN07> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 15u;
  static constexpr std::uint8_t gpioPinIndex = 7u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_7;
};
/**
 * @brief Specialization for Pin 8 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN08> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 14u;
  static constexpr std::uint8_t gpioPinIndex = 8u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_8;
};
/**
 * @brief Specialization for Pin 9 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN09> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 13u;
  static constexpr std::uint8_t gpioPinIndex = 9u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_9;
};
/**
 * @brief Specialization for Pin 10 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN10> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::IOCON_I2C;
  static constexpr std::uint8_t ioconIndex = 8u;
  static constexpr std::uint8_t gpioPinIndex = 10u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_10;
};
/**
 * @brief Specialization for Pin 11 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN11> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::IOCON_I2C;
  static constexpr std::uint8_t ioconIndex = 7u;
  static constexpr std::uint8_t gpioPinIndex = 11u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_11;
};
/**
 * @brief Specialization for Pin 12 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN12> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 2u;
  static constexpr std::uint8_t gpioPinIndex = 12u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_12;
};
/**
 * @brief Specialization for Pin 13 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN13> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 1u;
  static constexpr std::uint8_t gpioPinIndex = 13u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_13;
};
/**
 * @brief Specialization for Pin 14 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN14> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 18u;
  static constexpr std::uint8_t gpioPinIndex = 14u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_14;
};
/**
 * @brief Specialization for Pin 15 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN15> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 10u;
  static constexpr std::uint8_t gpioPinIndex = 15u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_15;
};
/**
 * @brief Specialization for Pin 16 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN16> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 9u;
  static constexpr std::uint8_t gpioPinIndex = 16u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_16;
};
/**
 * @brief Specialization for Pin 17 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN17> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 0u;
  static constexpr std::uint8_t gpioPinIndex = 17u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_17;
};
/**
 * @brief Specialization for Pin 18 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN18> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 30u;
  static constexpr std::uint8_t gpioPinIndex = 18u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_18;
};
/**
 * @brief Specialization for Pin 19 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN19> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 29u;
  static constexpr std::uint8_t gpioPinIndex = 19u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_19;
};
/**
 * @brief Specialization for Pin 20 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN20> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 28u;
  static constexpr std::uint8_t gpioPinIndex = 20u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_20;
};
/**
 * @brief Specialization for Pin 21 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN21> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 27u;
  static constexpr std::uint8_t gpioPinIndex = 21u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_21;
};
/**
 * @brief Specialization for Pin 22 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN22> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 26u;
  static constexpr std::uint8_t gpioPinIndex = 22u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_22;
};
/**
 * @brief Specialization for Pin 23 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN23> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 25u;
  static constexpr std::uint8_t gpioPinIndex = 23u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_23;
};
/**
 * @brief Specialization for Pin 24 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN24> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 24u;
  static constexpr std::uint8_t gpioPinIndex = 24u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_24;
};
/**
 * @brief Specialization for Pin 25 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN25> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 23u;
  static constexpr std::uint8_t gpioPinIndex = 25u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_25;
};
/**
 * @brief Specialization for Pin 26 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN26> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 22u;
  static constexpr std::uint8_t gpioPinIndex = 26u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_26;
};
/**
 * @brief Specialization for Pin 27 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN27> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 21u;
  static constexpr std::uint8_t gpioPinIndex = 27u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_27;
};
/**
 * @brief Specialization for Pin 28 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN28> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 20u;
  static constexpr std::uint8_t gpioPinIndex = 28u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_28;
};
/**
 * @brief Specialization for Pin 29 on Port 0
 *
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN29> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 50u;
  static constexpr std::uint8_t gpioPinIndex = 29u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_29;
};
/**
 * @brief Specialization for Pin 30 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN30> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 51u;
  static constexpr std::uint8_t gpioPinIndex = 30u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_30;
};
/**
 * @brief Specialization for Pin 31 on Port 0
 */
template <>
struct pin<IOports::PORT0, IOpins::PIN31> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 35u;
  static constexpr std::uint8_t gpioPinIndex = 31u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 0u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO0_31;
};
/**
 * @brief Specialization for Pin 0 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN00> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 36u;
  static constexpr std::uint8_t gpioPinIndex = 0u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_0;
};
/**
 * @brief Specialization for Pin 1 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN01> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 37u;
  static constexpr std::uint8_t gpioPinIndex = 1u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_1;
};
/**
 * @brief Specialization for Pin 2 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN02> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 38u;
  static constexpr std::uint8_t gpioPinIndex = 2u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_2;
};
/**
 * @brief Specialization for Pin 3 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN03> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 41u;
  static constexpr std::uint8_t gpioPinIndex = 3u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_3;
};
/**
 * @brief Specialization for Pin 4 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN04> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 42u;
  static constexpr std::uint8_t gpioPinIndex = 4u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_4;
};
/**
 * @brief Specialization for Pin 5 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN05> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 43u;
  static constexpr std::uint8_t gpioPinIndex = 5u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_5;
};
/**
 * @brief Specialization for Pin 6 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN06> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 46u;
  static constexpr std::uint8_t gpioPinIndex = 6u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_6;
};
/**
 * @brief Specialization for Pin 7 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN07> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 49u;
  static constexpr std::uint8_t gpioPinIndex = 7u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_7;
};
/**
 * @brief Specialization for Pin 8 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN08> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 31u;
  static constexpr std::uint8_t gpioPinIndex = 8u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_8;
};
/**
 * @brief Specialization for Pin 9 on Port 1
 */
template <>
struct pin<IOports::PORT1, IOpins::PIN09> {
  static constexpr std::uint8_t typeFlags = pinTypeFlags::NORMAL;
  static constexpr std::uint8_t ioconIndex = 32u;
  static constexpr std::uint8_t gpioPinIndex = 9u;
  static constexpr std::uint32_t gpioPinMask = 1 << gpioPinIndex;
  static constexpr std::uint8_t gpioPortIndex = 1u;
  static constexpr hw::swm::pinAssign pio = hw::swm::pinAssign::PIO1_9;
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
  static constexpr std::uint8_t gpioPortIndex = 0u;
};
/**
 * @brief Specialization for Port 1
 *
 */
template <>
struct port<IOports::PORT1> {
  static constexpr std::uint8_t gpioPortIndex = 1u;
};
}  // namespace hw
}  // namespace libMcuLL

#endif