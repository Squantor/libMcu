/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Flash memory control functions
 */
#ifndef LPC81X_FMC_HPP
#define LPC81X_FMC_HPP

namespace instances {
namespace fmc {
using namespace registers::fmc;
template <libMcuLL::FMCaddress address_>
struct fmc {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  static auto regs() {
    return reinterpret_cast<registers::fmc::registers *>(address_);
  }
};
}  // namespace fmc
}  // namespace instances

#endif