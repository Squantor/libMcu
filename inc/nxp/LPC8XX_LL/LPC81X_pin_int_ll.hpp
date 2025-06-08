/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_pin_int_ll.hpp
 * @brief LPC810 series Pin interrupt interface class and definitions
 */
#ifndef LPC81X_PIN_INT_HPP
#define LPC81X_PIN_INT_HPP

namespace libmcull::pin_int {
namespace hardware = libmcuhw::pinint;
/**
 * @brief Pin interrupt peripheral low level interface
 * @tparam pinint_address
 */
template <libmcu::PinintBaseAddress pinint_address>
struct Pinint : libmcull::PeripheralBase {
  /**
   * @brief get registers from peripheral
   * @return pointer to pin interrupt registers
   */
  constexpr static libmcuhw::pinint::Pinint *GetPeripheral() {
    return reinterpret_cast<libmcuhw::pinint::Pinint *>(pinint_address_);
  }

 private:
  static constexpr libmcu::HwAddressType pinint_address_ = pinint_address; /*!< peripheral address */
};
}  // namespace libmcull::pin_int
#endif