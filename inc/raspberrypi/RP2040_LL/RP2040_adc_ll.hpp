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
#ifndef RP2040_ADC_LL_HPP
#define RP2040_ADC_LL_HPP

namespace libmcull::adc {
namespace hardware = libmcuhw::adc;
/**
 * @brief
 * @tparam adc_address
 */
template <libmcu::AdcBaseAddress const& adc_address>
struct Adc : libmcull::AdcBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Adc* GetPeripheral() {
    return reinterpret_cast<hardware::Adc*>(adc_address_);
  }

 private:
  static constexpr libmcu::HwAddressType adc_address_ = adc_address; /*!< peripheral address */
};
}  // namespace libmcull::adc
#endif