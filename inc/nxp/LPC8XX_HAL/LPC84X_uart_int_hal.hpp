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
namespace lowlevel = libmcull::usart;
namespace nvic = libmcuhw::nvic;

template <libmcull::DerivedFromAsyncUart auto& ll_uart_async, typename TransferType, std::size_t action_timeout = 0x1000>
struct UartInterrupt : public libmcuhal::AsyncUartBase {
  /**
   * @brief Setup USART
   * @tparam &clock_config clock configuration to use
   * @param baudRate Baud rate value
   * @param lengthBits bit length of transmissions
   * @param parity parity type of transmissions
   * @param stopBits Amount of stop bits
   * @return actual baud rate
   */
  template <const libmcuhw::clock::PeriClockConfig& clock_config>
  constexpr std::uint32_t Init(std::uint32_t baudRate, UartParities parity = UartParities::None,
                               UartStops stopBits = UartStops::Stop1, UartLengths lengthBits = UartLengths::Size8) {
    return ll_uart_async.template Init<clock_config>(baudRate, static_cast<lowlevel::UartParities>(parity),
                                                     static_cast<lowlevel::UartStops>(stopBits),
                                                     static_cast<lowlevel::UartLengths>(lengthBits));
  }
  /**
   * @brief Claim asynchronous interface
   * @returns Claimed if successful
   * @returns see @ref libmcull::usart::UartInterrupt
   */
  libmcu::Results Claim() {
    return ll_uart_async.Claim();
  }
  /**
   * @brief Release the asynchronous interface
   * @returns InUse if the interface is already in use by another claimant
   * @returns Unclaimed if the interface is not claimed
   * @returns see @ref libmcull::usart::UartInterrupt
   */
  libmcu::Results Unclaim() {
    return ll_uart_async.Unclaim();
  }

  constexpr void Progress() {}

  constexpr void Callback() {}
  /**
   * @brief Transmit single element
   * @todo timeout handling
   * @param element single element to transmit
   * @returns see @ref libmcull::usart::UartInterrupt
   */
  libmcu::Results Transmit(TransferType element) {
    return ll_uart_async.Transmit(element);
  }
  /**
   * @brief Transmit multiple elements
   * @todo timeout handling
   * @param buffer span of elements to transmit
   * @returns see @ref libmcull::usart::UartInterrupt
   */
  libmcu::Results Transmit(std::span<const TransferType> buffer) {
    return ll_uart_async.Transmit(buffer);
  }
  /**
   * @brief Receive single element
   * @todo timeout handling
   * @param element singe element to receive
   * @returns see @ref libmcull::usart::UartInterrupt
   */
  libmcu::Results Receive(TransferType& element) {
    return ll_uart_async.Receive(element);
  }
  /**
   * @brief Receive multiple elements
   * @todo timeout handling
   * @param buffer span of elements to receive
   * @return libmcu::Results
   */
  libmcu::Results Receive(std::span<TransferType> buffer) {
    return ll_uart_async.Receive(buffer);
  }
  /**
   * @brief Get the Receive buffer fill level
   * @return How many elements have been received
   */
  constexpr std::size_t GetReceiveLevel() {
    return ll_uart_async.GetReceiveLevel();
  }

 private:
};
}  // namespace libmcuhal::usart

#endif