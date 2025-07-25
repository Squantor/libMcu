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
  Normal = 0u,         /*!< Normal pin without any special handling */
  IoconI2c = (1 << 0), /*!< IOCON special handling for I2C */
};
/**
 * @brief Available pins on LPC845M301BD48
 *
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
  Pin30, /*!< Pin 30 */
  Pin31, /*!< Pin 31 */
};
/**
 * @brief Available ports on LPC845M301BD48
 *
 */
enum class IoPorts : std::uint8_t {
  Port0, /*!< Port 0 */
  Port1, /*!< Port 1 */
};
/**
 * @brief base I/O pin template
 *
 * @tparam T_PORT IO port
 * @tparam T_PIN  IO pin
 */
template <IoPorts port, IoPins pin, bool dummy = false>
struct Pin {
  static_assert(dummy, "This I/O pin configuration is invalid!");
};
/**
 * @brief Specialization for Pin 0 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin00> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin01> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin02> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin03> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin04> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin05> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin06> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin07> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin08> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin09> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin10> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::IoconI2c;
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
struct Pin<IoPorts::Port0, IoPins::Pin11> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::IoconI2c;
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
struct Pin<IoPorts::Port0, IoPins::Pin12> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin13> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin14> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin15> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin16> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin17> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin18> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin19> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin20> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin21> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin22> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin23> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin24> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin25> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin26> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin27> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin28> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin29> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin30> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port0, IoPins::Pin31> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin00> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin01> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin02> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin03> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin04> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin05> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin06> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin07> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin08> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
struct Pin<IoPorts::Port1, IoPins::Pin09> {
  static constexpr std::uint8_t type_flags = PinTypeFlags::Normal;
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
template <IoPorts port, bool dummy = false>
struct Port {
  static_assert(dummy, "This I/O port configuration is invalid!");
};
/**
 * @brief Specialization for Port 0
 */
template <>
struct Port<IoPorts::Port0> {
  static constexpr std::uint8_t gpio_port_index = 0u;
};
/**
 * @brief Specialization for Port 1
 */
template <>
struct Port<IoPorts::Port1> {
  static constexpr std::uint8_t gpio_port_index = 1u;
};
}  // namespace libmcuhw
#endif