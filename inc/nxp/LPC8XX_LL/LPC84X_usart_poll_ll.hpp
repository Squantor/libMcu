/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_usart_poll_ll.hpp
 * @brief Polled low level USART interface for the LPC840 series
 */
#ifndef LPC84X_USART_POLL_LL_HPP
#define LPC84X_USART_POLL_LL_HPP

#include "LPC84X_usart_common_ll.hpp"

namespace libmcull::usart {
namespace hardware = ::libmcuhw::usart;
/**
 * @brief synchronous USART peripheral instance
 * @tparam usart_address Peripheral base usartAddress
 * @tparam TransferType datatype to use for data transfers
 */
template <const libmcu::UartBaseAddress usart_address, typename TransferType>
struct UartPolled : libmcull::SyncUartBase {
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
    GetPeripheral()->BRG = divider;
    GetPeripheral()->CFG = hardware::CFG::ENABLE | static_cast<std::uint32_t>(length_bits) | static_cast<std::uint32_t>(parity) |
                           static_cast<std::uint32_t>(stop_bits);
    return frequency / 16 / divider;
  }
  /**
   * @brief return uart status
   * @return std::uint32_t one to one copy of the status register, see bit masks for options
   */
  constexpr std::uint32_t Status() {
    return GetPeripheral()->STAT & hardware::STAT::RESERVED_MASK;
  }
  /**
   * @brief Send data out of the UART
   * @param data data to send, amount is sent according to configuration
   */
  constexpr void Write(TransferType data) {
    GetPeripheral()->TXDAT = static_cast<TransferType>(data & hardware::TXDAT::RESERVED_MASK);
  }
  /**
   * @brief Read data from UART
   * @param data reference to put received data in
   */
  constexpr void Read(TransferType &data) {
    data = static_cast<TransferType>(GetPeripheral()->RXDAT);
  }
  /**
   * @brief Read data and status from UART
   * @param data reference to put received data in
   * @param status reference to put received status in
   */
  constexpr void Read(TransferType &data, std::uint32_t &status) {
    std::uint32_t rx_status = GetPeripheral()->RXDATSTAT;
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
    if constexpr ((usart_address_ == libmcuhw::Usart0Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART0))
      return clock_config.GetFrequency();
    else if constexpr ((usart_address_ == libmcuhw::Usart1Address) &&
                       (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART1))
      return clock_config.GetFrequency();
    else if constexpr ((usart_address_ == libmcuhw::Usart2Address) &&
                       (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART2))
      return clock_config.GetFrequency();
    else if constexpr ((usart_address_ == libmcuhw::Usart3Address) &&
                       (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART3))
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
    return reinterpret_cast<std::uint32_t>(&(GetPeripheral()->TXDAT));
  }
  /**
   * @brief Get the Receiver Data register address
   * This value is typically used for DMA transfer address configuration
   * @return pointer to register address
   */
  constexpr static std::uint32_t GetRxDataAddress() {
    return reinterpret_cast<std::uint32_t>(&(GetPeripheral()->RXDAT));
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to usart registers
   */
  constexpr static hardware::Usart *GetPeripheral() {
    return reinterpret_cast<hardware::Usart *>(usart_address_);
  }

 private:
  static constexpr libmcu::HwAddressType usart_address_ = usart_address; /*!< peripheral usartAddress */
};
}  // namespace libmcull::usart
#endif