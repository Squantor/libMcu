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
   * @brief Claim an the asynchronous interface
   * @param[out] handle for the claimed interface, set when claimed
   * @returns Claimed if successful
   * @returns for the rest see @ref libmcull::I2cInterrupt
   */
  libmcu::Results Claim(libmcu::AsyncHandle& handle) {
    libmcu::Results result = ll_uart_async.Claim();
    if (result != libmcu::Results::Claimed)
      return result;
    handle = async_handle;
    return result;
  }
  /**
   * @brief Release the asynchronous interface
   * @param handle for the interface to be released
   * @returns InUse if the interface is already in use by another claimant
   * @returns Unclaimed if the interface is not claimed
   * @returns for the rest see @ref libmcull::I2cInterrupt
   */
  libmcu::Results Unclaim(libmcu::AsyncHandle handle) {
    if (handle != async_handle)
      return libmcu::Results::InUse;
    libmcu::Results result = ll_uart_async.Unclaim();
    if (result != libmcu::Results::Unclaimed)
      return result;
    async_handle += 1;
    return result;
  }
  /**
   * @brief Transmit single element
   * @todo timeout handling
   * @param handle Asynchronous handle from claim operation
   * @param element single element to transmit
   * @return libmcu::Results
   */
  libmcu::Results Transmit(libmcu::AsyncHandle handle, TransferType element) {
    if (ll_uart_async.GetStatus() != libmcu::Results::Claimed)
      return libmcu::Results::NotClaimed;
    if (handle != async_handle)
      return libmcu::Results::InvalidHandle;
    return ll_uart_async.Transmit(element);
  }
  /**
   * @brief Transmit multiple elements
   * @todo timeout handling
   * @param handle Asynchronous handle from claim operation
   * @param buffer span of elements to transmit
   * @return libmcu::Results
   */
  libmcu::Results Transmit(libmcu::AsyncHandle handle, std::span<TransferType> buffer) {
    if (ll_uart_async.GetStatus() != libmcu::Results::Claimed)
      return libmcu::Results::NotClaimed;
    if (handle != async_handle)
      return libmcu::Results::InvalidHandle;
    return ll_uart_async.Transmit(buffer);
  }
  /**
   * @brief Receive single element
   * @todo timeout handling
   * @param handle Asynchronous handle from claim operation
   * @param element singe element to receive
   * @return libmcu::Results
   */
  libmcu::Results Receive(libmcu::AsyncHandle handle, TransferType& element) {
    if (ll_uart_async.GetStatus() != libmcu::Results::Claimed)
      return libmcu::Results::NotClaimed;
    if (handle != async_handle)
      return libmcu::Results::InvalidHandle;
    return ll_uart_async.Receive(element);
  }
  /**
   * @brief Receive multiple elements
   * @todo timeout handling
   * @param handle Asynchronous handle from claim operation
   * @param buffer span of elements to receive
   * @return libmcu::Results
   */
  libmcu::Results Receive(libmcu::AsyncHandle handle, std::span<TransferType> buffer) {
    if (ll_uart_async.GetStatus() != libmcu::Results::Claimed)
      return libmcu::Results::NotClaimed;
    if (handle != async_handle)
      return libmcu::Results::InvalidHandle;
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
  libmcu::AsyncHandle async_handle = 0; /*!< Async handle to be passed to the claimant, incremented per claim/unclaim pair */
};
}  // namespace libmcuhal::usart

#endif