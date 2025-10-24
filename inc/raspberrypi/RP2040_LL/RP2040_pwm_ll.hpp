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
#ifndef RP2040_PWM_LL_HPP
#define RP2040_PWM_LL_HPP

namespace libmcull::pwm {
namespace hardware = libmcuhw::pwm;
/**
 * @brief
 * @tparam pwm_address
 */
template <libmcu::PwmBaseAddress const& pwm_address>
struct Pwm : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Pwm* GetPeripheral() {
    return reinterpret_cast<hardware::Pwm*>(pwm_address_);
  }

 private:
  static constexpr libmcu::HwAddressType pwm_address_{pwm_address}; /*!< peripheral address */
};
}  // namespace libmcull::pwm
#endif