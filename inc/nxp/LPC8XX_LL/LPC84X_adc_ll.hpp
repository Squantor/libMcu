/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_adc_ll.hpp
 * @brief LPC84X series ADC low level functions and definitions
 */
#ifndef LPC84X_ADC_LL_HPP
#define LPC84X_ADC_LL_HPP

namespace libmcull::adc {
namespace hardware = libmcuhw::adc;
template <libmcu::AdcBaseAddress adc_address>
struct Adc : libmcull::PeripheralBase {
  /**
   * @brief
   * @tparam &config clock configuration
   * @param rate sampling rate
   */
  template <auto &config>
  constexpr void Init(uint32_t rate) {
    uint32_t maxRate{GetInputClockFreq<config>() / 25};
    // initiate hardware selfcal
    GetPeripheral()->CTRL = hardware::CTRL::CALMODE | hardware::CTRL::CLKDIV(maxRate / 500000);
    while (GetPeripheral()->CTRL & hardware::CTRL::CALMODE)
      ;
    // configure ADC sample rate
    GetPeripheral()->CTRL = hardware::CTRL::CLKDIV(maxRate / rate);
  }
  /**
   * @brief single shot sampling of an ADC pin
   * Uses ADC sequencer A to initiate a single shot reading of ADC pin
   * @param pin ADC pin to read
   * @return ADC value
   */
  template <typename PIN>
  constexpr std::uint32_t Sample(PIN &pin) {
    std::uint32_t channelIndex = static_cast<std::uint32_t>(pin.adcPinIndex);
    GetPeripheral()->SEQ_CTRL[hardware::kSequencerA] = hardware::SEQ_CTRL::CHANNELS(channelIndex) | hardware::SEQ_CTRL::TRIG_NONE |
                                                       hardware::SEQ_CTRL::TRIGPOL_POS | hardware::SEQ_CTRL::LOWPRIO |
                                                       hardware::SEQ_CTRL::SEQ_ENA;
    GetPeripheral()->SEQ_CTRL[hardware::kSequencerA] = GetPeripheral()->SEQ_CTRL[hardware::kSequencerA] | hardware::SEQ_CTRL::START;
    std::uint32_t adcSample;
    do {
      adcSample = GetPeripheral()->DAT[channelIndex];
    } while (!(adcSample & hardware::DAT::DATAVALID_FLAG));
    return hardware::DAT::RESULT(adcSample);
  }
  /**
   * @brief Get input frequency of this peripheral
   * @tparam &config clock configuration
   * @return clock frequency for this peripheral with this input
   */
  template <auto &config>
  constexpr std::uint32_t GetInputClockFreq() {
    if constexpr (config.adcSource == libmcuhw::clock::PeriSource::SYS_PLL)
      return config.mainFreq;
    else if constexpr (config.adcSource == libmcuhw::clock::PeriSource::FRO)
      return config.froFreq;
    else
      static_assert(false, "Not available/implemented clock source!");
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to ADC registers
   */
  constexpr static hardware::Adc *GetPeripheral() {
    return reinterpret_cast<hardware::Adc *>(adc_address_);
  }

 private:
  static constexpr libmcu::HwAddressType adc_address_ = adc_address; /*!< peripheral address */
};

}  // namespace libmcull::adc
#endif
