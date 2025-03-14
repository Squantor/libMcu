/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_mrt_ll.hpp
 * @brief LPC810 series Multi rate timer interface class and definitions
 */
#ifndef LPC81X_MRT_HPP
#define LPC81X_MRT_HPP

namespace libMcuLL::sw::mrt {
using namespace hw::mrt;
template <libMcu::mrtBaseAddress mrtAddress_>
struct mrt : libMcu::PeripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to mrt registers
   */
  constexpr static hw::mrt::mrt *mrtPeripheral() {
    return reinterpret_cast<hw::mrt::mrt *>(mrtAddress);
  }

 private:
  static constexpr libMcu::hwAddressType mrtAddress = mrtAddress_; /*!< peripheral address */
};
}  // namespace libMcuLL::sw::mrt
#endif