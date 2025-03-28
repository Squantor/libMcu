/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_tbman_ll.hpp
 * @brief low level interface for the RP2040 Testbench Manager
 */
#ifndef RP2040_TBMAN_SW_HPP
#define RP2040_TBMAN_SW_HPP

namespace libMcuLL::tbman {
namespace hardware = libMcuHw::tbman;
template <libmcu::tbmanBaseAddress const& tbmanAddress_>
struct tbman : libmcu::PeripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::tbman* tbmanPeripheral() {
    return reinterpret_cast<hardware::tbman*>(tbmanAddress);
  }

 private:
  static constexpr libmcu::hwAddressType tbmanAddress{tbmanAddress_}; /*!< peripheral address */
};
}  // namespace libMcuLL::tbman
#endif