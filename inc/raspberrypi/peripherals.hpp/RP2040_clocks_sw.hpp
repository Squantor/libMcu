/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 clocks software interface
 */
#ifndef RP2040_CLOCKS_SW_HPP
#define RP2040_CLOCKS_SW_HPP

namespace libMcuLL {
namespace sw {
namespace clocks {
template <libMcuLL::clocksBaseAddress const& clocksAddress_>
struct clocks : libMcuLL::peripheralBase {
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
  static hw::clocks::peripheral* clocksPeripheral() {
    return reinterpret_cast<hw::clocks::peripheral*>(clocksAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType clocksAddress = clocksAddress_; /**< peripheral address */
};
}  // namespace clocks
}  // namespace sw
}  // namespace libMcuLL
#endif