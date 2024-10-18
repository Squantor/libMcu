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

namespace libMcuHw::clock {
namespace sysconLL = libMcuLL::syscon;

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
    sysconPeripheral.setSystemPllControl(findSystemPllMsel(config.inputFreq, config.mainFreq),
                                         static_cast<libMcuLL::syscon::pllPostDivider>(findSystemPllPsel(config.mainFreq)));
    sysconPeripheral.powerPeripherals(libMcuLL::syscon::powerOptions::SYSPLL);
    while (sysconPeripheral.getSystemPllStatus() == 0)
      ;
    sysconPeripheral.setMainClockDivider(config.mainFreq / config.systemFreq);
    sysconPeripheral.selectMainPllClock(libMcuLL::syscon::mainClockPllSources::SYSPLL);
  }
}

}  // namespace libMcuHw::clock

#endif