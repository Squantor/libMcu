/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series pin interrupt functions
 */
#ifndef LPC81X_PIN_INT_HPP
#define LPC81X_PIN_INT_HPP

namespace libMcuLL::sw::pin_int {
using namespace hw::gpio;
template <libMcu::pinintBaseAddress pinintAddress_>
struct pinint : libMcu::peripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to pin interrupt registers
   */
  constexpr static hw::pinint::pinint *pinintPeripheral() {
    return reinterpret_cast<hw::pinint::pinint *>(pinintAddress);
  }

 private:
  static constexpr libMcu::hwAddressType pinintAddress = pinintAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::pin_int
#endif