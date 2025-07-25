/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_usart_async_ll.hpp
 * @brief LPC810 series asynchronous USART interface class and definitions
 * @todo depricate async polling interfaces
 */
#ifndef LPC81X_USART_ASYNC_LL_HPP
#define LPC81X_USART_ASYNC_LL_HPP

#include "LPC81X_usart_common_ll.hpp"

namespace libmcull::usart {

namespace hardware = libmcuhw::usart;

/**
 * @brief Asynchronous USART peripheral instance
 * @tparam usart_address Peripheral base address
 * @tparam TransferType datatype to use for data transfers
 */
template <libmcu::UartBaseAddress usart_address, typename TransferType>
struct UsartAsync : libmcull::AsyncUartBase {
  /**
   * @brief Construct a new usart Async object
   * Initializes the internal state to defaults
   */
  UsartAsync()
    : transaction_write_state_{libmcu::AsynchronousStates::Idle}, transaction_read_state_{libmcu::AsynchronousStates::Idle} {}
  /**
   * @brief Setup USART to 8n1
   * @param baudRate Baud rate value
   * @return std::uint32_t actual baud rate
   */
  constexpr std::uint32_t Init(std::uint32_t baudRate) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    GetPeripheral()->BRG = baudDivider;
    GetPeripheral()->CFG = hardware::CFG::ENABLE | UartLengths::Size8 | UartParities::ParityNone | UartStops::Stop1;
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
    GetPeripheral()->CFG = hardware::CFG::ENABLE | lengthBits | parity | stopBits;
    return CLOCK_MAIN / 16 / baudDivider;
  }
  /**
   * @brief Claim the Usart interface
   * @return InUse when already in use
   * @return Claimed when the claim has been successful
   */
  constexpr libmcu::Results Claim(void) {
    if ((transaction_write_state_ != libmcu::AsynchronousStates::Idle) &&
        (transaction_read_state_ != libmcu::AsynchronousStates::Idle)) {
      return libmcu::Results::InUse;
    }
    transaction_write_state_ = libmcu::AsynchronousStates::Claimed;
    transaction_read_state_ = libmcu::AsynchronousStates::Claimed;
    return libmcu::Results::Claimed;
  }
  /**
   * @brief Unclaim the Usart interface
   * @returns Error when already idle or inconsistent, possible programming error!
   * @returns Busy when still executing a transaction
   * @returns Unclaimed when unclaim sucessful
   */
  constexpr libmcu::Results Unclaim(void) {
    if ((transaction_write_state_ == libmcu::AsynchronousStates::Busy) ||
        (transaction_read_state_ == libmcu::AsynchronousStates::Busy)) {
      return libmcu::Results::Busy;
    } else if ((transaction_write_state_ == libmcu::AsynchronousStates::Claimed) &&
               (transaction_read_state_ == libmcu::AsynchronousStates::Claimed)) {
      transaction_write_state_ = libmcu::AsynchronousStates::Idle;
      transaction_read_state_ = libmcu::AsynchronousStates::Idle;
      return libmcu::Results::Unclaimed;
    } else {
      return libmcu::Results::Error;
    }
  }
  /**
   * @brief Start a receive operation
   * @param buffer buffer of data to read, needs to be accessible while out of scope
   * @return Error if not claimed interface or busy
   * @return Started when transaction started
   */
  constexpr libmcu::Results Receive(std::span<TransferType> buffer) {
    if (transaction_read_state_ != libmcu::AsynchronousStates::Claimed) {
      return libmcu::Results::Error;
    }
    // store transaction information
    transaction_read_index_ = 0u;
    transaction_read_data_ = buffer;
    transaction_read_state_ = libmcu::AsynchronousStates::Busy;
    return libmcu::Results::Started;
  }
  /**
   * @brief Start a transmit operation
   * @param buffer buffer of data to read, needs to be accessible while out of scope
   * @return Error if not claimed interface or busy
   * @return Started when transaction started
   */
  constexpr libmcu::Results Transmit(std::span<TransferType> buffer) {
    if (transaction_write_state_ != libmcu::AsynchronousStates::Claimed) {
      return libmcu::Results::Error;
    }
    // store transaction information
    transaction_write_index_ = 0u;
    transaction_write_data_ = buffer;
    transaction_write_state_ = libmcu::AsynchronousStates::Busy;
    // TODO write first data in UART register
    return libmcu::Results::Started;
  }
  /**
   * @brief continue receive operation
   * @return Error if transaction has not started
   * @return Busy if transaction is still in progress
   * @return Done if transaction is done and buffer filled with data
   */
  constexpr libmcu::Results ProgressReceive(void) {
    if (transaction_read_state_ != libmcu::AsynchronousStates::Busy) {
      return libmcu::Results::Error;
    }
    if (GetPeripheral()->STAT & hardware::STAT::RXRDY) {
      transaction_read_data_[transaction_read_index_] = static_cast<TransferType>(GetPeripheral()->RXDAT);
      transaction_read_index_++;
      if (transaction_read_data_.size() == transaction_read_index_) {
        transaction_read_state_ = libmcu::AsynchronousStates::Claimed;
        return libmcu::Results::Done;
      }
    }
    return libmcu::Results::Busy;
  }
  /**
   * @brief continue transmission operation
   * @return Error if transaction has not started
   * @return Busy if transaction is still in progress
   * @return Done if transaction is done and buffer of data has been written
   */
  constexpr libmcu::Results ProgressTransmit(void) {
    if (transaction_write_state_ != libmcu::AsynchronousStates::Busy) {
      return libmcu::Results::Error;
    }
    std::uint32_t status = GetPeripheral()->STAT;
    if (status & hardware::STAT::TXRDY) {
      if (transaction_write_data_.size() > transaction_write_index_) {
        GetPeripheral()->TXDAT = static_cast<std::uint32_t>(transaction_write_data_[transaction_write_index_]);
        transaction_write_index_++;
      } else {
        if (status & hardware::STAT::TXIDLE) {
          transaction_write_state_ = libmcu::AsynchronousStates::Claimed;
          return libmcu::Results::Done;
        }
      }
    }
    return libmcu::Results::Busy;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to usart registers
   */
  static libmcuhw::usart::Usart *GetPeripheral() {
    return reinterpret_cast<libmcuhw::usart::Usart *>(usartAddress);
  }

 private:
  static constexpr libmcu::HwAddressType usartAddress = usart_address; /*!< peripheral address */
  libmcu::AsynchronousStates transaction_write_state_;                 /*!< usart write transaction state */
  libmcu::AsynchronousStates transaction_read_state_;                  /*!< usart read transaction state */
  std::size_t transaction_write_index_;                                /*!< transaction write buffer index */
  std::size_t transaction_read_index_;                                 /*!< transaction read buffer index */
  std::span<TransferType> transaction_write_data_;                     /*!< data to write */
  std::span<TransferType> transaction_read_data_;                      /*!< where to put read data in */
};
}  // namespace libmcull::usart
#endif