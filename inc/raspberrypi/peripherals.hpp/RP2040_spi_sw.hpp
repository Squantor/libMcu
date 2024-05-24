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
using namespace libMcuLL;
/**
 * @brief Frame formats available
 */
enum class frameFormats : std::uint32_t {
  MOTOROLA = hw::spi::SSPCR0::FRF_MOTOROLA, /**< Motorola frame format */
  TI = hw::spi::SSPCR0::FRF_TI,             /**< Texas instruments frame format */
  NATIONAL = hw::spi::SSPCR0::FRF_NATIONAL, /**< National microwire frame format */
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
  // CPHA0_CPOL0_MSB = 0,                                 /**< CPHA is 0, CPOL is 0, MSB first */
  // CPHA1_CPOL0_MSB = CFG::CPHA,                         /**< CPHA is 1, CPOL is 0, MSB first */
  // CPHA0_CPOL1_MSB = CFG::CPOL,                         /**< CPHA is 0, CPOL is 1, MSB first */
  // CPHA1_CPOL1_MSB = CFG::CPHA | CFG::CPOL,             /**< CPHA is 1, CPOL is 1, MSB first */
  // CPHA0_CPOL0_LSB = CFG::LSBF,                         /**< CPHA is 0, CPOL is 0, LSB first */
  // CPHA1_CPOL0_LSB = CFG::CPHA | CFG::LSBF,             /**< CPHA is 1, CPOL is 0, LSB first */
  // CPHA0_CPOL1_LSB = CFG::CPOL | CFG::LSBF,             /**< CPHA is 0, CPOL is 1, LSB first */
  // CPHA1_CPOL1_LSB = CFG::CPHA | CFG::CPOL | CFG::LSBF, /**< CPHA is 1, CPOL is 1, LSB first */
};

template <libMcuLL::spiBaseAddress const& spiAddress_>
struct spi : libMcuLL::peripheralBase {
  /**
   * @brief Base initialization function
   *
   */
  constexpr void init() {}
  /**
   * @brief Initialise SPI peripheral as master device
   *
   * Make sure clocks are enabled to the SPI peripheral first before calling this method!
   * LSB first mode, CPHA is 0, CPOL is 0,
   *
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  constexpr std::uint32_t initMaster(std::uint32_t bitRate) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    std::uint32_t cr0setting = frameFormats::MOTOROLA;
    spiPeripheral()->SSPCR0 = cr0setting;
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
  constexpr std::uint32_t initMaster(std::uint32_t bitRate, frameFormats format, waveforms waveform) {
    std::uint32_t actualBitRate = setBitRate(bitRate);
    // spiPeripheral()->CFG = CFG::ENABLE | CFG::MASTER | static_cast<std::uint32_t>(waveform) |
    // static_cast<std::uint32_t>(polarity);
    return actualBitRate;
  }
  // TODO: SPI slave initialisation method with standard waveform
  // TODO: SPI slave initialisation method with waveform selection
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
    std::uint16_t divider = static_cast<std::uint16_t>(FREQ_PERI / bitRate);
    // spiPeripheral()->DIV = DIV::DIVVAL(divider);
    // return CLOCK_AHB / divider;
    return 0;
  }
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::spi::peripheral* spiPeripheral() {
    return reinterpret_cast<hw::spi::peripheral*>(spiAddress);
  }

 private:
  static constexpr libMcuLL::hwAddressType spiAddress{spiAddress_}; /**< peripheral address */
};
}  // namespace libMcuLL::sw::spi
#endif