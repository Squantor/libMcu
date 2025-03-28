/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_acmp_hw.hpp
 * @brief LPC840 series analog comparator register interface and definitions
 */
#ifndef LPC84X_ACMP_HW_HPP
#define LPC84X_ACMP_HW_HPP

namespace libmcuhw::acmp {
/**
 * @brief ACMP register definitions
 */
struct acmp {
  volatile std::uint32_t CTRL; /*!< Comparator control register */
  volatile std::uint32_t LAD;  /*!< Voltage ladder register */
};
}  // namespace libmcuhw::acmp
#endif