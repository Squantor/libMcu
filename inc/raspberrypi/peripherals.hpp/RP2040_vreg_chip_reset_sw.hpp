/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Voltage regulator and chip reset software interface
 */
#ifndef RP2040_VREG_CHIP_RESET_SW_HPP
#define RP2040_VREG_CHIP_RESET_SW_HPP

namespace libMcuLL::sw::vregChipReset {
template <libMcuLL::vregChipResetBaseAddress const& vregChipResetAddress_>
struct vregChipReset : libMcuLL::peripheralBase {
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
  static hw::vregChipReset::peripheral* vregChipResetPeripheral() {
    return reinterpret_cast<hw::vregChipReset::peripheral*>(vregChipResetAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType vregChipResetAddress{vregChipResetAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sw::vregChipReset
#endif