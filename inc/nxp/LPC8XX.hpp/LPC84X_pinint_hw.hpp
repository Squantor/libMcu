/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Pin Interrupt register interface
 */
#ifndef LPC84X_PININT_HW_HPP
#define LPC84X_PININT_HW_HPP

namespace libMcu::hw::pinint {
/**
 * @brief PININT register definitions
 */
struct peripheral {
  volatile std::uint32_t ISEL;   /**< Pin Interrupt Mode register */
  volatile std::uint32_t IENR;   /**< Pin interrupt level or rising edge interrupt enable register */
  volatile std::uint32_t SIENR;  /**< Pin interrupt level or rising edge interrupt set register */
  volatile std::uint32_t CIENR;  /**< Pin interrupt level (rising edge interrupt) clear register */
  volatile std::uint32_t IENF;   /**< Pin interrupt active level or falling edge interrupt enable register */
  volatile std::uint32_t SIENF;  /**< Pin interrupt active level or falling edge interrupt set register */
  volatile std::uint32_t CIENF;  /**< Pin interrupt active level or falling edge interrupt clear register */
  volatile std::uint32_t RISE;   /**< Pin interrupt rising edge register */
  volatile std::uint32_t FALL;   /**< Pin interrupt falling edge register */
  volatile std::uint32_t IST;    /**< Pin interrupt status register */
  volatile std::uint32_t PMCTRL; /**< Pattern match interrupt control register */
  volatile std::uint32_t PMSRC;  /**< Pattern match interrupt bit-slice source register */
  volatile std::uint32_t PMCFG;  /**< Pattern match interrupt bit slice configuration register */
};
}  // namespace libMcu::hw::pinint
#endif