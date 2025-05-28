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
  k0_0 = 0u,       /*!< assign to pin P0_0. */
  k0_1 = 1u,       /*!< assign to pin P0_1. */
  k0_2 = 2u,       /*!< assign to pin P0_2. */
  k0_3 = 3u,       /*!< assign to pin P0_3. */
  k0_4 = 4u,       /*!< assign to pin P0_4. */
  k0_5 = 5u,       /*!< assign to pin P0_5. */
  k0_6 = 6u,       /*!< assign to pin P0_6. */
  k0_7 = 7u,       /*!< assign to pin P0_7. */
  k0_8 = 8u,       /*!< assign to pin P0_8. */
  k0_9 = 9u,       /*!< assign to pin P0_9. */
  k0_10 = 10u,     /*!< assign to pin P0_10. */
  k0_11 = 11u,     /*!< assign to pin P0_11. */
  k0_12 = 12u,     /*!< assign to pin P0_12. */
  k0_13 = 13u,     /*!< assign to pin P0_13. */
  k0_14 = 14u,     /*!< assign to pin P0_14. */
  k0_15 = 15u,     /*!< assign to pin P0_15. */
  k0_16 = 16u,     /*!< assign to pin P0_16. */
  k0_17 = 17u,     /*!< assign to pin P0_17. */
  k0_18 = 18u,     /*!< assign to pin P0_18. */
  k0_19 = 19u,     /*!< assign to pin P0_19. */
  k0_20 = 20u,     /*!< assign to pin P0_20. */
  k0_21 = 21u,     /*!< assign to pin P0_21. */
  k0_22 = 22u,     /*!< assign to pin P0_22. */
  k0_23 = 23u,     /*!< assign to pin P0_23. */
  k0_24 = 24u,     /*!< assign to pin P0_24. */
  k0_25 = 25u,     /*!< assign to pin P0_25. */
  k0_26 = 26u,     /*!< assign to pin P0_26. */
  k0_27 = 27u,     /*!< assign to pin P0_27. */
  k0_28 = 28u,     /*!< assign to pin P0_28. */
  k0_29 = 29u,     /*!< assign to pin P0_29. */
  k0_30 = 30u,     /*!< assign to pin P0_30. */
  k0_31 = 31u,     /*!< assign to pin P0_31. */
  k1_0 = 32u,      /*!< assign to pin P1_0. */
  k1_1 = 33u,      /*!< assign to pin P1_1. */
  k1_2 = 34u,      /*!< assign to pin P1_2. */
  k1_3 = 35u,      /*!< assign to pin P1_3. */
  k1_4 = 36u,      /*!< assign to pin P1_4. */
  k1_5 = 37u,      /*!< assign to pin P1_5. */
  k1_6 = 38u,      /*!< assign to pin P1_6. */
  k1_7 = 39u,      /*!< assign to pin P1_7. */
  k1_8 = 40u,      /*!< assign to pin P1_8. */
  k1_9 = 41u,      /*!< assign to pin P1_9. */
  k1_10 = 42u,     /*!< assign to pin P1_10. */
  k1_11 = 43u,     /*!< assign to pin P1_11. */
  k1_12 = 44u,     /*!< assign to pin P1_12. */
  k1_13 = 45u,     /*!< assign to pin P1_13. */
  k1_14 = 46u,     /*!< assign to pin P1_14. */
  k1_15 = 47u,     /*!< assign to pin P1_15. */
  k1_16 = 48u,     /*!< assign to pin P1_16. */
  k1_17 = 49u,     /*!< assign to pin P1_17. */
  k1_18 = 50u,     /*!< assign to pin P1_18. */
  k1_19 = 51u,     /*!< assign to pin P1_19. */
  k1_20 = 52u,     /*!< assign to pin P1_20. */
  k1_21 = 53u,     /*!< assign to pin P1_21. */
  PIO_NONE = 0xFFu /*!< assign to nothing */
};
/**
 * @brief
 */
enum MovableFunctions : std::uint8_t {
  kUsart0TxdOut = 0u,       /*!< UART0 TXD Output */
  kUsart0RdxIn = 1u,        /*!< UART0 RXD Input */
  kUsart0RtsOut = 2u,       /*!< UART0 RTS Output */
  kUsart0CtsIn = 3u,        /*!< UART0 CTS Input */
  kUsart0SclkInOut = 4u,    /*!< UART0 SCLK I/O */
  kUsart1TxdOut = 5u,       /*!< UART1 TXD Output */
  kUsart1RxdIn = 6u,        /*!< UART1 RXD Input */
  kUsart1RtsOut = 7u,       /*!< UART1 RTS Output */
  kUsart1CtsIn = 8u,        /*!< UART1 CTS Input */
  kUsart1SclkInOut = 9u,    /*!< UART1 SCLK I/O */
  kUsart2TxdOut = 10u,      /*!< UART2 TXD Output */
  kUsart2RxdIn = 11u,       /*!< UART2 RXD Input */
  kUsart2RtsOut = 12u,      /*!< UART2 RTS Output */
  kUsart2CtsIn = 13u,       /*!< UART2 CTS Input */
  kUsart2SclkInOut = 14u,   /*!< UART2 SCLK I/O */
  kSpi0SckInOut = 15u,      /*!< SPI0 SCK I/O */
  kSpi0MosiInOut = 16u,     /*!< SPI0 MOSI I/O */
  kSpi0misoInOut = 17u,     /*!< SPI0 MISO I/O */
  kSpi0Ssel0InOut = 18u,    /*!< SPI0 SSEL0 I/O */
  kSpi0Ssel1InOut = 19u,    /*!< SPI0 SSEL1 I/O */
  kSpi0Ssel2InOut = 20u,    /*!< SPI0 SSEL2 I/O */
  kSpi0Ssel3InOut = 21u,    /*!< SPI0 SSEL3 I/O */
  kSpi1SckInOut = 22u,      /*!< SPI1 SCK I/O */
  kSpi1MosiInOut = 23u,     /*!< SPI1 MOSI I/O */
  kSpi1MisoInOut = 24u,     /*!< SPI1 MISO I/O */
  kSpi1Ssel0InOut = 25u,    /*!< SPI1 SSEL0 I/O */
  kSpi1Ssel1InOut = 26u,    /*!< SPI1 SSEL1 I/O */
  kSctIn0 = 27u,            /*!< Pin input 0 to the SCT input multiplexer */
  kSctIn1 = 28u,            /*!< Pin input 1 to the SCT input multiplexer */
  kSctIn2 = 29u,            /*!< Pin input 2 to the SCT input multiplexer */
  kSctIn3 = 30u,            /*!< Pin input 3 to the SCT input multiplexer */
  kSctOut0 = 31u,           /*!< SCT Output 0 */
  kSctOut1 = 32u,           /*!< SCT Output 1 */
  kSctOut2 = 33u,           /*!< SCT Output 2 */
  kSctOut3 = 34u,           /*!< SCT Output 3 */
  kSctOut4 = 35u,           /*!< SCT Output 4 */
  kSctOut5 = 36u,           /*!< SCT Output 5 */
  kSctOut6 = 37u,           /*!< SCT Output 6 */
  kI2c1SdaInOut = 38u,      /*!< I2C1 SDA I/O */
  kI2c1SclInOut = 39u,      /*!< I2C1 SCL I/O */
  kI2c2SdaInOut = 40u,      /*!< I2C2 SDA I/O */
  kI2c2SclInOut = 41u,      /*!< I2C2 SCL I/O */
  kI2c3SdaInOut = 42u,      /*!< I2C3 SDA I/O */
  kI2c3SclInOut = 43u,      /*!< I2C3 SCL I/O */
  kAcmpOutput = 44u,        /*!< analog comparator Output */
  kClkoutOutput = 45u,      /*!< Clock Output */
  kGpioIntBmatOutput = 46u, /*!< GPIO pattern matching Output */
  kUart3TxdOutput = 47u,    /*!< Transmitter output for USART3 */
  kUart3RxdInput = 48u,     /*!< Receiver input for USART3 */
  kUart3SclkInOut = 49u,    /*!< Serial clock input/output for USART3 in synchronous mode */
  kUart4TxdOutput = 50u,    /*!< Transmitter output for USART4 */
  kUart4RxdInput = 51u,     /*!< Receiver input for USART4 */
  kUart4SclkInOut = 52u,    /*!< Serial clock input/output for USART4 in synchronous mode */
  kTimer0Mat0Output = 53u,  /*!< Timer Match channel 0 */
  kTimer0Mat1Output = 54u,  /*!< Timer Match channel 1 */
  kTimer0Mat2Output = 55u,  /*!< Timer Match channel 2 */
  kTimer0Mat3Output = 56u,  /*!< Timer Match channel 3 */
  kTimer0Cap0Input = 57u,   /*!< Timer Capture channel 0 */
  kTimer0Cap1Input = 58u,   /*!< Timer Capture channel 1 */
  kTimer0Cap2Input = 59u    /*!< Timer Capture channel 2 */
};
/**
 * @brief
 */
enum FixedFunctions0 : std::uint32_t {
  kAcmp1 = (1u << 0),       /*!< Analog comparator input 1 */
  kAcmp2 = (1u << 1),       /*!< Analog comparator input 2 */
  kAcmp3 = (1u << 2),       /*!< Analog comparator input 3 */
  kAcmp4 = (1u << 3),       /*!< Analog comparator input 4 */
  kAcmp5 = (1u << 4),       /*!< Analog comparator input 5 */
  kSwclk = (1u << 5),       /*!< SWCLK */
  kSwdio = (1u << 6),       /*!< SWDIO */
  kXtalIn = (1u << 7),      /*!< XTALIN */
  kXtalOut = (1u << 8),     /*!< XTALOUT */
  kResetn = (1u << 9),      /*!< RESETN */
  kClkin = (1u << 10),      /*!< CLKIN */
  kVddcmp = (1u << 11),     /*!< VDDCMP */
  kI2c0Sda = (1u << 12),    /*!< I2C0_SDA */
  kI2c0Scl = (1u << 13),    /*!< I2C0_SCL */
  kAdc0 = (1u << 14),       /*!< Adc input 0 */
  kAdc1 = (1u << 15),       /*!< Adc input 1 */
  kAdc2 = (1u << 16),       /*!< Adc input 2 */
  kAdc3 = (1u << 17),       /*!< Adc input 3 */
  kAdc4 = (1u << 18),       /*!< Adc input 4 */
  kAdc5 = (1u << 19),       /*!< Adc input 5 */
  kAdc6 = (1u << 20),       /*!< Adc input 6 */
  kAdc7 = (1u << 21),       /*!< Adc input 7 */
  kAdc8 = (1u << 22),       /*!< Adc input 8 */
  kAdc9 = (1u << 23),       /*!< Adc input 9 */
  kAdc10 = (1u << 24),      /*!< Adc input 10 */
  kAdc11 = (1u << 25),      /*!< Adc input 11 */
  kDacOut0 = (1u << 26),    /*!< DACOUT0 */
  kDacout1 = (1u << 27),    /*!< DACOUT1 */
  kCapTouchX0 = (1u << 28), /*!< Capacitive Touch 0 */
  kCapTouchX1 = (1u << 29), /*!< Capacitive Touch X1 */
  kCapTouchX2 = (1u << 30), /*!< Capacitive Touch X2 */
  kCapTouchX3 = (1u << 31), /*!< Capacitive Touch X3 */
};
/**
 * @brief
 */
enum FixedFunctions1 : std::uint32_t {
  kCapTouchX4 = (1u << 0), /*!< Capacitive Touch X4 */
  kCapTouchX5 = (1u << 1), /*!< Capacitive Touch X5 */
  kCapTouchX6 = (1u << 2), /*!< Capacitive Touch X6 */
  kCapTouchX7 = (1u << 3), /*!< Capacitive Touch X7 */
  kCapTouchX8 = (1u << 4), /*!< Capacitive Touch X8 */
  kCapTouchYL = (1u << 5), /*!< Capacitive Touch YL */
  kCapTouchYH = (1u << 6), /*!< Capacitive Touch YH */
};
/**
 * @brief
 */
enum class PinFunctions : std::uint8_t {
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
  kSpi0Ssel0InOut, /*!< SPI0 SSEL0 I/O */
  kSpi0Ssel1InOut, /*!< SPI0 SSEL1 I/O */
  kSpi0Ssel2InOut, /*!< SPI0 SSEL2 I/O */
  kSpi0Ssel3InOut, /*!< SPI0 SSEL3 I/O */
  kSpi1SckInOut,   /*!< SPI1 SCK I/O */
  kSpi1MosiInOut,  /*!< SPI1 MOSI I/O */
  kSpi1MisoInOut,  /*!< SPI1 MISO I/O */
  kSpi1Ssel0InOut, /*!< SPI1 SSEL0 I/O */
  kSpi1Ssel1InOut, /*!< SPI1 SSEL1 I/O */
  kSctIn0,         /*!< Pin input 0 to the SCT input multiplexer */
  kSctIn1,         /*!< Pin input 1 to the SCT input multiplexer */
  kSctIn2,         /*!< Pin input 2 to the SCT input multiplexer */
  kSctIn3,         /*!< Pin input 3 to the SCT input multiplexer */
  kSctOut0,        /*!< SCT Output 0 */
  kSctOut1,        /*!< SCT Output 1 */
  kSctOut2,        /*!< SCT Output 2 */
  kSctOut3,        /*!< SCT Output 3 */
  kSctOut4,        /*!< SCT Output 4 */
  kSctOut5,        /*!< SCT Output 5 */
  kSctOut6,        /*!< SCT Output 6 */
  kI2c1SdaInOut,   /*!< I2C1 SDA I/O */
  kI2c1SclInOut,   /*!< I2C1 SCL I/O */
  kI2c2SdaInOut,   /*!< I2C2 SDA I/O */
  kI2c2SclInOut,   /*!< I2C2 SCL I/O */
  kI2c3SdaInOut,   /*!< I2C3 SDA I/O */
  kI2c3SclInOut,   /*!< I2C3 SCL I/O */
  kAcmpOut,        /*!< analog comparator Output */
  kClkOut,         /*!< Clock Output */
  kGpioPatMatOut,  /*!< GPIO pattern matching Output */
  kUart3TxOut,     /*!< UART3 TXD Output */
  kUart3RxIn,      /*!< UART3 RXD Input */
  kUart3SclkInOut, /*!< UART3 SCLK I/O */
  kUart4TxOut,     /*!< UART4 TXD Output */
  kUart4RxIn,      /*!< UART4 RXD input */
  kUart4SclkInOut, /*!< UART4 SCLK I/O */
  kTimer0Mat00Out, /*!< Timer Match output channel 0 */
  kTimer0Mat1Out,  /*!< Timer Match output channel 1 */
  kTimer0Mat2Out,  /*!< Timer Match output channel 2 */
  kTimer0Mat3Out,  /*!< Timer Match output channel 3 */
  kTimer0Capt0In,  /*!< Timer Capture channel 0 */
  kTimer0Capt1In,  /*!< Timer Capture channel 1 */
  kTimer0Capt2In,  /*!< Timer Capture channel 2 */
  kAcmpIn1,        /*!< analog comparator input 1 */
  kAcmpIn2,        /*!< analog comparator input 2 */
  kAcmpIn3,        /*!< analog comparator input 3 */
  kAcmpIn4,        /*!< analog comparator input 3 */
  kAcmpIn5,        /*!< analog comparator input 3 */
  kSwdClk,         /*!< SWD clock */
  kSwdIO,          /*!< SWD input/output */
  kXtalIn,         /*!< Crystal oscillator input */
  kXtalOut,        /*!< Crystal oscillator output */
  kResetIn,        /*!< Reset */
  kClockIn,        /*!< Clock Input */
  kVddCmpInput,    /*!< analog comparator vdd input */
  kI2c0SdaInOut,   /*!< I2C0 SDA */
  kI2c0SclInOut,   /*!< I2C0 SCL */
  kAdc0In,         /*!< ADC 0 input */
  kAdc1In,         /*!< ADC 1 input */
  kAdc2In,         /*!< ADC 2 input */
  kAdc3In,         /*!< ADC 3 input */
  kAdc4In,         /*!< ADC 4 input */
  kAdc5In,         /*!< ADC 5 input */
  kAdc6In,         /*!< ADC 6 input */
  kAdc7In,         /*!< ADC 7 input */
  kAdc8In,         /*!< ADC 8 input */
  kAdc9In,         /*!< ADC 9 input */
  kAdc10In,        /*!< ADC 10 input */
  kAdc11In,        /*!< ADC 10 input */
  kDacOut0,        /*!< DAC 0 output */
  kDacOut1,        /*!< DAC 1 output */
  kCapTouchX0In,   /*!< Capacitive touch X0 */
  kCapTouchX1In,   /*!< Capacitive touch X1 */
  kCapTouchX2In,   /*!< Capacitive touch X2 */
  kCapTouchX3In,   /*!< Capacitive touch X3 */
  kCapTouchX4In,   /*!< Capacitive touch X4 */
  kCapTouchX5In,   /*!< Capacitive touch X5 */
  kCapTouchX6In,   /*!< Capacitive touch X6 */
  kCapTouchX7In,   /*!< Capacitive touch X7 */
  kCapTouchX8In,   /*!< Capacitive touch X8 */
  kCapTouchYLIn,   /*!< Capacitive touch YL */
  kCapTouchYHIn,   /*!< Capacitive touch YH */
};
/**
 * @brief
 */
enum class pinFunctionTypes : std::uint8_t {
  kMovable, /*!< Function is a movable function */
  kFixed0,  /*!< Function is a fixed pin function on PINENABLE0 */
  kFixed1,  /*!< Function is a fixed pin function on PINENABLE1 */
  kClear,   /*!< This function clears */
};
/**
 * @brief pin function base template
 * @tparam T_FUNC pin function
 * @tparam DUMMY  needed for the static_assert
 */
template <PinFunctions T_FUNC, bool DUMMY = false>
struct PinFunction {
  static_assert(DUMMY, "This configuration is invalid!");
};
/**
 * @brief Template specialization for UART 0 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart0TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 0 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart0RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 0 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart0RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 0 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart0CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 0 SCLK output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart0SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 1 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart1TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 1 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart1RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 1 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart1RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 1 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart1CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 1 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart1SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 2 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart2TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 2 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart2RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 2 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart2RtsOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 2 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart2CtsIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 2 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart2SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 0 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi0SckInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 0 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi0MosiInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 0 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi0MisoInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 0 SSEL 0 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi0Ssel0InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 0 SSEL 1 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi0Ssel1InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 0 SSEL 2 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi0Ssel2InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 0 SSEL 3 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi0Ssel3InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 1 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi1SckInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 1 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi1MosiInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 1 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi1MisoInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 1 SSEL0 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi1Ssel0InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 1 SSEL1 input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSpi1Ssel1InOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT input multiplexer input 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctIn0> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT input multiplexer input 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctIn1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT input multiplexer input 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctIn2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SCT input multiplexer input 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctIn3> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT output 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctOut0> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT output 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctOut1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT output 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctOut2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SCT output 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctOut3> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT output 4
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctOut4> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT output 5
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctOut5> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT output 6
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSctOut6> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for I2C1 SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kI2c1SdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for I2C1 SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kI2c1SclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for I2C2 SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kI2c2SdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for I2C2 SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kI2c2SclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for I2C3 SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kI2c3SdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for I2C3 SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kI2c3SclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for analog comparator output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAcmpOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for Clock output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kClkOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for GPIO pattern matcher output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kGpioPatMatOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 3 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart3TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 3 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart3RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 3 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart3SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 4 TX output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart4TxOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 4 RX input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart4RxIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 4 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kUart4SclkInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for Timer 0 Match 0 output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kTimer0Mat00Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for Timer 0 Match 1 output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kTimer0Mat1Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for Timer 0 Match 2 output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kTimer0Mat2Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for Timer 0 Match 3 output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kTimer0Mat3Out> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for Timer 0 Capture 0 input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kTimer0Capt0In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for Timer 0 Capture 1 input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kTimer0Capt1In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for Timer 0 Capture 2 input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kTimer0Capt2In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kMovable};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for analog comparator input 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAcmpIn1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_0};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAcmp1};
};
/**
 * @brief Template specialization for analog comparator input 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAcmpIn2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_1};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAcmp2};
};
/**
 * @brief Template specialization for analog comparator input 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAcmpIn3> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_14};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAcmp3};
};
/**
 * @brief Template specialization for analog comparator input 4
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAcmpIn4> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_23};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAcmp4};
};
/**
 * @brief Template specialization for analog comparator input 5
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAcmpIn5> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_30};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAcmp5};
};
/**
 * @brief Template specialization for Serial wire debug clock
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSwdClk> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_3};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kSwclk};
};
/**
 * @brief Template specialization for Serial wire debug data
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kSwdIO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_2};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kSwdio};
};
/**
 * @brief Template specialization for Crystal oscillator input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kXtalIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_8};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kXtalIn};
};
/**
 * @brief Template specialization for Crystal oscillator output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kXtalOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_9};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kXtalOut};
};
/**
 * @brief Template specialization for Crystal oscillator output
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kResetIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_5};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kResetn};
};
/**
 * @brief Template specialization for Clock input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kClockIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_1};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kClkin};
};
/**
 * @brief Template specialization for VDD comparator input
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kVddCmpInput> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_6};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kVddcmp};
};
/**
 * @brief Template specialization for I2C0 SDA
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kI2c0SdaInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_11};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kI2c0Sda};
};
/**
 * @brief Template specialization for I2C0 SCL
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kI2c0SclInOut> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_10};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kI2c0Scl};
};
/**
 * @brief Template specialization for ADC input 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc0In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_7};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc0};
};
/**
 * @brief Template specialization for ADC input 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc1In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_6};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc1};
};
/**
 * @brief Template specialization for ADC input 2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc2In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_14};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc2};
};
/**
 * @brief Template specialization for ADC input 3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc3In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_23};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc3};
};
/**
 * @brief Template specialization for ADC input 4
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc4In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_22};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc4};
};
/**
 * @brief Template specialization for ADC input 5
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc5In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_21};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc5};
};
/**
 * @brief Template specialization for ADC input 6
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc6In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_20};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc6};
};
/**
 * @brief Template specialization for ADC input 7
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc7In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_19};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc7};
};
/**
 * @brief Template specialization for ADC input 8
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc8In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_18};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc8};
};
/**
 * @brief Template specialization for ADC input 9
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc9In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_17};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc9};
};
/**
 * @brief Template specialization for ADC input 10
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc10In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_13};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc10};
};
/**
 * @brief Template specialization for ADC input 11
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kAdc11In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_4};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kAdc11};
};
/**
 * @brief Template specialization for DAC output 0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kDacOut0> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_17};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kDacOut0};
};
/**
 * @brief Template specialization for DAC output 1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kDacOut1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_29};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kDacout1};
};
/**
 * @brief Template specialization for Capacitive touch input X0
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchX0In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k0_31};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kCapTouchX0};
};
/**
 * @brief Template specialization for Capacitive touch input X1
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchX1In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k1_0};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kCapTouchX1};
};
/**
 * @brief Template specialization for Capacitive touch input X2
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchX2In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k1_1};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kCapTouchX2};
};
/**
 * @brief Template specialization for Capacitive touch input X3
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchX3In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed0};
  static constexpr PinAssignments pio{PinAssignments::k1_2};
  static constexpr FixedFunctions0 mask{FixedFunctions0::kCapTouchX3};
};
/**
 * @brief Template specialization for Capacitive touch input X4
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchX4In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed1};
  static constexpr PinAssignments pio{PinAssignments::k1_3};
  static constexpr FixedFunctions1 mask{FixedFunctions1::kCapTouchX4};
};
/**
 * @brief Template specialization for Capacitive touch input X5
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchX5In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed1};
  static constexpr PinAssignments pio{PinAssignments::k1_4};
  static constexpr FixedFunctions1 mask{FixedFunctions1::kCapTouchX5};
};
/**
 * @brief Template specialization for Capacitive touch input X6
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchX6In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed1};
  static constexpr PinAssignments pio{PinAssignments::k1_5};
  static constexpr FixedFunctions1 mask{FixedFunctions1::kCapTouchX6};
};
/**
 * @brief Template specialization for Capacitive touch input X7
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchX7In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed1};
  static constexpr PinAssignments pio{PinAssignments::k1_6};
  static constexpr FixedFunctions1 mask{FixedFunctions1::kCapTouchX7};
};
/**
 * @brief Template specialization for Capacitive touch input X8
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchX8In> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed1};
  static constexpr PinAssignments pio{PinAssignments::k1_7};
  static constexpr FixedFunctions1 mask{FixedFunctions1::kCapTouchX8};
};
/**
 * @brief Template specialization for Capacitive touch input YL
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchYLIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed1};
  static constexpr PinAssignments pio{PinAssignments::k1_8};
  static constexpr FixedFunctions1 mask{FixedFunctions1::kCapTouchYL};
};
/**
 * @brief Template specialization for Capacitive touch input YH
 * @tparam pinfunction specialization
 */
template <>
struct PinFunction<PinFunctions::kCapTouchYHIn> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::kFixed1};
  static constexpr PinAssignments pio{PinAssignments::k1_9};
  static constexpr FixedFunctions1 mask{FixedFunctions1::kCapTouchYH};
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