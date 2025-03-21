/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_sync_uart_hal.hpp
 * @brief Synchronous HAL UART interface for the LPC840 series
 */
#ifndef LPC84X_SYNC_UART_HAL_HPP
#define LPC84X_SYNC_UART_HAL_HPP

#include "LPC84X_hal_uart_common.hpp"

namespace libmcuhal::usart {
namespace hardware = libMcuHw::usart;
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

template <libmcull::DerivedFromLlUartSync auto& ll_uart_sync>
struct SyncUart : public libmcuhal::HalUartSync {
  /**
   * @brief Setup USART
   * @tparam &clock_config clock configuration to use
   * @param baudRate Baud rate value
   * @param lengthBits bit length of transmissions
   * @param parity parity type of transmissions
   * @param stopBits Amount of stop bits
   * @return actual baud rate
   */
  template <const libMcuHw::clock::periClockConfig& clock_config>
  constexpr std::uint32_t Init(std::uint32_t baudRate, UartParities parity = UartParities::kNone,
                               UartStops stopBits = UartStops::kStop1, UartLengths lengthBits = UartLengths::kSize8) {
    return ll_uart_sync.template Init<clock_config>(baudRate, static_cast<lowlevel::UartParities>(parity),
                                                    static_cast<lowlevel::UartStops>(stopBits),
                                                    static_cast<lowlevel::UartLengths>(lengthBits));
  }

 private:
};
}  // namespace libmcuhal::usart

#endif