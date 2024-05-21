/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 clocks software interface
 */
#ifndef RP2040_CLOCKS_SW_HPP
#define RP2040_CLOCKS_SW_HPP

namespace libMcuLL::sw::clocks {
using namespace libMcuLL;
/**
 * @brief available clock generators
 */
enum class gpoutGenerators : std::uint32_t {
  GPOUT0 = hw::clocks::clockIndex::GPOUT0, /**< GPIO mux clock 0 */
  GPOUT1 = hw::clocks::clockIndex::GPOUT1, /**< GPIO mux clock 1 */
  GPOUT2 = hw::clocks::clockIndex::GPOUT2, /**< GPIO mux clock 2 */
  GPOUT3 = hw::clocks::clockIndex::GPOUT3, /**< GPIO mux clock 3 */
};
/**
 * @brief available clock sources for gpout clock generators
 */
enum class gpoutSources : std::uint32_t {
  PLL_SYS = hw::clocks::CTRL::GPOUT_AUX_PLL_SYS,
  GPIN0 = hw::clocks::CTRL::GPOUT_AUX_GPIN0,
  GPIN1 = hw::clocks::CTRL::GPOUT_AUX_GPIN1,
  PLL_USB = hw::clocks::CTRL::GPOUT_AUX_PLL_USB,
  ROSC = hw::clocks::CTRL::GPOUT_AUX_ROSC,
  XOSC = hw::clocks::CTRL::GPOUT_AUX_XOSC,
  SYS = hw::clocks::CTRL::GPOUT_AUX_CLK_SYS,
  USB = hw::clocks::CTRL::GPOUT_AUX_CLK_USB,
  ADC = hw::clocks::CTRL::GPOUT_AUX_CLK_ADC,
  RTC = hw::clocks::CTRL::GPOUT_AUX_CLK_RTC,
  REF = hw::clocks::CTRL::GPOUT_AUX_CLK_REF,
};
/**
 * @brief
 */
enum class referenceAuxSources : std::uint32_t {
  PLL_USB = hw::clocks::CTRL::REF_AUX_PLL_USB,
  GPIN0 = hw::clocks::CTRL::REF_AUX_GPIN0,
  GPIN1 = hw::clocks::CTRL::REF_AUX_GPIN1,
};
/**
 * @brief
 */
enum class referenceSources : std::uint32_t {
  ROSC = hw::clocks::CTRL::REF_SRC_ROSC,
  AUX = hw::clocks::CTRL::REF_SRC_AUX,
  XOSC = hw::clocks::CTRL::REF_SRC_XOSC,
};
/**
 * @brief
 */
enum class systemAuxSources : std::uint32_t {
  PLL_SYS = hw::clocks::CTRL::SYS_AUX_PLL_SYS,
  PLL_USB = hw::clocks::CTRL::SYS_AUX_PLL_USB,
  ROSC = hw::clocks::CTRL::SYS_AUX_ROSC,
  XOSC = hw::clocks::CTRL::SYS_AUX_XOSC,
  GPIN0 = hw::clocks::CTRL::SYS_AUX_GPIN0,
  GPIN1 = hw::clocks::CTRL::SYS_AUX_GPIN1,
};
/**
 * @brief
 */
enum class systemSources : std::uint32_t {
  REF = hw::clocks::CTRL::SYS_SRC_CLK_REF,
  AUX = hw::clocks::CTRL::SYS_SRC_AUX,
};
/**
 * @brief
 */
enum class peripheralSources : std::uint32_t {
  SYS = hw::clocks::CTRL::PERI_AUX_CLK_SYS,
  PLL_SYS = hw::clocks::CTRL::PERI_AUX_PLL_SYS,
  PLL_USB = hw::clocks::CTRL::PERI_AUX_PLL_USB,
  ROSC = hw::clocks::CTRL::PERI_AUX_ROSC,
  XOSC = hw::clocks::CTRL::PERI_AUX_XOSC,
  GPIN0 = hw::clocks::CTRL::PERI_AUX_GPIN0,
  GPIN1 = hw::clocks::CTRL::PERI_AUX_GPIN1,
};
/**
 * @brief
 */
enum class usbSources : std::uint32_t {
  PLL_USB = hw::clocks::CTRL::USB_AUX_PLL_USB,
  PLL_SYS = hw::clocks::CTRL::USB_AUX_PLL_SYS,
  ROSC = hw::clocks::CTRL::USB_AUX_ROSC,
  XOSC = hw::clocks::CTRL::USB_AUX_XOSC,
  GPIN0 = hw::clocks::CTRL::USB_AUX_GPIN0,
  GPIN1 = hw::clocks::CTRL::USB_AUX_GPIN1,
};
/**
 * @brief
 */
enum class adcSources : std::uint32_t {
  PLL_USB = hw::clocks::CTRL::ADC_AUX_PLL_USB,
  PLL_SYS = hw::clocks::CTRL::ADC_AUX_PLL_SYS,
  ROSC = hw::clocks::CTRL::ADC_AUX_ROSC,
  XOSC = hw::clocks::CTRL::ADC_AUX_XOSC,
  GPIN0 = hw::clocks::CTRL::ADC_AUX_GPIN0,
  GPIN1 = hw::clocks::CTRL::ADC_AUX_GPIN1,
};
/**
 * @brief
 */
enum class rtcSources : std::uint32_t {
  PLL_USB = hw::clocks::CTRL::RTC_AUX_PLL_USB,
  PLL_SYS = hw::clocks::CTRL::RTC_AUX_PLL_SYS,
  ROSC = hw::clocks::CTRL::RTC_AUX_ROSC,
  XOSC = hw::clocks::CTRL::RTC_AUX_XOSC,
  GPIN0 = hw::clocks::CTRL::RTC_AUX_GPIN0,
  GPIN1 = hw::clocks::CTRL::RTC_AUX_GPIN1,
};
/**
 * @brief
 * @tparam clocksAddress_
 */
template <libMcuLL::clocksBaseAddress const& clocksAddress_>
struct clocks : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief Setup gpio clock output
   * @param generator GPIO output clock source to set
   * @param source clock source to output
   * @param divisor divisor value, 0 means max division
   * @param fraction fractional value
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void setup(gpoutGenerators generator, gpoutSources source, std::uint32_t divisor, std::uint32_t fraction,
                       std::uint32_t delay) {
    std::uint32_t index = static_cast<std::uint32_t>(generator);
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    switchAux(index, auxSource, divisor, fraction, delay);
  }
  /**
   * @brief
   *
   * @param source
   * @param divisor
   */
  constexpr void setup(referenceAuxSources source, std::uint32_t divisor, std::uint32_t delay) {
    std::uint32_t index = hw::clocks::clockIndex::REF;
    std::uint32_t divisorRegister = hw::clocks::DIV::INT(divisor);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > clocksPeripheral()->CLK[index].DIV)
      clocksPeripheral()->CLK[index].DIV = divisorRegister;
    switchSrc(index, hw::clocks::CTRL::REF_SRC_ROSC);  // set clock source to safe default
    clocksPeripheral()->CLK[index].CTRL =
      (clocksPeripheral()->CLK[index].CTRL & ~hw::clocks::CTRL::AUXSRC_MASK) | static_cast<std::uint32_t>(source);
    libMcu::sw::delay(delay);
    switchSrc(index, hw::clocks::CTRL::REF_SRC_AUX);
    clocksPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief switch reference clock glitchless mux
   * @param source clock source to switch to
   * @param divisor divisor
   */
  constexpr void setup(referenceSources source, std::uint32_t divisor) {
    std::uint32_t index = hw::clocks::clockIndex::REF;
    std::uint32_t divisorRegister = hw::clocks::DIV::INT(divisor);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > clocksPeripheral()->CLK[index].DIV)
      clocksPeripheral()->CLK[index].DIV = divisorRegister;
    switchSrc(index, static_cast<std::uint32_t>(source));
    clocksPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief
   * @param source
   * @param divisor
   * @param fraction
   * @param delay
   */
  constexpr void setup(systemAuxSources source, std::uint32_t divisor, std::uint32_t fraction, std::uint32_t delay) {
    std::uint32_t index = hw::clocks::clockIndex::SYS;
    std::uint32_t divisorRegister = hw::clocks::DIV::INT(divisor) | hw::clocks::DIV::FRAC(fraction);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > clocksPeripheral()->CLK[index].DIV)
      clocksPeripheral()->CLK[index].DIV = divisorRegister;
    switchSrc(index, hw::clocks::CTRL::SYS_SRC_CLK_REF);  // set clock source to safe default
    clocksPeripheral()->CLK[index].CTRL =
      (clocksPeripheral()->CLK[index].CTRL & ~hw::clocks::CTRL::AUXSRC_MASK) | static_cast<std::uint32_t>(source);
    libMcu::sw::delay(delay);
    switchSrc(index, hw::clocks::CTRL::SYS_SRC_AUX);
    clocksPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief
   * @param source
   * @param divisor
   * @param fraction
   * @param delay
   */
  constexpr void setup(systemSources source, std::uint32_t divisor, std::uint32_t fraction) {
    std::uint32_t index = hw::clocks::clockIndex::SYS;
    std::uint32_t divisorRegister = hw::clocks::DIV::INT(divisor) | hw::clocks::DIV::FRAC(fraction);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > clocksPeripheral()->CLK[index].DIV)
      clocksPeripheral()->CLK[index].DIV = divisorRegister;
    switchSrc(index, static_cast<std::uint32_t>(source));
    clocksPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief Setup peripheral clock generator
   * @param source clock source to connect to the peripheral clock generator
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void setup(peripheralSources source, std::uint32_t delay) {
    std::uint32_t index = hw::clocks::clockIndex::PERI;
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    switchAux(index, auxSource, 0u, 0u, delay);
  }
  /**
   * @brief Setup USB clock generator
   * @param source clock source to connect to the USB clock generator
   * @param divisor clock divisor
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void setup(usbSources source, std::uint32_t divisor, std::uint32_t delay) {
    std::uint32_t index = hw::clocks::clockIndex::USB;
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    switchAux(index, auxSource, divisor, 0u, delay);
  }
  /**
   * @brief Setup ADC clock generator
   * @param source clock source to connect to the ADC clock generator
   * @param divisor clock divisor
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void setup(adcSources source, std::uint32_t divisor, std::uint32_t delay) {
    std::uint32_t index = hw::clocks::clockIndex::ADC;
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    switchAux(index, auxSource, divisor, 0u, delay);
  }
  /**
   * @brief Setup RTC clock generator
   * @param source clock source to connect to the RTC clock generator
   * @param divisor clock divisor
   * @param fraction fractional clock divisor
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void setup(rtcSources source, std::uint32_t divisor, std::uint32_t fraction, std::uint32_t delay) {
    std::uint32_t index = hw::clocks::clockIndex::RTC;
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    switchAux(index, auxSource, divisor, fraction, delay);
  }

  /**
   * @brief Clear clock resusitator
   */
  constexpr void clearResusitator() {
    clocksPeripheralSet()->CLK_SYS_RESUS_CTRL = hw::clocks::CLK_SYS_RESUS_CTRL::CLEAR;
  }
  /**
   * @brief
   *
   * @param index
   * @param source
   */
  constexpr void switchSrc(std::uint32_t index, std::uint32_t source) {
    clocksPeripheral()->CLK[index].CTRL = (clocksPeripheral()->CLK[index].CTRL & ~hw::clocks::CTRL::SRCSRC_MASK) | source;
    while (clocksPeripheral()->CLK[index].SELECTED == 0) {
      libMcu::sw::nop();
    }
  }
  /**
   * @brief switch aux mux from clock source
   * @param index
   * @param source
   * @param divisor
   * @param fraction
   * @param delay
   */
  constexpr void switchAux(std::uint32_t index, std::uint32_t source, std::uint32_t divisor, std::uint32_t fraction,
                           std::uint32_t delay) {
    std::uint32_t divisorRegister = hw::clocks::DIV::INT(divisor) | hw::clocks::DIV::FRAC(fraction);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > clocksPeripheral()->CLK[index].DIV)
      clocksPeripheral()->CLK[index].DIV = divisorRegister;
    clocksPeripheralClear()->CLK[index].CTRL = hw::clocks::CTRL::ENABLE;
    libMcu::sw::delay(delay);
    clocksPeripheral()->CLK[index].CTRL = (clocksPeripheral()->CLK[index].CTRL & ~hw::clocks::CTRL::AUXSRC_MASK) | source;
    clocksPeripheralSet()->CLK[index].CTRL = hw::clocks::CTRL::ENABLE;
    clocksPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hw::clocks::peripheral* clocksPeripheral() {
    return reinterpret_cast<hw::clocks::peripheral*>(clocksAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hw::clocks::peripheral* clocksPeripheralSet() {
    return reinterpret_cast<hw::clocks::peripheral*>(clocksAddress + hw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hw::clocks::peripheral* clocksPeripheralClear() {
    return reinterpret_cast<hw::clocks::peripheral*>(clocksAddress + hw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hw::clocks::peripheral* clocksPeripheralXor() {
    return reinterpret_cast<hw::clocks::peripheral*>(clocksAddress + hw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcuLL::hwAddressType clocksAddress = clocksAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::clocks
#endif