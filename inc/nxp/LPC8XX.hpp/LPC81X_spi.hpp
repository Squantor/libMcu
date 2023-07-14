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

#include <span>

namespace instances {
namespace spi {

using namespace registers::spi;

/**
 * @brief SPI hardware chip enables
 *
 */
enum chipEnables : uint32_t {
  SSEL = (1 << 16), /**< Hardware chip enable */
};

template <uint32_t base>
struct spi {
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to spi registers
   */
  static auto regs() {
    return reinterpret_cast<registers::spi::registers *>(base);
  }

  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  uint32_t initMaster(uint32_t bitRate) {
    uint32_t actualBitRate = setBitRate(bitRate);
    regs()->CFG = CFG::ENABLE | CFG::MASTER;
    return actualBitRate;
  }

  // TODO: initMaster with alternative SSEL polarities
  // TODO: initMaster with CPOL/CPHA and SSEL polarities
  // TODO: initSlave();
  // TODO: initSlave with alternative SSEL polarities
  // TODO: initSlave with CPOL/CPHA and SSEL polarities

  /**
   * @brief Transmit data to SPI
   *
   * @param device SPI device to transmit to
   * @param transmitBuffer data to transmit
   * @param bitcount amount of bits to transmit
   * @param lastAction is this the last action? This will disable the chip select
   */
  void transmit(chipEnables device, const std::span<uint16_t> transmitBuffer, uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    uint32_t baseTransferCommand = TXDATCTL::TXSSEL(device) | TXDATCTL::RXIGNORE;  // base transfer command with presets
    while (bitcount > 16) {
      regs()->TXDATCTL = baseTransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(16);
      while ((regs()->STAT & STAT::TXRDY) == 0)
        ;
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      baseTransferCommand |= TXDATCTL::EOT;
    regs()->TXDATCTL = baseTransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(bitcount);
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
  void receive(chipEnables device, std::span<uint16_t> receiveBuffer, uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    uint32_t baseTransferCommand = TXDATCTL::TXSSEL(device);  // base transfer command with presets
    while (bitcount > 16) {
      regs()->TXDATCTL = baseTransferCommand | TXDATCTL::LEN(16);
      while ((regs()->STAT & STAT::RXRDY) == 0)
        ;
      receiveBuffer[index] = RXDAT::RXDAT(regs()->RXDAT);
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      baseTransferCommand |= TXDATCTL::EOT;
    regs()->TXDATCTL = baseTransferCommand | TXDATCTL::LEN(bitcount);
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
  void transceive(chipEnables device, const std::span<uint16_t> transmitBuffer, std::span<uint16_t> receiveBuffer,
                  uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    uint32_t baseTransferCommand = TXDATCTL::TXSSEL(device);  // base transfer command with presets
    while (bitcount > 16) {
      regs()->TXDATCTL = baseTransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(16);
      while ((regs()->STAT & STAT::RXRDY) == 0)
        ;
      receiveBuffer[index] = RXDAT::RXDAT(regs()->RXDAT);
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      baseTransferCommand |= TXDATCTL::EOT;
    regs()->TXDATCTL = baseTransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(bitcount);
    while ((regs()->STAT & STAT::RXRDY) == 0)
      ;
    receiveBuffer[index] = RXDAT::RXDAT(regs()->RXDAT);
  }

  // TODO: transceive with gpio chip select
  // TODO: transceive with chip select lambda
  // TODO: configure delay settings
};
}  // namespace spi
}  // namespace instances

#endif