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

namespace libMcuLL::sw::pio {
template <libMcuLL::pioBaseAddress const& pioAddress_>
struct pio : libMcuLL::peripheralBase {
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
  static hw::pio::peripheral* pioPeripheral() {
    return reinterpret_cast<hw::pio::peripheral*>(pioAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType pioAddress = pioAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::pio
#endif