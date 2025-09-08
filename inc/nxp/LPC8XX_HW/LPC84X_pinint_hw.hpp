/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_pinint_hw.hpp
 * @brief Register structure and bit definitions for the LPC840 series Pin Interrupt
 */
#ifndef LPC84X_PININT_HW_HPP
#define LPC84X_PININT_HW_HPP

namespace libmcuhw::pinint {
/**
 * @brief Interrupt pins indices
 */
enum class InterruptPins : std::size_t {
  PintSel0 = (1u << 0), /*!< PINTSEL0 */
  PintSel1 = (1u << 1), /*!< PINTSEL1 */
  PintSel2 = (1u << 2), /*!< PINTSEL2 */
  PintSel3 = (1u << 3), /*!< PINTSEL3 */
  PintSel4 = (1u << 4), /*!< PINTSEL4 */
  PintSel5 = (1u << 5), /*!< PINTSEL5 */
  PintSel6 = (1u << 6), /*!< PINTSEL6 */
  PintSel7 = (1u << 7), /*!< PINTSEL7 */
};
/**
 * @brief PININT register definitions
 */
struct Pinint {
  volatile std::uint32_t ISEL;   /*!< Pin Interrupt Mode register */
  volatile std::uint32_t IENR;   /*!< Pin interrupt level or rising edge interrupt enable register */
  volatile std::uint32_t SIENR;  /*!< Pin interrupt level or rising edge interrupt set register */
  volatile std::uint32_t CIENR;  /*!< Pin interrupt level (rising edge interrupt) clear register */
  volatile std::uint32_t IENF;   /*!< Pin interrupt active level or falling edge interrupt enable register */
  volatile std::uint32_t SIENF;  /*!< Pin interrupt active level or falling edge interrupt set register */
  volatile std::uint32_t CIENF;  /*!< Pin interrupt active level or falling edge interrupt clear register */
  volatile std::uint32_t RISE;   /*!< Pin interrupt rising edge register */
  volatile std::uint32_t FALL;   /*!< Pin interrupt falling edge register */
  volatile std::uint32_t IST;    /*!< Pin interrupt status register */
  volatile std::uint32_t PMCTRL; /*!< Pattern match interrupt control register */
  volatile std::uint32_t PMSRC;  /*!< Pattern match interrupt bit-slice source register */
  volatile std::uint32_t PMCFG;  /*!< Pattern match interrupt bit slice configuration register */
};
}  // namespace libmcuhw::pinint
#endif