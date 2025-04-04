/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_wwdt_hw.hpp
 * @brief Register structure and bit definitions for the LPC810 series windowed watchdog
 */
#ifndef LPC81X_WWDT_REGS_HPP
#define LPC81X_WWDT_REGS_HPP

namespace libmcuhw::wwdt {

/**
 * @brief windowed watchdog register definitions
 */
struct wwdt {
  volatile std::uint32_t MOD;      /*!< basic mode and status register */
  volatile std::uint32_t TC;       /*!< time-out value register */
  volatile std::uint32_t FEED;     /*!< Writing 0xAA followed by 0x55 reloads the Watchdog timer */
  volatile const std::uint32_t TV; /*!< current value of the Watchdog timer */
  volatile const std::uint32_t RESERVED0;
  volatile std::uint32_t WARNINT; /*!< contains the Watchdog warning interrupt value */
  volatile std::uint32_t WINDOW;  /*!< contains the Watchdog window value. */
};

}  // namespace libmcuhw::wwdt
#endif