/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_hal_uartasync_int.hpp
 * @brief LPC840 series interrupt synchronous UART HAL
 * @todo depricate synchronous interrupt interfaces
 * @todo Change this to use the Uart LL interrupt
 */
#ifndef LPC84X_HAL_UARTSYNC_INT_HPP
#define LPC84X_HAL_UARTSYNC_INT_HPP

#include "LPC84X_uart_common_hal.hpp"

namespace libmcuhal::usart {
namespace hardware = libmcuhw::usart;
namespace nvic = libmcuhw::nvic;

template <typename TransferType, std::size_t bufSize>
struct UartInterrupt {
  /**
   * @brief Construct a new asynchronous uart
   */
  UartInterrupt() {}
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
    return 0;
  }
  /**
   * @brief Setup USART
   * @param baudRate Baud rate value
   * @param lengthBits bit length of transmissions, see UartLength enum for options
   * @param parity parity type of transmissions, see UartParity enum for options
   * @param stopBits Amount of stop bits, see UartStop enum for options
   * @return std::uint32_t actual baud rate
   */
  template <auto& config>
  constexpr std::uint32_t init(std::uint32_t baudRate, UartLength lengthBits, UartParity parity, UartStop stopBits) {
    (void)baudRate;
    (void)lengthBits;
    (void)parity;
    (void)stopBits;
    return 0;
  }
  /**
   * @brief blocking USART transmit
   * @param input data to transmit via USART
   */
  constexpr void write(const TransferType& input) {
    (void)input;
  }
  /**
   * @brief blocking USART transmit
   * @param buffer data to transmit via USART
   */
  constexpr void write(std::span<const TransferType> buffer) {
    (void)buffer;
  }
  /**
   * @brief blocking USART receive
   * @param buffer data to receive from USART
   */
  constexpr void read(std::span<TransferType> buffer) {
    (void)buffer;
  }
  /**
   * @brief
   * @return constexpr std::uint32_t
   */
  constexpr std::uint32_t receiveDataAvailable() {
    return 0;
  }
  /**
   * @brief UART interrupt service routine
   */
  constexpr void isr() {}
  /**
   * @brief get the input clock of this UART peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <auto& config>
  constexpr std::uint32_t GetInputClockFreq() {
    return 0;
  }

 private:
  libmcu::RingBuffer<TransferType, bufSize> txBuffer;
  libmcu::RingBuffer<TransferType, bufSize> rxBuffer;
};
}  // namespace libmcuhal::usart

#endif