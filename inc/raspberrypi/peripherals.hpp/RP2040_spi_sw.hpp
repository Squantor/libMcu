/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 SPI GPIO software interface
 */
#ifndef RP2040_SPI_SW_HPP
#define RP2040_SPI_SW_HPP

namespace libMcuLL::sw::spi {
/**
 * @brief Frame formats available
 */
enum class frameFormats : std::uint32_t {
  MOTOROLA = libMcuHw::spi::SSPCR0::FRF_MOTOROLA, /**< Motorola frame format */
  TI = libMcuHw::spi::SSPCR0::FRF_TI,             /**< Texas instruments frame format */
  NATIONAL = libMcuHw::spi::SSPCR0::FRF_NATIONAL, /**< National microwire frame format */
};
/**
 * @brief SPI hardware chip enables
 *
 */
enum class chipEnables : std::uint32_t {
  SSEL_NONE = 0,    /**< No chip select */
  SSEL = (1 << 16), /**< Hardware chip enable */
};
/**
 * @brief possible SPI clocking/phasing/ordering
 *
 */
enum class waveforms : std::uint32_t {
  CPHA0_CPOL0 = 0,                                                       /**< CPHA is 0, CPOL is 0, MSB first */
  CPHA1_CPOL0 = libMcuHw::spi::SSPCR0::SPH,                              /**< CPHA is 1, CPOL is 0, MSB first */
  CPHA0_CPOL1 = libMcuHw::spi::SSPCR0::SPO,                              /**< CPHA is 0, CPOL is 1, MSB first */
  CPHA1_CPOL1 = libMcuHw::spi::SSPCR0::SPH | libMcuHw::spi::SSPCR0::SPO, /**< CPHA is 1, CPOL is 1, MSB first */
};

template <libMcu::spiBaseAddress const& spiAddress_>
struct spi : libMcu::peripheralBase {
  /**
   * @brief Base initialization function
   */
  constexpr void init() {}
  /**
   * @brief Setup SPI with motorola format
   * @param bitRate requested bit rate
   * @param waveform waveform to output, see sw::spi::waveforms
   * @return actual bit rate
   */
  constexpr std::uint32_t setupMaster(std::uint32_t bitRate, waveforms waveform) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    std::uint32_t cr0setting = spiPeripheral()->SSPCR0 & ~libMcuHw::spi::SSPCR0::FORMAT_MASK;
    cr0setting |= static_cast<std::uint32_t>(waveform) | libMcuHw::spi::SSPCR0::FRF_MOTOROLA;
    spiPeripheral()->SSPCR0 = cr0setting;
    return actualBitRate;
  }
  // TODO: SPI master initialisation method with frame format selection
  // TODO: SPI slave initialisation method with standard waveform
  // TODO: SPI slave initialisation method with waveform selection
  constexpr void write() {}
  constexpr void read() {}
  constexpr void readWrite(const std::span<std::uint16_t> transmitBuffer, std::span<std::uint16_t> receiveBuffer,
                           std::uint32_t bitcount) {
    size_t transmitIndex = 0u;
    size_t receiveIndex = 0u;
    spiPeripheral()->SSPCR0 = (spiPeripheral()->SSPCR0 & ~libMcuHw::spi::SSPCR0::DSS_MASK) | libMcuHw::spi::SSPCR0::DSS(bitcount);
    spiPeripheral()->SSPCR1 = libMcuHw::spi::SSPCR1::SSE;
    while (transmitIndex != transmitBuffer.size()) {
      // TX FIFO not full? Add one element, as we loop we will fill the TX buffer in short order
      if (spiPeripheral()->SSPSR & libMcuHw::spi::SSPSR::TNF_MASK) {
        spiPeripheral()->SSPDR = transmitBuffer[transmitIndex];
        transmitIndex++;
      }
      // if we get some data in the mean time, put it in the receive buffer
      if (spiPeripheral()->SSPSR & libMcuHw::spi::SSPSR::RNE_MASK) {
        receiveBuffer[receiveIndex] = spiPeripheral()->SSPDR;
        receiveIndex++;
      }
    }
    // receive remaining data
    while (transmitIndex > receiveIndex) {
      if (spiPeripheral()->SSPSR & libMcuHw::spi::SSPSR::RNE_MASK) {
        receiveBuffer[receiveIndex] = spiPeripheral()->SSPDR;
        receiveIndex++;
      }
    }
    spiPeripheralClear()->SSPCR1 = libMcuHw::spi::SSPCR1::SSE;
  }

  /**
   * @brief Set the SPI peripheral bit rate
   *
   * Uses defined CLOCK_AHB to compute the actual bit rate
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  constexpr std::uint32_t setBitRate(std::uint32_t bitRate) {
    // compute divider and truncate so we can observe a possible round off
    std::uint16_t divider = static_cast<std::uint16_t>(FREQ_PERI / 2 / bitRate);
    spiPeripheral()->SSPCPSR = 2; /* divide by two as a minimum */
    spiPeripheral()->SSPCR0 = (spiPeripheral()->SSPCR0 & ~libMcuHw::spi::SSPCR0::SCR_MASK) | libMcuHw::spi::SSPCR0::SCR(divider);
    return FREQ_PERI / 2 / divider;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static libMcuHw::spi::peripheral* spiPeripheral() {
    return reinterpret_cast<libMcuHw::spi::peripheral*>(spiAddress);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static libMcuHw::spi::peripheral* spiPeripheralSet() {
    return reinterpret_cast<libMcuHw::spi::peripheral*>(spiAddress + libMcuHw::peripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static libMcuHw::spi::peripheral* spiPeripheralClear() {
    return reinterpret_cast<libMcuHw::spi::peripheral*>(spiAddress + libMcuHw::peripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static libMcuHw::spi::peripheral* spiPeripheralXor() {
    return reinterpret_cast<libMcuHw::spi::peripheral*>(spiAddress + libMcuHw::peripheralOffsetXor);
  }

 private:
  static constexpr libMcu::hwAddressType spiAddress{spiAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sw::spi
#endif