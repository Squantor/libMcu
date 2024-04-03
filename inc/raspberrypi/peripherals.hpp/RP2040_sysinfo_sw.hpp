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

namespace libMcuLL {
namespace sw {
namespace sysinfo {
template <libMcuLL::sysinfoBaseAddress const& sysinfoAddress_>
struct sysinfo : libMcuLL::peripheralBase {
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
  static hw::sysinfo::peripheral* sysinfoPeripheral() {
    return reinterpret_cast<hw::sysinfo::peripheral*>(sysinfoAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType sysinfoAddress = sysinfoAddress_; /**< peripheral address */
};
}  // namespace sysinfo
}  // namespace sw
}  // namespace libMcuLL
#endif