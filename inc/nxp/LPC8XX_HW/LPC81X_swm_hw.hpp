/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series SWM register interface
 */
#ifndef LPC81X_SMW_REGS_HPP
#define LPC81X_SWM_REGS_HPP

namespace libMcuLL::hw::swm {
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
  PIO_NONE = 0xFFu /**< assign to nothing */
};
/**
 * @brief
 */
enum functionMovable : std::uint8_t {
  USART0_TXD_O = 0u,     /**< UART0 TXD Output */
  USART0_RXD_I = 1u,     /**< UART0 RXD Input */
  USART0_RTS_O = 2u,     /**< UART0 RTS Output */
  USART0_CTS_I = 3u,     /**< UART0 CTS Input */
  USART0_SCLK_IO = 4u,   /**< UART0 SCLK I/O */
  USART1_TXD_O = 5u,     /**< UART1 TXD Output */
  USART1_RXD_I = 6u,     /**< UART1 RXD Input */
  USART1_RTS_O = 7u,     /**< UART1 RTS Output */
  USART1_CTS_I = 8u,     /**< UART1 CTS Input */
  USART1_SCLK_IO = 9u,   /**< UART1 SCLK I/O */
  USART2_TXD_O = 10u,    /**< UART2 TXD Output */
  USART2_RXD_I = 11u,    /**< UART2 RXD Input */
  USART2_RTS_O = 12u,    /**< UART2 RTS Output */
  USART2_CTS_I = 13u,    /**< UART2 CTS Input */
  USART2_SCLK_IO = 14u,  /**< UART2 SCLK I/O */
  SPI0_SCK_IO = 15u,     /**< SPI0 SCK I/O */
  SPI0_MOSI_IO = 16u,    /**< SPI0 MOSI I/O */
  SPI0_MISO_IO = 17u,    /**< SPI0 MISO I/O */
  SPI0_SSEL_IO = 18u,    /**< SPI0 SSEL I/O */
  SPI1_SCK_IO = 19u,     /**< SPI1 SCK I/O */
  SPI1_MOSI_IO = 20u,    /**< SPI1 MOSI I/O */
  SPI1_MISO_IO = 21u,    /**< SPI1 MISO I/O */
  SPI1_SSEL_IO = 22u,    /**< SPI1 SSEL I/O */
  SCT0_IN_0_I = 23u,     /**< SCT Input 0*/
  SCT0_IN_1_I = 24u,     /**< SCT Input 1*/
  SCT0_IN_2_I = 25u,     /**< SCT Input 2*/
  SCT0_IN_3_I = 26u,     /**< SCT Input 3*/
  SCT0_OUT_0_O = 27u,    /**< SCT Output 0*/
  SCT0_OUT_1_O = 28u,    /**< SCT Output 1*/
  SCT0_OUT_2_O = 29u,    /**< SCT Output 2*/
  SCT0_OUT_3_O = 30u,    /**< SCT Output 3*/
  I2C0_SDA_IO = 31u,     /**< I2C SDA I/O */
  I2C0_SCL_IO = 32u,     /**< I2C SCL I/O */
  ACMP_O = 33u,          /**< ACMP Output */
  CLKOUT_O = 34u,        /**< CLKOUT Output */
  GPIO_INT_BMAT_O = 35u, /**< GPIO INT BMAT Output */
};
/**
 * @brief
 */
enum functionFixed : std::uint16_t {
  ACMP_I1 = (1 << 0), /**< ACMP I1 */
  ACMP_I2 = (1 << 1), /**< ACMP I2 */
  SWCLK = (1 << 2),   /**< SWCLK */
  SWDIO = (1 << 3),   /**< SWDIO */
  XTALIN = (1 << 4),  /**< XTALIN */
  XTALOUT = (1 << 5), /**< XTALOUT */
  RESET = (1 << 6),   /**< Reset */
  CLKIN = (1 << 7),   /**< Clock Input */
  VDDCMP = (1 << 8)   /**< ACMP VDD*/
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
  SPI0_SSEL_IO,    /**< SPI0 SSEL I/O */
  SPI1_SCK_IO,     /**< SPI1 SCK I/O */
  SPI1_MOSI_IO,    /**< SPI1 MOSI I/O */
  SPI1_MISO_IO,    /**< SPI1 MISO I/O */
  SPI1_SSEL_IO,    /**< SPI1 SSEL I/O */
  CTIN_0_I,        /**< SCT Input 0*/
  CTIN_1_I,        /**< SCT Input 1*/
  CTIN_2_I,        /**< SCT Input 2*/
  CTIN_3_I,        /**< SCT Input 3*/
  CTOUT_0_O,       /**< SCT Output 0*/
  CTOUT_1_O,       /**< SCT Output 1*/
  CTOUT_2_O,       /**< SCT Output 2*/
  CTOUT_3_O,       /**< SCT Output 3*/
  I2C_SDA_IO,      /**< I2C SDA I/O */
  I2C_SCL_IO,      /**< I2C SCL I/O */
  ACMP_O_O,        /**< analog comparator Output */
  CLKOUT_O,        /**< CLKOUT Output */
  GPIO_INT_BMAT_O, /**< GPIO pattern matching Output */
  ACMP_I1,         /**< analog comparator input 1 */
  ACMP_I2,         /**< analog comparator input 2 */
  SWCLK,           /**< SWD clock */
  SWDIO,           /**< SWD input/output */
  XTALIN,          /**< Crystal oscillator input */
  XTALOUT,         /**< Crystal oscillator output */
  RESET,           /**< Reset */
  CLKIN,           /**< Clock Input */
  VDDCMP,          /**< analog comparator vdd input */
};
/**
 * @brief
 */
enum class pinFunctionTypes : std::uint8_t {
  MOVABLE, /**< Function is a movable function */
  FIXED,   /**< Function is a fixed pin function */
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI0_MISO_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 0 SSEL input/output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI0_SSEL_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SPI 1 SCK input/output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI1_SCK_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{4};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SPI 1 MOSI input/output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI1_MOSI_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SPI 1 MISO input/output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI1_MISO_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SPI 1 SSEL input/output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SPI1_SSEL_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT input 0
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTIN_0_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{5};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT input 1
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTIN_1_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT input 2
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTIN_2_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SCT input 3
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTIN_3_I> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for SCT output 0
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_0_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{6};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for SCT output 1
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_1_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for SCT output 2
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_2_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for SCT output 3
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CTOUT_3_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for I2C SDA input/output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C_SDA_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{7};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for I2C SCL input/output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::I2C_SCL_IO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{0};
};
/**
 * @brief Template specialization for analog comparator output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ACMP_O_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{8};
};
/**
 * @brief Template specialization for Clock output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CLKOUT_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{16};
};
/**
 * @brief Template specialization for GPIO pattern matcher output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::GPIO_INT_BMAT_O> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::MOVABLE};
  static constexpr std::uint8_t index{8};
  static constexpr std::uint8_t shift{24};
};
/**
 * @brief Template specialization for analog comparator input 1
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ACMP_I1> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED};
  static constexpr pinAssign pio{pinAssign::PIO0_0};
  static constexpr functionFixed mask{functionFixed::ACMP_I1};
};
/**
 * @brief Template specialization for analog comparator input 2
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::ACMP_I2> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED};
  static constexpr pinAssign pio{pinAssign::PIO0_1};
  static constexpr functionFixed mask{functionFixed::ACMP_I2};
};
/**
 * @brief Template specialization for SWD clock
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SWCLK> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED};
  static constexpr pinAssign pio{pinAssign::PIO0_3};
  static constexpr functionFixed mask{functionFixed::SWCLK};
};
/**
 * @brief Template specialization for SWD input/output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::SWDIO> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED};
  static constexpr pinAssign pio{pinAssign::PIO0_2};
  static constexpr functionFixed mask{functionFixed::SWDIO};
};
/**
 * @brief Template specialization for crystal input
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::XTALIN> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED};
  static constexpr pinAssign pio{pinAssign::PIO0_8};
  static constexpr functionFixed mask{functionFixed::XTALIN};
};
/**
 * @brief Template specialization for crystal output
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::XTALOUT> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED};
  static constexpr pinAssign pio{pinAssign::PIO0_9};
  static constexpr functionFixed mask{functionFixed::XTALOUT};
};
/**
 * @brief Template specialization for RESET input
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::RESET> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED};
  static constexpr pinAssign pio{pinAssign::PIO0_5};
  static constexpr functionFixed mask{functionFixed::RESET};
};
/**
 * @brief Template specialization for clock input
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::CLKIN> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED};
  static constexpr pinAssign pio{pinAssign::PIO0_1};
  static constexpr functionFixed mask{functionFixed::CLKIN};
};
/**
 * @brief Template specialization for analog comparator ladder VDD
 *
 * @tparam pinfunction specialization
 */
template <>
struct pinFunction<pinFunctions::VDDCMP> {
  static constexpr pinFunctionTypes type{pinFunctionTypes::FIXED};
  static constexpr pinAssign pio{pinAssign::PIO0_6};
  static constexpr functionFixed mask{functionFixed::VDDCMP};
};
/**
 * @brief SWM register definitions
 *
 */
struct swm {
  volatile std::uint32_t PINASSIGN[9];   /**< Pin Assign register array */
  volatile std::uint32_t RESERVED0[103]; /**< reserved*/
  volatile std::uint32_t PINENABLE0;     /**< Pin Enable register */
};
}  // namespace libMcuLL::hw::swm
#endif