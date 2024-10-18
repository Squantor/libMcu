/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC84X_clock.hpp
 * \brief TODO
 */
#ifndef LPC84X_CLOCK_HPP
#define LPC84X_CLOCK_HPP

#include "LPC8XX_clock.hpp"

namespace libMcuHw::clock {
namespace sysconLL = libMcuLL::syscon;

constexpr inline std::uint32_t systemPllMinVcoFreq{156'000'000}; /**< minimum PLL VCO frequency */
constexpr inline std::uint32_t systemPllMaxVcoFreq{320'000'000}; /**< maximum PLL VCO frequency */
constexpr inline std::uint32_t mainClockMaxFreq{100'000'000};    /**< main clock max frequency */
constexpr inline std::uint32_t froDefaultClockFreq{12'000'000};  /**< IRC clock frequency */

enum class clockInputSources : std::uint8_t {
  FRO,   /**< FRO clock oscillator */
  XTAL,  /**< Crystal clock oscillator */
  CLKIN, /**< Clock input pin */
  // todo WDT
};

consteval libMcuLL::syscon::pllPostDivider findSystemPllPsel(uint32_t outFreq) {
  if (outFreq > (systemPllMinVcoFreq >> 1U))
    return libMcuLL::syscon::pllPostDivider::DIV_2;
  else if (outFreq > (systemPllMinVcoFreq >> 2U))
    return libMcuLL::syscon::pllPostDivider::DIV_4;
  else if (outFreq > (systemPllMinVcoFreq >> 3U))
    return libMcuLL::syscon::pllPostDivider::DIV_8;
  else
    return libMcuLL::syscon::pllPostDivider::DIV_16;
}

consteval uint32_t findSystemPllMsel(uint32_t inFreq, uint32_t outFreq) {
  return (outFreq / inFreq) - 1;
}

consteval uint32_t findClockFrequency(uint32_t inFreq, uint32_t cpuFreq) {
  return libMcu::findLcm(inFreq, cpuFreq, mainClockMaxFreq);
}

template <clockInputSources t_source, std::uint32_t t_inputFreq, std::uint32_t t_systemFreq>
struct clockConfig {
  static_assert(findClockFrequency(t_inputFreq, t_systemFreq) != 0, "Unable to find a clock configuration solution");
  static constexpr clockInputSources source{t_source};
  static constexpr std::uint32_t inputFreq{t_inputFreq};
  static constexpr std::uint32_t mainFreq{findClockFrequency(t_inputFreq, t_systemFreq)};
  static constexpr std::uint32_t systemFreq{t_systemFreq};
  // TODO fractional rate converters?
};

inline clockConfig<clockInputSources::FRO, froDefaultClockFreq, froDefaultClockFreq> const defaultClocks;

template <auto &sysconPeripheral, auto &config = defaultClocks>
constexpr void configureClocks() {
  // check if the wanted config is possible at all?
  static_assert(findClockFrequency(config.inputFreq, config.systemFreq) != 0, "Unable to find a clock configuration solution");
  // setup clock source
  if constexpr (config.source == clockInputSources::FRO) {
    sysconPeripheral.selectMainClock(sysconLL::mainClockSources::FRO);
  } else if constexpr (config.source == clockInputSources::XTAL) {
    if constexpr (config.inputFreq > 15'000'000) {
      sysconPeripheral.setSysOscControl(libMcuHw::syscon::SYSOSCCTRL::NO_BYPASS | libMcuHw::syscon::SYSOSCCTRL::FREQ_15_25MHz);
    } else
      sysconPeripheral.setSysOscControl(libMcuHw::syscon::SYSOSCCTRL::NO_BYPASS | libMcuHw::syscon::SYSOSCCTRL::FREQ_1_20MHz);
    sysconPeripheral.powerPeripherals(libMcuLL::syscon::powerOptions::SYSOSC);
    libMcuLL::delay(3000);
    sysconPeripheral.selectMainClock(sysconLL::mainClockSources::EXT);
  }
  // TODO: WDT clock source
  // TODO: FRO 24 MHZ
  // TODO: with rom functions we can setup the FRO even better
  sysconPeripheral.selectMainPllClock(sysconLL::mainClockPllSources::PRE);
  // can we achieve the frequency we need without using the PLL?
  if constexpr (config.mainFreq == config.inputFreq) {
    sysconPeripheral.setMainClockDivider(config.mainFreq / config.systemFreq);
  } else {
    if constexpr (config.source == clockInputSources::FRO) {
      sysconPeripheral.selectPllClock(libMcuLL::syscon::pllClockSources::FRO);
    } else if constexpr (config.source == clockInputSources::XTAL) {
      sysconPeripheral.selectPllClock(libMcuLL::syscon::pllClockSources::EXT);
    }
    sysconPeripheral.depowerPeripherals(libMcuLL::syscon::powerOptions::SYSPLL);
    sysconPeripheral.setSystemPllControl(findSystemPllMsel(config.inputFreq, config.mainFreq), findSystemPllPsel(config.mainFreq));
    sysconPeripheral.powerPeripherals(libMcuLL::syscon::powerOptions::SYSPLL);
    while (sysconPeripheral.getSystemPllStatus() == 0)
      ;
    sysconPeripheral.setMainClockDivider(config.mainFreq / config.systemFreq);
    sysconPeripheral.selectMainPllClock(libMcuLL::syscon::mainClockPllSources::SYSPLL);
  }
}

}  // namespace libMcuHw::clock

#endif