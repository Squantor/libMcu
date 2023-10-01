/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series windowed watchdog functions
 */
#ifndef LPC81X_WWDT_HPP
#define LPC81X_WWDT_HPP

namespace instances {
namespace wwdt {
using namespace registers::wwdt;
template <libMcuLL::WWDTaddress address_>
struct wwdt {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to windowed watchdog registers
   */
  static auto regs() {
    return reinterpret_cast<registers::wwdt::registers *>(address_);
  }
};
}  // namespace wwdt
}  // namespace instances

#endif