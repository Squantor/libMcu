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

#include "LPC81X_usart_ll_common.hpp"

namespace libMcuLL::sw::usart {
using namespace libMcuLL::hw::usart;

/**
 * @brief synchronous USART peripheral instance
 *
 * @tparam usartAddress_ Peripheral base usartAddress
 * @tparam transferType datatype to use for data transfers
 */
template <libMcu::uartBaseAddress usartAddress_, typename transferType>
struct usartSync : libMcu::peripheralBase {
  /**
   * @brief Setup USART to 8n1
   *
   * @param baudRate Baud rate value
   * @return std::uint32_t actual baud rate
   */
  constexpr std::uint32_t init(std::uint32_t baudRate) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    usartPeripheral()->BRG = baudDivider;
    usartPeripheral()->CFG = CFG::ENABLE | uartLength::SIZE_8 | uartParity::NONE | uartStop::STOP_1;
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
  constexpr std::uint32_t init(std::uint32_t baudRate, uartLength lengthBits, uartParity parity, uartStop stopBits) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    usartPeripheral()->BRG = baudDivider;
    usartPeripheral()->CFG = CFG::ENABLE | lengthBits | parity | stopBits;
    return CLOCK_MAIN / 16 / baudDivider;
  }
  /**
   * @brief return uart status
   *
   * @return std::uint32_t one to one copy of the status register, see bit masks for options
   */
  constexpr std::uint32_t status() {
    return usartPeripheral()->STAT & STAT::RESERVED_MASK;
  }
  /**
   * @brief Send data out of the UART
   *
   * @param data data to send, amount is sent according to configuration
   */
  constexpr void write(transferType data) {
    usartPeripheral()->TXDAT = static_cast<transferType>(data & TXDAT::RESERVED_MASK);
  }
  /**
   * @brief Read data from UART
   *
   * @param data reference to put received data in
   */
  constexpr void read(transferType &data) {
    data = static_cast<transferType>(usartPeripheral()->RXDAT);
  }
  /**
   * @brief Read data and status from UART
   *
   * @param data reference to put received data in
   * @param status reference to put received status in
   */
  constexpr void read(transferType &data, std::uint32_t &status) {
    std::uint32_t regData = usartPeripheral()->RXDATSTAT;
    data = static_cast<transferType>(regData & RXDATSTAT::DATA_MASK);
    status = regData & RXDATSTAT::STAT_MASK;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to usart registers
   */
  constexpr static hw::usart::peripheral *usartPeripheral() {
    return reinterpret_cast<hw::usart::peripheral *>(usartAddress);
  }

 private:
  static constexpr libMcu::hwAddressType usartAddress = usartAddress_; /**< peripheral usartAddress */
};
}  // namespace libMcuLL::sw::usart
#endif