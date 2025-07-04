/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_swm_hw.hpp
 * @brief Register structure and bit definitions for the LPC840 series Switch Matrix
 */
#ifndef LPC84X_SMW_HW_HPP
#define LPC84X_SWM_HW_HPP

namespace libmcuhw::swm {
/**
 * @brief
 */
enum PinAssignments : std::uint8_t {
  PinAssign0_0 = 0u,    /*!< assign to pin P0_0. */
  PinAssign0_1 = 1u,    /*!< assign to pin P0_1. */
  PinAssign0_2 = 2u,    /*!< assign to pin P0_2. */
  PinAssign0_3 = 3u,    /*!< assign to pin P0_3. */
  PinAssign0_4 = 4u,    /*!< assign to pin P0_4. */
  PinAssign0_5 = 5u,    /*!< assign to pin P0_5. */
  PinAssign0_6 = 6u,    /*!< assign to pin P0_6. */
  PinAssign0_7 = 7u,    /*!< assign to pin P0_7. */
  PinAssign0_8 = 8u,    /*!< assign to pin P0_8. */
  PinAssign0_9 = 9u,    /*!< assign to pin P0_9. */
  PinAssign0_10 = 10u,  /*!< assign to pin P0_10. */
  PinAssign0_11 = 11u,  /*!< assign to pin P0_11. */
  PinAssign0_12 = 12u,  /*!< assign to pin P0_12. */
  PinAssign0_13 = 13u,  /*!< assign to pin P0_13. */
  PinAssign0_14 = 14u,  /*!< assign to pin P0_14. */
  PinAssign0_15 = 15u,  /*!< assign to pin P0_15. */
  PinAssign0_16 = 16u,  /*!< assign to pin P0_16. */
  PinAssign0_17 = 17u,  /*!< assign to pin P0_17. */
  PinAssign0_18 = 18u,  /*!< assign to pin P0_18. */
  PinAssign0_19 = 19u,  /*!< assign to pin P0_19. */
  PinAssign0_20 = 20u,  /*!< assign to pin P0_20. */
  PinAssign0_21 = 21u,  /*!< assign to pin P0_21. */
  PinAssign0_22 = 22u,  /*!< assign to pin P0_22. */
  PinAssign0_23 = 23u,  /*!< assign to pin P0_23. */
  PinAssign0_24 = 24u,  /*!< assign to pin P0_24. */
  PinAssign0_25 = 25u,  /*!< assign to pin P0_25. */
  PinAssign0_26 = 26u,  /*!< assign to pin P0_26. */
  PinAssign0_27 = 27u,  /*!< assign to pin P0_27. */
  PinAssign0_28 = 28u,  /*!< assign to pin P0_28. */
  PinAssign0_29 = 29u,  /*!< assign to pin P0_29. */
  PinAssign0_30 = 30u,  /*!< assign to pin P0_30. */
  PinAssign0_31 = 31u,  /*!< assign to pin P0_31. */
  PinAssign1_0 = 32u,   /*!< assign to pin P1_0. */
  PinAssign1_1 = 33u,   /*!< assign to pin P1_1. */
  PinAssign1_2 = 34u,   /*!< assign to pin P1_2. */
  PinAssign1_3 = 35u,   /*!< assign to pin P1_3. */
  PinAssign1_4 = 36u,   /*!< assign to pin P1_4. */
  PinAssign1_5 = 37u,   /*!< assign to pin P1_5. */
  PinAssign1_6 = 38u,   /*!< assign to pin P1_6. */
  PinAssign1_7 = 39u,   /*!< assign to pin P1_7. */
  PinAssign1_8 = 40u,   /*!< assign to pin P1_8. */
  PinAssign1_9 = 41u,   /*!< assign to pin P1_9. */
  PinAssign1_10 = 42u,  /*!< assign to pin P1_10. */
  PinAssign1_11 = 43u,  /*!< assign to pin P1_11. */
  PinAssign1_12 = 44u,  /*!< assign to pin P1_12. */
  PinAssign1_13 = 45u,  /*!< assign to pin P1_13. */
  PinAssign1_14 = 46u,  /*!< assign to pin P1_14. */
  PinAssign1_15 = 47u,  /*!< assign to pin P1_15. */
  PinAssign1_16 = 48u,  /*!< assign to pin P1_16. */
  PinAssign1_17 = 49u,  /*!< assign to pin P1_17. */
  PinAssign1_18 = 50u,  /*!< assign to pin P1_18. */
  PinAssign1_19 = 51u,  /*!< assign to pin P1_19. */
  PinAssign1_20 = 52u,  /*!< assign to pin P1_20. */
  PinAssign1_21 = 53u,  /*!< assign to pin P1_21. */
  PinAssignNone = 0xFFu /*!< assign to nothing */
};
/**
 * @brief
 */
enum MovableFunctions : std::uint8_t {
  Usart0TxdOut = 0u,       /*!< UART0 TXD Output */
  Usart0RdxIn = 1u,        /*!< UART0 RXD Input */
  Usart0RtsOut = 2u,       /*!< UART0 RTS Output */
  Usart0CtsIn = 3u,        /*!< UART0 CTS Input */
  Usart0SclkInOut = 4u,    /*!< UART0 SCLK I/O */
  Usart1TxdOut = 5u,       /*!< UART1 TXD Output */
  Usart1RxdIn = 6u,        /*!< UART1 RXD Input */
  Usart1RtsOut = 7u,       /*!< UART1 RTS Output */
  Usart1CtsIn = 8u,        /*!< UART1 CTS Input */
  Usart1SclkInOut = 9u,    /*!< UART1 SCLK I/O */
  Usart2TxdOut = 10u,      /*!< UART2 TXD Output */
  Usart2RxdIn = 11u,       /*!< UART2 RXD Input */
  Usart2RtsOut = 12u,      /*!< UART2 RTS Output */
  Usart2CtsIn = 13u,       /*!< UART2 CTS Input */
  Usart2SclkInOut = 14u,   /*!< UART2 SCLK I/O */
  Spi0SckInOut = 15u,      /*!< SPI0 SCK I/O */
  Spi0MosiInOut = 16u,     /*!< SPI0 MOSI I/O */
  Spi0misoInOut = 17u,     /*!< SPI0 MISO I/O */
  Spi0Ssel0InOut = 18u,    /*!< SPI0 SSEL0 I/O */
  Spi0Ssel1InOut = 19u,    /*!< SPI0 SSEL1 I/O */
  Spi0Ssel2InOut = 20u,    /*!< SPI0 SSEL2 I/O */
  Spi0Ssel3InOut = 21u,    /*!< SPI0 SSEL3 I/O */
  Spi1SckInOut = 22u,      /*!< SPI1 SCK I/O */
  Spi1MosiInOut = 23u,     /*!< SPI1 MOSI I/O */
  Spi1MisoInOut = 24u,     /*!< SPI1 MISO I/O */
  Spi1Ssel0InOut = 25u,    /*!< SPI1 SSEL0 I/O */
  Spi1Ssel1InOut = 26u,    /*!< SPI1 SSEL1 I/O */
  SctIn0 = 27u,            /*!< Pin input 0 to the SCT input multiplexer */
  SctIn1 = 28u,            /*!< Pin input 1 to the SCT input multiplexer */
  SctIn2 = 29u,            /*!< Pin input 2 to the SCT input multiplexer */
  SctIn3 = 30u,            /*!< Pin input 3 to the SCT input multiplexer */
  SctOut0 = 31u,           /*!< SCT Output 0 */
  SctOut1 = 32u,           /*!< SCT Output 1 */
  SctOut2 = 33u,           /*!< SCT Output 2 */
  SctOut3 = 34u,           /*!< SCT Output 3 */
  SctOut4 = 35u,           /*!< SCT Output 4 */
  SctOut5 = 36u,           /*!< SCT Output 5 */
  SctOut6 = 37u,           /*!< SCT Output 6 */
  I2c1SdaInOut = 38u,      /*!< I2C1 SDA I/O */
  I2c1SclInOut = 39u,      /*!< I2C1 SCL I/O */
  I2c2SdaInOut = 40u,      /*!< I2C2 SDA I/O */
  I2c2SclInOut = 41u,      /*!< I2C2 SCL I/O */
  I2c3SdaInOut = 42u,      /*!< I2C3 SDA I/O */
  I2c3SclInOut = 43u,      /*!< I2C3 SCL I/O */
  AcmpOutput = 44u,        /*!< analog comparator Output */
  ClkoutOutput = 45u,      /*!< Clock Output */
  GpioIntBmatOutput = 46u, /*!< GPIO pattern matching Output */
  Uart3TxdOutput = 47u,    /*!< Transmitter output for USART3 */
  Uart3RxdInput = 48u,     /*!< Receiver input for USART3 */
  Uart3SclkInOut = 49u,    /*!< Serial clock input/output for USART3 in synchronous mode */
  Uart4TxdOutput = 50u,    /*!< Transmitter output for USART4 */
  Uart4RxdInput = 51u,     /*!< Receiver input for USART4 */
  Uart4SclkInOut = 52u,    /*!< Serial clock input/output for USART4 in synchronous mode */
  Timer0Mat0Output = 53u,  /*!< Timer Match channel 0 */
  Timer0Mat1Output = 54u,  /*!< Timer Match channel 1 */
  Timer0Mat2Output = 55u,  /*!< Timer Match channel 2 */
  Timer0Mat3Output = 56u,  /*!< Timer Match channel 3 */
  Timer0Cap0Input = 57u,   /*!< Timer Capture channel 0 */
  Timer0Cap1Input = 58u,   /*!< Timer Capture channel 1 */
  Timer0Cap2Input = 59u    /*!< Timer Capture channel 2 */
};
/**
 * @brief
 */
enum FixedFunctions0 : std::uint32_t {
  Acmp1 = (1u << 0),       /*!< Analog comparator input 1 */
  Acmp2 = (1u << 1),       /*!< Analog comparator input 2 */
  Acmp3 = (1u << 2),       /*!< Analog comparator input 3 */
  Acmp4 = (1u << 3),       /*!< Analog comparator input 4 */
  Acmp5 = (1u << 4),       /*!< Analog comparator input 5 */
  Swclk = (1u << 5),       /*!< SWCLK */
  Swdio = (1u << 6),       /*!< SWDIO */
  XtalIn = (1u << 7),      /*!< XTALIN */
  XtalOut = (1u << 8),     /*!< XTALOUT */
  Resetn = (1u << 9),      /*!< RESETN */
  Clkin = (1u << 10),      /*!< CLKIN */
  Vddcmp = (1u << 11),     /*!< VDDCMP */
  I2c0Sda = (1u << 12),    /*!< I2C0_SDA */
  I2c0Scl = (1u << 13),    /*!< I2C0_SCL */
  Adc0 = (1u << 14),       /*!< Adc input 0 */
  Adc1 = (1u << 15),       /*!< Adc input 1 */
  Adc2 = (1u << 16),       /*!< Adc input 2 */
  Adc3 = (1u << 17),       /*!< Adc input 3 */
  Adc4 = (1u << 18),       /*!< Adc input 4 */
  Adc5 = (1u << 19),       /*!< Adc input 5 */
  Adc6 = (1u << 20),       /*!< Adc input 6 */
  Adc7 = (1u << 21),       /*!< Adc input 7 */
  Adc8 = (1u << 22),       /*!< Adc input 8 */
  Adc9 = (1u << 23),       /*!< Adc input 9 */
  Adc10 = (1u << 24),      /*!< Adc input 10 */
  Adc11 = (1u << 25),      /*!< Adc input 11 */
  DacOut0 = (1u << 26),    /*!< DACOUT0 */
  Dacout1 = (1u << 27),    /*!< DACOUT1 */
  CapTouchX0 = (1u << 28), /*!< Capacitive Touch 0 */
  CapTouchX1 = (1u << 29), /*!< Capacitive Touch X1 */
  CapTouchX2 = (1u << 30), /*!< Capacitive Touch X2 */
  CapTouchX3 = (1u << 31), /*!< Capacitive Touch X3 */
};
/**
 * @brief
 */
enum FixedFunctions1 : std::uint32_t {
  CapTouchX4 = (1u << 0), /*!< Capacitive Touch X4 */
  CapTouchX5 = (1u << 1), /*!< Capacitive Touch X5 */
  CapTouchX6 = (1u << 2), /*!< Capacitive Touch X6 */
  CapTouchX7 = (1u << 3), /*!< Capacitive Touch X7 */
  CapTouchX8 = (1u << 4), /*!< Capacitive Touch X8 */
  CapTouchYL = (1u << 5), /*!< Capacitive Touch YL */
  CapTouchYH = (1u << 6), /*!< Capacitive Touch YH */
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
  Spi0Ssel0InOut, /*!< SPI0 SSEL0 I/O */
  Spi0Ssel1InOut, /*!< SPI0 SSEL1 I/O */
  Spi0Ssel2InOut, /*!< SPI0 SSEL2 I/O */
  Spi0Ssel3InOut, /*!< SPI0 SSEL3 I/O */
  Spi1SckInOut,   /*!< SPI1 SCK I/O */
  Spi1MosiInOut,  /*!< SPI1 MOSI I/O */
  Spi1MisoInOut,  /*!< SPI1 MISO I/O */
  Spi1Ssel0InOut, /*!< SPI1 SSEL0 I/O */
  Spi1Ssel1InOut, /*!< SPI1 SSEL1 I/O */
  SctIn0,         /*!< Pin input 0 to the SCT input multiplexer */
  SctIn1,         /*!< Pin input 1 to the SCT input multiplexer */
  SctIn2,         /*!< Pin input 2 to the SCT input multiplexer */
  SctIn3,         /*!< Pin input 3 to the SCT input multiplexer */
  SctOut0,        /*!< SCT Output 0 */
  SctOut1,        /*!< SCT Output 1 */
  SctOut2,        /*!< SCT Output 2 */
  SctOut3,        /*!< SCT Output 3 */
  SctOut4,        /*!< SCT Output 4 */
  SctOut5,        /*!< SCT Output 5 */
  SctOut6,        /*!< SCT Output 6 */
  I2c1SdaInOut,   /*!< I2C1 SDA I/O */
  I2c1SclInOut,   /*!< I2C1 SCL I/O */
  I2c2SdaInOut,   /*!< I2C2 SDA I/O */
  I2c2SclInOut,   /*!< I2C2 SCL I/O */
  I2c3SdaInOut,   /*!< I2C3 SDA I/O */
  I2c3SclInOut,   /*!< I2C3 SCL I/O */
  AcmpOut,        /*!< analog comparator Output */
  ClkOut,         /*!< Clock Output */
  GpioPatMatOut,  /*!< GPIO pattern matching Output */
  Uart3TxOut,     /*!< UART3 TXD Output */
  Uart3RxIn,      /*!< UART3 RXD Input */
  Uart3SclkInOut, /*!< UART3 SCLK I/O */
  Uart4TxOut,     /*!< UART4 TXD Output */
  Uart4RxIn,      /*!< UART4 RXD input */
  Uart4SclkInOut, /*!< UART4 SCLK I/O */
  Timer0Mat00Out, /*!< Timer Match output channel 0 */
  Timer0Mat1Out,  /*!< Timer Match output channel 1 */
  Timer0Mat2Out,  /*!< Timer Match output channel 2 */
  Timer0Mat3Out,  /*!< Timer Match output channel 3 */
  Timer0Capt0In,  /*!< Timer Capture channel 0 */
  Timer0Capt1In,  /*!< Timer Capture channel 1 */
  Timer0Capt2In,  /*!< Timer Capture channel 2 */
  AcmpIn1,        /*!< analog comparator input 1 */
  AcmpIn2,        /*!< analog comparator input 2 */
  AcmpIn3,        /*!< analog comparator input 3 */
  AcmpIn4,        /*!< analog comparator input 3 */
  AcmpIn5,        /*!< analog comparator input 3 */
  SwdClk,         /*!< SWD clock */
  SwdIO,          /*!< SWD input/output */
  XtalIn,         /*!< Crystal oscillator input */
  XtalOut,        /*!< Crystal oscillator output */
  ResetIn,        /*!< Reset */
  ClockIn,        /*!< Clock Input */
  VddCmpInput,    /*!< analog comparator vdd input */
  I2c0SdaInOut,   /*!< I2C0 SDA */
  I2c0SclInOut,   /*!< I2C0 SCL */
  Adc0In,         /*!< ADC 0 input */
  Adc1In,         /*!< ADC 1 input */
  Adc2In,         /*!< ADC 2 input */
  Adc3In,         /*!< ADC 3 input */
  Adc4In,         /*!< ADC 4 input */
  Adc5In,         /*!< ADC 5 input */
  Adc6In,         /*!< ADC 6 input */
  Adc7In,         /*!< ADC 7 input */
  Adc8In,         /*!< ADC 8 input */
  Adc9In,         /*!< ADC 9 input */
  Adc10In,        /*!< ADC 10 input */
  Adc11In,        /*!< ADC 10 input */
  DacOut0,        /*!< DAC 0 output */
  DacOut1,        /*!< DAC 1 output */
  CapTouchX0In,   /*!< Capacitive touch X0 */
  CapTouchX1In,   /*!< Capacitive touch X1 */
  CapTouchX2In,   /*!< Capacitive touch X2 */
  CapTouchX3In,   /*!< Capacitive touch X3 */
  CapTouchX4In,   /*!< Capacitive touch X4 */
  CapTouchX5In,   /*!< Capacitive touch X5 */
  CapTouchX6In,   /*!< Capacitive touch X6 */
  CapTouchX7In,   /*!< Capacitive touch X7 */
  CapTouchX8In,   /*!< Capacitive touch X8 */
  CapTouchYLIn,   /*!< Capacitive touch YL */
  CapTouchYHIn,   /*!< Capacitive touch YH */
};
/**
 * @brief
 */
enum class pinFunctionTypes : std::uint8_t {
  Movable, /*!< Function is a movable function */
  Fixed0,  /*!< Function is a fixed pin function on PINENABLE0 */
  Fixed1,  /*!< Function is a fixed pin function on PINENABLE1 */
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
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 0 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart0RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 0 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart0RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 0 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart0CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 0 SCLK output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart0SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 1 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 1 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 1 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 1 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 1 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart1SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 2 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 2 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 2 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 2 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 2 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart2SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 0 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0SckInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 0 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0MosiInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 0 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0MisoInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 0 SSEL 0 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0Ssel0InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 0 SSEL 1 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0Ssel1InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 0 SSEL 2 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0Ssel2InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 0 SSEL 3 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi0Ssel3InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 1 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi1SckInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 1 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi1MosiInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 1 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi1MisoInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 1 SSEL0 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi1Ssel0InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 1 SSEL1 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Spi1Ssel1InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT input multiplexer input 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctIn0> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT input multiplexer input 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctIn1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT input multiplexer input 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctIn2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SCT input multiplexer input 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctIn3> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT output 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctOut0> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT output 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctOut1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT output 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctOut2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SCT output 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctOut3> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT output 4
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctOut4> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT output 5
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctOut5> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT output 6
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SctOut6> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for I2C1 SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2c1SdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for I2C1 SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2c1SclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for I2C2 SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2c2SdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for I2C2 SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2c2SclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for I2C3 SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2c3SdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for I2C3 SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2c3SclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for analog comparator output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::AcmpOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for Clock output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::ClkOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for GPIO pattern matcher output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::GpioPatMatOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 3 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart3TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 3 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart3RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 3 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart3SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 4 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart4TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 4 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart4RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 4 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Uart4SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for Timer 0 Match 0 output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Timer0Mat00Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for Timer 0 Match 1 output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Timer0Mat1Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for Timer 0 Match 2 output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Timer0Mat2Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for Timer 0 Match 3 output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Timer0Mat3Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for Timer 0 Capture 0 input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Timer0Capt0In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for Timer 0 Capture 1 input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Timer0Capt1In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for Timer 0 Capture 2 input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Timer0Capt2In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Movable};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for analog comparator input 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::AcmpIn1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_0};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Acmp1};
};
/**
 * @brief Template specialization for analog comparator input 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::AcmpIn2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_1};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Acmp2};
};
/**
 * @brief Template specialization for analog comparator input 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::AcmpIn3> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_14};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Acmp3};
};
/**
 * @brief Template specialization for analog comparator input 4
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::AcmpIn4> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_23};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Acmp4};
};
/**
 * @brief Template specialization for analog comparator input 5
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::AcmpIn5> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_30};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Acmp5};
};
/**
 * @brief Template specialization for Serial wire debug clock
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SwdClk> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_3};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Swclk};
};
/**
 * @brief Template specialization for Serial wire debug data
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::SwdIO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_2};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Swdio};
};
/**
 * @brief Template specialization for Crystal oscillator input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::XtalIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_8};
  static constexpr FixedFunctions0 mask{FixedFunctions0::XtalIn};
};
/**
 * @brief Template specialization for Crystal oscillator output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::XtalOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_9};
  static constexpr FixedFunctions0 mask{FixedFunctions0::XtalOut};
};
/**
 * @brief Template specialization for Crystal oscillator output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::ResetIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_5};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Resetn};
};
/**
 * @brief Template specialization for Clock input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::ClockIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_1};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Clkin};
};
/**
 * @brief Template specialization for VDD comparator input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::VddCmpInput> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_6};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Vddcmp};
};
/**
 * @brief Template specialization for I2C0 SDA
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2c0SdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_11};
  static constexpr FixedFunctions0 mask{FixedFunctions0::I2c0Sda};
};
/**
 * @brief Template specialization for I2C0 SCL
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::I2c0SclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_10};
  static constexpr FixedFunctions0 mask{FixedFunctions0::I2c0Scl};
};
/**
 * @brief Template specialization for ADC input 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc0In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_7};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc0};
};
/**
 * @brief Template specialization for ADC input 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc1In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_6};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc1};
};
/**
 * @brief Template specialization for ADC input 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc2In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_14};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc2};
};
/**
 * @brief Template specialization for ADC input 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc3In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_23};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc3};
};
/**
 * @brief Template specialization for ADC input 4
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc4In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_22};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc4};
};
/**
 * @brief Template specialization for ADC input 5
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc5In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_21};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc5};
};
/**
 * @brief Template specialization for ADC input 6
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc6In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_20};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc6};
};
/**
 * @brief Template specialization for ADC input 7
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc7In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_19};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc7};
};
/**
 * @brief Template specialization for ADC input 8
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc8In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_18};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc8};
};
/**
 * @brief Template specialization for ADC input 9
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc9In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_17};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc9};
};
/**
 * @brief Template specialization for ADC input 10
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc10In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_13};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc10};
};
/**
 * @brief Template specialization for ADC input 11
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::Adc11In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_4};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Adc11};
};
/**
 * @brief Template specialization for DAC output 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::DacOut0> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_17};
  static constexpr FixedFunctions0 mask{FixedFunctions0::DacOut0};
};
/**
 * @brief Template specialization for DAC output 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::DacOut1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_29};
  static constexpr FixedFunctions0 mask{FixedFunctions0::Dacout1};
};
/**
 * @brief Template specialization for Capacitive touch input X0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchX0In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign0_31};
  static constexpr FixedFunctions0 mask{FixedFunctions0::CapTouchX0};
};
/**
 * @brief Template specialization for Capacitive touch input X1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchX1In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_0};
  static constexpr FixedFunctions0 mask{FixedFunctions0::CapTouchX1};
};
/**
 * @brief Template specialization for Capacitive touch input X2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchX2In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_1};
  static constexpr FixedFunctions0 mask{FixedFunctions0::CapTouchX2};
};
/**
 * @brief Template specialization for Capacitive touch input X3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchX3In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed0};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_2};
  static constexpr FixedFunctions0 mask{FixedFunctions0::CapTouchX3};
};
/**
 * @brief Template specialization for Capacitive touch input X4
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchX4In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed1};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_3};
  static constexpr FixedFunctions1 mask{FixedFunctions1::CapTouchX4};
};
/**
 * @brief Template specialization for Capacitive touch input X5
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchX5In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed1};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_4};
  static constexpr FixedFunctions1 mask{FixedFunctions1::CapTouchX5};
};
/**
 * @brief Template specialization for Capacitive touch input X6
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchX6In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed1};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_5};
  static constexpr FixedFunctions1 mask{FixedFunctions1::CapTouchX6};
};
/**
 * @brief Template specialization for Capacitive touch input X7
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchX7In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed1};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_6};
  static constexpr FixedFunctions1 mask{FixedFunctions1::CapTouchX7};
};
/**
 * @brief Template specialization for Capacitive touch input X8
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchX8In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed1};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_7};
  static constexpr FixedFunctions1 mask{FixedFunctions1::CapTouchX8};
};
/**
 * @brief Template specialization for Capacitive touch input YL
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchYLIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed1};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_8};
  static constexpr FixedFunctions1 mask{FixedFunctions1::CapTouchYL};
};
/**
 * @brief Template specialization for Capacitive touch input YH
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::CapTouchYHIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::Fixed1};
  static constexpr PinAssignments pio{PinAssignments::PinAssign1_9};
  static constexpr FixedFunctions1 mask{FixedFunctions1::CapTouchYH};
};
/**
 * @brief SWM register definitions
 */
struct Swm {
  union {                                  /* offset: 0x0 */
    struct {                               /* offset: 0x0 */
      volatile std::uint32_t PINASSIGN0;   /*!< Pin assign register for kUart0Tx, kUart0Rx, kUart0Rts, kUart0Cts */
      volatile std::uint32_t PINASSIGN1;   /*!< Pin assign register for kUart0SCLK, kUart1Tx, kUart1Rx, kUart1RT */
      volatile std::uint32_t PINASSIGN2;   /*!< Pin assign register for kUart1Cts, kUart1SCLK, U2_Tx, U2_Rx */
      volatile std::uint32_t PINASSIGN3;   /*!< Pin assign register for U2_Rts, U2_Cts, U2_SCLK, kSpi0SCK */
      volatile std::uint32_t PINASSIGN4;   /*!< Pin assign register for kSpi0MOSI, kSpi0MISO, kSpi0SSEL0, kSpi0SSEL1 */
      volatile std::uint32_t PINASSIGN5;   /*!< Pin assign register for kSpi0SSEL2, kSpi0SSEL3, kSpi1SCK, kSpi1MOSI */
      volatile std::uint32_t PINASSIGN6;   /*!< Pin assign register for kSpi1MISO, kSpi1SSEL0, kSpi1SSEL1, SCT0_IN0 */
      volatile std::uint32_t PINASSIGN7;   /*!< Pin assign register for SCT_IN1, SCT_IN2, SCT_IN3, kSctOut0 */
      volatile std::uint32_t PINASSIGN8;   /*!< Pin assign register for kSctOut1, kSctOut2, kSctOut3, kSctOut4 */
      volatile std::uint32_t PINASSIGN9;   /*!< Pin assign register for kSctOut5, kSctOut6, I2C1_SDA, I2C1_SCL */
      volatile std::uint32_t PINASSIGN10;  /*!< Pin assign register for I2C2_SDA, I2C2_SCL, I2C3_SDA, I2C3_SCL */
      volatile std::uint32_t PINASSIGN11;  /*!< Pin assign register for COMP0OutUT, CLKOUT, GPIOINT_BMATCH, UART3_Tx */
      volatile std::uint32_t PINASSIGN12;  /*!< Pin assign register for UART3_Rx, UART3_SCLK, UART4_Tx, UART4_Rx */
      volatile std::uint32_t PINASSIGN13;  /*!< Pin assign register for UART4_SCLK, kTimer0MAT0, kTimer0MAT1, kTimer0MAT2 */
      volatile std::uint32_t PINASSIGN14;  /*!< Pin assign register for kTimer0MAT3, kTimer0CAP0, kTimer0CAP1, kTimer0CAP2 */
    } PINASSIGN;                           /*!< Pin assignment register  */
    volatile std::uint32_t PINASSIGNS[15]; /*!< Pin assign register array */
  }; /* */
  std::uint8_t RESERVED_0[388];      /*!< Reserved */
  volatile std::uint32_t PINENABLE0; /*!< Pin enable register 0. Enables fixed-pin functions */
  volatile std::uint32_t PINENABLE1; /*!< Pin enable register 1. Enables fixed-pin functions */
};
}  // namespace libmcuhw::swm
#endif