/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC84X_clock_hw.hpp
 * \brief LPC84X series common clock distribution register definitions and functions
 */
#ifndef LPC84X_CLOCK_HW_HPP
#define LPC84X_CLOCK_HW_HPP

#include "LPC8XX_clock.hpp"

namespace libmcuhw::clock {

/**
 * @brief
 * @todo rename to naming conventions
 */
enum class ClockInputSources : std::uint8_t {
  FRO,   /*!< FRO clock oscillator */
  XTAL,  /*!< Crystal clock oscillator */
  CLKIN, /*!< Clock input pin */
  // TODO: WDT
};
/**
 * @brief
 * @todo rename to naming conventions
 */
enum class PeriSelect : std::uint8_t {
  UART0, /*!< UART 0 peripheral */
  UART1, /*!< UART 1 peripheral */
  UART2, /*!< UART 2 peripheral */
  UART3, /*!< UART 3 peripheral */
  I2C0,  /*!< I2C 0 peripheral */
  I2C1,  /*!< I2C 1 peripheral */
  I2C2,  /*!< I2C 2 peripheral */
  I2C3,  /*!< I2C 3 peripheral */
  SPI0,  /*!< SPI 0 peripheral */
  SPI1   /*!< SPI 1 peripheral */
};
/**
 * @brief
 * @todo rename to naming conventions
 */
enum class PeriSource : std::uint8_t {
  FRO,     /*!< FRO oscillator */
  MAIN,    /*!< Main clock oscillator */
  FRG0,    /*!< Fractional clock generator 0 */
  FRG1,    /*!< Fractional clock generator 1 */
  FRO_DIV, /*!< FRO oscillator divided by 2 */
  SYS_PLL, /*!< System PLL */
  NONE,    /*!< No clock */
};
/**
 * @brief Microcontroller clock configuration generation
 * @tparam source primary microcontroller clock source
 * @tparam input_freq input frequency of this clock source
 * @tparam system_freq wanted system (CPU) frequency
 */
template <ClockInputSources source, std::uint32_t input_freq, std::uint32_t system_freq>
struct McuClockConfig {
  static constexpr ClockInputSources source_{source}; /*!< primary clock source for the microcontroller */
  /**
   * @brief Get frequency for the input clock source
   * @retval frequency in Hertz
   */
  static consteval std::uint32_t GetSourceFreq() {
    return input_freq;
  }
  /**
   * @brief Get frequency for the main clock clock net
   * @retval frequency in Hertz
   */
  static consteval std::uint32_t GetMainFreq() {
    static_assert(FindClockFrequency(input_freq, system_freq) != 0, "Unable to find a clock configuration solution");
    return FindClockFrequency(input_freq, system_freq);
  }
  /**
   * @brief Get frequency for the system clock net, this is also the CPU frequency
   * @return frequency in Hertz
   */
  static consteval std::uint32_t GetSystemFreq() {
    return system_freq;
  }
  /**
   * @brief Get frequency for the FRO clock generator
   * @return frequency in Hertz
   */
  static consteval std::uint32_t GetFroFreq() {
    if constexpr (source_ == ClockInputSources::FRO) {
      return input_freq;
    } else {
      return FroDefaultClockFreq;
    }
  };
  // TODO fractional rate converters?
};
/**
 * @brief peripheral clock configuration generation
 * @tparam &clock_config microcontroller clock configuration
 * @tparam peripheral peripheral to configure
 * @tparam source clock source to setup
 */
template <const auto &clock_config, PeriSelect peripheral, PeriSource source>
struct PeriClockConfig {
  PeriSelect peripheral_{peripheral};
  PeriSource source_{source};
  /**
   * @brief Get the peripheral input clock frequency
   * @return consteval
   */
  static consteval std::uint32_t GetFrequency() {
    if constexpr (source == PeriSource::FRO)
      return clock_config.GetFroFreq();
    else if constexpr (source == PeriSource::MAIN)
      return clock_config.GetMainFreq();
    else if constexpr (source == PeriSource::FRG0)
      static_assert(false, "FRG0 input not implemented yet!");
    else if constexpr (source == PeriSource::FRG1)
      static_assert(false, "FRG1 input not implemented yet!");
    else if constexpr (source == PeriSource::FRO_DIV)
      static_assert(false, "FRO divider input not implemented yet!");
    else
      static_assert(false, "Unsupported clock input for this peripheral!");
    return 0;
  }
};
/*!< Default clock configuration for LPC840 series*/
inline McuClockConfig<ClockInputSources::FRO, FroDefaultClockFreq, FroDefaultClockFreq> const default_clock_config;

}  // namespace libmcuhw::clock

#endif