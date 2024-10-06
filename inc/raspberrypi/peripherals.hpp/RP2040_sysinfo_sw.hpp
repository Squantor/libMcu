/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Sysinfo software interface
 */
#ifndef RP2040_SYSINFO_SW_HPP
#define RP2040_SYSINFO_SW_HPP

namespace libMcuLL::sw::sysinfo {
template <libMcu::sysinfoBaseAddress const& sysinfoAddress_>
struct sysinfo : libMcu::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libMcuHw::sysinfo::peripheral* sysinfoPeripheral() {
    return reinterpret_cast<libMcuHw::sysinfo::peripheral*>(sysinfoAddress);
  }

 private:
  static constexpr libMcu::hwAddressType sysinfoAddress = sysinfoAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::sysinfo
#endif