/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_usart_common_ll.hpp
 * @brief LPC810 series USART interface class and definitions
 */
#ifndef LPC81X_USART_COMMON_LL_HPP
#define LPC81X_USART_COMMON_LL_HPP

namespace libmcull::usart {
namespace hardware = libmcuhw::usart;
/**
 * @brief amount of bits to transmit
 */
enum UartLengths : std::uint32_t {
  Size7 = hardware::CFG::DATALEN7BIT, /*!< USART transmit length of 7 bits */
  Size8 = hardware::CFG::DATALEN8BIT, /*!< USART transmit length of 8 bits */
  Size9 = hardware::CFG::DATALEN9BIT, /*!< USART transmit length of 9 bits */
};

/**
 * @brief Parity bit options
 */
enum UartParities : std::uint32_t {
  ParityNone = hardware::CFG::PARITY_NONE, /*!< No parity */
  ParityEven = hardware::CFG::PARITY_EVEN, /*!< Even parity */
  ParityOdd = hardware::CFG::PARITY_ODD,   /*!< Odd parity */
};

/**
 * @brief stop bit options
 */
enum UartStops : std::uint32_t {
  Stop1 = hardware::CFG::STOPBIT1, /*!< 1 stop bit */
  Stop2 = hardware::CFG::STOPBIT2, /*!< 2 stop bits */
};

/**
 * @brief Uart status bit masks
 */
enum UartStatusMasks : std::uint32_t {
  RxReady = hardware::STAT::RXRDY,            /*!< Receiver ready flag, Read only */
  RxIdle = hardware::STAT::RXIDLE,            /*!< Receiver idle, Read only */
  TxReady = hardware::STAT::CTS,              /*!< Transmitter ready, Read only  */
  TxIdle = hardware::STAT::TXIDLE,            /*!< Transmitter idle, Read only */
  Cts = hardware::STAT::CTS,                  /*!< CTS signal state, Read only */
  DeltaCts = hardware::STAT::DELTACTS,        /*!< Change detected in CTS signal, write 1 clear */
  TxdDisabled = hardware::STAT::TXDISINT,     /*!< Transmitter disabled confirmation, read only  */
  Overrun = hardware::STAT::OVERRUNINT,       /*!< Overrun error interrupt flag, write 1 clear */
  RxBreak = hardware::STAT::RXBRK,            /*!< Received break, read only */
  RxBreakChange = hardware::STAT::DELTARXBRK, /*!< Change detected in receiver break, write 1 clear */
  Start = hardware::STAT::START,              /*!< Start condition detected, write 1 clear */
  FrameError = hardware::STAT::FRAMERRINT,    /*!< Frame error interrupt flag, write 1 clear */
  ParityError = hardware::STAT::PARITYERRINT, /*!< Parity error interrupt flag, write 1 clear */
  RxNoise = hardware::STAT::RXNOISEINT,       /*!< Recieved noise interrupt flag, write 1 clear*/
};
}  // namespace libmcull::usart
#endif