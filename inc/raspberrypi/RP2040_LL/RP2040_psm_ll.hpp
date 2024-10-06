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

namespace libMcuLL::psm {
namespace hardware = libMcuHw::psm;
/**
 * @brief
 * @tparam psmAddress_
 */
template <libMcu::psmBaseAddress const& psmAddress_>
struct psm : libMcu::peripheralBase {
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
  static hardware::psm* psmPeripheral() {
    return reinterpret_cast<hardware::psm*>(psmAddress);
  }

 private:
  static constexpr libMcu::hwAddressType psmAddress{psmAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::psm
#endif