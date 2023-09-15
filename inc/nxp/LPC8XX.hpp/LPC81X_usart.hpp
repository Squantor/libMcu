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

namespace instances {
namespace usart {
using namespace registers::usart;

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

template <uint32_t base>
struct usart {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to usart registers
   */
  static registers::usart::registers *regs() {
    return reinterpret_cast<registers::usart::registers *>(base);
  }

  /**
   * @brief Setup USART to 8n1
   *
   * @param baudRate Baud rate value
   * @return uint32_t actual baud rate
   */
  uint32_t init(uint32_t baudRate) {
    uint32_t baudDivider = CLOCK_AHB / (baudRate * 16);
    regs()->BRG = baudDivider;
    regs()->CFG = CFG::ENABLE | uartLength::SIZE_8 | uartParity::NONE | uartStop::STOP_1;
    return CLOCK_AHB / 16 / baudDivider;
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
    uint32_t baudDivider = CLOCK_AHB / (baudRate * 16);
    regs()->BRG = baudDivider;
    regs()->CFG = CFG::ENABLE | lengthBits | parity | stopBits;
    return CLOCK_AHB / 16 / baudDivider;
  }
};
}  // namespace usart
}  // namespace instances

#endif