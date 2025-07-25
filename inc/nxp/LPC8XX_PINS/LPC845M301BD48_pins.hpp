/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC845M301BD48_pins.hpp
 * @brief LPC845M301BD48 pin definitions
 */

#ifndef LPC845M301BD48_PINS_HPP
#define LPC845M301BD48_PINS_HPP
namespace libmcuhw {
namespace hardware = libmcuhw::swm;

enum PinTypeFlags : std::uint8_t {
  Normal = 0u,          /*!< Normal pin without any special handling */
  IoconI2c = (1u << 0), /*!< IOCON special handling for I2C */
};
/**
 * @brief Available pins on LPC845M301BD48
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
 */
enum class IoPorts : std::uint8_t {
  Port0, /*!< Port 0 */
  Port1, /*!< Port 1 */
};
/**
 * @brief ADC inputs
 */
enum class ADCpins : std::uint8_t {
  PIN0,  /*!< ADC input 0 */
  PIN1,  /*!< ADC input 1 */
  PIN2,  /*!< ADC input 2 */
  PIN3,  /*!< ADC input 3 */
  PIN4,  /*!< ADC input 4 */
  PIN5,  /*!< ADC input 5 */
  PIN6,  /*!< ADC input 6 */
  PIN7,  /*!< ADC input 7 */
  PIN8,  /*!< ADC input 8 */
  PIN9,  /*!< ADC input 9 */
  PIN10, /*!< ADC input 10 */
  PIN11, /*!< ADC input 10 */
};
/**
 * @brief Analog comparator inputs
 */
enum class ACMPpins : std::uint8_t {
  PIN1, /*!< Analog comparator input 1 */
  PIN2, /*!< Analog comparator input 2 */
  PIN3, /*!< Analog comparator input 3 */
  PIN4, /*!< Analog comparator input 4 */
  PIN5, /*!< Analog comparator input 5 */
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
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{17u};
  static constexpr std::uint8_t gpioPinIndex{0u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t acmpPinIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_0};
};
/**
 * @brief Specialization for Pin 1 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin01> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{11u};
  static constexpr std::uint8_t gpioPinIndex{1u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t acmpPinIndex{2u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_1};
};
/**
 * @brief Specialization for Pin 2 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin02> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{6u};
  static constexpr std::uint8_t gpioPinIndex{2u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_2};
};
/**
 * @brief Specialization for Pin 3 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin03> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{5u};
  static constexpr std::uint8_t gpioPinIndex{3u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_3};
};
/**
 * @brief Specialization for Pin 4 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin04> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{4u};
  static constexpr std::uint8_t gpioPinIndex{4u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_4};
};
/**
 * @brief Specialization for Pin 5 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin05> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{3u};
  static constexpr std::uint8_t gpioPinIndex{5u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_5};
};
/**
 * @brief Specialization for Pin 6 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin06> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{16u};
  static constexpr std::uint8_t gpioPinIndex{6u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{6u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_6};
};
/**
 * @brief Specialization for Pin 7 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin07> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{15u};
  static constexpr std::uint8_t gpioPinIndex{7u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_7};
};
/**
 * @brief Specialization for Pin 8 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin08> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{14u};
  static constexpr std::uint8_t gpioPinIndex{8u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_8};
};
/**
 * @brief Specialization for Pin 9 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin09> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{13u};
  static constexpr std::uint8_t gpioPinIndex{9u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_9};
};
/**
 * @brief Specialization for Pin 10 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin10> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::IoconI2c};
  static constexpr std::uint8_t ioconIndex{8u};
  static constexpr std::uint8_t gpioPinIndex{10u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_10};
};
/**
 * @brief Specialization for Pin 11 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin11> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::IoconI2c};
  static constexpr std::uint8_t ioconIndex{7u};
  static constexpr std::uint8_t gpioPinIndex{11u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_11};
};
/**
 * @brief Specialization for Pin 12 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin12> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{2u};
  static constexpr std::uint8_t gpioPinIndex{12u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_12};
};
/**
 * @brief Specialization for Pin 13 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin13> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{1u};
  static constexpr std::uint8_t gpioPinIndex{13u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{13u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_13};
};
/**
 * @brief Specialization for Pin 14 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin14> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{18u};
  static constexpr std::uint8_t gpioPinIndex{14u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{2u};
  static constexpr std::uint8_t acmpPinIndex{3u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_14};
};
/**
 * @brief Specialization for Pin 15 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin15> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{10u};
  static constexpr std::uint8_t gpioPinIndex{15u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_15};
};
/**
 * @brief Specialization for Pin 16 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin16> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{9u};
  static constexpr std::uint8_t gpioPinIndex{16u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_16};
};
/**
 * @brief Specialization for Pin 17 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin17> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{0u};
  static constexpr std::uint8_t gpioPinIndex{17u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{9u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_17};
};
/**
 * @brief Specialization for Pin 18 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin18> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{30u};
  static constexpr std::uint8_t gpioPinIndex{18u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{8u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_18};
};
/**
 * @brief Specialization for Pin 19 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin19> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{29u};
  static constexpr std::uint8_t gpioPinIndex{19u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{7u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_19};
};
/**
 * @brief Specialization for Pin 20 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin20> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{28u};
  static constexpr std::uint8_t gpioPinIndex{20u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{6u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_20};
};
/**
 * @brief Specialization for Pin 21 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin21> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{27u};
  static constexpr std::uint8_t gpioPinIndex{21u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{5u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_21};
};
/**
 * @brief Specialization for Pin 22 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin22> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{26u};
  static constexpr std::uint8_t gpioPinIndex{22u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{4u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_22};
};
/**
 * @brief Specialization for Pin 23 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin23> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{25u};
  static constexpr std::uint8_t gpioPinIndex{23u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t adcPinIndex{3u};
  static constexpr std::uint8_t acmpPinIndex{4u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_23};
};
/**
 * @brief Specialization for Pin 24 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin24> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{24u};
  static constexpr std::uint8_t gpioPinIndex{24u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_24};
};
/**
 * @brief Specialization for Pin 25 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin25> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{23u};
  static constexpr std::uint8_t gpioPinIndex{25u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_25};
};
/**
 * @brief Specialization for Pin 26 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin26> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{22u};
  static constexpr std::uint8_t gpioPinIndex{26u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_26};
};
/**
 * @brief Specialization for Pin 27 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin27> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{21u};
  static constexpr std::uint8_t gpioPinIndex{27u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_27};
};
/**
 * @brief Specialization for Pin 28 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin28> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{20u};
  static constexpr std::uint8_t gpioPinIndex{28u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_28};
};
/**
 * @brief Specialization for Pin 29 on Port 0
 *
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin29> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{50u};
  static constexpr std::uint8_t gpioPinIndex{29u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_29};
};
/**
 * @brief Specialization for Pin 30 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin30> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{51u};
  static constexpr std::uint8_t gpioPinIndex{30u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr std::uint8_t acmpPinIndex{5u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_30};
};
/**
 * @brief Specialization for Pin 31 on Port 0
 */
template <>
struct Pin<IoPorts::Port0, IoPins::Pin31> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{35u};
  static constexpr std::uint8_t gpioPinIndex{31u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{0u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign0_31};
};
/**
 * @brief Specialization for Pin 0 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin00> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{36u};
  static constexpr std::uint8_t gpioPinIndex{0u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_0};
};
/**
 * @brief Specialization for Pin 1 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin01> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{37u};
  static constexpr std::uint8_t gpioPinIndex{1u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_1};
};
/**
 * @brief Specialization for Pin 2 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin02> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{38u};
  static constexpr std::uint8_t gpioPinIndex{2u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_2};
};
/**
 * @brief Specialization for Pin 3 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin03> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{41u};
  static constexpr std::uint8_t gpioPinIndex{3u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_3};
};
/**
 * @brief Specialization for Pin 4 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin04> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{42u};
  static constexpr std::uint8_t gpioPinIndex{4u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_4};
};
/**
 * @brief Specialization for Pin 5 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin05> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{43u};
  static constexpr std::uint8_t gpioPinIndex{5u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_5};
};
/**
 * @brief Specialization for Pin 6 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin06> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{46u};
  static constexpr std::uint8_t gpioPinIndex{6u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_6};
};
/**
 * @brief Specialization for Pin 7 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin07> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{49u};
  static constexpr std::uint8_t gpioPinIndex{7u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_7};
};
/**
 * @brief Specialization for Pin 8 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin08> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{31u};
  static constexpr std::uint8_t gpioPinIndex{8u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_8};
};
/**
 * @brief Specialization for Pin 9 on Port 1
 */
template <>
struct Pin<IoPorts::Port1, IoPins::Pin09> {
  static constexpr std::uint8_t typeFlags{PinTypeFlags::Normal};
  static constexpr std::uint8_t ioconIndex{32u};
  static constexpr std::uint8_t gpioPinIndex{9u};
  static constexpr std::uint32_t gpioPinMask{1u << gpioPinIndex};
  static constexpr std::uint8_t gpioPortIndex{1u};
  static constexpr hardware::PinAssignments pio{hardware::PinAssignments::PinAssign1_9};
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
  static constexpr std::uint8_t gpioPortIndex{0u};
};
/**
 * @brief Specialization for Port 1
 *
 */
template <>
struct Port<IoPorts::Port1> {
  static constexpr std::uint8_t gpioPortIndex{1u};
};
}  // namespace libmcuhw
#endif