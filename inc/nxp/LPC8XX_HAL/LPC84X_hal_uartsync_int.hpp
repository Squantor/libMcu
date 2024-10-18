/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series interrupt synchronous UART HAL
 */
#ifndef LPC84X_HAL_UARTSYNC_INT_HPP
#define LPC84X_HAL_UARTSYNC_INT_HPP

#include "LPC84X_hal_uart_common.hpp"

namespace libMcuHal::usart {
namespace hardware = libMcuHw::usart;
namespace nvic = libMcuHw::nvic;

template <libMcu::uartBaseAddress const& uartBaseAddress_, libMcu::nvicBaseAddress const& nvicBaseAddress_, typename transferType,
          std::size_t bufSize>
struct uartSync {
  /**
   * @brief Construct a new asynchronous uart
   */
  uartSync() {}
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
    usartPeripheral()->INTENSET = hardware::INTENSET::RXRDYEN;
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
    usartPeripheral()->INTENSET = hardware::INTENSET::RXRDYEN;
    return getInputClockFreq<config>() / 16 / baudDivider;
  }
  /**
   * @brief blocking USART transmit
   * @param input data to transmit via USART
   */
  constexpr void write(const transferType& input) {
    std::array<transferType, 1> inputBuffer{input};
    write(inputBuffer);
  }
  /**
   * @brief blocking USART transmit
   * @param buffer data to transmit via USART
   */
  constexpr void write(std::span<const transferType> buffer) {
    std::size_t bufferIndex = 0;
    while (bufferIndex != buffer.size()) {
      if (!txBuffer.full()) {
        txBuffer.pushFront(buffer[bufferIndex]);
        bufferIndex++;
      }
      // are we currently transmitting?
      if (!(usartPeripheral()->INTENSET & hardware::INTENSET::TXRDYEN)) {
        // no, lets start the whole transmit chain
        transferType data = 0;
        if (txBuffer.popBack(data)) {
          usartPeripheral()->TXDAT = data;
          usartPeripheral()->INTENSET = hardware::INTENSET::TXRDYEN;
        }
      }
    }
  }
  /** 
   * @brief blocking USART receive
   * @param buffer data to receive from USART
   */
  constexpr void read(std::span<transferType> buffer) {
    std::size_t bufferIndex = 0;
    while (bufferIndex != buffer.size()) {
      if (!rxBuffer.empty()) {
        rxBuffer.popBack(buffer[bufferIndex]);
        bufferIndex++;
      }
    }
  }
  /**
   * @brief 
   * @return constexpr std::uint32_t 
   */
  constexpr std::uint32_t receiveDataAvailable() {
    return rxBuffer.level();
  }
  /**
   * @brief UART interrupt service routine
   */
  constexpr void isr() {
    if (usartPeripheral()->INTSTAT & hardware::INTSTAT::TXRDY) {
      if (txBuffer.empty()) {
        usartPeripheral()->INTENCLR = hardware::INTENCLR::TXRDYCLR;
      } else {
        transferType data;
        txBuffer.popBack(data);
        usartPeripheral()->TXDAT = data;
      }
    }
    if (usartPeripheral()->INTSTAT & hardware::INTSTAT::RXRDY) {
      // TODO, what do we do if rx buffer is full?
      rxBuffer.pushFront(usartPeripheral()->RXDAT);
    }
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
   * @brief access uart registers
   * @return return pointer to peripheral
   */
  static hardware::usart* usartPeripheral() {
    return reinterpret_cast<hardware::usart*>(uartBaseAddress);
  }
  /**
   * @brief access nvic registers
   * @return return pointer to peripheral
   */
  static nvic::nvic* nvicPeripheral() {
    return reinterpret_cast<nvic::nvic*>(nvicBaseAddress);
  }

  static constexpr libMcu::hwAddressType uartBaseAddress = uartBaseAddress_; /**< UART peripheral address */
  static constexpr libMcu::hwAddressType nvicBaseAddress = nvicBaseAddress_; /**< NVIC peripheral address */
  libMcu::RingBuffer<transferType, bufSize> txBuffer;
  libMcu::RingBuffer<transferType, bufSize> rxBuffer;
};  // namespace libMcu::hw::nvic
}  // namespace libMcuHal::usart

#endif