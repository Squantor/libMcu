/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 ADC software interface
 */
#ifndef RP2040_ADC_SW_HPP
#define RP2040_ADC_SW_HPP

namespace libMcuLL::sw::adc {
template <libMcuLL::adcBaseAddress const& adcAddress_>
struct adc : libMcuLL::peripheralBase {
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
  static hw::adc::peripheral* adcPeripheral() {
    return reinterpret_cast<hw::adc::peripheral*>(adcAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType adcAddress = adcAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::adc
#endif