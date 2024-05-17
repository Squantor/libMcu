/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 PLL register interface
 */
#ifndef RP2040_PLL_HW_HPP
#define RP2040_PLL_HW_HPP

namespace libMcuLL {
namespace hw {
namespace pll {
/**
 * @brief I2C register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t CS;        /**< Control and Status */
  volatile std::uint32_t PWR;       /**< Controls the PLL power modes */
  volatile std::uint32_t FBDIV_INT; /**< Feedback divisor */
  volatile std::uint32_t PRIM;      /**< Controls the PLL post dividers for the primary output*/
};
namespace CS {
constexpr inline std::uint32_t RESERVED_MASK{0x8000'013Fu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t LOCK_MASK{1u << 31};         /**< PLL is locked */
constexpr inline std::uint32_t BYPASS{1u << 8};             /**< passes reference clock to output */
/**
 * @brief Formats REFDIV value to CS register
 * @param divider PLL input reference clock divider
 * @return Formatted REFDIV value for the CS register
 */
constexpr inline std::uint32_t REFDIV(std::uint32_t divider) {
  return divider << 0;
}
}  // namespace CS
namespace PWR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'002Du}; /**< Mask for allowed bits */
constexpr inline std::uint32_t VCOPD{1u << 5};              /**< Powerdown VCO */
constexpr inline std::uint32_t POSTDIVPD{1u << 3};          /**< Powerdown Post divider */
constexpr inline std::uint32_t DSMPD{1u << 2};              /**< Powerdown DSM */
constexpr inline std::uint32_t PD{1u << 0};                 /**< Powerdown PLL */
}  // namespace PWR
namespace FBDIV_INT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0FFFu}; /**< Mask for allowed bits */
}  // namespace FBDIV_INT
namespace PRIM {
constexpr inline std::uint32_t RESERVED_MASK{0x0007'7000u}; /**< Mask for allowed bits */
/**
 * @brief Format POSTDIV field to PRIM register
 * @param divider1 amount of input clock cycles before enable
 * @param divider2 amount of input clock cycles before enable
 * @return POSTDIV field formatted to PRIM register
 */
constexpr inline std::uint32_t POSTDIV(std::uint32_t divider1, std::uint32_t divider2) {
  return (divider1 << 16) | (divider2 << 12);
}
}  // namespace PRIM
}  // namespace pll
}  // namespace hw
}  // namespace libMcuLL
#endif