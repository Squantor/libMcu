/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC844M201BD64_pins.hpp
 * @brief LPC844M201BD64 pin definitions
 */

#ifndef LPC844M201BD64_PINS_HPP
#define LPC844M201BD64_PINS_HPP
namespace libmcuhw {
/**
 * @brief Pin type flags used for the LPC844
 */
enum PinTypeFlags : std::uint8_t {
  kNormal = 0u,         /*!< Normal pin without any special handling */
  kIoconI2c = (1 << 0), /*!< IOCON special handling for I2C */
};
/**
 * @brief Available pins on LPC845M301BD48
 *
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
  kPin30, /*!< Pin 30 */
  kPin31, /*!< Pin 31 */
};
/**
 * @brief Available ports on LPC845M301BD48
 *
 */
enum class IoPorts : std::uint8_t {
  PORT0, /*!< Port 0 */
  PORT1, /*!< Port 1 */
};
/**
 * @brief base I/O pin template
 *
 * @tparam T_PORT IO port
 * @tparam T_PIN  IO pin
 */
template <IoPorts T_PORT, IoPins T_PIN, bool DUMMY = false>
struct Pin {
  static_assert(DUMMY, "This I/O pin configuration is invalid!");
};
/**
 * @brief Specialization for Pin 0 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin00> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 17u;
  static constexpr std::uint8_t gpio_pin_index = 0u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::k0_0};
};
/**
 * @brief Specialization for Pin 1 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin01> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 11u;
  static constexpr std::uint8_t gpio_pin_index = 1u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::k0_1};
};
/**
 * @brief Specialization for Pin 2 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin02> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 6u;
  static constexpr std::uint8_t gpio_pin_index = 2u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_2};
};
/**
 * @brief Specialization for Pin 3 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin03> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 5u;
  static constexpr std::uint8_t gpio_pin_index = 3u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_3};
};
/**
 * @brief Specialization for Pin 4 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin04> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 4u;
  static constexpr std::uint8_t gpio_pin_index = 4u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_4};
};
/**
 * @brief Specialization for Pin 5 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin05> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 3u;
  static constexpr std::uint8_t gpio_pin_index = 5u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_5};
};
/**
 * @brief Specialization for Pin 6 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin06> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 16u;
  static constexpr std::uint8_t gpio_pin_index = 6u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_6};
};
/**
 * @brief Specialization for Pin 7 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin07> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 15u;
  static constexpr std::uint8_t gpio_pin_index = 7u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_7};
};
/**
 * @brief Specialization for Pin 8 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin08> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 14u;
  static constexpr std::uint8_t gpio_pin_index = 8u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_8};
};
/**
 * @brief Specialization for Pin 9 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin09> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 13u;
  static constexpr std::uint8_t gpio_pin_index = 9u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_9};
};
/**
 * @brief Specialization for Pin 10 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin10> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kIoconI2c;
  static constexpr std::uint8_t iocon_index = 8u;
  static constexpr std::uint8_t gpio_pin_index = 10u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_10};
};
/**
 * @brief Specialization for Pin 11 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin11> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kIoconI2c;
  static constexpr std::uint8_t iocon_index = 7u;
  static constexpr std::uint8_t gpio_pin_index = 11u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_11};
};
/**
 * @brief Specialization for Pin 12 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin12> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 2u;
  static constexpr std::uint8_t gpio_pin_index = 12u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_12};
};
/**
 * @brief Specialization for Pin 13 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin13> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 1u;
  static constexpr std::uint8_t gpio_pin_index = 13u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_13};
};
/**
 * @brief Specialization for Pin 14 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin14> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 18u;
  static constexpr std::uint8_t gpio_pin_index = 14u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_14};
};
/**
 * @brief Specialization for Pin 15 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin15> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 10u;
  static constexpr std::uint8_t gpio_pin_index = 15u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_15};
};
/**
 * @brief Specialization for Pin 16 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin16> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 9u;
  static constexpr std::uint8_t gpio_pin_index = 16u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_16};
};
/**
 * @brief Specialization for Pin 17 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin17> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 0u;
  static constexpr std::uint8_t gpio_pin_index = 17u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_17};
};
/**
 * @brief Specialization for Pin 18 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin18> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 30u;
  static constexpr std::uint8_t gpio_pin_index = 18u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_18};
};
/**
 * @brief Specialization for Pin 19 on Port 0
 *
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin19> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 29u;
  static constexpr std::uint8_t gpio_pin_index = 19u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_19};
};
/**
 * @brief Specialization for Pin 20 on Port 0
 *
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin20> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 28u;
  static constexpr std::uint8_t gpio_pin_index = 20u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_20};
};
/**
 * @brief Specialization for Pin 21 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin21> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 27u;
  static constexpr std::uint8_t gpio_pin_index = 21u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_21};
};
/**
 * @brief Specialization for Pin 22 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin22> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 26u;
  static constexpr std::uint8_t gpio_pin_index = 22u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_22};
};
/**
 * @brief Specialization for Pin 23 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin23> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 25u;
  static constexpr std::uint8_t gpio_pin_index = 23u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_23};
};
/**
 * @brief Specialization for Pin 24 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin24> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 24u;
  static constexpr std::uint8_t gpio_pin_index = 24u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_24};
};
/**
 * @brief Specialization for Pin 25 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin25> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 23u;
  static constexpr std::uint8_t gpio_pin_index = 25u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_25};
};
/**
 * @brief Specialization for Pin 26 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin26> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 22u;
  static constexpr std::uint8_t gpio_pin_index = 26u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_26};
};
/**
 * @brief Specialization for Pin 27 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin27> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 21u;
  static constexpr std::uint8_t gpio_pin_index = 27u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_27};
};
/**
 * @brief Specialization for Pin 28 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin28> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 20u;
  static constexpr std::uint8_t gpio_pin_index = 28u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_28};
};
/**
 * @brief Specialization for Pin 29 on Port 0
 *
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin29> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 50u;
  static constexpr std::uint8_t gpio_pin_index = 29u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_29};
};
/**
 * @brief Specialization for Pin 30 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin30> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 51u;
  static constexpr std::uint8_t gpio_pin_index = 30u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_30};
};
/**
 * @brief Specialization for Pin 31 on Port 0
 */
template <>
struct Pin<IoPorts::PORT0, IoPins::kPin31> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 35u;
  static constexpr std::uint8_t gpio_pin_index = 31u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 0u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO0_31};
};
/**
 * @brief Specialization for Pin 0 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin00> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 36u;
  static constexpr std::uint8_t gpio_pin_index = 0u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_0};
};
/**
 * @brief Specialization for Pin 1 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin01> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 37u;
  static constexpr std::uint8_t gpio_pin_index = 1u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_1};
};
/**
 * @brief Specialization for Pin 2 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin02> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 38u;
  static constexpr std::uint8_t gpio_pin_index = 2u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_2};
};
/**
 * @brief Specialization for Pin 3 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin03> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 41u;
  static constexpr std::uint8_t gpio_pin_index = 3u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_3};
};
/**
 * @brief Specialization for Pin 4 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin04> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 42u;
  static constexpr std::uint8_t gpio_pin_index = 4u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_4};
};
/**
 * @brief Specialization for Pin 5 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin05> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 43u;
  static constexpr std::uint8_t gpio_pin_index = 5u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_5};
};
/**
 * @brief Specialization for Pin 6 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin06> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 46u;
  static constexpr std::uint8_t gpio_pin_index = 6u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_6};
};
/**
 * @brief Specialization for Pin 7 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin07> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 49u;
  static constexpr std::uint8_t gpio_pin_index = 7u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_7};
};
/**
 * @brief Specialization for Pin 8 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin08> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 31u;
  static constexpr std::uint8_t gpio_pin_index = 8u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_8};
};
/**
 * @brief Specialization for Pin 9 on Port 1
 */
template <>
struct Pin<IoPorts::PORT1, IoPins::kPin09> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::kNormal;
  static constexpr std::uint8_t iocon_index = 32u;
  static constexpr std::uint8_t gpio_pin_index = 9u;
  static constexpr std::uint32_t gpio_pin_mask = 1 << gpio_pin_index;
  static constexpr std::uint8_t gpio_port_index = 1u;
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::PIO1_9};
};
/**
 * @brief base I/O port template
 * @tparam T_PORT IO port
 */
template <IoPorts T_PORT, bool DUMMY = false>
struct Port {
  static_assert(DUMMY, "This I/O port configuration is invalid!");
};
/**
 * @brief Specialization for Port 0
 */
template <>
struct Port<IoPorts::PORT0> {
  static constexpr std::uint8_t gpio_port_index = 0u;
};
/**
 * @brief Specialization for Port 1
 */
template <>
struct Port<IoPorts::PORT1> {
  static constexpr std::uint8_t gpio_port_index = 1u;
};
}  // namespace libmcuhw
#endif