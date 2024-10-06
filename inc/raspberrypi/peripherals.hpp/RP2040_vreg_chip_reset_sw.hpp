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

namespace libMcuLL::vregChipReset {
template <libMcu::vregChipResetBaseAddress const& vregChipResetAddress_>
struct vregChipReset : libMcu::peripheralBase {
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
  static libMcuHw::vregChipReset::peripheral* vregChipResetPeripheral() {
    return reinterpret_cast<libMcuHw::vregChipReset::peripheral*>(vregChipResetAddress);
  }

 private:
  static constexpr libMcu::hwAddressType vregChipResetAddress{vregChipResetAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::vregChipReset
#endif