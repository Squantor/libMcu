/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC8XX_clock.hpp
 * \brief LPC800 series common clock distribution definitions and functions
 */
#ifndef LPC8XX_CLOCK_HPP
#define LPC8XX_CLOCK_HPP

namespace libmcuhw::clock {

constexpr inline std::uint32_t SystemPllMinVcoFreq{156'000'000}; /*!< minimum PLL VCO frequency */
constexpr inline std::uint32_t SystemPllMaxVcoFreq{320'000'000}; /*!< maximum PLL VCO frequency */
constexpr inline std::uint32_t MainClockMaxFreq{100'000'000};    /*!< main clock max frequency */
constexpr inline std::uint32_t FroDefaultClockFreq{12'000'000};  /*!< IRC clock frequency */

consteval std::uint32_t FindSystemPllPsel(uint32_t outFreq) {
  if (outFreq > (SystemPllMinVcoFreq >> 1U))
    return libmcuhw::syscon::SYSPLLCTRL::PSEL_DIV2;
  else if (outFreq > (SystemPllMinVcoFreq >> 2U))
    return libmcuhw::syscon::SYSPLLCTRL::PSEL_DIV4;
  else if (outFreq > (SystemPllMinVcoFreq >> 3U))
    return libmcuhw::syscon::SYSPLLCTRL::PSEL_DIV8;
  else
    return libmcuhw::syscon::SYSPLLCTRL::PSEL_DIV16;
}

consteval uint32_t FindSystemPllMsel(uint32_t inFreq, uint32_t outFreq) {
  return (outFreq / inFreq) - 1;
}

consteval uint32_t FindClockFrequency(uint32_t inFreq, uint32_t cpuFreq) {
  return libmcu::FindLcm(inFreq, cpuFreq, MainClockMaxFreq);
}
}  // namespace libmcuhw::clock

#endif