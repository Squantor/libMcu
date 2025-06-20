/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_spi_poll_ll.hpp
 * @brief LPC810 series polled synchronous SPI interface class and definitions
 */
#ifndef LPC81X_SPI_POLL_LL_HPP
#define LPC81X_SPI_POLL_LL_HPP

#include "LPC81X_spi_common_ll.hpp"

namespace libmcull::spi {
namespace hardware = libmcuhw::spi;
/**
 * @brief synchronous SPI peripheral instance
 * @tparam spi_address Peripheral base spi_address_
 * @tparam chipEnables enum of available chip enables
 * @tparam transferType datatype to use for data transfers
 * @todo Slave initializations
 */
template <libmcu::SpiBaseAddress spi_address, typename ChipEnable, typename TransferType>
struct SpiPolled : libmcull::PeripheralBase {
  /**
   * @brief Initialise SPI peripheral as master device, LSB first mode, CPHA is 0, CPOL is 0,
   * @param bit_rate requested bit rate
   * @return actual bit rate
   */
  constexpr std::uint32_t InitMaster(std::uint32_t bit_rate) {
    std::uint32_t actual_bitrate = SetBitRate(bit_rate);
    GetPeripheral()->CFG = hardware::CFG::kENABLE | hardware::CFG::kMASTER;
    return actual_bitrate;
  }
  /**
   * @brief Initialise SPI peripheral as master device with custom settings
   * @param bit_rate requested bit rate
   * @param waveform SPI waveform, see waveforms for options
   * @param polarity SPI slave select polarity
   * @return actual bit rate
   */
  constexpr std::uint32_t InitMaster(std::uint32_t bit_rate, Waveforms waveform, SlavePolaritySelects polarity) {
    std::uint32_t actual_bitrate = SetBitRate(bit_rate);
    GetPeripheral()->CFG =
      hardware::CFG::kENABLE | hardware::CFG::kMASTER | static_cast<std::uint32_t>(waveform) | static_cast<std::uint32_t>(polarity);
    return actual_bitrate;
  }
  /**
   * @brief Transmit data to SPI device
   * @param device SPI device to transmit to
   * @param transmit_buffer data to transmit
   * @param bit_count amount of bits to transmit
   * @param last_action is this the last action? This will disable the chip select
   */
  constexpr void Transmit(ChipEnable device, const std::span<std::uint16_t> transmit_buffer, std::uint32_t bit_count,
                          bool last_action) {
    size_t index = 0u;
    std::uint32_t transfer_command =
      hardware::TXDATCTL::TXSSEL(device) | hardware::TXDATCTL::kRXIGNORE;  // spi_address__ transfer command with presets
    while (bit_count > 16u) {
      GetPeripheral()->TXDATCTL =
        transfer_command | hardware::TXDATCTL::TXDAT(transmit_buffer[index]) | hardware::TXDATCTL::LEN(16);
      while ((GetPeripheral()->STAT & hardware::STAT::kTXRDY) == 0u)
        ;
      bit_count -= 16u;
      index++;
    }
    // process remainder
    if (last_action)
      transfer_command |= hardware::TXDATCTL::kEOT;
    GetPeripheral()->TXDATCTL =
      transfer_command | hardware::TXDATCTL::TXDAT(transmit_buffer[index]) | hardware::TXDATCTL::LEN(bit_count);
    while ((GetPeripheral()->STAT & hardware::STAT::kTXRDY) == 0u)
      ;
  }
  /**
   * @brief Receive data from SPI device, transmitter is active but transmits zeroes, disable MOSI if you want to float it
   * @param device SPI device to receive data from
   * @param receive_buffer buffer to put data into
   * @param bit_count amount of bits to receive
   * @param last_action is this the last action? This will disable the chip select
   */
  constexpr void Receive(ChipEnable device, std::span<std::uint16_t> receive_buffer, std::uint32_t bit_count, bool last_action) {
    size_t index = 0u;
    std::uint32_t transfer_command =
      hardware::TXDATCTL::TXSSEL(static_cast<std::uint32_t>(device));  // spi_address__ transfer command with presets
    while (bit_count > 16u) {
      GetPeripheral()->TXDATCTL = transfer_command | hardware::TXDATCTL::LEN(16);
      while ((GetPeripheral()->STAT & hardware::STAT::kRXRDY) == 0u)
        ;
      receive_buffer[index] = hardware::RXDAT::RXDAT(GetPeripheral()->RXDAT);
      bit_count -= 16u;
      index++;
    }
    // process remainder
    if (last_action)
      transfer_command |= hardware::TXDATCTL::kEOT;
    GetPeripheral()->TXDATCTL = transfer_command | hardware::TXDATCTL::LEN(bit_count);
    while ((GetPeripheral()->STAT & hardware::STAT::kRXRDY) == 0u)
      ;
    receive_buffer[index] = hardware::RXDAT::RXDAT(GetPeripheral()->RXDAT);
  }
  /**
   * @brief Set the SPI peripheral bit rate
   * @param bit_rate requested bit rate
   * @return actual bit rate
   */
  constexpr std::uint32_t SetBitRate(std::uint32_t bit_rate) {
    // compute divider and truncate so we can observe a possible round off
    std::uint16_t divider = static_cast<std::uint16_t>(CLOCK_AHB / bit_rate);
    GetPeripheral()->DIV = hardware::DIV::DIVVAL(divider);
    return CLOCK_AHB / divider;
  }
  /**
   * @brief Transmit and recieve data via SPI
   * @param device SPI device to use
   * @param transmit_buffer data to transmit
   * @param receive_buffer buffer to put data into
   * @param bit_count amount of bits
   * @param last_action is this the last action? This will disable the chip select
   */
  constexpr void Transceive(ChipEnable device, const std::span<std::uint16_t> transmit_buffer,
                            std::span<std::uint16_t> receive_buffer, std::uint32_t bit_count, bool last_action) {
    size_t index = 0u;
    std::uint32_t transfer_command = hardware::TXDATCTL::TXSSEL(static_cast<std::uint32_t>(device));
    while (bit_count > 16u) {
      GetPeripheral()->TXDATCTL =
        transfer_command | hardware::TXDATCTL::TXDAT(transmit_buffer[index]) | hardware::TXDATCTL::LEN(16);
      while ((GetPeripheral()->STAT & hardware::STAT::kRXRDY) == 0u)
        ;
      receive_buffer[index] = hardware::RXDAT::RXDAT(GetPeripheral()->RXDAT);
      bit_count -= 16u;
      index++;
    }
    // process remainder
    if (last_action)
      transfer_command |= hardware::TXDATCTL::kEOT;
    GetPeripheral()->TXDATCTL =
      transfer_command | hardware::TXDATCTL::TXDAT(transmit_buffer[index]) | hardware::TXDATCTL::LEN(bit_count);
    while ((GetPeripheral()->STAT & hardware::STAT::kRXRDY) == 0u)
      ;
    receive_buffer[index] = hardware::RXDAT::RXDAT(GetPeripheral()->RXDAT);
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to spi registers
   */
  constexpr hardware::Spi *GetPeripheral() {
    return reinterpret_cast<hardware::Spi *>(spi_address_);
  }

 private:
  static constexpr libmcu::HwAddressType spi_address_ = spi_address; /*!< peripheral spi_address_ */
};
}  // namespace libmcull::spi
#endif