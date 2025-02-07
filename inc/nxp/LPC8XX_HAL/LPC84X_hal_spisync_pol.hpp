/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_hal_spi_sync_pol.hpp
 * @brief LPC840 series synchronous polling SPI HAL
 */
#ifndef LPC84X_HAL_SPISYNC_POL_HPP
#define LPC84X_HAL_SPISYNC_POL_HPP

#include "LPC84X_hal_spi_common.hpp"

namespace libMcuHal::spi {
namespace hardware = libMcuHw::spi;
namespace nvic = libMcuHw::nvic;

/**
 * @brief Polling SPI HAL class
 * @todo write with a software slave select, preferably a gpio? Would require a gpio hal access parameter
 * @tparam spiBaseAddress_ Base address of the spi peripheral structure
 */
template <libMcu::spiBaseAddress const& spiBaseAddress_>
struct spiSyncPol {
  /**
   * @brief Construct a new synchronous polling spi
   */
  spiSyncPol() {}

  template <const libMcuHw::clock::periClockConfig& t_clockConfig>
  /**
   * @brief Initialize SPI peripheral
   * @param bitRate SPI bit rate
   * @param selectPolarity Mask with chip select polarities for the 4 hardware chip selects
   * @param preDelay Delay in SPI clocks between chip select assertion and first bit
   * @param postDelay Delay in SPI clocks between last bit and chip select deassertion
   * @param frameDelay Delay in SPI clocks between frames
   * @param transferDelay Delay in SPI clocks between transfers
   * @return actual SPI bit rate
   */
  constexpr std::uint32_t init(std::uint32_t bitRate, std::uint32_t selectPolarity = 0, std::uint32_t preDelay = 0,
                               std::uint32_t postDelay = 0, std::uint32_t frameDelay = 0, std::uint32_t transferDelay = 0) {
    while (!(spiPeripheral()->STAT & hardware::STAT::MSTIDLE))
      ;
    spiPeripheral()->CFG = 0;  // disable
    std::uint32_t peripheralFrequency = getInputClockFreq<t_clockConfig>();
    std::uint32_t divider = peripheralFrequency / bitRate;
    spiPeripheral()->DIV = hardware::DIV::DIVVAL(divider);
    spiPeripheral()->DLY = hardware::DLY::PRE_DELAY(preDelay) | hardware::DLY::POST_DELAY(postDelay) |
                           hardware::DLY::FRAME_DELAY(frameDelay) | hardware::DLY::TRANSFER_DELAY(transferDelay);
    std::uint32_t config = hardware::CFG::ENABLE | hardware::CFG::MASTER;
    config |= hardware::CFG::SPOL(selectPolarity);
    spiPeripheral()->CFG = config;
    return peripheralFrequency / divider;
  }
  constexpr void write(const std::span<const uint8_t> data, const std::uint32_t bitSize,
                       spiSlaveSelects select = spiSlaveSelects::None, bool endOfTransfer = true, bool lsbFirst = false) {
    writeGeneric(data, bitSize, select, endOfTransfer, lsbFirst);
  }
  constexpr void write(const std::span<const uint16_t> data, const std::uint32_t bitSize,
                       spiSlaveSelects select = spiSlaveSelects::None, bool endOfTransfer = true, bool lsbFirst = false) {
    writeGeneric(data, bitSize, select, endOfTransfer, lsbFirst);
  }

  template <typename bufferType>
  constexpr void writeGeneric(const std::span<const bufferType> data, const std::uint32_t bitSize, spiSlaveSelects select,
                              bool endOfTransfer, bool lsbFirst) {
    // check if busy
    while (!(spiPeripheral()->STAT & hardware::STAT::MSTIDLE))
      ;
    // configure new settings
    std::uint32_t config = spiPeripheral()->CFG;
    if (lsbFirst)
      config |= hardware::CFG::LSBF;
    else
      config &= ~hardware::CFG::LSBF;
    spiPeripheral()->CFG = config;
    // setup transfer
    uint32_t txctl =
      hardware::TXCTL::LEN(bitSize) | hardware::TXCTL::TXSSEL(static_cast<std::uint32_t>(select)) | hardware::TXCTL::RXIGNORE;
    spiPeripheral()->TXCTL = txctl;
    std::size_t index = 0;
    // write data minus one element
    while (index < data.size() - 1) {
      while (!(spiPeripheral()->STAT & hardware::STAT::TXRDY))
        ;
      spiPeripheral()->TXDAT = data[index];
      index++;
    }
    // write last data and terminate transfer if needed
    while (!(spiPeripheral()->STAT & hardware::STAT::TXRDY))
      ;
    if (endOfTransfer)
      txctl |= hardware::TXCTL::EOT;
    spiPeripheral()->TXCTL = txctl;
    spiPeripheral()->TXDAT = data[index];
  }
  // @todo write with clock speed
  // @todo read
  // @todo read and clock speed
  // @todo readWrite
  // @todo readWrite and clock speed
  /**
   * @brief get the input clock of this spi peripheral
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <auto& config>
  constexpr std::uint32_t getInputClockFreq() {
    static_assert(config.peripheral == libMcuHw::clock::periSelect::SPI0);
    return config.getFrequency();
  }
  /**
   * @brief access spi registers
   * @return return pointer to peripheral
   */
  static hardware::spi* spiPeripheral() {
    return reinterpret_cast<hardware::spi*>(spiBaseAddress);
  }

  static constexpr libMcu::hwAddressType spiBaseAddress = spiBaseAddress_; /**< SPI peripheral address */
};

}  // namespace libMcuHal::spi

#endif