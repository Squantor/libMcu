/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series USART register interface
 */
#ifndef LPC81X_USART_REGS_HPP
#define LPC81X_USART_REGS_HPP

namespace registers {
namespace usart {

/**
 * @brief USART register definitions
 *
 */
struct registers {
  volatile uint32_t CFG;             /**< USART Configuration register. */
  volatile uint32_t CTL;             /**< USART Control register. */
  volatile uint32_t STAT;            /**< USART Status register. */
  volatile uint32_t INTENSET;        /**< Interrupt Enable read and Set register. */
  volatile uint32_t INTENCLR;        /**< Interrupt Enable Clear register. */
  volatile const uint32_t RXDAT;     /**< Receiver Data register. */
  volatile const uint32_t RXDATSTAT; /**< Receiver Data with Status register.  */
  volatile uint32_t TXDAT;           /**< Transmit Data register. */
  volatile uint32_t BRG;             /**< Baud Rate Generator register. */
  volatile const uint32_t INTSTAT;   /**< Interrupt status register. */
};

}  // namespace usart
}  // namespace registers

#endif