/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC84X_clock_hw.hpp
 * \brief TODO
 */
#ifndef LPC84X_CLOCK_HW_HPP
#define LPC84X_CLOCK_HW_HPP

#include "LPC8XX_clock.hpp"

namespace libMcuHw::clock {

/**
 * @brief
 */
enum class clockInputSources : std::uint8_t {
  FRO,   /**< FRO clock oscillator */
  XTAL,  /**< Crystal clock oscillator */
  CLKIN, /**< Clock input pin */
  // TODO: WDT
};
/**
 * @brief
 */
enum class periSelect : std::uint8_t {
  UART0, /**< UART 0 peripheral */
  UART1, /**< UART 1 peripheral */
  UART2, /**< UART 2 peripheral */
  UART3, /**< UART 3 peripheral */
  I2C0,  /**< I2C 0 peripheral */
  I2C1,  /**< I2C 1 peripheral */
  I2C2,  /**< I2C 2 peripheral */
  I2C3,  /**< I2C 3 peripheral */
  SPI0,  /**< SPI 0 peripheral */
  SPI1   /**< SPI 1 peripheral */
};
/**
 * @brief
 */
enum class periSource : std::uint8_t {
  FRO,     /**< FRO oscillator */
  MAIN,    /**< Main clock oscillator */
  FRG0,    /**< Fractional clock generator 0 */
  FRG1,    /**< Fractional clock generator 1 */
  FRO_DIV, /**< FRO oscillator divided by 2 */
  SYS_PLL, /**< System PLL */
  NONE,    /**< No clock */
};
/**
 * @brief Microcontroller clock configuration generation
 * @tparam t_source primary microcontroller clock source
 * @tparam t_inputFreq input frequency of this clock source
 * @tparam t_systemFreq wanted system (CPU) frequency
 */
template <clockInputSources t_source, std::uint32_t t_inputFreq, std::uint32_t t_systemFreq>
struct mcuClockConfig {
  static_assert(findClockFrequency(t_inputFreq, t_systemFreq) != 0, "Unable to find a clock configuration solution");
  static constexpr clockInputSources source{t_source};
  static constexpr std::uint32_t inputFreq{t_inputFreq};
  static constexpr std::uint32_t mainFreq{findClockFrequency(t_inputFreq, t_systemFreq)};
  static constexpr std::uint32_t systemFreq{t_systemFreq};
  static constexpr std::uint32_t froFreq{froDefaultClockFreq};
  // TODO fractional rate converters?
};
/**
 * @brief peripheral clock configuration generation
 * @tparam &t_clockConfig microcontroller clock configuration
 * @tparam t_peripheral peripheral to configure
 * @tparam t_source clock source to setup
 */
template <const mcuClockConfig &t_clockConfig, periSelect t_peripheral, periSource t_source>
struct periClockConfig {
  periSelect peripheral{t_peripheral};
  periSource source{t_source};
  static consteval std::uint32_t getFrequency() {
    if constexpr (t_source == periSource::FRO)
      return t_clockConfig.froFreq;
    else if constexpr (t_source == periSource::MAIN)
      return t_clockConfig.mainFreq;
    else if constexpr (t_source == periSource::FRG0)
      static_assert(false, "FRG0 input not implemented yet!");
    else if constexpr (t_source == periSource::FRG1)
      static_assert(false, "FRG1 input not implemented yet!");
    else if constexpr (t_source == periSource::FRO_DIV)
      static_assert(false, "FRO divider input not implemented yet!");
    else
      static_assert(false, "Unsupported clock input for this peripheral!");
    return 0;
  }
};
/**< */
inline mcuClockConfig<clockInputSources::FRO, froDefaultClockFreq, froDefaultClockFreq> const defaultClocks;

}  // namespace libMcuHw::clock

#endif