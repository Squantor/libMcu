/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_usart_common_ll.hpp
 * @brief Common definitions for the low level USART interface of the LPC840 series
 */
#ifndef LPC84X_USART_COMMON_LL_HPP
#define LPC84X_USART_COMMON_LL_HPP

namespace libmcull::usart {
namespace hardware = ::libmcuhw::usart;

/**
 * @brief amount of bits to transmit
 */
enum class UartLengths : std::uint32_t {
  Size7 = hardware::CFG::DATALEN7BIT, /*!< USART transmit length of 7 bits */
  Size8 = hardware::CFG::DATALEN8BIT, /*!< USART transmit length of 8 bits */
  Size9 = hardware::CFG::DATALEN9BIT, /*!< USART transmit length of 9 bits */
};
/**
 * @brief Parity bit options
 */
enum class UartParities : std::uint32_t {
  None = hardware::CFG::PARITY_NONE, /*!< No parity */
  Even = hardware::CFG::PARITY_EVEN, /*!< Even parity */
  Odd = hardware::CFG::PARITY_ODD,   /*!< Odd parity */
};
/**
 * @brief stop bit options
 */
enum class UartStops : std::uint32_t {
  Stop1 = hardware::CFG::STOPBIT1, /*!< 1 stop bit */
  Stop2 = hardware::CFG::STOPBIT2, /*!< 2 stop bits */
};
/**
 * @brief Uart status bits
 * These bit patterns match the USART STAT register settings
 */
enum UartStatuses : std::uint32_t {
  RxReady = hardware::STAT::RXRDY,            /*!< Receiver ready flag*/
  RxIdle = hardware::STAT::RXIDLE,            /*!< Receiver idle flag */
  TxReady = hardware::STAT::TXRDY,            /*!< Transmitter ready flag  */
  TxIdle = hardware::STAT::TXIDLE,            /*!< Transmitter idle flag */
  Cts = hardware::STAT::CTS,                  /*!< CTS signal state flag */
  CtsChange = hardware::STAT::DELTACTS,       /*!< Change detected in CTS signal flag */
  TxDisable = hardware::STAT::TXDISINT,       /*!< Transmitter disabled confirmation flag */
  Overrun = hardware::STAT::OVERRUNINT,       /*!< Overrun error flag */
  RxBreak = hardware::STAT::RXBRK,            /*!< Received break flag */
  RxBreakChange = hardware::STAT::DELTARXBRK, /*!< Change detected in receiver break flag */
  Start = hardware::STAT::START,              /*!< Start condition detected flag */
  FrameError = hardware::STAT::FRAMERRINT,    /*!< Frame error flag */
  ParityError = hardware::STAT::PARITYERRINT, /*!< Parity error flag */
  RxNoise = hardware::STAT::RXNOISEINT,       /*!< Recieved noise flag */
  AutobaudError = hardware::STAT::ABERR,      /*!< Autobaud error flags */
};

}  // namespace libmcull::usart

#endif