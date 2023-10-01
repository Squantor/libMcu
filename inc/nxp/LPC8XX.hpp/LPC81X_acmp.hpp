/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series analog comparator functions
 */
#ifndef LPC81X_ACMP_HPP
#define LPC81X_ACMP_HPP
namespace libMcuLL {
namespace sw {
namespace acmp {
using namespace hw::acmp;
template <libMcuLL::ACMPaddress const& address_>
struct acmp {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to analog comparator registers
   */
  static hw::acmp::peripheral* peripheral() {
    return reinterpret_cast<hw::acmp::peripheral*>(address);
  }
};
}  // namespace acmp
}  // namespace sw
}  // namespace libMcuLL

#endif