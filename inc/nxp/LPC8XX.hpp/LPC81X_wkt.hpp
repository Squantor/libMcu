/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series wakeup timer functions
 */
#ifndef LPC81X_WKT_HPP
#define LPC81X_WKT_HPP

namespace instances {
namespace wkt {
using namespace registers::wkt;
template <libMcuLL::WKTtype base>
struct wkt {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to wkt registers
   */
  static auto regs() {
    return reinterpret_cast<registers::wkt::registers *>(base);
  }
};
}  // namespace wkt
}  // namespace instances

#endif