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

#include "nxp/LPC8XX.hpp/LPC81X_usart_common.hpp"

namespace libMcuLL {
namespace sw {
namespace usart {
using namespace hw::usart;

/**
 * @brief synchronous USART peripheral instance
 *
 * @tparam address_ Peripheral base address
 * @tparam transferType datatype to use for data transfers
 */
template <libMcuLL::USARTbaseAddress address_, typename transferType>
struct usartSync {
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
   * @return std::uint32_t actual baud rate
   */
  std::uint32_t init(std::uint32_t baudRate) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
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
   * @return std::uint32_t actual baud rate
   */
  std::uint32_t init(std::uint32_t baudRate, uartLength lengthBits, uartParity parity, uartStop stopBits) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    regs()->BRG = baudDivider;
    regs()->CFG = CFG::ENABLE | lengthBits | parity | stopBits;
    return CLOCK_MAIN / 16 / baudDivider;
  }

  /**
   * @brief return uart status
   *
   * @return std::uint32_t one to one copy of the status register, see bit masks for options
   */
  std::uint32_t status() {
    return regs()->STAT & STAT::MASK;
  }

  /**
   * @brief Send data out of the UART
   *
   * @param data data to send, amount is sent according to configuration
   */
  void write(transferType data) {
    regs()->TXDAT = static_cast<transferType>(data & TXDAT::MASK);
  }
  /**
   * @brief Read data from UART
   *
   * @param data reference to put received data in
   */
  void read(transferType &data) {
    data = static_cast<transferType>(regs()->RXDAT);
  }

  /**
   * @brief Read data and status from UART
   *
   * @param data reference to put received data in
   * @param status reference to put received status in
   */
  void read(transferType &data, std::uint32_t &status) {
    std::uint32_t regData = regs()->RXDATSTAT;
    data = static_cast<transferType>(regData & RXDATSTAT::MASK_DATA);
    status = regData & RXDATSTAT::MASK_STAT;
  }
};
}  // namespace usart
}  // namespace sw
}  // namespace libMcuLL

#endif