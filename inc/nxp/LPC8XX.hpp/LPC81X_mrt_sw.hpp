/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Multi rate timer functions
 */
#ifndef LPC81X_MRT_HPP
#define LPC81X_MRT_HPP

namespace libMcuLL {
namespace sw {
namespace mrt {
using namespace hw::mrt;
template <libMcuLL::MRTbaseAddress address_>
struct mrt {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to mrt registers
   */
  static hw::mrt::peripheral *peripheral() {
    return reinterpret_cast<hw::mrt::peripheral *>(address_);
  }
};
}  // namespace mrt
}  // namespace sw
}  // namespace libMcuLL

#endif