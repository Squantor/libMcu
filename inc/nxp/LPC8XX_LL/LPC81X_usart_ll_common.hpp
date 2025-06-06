/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_usart_ll_common.hpp
 * @brief LPC810 series USART interface class and definitions
 */
#ifndef LPC81X_USART_SW_COMMON_HPP
#define LPC81X_USART_SW_COMMON_HPP

namespace libmcull::usart {
namespace hardware = libmcuhw::usart;
/**
 * @brief amount of bits to transmit
 */
enum UartLengths : std::uint32_t {
  kSize7 = hardware::CFG::kDATALEN7BIT, /*!< USART transmit length of 7 bits */
  kSize8 = hardware::CFG::kDATALEN8BIT, /*!< USART transmit length of 8 bits */
  kSize9 = hardware::CFG::kDATALEN9BIT, /*!< USART transmit length of 9 bits */
};

/**
 * @brief Parity bit options
 */
enum UartParities : std::uint32_t {
  kParityNone = hardware::CFG::kPARITY_NONE, /*!< No parity */
  kParityEven = hardware::CFG::kPARITY_EVEN, /*!< Even parity */
  kParityOdd = hardware::CFG::kPARITY_ODD,   /*!< Odd parity */
};

/**
 * @brief stop bit options
 */
enum UartStops : std::uint32_t {
  kStop1 = hardware::CFG::kSTOPBIT1, /*!< 1 stop bit */
  kStop2 = hardware::CFG::kSTOPBIT2, /*!< 2 stop bits */
};

/**
 * @brief Uart status bit masks
 */
enum UartStatusMasks : std::uint32_t {
  kRxReady = hardware::STAT::kRXRDY,            /*!< Receiver ready flag, Read only */
  kRxIdle = hardware::STAT::kRXIDLE,            /*!< Receiver idle, Read only */
  kTxReady = hardware::STAT::kCTS,              /*!< Transmitter ready, Read only  */
  kTxIdle = hardware::STAT::kTXIDLE,            /*!< Transmitter idle, Read only */
  kCts = hardware::STAT::kCTS,                  /*!< CTS signal state, Read only */
  kDeltaCts = hardware::STAT::kDELTACTS,        /*!< Change detected in CTS signal, write 1 clear */
  kTxdDisabled = hardware::STAT::kTXDISINT,     /*!< Transmitter disabled confirmation, read only  */
  kOverrun = hardware::STAT::kOVERRUNINT,       /*!< Overrun error interrupt flag, write 1 clear */
  kRxBreak = hardware::STAT::kRXBRK,            /*!< Received break, read only */
  kRxBreakChange = hardware::STAT::kDELTARXBRK, /*!< Change detected in receiver break, write 1 clear */
  kStart = hardware::STAT::kSTART,              /*!< Start condition detected, write 1 clear */
  kFrameError = hardware::STAT::kFRAMERRINT,    /*!< Frame error interrupt flag, write 1 clear */
  kParityError = hardware::STAT::kPARITYERRINT, /*!< Parity error interrupt flag, write 1 clear */
  kRxNoise = hardware::STAT::kRXNOISEINT,       /*!< Recieved noise interrupt flag, write 1 clear*/
};
}  // namespace libmcull::usart
#endif