/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_vreg_chip_reset_ll.hpp
 * @brief low level interface for the RP2040 Voltage regulator and chip reset
 */
#ifndef RP2040_VREG_CHIP_RESET_LL_HPP
#define RP2040_VREG_CHIP_RESET_LL_HPP

namespace libmcull::vregChipReset {
namespace hardware = libmcuhw::vregChipReset;
/**
 * @brief
 * @tparam vregchip_reset_address
 */
template <libmcu::VregChipResetBaseAddress const& vregchip_reset_address>
struct VregChipReset : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::VregChipReset* GetPeripheral() {
    return reinterpret_cast<hardware::VregChipReset*>(vregchip_reset_address_);
  }

 private:
  static constexpr libmcu::HwAddressType vregchip_reset_address_{vregchip_reset_address}; /*!< peripheral address */
};
}  // namespace libmcull::vregChipReset
#endif