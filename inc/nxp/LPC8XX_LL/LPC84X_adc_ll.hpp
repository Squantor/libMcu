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
template <libmcu::AdcBaseAddress adcAddress_>
struct adc : libmcu::PeripheralBase {
  /**
   * @brief
   * @tparam &config clock configuration
   * @param rate sampling rate
   */
  template <auto &config>
  constexpr void init(uint32_t rate) {
    uint32_t maxRate{getInputClockFreq<config>() / 25};
    // initiate hardware selfcal
    adcPeripheral()->CTRL = hardware::CTRL::kCALMODE | hardware::CTRL::CLKDIV(maxRate / 500000);
    while (adcPeripheral()->CTRL & hardware::CTRL::kCALMODE)
      ;
    // configure ADC sample rate
    adcPeripheral()->CTRL = hardware::CTRL::CLKDIV(maxRate / rate);
  }
  /**
   * @brief single shot sampling of an ADC pin
   * Uses ADC sequencer A to initiate a single shot reading of ADC pin
   * @param pin ADC pin to read
   * @return ADC value
   */
  template <typename PIN>
  constexpr std::uint32_t sample(PIN &pin) {
    std::uint32_t channelIndex = static_cast<std::uint32_t>(pin.adcPinIndex);
    adcPeripheral()->SEQ_CTRL[hardware::kSequencerA] = hardware::SEQ_CTRL::CHANNELS(channelIndex) | hardware::SEQ_CTRL::kTRIG_NONE |
                                                       hardware::SEQ_CTRL::kTRIGPOL_POS | hardware::SEQ_CTRL::kLOWPRIO |
                                                       hardware::SEQ_CTRL::kSEQ_ENA;
    adcPeripheral()->SEQ_CTRL[hardware::kSequencerA] =
      adcPeripheral()->SEQ_CTRL[hardware::kSequencerA] | hardware::SEQ_CTRL::kSTART;
    std::uint32_t adcSample;
    do {
      adcSample = adcPeripheral()->DAT[channelIndex];
    } while (!(adcSample & hardware::DAT::kDATAVALID_FLAG));
    return hardware::DAT::RESULT(adcSample);
  }
  /**
   * @brief Get input frequency of this peripheral
   * @tparam &config clock configuration
   * @return clock frequency for this peripheral with this input
   */
  template <auto &config>
  constexpr std::uint32_t getInputClockFreq() {
    if constexpr (config.adcSource == libmcuhw::clock::periSource::SYS_PLL)
      return config.mainFreq;
    else if constexpr (config.adcSource == libmcuhw::clock::periSource::FRO)
      return config.froFreq;
    else
      static_assert(false, "Not available/implemented clock source!");
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to ADC registers
   */
  constexpr static hardware::Adc *adcPeripheral() {
    return reinterpret_cast<hardware::Adc *>(adcAddress);
  }

 private:
  static constexpr libmcu::HwAddressType adcAddress = adcAddress_; /*!< peripheral address */
};

}  // namespace libmcull::adc
#endif
