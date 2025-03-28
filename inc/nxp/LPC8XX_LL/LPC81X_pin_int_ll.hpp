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

namespace libmcull::sw::pin_int {
using namespace libmcuhw::gpio;
template <libmcu::pinintBaseAddress pinintAddress_>
struct pinint : libmcu::PeripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to pin interrupt registers
   */
  constexpr static libmcuhw::pinint::pinint *pinintPeripheral() {
    return reinterpret_cast<libmcuhw::pinint::pinint *>(pinintAddress);
  }

 private:
  static constexpr libmcu::hwAddressType pinintAddress = pinintAddress_; /*!< peripheral address */
};
}  // namespace libmcull::sw::pin_int
#endif