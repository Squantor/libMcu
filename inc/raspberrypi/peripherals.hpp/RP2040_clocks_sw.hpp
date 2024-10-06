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

namespace libMcuLL::clocks {
namespace hardware = libMcuHw::clocks;

/**
 * @brief available clock generators
 */
enum class gpoutGenerators : std::uint32_t {
  GPOUT0 = hardware::clockIndex::GPOUT0, /**< GPIO mux clock 0 */
  GPOUT1 = hardware::clockIndex::GPOUT1, /**< GPIO mux clock 1 */
  GPOUT2 = hardware::clockIndex::GPOUT2, /**< GPIO mux clock 2 */
  GPOUT3 = hardware::clockIndex::GPOUT3, /**< GPIO mux clock 3 */
};
/**
 * @brief available clock sources for gpout clock generators
 */
enum class gpoutSources : std::uint32_t {
  PLL_SYS = hardware::CTRL::GPOUT_AUX_PLL_SYS,
  GPIN0 = hardware::CTRL::GPOUT_AUX_GPIN0,
  GPIN1 = hardware::CTRL::GPOUT_AUX_GPIN1,
  PLL_USB = hardware::CTRL::GPOUT_AUX_PLL_USB,
  ROSC = hardware::CTRL::GPOUT_AUX_ROSC,
  XOSC = hardware::CTRL::GPOUT_AUX_XOSC,
  SYS = hardware::CTRL::GPOUT_AUX_CLK_SYS,
  USB = hardware::CTRL::GPOUT_AUX_CLK_USB,
  ADC = hardware::CTRL::GPOUT_AUX_CLK_ADC,
  RTC = hardware::CTRL::GPOUT_AUX_CLK_RTC,
  REF = hardware::CTRL::GPOUT_AUX_CLK_REF,
};
/**
 * @brief
 */
enum class referenceAuxSources : std::uint32_t {
  PLL_USB = hardware::CTRL::REF_AUX_PLL_USB,
  GPIN0 = hardware::CTRL::REF_AUX_GPIN0,
  GPIN1 = hardware::CTRL::REF_AUX_GPIN1,
};
/**
 * @brief
 */
enum class referenceSources : std::uint32_t {
  ROSC = hardware::CTRL::REF_SRC_ROSC,
  AUX = hardware::CTRL::REF_SRC_AUX,
  XOSC = hardware::CTRL::REF_SRC_XOSC,
};
/**
 * @brief
 */
enum class systemAuxSources : std::uint32_t {
  PLL_SYS = hardware::CTRL::SYS_AUX_PLL_SYS,
  PLL_USB = hardware::CTRL::SYS_AUX_PLL_USB,
  ROSC = hardware::CTRL::SYS_AUX_ROSC,
  XOSC = hardware::CTRL::SYS_AUX_XOSC,
  GPIN0 = hardware::CTRL::SYS_AUX_GPIN0,
  GPIN1 = hardware::CTRL::SYS_AUX_GPIN1,
};
/**
 * @brief
 */
enum class systemSources : std::uint32_t {
  REF = hardware::CTRL::SYS_SRC_CLK_REF,
  AUX = hardware::CTRL::SYS_SRC_AUX,
};
/**
 * @brief
 */
enum class peripheralSources : std::uint32_t {
  SYS = hardware::CTRL::PERI_AUX_CLK_SYS,
  PLL_SYS = hardware::CTRL::PERI_AUX_PLL_SYS,
  PLL_USB = hardware::CTRL::PERI_AUX_PLL_USB,
  ROSC = hardware::CTRL::PERI_AUX_ROSC,
  XOSC = hardware::CTRL::PERI_AUX_XOSC,
  GPIN0 = hardware::CTRL::PERI_AUX_GPIN0,
  GPIN1 = hardware::CTRL::PERI_AUX_GPIN1,
};
/**
 * @brief
 */
enum class usbSources : std::uint32_t {
  PLL_USB = hardware::CTRL::USB_AUX_PLL_USB,
  PLL_SYS = hardware::CTRL::USB_AUX_PLL_SYS,
  ROSC = hardware::CTRL::USB_AUX_ROSC,
  XOSC = hardware::CTRL::USB_AUX_XOSC,
  GPIN0 = hardware::CTRL::USB_AUX_GPIN0,
  GPIN1 = hardware::CTRL::USB_AUX_GPIN1,
};
/**
 * @brief
 */
enum class adcSources : std::uint32_t {
  PLL_USB = hardware::CTRL::ADC_AUX_PLL_USB,
  PLL_SYS = hardware::CTRL::ADC_AUX_PLL_SYS,
  ROSC = hardware::CTRL::ADC_AUX_ROSC,
  XOSC = hardware::CTRL::ADC_AUX_XOSC,
  GPIN0 = hardware::CTRL::ADC_AUX_GPIN0,
  GPIN1 = hardware::CTRL::ADC_AUX_GPIN1,
};
/**
 * @brief
 */
enum class rtcSources : std::uint32_t {
  PLL_USB = hardware::CTRL::RTC_AUX_PLL_USB,
  PLL_SYS = hardware::CTRL::RTC_AUX_PLL_SYS,
  ROSC = hardware::CTRL::RTC_AUX_ROSC,
  XOSC = hardware::CTRL::RTC_AUX_XOSC,
  GPIN0 = hardware::CTRL::RTC_AUX_GPIN0,
  GPIN1 = hardware::CTRL::RTC_AUX_GPIN1,
};
/**
 * @brief
 * @tparam clocksAddress_
 */
template <libMcu::clocksBaseAddress const& clocksAddress_>
struct clocks : libMcu::peripheralBase {
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
    std::uint32_t index = hardware::clockIndex::REF;
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > clocksPeripheral()->CLK[index].DIV)
      clocksPeripheral()->CLK[index].DIV = divisorRegister;
    switchSrc(index, hardware::CTRL::REF_SRC_ROSC);  // set clock source to safe default
    clocksPeripheral()->CLK[index].CTRL =
      (clocksPeripheral()->CLK[index].CTRL & ~hardware::CTRL::AUXSRC_MASK) | static_cast<std::uint32_t>(source);
    libMcuLL::delay(delay);
    switchSrc(index, hardware::CTRL::REF_SRC_AUX);
    clocksPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief switch reference clock glitchless mux
   * @param source clock source to switch to
   * @param divisor divisor
   */
  constexpr void setup(referenceSources source, std::uint32_t divisor) {
    std::uint32_t index = hardware::clockIndex::REF;
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor);
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
    std::uint32_t index = hardware::clockIndex::SYS;
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor) | hardware::DIV::FRAC(fraction);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > clocksPeripheral()->CLK[index].DIV)
      clocksPeripheral()->CLK[index].DIV = divisorRegister;
    switchSrc(index, hardware::CTRL::SYS_SRC_CLK_REF);  // set clock source to safe default
    clocksPeripheral()->CLK[index].CTRL =
      (clocksPeripheral()->CLK[index].CTRL & ~hardware::CTRL::AUXSRC_MASK) | static_cast<std::uint32_t>(source);
    libMcuLL::delay(delay);
    switchSrc(index, hardware::CTRL::SYS_SRC_AUX);
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
    std::uint32_t index = hardware::clockIndex::SYS;
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor) | hardware::DIV::FRAC(fraction);
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
    std::uint32_t index = hardware::clockIndex::PERI;
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
    std::uint32_t index = hardware::clockIndex::USB;
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
    std::uint32_t index = hardware::clockIndex::ADC;
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
    std::uint32_t index = hardware::clockIndex::RTC;
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    switchAux(index, auxSource, divisor, fraction, delay);
  }

  /**
   * @brief Clear clock resusitator
   */
  constexpr void clearResusitator() {
    clocksPeripheralSet()->CLK_SYS_RESUS_CTRL = hardware::CLK_SYS_RESUS_CTRL::CLEAR;
  }
  /**
   * @brief
   *
   * @param index
   * @param source
   */
  constexpr void switchSrc(std::uint32_t index, std::uint32_t source) {
    clocksPeripheral()->CLK[index].CTRL = (clocksPeripheral()->CLK[index].CTRL & ~hardware::CTRL::SRCSRC_MASK) | source;
    while (clocksPeripheral()->CLK[index].SELECTED == 0) {
      libMcuLL::nop();
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
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor) | hardware::DIV::FRAC(fraction);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > clocksPeripheral()->CLK[index].DIV)
      clocksPeripheral()->CLK[index].DIV = divisorRegister;
    clocksPeripheralClear()->CLK[index].CTRL = hardware::CTRL::ENABLE;
    libMcuLL::delay(delay);
    clocksPeripheral()->CLK[index].CTRL = (clocksPeripheral()->CLK[index].CTRL & ~hardware::CTRL::AUXSRC_MASK) | source;
    clocksPeripheralSet()->CLK[index].CTRL = hardware::CTRL::ENABLE;
    clocksPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::peripheral* clocksPeripheral() {
    return reinterpret_cast<hardware::peripheral*>(clocksAddress + libMcuHw::peripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::peripheral* clocksPeripheralSet() {
    return reinterpret_cast<hardware::peripheral*>(clocksAddress + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::peripheral* clocksPeripheralClear() {
    return reinterpret_cast<hardware::peripheral*>(clocksAddress + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::peripheral* clocksPeripheralXor() {
    return reinterpret_cast<hardware::peripheral*>(clocksAddress + libMcuHw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcu::hwAddressType clocksAddress = clocksAddress_; /**< peripheral address */
};
}  // namespace libMcuLL::clocks
#endif