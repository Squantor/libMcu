/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_hal_uart_common.hpp
 * @brief LPC84X series UART HAL common definitions
 */
#ifndef LPC84X_HAL_UART_COMMON_HPP
#define LPC84X_HAL_UART_COMMON_HPP

namespace libmcuhal::usart {
namespace hardware = libmcuhw::usart;

/**
 * @brief amount of bits to transmit
 */
enum class uartLength : std::uint32_t {
  SIZE_7 = hardware::CFG::kDATALEN7BIT, /*!< USART transmit length of 7 bits */
  SIZE_8 = hardware::CFG::kDATALEN8BIT, /*!< USART transmit length of 8 bits */
  SIZE_9 = hardware::CFG::kDATALEN9BIT, /*!< USART transmit length of 9 bits */
};

/**
 * @brief Parity bit options
 */
enum class uartParity : std::uint32_t {
  NONE = hardware::CFG::kPARITY_NONE, /*!< No parity */
  EVEN = hardware::CFG::kPARITY_EVEN, /*!< Even parity */
  ODD = hardware::CFG::kPARITY_ODD,   /*!< Odd parity */
};

/**
 * @brief stop bit options
 */
enum class uartStop : std::uint32_t {
  STOP_1 = hardware::CFG::kSTOPBIT1, /*!< 1 stop bit */
  STOP_2 = hardware::CFG::kSTOPBIT2, /*!< 2 stop bits */
};

/**
 * @brief Uart status bits
 *
 * These bit patterns match the USART STAT register settings
 */
enum uartStatus : std::uint32_t {
  RXRDY = hardware::STAT::kRXRDY,               /*!< Receiver ready flag, Read only */
  RXIDLE = hardware::STAT::kRXIDLE,             /*!< Receiver idle, Read only */
  TXRDY = hardware::STAT::kTXRDY,               /*!< Transmitter ready, Read only  */
  TXIDLE = hardware::STAT::kTXIDLE,             /*!< Transmitter idle, Read only */
  CTS = hardware::STAT::kCTS,                   /*!< CTS signal state, Read only */
  DELTACTS = hardware::STAT::kDELTACTS,         /*!< Change detected in CTS signal, write 1 clear */
  TXDISINT = hardware::STAT::kTXDISINT,         /*!< Transmitter disabled confirmation, read only  */
  OVERRUNINT = hardware::STAT::kOVERRUNINT,     /*!< Overrun error interrupt flag, write 1 clear */
  RXBRK = hardware::STAT::kRXBRK,               /*!< Received break, read only */
  DELTARXBRK = hardware::STAT::kDELTARXBRK,     /*!< Change detected in receiver break, write 1 clear */
  START = hardware::STAT::kSTART,               /*!< Start condition detected, write 1 clear */
  FRAMERRINT = hardware::STAT::kFRAMERRINT,     /*!< Frame error interrupt flag, write 1 clear */
  PARITYERRINT = hardware::STAT::kPARITYERRINT, /*!< Parity error interrupt flag, write 1 clear */
  RXNOISEINT = hardware::STAT::kRXNOISEINT,     /*!< Recieved noise interrupt flag, write 1 clear*/
  ABERR = hardware::STAT::kABERR,               /*!< Autobaud error flag, write 1 clears */
};

namespace detail {

enum class synchonousStates : std::uint8_t {
  IDLE,        /*!< Interface is idle, ready to be claimed */
  CLAIMED,     /*!< Interface is claimed, ready to transact */
  TRANSACTING, /*!< Interface is busy with a transaction */
};
}  // namespace detail

}  // namespace libmcuhal::usart

#endif