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

namespace libmcull::usart {
namespace hardware = ::libmcuhw::usart;
/**
 * @brief amount of bits to transmit
 */
enum class UartLengths : std::uint32_t {
  kSize7 = hardware::CFG::kDATALEN7BIT, /*!< USART transmit length of 7 bits */
  kSize8 = hardware::CFG::kDATALEN8BIT, /*!< USART transmit length of 8 bits */
  kSize9 = hardware::CFG::kDATALEN9BIT, /*!< USART transmit length of 9 bits */
};
/**
 * @brief Parity bit options
 */
enum class UartParities : std::uint32_t {
  kNone = hardware::CFG::kPARITY_NONE, /*!< No parity */
  kEven = hardware::CFG::kPARITY_EVEN, /*!< Even parity */
  kOdd = hardware::CFG::kPARITY_ODD,   /*!< Odd parity */
};
/**
 * @brief stop bit options
 */
enum class UartStops : std::uint32_t {
  kStop1 = hardware::CFG::kSTOPBIT1, /*!< 1 stop bit */
  kStop2 = hardware::CFG::kSTOPBIT2, /*!< 2 stop bits */
};
/**
 * @brief Uart status bits
 * These bit patterns match the USART STAT register settings
 */
enum UartStatuses : std::uint32_t {
  kRxReady = hardware::STAT::kRXRDY,            /*!< Receiver ready flag*/
  kRxIdle = hardware::STAT::kRXIDLE,            /*!< Receiver idle flag */
  kTxReady = hardware::STAT::kTXRDY,            /*!< Transmitter ready flag  */
  kTxIdle = hardware::STAT::kTXIDLE,            /*!< Transmitter idle flag */
  kCts = hardware::STAT::kCTS,                  /*!< CTS signal state flag */
  kCtsChange = hardware::STAT::kDELTACTS,       /*!< Change detected in CTS signal flag */
  kTxDisable = hardware::STAT::kTXDISINT,       /*!< Transmitter disabled confirmation flag */
  kOverrun = hardware::STAT::kOVERRUNINT,       /*!< Overrun error flag */
  kRxBreak = hardware::STAT::kRXBRK,            /*!< Received break flag */
  kRxBreakChange = hardware::STAT::kDELTARXBRK, /*!< Change detected in receiver break flag */
  kStart = hardware::STAT::kSTART,              /*!< Start condition detected flag */
  kFrameError = hardware::STAT::kFRAMERRINT,    /*!< Frame error flag */
  kParityError = hardware::STAT::kPARITYERRINT, /*!< Parity error flag */
  kRxNoise = hardware::STAT::kRXNOISEINT,       /*!< Recieved noise flag */
  kAutobaudError = hardware::STAT::kABERR,      /*!< Autobaud error flags */
};
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
  constexpr std::uint32_t Init(std::uint32_t baud_rate, UartParities parity = UartParities::kNone,
                               UartStops stop_bits = UartStops::kStop1, UartLengths length_bits = UartLengths::kSize8) {
    std::uint32_t frequency = GetInputClockFreq<clock_config>();
    std::uint32_t divider = frequency / (baud_rate * 16);
    UsartPeripheral()->BRG = divider;
    UsartPeripheral()->CFG = hardware::CFG::kENABLE | static_cast<std::uint32_t>(length_bits) | static_cast<std::uint32_t>(parity) |
                             static_cast<std::uint32_t>(stop_bits);
    return frequency / 16 / divider;
  }
  /**
   * @brief return uart status
   * @return std::uint32_t one to one copy of the status register, see bit masks for options
   */
  constexpr std::uint32_t Status() {
    return UsartPeripheral()->STAT & hardware::STAT::RESERVED_MASK;
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
    data = static_cast<TransferType>(rx_status & hardware::RXDATSTAT::kDATA_MASK);
    status = rx_status & hardware::RXDATSTAT::kSTAT_MASK;
  }
  /**
   * @brief get the input clock of this UART peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t GetInputClockFreq() {
    // constexpr check if we configure the right peripheral
    if constexpr ((usart_address_ == libmcuhw::kUsart0Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART0))
      return clock_config.GetFrequency();
    else if constexpr ((usart_address_ == libmcuhw::kUsart1Address) &&
                       (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART1))
      return clock_config.GetFrequency();
    else if constexpr ((usart_address_ == libmcuhw::kUsart2Address) &&
                       (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::UART2))
      return clock_config.GetFrequency();
    else if constexpr ((usart_address_ == libmcuhw::kUsart3Address) &&
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
    return reinterpret_cast<hardware::Usart *>(usart_address_);
  }

 private:
  static constexpr libmcu::HwAddressType usart_address_ = usart_address; /*!< peripheral usartAddress */
};
}  // namespace libmcull::usart
#endif