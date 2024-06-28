/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Analog comparator register interface
 */
#ifndef LPC84X_ACMP_HW_HPP
#define LPC84X_ACMP_HW_HPP

namespace libMcu::hw::acmp {
/**
 * @brief ACMP register definitions
 */
struct peripheral {
  volatile std::uint32_t CTRL; /**< Comparator control register */
  volatile std::uint32_t LAD;  /**< Voltage ladder register */
};
}  // namespace libMcu::hw::acmp
#endif