/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_swm_hw.hpp
 * @brief Register structure and bit definitions for the LPC810 series Switch Matrix
 */
#ifndef LPC81X_SMW_HW_HPP
#define LPC81X_SWM_HW_HPP

namespace libmcuhw::swm {
/**
 * @brief Pin assignment enumeration
 */
enum PinAssignments : std::uint8_t {
  k0_0 = 0u,    /*!< assign to pin P0_0. */
  k0_1 = 1u,    /*!< assign to pin P0_1. */
  k0_2 = 2u,    /*!< assign to pin P0_2. */
  k0_3 = 3u,    /*!< assign to pin P0_3. */
  k0_4 = 4u,    /*!< assign to pin P0_4. */
  k0_5 = 5u,    /*!< assign to pin P0_5. */
  k0_6 = 6u,    /*!< assign to pin P0_6. */
  k0_7 = 7u,    /*!< assign to pin P0_7. */
  k0_8 = 8u,    /*!< assign to pin P0_8. */
  k0_9 = 9u,    /*!< assign to pin P0_9. */
  k0_10 = 10u,  /*!< assign to pin P0_10. */
  k0_11 = 11u,  /*!< assign to pin P0_11. */
  k0_12 = 12u,  /*!< assign to pin P0_12. */
  k0_13 = 13u,  /*!< assign to pin P0_13. */
  k0_14 = 14u,  /*!< assign to pin P0_14. */
  k0_15 = 15u,  /*!< assign to pin P0_15. */
  k0_16 = 16u,  /*!< assign to pin P0_16. */
  k0_17 = 17u,  /*!< assign to pin P0_17. */
  kNone = 0xFFu /*!< assign to nothing */
};
/**
 * @brief Movable pin functions
 */
enum MovableFunctions : std::uint8_t {
  kUsart0TxdOut = 0u,     /*!< UART0 TXD Output */
  kUsart0RxdIn = 1u,      /*!< UART0 RXD Input */
  kUsart0RtsOut = 2u,     /*!< UART0 RTS Output */
  kUsart0CtsIn = 3u,      /*!< UART0 CTS Input */
  kUsart0SclkInOut = 4u,  /*!< UART0 SCLK I/O */
  kUsart1TxdOut = 5u,     /*!< UART1 TXD Output */
  kUsart1RxdIn = 6u,      /*!< UART1 RXD Input */
  kUsart1RtsOut = 7u,     /*!< UART1 RTS Output */
  kUsart1CtsIn = 8u,      /*!< UART1 CTS Input */
  kUsart1SclkInOut = 9u,  /*!< UART1 SCLK I/O */
  kUsart2TxdOut = 10u,    /*!< UART2 TXD Output */
  kUsart2RxdIn = 11u,     /*!< UART2 RXD Input */
  kUsart2RtsOut = 12u,    /*!< UART2 RTS Output */
  kUsart2CtsIn = 13u,     /*!< UART2 CTS Input */
  kUsart2SclkInOut = 14u, /*!< UART2 SCLK I/O */
  kSpi0SckInOut = 15u,    /*!<  SPI0 SCK I/O */
  kSpi0MosiInOut = 16u,   /*!< SPI0 MOSI I/O */
  kSpi0MisoInOut = 17u,   /*!< SPI0 MISO I/O */
  kSpi0SselInOut = 18u,   /*!< SPI0 SSEL I/O */
  kSpi1SckInOut = 19u,    /*!< SPI1 SCK I/O */
  kSpi1MosiInOut = 20u,   /*!< SPI1 MOSI I/O */
  kSpi1MisoInOut = 21u,   /*!< SPI1 MISO I/O */
  kSpi1SselInOut = 22u,   /*!< SPI1 SSEL I/O */
  kSct0In0In = 23u,       /*!< SCT Input 0*/
  kSct0In1In = 24u,       /*!< SCT Input 1*/
  kSct0In2In = 25u,       /*!< SCT Input 2*/
  kSct0In3In = 26u,       /*!< SCT Input 3*/
  kSct0Out0Out = 27u,     /*!< SCT Output 0*/
  kSct0Out1Out = 28u,     /*!< SCT Output 1*/
  kSct0Out2Out = 29u,     /*!< SCT Output 2*/
  kSct0Out3Out = 30u,     /*!< SCT Output 3*/
  kI2c0SdaInOut = 31u,    /*!< I2C SDA I/O */
  kI2c0SclInOut = 32u,    /*!< I2C SCL I/O */
  kAcmpOut = 33u,         /*!< ACMP Output */
  kSclktOut = 34u,        /*!< CLKOUT Output */
  kGpioIntBmatOut = 35u,  /*!< GPIO INT BMAT Output */
};
/**
 * @brief
 */
enum functionFixed : std::uint16_t {
  kAcmpIn1 = (1u << 0), /*!< ACMP I1 */
  kAcmpIn2 = (1u << 1), /*!< ACMP I2 */
  kSwclk = (1u << 2),   /*!< SWCLK */
  kSwdio = (1u << 3),   /*!< SWDIO */
  kXtalIn = (1u << 4),  /*!< XTALIN */
  kXtalOut = (1u << 5), /*!< XTALOUT */
  kReset = (1u << 6),   /*!< Reset */
  kClkin = (1u << 7),   /*!< Clock Input */
  kVddCmp = (1u << 8)   /*!< ACMP VDD*/
};
/**
 * @brief
 */
enum class pinFunctions : std::uint8_t {
  kUart0TxOut,     /*!< UART0 TXD Output */
  kUart0RxIn,      /*!< UART0 RXD Input */
  kUart0RtsOut,    /*!< UART0 RTS Output */
  kUart0CtsIn,     /*!< UART0 CTS Input */
  kUart0SclkInOut, /*!< UART0 SCLK I/O */
  kUart1TxOut,     /*!< UART1 TXD Output */
  kUart1RxIn,      /*!< UART1 RXD Input */
  kUart1RtsOut,    /*!< UART1 RTS Output */
  kUart1CtsIn,     /*!< UART1 CTS Input */
  kUart1SclkInOut, /*!< UART1 SCLK I/O */
  kUart2TxOut,     /*!< UART2 TXD Output */
  kUart2RxIn,      /*!< UART2 RXD Input */
  kUart2RtsOut,    /*!< UART2 RTS Output */
  kUart2CtsIn,     /*!< UART2 CTS Input */
  kUart2SclkInOut, /*!< UART2 SCLK I/O */
  kSpi0SckInOut,   /*!< SPI0 SCK I/O */
  kSpi0MosiInOut,  /*!< SPI0 MOSI I/O */
  kSpi0MisoInOut,  /*!< SPI0 MISO I/O */
  kSpi0SselInOut,  /*!< SPI0 SSEL I/O */
  kSpi1SckInOut,   /*!< SPI1 SCK I/O */
  kSpi1MosiInOut,  /*!< SPI1 MOSI I/O */
  kSpi1MisoInOut,  /*!< SPI1 MISO I/O */
  kSpi1SselInOut,  /*!< SPI1 SSEL I/O */
  kSct0In0In,      /*!< SCT Input 0 */
  kSct0In1In,      /*!< SCT Input 1 */
  kSct0In2In,      /*!< SCT Input 2 */
  kSct0In3In,      /*!< SCT Input 3 */
  kSct0Out0Out,    /*!< SCT Output 0 */
  kSct0Out1Out,    /*!< SCT Output 1 */
  kSct0Out2Out,    /*!< SCT Output 2 */
  kSct0Out3Out,    /*!< SCT Output 3 */
  kI2cSdaInOut,    /*!< I2C SDA I/O */
  kI2cSclInOut,    /*!< I2C SCL I/O */
  kAcmpOut,        /*!< Analog comparator Output */
  kClkOut,         /*!< CLKOUT Output */
  kGpioIntBmatOut, /*!< GPIO pattern matching Output */
  kAcmpIn1,        /*!< Analog comparator input 1 */
  kAcmpIn2,        /*!< Analog comparator input 2 */
  kSwClk,          /*!< SWD clock */
  kSwDio,          /*!< SWD input/output */
  kXtalIn,         /*!< Crystal oscillator input */
  kXtalOut,        /*!< Crystal oscillator output */
  kReset,          /*!< Reset */
  kClkIn,          /*!< Clock Input */
  kVddCmp          /*!< Analog comparator VDD input */
};
/**
 * @brief
 */
enum class pinFunctionTypes : std::uint8_t {
  kMovable, /*!< Function is a movable function */
  kFixed,   /*!< Function is a fixed pin function */
  kClear,   /*!< This function clears */
};
/**
 * @brief pin function base template
 * @tparam T_FUNC pin function
 * @tparam DUMMY  needed for the static_assert
 */
template <pinFunctions T_FUNC, bool DUMMY = false>
struct pinFunction {
  static_assert(DUMMY, "This configuration is invalid!");
};
/**
 * @brief Template specialization for UART 0 TX output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart0TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{0u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for UART 0 RX input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart0RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{0u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for UART 0 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart0RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{0u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for UART 0 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart0CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{0u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for UART 0 SCLK output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart0SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{1u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for UART 1 TX output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart1TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{1u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for UART 1 RX input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart1RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{1u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for UART 1 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart1RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{1u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for UART 1 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart1CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{2u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for UART 1 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart1SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{2u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for UART 2 TX output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart2TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{2u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for UART 2 RX input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart2RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{2u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for UART 2 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart2RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{3u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for UART 2 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart2CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{3u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for UART 2 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kUart2SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{3u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for SPI 0 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSpi0SckInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{3u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for SPI 0 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSpi0MosiInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{4u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for SPI 0 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSpi0MisoInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{4u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for SPI 0 SSEL input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSpi0SselInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{4u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for SPI 1 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSpi1SckInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{4u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for SPI 1 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSpi1MosiInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{5u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for SPI 1 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSpi1MisoInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{5u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for SPI 1 SSEL input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSpi1SselInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{5u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for SCT input 0
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSct0In0In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{5u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for SCT input 1
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSct0In1In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{6u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for SCT input 2
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSct0In2In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{6u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for SCT input 3
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSct0In3In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{6u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for SCT output 0
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSct0Out0Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{6u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for SCT output 1
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSct0Out1Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{7u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for SCT output 2
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSct0Out2Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{7u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for SCT output 3
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSct0Out3Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{7u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for I2C SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kI2cSdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{7u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for I2C SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kI2cSclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{8u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for analog comparator output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kAcmpOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{8u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for Clock output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kClkOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{8u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for GPIO pattern matcher output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kGpioIntBmatOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{8u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for analog comparator input 1
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kAcmpIn1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed};
  static constexpr PinAssignments pio{PinAssignments::k0_0};
  static constexpr functionFixed mask{functionFixed::kAcmpIn1};
};
/**
 * @brief Template specialization for analog comparator input 2
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kAcmpIn2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed};
  static constexpr PinAssignments pio{PinAssignments::k0_1};
  static constexpr functionFixed mask{functionFixed::kAcmpIn2};
};
/**
 * @brief Template specialization for SWD clock
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSwClk> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed};
  static constexpr PinAssignments pio{PinAssignments::k0_3};
  static constexpr functionFixed mask{functionFixed::kSwclk};
};
/**
 * @brief Template specialization for SWD input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kSwDio> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed};
  static constexpr PinAssignments pio{PinAssignments::k0_2};
  static constexpr functionFixed mask{functionFixed::kSwdio};
};
/**
 * @brief Template specialization for crystal input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kXtalIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed};
  static constexpr PinAssignments pio{PinAssignments::k0_8};
  static constexpr functionFixed mask{functionFixed::kXtalIn};
};
/**
 * @brief Template specialization for crystal output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kXtalOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed};
  static constexpr PinAssignments pio{PinAssignments::k0_9};
  static constexpr functionFixed mask{functionFixed::kXtalOut};
};
/**
 * @brief Template specialization for RESET input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kReset> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed};
  static constexpr PinAssignments pio{PinAssignments::k0_5};
  static constexpr functionFixed mask{functionFixed::kReset};
};
/**
 * @brief Template specialization for clock input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kClkIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed};
  static constexpr PinAssignments pio{PinAssignments::k0_1};
  static constexpr functionFixed mask{functionFixed::kClkin};
};
/**
 * @brief Template specialization for analog comparator ladder VDD
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::kVddCmp> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed};
  static constexpr PinAssignments pio{PinAssignments::k0_6};
  static constexpr functionFixed mask{functionFixed::kVddCmp};
};
/**
 * @brief SWM register definitions
 *
 */
struct Swm {
  volatile std::uint32_t PINASSIGN[9];   /*!< Pin Assign register array */
  volatile std::uint32_t RESERVED0[103]; /*!< reserved*/
  volatile std::uint32_t PINENABLE0;     /*!< Pin Enable register */
};
}  // namespace libmcuhw::swm
#endif