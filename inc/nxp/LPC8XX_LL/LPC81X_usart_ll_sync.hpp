/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_usart_ll_sync.hpp
 * @brief LPC810 series synchronous USART interface class and definitions
 */
#ifndef LPC81X_USART_HPP
#define LPC81X_USART_HPP

#include "LPC81X_usart_ll_common.hpp"

namespace libmcull::usart {
using namespace libmcuhw::usart;

/**
 * @brief synchronous USART peripheral instance
 *
 * @tparam usartAddress_ Peripheral base usartAddress
 * @tparam transferType datatype to use for data transfers
 */
template <libmcu::UartBaseAddress usartAddress_, typename TransferType>
struct usartSync : libmcu::PeripheralBase {
  /**
   * @brief Setup USART to 8n1
   *
   * @param baudRate Baud rate value
   * @return std::uint32_t actual baud rate
   */
  constexpr std::uint32_t init(std::uint32_t baudRate) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    usartPeripheral()->BRG = baudDivider;
    usartPeripheral()->CFG = CFG::kENABLE | uartLength::SIZE_8 | uartParity::NONE | uartStop::STOP_1;
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
    usartPeripheral()->CFG = CFG::kENABLE | lengthBits | parity | stopBits;
    return CLOCK_MAIN / 16 / baudDivider;
  }
  /**
   * @brief return uart status
   *
   * @return std::uint32_t one to one copy of the status register, see bit masks for options
   */
  constexpr std::uint32_t status() {
    return usartPeripheral()->STAT & STAT::kRESERVED_MASK;
  }
  /**
   * @brief Send data out of the UART
   *
   * @param data data to send, amount is sent according to configuration
   */
  constexpr void write(TransferType data) {
    usartPeripheral()->TXDAT = static_cast<TransferType>(data & TXDAT::kRESERVED_MASK);
  }
  /**
   * @brief Read data from UART
   *
   * @param data reference to put received data in
   */
  constexpr void read(TransferType &data) {
    data = static_cast<TransferType>(usartPeripheral()->RXDAT);
  }
  /**
   * @brief Read data and status from UART
   *
   * @param data reference to put received data in
   * @param status reference to put received status in
   */
  constexpr void read(TransferType &data, std::uint32_t &status) {
    std::uint32_t regData = usartPeripheral()->RXDATSTAT;
    data = static_cast<TransferType>(regData & RXDATSTAT::kDATA_MASK);
    status = regData & RXDATSTAT::kSTAT_MASK;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to usart registers
   */
  constexpr static libmcuhw::usart::Usart *usartPeripheral() {
    return reinterpret_cast<libmcuhw::usart::Usart *>(usartAddress);
  }

 private:
  static constexpr libmcu::HwAddressType usartAddress = usartAddress_; /*!< peripheral usartAddress */
};
}  // namespace libmcull::usart
#endif