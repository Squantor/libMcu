/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series SWM register interface
 */
#ifndef LPC84X_SMW_HW_HPP
#define LPC84X_SWM_HW_HPP

namespace libMcu::hw::swm {
/**
 * @brief
 */
enum pinAssign : std::uint8_t {
  PIO0_0 = 0u,     /**< assign to pin P0_0. */
  PIO0_1 = 1u,     /**< assign to pin P0_1. */
  PIO0_2 = 2u,     /**< assign to pin P0_2. */
  PIO0_3 = 3u,     /**< assign to pin P0_3. */
  PIO0_4 = 4u,     /**< assign to pin P0_4. */
  PIO0_5 = 5u,     /**< assign to pin P0_5. */
  PIO0_6 = 6u,     /**< assign to pin P0_6. */
  PIO0_7 = 7u,     /**< assign to pin P0_7. */
  PIO0_8 = 8u,     /**< assign to pin P0_8. */
  PIO0_9 = 9u,     /**< assign to pin P0_9. */
  PIO0_10 = 10u,   /**< assign to pin P0_10. */
  PIO0_11 = 11u,   /**< assign to pin P0_11. */
  PIO0_12 = 12u,   /**< assign to pin P0_12. */
  PIO0_13 = 13u,   /**< assign to pin P0_13. */
  PIO0_14 = 14u,   /**< assign to pin P0_14. */
  PIO0_15 = 15u,   /**< assign to pin P0_15. */
  PIO0_16 = 16u,   /**< assign to pin P0_16. */
  PIO0_17 = 17u,   /**< assign to pin P0_17. */
  PIO0_18 = 18u,   /**< assign to pin P0_18. */
  PIO0_19 = 19u,   /**< assign to pin P0_19. */
  PIO0_20 = 20u,   /**< assign to pin P0_20. */
  PIO0_21 = 21u,   /**< assign to pin P0_21. */
  PIO0_22 = 22u,   /**< assign to pin P0_22. */
  PIO0_23 = 23u,   /**< assign to pin P0_23. */
  PIO0_24 = 24u,   /**< assign to pin P0_24. */
  PIO0_25 = 25u,   /**< assign to pin P0_25. */
  PIO0_26 = 26u,   /**< assign to pin P0_26. */
  PIO0_27 = 27u,   /**< assign to pin P0_27. */
  PIO0_28 = 28u,   /**< assign to pin P0_28. */
  PIO0_29 = 29u,   /**< assign to pin P0_29. */
  PIO0_30 = 30u,   /**< assign to pin P0_30. */
  PIO0_31 = 31u,   /**< assign to pin P0_31. */
  PIO1_0 = 32u,    /**< assign to pin P1_0. */
  PIO1_1 = 33u,    /**< assign to pin P1_1. */
  PIO1_2 = 34u,    /**< assign to pin P1_2. */
  PIO1_3 = 35u,    /**< assign to pin P1_3. */
  PIO1_4 = 36u,    /**< assign to pin P1_4. */
  PIO1_5 = 37u,    /**< assign to pin P1_5. */
  PIO1_6 = 38u,    /**< assign to pin P1_6. */
  PIO1_7 = 39u,    /**< assign to pin P1_7. */
  PIO1_8 = 40u,    /**< assign to pin P1_8. */
  PIO1_9 = 41u,    /**< assign to pin P1_9. */
  PIO1_10 = 42u,   /**< assign to pin P1_10. */
  PIO1_11 = 43u,   /**< assign to pin P1_11. */
  PIO1_12 = 44u,   /**< assign to pin P1_12. */
  PIO1_13 = 45u,   /**< assign to pin P1_13. */
  PIO1_14 = 46u,   /**< assign to pin P1_14. */
  PIO1_15 = 47u,   /**< assign to pin P1_15. */
  PIO1_16 = 48u,   /**< assign to pin P1_16. */
  PIO1_17 = 49u,   /**< assign to pin P1_17. */
  PIO1_18 = 50u,   /**< assign to pin P1_18. */
  PIO1_19 = 51u,   /**< assign to pin P1_19. */
  PIO1_20 = 52u,   /**< assign to pin P1_20. */
  PIO1_21 = 53u,   /**< assign to pin P1_21. */
  PIO_NONE = 0xFFu /**< assign to nothing */
};
/**
 * @brief
 */
enum functionMovable : std::uint8_t {
  U0_TXD_O,        /**< UART0 TXD Output */
  U0_RXD_I,        /**< UART0 RXD Input */
  U0_RTS_O,        /**< UART0 RTS Output */
  U0_CTS_I,        /**< UART0 CTS Input */
  U0_SCLK_IO,      /**< UART0 SCLK I/O */
  U1_TXD_O,        /**< UART1 TXD Output */
  U1_RXD_I,        /**< UART1 RXD Input */
  U1_RTS_O,        /**< UART1 RTS Output */
  U1_CTS_I,        /**< UART1 CTS Input */
  U1_SCLK_IO,      /**< UART1 SCLK I/O */
  U2_TXD_O,        /**< UART2 TXD Output */
  U2_RXD_I,        /**< UART2 RXD Input */
  U2_RTS_O,        /**< UART2 RTS Output */
  U2_CTS_I,        /**< UART2 CTS Input */
  U2_SCLK_IO,      /**< UART2 SCLK I/O */
  SPI0_SCK_IO,     /**< SPI0 SCK I/O */
  SPI0_MOSI_IO,    /**< SPI0 MOSI I/O */
  SPI0_MISO_IO,    /**< SPI0 MISO I/O */
  SPI0_SSEL0_IO,   /**< SPI0 SSEL0 I/O */
  SPI0_SSEL1_IO,   /**< SPI0 SSEL1 I/O */
  SPI0_SSEL2_IO,   /**< SPI0 SSEL2 I/O */
  SPI0_SSEL3_IO,   /**< SPI0 SSEL3 I/O */
  SPI1_SCK_IO,     /**< SPI1 SCK I/O */
  SPI1_MOSI_IO,    /**< SPI1 MOSI I/O */
  SPI1_MISO_IO,    /**< SPI1 MISO I/O */
  SPI1_SSEL0_IO,   /**< SPI1 SSEL0 I/O */
  SPI1_SSEL1_IO,   /**< SPI1 SSEL1 I/O */
  SCT_PIN0_I,      /**< Pin input 0 to the SCT input multiplexer */
  SCT_PIN1_I,      /**< Pin input 1 to the SCT input multiplexer */
  SCT_PIN2_I,      /**< Pin input 2 to the SCT input multiplexer */
  SCT_PIN3_I,      /**< Pin input 3 to the SCT input multiplexer */
  CTOUT_0_O,       /**< SCT Output 0 */
  CTOUT_1_O,       /**< SCT Output 1 */
  CTOUT_2_O,       /**< SCT Output 2 */
  CTOUT_3_O,       /**< SCT Output 3 */
  CTOUT_4_O,       /**< SCT Output 4 */
  CTOUT_5_O,       /**< SCT Output 5 */
  CTOUT_6_O,       /**< SCT Output 6 */
  I2C1_SDA_IO,     /**< I2C1 SDA I/O */
  I2C1_SCL_IO,     /**< I2C1 SCL I/O */
  I2C2_SDA_IO,     /**< I2C2 SDA I/O */
  I2C2_SCL_IO,     /**< I2C2 SCL I/O */
  I2C3_SDA_IO,     /**< I2C3 SDA I/O */
  I2C3_SCL_IO,     /**< I2C3 SCL I/O */
  ACMP_O_O,        /**< analog comparator Output */
  CLKOUT_O,        /**< Clock Output */
  GPIO_INT_BMAT_O, /**< GPIO pattern matching Output */
  U3_TXD_O,        /**< Transmitter output for USART3 */
  U3_RXD_I,        /**< Receiver input for USART3 */
  U3_SCLK_IO,      /**< Serial clock input/output for USART3 in synchronous mode */
  U4_TXD_O,        /**< Transmitter output for USART4 */
  U4_RXD_I,        /**< Receiver input for USART4 */
  U4_SCLK_IO,      /**< Serial clock input/output for USART4 in synchronous mode */
  T0_MAT0_O,       /**< Timer Match channel 0 */
  T0_MAT1_O,       /**< Timer Match channel 1 */
  T0_MAT2_O,       /**< Timer Match channel 2 */
  T0_MAT3_O,       /**< Timer Match channel 3 */
  T0_CAP0_I,       /**< Timer Capture channel 0 */
  T0_CAP1_I,       /**< Timer Capture channel 1 */
  T0_CAP2_I,       /**< Timer Capture channel 2 */
};
/**
 * @brief
 */
enum functionFixed0 : std::uint32_t {
  ACMP_I1 = (1u << 0),   /**< ACMP I1 */
  ACMP_I2 = (1u << 1),   /**< ACMP_I2 fixed function */
  ACMP_I3 = (1u << 2),   /**< ACMP_I3 fixed function */
  ACMP_I4 = (1u << 3),   /**< ACMP_I4 fixed function */
  ACMP_I5 = (1u << 4),   /**< ACMP_I5 fixed function */
  SWCLK = (1u << 5),     /**< SWCLK fixed function */
  SWDIO = (1u << 6),     /**< SWDIO fixed function */
  XTALIN = (1u << 7),    /**< XTALIN fixed function */
  XTALOUT = (1u << 8),   /**< XTALOUT fixed function */
  RESETN = (1u << 9),    /**< RESETN fixed function */
  CLKIN = (1u << 10),    /**< CLKIN fixed function */
  VDDCMP = (1u << 11),   /**< VDDCMP fixed function */
  I2C0_SDA = (1u << 12), /**< I2C0_SDA fixed function */
  I2C0_SCL = (1u << 13), /**< I2C0_SCL fixed function */
  ADC_0 = (1u << 14),    /**< ADC_0 fixed function */
  ADC_1 = (1u << 15),    /**< ADC_1 fixed function */
  ADC_2 = (1u << 16),    /**< ADC_2 fixed function */
  ADC_3 = (1u << 17),    /**< ADC_3 fixed function */
  ADC_4 = (1u << 18),    /**< ADC_4 fixed function */
  ADC_5 = (1u << 19),    /**< ADC_5 fixed function */
  ADC_6 = (1u << 20),    /**< ADC_6 fixed function */
  ADC_7 = (1u << 21),    /**< ADC_7 fixed function */
  ADC_8 = (1u << 22),    /**< ADC_8 fixed function */
  ADC_9 = (1u << 23),    /**< ADC_9 fixed function */
  ADC_10 = (1u << 24),   /**< ADC_10 fixed function */
  ADC_11 = (1u << 25),   /**< ADC_11 fixed function */
  DACOUT0 = (1u << 26),  /**< DACOUT0 fixed function */
  DACOUT1 = (1u << 27),  /**< DACOUT1 fixed function */
  CAPT_X0 = (1u << 28),  /**< CAPT_X0 fixed function */
  CAPT_X1 = (1u << 29),  /**< CAPT_X1 fixed function */
  CAPT_X2 = (1u << 30),  /**< CAPT_X2 fixed function */
  CAPT_X3 = (1u << 31),  /**< CAPT_X3 fixed function */
};
/**
 * @brief
 */
enum functionFixed1 : std::uint32_t {
  CAPT_X4 = (1u << 0), /**< CAPT_X4 */
  CAPT_X5 = (1u << 1), /**< CAPT_X5 */
  CAPT_X6 = (1u << 2), /**< CAPT_X6 */
  CAPT_X7 = (1u << 3), /**< CAPT_X7 */
  CAPT_X8 = (1u << 4), /**< CAPT_X8 */
  CAPT_YL = (1u << 5), /**< CAPT_YL */
  CAPT_YH = (1u << 5), /**< CAPT_YL */
};
/**
 * @brief
 */
enum class pinFunctions : std::uint8_t {
  U0_TXD_O,        /**< UART0 TXD Output */
  U0_RXD_I,        /**< UART0 RXD Input */
  U0_RTS_O,        /**< UART0 RTS Output */
  U0_CTS_I,        /**< UART0 CTS Input */
  U0_SCLK_IO,      /**< UART0 SCLK I/O */
  U1_TXD_O,        /**< UART1 TXD Output */
  U1_RXD_I,        /**< UART1 RXD Input */
  U1_RTS_O,        /**< UART1 RTS Output */
  U1_CTS_I,        /**< UART1 CTS Input */
  U1_SCLK_IO,      /**< UART1 SCLK I/O */
  U2_TXD_O,        /**< UART2 TXD Output */
  U2_RXD_I,        /**< UART2 RXD Input */
  U2_RTS_O,        /**< UART2 RTS Output */
  U2_CTS_I,        /**< UART2 CTS Input */
  U2_SCLK_IO,      /**< UART2 SCLK I/O */
  SPI0_SCK_IO,     /**< SPI0 SCK I/O */
  SPI0_MOSI_IO,    /**< SPI0 MOSI I/O */
  SPI0_MISO_IO,    /**< SPI0 MISO I/O */
  SPI0_SSEL0_IO,   /**< SPI0 SSEL0 I/O */
  SPI0_SSEL1_IO,   /**< SPI0 SSEL1 I/O */
  SPI0_SSEL2_IO,   /**< SPI0 SSEL2 I/O */
  SPI0_SSEL3_IO,   /**< SPI0 SSEL3 I/O */
  SPI1_SCK_IO,     /**< SPI1 SCK I/O */
  SPI1_MOSI_IO,    /**< SPI1 MOSI I/O */
  SPI1_MISO_IO,    /**< SPI1 MISO I/O */
  SPI1_SSEL0_IO,   /**< SPI1 SSEL0 I/O */
  SPI1_SSEL1_IO,   /**< SPI1 SSEL1 I/O */
  SCT_PIN0_I,      /**< Pin input 0 to the SCT input multiplexer */
  SCT_PIN1_I,      /**< Pin input 1 to the SCT input multiplexer */
  SCT_PIN2_I,      /**< Pin input 2 to the SCT input multiplexer */
  SCT_PIN3_I,      /**< Pin input 3 to the SCT input multiplexer */
  CTOUT_0_O,       /**< SCT Output 0 */
  CTOUT_1_O,       /**< SCT Output 1 */
  CTOUT_2_O,       /**< SCT Output 2 */
  CTOUT_3_O,       /**< SCT Output 3 */
  CTOUT_4_O,       /**< SCT Output 4 */
  CTOUT_5_O,       /**< SCT Output 5 */
  CTOUT_6_O,       /**< SCT Output 6 */
  I2C1_SDA_IO,     /**< I2C1 SDA I/O */
  I2C1_SCL_IO,     /**< I2C1 SCL I/O */
  I2C2_SDA_IO,     /**< I2C2 SDA I/O */
  I2C2_SCL_IO,     /**< I2C2 SCL I/O */
  I2C3_SDA_IO,     /**< I2C3 SDA I/O */
  I2C3_SCL_IO,     /**< I2C3 SCL I/O */
  ACMP_O_O,        /**< analog comparator Output */
  CLKOUT_O,        /**< Clock Output */
  GPIO_INT_BMAT_O, /**< GPIO pattern matching Output */
  U3_TXD_O,        /**< Transmitter output for USART3 */
  U3_RXD_I,        /**< Receiver input for USART3 */
  U3_SCLK_IO,      /**< Serial clock input/output for USART3 in synchronous mode */
  U4_TXD_O,        /**< Transmitter output for USART4 */
  U4_RXD_I,        /**< Receiver input for USART4 */
  U4_SCLK_IO,      /**< Serial clock input/output for USART4 in synchronous mode */
  T0_MAT0_O,       /**< Timer Match channel 0 */
  T0_MAT1_O,       /**< Timer Match channel 1 */
  T0_MAT2_O,       /**< Timer Match channel 2 */
  T0_MAT3_O,       /**< Timer Match channel 3 */
  T0_CAP0_I,       /**< Timer Capture channel 0 */
  T0_CAP1_I,       /**< Timer Capture channel 1 */
  T0_CAP2_I,       /**< Timer Capture channel 2 */
  ACMP_I1,         /**< analog comparator input 1 */
  ACMP_I2,         /**< analog comparator input 2 */
  ACMP_I3,         /**< analog comparator input 3 */
  ACMP_I4,         /**< analog comparator input 3 */
  ACMP_I5,         /**< analog comparator input 3 */
  SWCLK,           /**< SWD clock */
  SWDIO,           /**< SWD input/output */
  XTALIN,          /**< Crystal oscillator input */
  XTALOUT,         /**< Crystal oscillator output */
  RESETN,          /**< Reset */
  CLKIN,           /**< Clock Input */
  VDDCMP,          /**< analog comparator vdd input */
  I2C0_SDA,        /**< I2C0 SDA */
  I2C0_SCL,        /**< I2C0 SCL */
  ADC_0,           /** ADC 0 input */
  ADC_1,           /** ADC 1 input */
  ADC_2,           /** ADC 2 input */
  ADC_3,           /** ADC 3 input */
  ADC_4,           /** ADC 4 input */
  ADC_5,           /** ADC 5 input */
  ADC_6,           /** ADC 6 input */
  ADC_7,           /** ADC 7 input */
  ADC_8,           /** ADC 8 input */
  ADC_9,           /** ADC 9 input */
  ADC_10,          /** ADC 10 input */
  ADC_11,          /** ADC 10 input */
  DACOUT0,         /** DAC 0 output */
  DACOUT1,         /** DAC 1 output */
  CAPT_X0,         /** Capacitive touch X0 */
  CAPT_X1,         /** Capacitive touch X1 */
  CAPT_X2,         /** Capacitive touch X2 */
  CAPT_X3,         /** Capacitive touch X3 */
  CAPT_X4,         /** Capacitive touch X4 */
  CAPT_X5,         /** Capacitive touch X5 */
  CAPT_X6,         /** Capacitive touch X6 */
  CAPT_X7,         /** Capacitive touch X7 */
  CAPT_X8,         /** Capacitive touch X8 */
  CAPT_YL,         /** Capacitive touch YL */
  CAPT_YH,         /** Capacitive touch YH */
};
/**
 * @brief
 */
enum class pinFunctionTypes : std::uint8_t {
  MOVABLE, /**< Function is a movable function */
  FIXED0,  /**< Function is a fixed pin function on PINENABLE0 */
  FIXED1,  /**< Function is a fixed pin function on PINENABLE1 */
  CLEAR,   /**< This function clears */
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
struct pinFunction<pinFunctions::U0_TXD_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 0 RX input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U0_RXD_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 0 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U0_RTS_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 0 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U0_CTS_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{0};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 0 SCLK output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U0_SCLK_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 1 TX output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U1_TXD_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 1 RX input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U1_RXD_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 1 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U1_RTS_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{1};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 1 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U1_CTS_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 1 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U1_SCLK_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 2 TX output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U2_TXD_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 2 RX input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U2_RXD_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{2};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 2 RTS output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U2_RTS_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 2 CTS input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U2_CTS_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 2 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U2_SCLK_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 0 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI0_SCK_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{3};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 0 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI0_MOSI_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 0 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI0_MISO_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 0 SSEL 0 input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI0_SSEL0_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 0 SSEL 1 input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI0_SSEL1_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 0 SSEL 2 input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI0_SSEL2_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 0 SSEL 3 input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI0_SSEL3_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 1 SCK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI1_SCK_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 1 MOSI input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI1_MOSI_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 1 MISO input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI1_MISO_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 1 SSEL0 input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI1_SSEL0_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 1 SSEL1 input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI1_SSEL1_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT input multiplexer input 0
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SCT_PIN0_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT input multiplexer input 1
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SCT_PIN1_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT input multiplexer input 2
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SCT_PIN2_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SCT input multiplexer input 3
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SCT_PIN3_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT output 0
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_0_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT output 1
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_1_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT output 2
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_2_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SCT output 3
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_3_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT output 4
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_4_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT output 5
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_5_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT output 6
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_6_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for I2C1 SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C1_SDA_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for I2C1 SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C1_SCL_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{9};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for I2C2 SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C2_SDA_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for I2C2 SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C2_SCL_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for I2C3 SDA input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C3_SDA_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for I2C3 SCL input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C3_SCL_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{10};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for analog comparator output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ACMP_O_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for Clock output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CLKOUT_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for GPIO pattern matcher output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::GPIO_INT_BMAT_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 3 TX output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U3_TXD_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{11};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 3 RX input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U3_RXD_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for UART 3 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U3_SCLK_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for UART 4 TX output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U4_TXD_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for UART 4 RX input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U4_RXD_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{12};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for UART 4 SCLK input/output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::U4_SCLK_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for Timer 0 Match 0 output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::T0_MAT0_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for Timer 0 Match 1 output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::T0_MAT1_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for Timer 0 Match 2 output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::T0_MAT2_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{13};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for Timer 0 Match 3 output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::T0_MAT3_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for Timer 0 Capture 0 input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::T0_CAP0_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for Timer 0 Capture 1 input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::T0_CAP1_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for Timer 0 Capture 2 input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::T0_CAP2_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{14};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for analog comparator input 1
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ACMP_I1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_0};
  static constexpr functionFixed0 mask{functionFixed0::ACMP_I1};
};
/**
 * @brief Template specialization for analog comparator input 2
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ACMP_I2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_1};
  static constexpr functionFixed0 mask{functionFixed0::ACMP_I2};
};
/**
 * @brief Template specialization for analog comparator input 3
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ACMP_I3> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_14};
  static constexpr functionFixed0 mask{functionFixed0::ACMP_I3};
};
/**
 * @brief Template specialization for analog comparator input 4
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ACMP_I4> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_23};
  static constexpr functionFixed0 mask{functionFixed0::ACMP_I4};
};
/**
 * @brief Template specialization for analog comparator input 5
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ACMP_I5> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_30};
  static constexpr functionFixed0 mask{functionFixed0::ACMP_I5};
};
/**
 * @brief Template specialization for Serial wire debug clock
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SWCLK> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_3};
  static constexpr functionFixed0 mask{functionFixed0::SWCLK};
};
/**
 * @brief Template specialization for Serial wire debug data
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SWDIO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_2};
  static constexpr functionFixed0 mask{functionFixed0::SWDIO};
};
/**
 * @brief Template specialization for Crystal oscillator input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::XTALIN> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_8};
  static constexpr functionFixed0 mask{functionFixed0::XTALIN};
};
/**
 * @brief Template specialization for Crystal oscillator output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::XTALOUT> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_9};
  static constexpr functionFixed0 mask{functionFixed0::XTALOUT};
};
/**
 * @brief Template specialization for Crystal oscillator output
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::RESETN> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_5};
  static constexpr functionFixed0 mask{functionFixed0::RESETN};
};
/**
 * @brief Template specialization for Clock input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CLKIN> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_1};
  static constexpr functionFixed0 mask{functionFixed0::CLKIN};
};
/**
 * @brief Template specialization for VDD comparator input
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::VDDCMP> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_6};
  static constexpr functionFixed0 mask{functionFixed0::VDDCMP};
};
/**
 * @brief Template specialization for I2C0 SDA
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C0_SDA> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_11};
  static constexpr functionFixed0 mask{functionFixed0::I2C0_SDA};
};
/**
 * @brief Template specialization for I2C0 SCL
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C0_SCL> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_10};
  static constexpr functionFixed0 mask{functionFixed0::I2C0_SCL};
};
/**
 * @brief Template specialization for ADC input 0
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_0> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_7};
  static constexpr functionFixed0 mask{functionFixed0::ADC_0};
};
/**
 * @brief Template specialization for ADC input 1
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_6};
  static constexpr functionFixed0 mask{functionFixed0::ADC_1};
};
/**
 * @brief Template specialization for ADC input 2
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_14};
  static constexpr functionFixed0 mask{functionFixed0::ADC_2};
};
/**
 * @brief Template specialization for ADC input 3
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_3> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_23};
  static constexpr functionFixed0 mask{functionFixed0::ADC_3};
};
/**
 * @brief Template specialization for ADC input 4
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_4> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_22};
  static constexpr functionFixed0 mask{functionFixed0::ADC_4};
};
/**
 * @brief Template specialization for ADC input 5
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_5> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_21};
  static constexpr functionFixed0 mask{functionFixed0::ADC_5};
};
/**
 * @brief Template specialization for ADC input 6
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_6> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_20};
  static constexpr functionFixed0 mask{functionFixed0::ADC_6};
};
/**
 * @brief Template specialization for ADC input 7
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_7> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_19};
  static constexpr functionFixed0 mask{functionFixed0::ADC_7};
};
/**
 * @brief Template specialization for ADC input 8
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_8> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_18};
  static constexpr functionFixed0 mask{functionFixed0::ADC_8};
};
/**
 * @brief Template specialization for ADC input 9
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_9> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_17};
  static constexpr functionFixed0 mask{functionFixed0::ADC_9};
};
/**
 * @brief Template specialization for ADC input 10
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_10> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_13};
  static constexpr functionFixed0 mask{functionFixed0::ADC_10};
};
/**
 * @brief Template specialization for ADC input 11
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ADC_11> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_4};
  static constexpr functionFixed0 mask{functionFixed0::ADC_11};
};
/**
 * @brief Template specialization for DAC output 0
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::DACOUT0> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_17};
  static constexpr functionFixed0 mask{functionFixed0::DACOUT0};
};
/**
 * @brief Template specialization for DAC output 1
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::DACOUT1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_29};
  static constexpr functionFixed0 mask{functionFixed0::DACOUT1};
};
/**
 * @brief Template specialization for Capacitive touch input X0
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_X0> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO0_31};
  static constexpr functionFixed0 mask{functionFixed0::CAPT_X0};
};
/**
 * @brief Template specialization for Capacitive touch input X1
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_X1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO1_0};
  static constexpr functionFixed0 mask{functionFixed0::CAPT_X1};
};
/**
 * @brief Template specialization for Capacitive touch input X2
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_X2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO1_1};
  static constexpr functionFixed0 mask{functionFixed0::CAPT_X2};
};
/**
 * @brief Template specialization for Capacitive touch input X3
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_X3> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED0};
  static constexpr pinAssign pio{pinAssign::PIO1_2};
  static constexpr functionFixed0 mask{functionFixed0::CAPT_X3};
};
/**
 * @brief Template specialization for Capacitive touch input X4
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_X4> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED1};
  static constexpr pinAssign pio{pinAssign::PIO1_3};
  static constexpr functionFixed1 mask{functionFixed1::CAPT_X4};
};
/**
 * @brief Template specialization for Capacitive touch input X5
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_X5> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED1};
  static constexpr pinAssign pio{pinAssign::PIO1_4};
  static constexpr functionFixed1 mask{functionFixed1::CAPT_X5};
};
/**
 * @brief Template specialization for Capacitive touch input X6
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_X6> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED1};
  static constexpr pinAssign pio{pinAssign::PIO1_5};
  static constexpr functionFixed1 mask{functionFixed1::CAPT_X6};
};
/**
 * @brief Template specialization for Capacitive touch input X7
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_X7> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED1};
  static constexpr pinAssign pio{pinAssign::PIO1_6};
  static constexpr functionFixed1 mask{functionFixed1::CAPT_X7};
};
/**
 * @brief Template specialization for Capacitive touch input X8
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_X8> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED1};
  static constexpr pinAssign pio{pinAssign::PIO1_7};
  static constexpr functionFixed1 mask{functionFixed1::CAPT_X8};
};
/**
 * @brief Template specialization for Capacitive touch input YL
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_YL> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED1};
  static constexpr pinAssign pio{pinAssign::PIO1_8};
  static constexpr functionFixed1 mask{functionFixed1::CAPT_YL};
};
/**
 * @brief Template specialization for Capacitive touch input YH
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CAPT_YH> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED1};
  static constexpr pinAssign pio{pinAssign::PIO1_9};
  static constexpr functionFixed1 mask{functionFixed1::CAPT_YH};
};
/**
 * @brief SWM register definitions
 *
 */
struct peripheral {
  union {                                  /* offset: 0x0 */
    struct {                               /* offset: 0x0 */
      volatile std::uint32_t PINASSIGN0;   /**< Pin assign register for U0_TXD, U0_RXD, U0_RTS, U0_CTS */
      volatile std::uint32_t PINASSIGN1;   /**< Pin assign register for U0_SCLK, U1_TXD, U1_RXD, U1_RT */
      volatile std::uint32_t PINASSIGN2;   /**< Pin assign register for U1_CTS, U1_SCLK, U2_TXD, U2_RXD */
      volatile std::uint32_t PINASSIGN3;   /**< Pin assign register for U2_RTS, U2_CTS, U2_SCLK, SPI0_SCK */
      volatile std::uint32_t PINASSIGN4;   /**< Pin assign register for SPI0_MOSI, SPI0_MISO, SPI0_SSEL0, SPI0_SSEL1 */
      volatile std::uint32_t PINASSIGN5;   /**< Pin assign register for SPI0_SSEL2, SPI0_SSEL3, SPI1_SCK, SPI1_MOSI */
      volatile std::uint32_t PINASSIGN6;   /**< Pin assign register for SPI1_MISO, SPI1_SSEL0, SPI1_SSEL1, SCT0_IN0 */
      volatile std::uint32_t PINASSIGN7;   /**< Pin assign register for SCT_IN1, SCT_IN2, SCT_IN3, SCT_OUT0 */
      volatile std::uint32_t PINASSIGN8;   /**< Pin assign register for SCT_OUT1, SCT_OUT2, SCT_OUT3, SCT_OUT4 */
      volatile std::uint32_t PINASSIGN9;   /**< Pin assign register for SCT_OUT5, SCT_OUT6, I2C1_SDA, I2C1_SCL */
      volatile std::uint32_t PINASSIGN10;  /**< Pin assign register for I2C2_SDA, I2C2_SCL, I2C3_SDA, I2C3_SCL */
      volatile std::uint32_t PINASSIGN11;  /**< Pin assign register for COMP0_OUT, CLKOUT, GPIOINT_BMATCH, UART3_TXD */
      volatile std::uint32_t PINASSIGN12;  /**< Pin assign register for UART3_RXD, UART3_SCLK, UART4_TXD, UART4_RXD */
      volatile std::uint32_t PINASSIGN13;  /**< Pin assign register for UART4_SCLK, T0_MAT0, T0_MAT1, T0_MAT2 */
      volatile std::uint32_t PINASSIGN14;  /**< Pin assign register for T0_MAT3, T0_CAP0, T0_CAP1, T0_CAP2 */
    } PINASSIGN;                           /**< Pin assignment register  */
    volatile std::uint32_t PINASSIGNS[15]; /**< Pin assign register array */
  };                                       /* */
  std::uint8_t RESERVED_0[388];            /**< Reserved */
  volatile std::uint32_t PINENABLE0;       /**< Pin enable register 0. Enables fixed-pin functions */
  volatile std::uint32_t PINENABLE1;       /**< Pin enable register 1. Enables fixed-pin functions */
};
}  // namespace libMcu::hw::swm
#endif