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
  CPHA0_CPOL0 = 0,                                           /**< CPHA is 0, CPOL is 0, MSB first */
  CPHA1_CPOL0 = hw::spi::SSPCR0::SPH,                        /**< CPHA is 1, CPOL is 0, MSB first */
  CPHA0_CPOL1 = hw::spi::SSPCR0::SPO,                        /**< CPHA is 0, CPOL is 1, MSB first */
  CPHA1_CPOL1 = hw::spi::SSPCR0::SPH | hw::spi::SSPCR0::SPO, /**< CPHA is 1, CPOL is 1, MSB first */
};

template <libMcuLL::spiBaseAddress const& spiAddress_>
struct spi : libMcuLL::peripheralBase {
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
    std::uint32_t cr0setting = spiPeripheral()->SSPCR0 & ~hw::spi::SSPCR0::FORMAT_MASK;
    cr0setting |= static_cast<std::uint32_t>(waveform) | hw::spi::SSPCR0::FRF_MOTOROLA;
    spiPeripheral()->SSPCR0 = cr0setting;
    return actualBitRate;
  }
  // TODO: SPI master initialisation method with frame format selection
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
    spiPeripheral()->SSPCR0 = (spiPeripheral()->SSPCR0 & ~hw::spi::SSPCR0::SCR_MASK) | hw::spi::SSPCR0::SCR(divider);
    return FREQ_PERI / divider;
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