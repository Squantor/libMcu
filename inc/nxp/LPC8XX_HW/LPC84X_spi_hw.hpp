/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Serial Peripheral register interface
 */
#ifndef LPC84X_SPI_HW_HPP
#define LPC84X_SPI_HW_HPP

namespace libMcuHw::spi {
/**
 * @brief SPI register definitions
 */
struct spi {
  volatile std::uint32_t CFG;           /**< SPI Configuration register */
  volatile std::uint32_t DLY;           /**< SPI Delay register */
  volatile std::uint32_t STAT;          /**< SPI Status */
  volatile std::uint32_t INTENSET;      /**< SPI Interrupt Enable read and Set */
  volatile std::uint32_t INTENCLR;      /**< SPI Interrupt Enable Clear */
  volatile const std::uint32_t RXDAT;   /**< SPI Receive Data */
  volatile std::uint32_t TXDATCTL;      /**< SPI Transmit Data with Control */
  volatile std::uint32_t TXDAT;         /**< SPI Transmit Data */
  volatile std::uint32_t TXCTL;         /**< SPI Transmit Control */
  volatile std::uint32_t DIV;           /**< SPI clock Divider */
  volatile const std::uint32_t INTSTAT; /**< SPI Interrupt Status */
};
}  // namespace libMcuHw::spi
#endif