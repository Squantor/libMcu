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
  kGpout0 = hardware::ClockIndices::kGpout0, /*!< GPIO mux clock 0 */
  kGpout1 = hardware::ClockIndices::kGpout1, /*!< GPIO mux clock 1 */
  kGpout2 = hardware::ClockIndices::kGpout2, /*!< GPIO mux clock 2 */
  kGpout3 = hardware::ClockIndices::kGpout3, /*!< GPIO mux clock 3 */
};
/**
 * @brief available clock sources for gpout clock generators
 */
enum class GpoutSources : std::uint32_t {
  kPllSys = hardware::CTRL::GPOUT_AUX_PLL_SYS,
  kGpin0 = hardware::CTRL::GPOUT_AUX_GPIN0,
  kGpin1 = hardware::CTRL::GPOUT_AUX_GPIN1,
  kPllUsb = hardware::CTRL::GPOUT_AUX_PLL_USB,
  kRosc = hardware::CTRL::GPOUT_AUX_ROSC,
  kXosc = hardware::CTRL::GPOUT_AUX_XOSC,
  kSys = hardware::CTRL::GPOUT_AUX_CLK_SYS,
  kUsb = hardware::CTRL::GPOUT_AUX_CLK_USB,
  kAdc = hardware::CTRL::GPOUT_AUX_CLK_ADC,
  kRtc = hardware::CTRL::GPOUT_AUX_CLK_RTC,
  kRef = hardware::CTRL::GPOUT_AUX_CLK_REF,
};
/**
 * @brief
 */
enum class ReferenceAuxSources : std::uint32_t {
  kPllUsb = hardware::CTRL::REF_AUX_PLL_USB,
  kGpin0 = hardware::CTRL::REF_AUX_GPIN0,
  kGpin1 = hardware::CTRL::REF_AUX_GPIN1,
};
/**
 * @brief
 */
enum class ReferenceSources : std::uint32_t {
  kRosc = hardware::CTRL::REF_SRC_ROSC,
  kAux = hardware::CTRL::REF_SRC_AUX,
  kXosc = hardware::CTRL::REF_SRC_XOSC,
};
/**
 * @brief
 */
enum class SystemAuxSources : std::uint32_t {
  kPllSys = hardware::CTRL::SYS_AUX_PLL_SYS,
  kPllUsb = hardware::CTRL::SYS_AUX_PLL_USB,
  kRosc = hardware::CTRL::SYS_AUX_ROSC,
  kXosc = hardware::CTRL::SYS_AUX_XOSC,
  kGpin0 = hardware::CTRL::SYS_AUX_GPIN0,
  kGpin1 = hardware::CTRL::SYS_AUX_GPIN1,
};
/**
 * @brief
 */
enum class SystemSources : std::uint32_t {
  kRef = hardware::CTRL::SYS_SRC_CLK_REF,
  kAux = hardware::CTRL::SYS_SRC_AUX,
};
/**
 * @brief
 */
enum class PeripheralSources : std::uint32_t {
  kSys = hardware::CTRL::PERI_AUX_CLK_SYS,
  kPllSys = hardware::CTRL::PERI_AUX_PLL_SYS,
  kPllUsb = hardware::CTRL::PERI_AUX_PLL_USB,
  kRosc = hardware::CTRL::PERI_AUX_ROSC,
  kXosc = hardware::CTRL::PERI_AUX_XOSC,
  kGpin0 = hardware::CTRL::PERI_AUX_GPIN0,
  kGpin1 = hardware::CTRL::PERI_AUX_GPIN1,
};
/**
 * @brief
 */
enum class UsbSources : std::uint32_t {
  kPllUsb = hardware::CTRL::USB_AUX_PLL_USB,
  kPllSys = hardware::CTRL::USB_AUX_PLL_SYS,
  kRosc = hardware::CTRL::USB_AUX_ROSC,
  kXosc = hardware::CTRL::USB_AUX_XOSC,
  kGpin0 = hardware::CTRL::USB_AUX_GPIN0,
  kGpin1 = hardware::CTRL::USB_AUX_GPIN1,
};
/**
 * @brief
 */
enum class AdcSources : std::uint32_t {
  kPllUsb = hardware::CTRL::ADC_AUX_PLL_USB,
  kPllSys = hardware::CTRL::ADC_AUX_PLL_SYS,
  kRosc = hardware::CTRL::ADC_AUX_ROSC,
  kXosc = hardware::CTRL::ADC_AUX_XOSC,
  kGpin0 = hardware::CTRL::ADC_AUX_GPIN0,
  kGpin1 = hardware::CTRL::ADC_AUX_GPIN1,
};
/**
 * @brief
 */
enum class RtcSources : std::uint32_t {
  kPllUsb = hardware::CTRL::RTC_AUX_PLL_USB,
  kPllSys = hardware::CTRL::RTC_AUX_PLL_SYS,
  kRosc = hardware::CTRL::RTC_AUX_ROSC,
  kXosc = hardware::CTRL::RTC_AUX_XOSC,
  kGpin0 = hardware::CTRL::RTC_AUX_GPIN0,
  kGpin1 = hardware::CTRL::RTC_AUX_GPIN1,
};
/**
 * @brief
 * @tparam clocks_address
 */
template <libmcu::ClocksBaseAddress const& clocks_address>
struct Clocks : libmcull::PeripheralBase {
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
    std::uint32_t index = hardware::ClockIndices::kRef;
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
    std::uint32_t index = hardware::ClockIndices::kRef;
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
    std::uint32_t index = hardware::ClockIndices::kSys;
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
    std::uint32_t index = hardware::ClockIndices::kSys;
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
    std::uint32_t index = hardware::ClockIndices::kPeri;
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
    std::uint32_t index = hardware::ClockIndices::kUsb;
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
    std::uint32_t index = hardware::ClockIndices::kAdc;
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
    std::uint32_t index = hardware::ClockIndices::kRtc;
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
    return reinterpret_cast<hardware::Clocks*>(clocks_address_ + libmcuhw::kPeripheralOffsetNormal);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::Clocks* GetPeripheralSet() {
    return reinterpret_cast<hardware::Clocks*>(clocks_address_ + libmcuhw::kPeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::Clocks* GetPeripheralClear() {
    return reinterpret_cast<hardware::Clocks*>(clocks_address_ + libmcuhw::kPeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::Clocks* GetPeripheralXor() {
    return reinterpret_cast<hardware::Clocks*>(clocks_address_ + libmcuhw::kPeripheralOffsetXor);
  }

 private:
  static constexpr libmcu::HwAddressType clocks_address_ = clocks_address; /*!< peripheral address */
};
}  // namespace libmcull::clocks
#endif