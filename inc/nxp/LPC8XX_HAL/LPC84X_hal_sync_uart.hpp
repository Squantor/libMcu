/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_hal_sync_uart.hpp
 * @brief Synchronous UART interface for the LPC840 series
 */
#ifndef LPC84X_HAL_SYNC_UART_HPP
#define LPC84X_HAL_SYNC_UART_HPP

#include "LPC84X_hal_uart_common.hpp"

namespace libmcuhal::usartsync {
namespace hardware = libMcuHw::usart;
namespace lowlevel = libMcuLL::usart;

template <libmcuhal::DerivedFromHalUartSync auto& ll_uart_sync>
struct uartSync : public libmcuhal::HalUartSync {
 private:
};
}  // namespace libmcuhal::usartsync

#endif