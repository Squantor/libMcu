/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC84X series SPI functions
 */
#ifndef LPC84X_SPI_HPP
#define LPC84X_SPI_HPP

#include <span>

namespace instances {
namespace spi {

using namespace registers::spi;

/**
 * @brief SPI hardware chip enables
 *
 */
enum class spiChipEnables : uint32_t {
  SSEL0 = (1 << 16), /**< Hardware chip enable 0 */
  SSEL1 = (1 << 17), /**< Hardware chip enable 1 */
  SSEL2 = (1 << 18), /**< Hardware chip enable 2 */
  SSEL3 = (1 << 19), /**< Hardware chip enable 3 */
};

/**
 * @brief XOR operator to use slave selects on uint32_t registers
 *
 * @param a register input
 * @param b slave select to xor
 * @return uint32_t register setting
 */
inline uint32_t operator^(uint32_t a, spiChipEnables b) {
  return a ^ static_cast<uint32_t>(b);
}

template <uint32_t base, typename chipEnables>
struct spi {
  static auto regs() {
    return reinterpret_cast<registers::spi::registers*>(base);
  }

  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  uint32_t init(uint32_t bitRate) {
    uint32_t actualBitRate = setBitRate(bitRate);
    regs()->CFG = CFG::ENABLE | CFG::MASTER;
    return actualBitRate;
  }

  /**
   * @brief Set the SPI peripheral bit rate
   *
   * Uses defined CLOCK_AHB to compute the actual bit rate
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  uint32_t setBitRate(uint32_t bitRate) {
    // compute divider
    uint32_t divider = CLOCK_AHB / bitRate;
    regs()->DIV = divider - 1; /**< Divider value is -1 encoded as per datasheet */
    return CLOCK_AHB / divider;
  }
  /**
   * @brief Transmit data to SPI
   *
   * @param device SPI device to transmit to
   * @param transmitBuffer data to transmit
   * @param bitcount amount of bits to transmit
   * @param lastAction is this the last action? This will disable the chip select
   */
  void transmit(chipEnables device, const std::span<uint16_t> transmitBuffer, uint16_t bitcount, bool lastAction) {
    size_t index = 0;
    uint32_t baseTransferCommand = (0x000F0000u ^ device) | TXDATCTL::RXIGNORE;  // base transfer command with presets
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
  /**
   * @brief Receive data from SPI, transmitter is active but transmits zeroes, disable MOSI if you want to float it
   *
   * @param device SPI device to receive data from
   * @param receiveBuffer buffer to put data into
   * @param bitcount amount of bits to receive
   * @param lastAction is this the last action? This will disable the chip select
   */
  void receive(chipEnables device, std::span<uint16_t> receiveBuffer, uint16_t bitcount, bool lastAction) {
    size_t index = 0;
    uint32_t baseTransferCommand = 0x000F0000u ^ device;  // base transfer command with presets
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
                  uint16_t bitcount, bool lastAction) {
    size_t index = 0;
    uint32_t baseTransferCommand = 0x000F0000u ^ device;  // base transfer command with presets
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
};
}  // namespace spi
}  // namespace instances

#endif