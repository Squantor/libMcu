/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_dac_hw.hpp
 * @brief Register structure and bit definitions for the LPC840 series DAC
 */
#ifndef LPC84X_DAC_HW_HPP
#define LPC84X_DAC_HW_HPP

namespace libmcuhw::dac {
/**
 * @brief Digital to Analog register definitions
 */
struct Dac {
  volatile std::uint32_t CR;     /*!< D/A Converter Register */
  volatile std::uint32_t CTRL;   /*!< DAC Control register */
  volatile std::uint32_t CNTVAL; /*!< DAC Counter Value register */
};
}  // namespace libmcuhw::dac
#endif