/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Resets software interface
 */
#ifndef RP2040_RESETS_SW_HPP
#define RP2040_RESETS_SW_HPP

namespace libMcuLL {
namespace sw {
namespace resets {
template <libMcuLL::resetsBaseAddress const& resetAddress_>
struct resets : libMcuLL::peripheralBase {
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
  static hw::resets::peripheral* resetsPeripheral() {
    return reinterpret_cast<hw::resets::peripheral*>(resetAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType resetAddress{resetAddress_}; /**< peripheral address */
};
}  // namespace resets
}  // namespace sw
}  // namespace libMcuLL
#endif