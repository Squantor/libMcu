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
using namespace libMcuLL::hw::uart;
template <libMcuLL::uartBaseAddress const& uartAddress_>
struct uart : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief setup UART to 8N1
   * Taken from raspberry Pi Pico SDK
   * @param baudrate requested baud rate
   * @return actual baud rate
   */
  constexpr std::uint32_t setup(std::uint32_t baudrate) {
    uartPeripheralClear()->UARTCR = UARTCR::TXE | UARTCR::RXE | UARTCR::UARTEN;
    // baud rate calculations
    std::uint32_t divisor = (8 * FREQ_PERI / baudrate);
    std::uint32_t divIntegral = divisor >> 7;
    std::uint32_t divFractional;
    if (divIntegral == 0) {
      divIntegral = 1;
      divFractional = 0;
    } else if (divIntegral >= 65535) {
      divIntegral = 65535;
      divFractional = 0;
    } else {
      divFractional = ((divisor & 0x7f) + 1) / 2;
    }
    uartPeripheral()->UARTIBRD = divIntegral;
    uartPeripheral()->UARTFBRD = divFractional;
    // PL011 needs a (dummy) LCR_H write to latch in the divisors.
    // We don't want to actually change LCR_H contents here.
    // uartPeripheral()->UARTLCR_H = uartPeripheral()->UARTLCR_H;

    uartPeripheral()->UARTLCR_H = UARTLCR_H::WLEN_8 | UARTLCR_H::FEN;
    uartPeripheral()->UARTCR = UARTCR::TXE | UARTCR::RXE | UARTCR::UARTEN;
    uartPeripheral()->UARTDMACR = UARTDMACR::TXDMAE | UARTDMACR::RXDMAE;
    return (4 * FREQ_PERI) / (64 * divIntegral + divFractional);
  }
  // TODO: add setup with format settings
  // write
  constexpr void write(std::span<const std::uint8_t> transmitBuffer) {
    for (const std::uint8_t& character : transmitBuffer) {
      while ((uartPeripheral()->UARTFR & UARTFR::TXFF_FLAG))
        libMcu::sw::nop();
      uartPeripheral()->UARTDR = character;
    }
  }
  // read, data, timeout
  constexpr libMcu::results read(std::span<std::uint8_t> receiveBuffer, std::uint32_t timeout) {
    std::uint32_t countdown;
    for (std::uint8_t& character : receiveBuffer) {
      countdown = timeout;
      while ((uartPeripheral()->UARTFR & UARTFR::RXFE_FLAG) && countdown) {
        countdown = countdown - 1;
      }
      if (countdown == 0)
        return libMcu::results::TIMEOUT;
      std::uint32_t receivedData = uartPeripheral()->UARTDR;
      if (receivedData & UARTDR::ERROR_MASK) {
        if (receivedData & UARTDR::OE_FLAG)
          return libMcu::results::OVERRUN;
        else if (receivedData & UARTDR::BE_FLAG)
          return libMcu::results::BREAK;
        else if (receivedData & UARTDR::PE_FLAG)
          return libMcu::results::PARITY;
        else if (receivedData & UARTDR::FE_FLAG)
          return libMcu::results::FRAMING;
      }
      character = static_cast<std::uint8_t>(receivedData);
    }
    return libMcu::results::NO_ERROR;
  }

  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::uart::peripheral* uartPeripheral() {
    return reinterpret_cast<hw::uart::peripheral*>(uartAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hw::uart::peripheral* uartPeripheralSet() {
    return reinterpret_cast<hw::uart::peripheral*>(uartAddress + hw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hw::uart::peripheral* uartPeripheralClear() {
    return reinterpret_cast<hw::uart::peripheral*>(uartAddress + hw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hw::uart::peripheral* uartPeripheralXor() {
    return reinterpret_cast<hw::uart::peripheral*>(uartAddress + hw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcuLL::hwAddressType uartAddress{uartAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sw::uart
#endif