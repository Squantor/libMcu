/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 windowed watchdog register interface
 */
#ifndef LPC84X_WWDT_HW_HPP
#define LPC84X_WWDT_HW_HPP

namespace libMcuHw::wwdt {

/**
 * @brief wwdt register definitions
 */
struct wwdt {
  volatile std::uint32_t MOD;      /**< Watchdog mode register */
  volatile std::uint32_t TC;       /**< Watchdog timer constant register */
  volatile std::uint32_t FEED;     /**< Watchdog feed sequence register. Writing 0xAA then 0x55 feeds the watchdog  */
  volatile const std::uint32_t TV; /**< Watchdog timer value register */
  std::uint8_t RESERVED_0[4];      /**< Reserved */
  volatile std::uint32_t WARNINT;  /**< Watchdog Warning Interrupt compare value */
  volatile std::uint32_t WINDOW;   /**< Watchdog Window compare valu */
};
}  // namespace libMcuHw::wwdt
#endif