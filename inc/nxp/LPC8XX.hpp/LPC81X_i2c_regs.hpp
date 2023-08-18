/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series I2C bus register interface
 */
#ifndef LPC81X_I2C_REGS_HPP
#define LPC81X_I2C_REGS_HPP

namespace registers {
namespace i2c {

/**
 * @brief I2C bus register definitions
 *
 */
struct registers {
  volatile uint32_t CFG;                /**< Configuration for shared functions */
  volatile uint32_t STAT;               /**< Status register for Master, Slave, and Monitor functions */
  volatile uint32_t INTENSET;           /**< Interrupt Enable Set and read register */
  volatile uint32_t INTENCLR;           /**< Interrupt Enable Clear register */
  volatile uint32_t TIMEOUT;            /**< Time-out value register */
  volatile uint32_t CLKDIV;             /**< Clock pre-divider for the entire I2C interface */
  volatile const uint32_t INTSTAT;      /**< Interrupt Status register for Master, Slave, and Monitor functions */
  volatile const uint32_t RESERVED0;    /**< reserved */
  volatile uint32_t MSTCTL;             /**< Master control register */
  volatile uint32_t MSTTIME;            /**< Master timing configuration */
  volatile uint32_t MSTDAT;             /**< Combined Master receiver and transmitter data register */
  volatile const uint32_t RESERVED1[5]; /**< reserved */
  volatile uint32_t SLVCTL;             /**< Slave control register */
  volatile uint32_t SLVDAT;             /**< Combined Slave receiver and transmitter data register */
  volatile uint32_t SLVADR[4];          /**< Slave address register */
  volatile uint32_t SLVQUAL0;           /**< Slave Qualification for address 0 */
  volatile const uint32_t RESERVED2[9]; /**< reserved */
  volatile const uint32_t MONRXDAT;     /**< Monitor receiver data register */
};

}  // namespace i2c
}  // namespace registers

#endif