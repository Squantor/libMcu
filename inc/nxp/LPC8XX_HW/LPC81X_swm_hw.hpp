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
  Pin0_0 = 0u,   /*!< assign to pin P0_0. */
  Pin0_1 = 1u,   /*!< assign to pin P0_1. */
  Pin0_2 = 2u,   /*!< assign to pin P0_2. */
  Pin0_3 = 3u,   /*!< assign to pin P0_3. */
  Pin0_4 = 4u,   /*!< assign to pin P0_4. */
  Pin0_5 = 5u,   /*!< assign to pin P0_5. */
  Pin0_6 = 6u,   /*!< assign to pin P0_6. */
  Pin0_7 = 7u,   /*!< assign to pin P0_7. */
  Pin0_8 = 8u,   /*!< assign to pin P0_8. */
  Pin0_9 = 9u,   /*!< assign to pin P0_9. */
  Pin0_10 = 10u, /*!< assign to pin P0_10. */
  Pin0_11 = 11u, /*!< assign to pin P0_11. */
  Pin0_12 = 12u, /*!< assign to pin P0_12. */
  Pin0_13 = 13u, /*!< assign to pin P0_13. */
  Pin0_14 = 14u, /*!< assign to pin P0_14. */
  Pin0_15 = 15u, /*!< assign to pin P0_15. */
  Pin0_16 = 16u, /*!< assign to pin P0_16. */
  Pin0_17 = 17u, /*!< assign to pin P0_17. */
  None = 0xFFu   /*!< assign to nothing */
};
/**
 * @brief Movable pin functions
 */
enum MovableFunctions : std::uint8_t {
  Usart0TxdOut = 0u,     /*!< UART0 TXD Output */
  Usart0RxdIn = 1u,      /*!< UART0 RXD Input */
  Usart0RtsOut = 2u,     /*!< UART0 RTS Output */
  Usart0CtsIn = 3u,      /*!< UART0 CTS Input */
  Usart0SclkInOut = 4u,  /*!< UART0 SCLK I/O */
  Usart1TxdOut = 5u,     /*!< UART1 TXD Output */
  Usart1RxdIn = 6u,      /*!< UART1 RXD Input */
  Usart1RtsOut = 7u,     /*!< UART1 RTS Output */
  Usart1CtsIn = 8u,      /*!< UART1 CTS Input */
  Usart1SclkInOut = 9u,  /*!< UART1 SCLK I/O */
  Usart2TxdOut = 10u,    /*!< UART2 TXD Output */
  Usart2RxdIn = 11u,     /*!< UART2 RXD Input */
  Usart2RtsOut = 12u,    /*!< UART2 RTS Output */
  Usart2CtsIn = 13u,     /*!< UART2 CTS Input */
  Usart2SclkInOut = 14u, /*!< UART2 SCLK I/O */
  Spi0SckInOut = 15u,    /*!<  SPI0 SCK I/O */
  Spi0MosiInOut = 16u,   /*!< SPI0 MOSI I/O */
  Spi0MisoInOut = 17u,   /*!< SPI0 MISO I/O */
  Spi0SselInOut = 18u,   /*!< SPI0 SSEL I/O */
  Spi1SckInOut = 19u,    /*!< SPI1 SCK I/O */
  Spi1MosiInOut = 20u,   /*!< SPI1 MOSI I/O */
  Spi1MisoInOut = 21u,   /*!< SPI1 MISO I/O */
  Spi1SselInOut = 22u,   /*!< SPI1 SSEL I/O */
  Sct0In0In = 23u,       /*!< SCT Input 0*/
  Sct0In1In = 24u,       /*!< SCT Input 1*/
  Sct0In2In = 25u,       /*!< SCT Input 2*/
  Sct0In3In = 26u,       /*!< SCT Input 3*/
  Sct0Out0Out = 27u,     /*!< SCT Output 0*/
  Sct0Out1Out = 28u,     /*!< SCT Output 1*/
  Sct0Out2Out = 29u,     /*!< SCT Output 2*/
  Sct0Out3Out = 30u,     /*!< SCT Output 3*/
  I2c0SdaInOut = 31u,    /*!< I2C SDA I/O */
  I2c0SclInOut = 32u,    /*!< I2C SCL I/O */
  AcmpOut = 33u,         /*!< ACMP Output */
  SclktOut = 34u,        /*!< CLKOUT Output */
  GpioIntBmatOut = 35u,  /*!< GPIO INT BMAT Output */
};
/**
 * @brief
 */
enum functionFixed : std::uint16_t {
  AcmpIn1 = (1u << 0), /*!< ACMP I1 */
  AcmpIn2 = (1u << 1), /*!< ACMP I2 */
  Swclk = (1u << 2),   /*!< SWCLK */
  Swdio = (1u << 3),   /*!< SWDIO */
  XtalIn = (1u << 4),  /*!< XTALIN */
  XtalOut = (1u << 5), /*!< XTALOUT */
  Reset = (1u << 6),   /*!< Reset */
  Clkin = (1u << 7),   /*!< Clock Input */
  VddCmp = (1u << 8)   /*!< ACMP VDD*/
};
/**
 * @brief
 */
enum class PinFunctions : std::uint8_t {
  Uart0TxOut,     /*!< UART0 TXD Output */
  Uart0RxIn,      /*!< UART0 RXD Input */
  Uart0RtsOut,    /*!< UART0 RTS Output */
  Uart0CtsIn,     /*!< UART0 CTS Input */
  Uart0SclkInOut, /*!< UART0 SCLK I/O */
  Uart1TxOut,     /*!< UART1 TXD Output */
  Uart1RxIn,      /*!< UART1 RXD Input */
  Uart1RtsOut,    /*!< UART1 RTS Output */
  Uart1CtsIn,     /*!< UART1 CTS Input */
  Uart1SclkInOut, /*!< UART1 SCLK I/O */
  Uart2TxOut,     /*!< UART2 TXD Output */
  Uart2RxIn,      /*!< UART2 RXD Input */
  Uart2RtsOut,    /*!< UART2 RTS Output */
  Uart2CtsIn,     /*!< UART2 CTS Input */
  Uart2SclkInOut, /*!< UART2 SCLK I/O */
  Spi0SckInOut,   /*!< SPI0 SCK I/O */
  Spi0MosiInOut,  /*!< SPI0 MOSI I/O */
  Spi0MisoInOut,  /*!< SPI0 MISO I/O */
  Spi0SselInOut,  /*!< SPI0 SSEL I/O */
  Spi1SckInOut,   /*!< SPI1 SCK I/O */
  Spi1MosiInOut,  /*!< SPI1 MOSI I/O */
  Spi1MisoInOut,  /*!< SPI1 MISO I/O */
  Spi1SselInOut,  /*!< SPI1 SSEL I/O */
  Sct0In0In,      /*!< SCT Input 0 */
  Sct0In1In,      /*!< SCT Input 1 */
  Sct0In2In,      /*!< SCT Input 2 */
  Sct0In3In,      /*!< SCT Input 3 */
  Sct0Out0Out,    /*!< SCT Output 0 */
  Sct0Out1Out,    /*!< SCT Output 1 */
  Sct0Out2Out,    /*!< SCT Output 2 */
  Sct0Out3Out,    /*!< SCT Output 3 */
  I2cSdaInOut,    /*!< I2C SDA I/O */
  I2cSclInOut,    /*!< I2C SCL I/O */
  AcmpOut,        /*!< Analog comparator Output */
  ClkOut,         /*!< CLKOUT Output */
  GpioIntBmatOut, /*!< GPIO pattern matching Output */
  AcmpIn1,        /*!< Analog comparator input 1 */
  AcmpIn2,        /*!< Analog comparator input 2 */
  SwClk,          /*!< SWD clock */
  SwDio,          /*!< SWD input/output */
  XtalIn,         /*!< Crystal oscillator input */
  XtalOut,        /*!< Crystal oscillator output */
  Reset,          /*!< Reset */
  ClkIn,          /*!< Clock Input */
  VddCmp          /*!< Analog comparator VDD input */
};
/**
 * @brief
 */
enum class pinFunctionTypes : std::uint8_t {
  Movable, /*!< Function is a movable function */
  Fixed,   /*!< Function is a fixed pin function */
  Clear,   /*!< This function clears */
};
/**
 * @brief pin function base template
 * @tparam T_FUNC pin function
 * @tparam DUMMY  needed for the static_assert
 */
template <PinFunctions T_FUNC, bool dummy = false>
struct PinFunction {
  static_assert(dummy, "This configuration is invalid!");
};
/**
 * @brief Template specialization for UART 0 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart0TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{0u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for UART 0 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart0RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{0u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for UART 0 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart0RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{0u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for UART 0 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart0CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{0u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for UART 0 SCLK output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart0SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{1u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for UART 1 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{1u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for UART 1 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{1u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for UART 1 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{1u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for UART 1 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{2u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for UART 1 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{2u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for UART 2 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{2u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for UART 2 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{2u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for UART 2 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{3u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for UART 2 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{3u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for UART 2 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{3u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for SPI 0 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0SckInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{3u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for SPI 0 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0MosiInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{4u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for SPI 0 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0MisoInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{4u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for SPI 0 SSEL input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0SselInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{4u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for SPI 1 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi1SckInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{4u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for SPI 1 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi1MosiInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{5u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for SPI 1 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi1MisoInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{5u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for SPI 1 SSEL input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi1SselInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{5u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for SCT input 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Sct0In0In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{5u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for SCT input 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Sct0In1In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{6u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for SCT input 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Sct0In2In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{6u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for SCT input 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Sct0In3In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{6u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for SCT output 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Sct0Out0Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{6u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for SCT output 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Sct0Out1Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{7u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for SCT output 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Sct0Out2Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{7u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for SCT output 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Sct0Out3Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{7u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for I2C SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2cSdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{7u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for I2C SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2cSclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{8u};
  static constexpr std::uint8_t shift{0u};
};
/**
 * @brief Template specialization for analog comparator output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::AcmpOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{8u};
  static constexpr std::uint8_t shift{8u};
};
/**
 * @brief Template specialization for Clock output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::ClkOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{8u};
  static constexpr std::uint8_t shift{16u};
};
/**
 * @brief Template specialization for GPIO pattern matcher output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::GpioIntBmatOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{8u};
  static constexpr std::uint8_t shift{24u};
};
/**
 * @brief Template specialization for analog comparator input 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::AcmpIn1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed};
  static constexpr PinAssignments pio{PinAssignments::Pin0_0};
  static constexpr functionFixed mask{functionFixed::AcmpIn1};
};
/**
 * @brief Template specialization for analog comparator input 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::AcmpIn2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed};
  static constexpr PinAssignments pio{PinAssignments::Pin0_1};
  static constexpr functionFixed mask{functionFixed::AcmpIn2};
};
/**
 * @brief Template specialization for SWD clock
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SwClk> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed};
  static constexpr PinAssignments pio{PinAssignments::Pin0_3};
  static constexpr functionFixed mask{functionFixed::Swclk};
};
/**
 * @brief Template specialization for SWD input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SwDio> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed};
  static constexpr PinAssignments pio{PinAssignments::Pin0_2};
  static constexpr functionFixed mask{functionFixed::Swdio};
};
/**
 * @brief Template specialization for crystal input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::XtalIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed};
  static constexpr PinAssignments pio{PinAssignments::Pin0_8};
  static constexpr functionFixed mask{functionFixed::XtalIn};
};
/**
 * @brief Template specialization for crystal output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::XtalOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed};
  static constexpr PinAssignments pio{PinAssignments::Pin0_9};
  static constexpr functionFixed mask{functionFixed::XtalOut};
};
/**
 * @brief Template specialization for RESET input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Reset> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed};
  static constexpr PinAssignments pio{PinAssignments::Pin0_5};
  static constexpr functionFixed mask{functionFixed::Reset};
};
/**
 * @brief Template specialization for clock input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::ClkIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed};
  static constexpr PinAssignments pio{PinAssignments::Pin0_1};
  static constexpr functionFixed mask{functionFixed::Clkin};
};
/**
 * @brief Template specialization for analog comparator ladder VDD
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::VddCmp> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed};
  static constexpr PinAssignments pio{PinAssignments::Pin0_6};
  static constexpr functionFixed mask{functionFixed::VddCmp};
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