/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series State configurable timer functions
 */
#ifndef LPC81X_SCT_HPP
#define LPC81X_SCT_HPP

namespace libMcuLL {
namespace sw {
namespace sct {
using namespace hw::sct;
template <libMcuLL::SCTaddress address_>
struct sct {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to state configurable timer registers
   */
  static hw::sct::peripheral *regs() {
    return reinterpret_cast<hw::sct::peripheral *>(address_);
  }
};
}  // namespace sct
}  // namespace sw
}  // namespace libMcuLL

#endif