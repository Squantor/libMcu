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

namespace libmcull::sw::usart {
namespace detail {

enum class synchonousStates : std::uint8_t {
  IDLE,        /*!< Interface is idle, ready to be claimed */
  CLAIMED,     /*!< Interface is claimed, ready to transact */
  TRANSACTING, /*!< Interface is busy with a transaction */
};

}  // namespace detail
using namespace libmcuhw::usart;

/**
 * @brief Asynchronous USART peripheral instance
 *
 * @tparam usartAddress_ Peripheral base address
 * @tparam transferType datatype to use for data transfers
 */
template <libmcu::uartBaseAddress usartAddress_, typename transferType>
struct usartAsync : libmcu::PeripheralBase {
  /**
   * @brief Construct a new usart Async object
   *
   * Initializes the internal state to defaults
   *
   */
  usartAsync() : transactionWriteState{detail::synchonousStates::IDLE}, transactionReadState{detail::synchonousStates::IDLE} {}
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
   * @brief Claim the Usart interface
   *
   * @return IN_USE when already in use
   * @return CLAIMED when the claim has been successful
   */
  constexpr libmcu::Results claim(void) {
    if ((transactionWriteState != detail::synchonousStates::IDLE) && (transactionReadState != detail::synchonousStates::IDLE)) {
      return libmcu::Results::IN_USE;
    }
    transactionWriteState = detail::synchonousStates::CLAIMED;
    transactionReadState = detail::synchonousStates::CLAIMED;
    return libmcu::Results::CLAIMED;
  }
  /**
   * @brief Unclaim the Usart interface
   *
   * @return ERROR when already idle or inconsistent, possible programming error!
   * @return BUSY when still executing a transaction
   * @return UNCLAIMED when unclaim sucessful
   */
  constexpr libmcu::Results unclaim(void) {
    if ((transactionWriteState == detail::synchonousStates::TRANSACTING) ||
        (transactionReadState == detail::synchonousStates::TRANSACTING)) {
      return libmcu::Results::BUSY;
    } else if ((transactionWriteState == detail::synchonousStates::CLAIMED) &&
               (transactionReadState == detail::synchonousStates::CLAIMED)) {
      transactionWriteState = detail::synchonousStates::IDLE;
      transactionReadState = detail::synchonousStates::IDLE;
      return libmcu::Results::UNCLAIMED;
    } else {
      return libmcu::Results::ERROR;
    }
  }
  /**
   * @brief Start a read transaction
   *
   * @param buffer buffer of data to read
   * @return ERROR if not claimed interface or busy
   * @return STARTED when transaction started
   */
  constexpr libmcu::Results startRead(std::span<transferType> buffer) {
    if (transactionReadState != detail::synchonousStates::CLAIMED) {
      return libmcu::Results::ERROR;
    }
    // store transaction information
    transactionReadIndex = 0u;
    transactionReadData = buffer;
    transactionReadState = detail::synchonousStates::TRANSACTING;
    return libmcu::Results::STARTED;
  }
  /**
   * @brief Start a write transaction
   *
   * @param buffer buffer of data to read
   * @return ERROR if not claimed interface or busy
   * @return STARTED when transaction started
   */
  constexpr libmcu::Results startWrite(std::span<transferType> buffer) {
    if (transactionWriteState != detail::synchonousStates::CLAIMED) {
      return libmcu::Results::ERROR;
    }
    // store transaction information
    transactionWriteIndex = 0u;
    transactionWriteData = buffer;
    transactionWriteState = detail::synchonousStates::TRANSACTING;
    // TODO write first data in UART register
    return libmcu::Results::STARTED;
  }
  /**
   * @brief continue started read transaction
   *
   * @return ERROR if transaction has not started
   * @return BUSY if transaction is still in progress
   * @return DONE if transaction is done and buffer filled with data
   */
  constexpr libmcu::Results progressRead(void) {
    if (transactionReadState != detail::synchonousStates::TRANSACTING) {
      return libmcu::Results::ERROR;
    }
    if (usartPeripheral()->STAT & STAT::kRXRDY) {
      transactionReadData[transactionReadIndex] = static_cast<transferType>(usartPeripheral()->RXDAT);
      transactionReadIndex++;
      if (transactionReadData.size() == transactionReadIndex) {
        transactionReadState = detail::synchonousStates::CLAIMED;
        return libmcu::Results::DONE;
      }
    }
    return libmcu::Results::BUSY;
  }
  /**
   * @brief continue started write transaction
   *
   * @return ERROR if transaction has not started
   * @return BUSY if transaction is still in progress
   * @return DONE if transaction is done and buffer of data has been written
   */
  constexpr libmcu::Results progressWrite(void) {
    if (transactionWriteState != detail::synchonousStates::TRANSACTING) {
      return libmcu::Results::ERROR;
    }
    std::uint32_t status = usartPeripheral()->STAT;
    if (status & STAT::kTXRDY) {
      if (transactionWriteData.size() > transactionWriteIndex) {
        usartPeripheral()->TXDAT = static_cast<std::uint32_t>(transactionWriteData[transactionWriteIndex]);
        transactionWriteIndex++;
      } else {
        if (status & STAT::kTXIDLE) {
          transactionWriteState = detail::synchonousStates::CLAIMED;
          return libmcu::Results::DONE;
        }
      }
    }
    return libmcu::Results::BUSY;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to usart registers
   */
  static libmcuhw::usart::Usart *usartPeripheral() {
    return reinterpret_cast<libmcuhw::usart::Usart *>(usartAddress);
  }

 private:
  static constexpr libmcu::hwAddressType usartAddress = usartAddress_; /*!< peripheral address */
  detail::synchonousStates transactionWriteState;                      /*!< usart write transaction state */
  detail::synchonousStates transactionReadState;                       /*!< usart read transaction state */
  std::size_t transactionWriteIndex;                                   /*!< transaction write buffer index */
  std::size_t transactionReadIndex;                                    /*!< transaction read buffer index */
  std::span<transferType> transactionWriteData;                        /*!< data to write */
  std::span<transferType> transactionReadData;                         /*!< where to put read data in */
};
}  // namespace libmcull::sw::usart
#endif