/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_sync_usart_ll.hpp
 * @brief Synchronous low level USART interface for the LPC840 series
 */
#ifndef LPC84X_SYNC_USART_LL_HPP
#define LPC84X_SYNC_USART_LL_HPP

namespace libmcull::usart {
namespace hardware = ::libMcuHw::usart;
/**
 * @brief amount of bits to transmit
 */
enum class UartLengths : std::uint32_t {
  kSize7 = hardware::CFG::DATALEN7BIT, /*!< USART transmit length of 7 bits */
  kSize8 = hardware::CFG::DATALEN8BIT, /*!< USART transmit length of 8 bits */
  kSize9 = hardware::CFG::DATALEN9BIT, /*!< USART transmit length of 9 bits */
};

/**
 * @brief Parity bit options
 */
enum class UartParities : std::uint32_t {
  kNone = hardware::CFG::PARITY_NONE, /*!< No parity */
  kEven = hardware::CFG::PARITY_EVEN, /*!< Even parity */
  kOdd = hardware::CFG::PARITY_ODD,   /*!< Odd parity */
};

/**
 * @brief stop bit options
 */
enum class UartStops : std::uint32_t {
  kStop1 = hardware::CFG::STOPBIT1, /*!< 1 stop bit */
  kStop2 = hardware::CFG::STOPBIT2, /*!< 2 stop bits */
};

/**
 * @brief Uart status bits
 * These bit patterns match the USART STAT register settings
 */
enum UartStatuses : std::uint32_t {
  kRxReady = hardware::STAT::RXRDY,            /*!< Receiver ready flag*/
  kRxIdle = hardware::STAT::RXIDLE,            /*!< Receiver idle flag */
  kTxReady = hardware::STAT::TXRDY,            /*!< Transmitter ready flag  */
  kTxIdle = hardware::STAT::TXIDLE,            /*!< Transmitter idle flag */
  kCts = hardware::STAT::CTS,                  /*!< CTS signal state flag */
  kCtsChange = hardware::STAT::DELTACTS,       /*!< Change detected in CTS signal flag */
  kTxDisable = hardware::STAT::TXDISINT,       /*!< Transmitter disabled confirmation flag */
  kOverrun = hardware::STAT::OVERRUNINT,       /*!< Overrun error flag */
  kRxBreak = hardware::STAT::RXBRK,            /*!< Received break flag */
  kRxBreakChange = hardware::STAT::DELTARXBRK, /*!< Change detected in receiver break flag */
  kStart = hardware::STAT::START,              /*!< Start condition detected flag */
  kFrameError = hardware::STAT::FRAMERRINT,    /*!< Frame error flag */
  kParityError = hardware::STAT::PARITYERRINT, /*!< Parity error flag */
  kRxNoise = hardware::STAT::RXNOISEINT,       /*!< Recieved noise flag */
  kAutobaudError = hardware::STAT::ABERR,      /*!< Autobaud error flags */
};

/**
 * @brief synchronous USART peripheral instance
 * @tparam usart_address Peripheral base usartAddress
 * @tparam TransferType datatype to use for data transfers
 */
template <libmcuhw::UartBaseAddress usart_address, typename TransferType>
struct SyncUart : libmcull::LlSyncUartBase {
  /**
   * @brief Setup USART
   * @tparam &clock_config clock configuration to use
   * @param baud_rate Baud rate value
   * @param length_bits bit length of transmissions
   * @param parity parity type of transmissions
   * @param stop_bits Amount of stop bits
   * @return actual baud rate
   */
  template <const libMcuHw::clock::periClockConfig &clock_config>
  constexpr std::uint32_t Init(std::uint32_t baud_rate, UartParities parity = UartParities::kNone,
                               UartStops stop_bits = UartStops::kStop1, UartLengths length_bits = UartLengths::kSize8) {
    std::uint32_t frequency = GetInputClockFreq<clock_config>();
    std::uint32_t divider = frequency / (baud_rate * 16);
    UsartPeripheral()->BRG = divider;
    UsartPeripheral()->CFG = hardware::CFG::ENABLE | static_cast<std::uint32_t>(length_bits) | static_cast<std::uint32_t>(parity) |
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
    data = static_cast<TransferType>(rx_status & hardware::RXDATSTAT::DATA_MASK);
    status = rx_status & hardware::RXDATSTAT::STAT_MASK;
  }
  /**
   * @brief get the input clock of this UART peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <const libMcuHw::clock::periClockConfig &clock_config>
  constexpr std::uint32_t GetInputClockFreq() {
    // constexpr check if we configure the right peripheral
    if constexpr ((usartAddress_ == libMcuHw::usart0Address) && (clock_config.peripheral == libMcuHw::clock::periSelect::UART0))
      return clock_config.getFrequency();
    else if constexpr ((usartAddress_ == libMcuHw::usart1Address) &&
                       (clock_config.peripheral == libMcuHw::clock::periSelect::UART1))
      return clock_config.getFrequency();
    else if constexpr ((usartAddress_ == libMcuHw::usart2Address) &&
                       (clock_config.peripheral == libMcuHw::clock::periSelect::UART2))
      return clock_config.getFrequency();
    else if constexpr ((usartAddress_ == libMcuHw::usart3Address) &&
                       (clock_config.peripheral == libMcuHw::clock::periSelect::UART3))
      return clock_config.getFrequency();
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
  constexpr static hardware::usart *UsartPeripheral() {
    return reinterpret_cast<hardware::usart *>(usartAddress_);
  }

 private:
  static constexpr libmcu::hwAddressType usartAddress_ = usart_address; /*!< peripheral usartAddress */
};
}  // namespace libmcull::usart
#endif