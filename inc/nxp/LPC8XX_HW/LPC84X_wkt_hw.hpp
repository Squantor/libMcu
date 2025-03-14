/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_wkt_hw.hpp
 * @brief LPC840 series Wake Up Timer register interface and definitions
 */
#ifndef LPC84X_WKT_HW_HPP
#define LPC84X_WKT_HW_HPP

namespace libMcuHw::wkt {

/**
 * @brief wakeup timer register definitions
 */
struct wkt {
  volatile std::uint32_t CTRL;  /*!< Self wake-up timer control register */
  std::uint8_t RESERVED_0[8];   /*!< Reserved */
  volatile std::uint32_t COUNT; /*!< Counter register */
};
}  // namespace libMcuHw::wkt
#endif