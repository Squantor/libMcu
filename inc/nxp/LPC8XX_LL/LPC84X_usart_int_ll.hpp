/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_usart_int_ll.hpp
 * @brief Polled low level USART interface for the LPC840 series
 */
#ifndef LPC84X_USART_INT_LL_HPP
#define LPC84X_USART_INT_LL_HPP

#include "LPC84X_usart_common_ll.hpp"

namespace libmcull::usart {
namespace hardware = ::libmcuhw::usart;
/**
 * @brief Interrupt driven USART peripheral instance
 * @tparam usart_address Peripheral base usartAddress
 * @tparam TransferType datatype to use for data transfers
 */
template <const libmcu::UartBaseAddress usart_address, typename TransferType, std::size_t buffer_size>
struct UartInterrupt : libmcull::AsyncUartBase {
  /**
   * @brief Setup USART
   * @tparam &clock_config clock configuration to use
   * @param baud_rate Baud rate value
   * @param length_bits bit length of transmissions
   * @param parity parity type of transmissions
   * @param stop_bits Amount of stop bits
   * @return actual baud rate
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t Init(std::uint32_t baud_rate, UartParities parity = UartParities::None,
                               UartStops stop_bits = UartStops::Stop1, UartLengths length_bits = UartLengths::Size8) {
    std::uint32_t frequency = GetInputClockFreq<clock_config>();
    std::uint32_t divider = frequency / (baud_rate * 16);
    UsartPeripheral()->BRG = divider;
    UsartPeripheral()->CFG = hardware::CFG::ENABLE | static_cast<std::uint32_t>(length_bits) | static_cast<std::uint32_t>(parity) |
                             static_cast<std::uint32_t>(stop_bits);
    state = libmcu::States::Idle;
    return frequency / 16 / divider;
  }
  /**
   * @brief return uart status
   * @return current status of the asynchronous interface
   */
  constexpr libmcu::Results GetStatus() {
    return static_cast<libmcu::Results>(state);
  }
  /**
   * @brief Claim the USART interface
   * @return Claimed when the claim has been successful, any other value indicates an error
   */
  constexpr libmcu::Results Claim(void) {
    if (state == libmcu::States::Claimed) {
      return libmcu::Results::InUse;
    }
    if (state == libmcu::States::Idle) {
      state = libmcu::States::Claimed;
    }
    return static_cast<libmcu::Results>(state);
  }
  /**
   * @brief Unclaim the USART interface
   * @return Unclaimed when the unclaim has been successful, any other value indicates an error
   */
  constexpr libmcu::Results Unclaim(void) {
    if (state == libmcu::States::Claimed) {
      state = libmcu::States::Idle;
      return libmcu::Results::Unclaimed;
    }
    return static_cast<libmcu::Results>(state);
  }
  /**
   * @brief Send data out of the UART
   * @param data data to send, amount is sent according to configuration
   */
  constexpr void Write(TransferType data) {
    UsartPeripheral()->TXDAT = static_cast<TransferType>(data & hardware::TXDAT::RESERVED_MASK);
  }
  /**
   * @brief Read data from UART
   * @param data reference to put received data in
   */
  constexpr void Read(TransferType &data) {
    data = static_cast<TransferType>(UsartPeripheral()->RXDAT);
  }
  /**
   * @brief Read data and status from UART
   * @param data reference to put received data in
   * @param status reference to put received status in
   */
  constexpr void Read(TransferType &data, std::uint32_t &status) {
    std::uint32_t rx_status = UsartPeripheral()->RXDATSTAT;
    data = static_cast<TransferType>(rx_status & hardware::RXDATSTAT::DATA_MASK);
    status = rx_status & hardware::RXDATSTAT::STAT_MASK;
  }
  /**
   * @brief get the input clock of this UART peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t GetInputClockFreq() {
    // constexpr check if we configure the right peripheral
    if constexpr ((address == libmcuhw::Usart0Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART0))
      return clock_config.GetFrequency();
    else if constexpr ((address == libmcuhw::Usart1Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART1))
      return clock_config.GetFrequency();
    else if constexpr ((address == libmcuhw::Usart2Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART2))
      return clock_config.GetFrequency();
    else if constexpr ((address == libmcuhw::Usart3Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART3))
      return clock_config.GetFrequency();
    else
      static_assert(false, "Clock config and peripherals unknown or not matching!");
    return 0;
  }
  /**
   * @brief Get the Transmitter Data register address
   * This value is typically used for DMA transfer address configuration
   * @return pointer to register address
   */
  constexpr static std::uint32_t GetTxDataAddress() {
    return reinterpret_cast<std::uint32_t>(&(UsartPeripheral()->TXDAT));
  }
  /**
   * @brief Get the Receiver Data register address
   * This value is typically used for DMA transfer address configuration
   * @return pointer to register address
   */
  constexpr static std::uint32_t GetRxDataAddress() {
    return reinterpret_cast<std::uint32_t>(&(UsartPeripheral()->RXDAT));
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to usart registers
   */
  constexpr static hardware::Usart *UsartPeripheral() {
    return reinterpret_cast<hardware::Usart *>(address);
  }
  /**
   * @brief Interrupt handler for this USART peripheral
   */
  constexpr void InterruptHandler() {}

 private:
  static constexpr libmcu::HwAddressType address = usart_address; /*!< peripheral usartAddress */
  volatile libmcu::States state;                                  /*!< transmit state */
  libmcu::RingBuffer<TransferType, buffer_size> rx_buffer;        /*!< receive buffer */
  libmcu::RingBuffer<TransferType, buffer_size> tx_buffer;        /*!< transmit buffer */
};
}  // namespace libmcull::usart
#endif