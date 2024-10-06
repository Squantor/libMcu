/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 PIO software interface
 */
#ifndef RP2040_PIO_SW_HPP
#define RP2040_PIO_SW_HPP

namespace libMcuLL::pio {
namespace hardware = libMcuHw::pio;
/**
 * @brief
 * @tparam pioAddress_
 */
template <libMcu::pioBaseAddress const& pioAddress_>
struct pio : libMcu::peripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::pio* pioPeripheral() {
    return reinterpret_cast<hardware::pio*>(pioAddress);
  }

 private:
  static constexpr libMcu::hwAddressType pioAddress = pioAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::pio
#endif