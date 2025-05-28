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

namespace libmcull::sw::mrt {
namespace hardware = libmcuhw::mrt;
/**
 * @brief Mrt peripheral low level interface
 * @tparam mrt_address peripheral address
 */
template <libmcu::MrtBaseAddress mrt_address>
struct Mrt : libmcu::PeripheralBase {
  /**
   * @brief get registers from peripheral
   * @return return pointer to mrt registers
   */
  constexpr static libmcuhw::mrt::Mrt *GetPeripheral() {
    return reinterpret_cast<libmcuhw::mrt::Mrt *>(mrt_address_);
  }

 private:
  static constexpr libmcu::HwAddressType mrt_address_ = mrt_address; /*!< peripheral address */
};
}  // namespace libmcull::sw::mrt
#endif