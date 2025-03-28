/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_pwm_ll.hpp
 * @brief low level interface for the RP2040 PWM
 */
#ifndef RP2040_PWM_SW_HPP
#define RP2040_PWM_SW_HPP

namespace libmcull::pwm {
namespace hardware = libmcuhw::pwm;
/**
 * @brief
 * @tparam pwmAddress_
 */
template <libmcu::pwmBaseAddress const& pwmAddress_>
struct pwm : libmcu::PeripheralBase {
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
  static hardware::pwm* pwmPeripheral() {
    return reinterpret_cast<hardware::pwm*>(pwmAddress);
  }

 private:
  static constexpr libmcu::hwAddressType pwmAddress{pwmAddress_}; /*!< peripheral address */
};
}  // namespace libmcull::pwm
#endif