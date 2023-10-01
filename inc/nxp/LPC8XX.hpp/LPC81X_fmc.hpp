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

namespace libMcuLL {
namespace sw {
namespace fmc {
using namespace libMcuLL::hw::fmc;
template <libMcuLL::FMCaddress address_>
struct fmc {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to gpio registers
   */
  static hw::fmc::peripheral *peripheral() {
    return reinterpret_cast<hw::fmc::peripheral *>(address_);
  }
};
}  // namespace fmc
}  // namespace sw
}  // namespace libMcuLL

#endif