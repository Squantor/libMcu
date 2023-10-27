/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series asynchronous USART functions
 */
#ifndef LPC81X_USART_ASYNC_HPP
#define LPC81X_USART_ASYNC_HPP

#include "nxp/LPC8XX.hpp/LPC81X_usart_common.hpp"

namespace libMcuLL {
namespace sw {
namespace usart {
namespace detail {

enum class synchonousStates : std::uint8_t {
  IDLE,        /**< Interface is idle, ready to be claimed */
  CLAIMED,     /**< Interface is claimed, ready to transact */
  TRANSACTING, /**< Interface is busy with a transaction */
};

}
using namespace hw::usart;

template <libMcuLL::USARTbaseAddress address_>
struct usartAsync {
  /**
   * @brief Construct a new usart Async object
   *
   * Initializes the internal state to defaults
   *
   */
  usartAsync() : transactionWriteState{detail::synchonousStates::IDLE}, transactionReadState{detail::synchonousStates::IDLE} {}

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
   * @brief Claim the Usart interface
   *
   * @return IN_USE when already in use
   * @return CLAIMED when the claim has been successful
   */
  libMcuLL::results claim(void) {
    if ((transactionWriteState != detail::synchonousStates::IDLE) && (transactionReadState != detail::synchonousStates::IDLE)) {
      return libMcuLL::results::IN_USE;
    }
    transactionWriteState = detail::synchonousStates::CLAIMED;
    transactionReadState = detail::synchonousStates::CLAIMED;
    return libMcuLL::results::CLAIMED;
  }

  /**
   * @brief Unclaim the Usart interface
   *
   * @return ERROR when already idle or inconsistent, possible programming error!
   * @return BUSY when still executing a transaction
   * @return UNCLAIMED when unclaim sucessful
   */
  libMcuLL::results unclaim(void) {
    if ((transactionWriteState == detail::synchonousStates::TRANSACTING) ||
        (transactionReadState == detail::synchonousStates::TRANSACTING)) {
      return libMcuLL::results::BUSY;
    } else if ((transactionWriteState == detail::synchonousStates::CLAIMED) &&
               (transactionReadState == detail::synchonousStates::CLAIMED)) {
      transactionWriteState = detail::synchonousStates::IDLE;
      transactionReadState = detail::synchonousStates::IDLE;
      return libMcuLL::results::UNCLAIMED;
    } else {
      return libMcuLL::results::ERROR;
    }
  }

  /**
   * @brief Start a read transaction
   *
   * @param buffer buffer of data to read
   * @return libMcuLL::results::ERROR if not claimed interface or busy
   * @return libMcuLL::results::STARTED when transaction started
   */
  libMcuLL::results startRead(std::span<std::uint16_t> buffer) {
    if (transactionReadState != detail::synchonousStates::CLAIMED) {
      return libMcuLL::results::ERROR;
    }
    // store transaction information
    transactionReadIndex = 0;
    transactionReadData = buffer;
    transactionReadState = detail::synchonousStates::TRANSACTING;
    return libMcuLL::results::STARTED;
  }

  /**
   * @brief Start a write transaction
   *
   * @param buffer buffer of data to read
   * @return libMcuLL::results::ERROR if not claimed interface or busy
   * @return libMcuLL::results::STARTED when transaction started
   */
  libMcuLL::results startWrite(std::span<std::uint16_t> buffer) {
    if (transactionWriteState != detail::synchonousStates::CLAIMED) {
      return libMcuLL::results::ERROR;
    }
    // store transaction information
    transactionWriteIndex = 0;
    transactionWriteData = buffer;
    transactionWriteState = detail::synchonousStates::TRANSACTING;
    // TODO write first data in UART register
    return libMcuLL::results::STARTED;
  }

  // TODO: progressRead/progressWrite
 private:
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  detail::synchonousStates transactionWriteState;              /**< usart write transaction state */
  detail::synchonousStates transactionReadState;               /**< usart read transaction state */
  std::size_t transactionWriteIndex;                           /**< transaction write buffer index */
  std::size_t transactionReadIndex;                            /**< transaction read buffer index */
  std::span<std::uint16_t> transactionWriteData;               /**< data to write */
  std::span<std::uint16_t> transactionReadData;                /**< where to put read data in */
};
}  // namespace usart
}  // namespace sw
}  // namespace libMcuLL

#endif