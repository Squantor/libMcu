/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_wwdt_ll.hpp
 * @brief LPC810 series windowed watchdog interface class and definitions
 */
#ifndef LPC81X_WWDT_HPP
#define LPC81X_WWDT_HPP

namespace libmcull::wwdt {
namespace hardware = libmcuhw::wwdt;
/**
 * @brief
 * @tparam wwdtAddress_
 */
template <libmcu::WwdtBaseAddress wwdt_address>
struct Wwdt {
  /**
   * @brief get registers from peripheral
   * @return return pointer to windowed watchdog registers
   */
  static libmcuhw::wwdt::Wwdt *GetPeripheral() {
    return reinterpret_cast<libmcuhw::wwdt::Wwdt *>(wwdt_address_);
  }

 private:
  static constexpr libmcu::HwAddressType wwdt_address_ = wwdt_address; /*!< peripheral address */
};
}  // namespace libmcull::wwdt
#endif