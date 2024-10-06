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

namespace libMcuLL::adc {
template <libMcu::adcBaseAddress const& adcAddress_>
struct adc : libMcu::peripheralBase {
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
  static libMcuHw::adc::peripheral* adcPeripheral() {
    return reinterpret_cast<libMcuHw::adc::peripheral*>(adcAddress);
  }

 private:
  static constexpr libMcu::hwAddressType adcAddress = adcAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::adc
#endif