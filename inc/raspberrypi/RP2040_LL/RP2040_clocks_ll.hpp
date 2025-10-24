/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_clocks_ll.hpp
 * @brief low level interface for the RP2040 clocks
 */
#ifndef RP2040_CLOCKS_LL_HPP
#define RP2040_CLOCKS_LL_HPP

namespace libmcull::clocks {
namespace hardware = libmcuhw::clocks;

/**
 * @brief available clock generators
 */
enum class GpoutGenerators : std::uint32_t {
  Gpout0 = hardware::ClockIndices::Gpout0, /*!< GPIO mux clock 0 */
  Gpout1 = hardware::ClockIndices::Gpout1, /*!< GPIO mux clock 1 */
  Gpout2 = hardware::ClockIndices::Gpout2, /*!< GPIO mux clock 2 */
  Gpout3 = hardware::ClockIndices::Gpout3, /*!< GPIO mux clock 3 */
};
/**
 * @brief available clock sources for gpout clock generators
 */
enum class GpoutSources : std::uint32_t {
  PllSys = hardware::CTRL::GPOUT_AUX_PLL_SYS,
  Gpin0 = hardware::CTRL::GPOUT_AUX_GPIN0,
  Gpin1 = hardware::CTRL::GPOUT_AUX_GPIN1,
  PllUsb = hardware::CTRL::GPOUT_AUX_PLL_USB,
  Rosc = hardware::CTRL::GPOUT_AUX_ROSC,
  Xosc = hardware::CTRL::GPOUT_AUX_XOSC,
  Sys = hardware::CTRL::GPOUT_AUX_CLK_SYS,
  Usb = hardware::CTRL::GPOUT_AUX_CLK_USB,
  Adc = hardware::CTRL::GPOUT_AUX_CLK_ADC,
  Rtc = hardware::CTRL::GPOUT_AUX_CLK_RTC,
  Ref = hardware::CTRL::GPOUT_AUX_CLK_REF,
};
/**
 * @brief
 */
enum class ReferenceAuxSources : std::uint32_t {
  PllUsb = hardware::CTRL::REF_AUX_PLL_USB,
  Gpin0 = hardware::CTRL::REF_AUX_GPIN0,
  Gpin1 = hardware::CTRL::REF_AUX_GPIN1,
};
/**
 * @brief
 */
enum class ReferenceSources : std::uint32_t {
  Rosc = hardware::CTRL::REF_SRC_ROSC,
  Aux = hardware::CTRL::REF_SRC_AUX,
  Xosc = hardware::CTRL::REF_SRC_XOSC,
};
/**
 * @brief
 */
enum class SystemAuxSources : std::uint32_t {
  PllSys = hardware::CTRL::SYS_AUX_PLL_SYS,
  PllUsb = hardware::CTRL::SYS_AUX_PLL_USB,
  Rosc = hardware::CTRL::SYS_AUX_ROSC,
  Xosc = hardware::CTRL::SYS_AUX_XOSC,
  Gpin0 = hardware::CTRL::SYS_AUX_GPIN0,
  Gpin1 = hardware::CTRL::SYS_AUX_GPIN1,
};
/**
 * @brief
 */
enum class SystemSources : std::uint32_t {
  Ref = hardware::CTRL::SYS_SRC_CLK_REF,
  Aux = hardware::CTRL::SYS_SRC_AUX,
};
/**
 * @brief
 */
enum class PeripheralSources : std::uint32_t {
  Sys = hardware::CTRL::PERI_AUX_CLK_SYS,
  PllSys = hardware::CTRL::PERI_AUX_PLL_SYS,
  PllUsb = hardware::CTRL::PERI_AUX_PLL_USB,
  Rosc = hardware::CTRL::PERI_AUX_ROSC,
  Xosc = hardware::CTRL::PERI_AUX_XOSC,
  Gpin0 = hardware::CTRL::PERI_AUX_GPIN0,
  Gpin1 = hardware::CTRL::PERI_AUX_GPIN1,
};
/**
 * @brief
 */
enum class UsbSources : std::uint32_t {
  PllUsb = hardware::CTRL::USB_AUX_PLL_USB,
  PllSys = hardware::CTRL::USB_AUX_PLL_SYS,
  Rosc = hardware::CTRL::USB_AUX_ROSC,
  Xosc = hardware::CTRL::USB_AUX_XOSC,
  Gpin0 = hardware::CTRL::USB_AUX_GPIN0,
  Gpin1 = hardware::CTRL::USB_AUX_GPIN1,
};
/**
 * @brief
 */
enum class AdcSources : std::uint32_t {
  PllUsb = hardware::CTRL::ADC_AUX_PLL_USB,
  PllSys = hardware::CTRL::ADC_AUX_PLL_SYS,
  Rosc = hardware::CTRL::ADC_AUX_ROSC,
  Xosc = hardware::CTRL::ADC_AUX_XOSC,
  Gpin0 = hardware::CTRL::ADC_AUX_GPIN0,
  Gpin1 = hardware::CTRL::ADC_AUX_GPIN1,
};
/**
 * @brief
 */
enum class RtcSources : std::uint32_t {
  PllUsb = hardware::CTRL::RTC_AUX_PLL_USB,
  PllSys = hardware::CTRL::RTC_AUX_PLL_SYS,
  Rosc = hardware::CTRL::RTC_AUX_ROSC,
  Xosc = hardware::CTRL::RTC_AUX_XOSC,
  Gpin0 = hardware::CTRL::RTC_AUX_GPIN0,
  Gpin1 = hardware::CTRL::RTC_AUX_GPIN1,
};
/**
 * @brief
 * @tparam clocks_address
 */
template <libmcu::ClocksBaseAddress const& clocks_address>
struct Clocks : libmcull::LowLevelBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief Setup gpio clock output
   * @param generator GPIO output clock source to set
   * @param source clock source to output
   * @param divisor divisor value, 0 means max division
   * @param fraction fractional value
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void Setup(GpoutGenerators generator, GpoutSources source, std::uint32_t divisor, std::uint32_t fraction,
                       std::uint32_t delay) {
    std::uint32_t index = static_cast<std::uint32_t>(generator);
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    SwitchAux(index, auxSource, divisor, fraction, delay);
  }
  /**
   * @brief
   * @param source
   * @param divisor
   */
  constexpr void Setup(ReferenceAuxSources source, std::uint32_t divisor, std::uint32_t delay) {
    std::uint32_t index = hardware::ClockIndices::Ref;
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > GetPeripheral()->CLK[index].DIV)
      GetPeripheral()->CLK[index].DIV = divisorRegister;
    SwitchSrc(index, hardware::CTRL::REF_SRC_ROSC);  // set clock source to safe default
    GetPeripheral()->CLK[index].CTRL =
      (GetPeripheral()->CLK[index].CTRL & ~hardware::CTRL::AUXSRC_MASK) | static_cast<std::uint32_t>(source);
    libmcu::Delay(delay);
    SwitchSrc(index, hardware::CTRL::REF_SRC_AUX);
    GetPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief switch reference clock glitchless mux
   * @param source clock source to switch to
   * @param divisor divisor
   */
  constexpr void Setup(ReferenceSources source, std::uint32_t divisor) {
    std::uint32_t index = hardware::ClockIndices::Ref;
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > GetPeripheral()->CLK[index].DIV)
      GetPeripheral()->CLK[index].DIV = divisorRegister;
    SwitchSrc(index, static_cast<std::uint32_t>(source));
    GetPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief
   * @param source
   * @param divisor
   * @param fraction
   * @param delay
   */
  constexpr void Setup(SystemAuxSources source, std::uint32_t divisor, std::uint32_t fraction, std::uint32_t delay) {
    std::uint32_t index = hardware::ClockIndices::Sys;
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor) | hardware::DIV::FRAC(fraction);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > GetPeripheral()->CLK[index].DIV)
      GetPeripheral()->CLK[index].DIV = divisorRegister;
    SwitchSrc(index, hardware::CTRL::SYS_SRC_CLK_REF);  // set clock source to safe default
    GetPeripheral()->CLK[index].CTRL =
      (GetPeripheral()->CLK[index].CTRL & ~hardware::CTRL::AUXSRC_MASK) | static_cast<std::uint32_t>(source);
    libmcu::Delay(delay);
    SwitchSrc(index, hardware::CTRL::SYS_SRC_AUX);
    GetPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief
   * @param source
   * @param divisor
   * @param fraction
   * @param delay
   */
  constexpr void Setup(SystemSources source, std::uint32_t divisor, std::uint32_t fraction) {
    std::uint32_t index = hardware::ClockIndices::Sys;
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor) | hardware::DIV::FRAC(fraction);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > GetPeripheral()->CLK[index].DIV)
      GetPeripheral()->CLK[index].DIV = divisorRegister;
    SwitchSrc(index, static_cast<std::uint32_t>(source));
    GetPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief Setup peripheral clock generator
   * @param source clock source to connect to the peripheral clock generator
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void Setup(PeripheralSources source, std::uint32_t delay) {
    std::uint32_t index = hardware::ClockIndices::Peri;
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    SwitchAux(index, auxSource, 0u, 0u, delay);
  }
  /**
   * @brief Setup USB clock generator
   * @param source clock source to connect to the USB clock generator
   * @param divisor clock divisor
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void Setup(UsbSources source, std::uint32_t divisor, std::uint32_t delay) {
    std::uint32_t index = hardware::ClockIndices::Usb;
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    SwitchAux(index, auxSource, divisor, 0u, delay);
  }
  /**
   * @brief Setup ADC clock generator
   * @param source clock source to connect to the ADC clock generator
   * @param divisor clock divisor
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void Setup(AdcSources source, std::uint32_t divisor, std::uint32_t delay) {
    std::uint32_t index = hardware::ClockIndices::Adc;
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    SwitchAux(index, auxSource, divisor, 0u, delay);
  }
  /**
   * @brief Setup RTC clock generator
   * @param source clock source to connect to the RTC clock generator
   * @param divisor clock divisor
   * @param fraction fractional clock divisor
   * @param delay delay of 3 input clocks for disable
   */
  constexpr void Setup(RtcSources source, std::uint32_t divisor, std::uint32_t fraction, std::uint32_t delay) {
    std::uint32_t index = hardware::ClockIndices::Rtc;
    std::uint32_t auxSource = static_cast<std::uint32_t>(source);
    SwitchAux(index, auxSource, divisor, fraction, delay);
  }

  /**
   * @brief Clear clock resusitator
   */
  constexpr void ClearResusitator() {
    GetPeripheralSet()->CLK_SYS_RESUS_CTRL = hardware::CLK_SYS_RESUS_CTRL::CLEAR;
  }
  /**
   * @brief
   * @param index
   * @param source
   */
  constexpr void SwitchSrc(std::uint32_t index, std::uint32_t source) {
    GetPeripheral()->CLK[index].CTRL = (GetPeripheral()->CLK[index].CTRL & ~hardware::CTRL::SRCSRC_MASK) | source;
    while (GetPeripheral()->CLK[index].SELECTED == 0) {
      libmcull::nop();
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
  constexpr void SwitchAux(std::uint32_t index, std::uint32_t source, std::uint32_t divisor, std::uint32_t fraction,
                           std::uint32_t delay) {
    std::uint32_t divisorRegister = hardware::DIV::INT(divisor) | hardware::DIV::FRAC(fraction);
    // set divisor if divisor is larger to prevent overspeed (taken from API description)
    if (divisorRegister > GetPeripheral()->CLK[index].DIV)
      GetPeripheral()->CLK[index].DIV = divisorRegister;
    GetPeripheralClear()->CLK[index].CTRL = hardware::CTRL::ENABLE;
    libmcu::Delay(delay);
    GetPeripheral()->CLK[index].CTRL = (GetPeripheral()->CLK[index].CTRL & ~hardware::CTRL::AUXSRC_MASK) | source;
    GetPeripheralSet()->CLK[index].CTRL = hardware::CTRL::ENABLE;
    GetPeripheral()->CLK[index].DIV = divisorRegister;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Clocks* GetPeripheral() {
    return reinterpret_cast<hardware::Clocks*>(clocks_address_ + libmcuhw::PeripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::Clocks* GetPeripheralSet() {
    return reinterpret_cast<hardware::Clocks*>(clocks_address_ + libmcuhw::PeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::Clocks* GetPeripheralClear() {
    return reinterpret_cast<hardware::Clocks*>(clocks_address_ + libmcuhw::PeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::Clocks* GetPeripheralXor() {
    return reinterpret_cast<hardware::Clocks*>(clocks_address_ + libmcuhw::PeripheralOffsetXor);
  }

 private:
  static constexpr libmcu::HwAddressType clocks_address_ = clocks_address; /*!< peripheral address */
};
}  // namespace libmcull::clocks
#endif