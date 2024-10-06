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

namespace libMcuLL::padsQspi {
namespace hardware = libMcuHw::padsQspi;
/**
 * @brief
 * @tparam padsQspiAddress_
 */
template <libMcu::padsQspiBaseAddress const& padsQspiAddress_>
struct padsQspi : libMcu::peripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::padsQspi* padsQspiPeripheral() {
    return reinterpret_cast<hardware::padsQspi*>(padsQspiAddress);
  }

 private:
  static constexpr libMcu::hwAddressType padsQspiAddress = padsQspiAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::padsQspi
#endif