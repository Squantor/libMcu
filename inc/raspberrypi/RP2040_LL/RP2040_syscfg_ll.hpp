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
#ifndef RP2040_SYSCFG_LL_HPP
#define RP2040_SYSCFG_LL_HPP

namespace libmcull::syscfg {
namespace hardware = libmcuhw::syscfg;
/**
 * @brief
 * @tparam syscfg_address
 */
template <libmcu::SyscfgBaseAddress const& syscfg_address>
struct Syscfg : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Syscfg* GetPeripheral() {
    return reinterpret_cast<hardware::Syscfg*>(syscfg_address_);
  }

 private:
  static constexpr libmcu::HwAddressType syscfg_address_{syscfg_address}; /*!< peripheral address */
};
}  // namespace libmcull::syscfg
#endif