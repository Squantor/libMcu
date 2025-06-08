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
namespace hardware = libmcuhw::usart;

/**
 * @brief synchronous USART peripheral instance
 * @tparam usart_address Peripheral base address
 * @tparam transferType datatype to use for data transfers
 */
template <libmcu::UartBaseAddress usart_address, typename TransferType>
struct usartSync : libmcull::PeripheralBase {
  /**
   * @brief Setup USART to 8n1
   * @param baudRate Baud rate value
   * @return std::uint32_t actual baud rate
   */
  constexpr std::uint32_t Init(std::uint32_t baudRate) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    GetPeripheral()->BRG = baudDivider;
    GetPeripheral()->CFG = hardware::CFG::kENABLE | UartLengths::kSize8 | UartParities::kParityNone | UartStops::kStop1;
    return CLOCK_MAIN / 16 / baudDivider;
  }
  /**
   * @brief Setup USART
   * @param baudRate Baud rate value
   * @param lengthBits bit length of transmissions, see uartLength enum for options
   * @param parity parity type of transmissions, see uartParity enum for options
   * @param stopBits Amount of stop bits, see uartStop enum for options
   * @return std::uint32_t actual baud rate
   */
  constexpr std::uint32_t Init(std::uint32_t baudRate, UartLengths lengthBits, UartParities parity, UartStops stopBits) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    GetPeripheral()->BRG = baudDivider;
    GetPeripheral()->CFG = hardware::CFG::kENABLE | lengthBits | parity | stopBits;
    return CLOCK_MAIN / 16 / baudDivider;
  }
  /**
   * @brief return uart status
   * @return std::uint32_t one to one copy of the status register, see bit masks for options
   */
  constexpr std::uint32_t Status() {
    return GetPeripheral()->STAT & hardware::STAT::kRESERVED_MASK;
  }
  /**
   * @brief Send data out of the UART
   * @param data data to send, amount is sent according to configuration
   */
  constexpr void Transmit(TransferType data) {
    GetPeripheral()->TXDAT = static_cast<TransferType>(data & hardware::TXDAT::kRESERVED_MASK);
  }
  /**
   * @brief Read data from UART
   * @param data reference to put received data in
   */
  constexpr void Receive(TransferType &data) {
    data = static_cast<TransferType>(GetPeripheral()->RXDAT);
  }
  /**
   * @brief Read data and status from UART
   * @param data reference to put received data in
   * @param status reference to put received status in
   */
  constexpr void Receive(TransferType &data, std::uint32_t &status) {
    std::uint32_t regData = GetPeripheral()->RXDATSTAT;
    data = static_cast<TransferType>(regData & hardware::RXDATSTAT::kDATA_MASK);
    status = regData & hardware::RXDATSTAT::kSTAT_MASK;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to usart registers
   */
  constexpr static libmcuhw::usart::Usart *GetPeripheral() {
    return reinterpret_cast<libmcuhw::usart::Usart *>(usart_address_);
  }

 private:
  static constexpr libmcu::HwAddressType usart_address_ = usart_address; /*!< peripheral usart_address_ */
};
}  // namespace libmcull::usart
#endif