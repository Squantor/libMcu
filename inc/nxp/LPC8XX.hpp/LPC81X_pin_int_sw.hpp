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

namespace libMcuLL {
namespace sw {
namespace pin_int {
using namespace hw::gpio;
template <libMcuLL::pinintBaseAddress pinintAddress_>
struct pinint : peripheralBase {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to pin interrupt registers
   */
  constexpr static hw::pinint::peripheral *pinintPeripheral() {
    return reinterpret_cast<hw::pinint::peripheral *>(pinintAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType pinintAddress = pinintAddress_; /**< peripheral address */
};
}  // namespace pin_int
}  // namespace sw
}  // namespace libMcuLL

#endif