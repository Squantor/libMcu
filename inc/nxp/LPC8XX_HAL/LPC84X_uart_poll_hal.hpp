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
  kSize7 = static_cast<std::uint32_t>(lowlevel::UartLengths::kSize7), /*!< USART transmit length of 7 bits */
  kSize8 = static_cast<std::uint32_t>(lowlevel::UartLengths::kSize8), /*!< USART transmit length of 8 bits */
  kSize9 = static_cast<std::uint32_t>(lowlevel::UartLengths::kSize9), /*!< USART transmit length of 9 bits */
};

/**
 * @brief Parity bit options
 */
enum class UartParities : std::uint32_t {
  kNone = static_cast<std::uint32_t>(lowlevel::UartParities::kNone), /*!< No parity */
  kEven = static_cast<std::uint32_t>(lowlevel::UartParities::kEven), /*!< Even parity */
  kOdd = static_cast<std::uint32_t>(lowlevel::UartParities::kOdd),   /*!< Odd parity */
};

/**
 * @brief stop bit options
 */
enum class UartStops : std::uint32_t {
  kStop1 = static_cast<std::uint32_t>(lowlevel::UartStops::kStop1), /*!< 1 stop bit */
  kStop2 = static_cast<std::uint32_t>(lowlevel::UartStops::kStop2), /*!< 2 stop bits */
};
/**
 * @brief Uart status bits, multiple bits can be set
 */
enum UartStateMasks : std::uint32_t {
  kReceiverDataMask = lowlevel::kRxReady,        /*!< Receiver data ready flag */
  kReceiverIdleMask = lowlevel::kRxIdle,         /*!< Receiver idle */
  kTransmitDataMask = lowlevel::kTxReady,        /*!< Transmitter ready for data */
  kTransmitIdleMask = lowlevel::kTxIdle,         /*!< Transmitter idle */
  kOverrunMask = lowlevel::kOverrun,             /*!< Overrun error flag */
  kReceiverBreakMask = lowlevel::kRxBreak,       /*!< Received break flag */
  kFramingErrorMask = lowlevel::kFrameError,     /*!< Frame error interrupt flag */
  kParityErrorMask = lowlevel::kParityError,     /*!< Parity error interrupt flag */
  kReceiverNoiseMask = lowlevel::kRxNoise,       /*!< Recieved noise interrupt flag */
  kAutobaudErrorMask = lowlevel::kAutobaudError, /*!< Autobaud error flag */
};

/**
 * @brief UART HAL class
 * @tparam ll_uart_sync synchronous uart low level interface class
 */
template <libmcull::DerivedFromSyncUart auto& ll_uart_sync, typename TransferType, std::size_t action_timeout = 0x1000>
struct UartPolled : public libmcuhal::HalUartBase {
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
  constexpr std::uint32_t Init(std::uint32_t baudRate, UartParities parity = UartParities::kNone,
                               UartStops stopBits = UartStops::kStop1, UartLengths lengthBits = UartLengths::kSize8) {
    return ll_uart_sync.template Init<clock_config>(baudRate, static_cast<lowlevel::UartParities>(parity),
                                                    static_cast<lowlevel::UartStops>(stopBits),
                                                    static_cast<lowlevel::UartLengths>(lengthBits));
  }
  /**
   * @brief Claim an the asynchronous interface
   * @param[out] handle for the claimed interface, set when claimed
   * @returns kClaimed if successful
   * @returns kInUse if the interface is already in use
   */
  libmcu::Results Claim(AsyncHandle& handle) {
    if (state_ != libmcu::AsynchronousStates::kIdle)
      return libmcu::Results::kInUse;
    handle = async_handle_;
    state_ = libmcu::AsynchronousStates::kClaimed;
    return libmcu::Results::kClaimed;
  }
  /**
   * @brief Release the asynchronous interface
   * @param handle for the interface to be released
   * @returns kUnclaimed if successful
   * @returns kNotClaimed if the interface is not claimed
   * @returns kInvalidHandle if the handle is invalid
   */
  libmcu::Results Release(AsyncHandle handle) {
    if (state_ != libmcu::AsynchronousStates::kClaimed)
      return libmcu::Results::kNotClaimed;
    if (handle != async_handle_)
      return libmcu::Results::kInvalidHandle;
    async_handle_ += 1;
    state_ = libmcu::AsynchronousStates::kIdle;
    return libmcu::Results::kUnclaimed;
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
  libmcu::Results Transmit(AsyncHandle handle, TransferType buffer) {
    if (state_ != libmcu::AsynchronousStates::kClaimed)
      return libmcu::Results::kNotClaimed;
    if (handle != async_handle_)
      return libmcu::Results::kInvalidHandle;
    UartStateMasks status;
    do {
      status = GetStatus();
    } while ((status & kTransmitDataMask) == 0);
    ll_uart_sync.Write(buffer);
    return libmcu::Results::kNoError;
  }

  /**
   * @brief Receive single element
   * @param handle
   * @param buffer
   * @return libmcu::Results
   */
  libmcu::Results Receive(AsyncHandle handle, TransferType& buffer) {
    if (state_ != libmcu::AsynchronousStates::kClaimed)
      return libmcu::Results::kNotClaimed;
    if (handle != async_handle_)
      return libmcu::Results::kInvalidHandle;
    UartStateMasks status;
    std::size_t timeout = action_timeout;
    do {
      status = GetStatus();
      timeout -= 1;
    } while ((status & kReceiverDataMask) == 0 && timeout > 0);
    if (timeout == 0)
      return libmcu::Results::kTimeout;
    ll_uart_sync.Read(buffer);
    return libmcu::Results::kNoError;
  }

 private:
  AsyncHandle async_handle_ = 0; /*!< Async handle to be passed to the claimant, incremented per claim/unclaim pair */
  libmcu::AsynchronousStates state_ = libmcu::AsynchronousStates::kIdle;
};

}  // namespace libmcuhal::usart

#endif
