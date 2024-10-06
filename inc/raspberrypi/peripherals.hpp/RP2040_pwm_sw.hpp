/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 PWM software interface
 */
#ifndef RP2040_PWM_SW_HPP
#define RP2040_PWM_SW_HPP

namespace libMcuLL::pwm {
template <libMcu::pwmBaseAddress const& pwmAddress_>
struct pwm : libMcu::peripheralBase {
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
  static libMcuHw::pwm::peripheral* pwmPeripheral() {
    return reinterpret_cast<libMcuHw::pwm::peripheral*>(pwmAddress);
  }

 private:
  static constexpr libMcu::hwAddressType pwmAddress{pwmAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::pwm
#endif