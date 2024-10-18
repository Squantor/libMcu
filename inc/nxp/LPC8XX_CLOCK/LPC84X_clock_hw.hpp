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

enum class clockInputSources : std::uint8_t {
  FRO,   /**< FRO clock oscillator */
  XTAL,  /**< Crystal clock oscillator */
  CLKIN, /**< Clock input pin */
  // TODO: WDT
};

enum class periSource : std::uint8_t {
  FRO,
  MAIN,
  FRG0,
  FRG1,
  FRO_DIV_2,
  SYS_PLL,
  NONE,
};

template <clockInputSources t_source, std::uint32_t t_inputFreq, std::uint32_t t_systemFreq, periSource t_uart0, periSource t_uart1,
          periSource t_uart2, periSource t_uart3, periSource t_i2c0, periSource t_i2c1, periSource t_i2c2, periSource t_i2c3,
          periSource t_spi0, periSource t_spi1, periSource t_adc>
struct clockConfig {
  static_assert(findClockFrequency(t_inputFreq, t_systemFreq) != 0, "Unable to find a clock configuration solution");
  static constexpr clockInputSources source{t_source};
  static constexpr std::uint32_t inputFreq{t_inputFreq};
  static constexpr std::uint32_t mainFreq{findClockFrequency(t_inputFreq, t_systemFreq)};
  static constexpr std::uint32_t systemFreq{t_systemFreq};
  static constexpr std::uint32_t froFreq{froDefaultClockFreq};
  static constexpr periSource uart0Source{t_uart0};
  static constexpr periSource uart1Source{t_uart1};
  static constexpr periSource uart2Source{t_uart2};
  static constexpr periSource uart3Source{t_uart3};
  static constexpr periSource i2c0Source{t_i2c0};
  static constexpr periSource i2c1Source{t_i2c1};
  static constexpr periSource i2c2Source{t_i2c2};
  static constexpr periSource i2c3Source{t_i2c3};
  static constexpr periSource spi0Source{t_spi0};
  static constexpr periSource spi1Source{t_spi1};
  static constexpr periSource adcSource{t_adc};
  // TODO fractional rate converters?
};

inline clockConfig<clockInputSources::FRO, froDefaultClockFreq, froDefaultClockFreq, periSource::FRO, periSource::FRO,
                   periSource::FRO, periSource::FRO, periSource::FRO, periSource::FRO, periSource::FRO, periSource::FRO,
                   periSource::FRO, periSource::FRO, periSource::FRO> const defaultClocks;

}  // namespace libMcuHw::clock

#endif