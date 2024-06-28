/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 I2C register interface
 */
#ifndef LPC84X_I2C_HW_HPP
#define LPC84X_I2C_HW_HPP

namespace libMcu::hw::i2c {
/**
 * @brief I2C register definitions
 */
struct peripheral {
  volatile std::uint32_t CFG;            /**< Configuration for shared functions */
  volatile std::uint32_t STAT;           /**< Status register for Master, Slave, and Monitor functions */
  volatile std::uint32_t INTENSET;       /**< Interrupt Enable Set and read register */
  volatile std::uint32_t INTENCLR;       /**< Interrupt Enable Clear register */
  volatile std::uint32_t TIMEOUT;        /**< Time-out value register */
  volatile std::uint32_t CLKDIV;         /**< Clock pre-divider for the entire I2C interface */
  volatile const std::uint32_t INTSTAT;  /**< Interrupt Status register for Master, Slave, and Monitor functions */
  std::uint8_t RESERVED_0[4];            /**< Reserved */
  volatile std::uint32_t MSTCTL;         /**< Master control register */
  volatile std::uint32_t MSTTIME;        /**< Master timing configuration */
  volatile std::uint32_t MSTDAT;         /**< Combined Master receiver and transmitter data registe */
  std::uint8_t RESERVED_1[20];           /**< Reserved */
  volatile std::uint32_t SLVCTL;         /**< Slave control register */
  volatile std::uint32_t SLVDAT;         /**< Combined Slave receiver and transmitter data register */
  volatile std::uint32_t SLVADR[4];      /**< Slave address register */
  volatile std::uint32_t SLVQUAL0;       /**< Slave Qualification for address 0 */
  std::uint8_t RESERVED_2[36];           /**< Reserved */
  volatile const std::uint32_t MONRXDAT; /**< Monitor receiver data register */
};
}  // namespace libMcu::hw::i2c
#endif