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

namespace libMcuHw::clock {

constexpr inline std::uint32_t hsiDefaultClockFreq{8'000'000}; /*!< HSI default clock frequency */

/**
 * @brief clock sources available for this microcontroller
 */
enum class clockInputSources : std::uint8_t {
  HSI,   /*!< HSI 8MHz RC oscillator */
  HSE,   /*!< HSE crystal oscillator */
  LSI,   /*!< LSI 40kHz RC oscillator */
  LSE,   /*!< LSE low speed crystal oscillator (RTCCLK) */
  HSI14, /*!< HSI 14MHz RC oscillator for ADC */
};
template <clockInputSources t_source, std::uint32_t t_inputFreq, std::uint32_t t_cpuFreq>
struct mcuClockConfig {};

inline mcuClockConfig<clockInputSources::HSI, hsiDefaultClockFreq, hsiDefaultClockFreq> const defaultClocks;

}  // namespace libMcuHw::clock
#endif