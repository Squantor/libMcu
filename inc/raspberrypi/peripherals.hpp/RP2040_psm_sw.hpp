/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 PSM software interface
 */
#ifndef RP2040_PSM_SW_HPP
#define RP2040_PSM_SW_HPP

namespace libMcuLL::sw::psm {
template <libMcuLL::psmBaseAddress const& psmAddress_>
struct psm : libMcuLL::peripheralBase {
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
  static hw::psm::peripheral* psmPeripheral() {
    return reinterpret_cast<hw::psm::peripheral*>(psmAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType psmAddress{psmAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sw::psm
#endif