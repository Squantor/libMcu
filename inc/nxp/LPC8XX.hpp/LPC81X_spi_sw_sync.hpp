/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series synchronous SPI functions
 */
#ifndef LPC81X_SPI_HPP
#define LPC81X_SPI_HPP

#include <nxp/LPC8XX.hpp/LPC81X_spi_sw_common.hpp>

namespace libMcuLL {
namespace sw {
namespace spi {

using namespace hw::spi;

/**
 * @brief synchronous SPI peripheral instance
 *
 * @tparam spiAddress_ Peripheral base spiAddress
 * @tparam chipEnables enum of available chip enables
 * @tparam transferType datatype to use for data transfers
 */
template <libMcuLL::SPIbaseAddress spiAddress_, typename chipEnables, typename transferType>
struct spiSync {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to spi registers
   */
  static hw::spi::peripheral *spiPeripheral() {
    return reinterpret_cast<hw::spi::peripheral *>(spiAddress);
  }

  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   * LSB first mode, CPHA is 0, CPOL is 0,
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  std::uint32_t initMaster(std::uint32_t bitRate) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    spiPeripheral()->CFG = CFG::ENABLE | CFG::MASTER;
    return actualBitRate;
  }

  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   * LSB first mode, CPHA is 0, CPOL is 0,
   *
   * @param bitRate requested bit rate
   * @param waveform SPI waveform, see waveforms for options
   * @param polarity SPI slave select polarity
   * @return actual bit rate
   */
  std::uint32_t initMaster(std::uint32_t bitRate, waveforms waveform, slavePolaritySelects polarity) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    spiPeripheral()->CFG = CFG::ENABLE | CFG::MASTER | static_cast<std::uint32_t>(waveform) | static_cast<std::uint32_t>(polarity);
    return actualBitRate;
  }

  // TODO: SPI slave initialisation method with standard waveform
  // TODO: SPI slave initialisation method with waveform selection

  /**
   * @brief Transmit data to SPI
   *
   * @param device SPI device to transmit to
   * @param transmitBuffer data to transmit
   * @param bitcount amount of bits to transmit
   * @param lastAction is this the last action? This will disable the chip select
   */
  void write(chipEnables device, const std::span<std::uint16_t> transmitBuffer, std::uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    std::uint32_t address_TransferCommand =
      TXDATCTL::TXSSEL(device) | TXDATCTL::RXIGNORE;  // spiAddress_ transfer command with presets
    while (bitcount > 16) {
      spiPeripheral()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(16);
      while ((spiPeripheral()->STAT & STAT::TXRDY) == 0)
        ;
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      address_TransferCommand |= TXDATCTL::EOT;
    spiPeripheral()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(bitcount);
    while ((spiPeripheral()->STAT & STAT::TXRDY) == 0)
      ;
  }

  // TODO: transmit with gpio chip select
  // TODO: transmit with chip select lambda

  /**
   * @brief Receive data from SPI, transmitter is active but transmits zeroes, disable MOSI if you want to float it
   *
   * @param device SPI device to receive data from
   * @param receiveBuffer buffer to put data into
   * @param bitcount amount of bits to receive
   * @param lastAction is this the last action? This will disable the chip select
   */
  void read(chipEnables device, std::span<std::uint16_t> receiveBuffer, std::uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    std::uint32_t address_TransferCommand = TXDATCTL::TXSSEL(device);  // spiAddress_ transfer command with presets
    while (bitcount > 16) {
      spiPeripheral()->TXDATCTL = address_TransferCommand | TXDATCTL::LEN(16);
      while ((spiPeripheral()->STAT & STAT::RXRDY) == 0)
        ;
      receiveBuffer[index] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      address_TransferCommand |= TXDATCTL::EOT;
    spiPeripheral()->TXDATCTL = address_TransferCommand | TXDATCTL::LEN(bitcount);
    while ((spiPeripheral()->STAT & STAT::RXRDY) == 0)
      ;
    receiveBuffer[index] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
  }

  // TODO: receive with gpio chip select
  // TODO: receive with chip select lambda

  /**
   * @brief Set the SPI peripheral bit rate
   *
   * Uses defined CLOCK_AHB to compute the actual bit rate
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  std::uint32_t setBitRate(std::uint32_t bitRate) {
    // compute divider and truncate so we can observe a possible round off
    std::uint16_t divider = static_cast<std::uint16_t>(CLOCK_AHB / bitRate);
    spiPeripheral()->DIV = DIV::DIVVAL(divider);
    return CLOCK_AHB / divider;
  }

  /**
   * @brief Transmit and recieve data via SPI
   *
   * @param device SPI device to use
   * @param transmitBuffer data to transmit
   * @param receiveBuffer buffer to put data into
   * @param bitcount amount of bits
   * @param lastAction is this the last action? This will disable the chip select
   */
  void readWrite(chipEnables device, const std::span<std::uint16_t> transmitBuffer, std::span<std::uint16_t> receiveBuffer,
                 std::uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    std::uint32_t address_TransferCommand = TXDATCTL::TXSSEL(device);
    while (bitcount > 16) {
      spiPeripheral()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(16);
      while ((spiPeripheral()->STAT & STAT::RXRDY) == 0)
        ;
      receiveBuffer[index] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      address_TransferCommand |= TXDATCTL::EOT;
    spiPeripheral()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(bitcount);
    while ((spiPeripheral()->STAT & STAT::RXRDY) == 0)
      ;
    receiveBuffer[index] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
  }

  // TODO: readWrite with gpio chip select
  // TODO: readWrite with chip select lambda
  // TODO: configure delay settings
 private:
  static constexpr libMcuLL::hwAddressType spiAddress = spiAddress_; /**< peripheral spiAddress */
};
}  // namespace spi
}  // namespace sw
}  // namespace libMcuLL

#endif