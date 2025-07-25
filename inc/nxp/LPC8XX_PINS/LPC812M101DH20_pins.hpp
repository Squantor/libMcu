/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC812M101DH20_pins.hpp
 * @brief LPC812M101DH20 pin definitions
 */

#ifndef LPC812M101DH20_PINS_HPP
#define LPC812M101DH20_PINS_HPP
namespace libmcuhw {
/**
 * @brief Pin type flags used for the LPC812
 */
enum PinTypeFlags : std::uint8_t {
  Normal = 0u,          /*!< Normal pin without any special handling */
  IoconI2c = (1u << 0), /*!< IOCON special handling for I2C */
};

/**
 * @brief Available pins on LPC812M101DH20
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
};
/**
 * @brief Available ports on LPC812M101DH20
 */
enum class IoPorts : std::uint8_t {
  Port0, /*!< Port 0 */
};
/**
 * @brief base I/O pin template
 * @tparam T_PORT IO port
 * @tparam T_PIN  IO pin
 */
template <IoPorts port, IoPins pin, bool dummy = false>
struct Pin {
  static_assert(dummy, "This I/O pin configuration is invalid!");
};
/**
 * @brief Specialization for Pin 0 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin00> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{17u};
  static constexpr std::uint8_t gpio_pin_index{0u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_0};
};

/**
 * @brief Specialization for Pin 1 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{11u};
  static constexpr std::uint8_t gpio_pin_index{1u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_1};
};

/**
 * @brief Specialization for Pin 2 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{6u};
  static constexpr std::uint8_t gpio_pin_index{2u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_2};
};

/**
 * @brief Specialization for Pin 3 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{5u};
  static constexpr std::uint8_t gpio_pin_index{3u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_3};
};

/**
 * @brief Specialization for Pin 4 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{4u};
  static constexpr std::uint8_t gpio_pin_index{4u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_4};
};

/**
 * @brief Specialization for Pin 5 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{3u};
  static constexpr std::uint8_t gpio_pin_index{5u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_5};
};

/**
 * @brief Specialization for Pin 6 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{16u};
  static constexpr std::uint8_t gpio_pin_index{6u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_6};
};

/**
 * @brief Specialization for Pin 7 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{15u};
  static constexpr std::uint8_t gpio_pin_index{7u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_7};
};

/**
 * @brief Specialization for Pin 8 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{14u};
  static constexpr std::uint8_t gpio_pin_index{8u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_8};
};

/**
 * @brief Specialization for Pin 9 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{13u};
  static constexpr std::uint8_t gpio_pin_index{9u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_9};
};

/**
 * @brief Specialization for Pin 10 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::IoconI2c};
  static constexpr std::uint8_t iocon_index{8u};
  static constexpr std::uint8_t gpio_pin_index{10u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_10};
};

/**
 * @brief Specialization for Pin 11 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::IoconI2c};
  static constexpr std::uint8_t iocon_index{7u};
  static constexpr std::uint8_t gpio_pin_index{11u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_11};
};

/**
 * @brief Specialization for Pin 12 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{2u};
  static constexpr std::uint8_t gpio_pin_index{12u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_12};
};

/**
 * @brief Specialization for Pin 13 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{1u};
  static constexpr std::uint8_t gpio_pin_index{13u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_13};
};

/**
 * @brief Specialization for Pin 14 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{18u};
  static constexpr std::uint8_t gpio_pin_index{14u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_14};
};

/**
 * @brief Specialization for Pin 15 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{10u};
  static constexpr std::uint8_t gpio_pin_index{15u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_15};
};

/**
 * @brief Specialization for Pin 16 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{9u};
  static constexpr std::uint8_t gpio_pin_index{16u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_16};
};

/**
 * @brief Specialization for Pin 17 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17> {
  static constexpr std::uint8_t type_flags{PinTypeFlags::Normal};
  static constexpr std::uint8_t iocon_index{0u};
  static constexpr std::uint8_t gpio_pin_index{17u};
  static constexpr std::uint32_t gpio_pin_mask{1u << gpio_pin_index};
  static constexpr std::uint8_t gpio_port_index{0u};
  static constexpr libmcuhw::swm::PinAssignments pio{libmcuhw::swm::PinAssignments::Pin0_17};
};

/**
 * @brief base I/O port template
 *
 * @tparam T_PORT IO port
 */
template <IoPorts port, bool dummy = false>
struct Port {
  static_assert(dummy, "This I/O port configuration is invalid!");
};
/**
 * @brief Specialization for Port 0
 *
 */
template <>
struct Port<IoPorts::Port0> {
  static constexpr std::uint8_t gpio_port_index{0u};
};
}  // namespace libmcuhw
#endif