/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC84X series ADC low level functions
 */
#ifndef LPC84X_ADC_LL_HPP
#define LPC84X_ADC_LL_HPP

namespace libMcuLL::adc {
namespace hardware = libMcuHw::adc;
template <libMcu::adcBaseAddress adcAddress_>
struct adc : libMcu::peripheralBase {
  /**
   * @brief
   * @tparam &config clock configuration
   * @param rate sampling rate
   */
  template <auto &config>
  constexpr void init(uint32_t rate) {
    uint32_t maxRate{getInputClockFreq<config>() / 25};
    // initiate hardware selfcal
    adcPeripheral()->CTRL = hardware::CTRL::CALMODE | hardware::CTRL::CLKDIV(maxRate / 500000);
    while (adcPeripheral()->CTRL & hardware::CTRL::CALMODE)
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
    adcPeripheral()->SEQ_CTRL[hardware::SEQA] = hardware::SEQ_CTRL::CHANNELS(channelIndex) | hardware::SEQ_CTRL::TRIG_NONE |
                                                hardware::SEQ_CTRL::TRIGPOL_POS | hardware::SEQ_CTRL::LOWPRIO |
                                                hardware::SEQ_CTRL::SEQ_ENA;
    adcPeripheral()->SEQ_CTRL[hardware::SEQA] = adcPeripheral()->SEQ_CTRL[hardware::SEQA] | hardware::SEQ_CTRL::START;
    std::uint32_t adcSample;
    do {
      adcSample = adcPeripheral()->DAT[channelIndex];
    } while (!(adcSample & hardware::DAT::DATAVALID_FLAG));
    return hardware::DAT::RESULT(adcSample);
  }
  /**
   * @brief Get input frequency of this peripheral
   * @tparam &config clock configuration
   * @return clock frequency for this peripheral with this input
   */
  template <auto &config>
  constexpr std::uint32_t getInputClockFreq() {
    if constexpr (config.adcSource == libMcuHw::clock::periSource::SYS_PLL)
      return config.mainFreq;
    else if constexpr (config.adcSource == libMcuHw::clock::periSource::FRO)
      return config.froFreq;
    else
      static_assert(false, "Not available/implemented clock source!");
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to ADC registers
   */
  constexpr static hardware::adc *adcPeripheral() {
    return reinterpret_cast<hardware::adc *>(adcAddress);
  }

 private:
  static constexpr libMcu::hwAddressType adcAddress = adcAddress_; /**< peripheral address */
};

}  // namespace libMcuLL::adc
#endif
