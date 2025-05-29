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
#ifndef RP2040_VREG_CHIP_RESET_SW_HPP
#define RP2040_VREG_CHIP_RESET_SW_HPP

namespace libmcull::vregChipReset {
namespace hardware = libmcuhw::vregChipReset;
template <libmcu::VregChipResetBaseAddress const& vregChipResetAddress_>
struct vregChipReset : libmcu::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::vregChipReset* vregChipResetPeripheral() {
    return reinterpret_cast<hardware::vregChipReset*>(vregChipResetAddress);
  }

 private:
  static constexpr libmcu::HwAddressType vregChipResetAddress{vregChipResetAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::vregChipReset
#endif