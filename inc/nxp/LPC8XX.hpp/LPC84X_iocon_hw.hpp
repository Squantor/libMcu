/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series IOCON register interface
 */
#ifndef LPC84X_IOCON_HW_HPP
#define LPC84X_IOCON_HW_HPP

namespace libMcu::hw::iocon {

/**
 * @brief IOCON register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t PIO[56]; /**< Pin control registers */
};

namespace PIO {
constexpr inline std::uint32_t INACTIVE{0u << 3};      /**< No pullup/down */
constexpr inline std::uint32_t PULLDOWN{1u << 3};      /**< Pulldown enabled */
constexpr inline std::uint32_t PULLUP{2u << 3};        /**< Pullup enabled */
constexpr inline std::uint32_t REPEATER{3u << 3};      /**< Repeater mode */
constexpr inline std::uint32_t HYS{1u << 5};           /**< Hysteresis enable */
constexpr inline std::uint32_t INV{1u << 6};           /**< Invert input enable */
constexpr inline std::uint32_t OD{1u << 10};           /**< Open drain enable */
constexpr inline std::uint32_t BYPASS{0u << 11};       /**< Bypassed input filter */
constexpr inline std::uint32_t CYCLES1{1u << 11};      /**< 1 clock cycle pulses are filtered */
constexpr inline std::uint32_t CYCLES2{2u << 11};      /**< 2 clock cycle pulses are filtered */
constexpr inline std::uint32_t CYCLES3{3u << 11};      /**< 3 clock cycle pulses are filtered */
constexpr inline std::uint32_t IOCONCLKDIV0{0u << 13}; /**< use IOCONCLKDIV0 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV1{1u << 13}; /**< use IOCONCLKDIV1 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV2{2u << 13}; /**< use IOCONCLKDIV2 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV3{3u << 13}; /**< use IOCONCLKDIV3 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV4{4u << 13}; /**< use IOCONCLKDIV4 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV5{5u << 13}; /**< use IOCONCLKDIV5 in SYSCON */
constexpr inline std::uint32_t IOCONCLKDIV6{6u << 13}; /**< use IOCONCLKDIV6 in SYSCON */
constexpr inline std::uint32_t I2C_STD{0u << 8};       /**< standard/fast I2C mode */
constexpr inline std::uint32_t IO_STD{1u << 8};        /**< standard I/O functionality */
constexpr inline std::uint32_t I2C_FAST{2u << 8};      /**< fast mode plus I2C */
}  // namespace PIO
}  // namespace libMcu::hw::iocon
#endif