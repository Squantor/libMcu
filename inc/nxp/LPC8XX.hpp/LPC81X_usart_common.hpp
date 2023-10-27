/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series commong USART functions and definitions
 */
#ifndef LPC81X_USART_COMMON_HPP
#define LPC81X_USART_COMMON_HPP

#include "nxp/LPC8XX.hpp/LPC81X_usart_common.hpp"

namespace libMcuLL {
namespace sw {
namespace usart {
using namespace hw::usart;

/**
 * @brief amount of bits to transmit
 *
 * These bit patterns match the USART CFG register settings
 */
enum uartLength : std::uint32_t {
  SIZE_7 = (0 << 2), /**< USART transmit length of 7 bits */
  SIZE_8 = (1 << 2), /**< USART transmit length of 8 bits */
  SIZE_9 = (2 << 2), /**< USART transmit length of 9 bits */
};

/**
 * @brief Parity bit options
 *
 * These bit patterns match the USART CFG register settings
 */
enum uartParity : std::uint32_t {
  NONE = (0 << 4), /**< No parity */
  EVEN = (2 << 4), /**< Even parity */
  ODD = (3 << 4),  /**< Odd parity */
};

/**
 * @brief stop bit options
 *
 * These bit patterns match the USART CFG register settings
 */
enum uartStop : std::uint32_t {
  STOP_1 = (0 << 6), /**< 1 stop bit */
  STOP_2 = (1 << 6), /**< 2 stop bits */
};

/**
 * @brief Uart status bits
 *
 * These bit patterns match the USART STAT register settings
 */
enum uartStatus : std::uint32_t {
  RXRDY = STAT::RXRDY,               /**< Receiver ready flag, Read only */
  RXIDLE = STAT::RXIDLE,             /**< Receiver idle, Read only */
  TXRDY = STAT::TXRDY,               /**< Transmitter ready, Read only  */
  TXIDLE = STAT::TXIDLE,             /**< Transmitter idle, Read only */
  CTS = STAT::CTS,                   /**< CTS signal state, Read only */
  DELTACTS = STAT::DELTACTS,         /**< Change detected in CTS signal, write 1 clear */
  TXDISINT = STAT::TXDISINT,         /**< Transmitter disabled confirmation, read only  */
  OVERRUNINT = STAT::OVERRUNINT,     /**< Overrun error interrupt flag, write 1 clear */
  RXBRK = STAT::RXBRK,               /**< Received break, read only */
  DELTARXBRK = STAT::DELTARXBRK,     /**< Change detected in receiver break, write 1 clear */
  START = STAT::START,               /**< Start condition detected, write 1 clear */
  FRAMERRINT = STAT::FRAMERRINT,     /**< Frame error interrupt flag, write 1 clear */
  PARITYERRINT = STAT::PARITYERRINT, /**< Parity error interrupt flag, write 1 clear */
  RXNOISEINT = STAT::RXNOISEINT,     /**< Recieved noise interrupt flag, write 1 clear*/
};
}  // namespace usart
}  // namespace sw
}  // namespace libMcuLL
#endif