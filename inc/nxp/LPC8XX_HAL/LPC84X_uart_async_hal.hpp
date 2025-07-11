/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_hal_uartasync_pol.hpp
 * @brief LPC840 series asynchronous polling UART HAL
 * @todo depricate async polling interfaces
 */
#ifndef LPC84X_HAL_UARTASYNC_POL_HPP
#define LPC84X_HAL_UARTASYNC_POL_HPP

#include "LPC84X_hal_uart_common.hpp"

namespace libmcuhal::usart {
namespace hardware = libmcuhw::usart;

template <libmcu::UartBaseAddress const& uartBaseAddress_, typename TransferType>
struct UartAsync {
  /**
   * @brief Construct a new asynchronous uart
   */
  UartAsync() : transactionWriteState{detail::synchonousStates::IDLE}, transactionReadState{detail::synchonousStates::IDLE} {}
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
    std::uint32_t baudDivider = GetInputClockFreq<config>() / (baudRate * 16);
    usartPeripheral()->BRG = baudDivider;
    usartPeripheral()->CFG = hardware::CFG::ENABLE | static_cast<std::uint32_t>(uartLength::SIZE_8) |
                             static_cast<std::uint32_t>(uartParity::NONE) | static_cast<std::uint32_t>(uartStop::STOP_1);
    return GetInputClockFreq<config>() / 16 / baudDivider;
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
    std::uint32_t baudDivider = GetInputClockFreq<config>() / (baudRate * 16);
    usartPeripheral()->BRG = baudDivider;
    usartPeripheral()->CFG = hardware::CFG::ENABLE | static_cast<std::uint32_t>(lengthBits) | static_cast<std::uint32_t>(parity) |
                             static_cast<std::uint32_t>(stopBits);
    return GetInputClockFreq<config>() / 16 / baudDivider;
  }
  /**
   * @brief Claim the Usart interface
   * @return InUse when already in use
   * @return CLAIMED when the claim has been successful
   */
  constexpr libmcu::Results claim(void) {
    if ((transactionWriteState != detail::synchonousStates::IDLE) && (transactionReadState != detail::synchonousStates::IDLE)) {
      return libmcu::Results::InUse;
    }
    transactionWriteState = detail::synchonousStates::CLAIMED;
    transactionReadState = detail::synchonousStates::CLAIMED;
    return libmcu::Results::CLAIMED;
  }
  /**
   * @brief Unclaim the Usart interface
   * @return Error when already idle or inconsistent, possible programming error!
   * @return Busy when still executing a transaction
   * @return UNCLAIMED when unclaim sucessful
   */
  constexpr libmcu::Results unclaim(void) {
    if ((transactionWriteState == detail::synchonousStates::TRANSACTING) ||
        (transactionReadState == detail::synchonousStates::TRANSACTING)) {
      return libmcu::Results::Busy;
    } else if ((transactionWriteState == detail::synchonousStates::CLAIMED) &&
               (transactionReadState == detail::synchonousStates::CLAIMED)) {
      transactionWriteState = detail::synchonousStates::IDLE;
      transactionReadState = detail::synchonousStates::IDLE;
      return libmcu::Results::UNCLAIMED;
    } else {
      return libmcu::Results::Error;
    }
  }
  /**
   * @brief Start a read transaction
   * @param buffer buffer of data to read
   * @return Error if not claimed interface or busy
   * @return Started when transaction started
   */
  constexpr libmcu::Results startRead(std::span<transferType> buffer) {
    if (transactionReadState != detail::synchonousStates::CLAIMED) {
      return libmcu::Results::Error;
    }
    // store transaction information
    transactionReadIndex = 0u;
    transactionReadData = buffer;
    transactionReadState = detail::synchonousStates::TRANSACTING;
    return libmcu::Results::Started;
  }
  /**
   * @brief Start a write transaction
   * @param buffer buffer of data to read
   * @return Error if not claimed interface or busy
   * @return Started when transaction started
   */
  constexpr libmcu::Results startWrite(std::span<transferType> buffer) {
    if (transactionWriteState != detail::synchonousStates::CLAIMED) {
      return libmcu::Results::Error;
    }
    // store transaction information
    transactionWriteIndex = 0u;
    transactionWriteData = buffer;
    transactionWriteState = detail::synchonousStates::TRANSACTING;
    // TODO write first data in UART register
    return libmcu::Results::Started;
  }
  /**
   * @brief continue started read transaction
   * @return Error if transaction has not started
   * @return Busy if transaction is still in progress
   * @return Done if transaction is done and buffer filled with data
   */
  constexpr libmcu::Results progressRead(void) {
    if (transactionReadState != detail::synchonousStates::TRANSACTING) {
      return libmcu::Results::Error;
    }
    if (usartPeripheral()->STAT & hardware::STAT::RXRDY) {
      transactionReadData[transactionReadIndex] = static_cast<transferType>(usartPeripheral()->RXDAT);
      transactionReadIndex++;
      if (transactionReadData.size() == transactionReadIndex) {
        transactionReadState = detail::synchonousStates::CLAIMED;
        return libmcu::Results::Done;
      }
    }
    return libmcu::Results::Busy;
  }
  /**
   * @brief continue started write transaction
   * @return Error if transaction has not started
   * @return Busy if transaction is still in progress
   * @return Done if transaction is done and buffer of data has been written
   */
  constexpr libmcu::Results progressWrite(void) {
    if (transactionWriteState != detail::synchonousStates::TRANSACTING) {
      return libmcu::Results::Error;
    }
    std::uint32_t status = usartPeripheral()->STAT;
    if (status & hardware::STAT::TXRDY) {
      if (transactionWriteData.size() > transactionWriteIndex) {
        usartPeripheral()->TXDAT = static_cast<std::uint32_t>(transactionWriteData[transactionWriteIndex]);
        transactionWriteIndex++;
      } else {
        if (status & hardware::STAT::TXIDLE) {
          transactionWriteState = detail::synchonousStates::CLAIMED;
          return libmcu::Results::Done;
        }
      }
    }
    return libmcu::Results::Busy;
  }
  /**
   * @brief get the input clock of this UART peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <auto& config>
  constexpr std::uint32_t GetInputClockFreq() {
    if constexpr (uartBaseAddress == libmcuhw::usart0Address) {
      if constexpr (config.uart0Source == libmcuhw::clock::periSource::MAIN) {
        return config.mainFreq;
      } else
        static_assert(false, "unsupported peripheral source!");
    } else if constexpr (uartBaseAddress == libmcuhw::usart1Address) {
      if constexpr (config.uart1Source == libmcuhw::clock::periSource::MAIN) {
        return config.mainFreq;
      } else
        static_assert(false, "unsupported peripheral source!");
    } else if constexpr (uartBaseAddress == libmcuhw::usart2Address) {
      if constexpr (config.uart2Source == libmcuhw::clock::periSource::MAIN) {
        return config.mainFreq;
      } else
        static_assert(false, "unsupported peripheral source!");
    } else if constexpr (uartBaseAddress == libmcuhw::usart3Address) {
      if constexpr (config.uart3Source == libmcuhw::clock::periSource::MAIN) {
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

  static constexpr libmcu::HwAddressBase uartBaseAddress = uartBaseAddress_; /*!< uart peripheral address */
  detail::synchonousStates transactionWriteState;                            /*!< usart write transaction state */
  detail::synchonousStates transactionReadState;                             /*!< usart read transaction state */
  std::size_t transactionWriteIndex;                                         /*!< transaction write buffer index */
  std::size_t transactionReadIndex;                                          /*!< transaction read buffer index */
  std::span<transferType> transactionWriteData;                              /*!< data to write */
  std::span<transferType> transactionReadData;                               /*!< where to put read data in */
};
}  // namespace libmcuhal::usart

#endif