/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Wake Up Timer register interface
 */
#ifndef LPC84X_WKT_HW_HPP
#define LPC84X_WKT_HW_HPP

namespace libMcuHw::wkt {

/**
 * @brief wakeup timer register definitions
 */
struct wkt {
  volatile std::uint32_t CTRL;  /**< Self wake-up timer control register */
  std::uint8_t RESERVED_0[8];   /**< Reserved */
  volatile std::uint32_t COUNT; /**< Counter register */
};
}  // namespace libMcuHw::wkt
#endif