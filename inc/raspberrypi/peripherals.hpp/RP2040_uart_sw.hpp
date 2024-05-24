/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 UART software interface
 */
#ifndef RP2040_UART_SW_HPP
#define RP2040_UART_SW_HPP

namespace libMcuLL::sw::uart {
template <libMcuLL::uartBaseAddress const& uartAddress_>
struct uart : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::uart::peripheral* uartPeripheral() {
    return reinterpret_cast<hw::uart::peripheral*>(uartAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType uartAddress{uartAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sw::uart
#endif