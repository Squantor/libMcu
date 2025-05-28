/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_wkt_hw.hpp
 * @brief Register structure and bit definitions for the LPC840 series Wake Up Timer
 */
#ifndef LPC84X_WKT_HW_HPP
#define LPC84X_WKT_HW_HPP

namespace libmcuhw::wkt {

/**
 * @brief wakeup timer register definitions
 */
struct Wkt {
  volatile std::uint32_t CTRL;  /*!< Self wake-up timer control register */
  std::uint8_t RESERVED_0[8];   /*!< Reserved */
  volatile std::uint32_t COUNT; /*!< Counter register */
};
}  // namespace libmcuhw::wkt
#endif