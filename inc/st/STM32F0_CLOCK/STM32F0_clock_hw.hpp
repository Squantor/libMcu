/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file STM32F0_clock_hw.hpp
 * @brief STM32F0 clock hardware definitions and functions
 */
#ifndef STM32F0_CLOCK_HW_HPP
#define STM32F0_CLOCK_HW_HPP

namespace libmcuhw::clock {

constexpr inline std::uint32_t HsiDefaultClockFreq{8'000'000}; /*!< HSI default clock frequency */

/**
 * @brief clock sources available for this microcontroller
 */
enum class ClockInputSources : std::uint8_t {
  Hsi,   /*!< HSI 8MHz RC oscillator */
  Hse,   /*!< HSE crystal oscillator */
  Lsi,   /*!< LSI 40kHz RC oscillator */
  Lse,   /*!< LSE low speed crystal oscillator (RTCCLK) */
  Hsi14, /*!< HSI 14MHz RC oscillator for ADC */
};
template <ClockInputSources source, std::uint32_t input_freq, std::uint32_t cpu_freq>
struct McuClockConfig {};

inline McuClockConfig<ClockInputSources::Hsi, HsiDefaultClockFreq, HsiDefaultClockFreq> const default_clock_config;

}  // namespace libmcuhw::clock
#endif