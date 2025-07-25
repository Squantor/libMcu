/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_uart_poll_ll.hpp
 * @brief Polled low level interface for the polled RP2040 UART
 */
#ifndef RP2040_UART_POLL_LL_HPP
#define RP2040_UART_POLL_LL_HPP

namespace libmcull::uart {
namespace hardware = libmcuhw::uart;
/**
 * @brief
 * @tparam uart_address
 */
template <libmcu::UartBaseAddress const& uart_address>
struct UartPolled : libmcull::SyncUartBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief setup UART to 8N1
   * Taken from raspberry Pi Pico SDK
   * @param baudrate requested baud rate
   * @return actual baud rate
   */
  constexpr std::uint32_t Setup(std::uint32_t baudrate) {
    GetPeripheralClear()->UARTCR = hardware::UARTCR::TXE | hardware::UARTCR::RXE | hardware::UARTCR::UARTEN;
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
    GetPeripheral()->UARTIBRD = divIntegral;
    GetPeripheral()->UARTFBRD = divFractional;
    // PL011 needs a (dummy) LCR_H write to latch in the divisors.
    // We don't want to actually change LCR_H contents here.
    // uartPeripheral()->UARTLCR_H = uartPeripheral()->UARTLCR_H;

    GetPeripheral()->UARTLCR_H = hardware::UARTLCR_H::WLEN_8 | hardware::UARTLCR_H::FEN;
    GetPeripheral()->UARTCR = hardware::UARTCR::TXE | hardware::UARTCR::RXE | hardware::UARTCR::UARTEN;
    GetPeripheral()->UARTDMACR = hardware::UARTDMACR::TXDMAE | hardware::UARTDMACR::RXDMAE;
    return (4 * FREQ_PERI) / (64 * divIntegral + divFractional);
  }
  //! @todo add setup with format settings
  /**
   * @brief
   * @param transmitBuffer
   * @todo timeout
   */
  constexpr void Transmit(std::span<const std::uint8_t> transmitBuffer) {
    for (const std::uint8_t& character : transmitBuffer) {
      while ((GetPeripheral()->UARTFR & hardware::UARTFR::TXFF_FLAG))
        libmcull::nop();
      GetPeripheral()->UARTDR = character;
    }
  }
  /**
   * @brief
   * @param receiveBuffer
   * @param timeout
   * @return constexpr libmcu::Results
   */
  constexpr libmcu::Results Receive(std::span<std::uint8_t> receiveBuffer, std::uint32_t timeout) {
    std::uint32_t countdown;
    for (std::uint8_t& character : receiveBuffer) {
      countdown = timeout;
      while ((GetPeripheral()->UARTFR & hardware::UARTFR::RXFE_FLAG) && countdown) {
        countdown = countdown - 1;
      }
      if (countdown == 0)
        return libmcu::Results::Timeout;
      std::uint32_t receivedData = GetPeripheral()->UARTDR;
      if (receivedData & hardware::UARTDR::ERROR_MASK) {
        if (receivedData & hardware::UARTDR::OE_FLAG)
          return libmcu::Results::Overrun;
        else if (receivedData & hardware::UARTDR::BE_FLAG)
          return libmcu::Results::BreakError;
        else if (receivedData & hardware::UARTDR::PE_FLAG)
          return libmcu::Results::ParityError;
        else if (receivedData & hardware::UARTDR::FE_FLAG)
          return libmcu::Results::FramingError;
      }
      character = static_cast<std::uint8_t>(receivedData);
    }
    return libmcu::Results::NoError;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Uart* GetPeripheral() {
    return reinterpret_cast<hardware::Uart*>(uart_address_);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::Uart* GetPeripheralSet() {
    return reinterpret_cast<hardware::Uart*>(uart_address_ + libmcuhw::PeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::Uart* GetPeripheralClear() {
    return reinterpret_cast<hardware::Uart*>(uart_address_ + libmcuhw::PeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::Uart* GetPeripheralXor() {
    return reinterpret_cast<hardware::Uart*>(uart_address_ + libmcuhw::PeripheralOffsetXor);
  }

 private:
  static constexpr libmcu::HwAddressType uart_address_{uart_address}; /*!< peripheral address */
};
}  // namespace libmcull::uart
#endif