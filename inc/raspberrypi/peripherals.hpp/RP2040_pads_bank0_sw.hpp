/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 pads bank0 software interface
 */
#ifndef RP2040_PADS_BANK0_SW_HPP
#define RP2040_PADS_BANK0_SW_HPP

namespace libMcuLL {
namespace sw {
namespace padsBank0 {
template <libMcuLL::padsBank0BaseAddress const& padsBank0Address_>
struct padsBank0 : libMcuLL::peripheralBase {
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
  static hw::padsBank0::peripheral* padsBank0Peripheral() {
    return reinterpret_cast<hw::padsBank0::peripheral*>(padsBank0Address);
  }

 private:
  static constexpr libMcuLL::hwAddressType padsBank0Address = padsBank0Address_; /**< peripheral address */
};
}  // namespace padsBank0
}  // namespace sw
}  // namespace libMcuLL
#endif