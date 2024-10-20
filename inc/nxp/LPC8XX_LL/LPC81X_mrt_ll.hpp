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

namespace libMcuLL::sw::mrt {
using namespace hw::mrt;
template <libMcu::mrtBaseAddress mrtAddress_>
struct mrt : libMcu::peripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to mrt registers
   */
  constexpr static hw::mrt::mrt *mrtPeripheral() {
    return reinterpret_cast<hw::mrt::mrt *>(mrtAddress);
  }

 private:
  static constexpr libMcu::hwAddressType mrtAddress = mrtAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::mrt
#endif