/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 QSPI pads software interface
 */
#ifndef RP2040_PADS_QSPI_SW_HPP
#define RP2040_PADS_QSPI_SW_HPP

namespace libMcuLL {
namespace sw {
namespace padsQspi {
template <libMcuLL::padsQspiBaseAddress const& padsQspiAddress_>
struct padsQspi : libMcuLL::peripheralBase {
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
  static hw::padsQspi::peripheral* padsQspiPeripheral() {
    return reinterpret_cast<hw::padsQspi::peripheral*>(padsQspiAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType padsQspiAddress = padsQspiAddress_; /**< peripheral address */
};
}  // namespace padsQspi
}  // namespace sw
}  // namespace libMcuLL
#endif