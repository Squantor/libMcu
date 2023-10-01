/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series USART functions
 */
#ifndef LPC81X_USART_HPP
#define LPC81X_USART_HPP

namespace libMcuLL {
namespace sw {
namespace usart {
using namespace hw::usart;

/**
 * @brief amount of bits to transmit
 *
 * These bit patterns match the USART CFG register settings
 */
enum uartLength : uint32_t {
  SIZE_7 = (0 << 2), /**< USART transmit length of 7 bits */
  SIZE_8 = (1 << 2), /**< USART transmit length of 8 bits */
  SIZE_9 = (2 << 2), /**< USART transmit length of 9 bits */
};

/**
 * @brief Parity bit options
 *
 * These bit patterns match the USART CFG register settings
 */
enum uartParity : uint32_t {
  NONE = (0 << 4), /**< No parity */
  EVEN = (2 << 4), /**< Even parity */
  ODD = (3 << 4),  /**< Odd parity */
};

/**
 * @brief stop bit options
 *
 * These bit patterns match the USART CFG register settings
 */
enum uartStop : uint32_t {
  STOP_1 = (0 << 6), /**< 1 stop bit */
  STOP_2 = (1 << 6), /**< 2 stop bits */
};

/**
 * @brief Uart status bits
 *
 * These bit patterns match the USART STAT register settings
 */
enum uartStatus : uint32_t {
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

template <libMcuLL::USARTaddress address_>
struct usart {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to usart registers
   */
  static hw::usart::peripheral *regs() {
    return reinterpret_cast<hw::usart::peripheral *>(address);
  }

  /**
   * @brief Setup USART to 8n1
   *
   * @param baudRate Baud rate value
   * @return uint32_t actual baud rate
   */
  uint32_t init(uint32_t baudRate) {
    uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    regs()->BRG = baudDivider;
    regs()->CFG = CFG::ENABLE | uartLength::SIZE_8 | uartParity::NONE | uartStop::STOP_1;
    return CLOCK_MAIN / 16 / baudDivider;
  }

  /**
   * @brief Setup USART
   *
   * @param baudRate Baud rate value
   * @param lengthBits bit length of transmissions, see uartLength enum for options
   * @param parity parity type of transmissions, see uartParity enum for options
   * @param stopBits Amount of stop bits, see uartStop enum for options
   * @return uint32_t actual baud rate
   */
  uint32_t init(uint32_t baudRate, uartLength lengthBits, uartParity parity, uartStop stopBits) {
    uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    regs()->BRG = baudDivider;
    regs()->CFG = CFG::ENABLE | lengthBits | parity | stopBits;
    return CLOCK_MAIN / 16 / baudDivider;
  }

  /**
   * @brief return uart status
   *
   * @return uint32_t one to one copy of the status register, see bit masks for options
   */
  uint32_t status() {
    return regs()->STAT & STAT::MASK;
  }

  /**
   * @brief Send data out of the UART
   *
   * @param data data to send, amount is sent according to configuration
   */
  void write(uint32_t data) {
    regs()->TXDAT = data & TXDAT::MASK;
  }
  /**
   * @brief Read data from UART
   *
   * @param data reference to put received data in
   */
  void read(uint32_t &data) {
    data = regs()->RXDAT;
  }

  /**
   * @brief Read data and status from UART
   *
   * @param data reference to put received data in
   * @param status reference to put received status in
   */
  void read(uint32_t &data, uint32_t &status) {
    uint32_t regData = regs()->RXDATSTAT;
    data = regData & RXDATSTAT::MASK_DATA;
    status = regData & RXDATSTAT::MASK_STAT;
  }
};
}  // namespace usart
}  // namespace sw
}  // namespace libMcuLL

#endif