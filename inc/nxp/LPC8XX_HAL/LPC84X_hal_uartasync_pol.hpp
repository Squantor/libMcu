/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series polling asynchronous UART HAL
 */
#ifndef LPC84X_HAL_UARTASYNC_POL_HPP
#define LPC84X_HAL_UARTASYNC_POL_HPP

#include "LPC84X_hal_uart_common.hpp"

namespace libMcuHal::usart {
namespace hardware = libMcuHw::usart;

template <libMcu::uartBaseAddress const& uartBaseAddress_, typename transferType>
struct uartAsync {
  /**
   * @brief Construct a new asynchronous uart
   */
  uartAsync() : transactionWriteState{detail::synchonousStates::IDLE}, transactionReadState{detail::synchonousStates::IDLE} {}
  /**
   * @brief Initialize
   */
  void initialize() {}
  /**
   * @brief Setup USART to 8n1
   * @param baudRate Baud rate value
   * @return std::uint32_t actual baud rate
   */
  template <auto& config>
  constexpr std::uint32_t init(std::uint32_t baudRate) {
    std::uint32_t baudDivider = getInputClockFreq<config>() / (baudRate * 16);
    usartPeripheral()->BRG = baudDivider;
    usartPeripheral()->CFG = hardware::CFG::ENABLE | static_cast<std::uint32_t>(uartLength::SIZE_8) |
                             static_cast<std::uint32_t>(uartParity::NONE) | static_cast<std::uint32_t>(uartStop::STOP_1);
    return getInputClockFreq<config>() / 16 / baudDivider;
  }
  /**
   * @brief Setup USART
   * @param baudRate Baud rate value
   * @param lengthBits bit length of transmissions, see uartLength enum for options
   * @param parity parity type of transmissions, see uartParity enum for options
   * @param stopBits Amount of stop bits, see uartStop enum for options
   * @return std::uint32_t actual baud rate
   */
  template <auto& config>
  constexpr std::uint32_t init(std::uint32_t baudRate, uartLength lengthBits, uartParity parity, uartStop stopBits) {
    std::uint32_t baudDivider = getInputClockFreq<config>() / (baudRate * 16);
    usartPeripheral()->BRG = baudDivider;
    usartPeripheral()->CFG = hardware::CFG::ENABLE | static_cast<std::uint32_t>(lengthBits) | static_cast<std::uint32_t>(parity) |
                             static_cast<std::uint32_t>(stopBits);
    return getInputClockFreq<config>() / 16 / baudDivider;
  }
  /**
   * @brief Claim the Usart interface
   * @return IN_USE when already in use
   * @return CLAIMED when the claim has been successful
   */
  constexpr libMcu::results claim(void) {
    if ((transactionWriteState != detail::synchonousStates::IDLE) && (transactionReadState != detail::synchonousStates::IDLE)) {
      return libMcu::results::IN_USE;
    }
    transactionWriteState = detail::synchonousStates::CLAIMED;
    transactionReadState = detail::synchonousStates::CLAIMED;
    return libMcu::results::CLAIMED;
  }
  /**
   * @brief Unclaim the Usart interface
   * @return ERROR when already idle or inconsistent, possible programming error!
   * @return BUSY when still executing a transaction
   * @return UNCLAIMED when unclaim sucessful
   */
  constexpr libMcu::results unclaim(void) {
    if ((transactionWriteState == detail::synchonousStates::TRANSACTING) ||
        (transactionReadState == detail::synchonousStates::TRANSACTING)) {
      return libMcu::results::BUSY;
    } else if ((transactionWriteState == detail::synchonousStates::CLAIMED) &&
               (transactionReadState == detail::synchonousStates::CLAIMED)) {
      transactionWriteState = detail::synchonousStates::IDLE;
      transactionReadState = detail::synchonousStates::IDLE;
      return libMcu::results::UNCLAIMED;
    } else {
      return libMcu::results::ERROR;
    }
  }
  /**
   * @brief Start a read transaction
   * @param buffer buffer of data to read
   * @return ERROR if not claimed interface or busy
   * @return STARTED when transaction started
   */
  constexpr libMcu::results startRead(std::span<transferType> buffer) {
    if (transactionReadState != detail::synchonousStates::CLAIMED) {
      return libMcu::results::ERROR;
    }
    // store transaction information
    transactionReadIndex = 0u;
    transactionReadData = buffer;
    transactionReadState = detail::synchonousStates::TRANSACTING;
    return libMcu::results::STARTED;
  }
  /**
   * @brief Start a write transaction
   * @param buffer buffer of data to read
   * @return ERROR if not claimed interface or busy
   * @return STARTED when transaction started
   */
  constexpr libMcu::results startWrite(std::span<transferType> buffer) {
    if (transactionWriteState != detail::synchonousStates::CLAIMED) {
      return libMcu::results::ERROR;
    }
    // store transaction information
    transactionWriteIndex = 0u;
    transactionWriteData = buffer;
    transactionWriteState = detail::synchonousStates::TRANSACTING;
    // TODO write first data in UART register
    return libMcu::results::STARTED;
  }
  /**
   * @brief continue started read transaction
   * @return ERROR if transaction has not started
   * @return BUSY if transaction is still in progress
   * @return DONE if transaction is done and buffer filled with data
   */
  constexpr libMcu::results progressRead(void) {
    if (transactionReadState != detail::synchonousStates::TRANSACTING) {
      return libMcu::results::ERROR;
    }
    if (usartPeripheral()->STAT & hardware::STAT::RXRDY) {
      transactionReadData[transactionReadIndex] = static_cast<transferType>(usartPeripheral()->RXDAT);
      transactionReadIndex++;
      if (transactionReadData.size() == transactionReadIndex) {
        transactionReadState = detail::synchonousStates::CLAIMED;
        return libMcu::results::DONE;
      }
    }
    return libMcu::results::BUSY;
  }
  /**
   * @brief continue started write transaction
   * @return ERROR if transaction has not started
   * @return BUSY if transaction is still in progress
   * @return DONE if transaction is done and buffer of data has been written
   */
  constexpr libMcu::results progressWrite(void) {
    if (transactionWriteState != detail::synchonousStates::TRANSACTING) {
      return libMcu::results::ERROR;
    }
    std::uint32_t status = usartPeripheral()->STAT;
    if (status & hardware::STAT::TXRDY) {
      if (transactionWriteData.size() > transactionWriteIndex) {
        usartPeripheral()->TXDAT = static_cast<std::uint32_t>(transactionWriteData[transactionWriteIndex]);
        transactionWriteIndex++;
      } else {
        if (status & hardware::STAT::TXIDLE) {
          transactionWriteState = detail::synchonousStates::CLAIMED;
          return libMcu::results::DONE;
        }
      }
    }
    return libMcu::results::BUSY;
  }
  /**
   * @brief get the input clock of this UART peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <auto& config>
  constexpr std::uint32_t getInputClockFreq() {
    if constexpr (uartBaseAddress == libMcuHw::usart0Address) {
      if constexpr (config.uart0Source == libMcuHw::clock::periSource::MAIN) {
        return config.mainFreq;
      } else
        static_assert(false, "unsupported peripheral source!");
    } else if constexpr (uartBaseAddress == libMcuHw::usart1Address) {
      if constexpr (config.uart1Source == libMcuHw::clock::periSource::MAIN) {
        return config.mainFreq;
      } else
        static_assert(false, "unsupported peripheral source!");
    } else if constexpr (uartBaseAddress == libMcuHw::usart2Address) {
      if constexpr (config.uart2Source == libMcuHw::clock::periSource::MAIN) {
        return config.mainFreq;
      } else
        static_assert(false, "unsupported peripheral source!");
    } else if constexpr (uartBaseAddress == libMcuHw::usart3Address) {
      if constexpr (config.uart3Source == libMcuHw::clock::periSource::MAIN) {
        return config.mainFreq;
      } else
        static_assert(false, "unsupported peripheral source!");
    } else
      static_assert(false, "Unknown UART address!");
    return 0;
  }

 private:
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::usart* usartPeripheral() {
    return reinterpret_cast<hardware::usart*>(uartBaseAddress);
  }

  static constexpr libMcu::hwAddressBase uartBaseAddress = uartBaseAddress_; /**< uart peripheral address */
  detail::synchonousStates transactionWriteState;                            /**< usart write transaction state */
  detail::synchonousStates transactionReadState;                             /**< usart read transaction state */
  std::size_t transactionWriteIndex;                                         /**< transaction write buffer index */
  std::size_t transactionReadIndex;                                          /**< transaction read buffer index */
  std::span<transferType> transactionWriteData;                              /**< data to write */
  std::span<transferType> transactionReadData;                               /**< where to put read data in */
};
}  // namespace libMcuHal::usart

#endif