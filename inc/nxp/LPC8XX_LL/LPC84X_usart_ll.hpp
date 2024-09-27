/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series USART functions
 */
#ifndef LPC84X_USART_HPP
#define LPC84X_USART_HPP

namespace libMcuLL::usart {
namespace hardware = libMcuHw::usart;
/**
 * @brief amount of bits to transmit
 */
enum class uartLength : std::uint32_t {
  SIZE_7 = hardware::CFG::DATALEN7BIT, /**< USART transmit length of 7 bits */
  SIZE_8 = hardware::CFG::DATALEN8BIT, /**< USART transmit length of 8 bits */
  SIZE_9 = hardware::CFG::DATALEN9BIT, /**< USART transmit length of 9 bits */
};

/**
 * @brief Parity bit options
 */
enum class uartParity : std::uint32_t {
  NONE = hardware::CFG::PARITY_NONE, /**< No parity */
  EVEN = hardware::CFG::PARITY_EVEN, /**< Even parity */
  ODD = hardware::CFG::PARITY_ODD,   /**< Odd parity */
};

/**
 * @brief stop bit options
 */
enum class uartStop : std::uint32_t {
  STOP_1 = hardware::CFG::STOPBIT1, /**< 1 stop bit */
  STOP_2 = hardware::CFG::STOPBIT2, /**< 2 stop bits */
};

/**
 * @brief Uart status bits
 *
 * These bit patterns match the USART STAT register settings
 */
enum uartStatus : std::uint32_t {
  RXRDY = hardware::STAT::RXRDY,               /**< Receiver ready flag, Read only */
  RXIDLE = hardware::STAT::RXIDLE,             /**< Receiver idle, Read only */
  TXRDY = hardware::STAT::TXRDY,               /**< Transmitter ready, Read only  */
  TXIDLE = hardware::STAT::TXIDLE,             /**< Transmitter idle, Read only */
  CTS = hardware::STAT::CTS,                   /**< CTS signal state, Read only */
  DELTACTS = hardware::STAT::DELTACTS,         /**< Change detected in CTS signal, write 1 clear */
  TXDISINT = hardware::STAT::TXDISINT,         /**< Transmitter disabled confirmation, read only  */
  OVERRUNINT = hardware::STAT::OVERRUNINT,     /**< Overrun error interrupt flag, write 1 clear */
  RXBRK = hardware::STAT::RXBRK,               /**< Received break, read only */
  DELTARXBRK = hardware::STAT::DELTARXBRK,     /**< Change detected in receiver break, write 1 clear */
  START = hardware::STAT::START,               /**< Start condition detected, write 1 clear */
  FRAMERRINT = hardware::STAT::FRAMERRINT,     /**< Frame error interrupt flag, write 1 clear */
  PARITYERRINT = hardware::STAT::PARITYERRINT, /**< Parity error interrupt flag, write 1 clear */
  RXNOISEINT = hardware::STAT::RXNOISEINT,     /**< Recieved noise interrupt flag, write 1 clear*/
  ABERR = hardware::STAT::ABERR,               /**< Autobaud error flag, write 1 clears */
};

/**
 * @brief synchronous USART peripheral instance
 * @tparam usartAddress_ Peripheral base usartAddress
 * @tparam transferType datatype to use for data transfers
 */
template <libMcu::uartBaseAddress usartAddress_, typename transferType>
struct usart : libMcu::peripheralBase {
  /**
   * @brief Setup USART to 8n1
   * @param baudRate Baud rate value
   * @return std::uint32_t actual baud rate
   */
  constexpr std::uint32_t init(std::uint32_t baudRate) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    usartPeripheral()->BRG = baudDivider;
    usartPeripheral()->CFG = hardware::CFG::ENABLE | static_cast<std::uint32_t>(uartLength::SIZE_8) |
                             static_cast<std::uint32_t>(uartParity::NONE) | static_cast<std::uint32_t>(uartStop::STOP_1);
    return CLOCK_MAIN / 16u / baudDivider;
  }
  /**
   * @brief Setup USART
   * @param baudRate Baud rate value
   * @param lengthBits bit length of transmissions, see uartLength enum for options
   * @param parity parity type of transmissions, see uartParity enum for options
   * @param stopBits Amount of stop bits, see uartStop enum for options
   * @return std::uint32_t actual baud rate
   */
  constexpr std::uint32_t init(std::uint32_t baudRate, uartLength lengthBits, uartParity parity, uartStop stopBits) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    usartPeripheral()->BRG = baudDivider;
    usartPeripheral()->CFG = hardware::CFG::ENABLE | static_cast<std::uint32_t>(lengthBits) | static_cast<std::uint32_t>(parity) |
                             static_cast<std::uint32_t>(stopBits);
    return CLOCK_MAIN / 16 / baudDivider;
  }
  /**
   * @brief return uart status
   * @return std::uint32_t one to one copy of the status register, see bit masks for options
   */
  constexpr std::uint32_t status() {
    return usartPeripheral()->STAT & hardware::STAT::RESERVED_MASK;
  }
  /**
   * @brief Send data out of the UART
   * @param data data to send, amount is sent according to configuration
   */
  constexpr void write(transferType data) {
    usartPeripheral()->TXDAT = static_cast<transferType>(data & hardware::TXDAT::RESERVED_MASK);
  }
  /**
   * @brief Read data from UART
   * @param data reference to put received data in
   */
  constexpr void read(transferType &data) {
    data = static_cast<transferType>(usartPeripheral()->RXDAT);
  }
  /**
   * @brief Read data and status from UART
   * @param data reference to put received data in
   * @param status reference to put received status in
   */
  constexpr void read(transferType &data, std::uint32_t &status) {
    std::uint32_t regData = usartPeripheral()->RXDATSTAT;
    data = static_cast<transferType>(regData & hardware::RXDATSTAT::DATA_MASK);
    status = regData & hardware::RXDATSTAT::STAT_MASK;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to usart registers
   */
  constexpr static hardware::usart *usartPeripheral() {
    return reinterpret_cast<hardware::usart *>(usartAddress);
  }

 private:
  static constexpr libMcu::hwAddressType usartAddress = usartAddress_; /**< peripheral usartAddress */
};
}  // namespace libMcuLL::usart
#endif