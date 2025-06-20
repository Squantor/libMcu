/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file  RP2040_uart_int_hal.hpp
 * @brief RP2040 Interrupt UART HAL class
 */
#ifndef RP2040_UART_INT_HAL_HPP
#define RP2040_UART_INT_HAL_HPP

namespace libmcuhal::uart {
namespace lowlevel = libmcull::uart;

/**
 * @brief
 * @tparam uart_int_lowlevel
 */
template <const auto& uart_int_lowlevel>
struct UartInterrupt {
  /**
   * @brief
   */
  void Init() {}

 private:
};
}  // namespace libmcuhal::uart

#endif