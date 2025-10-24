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
#ifndef RP2040_PADS_QSPI_LL_HPP
#define RP2040_PADS_QSPI_LL_HPP

namespace libmcull::pads {
namespace hardware_qspi = libmcuhw::padsQspi;
/**
 * @brief
 * @tparam pads_qspi_address
 */
template <libmcu::PadsQspiBaseAddress const& pads_qspi_address>
struct PadsQspi : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware_qspi::PadsQspi* GetPeripheral() {
    return reinterpret_cast<hardware_qspi::PadsQspi*>(pads_qspi_address_);
  }

 private:
  static constexpr libmcu::HwAddressType pads_qspi_address_ = pads_qspi_address; /*!< peripheral address */
};
}  // namespace libmcull::pads
#endif