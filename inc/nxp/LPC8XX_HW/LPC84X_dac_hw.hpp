/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Digital to Analog register interface
 */
#ifndef LPC84X_DAC_HW_HPP
#define LPC84X_DAC_HW_HPP

namespace libMcuHw::dac {
/**
 * @brief Digital to Analog register definitions
 */
struct dac {
  volatile std::uint32_t CR;     /**< D/A Converter Register */
  volatile std::uint32_t CTRL;   /**< DAC Control register */
  volatile std::uint32_t CNTVAL; /**< DAC Counter Value register */
};
}  // namespace libMcuHw::dac
#endif