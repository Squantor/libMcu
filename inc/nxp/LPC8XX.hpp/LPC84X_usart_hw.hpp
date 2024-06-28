/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 USART register interface
 */
#ifndef LPC84X_USART_HW_HPP
#define LPC84X_USART_HW_HPP

namespace libMcu::hw::usart {
/**
 * @brief USART register definitions
 */
struct peripheral {
  volatile std::uint32_t CFG;             /**< USART Configuration register */
  volatile std::uint32_t CTL;             /**< USART Control register */
  volatile std::uint32_t STAT;            /**< USART Status register */
  volatile std::uint32_t INTENSET;        /**< Interrupt Enable read and Set register */
  volatile std::uint32_t INTENCLR;        /**< Interrupt Enable Clear register */
  volatile const std::uint32_t RXDAT;     /**< Receiver Data register */
  volatile const std::uint32_t RXDATSTAT; /**< Receiver Data with Status register */
  volatile std::uint32_t TXDAT;           /**< Transmit Data register */
  volatile std::uint32_t BRG;             /**< Baud Rate Generator register */
  volatile const std::uint32_t INTSTAT;   /**< Interrupt status register */
  volatile std::uint32_t OSR;             /**< Oversample selection register for asynchronous communication */
  volatile std::uint32_t ADDR;            /**< Address register for automatic address matching */
};
}  // namespace libMcu::hw::usart
#endif