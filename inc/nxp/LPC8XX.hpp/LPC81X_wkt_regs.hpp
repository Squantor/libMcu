/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series wakeup timer register interface
 */
#ifndef LPC81X_WKT_REGS_HPP
#define LPC81X_WKT_REGS_HPP

namespace registers {
namespace wkt {

/**
 * @brief wakeup timer register definitions
 *
 */
struct registers {
  volatile uint32_t CTRL; /**< Alarm/Wakeup Timer Control register */
  uint32_t Reserved[2];
  volatile uint32_t COUNT; /**< Alarm/Wakeup Timer Counter register */
};

}  // namespace wkt
}  // namespace registers

#endif