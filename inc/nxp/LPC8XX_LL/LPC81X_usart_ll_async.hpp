/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_usart_ll_async.hpp
 * @brief LPC810 series asynchronous USART interface class and definitions
 */
#ifndef LPC81X_USART_ASYNC_HPP
#define LPC81X_USART_ASYNC_HPP

#include "LPC81X_usart_ll_common.hpp"

namespace libmcull::usart {

namespace hardware = libmcuhw::usart;

/**
 * @brief Asynchronous USART peripheral instance
 * @tparam usart_address Peripheral base address
 * @tparam TransferType datatype to use for data transfers
 */
template <libmcu::UartBaseAddress usart_address, typename TransferType>
struct UsartAsync : libmcu::PeripheralBase {
  /**
   * @brief Construct a new usart Async object
   * Initializes the internal state to defaults
   */
  UsartAsync()
    : transaction_write_state_{libmcu::AsynchronousStates::kIdle}, transaction_read_state_{libmcu::AsynchronousStates::kIdle} {}
  /**
   * @brief Setup USART to 8n1
   * @param baudRate Baud rate value
   * @return std::uint32_t actual baud rate
   */
  constexpr std::uint32_t Init(std::uint32_t baudRate) {
    std::uint32_t baudDivider = CLOCK_MAIN / (baudRate * 16);
    GetPeripheral()->BRG = baudDivider;
    GetPeripheral()->CFG = CFG::kENABLE | UartLengths::kSize8 | UartParities::kParityNone | UartStops::kStop1;
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
    GetPeripheral()->CFG = CFG::kENABLE | lengthBits | parity | stopBits;
    return CLOCK_MAIN / 16 / baudDivider;
  }
  /**
   * @brief Claim the Usart interface
   * @return kInUse when already in use
   * @return kClaimed when the claim has been successful
   */
  constexpr libmcu::Results Claim(void) {
    if ((transaction_write_state_ != libmcu::AsynchronousStates::kIdle) &&
        (transaction_read_state_ != libmcu::AsynchronousStates::kIdle)) {
      return libmcu::Results::kInUse;
    }
    transaction_write_state_ = libmcu::AsynchronousStates::kClaimed;
    transaction_read_state_ = libmcu::AsynchronousStates::kClaimed;
    return libmcu::Results::kClaimed;
  }
  /**
   * @brief Unclaim the Usart interface
   * @returns kError when already idle or inconsistent, possible programming error!
   * @returns kBusy when still executing a transaction
   * @returns kUnclaimed when unclaim sucessful
   */
  constexpr libmcu::Results Unclaim(void) {
    if ((transaction_write_state_ == libmcu::AsynchronousStates::kBusy) ||
        (transaction_read_state_ == libmcu::AsynchronousStates::kBusy)) {
      return libmcu::Results::kBusy;
    } else if ((transaction_write_state_ == libmcu::AsynchronousStates::kClaimed) &&
               (transaction_read_state_ == libmcu::AsynchronousStates::kClaimed)) {
      transaction_write_state_ = libmcu::AsynchronousStates::kIdle;
      transaction_read_state_ = libmcu::AsynchronousStates::kIdle;
      return libmcu::Results::kUnclaimed;
    } else {
      return libmcu::Results::kError;
    }
  }
  /**
   * @brief Start a receive operation
   * @param buffer buffer of data to read, needs to be accessible while out of scope
   * @return kError if not claimed interface or busy
   * @return kStarted when transaction started
   */
  constexpr libmcu::Results Receive(std::span<TransferType> buffer) {
    if (transaction_read_state_ != libmcu::AsynchronousStates::kClaimed) {
      return libmcu::Results::kError;
    }
    // store transaction information
    transaction_read_index_ = 0u;
    transaction_read_data_ = buffer;
    transaction_read_state_ = libmcu::AsynchronousStates::kBusy;
    return libmcu::Results::kStarted;
  }
  /**
   * @brief Start a transmit operation
   * @param buffer buffer of data to read, needs to be accessible while out of scope
   * @return kError if not claimed interface or busy
   * @return kStarted when transaction started
   */
  constexpr libmcu::Results Transmit(std::span<TransferType> buffer) {
    if (transaction_write_state_ != libmcu::AsynchronousStates::kClaimed) {
      return libmcu::Results::kError;
    }
    // store transaction information
    transaction_write_index_ = 0u;
    transaction_write_data_ = buffer;
    transaction_write_state_ = libmcu::AsynchronousStates::kBusy;
    // TODO write first data in UART register
    return libmcu::Results::kStarted;
  }
  /**
   * @brief continue receive operation
   * @return kError if transaction has not started
   * @return kBusy if transaction is still in progress
   * @return kDone if transaction is done and buffer filled with data
   */
  constexpr libmcu::Results ProgressReceive(void) {
    if (transaction_read_state_ != libmcu::AsynchronousStates::kBusy) {
      return libmcu::Results::kError;
    }
    if (GetPeripheral()->STAT & STAT::kRXRDY) {
      transaction_read_data_[transaction_read_index_] = static_cast<TransferType>(GetPeripheral()->RXDAT);
      transaction_read_index_++;
      if (transaction_read_data_.size() == transaction_read_index_) {
        transaction_read_state_ = libmcu::AsynchronousStates::kClaimed;
        return libmcu::Results::kDone;
      }
    }
    return libmcu::Results::kBusy;
  }
  /**
   * @brief continue transmission operation
   * @return kError if transaction has not started
   * @return kBusy if transaction is still in progress
   * @return kDone if transaction is done and buffer of data has been written
   */
  constexpr libmcu::Results ProgressTransmit(void) {
    if (transaction_write_state_ != libmcu::AsynchronousStates::kBusy) {
      return libmcu::Results::kError;
    }
    std::uint32_t status = GetPeripheral()->STAT;
    if (status & STAT::kTXRDY) {
      if (transaction_write_data_.size() > transaction_write_index_) {
        GetPeripheral()->TXDAT = static_cast<std::uint32_t>(transaction_write_data_[transaction_write_index_]);
        transaction_write_index_++;
      } else {
        if (status & STAT::kTXIDLE) {
          transaction_write_state_ = libmcu::AsynchronousStates::kClaimed;
          return libmcu::Results::kDone;
        }
      }
    }
    return libmcu::Results::kBusy;
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