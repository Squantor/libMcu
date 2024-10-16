/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Pin interrupt register interface
 */
#ifndef LPC81X_PIN_INT_REGS_HPP
#define LPC81X_PIN_INT_REGS_HPP

namespace libMcuLL::hw::pinint {

/**
 * @brief pin interrupt register definitions
 */
struct pinint {
  volatile std::uint32_t ISEL;   /**< Pin Interrupt Mode register */
  volatile std::uint32_t IENR;   /**< Pin interrupt level or rising edge enable register */
  volatile std::uint32_t SIENR;  /**< Pin interrupt level or rising edge set register */
  volatile std::uint32_t CIENR;  /**< Pin interrupt level (rising edge interrupt) clear register */
  volatile std::uint32_t IENF;   /**< Pin interrupt active level or falling edge interrupt enable register */
  volatile std::uint32_t SIENF;  /**< Pin interrupt active level or falling edge interrupt set register */
  volatile std::uint32_t CIENF;  /**< Pin interrupt active level or falling edge interrupt clear register */
  volatile std::uint32_t RISE;   /**< Pin interrupt rising edge register */
  volatile std::uint32_t FALL;   /**< Pin interrupt falling edge register */
  volatile std::uint32_t IST;    /**< Pin interrupt status register */
  volatile std::uint32_t PMCTRL; /**< Pattern match interrupt control register */
  volatile std::uint32_t PMSRC;  /**< Pattern match interrupt bit slice source register */
  volatile std::uint32_t PMCFG;  /**< Pattern match interrupt bit slice configuration register */
};

}  // namespace libMcuLL::hw::pinint
#endif