/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series SPI functions
 */
#ifndef LPC81X_SPI_HPP
#define LPC81X_SPI_HPP

#include <nxp/LPC8XX.hpp/LPC81X_spi_common.hpp>

namespace libMcuLL {
namespace sw {
namespace spi {

using namespace hw::spi;

/**
 * @brief synchronous SPI peripheral instance
 *
 * @tparam address_ Peripheral base address
 * @tparam chipEnables enum of available chip enables
 */
template <libMcuLL::SPIbaseAddress address_, typename chipEnables>
struct spiSync {
  static constexpr libMcuLL::hwAddressType address = address_; /**< peripheral address */
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to spi registers
   */
  static hw::spi::peripheral *regs() {
    return reinterpret_cast<hw::spi::peripheral *>(address);
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
  uint32_t initMaster(uint32_t bitRate) {
    uint32_t actualBitRate = setBitRate(bitRate);
    regs()->CFG = CFG::ENABLE | CFG::MASTER;
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
  uint32_t initMaster(uint32_t bitRate, waveforms waveform, slavePolaritySelects polarity) {
    uint32_t actualBitRate = setBitRate(bitRate);
    regs()->CFG = CFG::ENABLE | CFG::MASTER | static_cast<uint32_t>(waveform) | static_cast<uint32_t>(polarity);
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
  void write(chipEnables device, const std::span<uint16_t> transmitBuffer, uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    uint32_t address_TransferCommand = TXDATCTL::TXSSEL(device) | TXDATCTL::RXIGNORE;  // address_ transfer command with presets
    while (bitcount > 16) {
      regs()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(16);
      while ((regs()->STAT & STAT::TXRDY) == 0)
        ;
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      address_TransferCommand |= TXDATCTL::EOT;
    regs()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(bitcount);
    while ((regs()->STAT & STAT::TXRDY) == 0)
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
  void read(chipEnables device, std::span<uint16_t> receiveBuffer, uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    uint32_t address_TransferCommand = TXDATCTL::TXSSEL(device);  // address_ transfer command with presets
    while (bitcount > 16) {
      regs()->TXDATCTL = address_TransferCommand | TXDATCTL::LEN(16);
      while ((regs()->STAT & STAT::RXRDY) == 0)
        ;
      receiveBuffer[index] = RXDAT::RXDAT(regs()->RXDAT);
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      address_TransferCommand |= TXDATCTL::EOT;
    regs()->TXDATCTL = address_TransferCommand | TXDATCTL::LEN(bitcount);
    while ((regs()->STAT & STAT::RXRDY) == 0)
      ;
    receiveBuffer[index] = RXDAT::RXDAT(regs()->RXDAT);
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
  uint32_t setBitRate(uint32_t bitRate) {
    // compute divider and truncate so we can observe a possible round off
    uint16_t divider = static_cast<uint16_t>(CLOCK_AHB / bitRate);
    regs()->DIV = DIV::DIVVAL(divider);
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
  void readWrite(chipEnables device, const std::span<uint16_t> transmitBuffer, std::span<uint16_t> receiveBuffer, uint32_t bitcount,
                 bool lastAction) {
    size_t index = 0;
    uint32_t address_TransferCommand = TXDATCTL::TXSSEL(device);
    while (bitcount > 16) {
      regs()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(16);
      while ((regs()->STAT & STAT::RXRDY) == 0)
        ;
      receiveBuffer[index] = RXDAT::RXDAT(regs()->RXDAT);
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      address_TransferCommand |= TXDATCTL::EOT;
    regs()->TXDATCTL = address_TransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(bitcount);
    while ((regs()->STAT & STAT::RXRDY) == 0)
      ;
    receiveBuffer[index] = RXDAT::RXDAT(regs()->RXDAT);
  }

  // TODO: readWrite with gpio chip select
  // TODO: readWrite with chip select lambda
  // TODO: configure delay settings
};
}  // namespace spi
}  // namespace sw
}  // namespace libMcuLL

#endif