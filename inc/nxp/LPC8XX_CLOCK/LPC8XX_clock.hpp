/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC8XX_clock.hpp
 * \brief TODO
 */
#ifndef LPC8XX_CLOCK_HPP
#define LPC8XX_CLOCK_HPP

namespace libMcuHw::clock {

constexpr inline std::uint32_t systemPllMinVcoFreq{156'000'000}; /**< minimum PLL VCO frequency */
constexpr inline std::uint32_t systemPllMaxVcoFreq{320'000'000}; /**< maximum PLL VCO frequency */
constexpr inline std::uint32_t mainClockMaxFreq{100'000'000};    /**< main clock max frequency */
constexpr inline std::uint32_t froDefaultClockFreq{12'000'000};  /**< IRC clock frequency */

consteval std::uint32_t findSystemPllPsel(uint32_t outFreq) {
  if (outFreq > (systemPllMinVcoFreq >> 1U))
    return libMcuHw::syscon::SYSPLLCTRL::PSEL_DIV2;
  else if (outFreq > (systemPllMinVcoFreq >> 2U))
    return libMcuHw::syscon::SYSPLLCTRL::PSEL_DIV4;
  else if (outFreq > (systemPllMinVcoFreq >> 3U))
    return libMcuHw::syscon::SYSPLLCTRL::PSEL_DIV8;
  else
    return libMcuHw::syscon::SYSPLLCTRL::PSEL_DIV16;
}

consteval uint32_t findSystemPllMsel(uint32_t inFreq, uint32_t outFreq) {
  return (outFreq / inFreq) - 1;
}

consteval uint32_t findClockFrequency(uint32_t inFreq, uint32_t cpuFreq) {
  return libMcu::findLcm(inFreq, cpuFreq, mainClockMaxFreq);
}
}  // namespace libMcuHw::clock

#endif