/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_syscfg_ll.hpp
 * @brief low level interface for the RP2040 System configuration
 */
#ifndef RP2040_SYSCFG_SW_HPP
#define RP2040_SYSCFG_SW_HPP

namespace libmcull::syscfg {
namespace hardware = libmcuhw::syscfg;
template <libmcu::SyscfgBaseAddress const& syscfgAddress_>
struct syscfg : libmcu::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::syscfg* syscfgPeripheral() {
    return reinterpret_cast<hardware::syscfg*>(syscfgAddress);
  }

 private:
  static constexpr libmcu::HwAddressType syscfgAddress{syscfgAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::syscfg
#endif