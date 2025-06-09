/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_sysinfo_ll.hpp
 * @brief low level interface for the RP2040 Sysinfo
 */
#ifndef RP2040_SYSINFO_LL_HPP
#define RP2040_SYSINFO_LL_HPP

namespace libmcull::sysinfo {
namespace hardware = libmcuhw::sysinfo;
/**
 * @brief
 * @tparam sysinfo_address
 */
template <libmcu::SysinfoBaseAddress const& sysinfo_address>
struct Sysinfo : libmcull::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Sysinfo* GetPeripheral() {
    return reinterpret_cast<hardware::Sysinfo*>(sysinfo_address_);
  }

 private:
  static constexpr libmcu::HwAddressType sysinfo_address_ = sysinfo_address; /*!< peripheral address */
};
}  // namespace libmcull::sysinfo
#endif