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

namespace libMcuLL::sw::pin_int {
using namespace hw::gpio;
template <libmcu::pinintBaseAddress pinintAddress_>
struct pinint : libmcu::PeripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to pin interrupt registers
   */
  constexpr static hw::pinint::pinint *pinintPeripheral() {
    return reinterpret_cast<hw::pinint::pinint *>(pinintAddress);
  }

 private:
  static constexpr libmcu::hwAddressType pinintAddress = pinintAddress_; /*!< peripheral address */
};
}  // namespace libMcuLL::sw::pin_int
#endif