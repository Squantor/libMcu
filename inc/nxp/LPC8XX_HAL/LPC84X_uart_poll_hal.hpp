/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_uart_hal.hpp
 * @brief UART HAL interface for the LPC840 series
 */
#ifndef LPC84X_UART_HAL_HPP
#define LPC84X_UART_HAL_HPP

#include "LPC84X_uart_common_hal.hpp"

namespace libmcuhal::usart {
namespace hardware = libmcuhw::usart;
namespace lowlevel = libmcull::usart;

/**
 * @brief amount of bits to transmit
 */
enum class UartLengths : std::uint32_t {
  Size7 = static_cast<std::uint32_t>(lowlevel::UartLengths::Size7), /*!< USART transmit length of 7 bits */
  Size8 = static_cast<std::uint32_t>(lowlevel::UartLengths::Size8), /*!< USART transmit length of 8 bits */
  Size9 = static_cast<std::uint32_t>(lowlevel::UartLengths::Size9), /*!< USART transmit length of 9 bits */
};

/**
 * @brief Parity bit options
 */
enum class UartParities : std::uint32_t {
  None = static_cast<std::uint32_t>(lowlevel::UartParities::None), /*!< No parity */
  Even = static_cast<std::uint32_t>(lowlevel::UartParities::Even), /*!< Even parity */
  Odd = static_cast<std::uint32_t>(lowlevel::UartParities::Odd),   /*!< Odd parity */
};

/**
 * @brief stop bit options
 */
enum class UartStops : std::uint32_t {
  Stop1 = static_cast<std::uint32_t>(lowlevel::UartStops::Stop1), /*!< 1 stop bit */
  Stop2 = static_cast<std::uint32_t>(lowlevel::UartStops::Stop2), /*!< 2 stop bits */
};
/**
 * @brief Uart status bits, multiple bits can be set
 */
enum UartStateMasks : std::uint32_t {
  ReceiverDataMask = lowlevel::RxReady,        /*!< Receiver data ready flag */
  ReceiverIdleMask = lowlevel::RxIdle,         /*!< Receiver idle */
  TransmitDataMask = lowlevel::TxReady,        /*!< Transmitter ready for data */
  TransmitIdleMask = lowlevel::TxIdle,         /*!< Transmitter idle */
  OverrunMask = lowlevel::Overrun,             /*!< Overrun error flag */
  ReceiverBreakMask = lowlevel::RxBreak,       /*!< Received break flag */
  FramingErrorMask = lowlevel::FrameError,     /*!< Frame error interrupt flag */
  ParityErrorMask = lowlevel::ParityError,     /*!< Parity error interrupt flag */
  ReceiverNoiseMask = lowlevel::RxNoise,       /*!< Recieved noise interrupt flag */
  AutobaudErrorMask = lowlevel::AutobaudError, /*!< Autobaud error flag */
};

/**
 * @brief UART HAL class
 * @tparam ll_uart_sync synchronous uart low level interface class
 * @todo refactor so you do not use libmcu::AsynchronousStates but libmcu::States instead
 */
template <libmcull::DerivedFromSyncUart auto& ll_uart_sync, typename TransferType, std::size_t action_timeout = 0x1000>
struct UartPolled : public libmcuhal::SyncUartBase {
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
    return ll_uart_sync.template Init<clock_config>(baudRate, static_cast<lowlevel::UartParities>(parity),
                                                    static_cast<lowlevel::UartStops>(stopBits),
                                                    static_cast<lowlevel::UartLengths>(lengthBits));
  }
  /**
   * @brief Claim an the asynchronous interface
   * @param[out] handle for the claimed interface, set when claimed
   * @returns Claimed if successful
   * @returns InUse if the interface is already in use
   */
  libmcu::Results Claim(libmcu::AsyncHandle& handle) {
    if (state_ != libmcu::AsynchronousStates::Idle)
      return libmcu::Results::InUse;
    handle = async_handle_;
    state_ = libmcu::AsynchronousStates::Claimed;
    return libmcu::Results::Claimed;
  }
  /**
   * @brief Release the asynchronous interface
   * @param handle for the interface to be released
   * @returns Unclaimed if successful
   * @returns NotClaimed if the interface is not claimed
   * @returns InvalidHandle if the handle is invalid
   */
  libmcu::Results Release(libmcu::AsyncHandle handle) {
    if (state_ != libmcu::AsynchronousStates::Claimed)
      return libmcu::Results::NotClaimed;
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    async_handle_ += 1;
    state_ = libmcu::AsynchronousStates::Idle;
    return libmcu::Results::Unclaimed;
  }
  /**
   * @brief Get the status of the UART interface
   * @return UartStateMasks bit fields
   */
  UartStateMasks GetStatus() {
    return static_cast<UartStateMasks>(ll_uart_sync.Status());
  }

  /**
   * @brief Transmit single element
   * @todo timeout handling
   * @param handle
   * @param buffer
   * @return libmcu::Results
   */
  libmcu::Results Transmit(libmcu::AsyncHandle handle, TransferType buffer) {
    if (state_ != libmcu::AsynchronousStates::Claimed)
      return libmcu::Results::NotClaimed;
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    UartStateMasks status;
    do {
      status = GetStatus();
    } while ((status & TransmitDataMask) == 0);
    ll_uart_sync.Write(buffer);
    return libmcu::Results::NoError;
  }

  /**
   * @brief Receive single element
   * @param handle
   * @param buffer
   * @return libmcu::Results
   */
  libmcu::Results Receive(libmcu::AsyncHandle handle, TransferType& buffer) {
    if (state_ != libmcu::AsynchronousStates::Claimed)
      return libmcu::Results::NotClaimed;
    if (handle != async_handle_)
      return libmcu::Results::InvalidHandle;
    UartStateMasks status;
    std::size_t timeout = action_timeout;
    do {
      status = GetStatus();
      timeout -= 1;
    } while ((status & ReceiverDataMask) == 0 && timeout > 0);
    if (timeout == 0)
      return libmcu::Results::Timeout;
    ll_uart_sync.Read(buffer);
    return libmcu::Results::NoError;
  }

 private:
  libmcu::AsyncHandle async_handle_ = 0; /*!< Async handle to be passed to the claimant, incremented per claim/unclaim pair */
  libmcu::AsynchronousStates state_ = libmcu::AsynchronousStates::Idle;
};

}  // namespace libmcuhal::usart

#endif
