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
enum class spiChipEnables : std::uint32_t {
  SSEL0 = (1 << 16), /**< Hardware chip enable 0 */
  SSEL1 = (1 << 17), /**< Hardware chip enable 1 */
  SSEL2 = (1 << 18), /**< Hardware chip enable 2 */
  SSEL3 = (1 << 19), /**< Hardware chip enable 3 */
};

/**
 * @brief XOR operator to use slave selects on std::uint32_t registers
 *
 * @param a register input
 * @param b slave select to xor
 * @return std::uint32_t register setting
 */
inline std::uint32_t operator^(std::uint32_t a, spiChipEnables b) {
  return a ^ static_cast<std::uint32_t>(b);
}

/**
 * @brief
 *
 * @tparam base
 * @tparam chipEnables
 */
template <std::uint32_t spiAddress, typename chipEnables>
struct spi {
  static auto spiPeripheral() {
    return reinterpret_cast<registers::spi::registers*>(spiAddress);
  }

  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  std::uint32_t init(std::uint32_t bitRate) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    spiPeripheral()->CFG = CFG::ENABLE | CFG::MASTER;
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
  std::uint32_t setBitRate(std::uint32_t bitRate) {
    // compute divider
    std::uint32_t divider = CLOCK_AHB / bitRate;
    spiPeripheral()->DIV = divider - 1; /**< Divider value is -1 encoded as per datasheet */
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
  void transmit(chipEnables device, const std::span<std::uint16_t> transmitBuffer, std::uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    std::uint32_t baseTransferCommand = (0x000F0000u ^ device) | TXDATCTL::RXIGNORE;  // base transfer command with presets
    while (bitcount > 16) {
      spiPeripheral()->TXDATCTL = baseTransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(16);
      while ((spiPeripheral()->STAT & STAT::TXRDY) == 0)
        ;
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      baseTransferCommand |= TXDATCTL::EOT;
    spiPeripheral()->TXDATCTL = baseTransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(bitcount);
    while ((spiPeripheral()->STAT & STAT::TXRDY) == 0)
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
  void receive(chipEnables device, std::span<std::uint16_t> receiveBuffer, std::uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    std::uint32_t baseTransferCommand = 0x000F0000u ^ device;  // base transfer command with presets
    while (bitcount > 16) {
      spiPeripheral()->TXDATCTL = baseTransferCommand | TXDATCTL::LEN(16);
      while ((spiPeripheral()->STAT & STAT::RXRDY) == 0)
        ;
      receiveBuffer[index] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      baseTransferCommand |= TXDATCTL::EOT;
    spiPeripheral()->TXDATCTL = baseTransferCommand | TXDATCTL::LEN(bitcount);
    while ((spiPeripheral()->STAT & STAT::RXRDY) == 0)
      ;
    receiveBuffer[index] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
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
  void transceive(chipEnables device, const std::span<std::uint16_t> transmitBuffer, std::span<std::uint16_t> receiveBuffer,
                  std::uint32_t bitcount, bool lastAction) {
    size_t index = 0;
    std::uint32_t baseTransferCommand = 0x000F0000u ^ device;  // base transfer command with presets
    while (bitcount > 16) {
      spiPeripheral()->TXDATCTL = baseTransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(16);
      while ((spiPeripheral()->STAT & STAT::RXRDY) == 0)
        ;
      receiveBuffer[index] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
      bitcount -= 16;
      index++;
    }
    // process remainder
    if (lastAction)
      baseTransferCommand |= TXDATCTL::EOT;
    spiPeripheral()->TXDATCTL = baseTransferCommand | TXDATCTL::TXDAT(transmitBuffer[index]) | TXDATCTL::LEN(bitcount);
    while ((spiPeripheral()->STAT & STAT::RXRDY) == 0)
      ;
    receiveBuffer[index] = RXDAT::RXDAT(spiPeripheral()->RXDAT);
  }
};
}  // namespace spi
}  // namespace instances

#endif