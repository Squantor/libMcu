/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series IOCON register interface
 */
#ifndef LPC81X_IOCON_REGS_HPP
#define LPC81X_IOCON_REGS_HPP

namespace registers {
namespace iocon {

/**
 * @brief Pin pull modes
 *
 */
enum pullModes : uint32_t {
  INACTIVE = (0 << 3), /**< No pullup/down */
  PULLDOWN = (1 << 3), /**< Pulldown enabled */
  PULLUP = (2 << 3),   /**< Pullup enabled */
  REPEATER = (3 << 3), /**< Repeater mode */
};

/**
 * @brief pin filtering modes
 *
 */
enum pinFiltering : uint32_t {
  BYPASS = (0 << 11),  /**< Bypassed input filter */
  CYCLES1 = (1 << 11), /**< 1 clock cycle pulses are filtered */
  CYCLES2 = (2 << 11), /**< 2 clock cycle pulses are filtered */
  CYCLES3 = (3 << 11), /**< 3 clock cycle pulses are filtered */
};

/**
 * @brief Clock divider to use for filtering
 *
 */
enum clockDivider : uint32_t {
  IOCONCLKDIV0 = (0 << 13), /**< use IOCONCLKDIV0 in SYSCON */
  IOCONCLKDIV1 = (1 << 13), /**< use IOCONCLKDIV1 in SYSCON */
  IOCONCLKDIV2 = (2 << 13), /**< use IOCONCLKDIV2 in SYSCON */
  IOCONCLKDIV3 = (3 << 13), /**< use IOCONCLKDIV3 in SYSCON */
  IOCONCLKDIV4 = (4 << 13), /**< use IOCONCLKDIV4 in SYSCON */
  IOCONCLKDIV5 = (5 << 13), /**< use IOCONCLKDIV5 in SYSCON */
  IOCONCLKDIV6 = (6 << 13), /**< use IOCONCLKDIV6 in SYSCON */
};

/**
 * @brief I2C pin modes
 *
 */
enum i2cmodes : uint32_t {
  I2C_STD = (0 << 8),  /**< standard/fast I2C mode */
  IO_STD = (1 << 8),   /**< standard I/O functionality */
  I2C_FAST = (2 << 8), /**< fast mode plus I2C */
};

/**
 * @brief IOCON register definitions
 *
 */
struct registers {
  volatile uint32_t PIO[56]; /**< Pin control registers */
};

namespace PIO {
constexpr inline uint32_t HYS = (1 << 5); /**< Hysteresis enable */
constexpr inline uint32_t INV = (1 << 6); /**< Invert input enable */
constexpr inline uint32_t OD = (1 << 10); /**< Open drain enable */
}  // namespace PIO
}  // namespace iocon
}  // namespace registers

#endif