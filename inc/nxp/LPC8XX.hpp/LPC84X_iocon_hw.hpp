/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series IOCON register interface
 */
#ifndef LPC84X_IOCON_REGS_HPP
#define LPC84X_IOCON_REGS_HPP

namespace libMcuLL::hw::iocon {

/**
 * @brief IOCON register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t PIO[56]; /**< Pin control registers */
};

namespace PIO {
constexpr inline std::uint32_t INACTIVE = (0 << 3);      /**< No pullup/down */
constexpr inline std::uint32_t PULLDOWN = (1 << 3);      /**< Pulldown enabled */
constexpr inline std::uint32_t PULLUP = (2 << 3);        /**< Pullup enabled */
constexpr inline std::uint32_t REPEATER = (3 << 3);      /**< Repeater mode */
constexpr inline std::uint32_t HYS = (1 << 5);           /**< Hysteresis enable */
constexpr inline std::uint32_t INV = (1 << 6);           /**< Invert input enable */
constexpr inline std::uint32_t OD = (1 << 10);           /**< Open drain enable */
constexpr inline std::uint32_t BYPASS = (0 << 11);       /**< Bypassed input filter */
constexpr inline std::uint32_t CYCLES1 = (1 << 11);      /**< 1 clock cycle pulses are filtered */
constexpr inline std::uint32_t CYCLES2 = (2 << 11);      /**< 2 clock cycle pulses are filtered */
constexpr inline std::uint32_t CYCLES3 = (3 << 11);      /**< 3 clock cycle pulses are filtered */
constexpr inline std::uint32_t IOCONCLKDIV0 = (0 << 13); /**< use IOCONCLKDIV0 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV1 = (1 << 13); /**< use IOCONCLKDIV1 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV2 = (2 << 13); /**< use IOCONCLKDIV2 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV3 = (3 << 13); /**< use IOCONCLKDIV3 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV4 = (4 << 13); /**< use IOCONCLKDIV4 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV5 = (5 << 13); /**< use IOCONCLKDIV5 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV6 = (6 << 13); /**< use IOCONCLKDIV6 in SYSCON */
constexpr inline std::uint32_t I2C_STD = (0 << 8);       /**< standard/fast I2C mode */
constexpr inline std::uint32_t IO_STD = (1 << 8);        /**< standard I/O functionality */
constexpr inline std::uint32_t I2C_FAST = (2 << 8);      /**< fast mode plus I2C */
}  // namespace PIO
}  // namespace libMcuLL::hw::iocon
#endif