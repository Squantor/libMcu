/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_adc_ll.hpp
 * @brief low level interface for the RP2040 ADC
 */
#ifndef RP2040_ADC_SW_HPP
#define RP2040_ADC_SW_HPP

namespace libmcull::adc {
namespace hardware = libmcuhw::adc;
template <libmcu::AdcBaseAddress const& adcAddress_>
struct adc : libmcull::PeripheralBase {
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
  static hardware::adc* adcPeripheral() {
    return reinterpret_cast<hardware::adc*>(adcAddress);
  }

 private:
  static constexpr libmcu::HwAddressType adcAddress = adcAddress_; /*!< peripheral address */
};
}  // namespace libmcull::adc
#endif