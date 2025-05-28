/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_pads_qspi_ll.hpp
 * @brief low level interface for the RP2040 pads QSPI
 */
#ifndef RP2040_PADS_QSPI_SW_HPP
#define RP2040_PADS_QSPI_SW_HPP

namespace libmcull::padsQspi {
namespace hardware = libmcuhw::padsQspi;
/**
 * @brief
 * @tparam padsQspiAddress_
 */
template <libmcu::padsQspiBaseAddress const& padsQspiAddress_>
struct padsQspi : libmcu::PeripheralBase {
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
  static constexpr libmcu::HwAddressType padsQspiAddress = padsQspiAddress_; /*!< peripheral address */
};
}  // namespace libmcull::padsQspi
#endif