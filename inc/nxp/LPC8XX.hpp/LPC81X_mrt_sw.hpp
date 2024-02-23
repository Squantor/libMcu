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
template <libMcuLL::MRTbaseAddress mrtAddress_>
struct mrt : libMcuLL::peripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to mrt registers
   */
  constexpr static hw::mrt::peripheral *mrtPeripheral() {
    return reinterpret_cast<hw::mrt::peripheral *>(mrtAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType mrtAddress = mrtAddress_; /**< peripheral address */
};
}  // namespace mrt
}  // namespace sw
}  // namespace libMcuLL

#endif