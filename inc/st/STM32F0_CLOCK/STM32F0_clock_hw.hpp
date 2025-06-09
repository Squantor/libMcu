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

constexpr inline std::uint32_t kHsiDefaultClockFreq{8'000'000}; /*!< HSI default clock frequency */

/**
 * @brief clock sources available for this microcontroller
 */
enum class ClockInputSources : std::uint8_t {
  kHsi,   /*!< HSI 8MHz RC oscillator */
  kHse,   /*!< HSE crystal oscillator */
  kLsi,   /*!< LSI 40kHz RC oscillator */
  kLse,   /*!< LSE low speed crystal oscillator (RTCCLK) */
  kHsi14, /*!< HSI 14MHz RC oscillator for ADC */
};
template <ClockInputSources source, std::uint32_t input_freq, std::uint32_t cpu_freq>
struct McuClockConfig {};

inline McuClockConfig<ClockInputSources::kHsi, kHsiDefaultClockFreq, kHsiDefaultClockFreq> const default_clock_config;

}  // namespace libmcuhw::clock
#endif