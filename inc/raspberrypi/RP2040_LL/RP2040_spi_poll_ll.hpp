/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_spi_poll_ll.hpp
 * @brief Polled low level interface for the RP2040 SPI
 */
#ifndef RP2040_SPI_POLL_LL_HPP
#define RP2040_SPI_POLL_LL_HPP

namespace libmcull::spi {
namespace hardware = libmcuhw::spi;
/**
 * @brief Frame formats available
 */
enum class FrameFormats : std::uint32_t {
  kMotorola = hardware::SSPCR0::FRF_MOTOROLA, /*!< Motorola frame format */
  kTi = hardware::SSPCR0::FRF_TI,             /*!< Texas instruments frame format */
  kNational = hardware::SSPCR0::FRF_NATIONAL, /*!< National microwire frame format */
};
/**
 * @brief SPI hardware chip enables
 */
enum class ChipEnables : std::uint32_t {
  kNone = 0,         /*!< No chip select */
  kSsel = (1 << 16), /*!< Hardware chip enable */
};
/**
 * @brief possible SPI clocking/phasing/ordering
 */
enum class Waveforms : std::uint32_t {
  kCpha0Cpol0 = 0,                                             /*!< CPHA is 0, CPOL is 0, MSB first */
  kCpha1Cpol0 = hardware::SSPCR0::SPH,                         /*!< CPHA is 1, CPOL is 0, MSB first */
  kCpha0Cpol1 = hardware::SSPCR0::SPO,                         /*!< CPHA is 0, CPOL is 1, MSB first */
  kCpha1Cpol1 = hardware::SSPCR0::SPH | hardware::SSPCR0::SPO, /*!< CPHA is 1, CPOL is 1, MSB first */
};
/**
 * @brief
 * @tparam spi_address
 */
template <libmcu::SpiBaseAddress const& spi_address>
struct SpiPolled : libmcull::SyncSpiBase {
  /**
   * @brief Base initialization function
   */
  constexpr void Init() {}
  /**
   * @brief Setup SPI with motorola format
   * @param bitRate requested bit rate
   * @param waveform waveform to output, see sw::spi::waveforms
   * @return actual bit rate
   */
  constexpr std::uint32_t SetupMaster(std::uint32_t bitRate, Waveforms waveform) {
    std::uint32_t actualBitRate = SetBitRate(bitRate);
    std::uint32_t cr0setting = GetPeripheral()->SSPCR0 & ~hardware::SSPCR0::FORMAT_MASK;
    cr0setting |= static_cast<std::uint32_t>(waveform) | hardware::SSPCR0::FRF_MOTOROLA;
    GetPeripheral()->SSPCR0 = cr0setting;
    return actualBitRate;
  }
  //! @todo SPI master initialisation method with frame format selection
  //! @todo SPI slave initialisation method with standard waveform
  //! @todo SPI slave initialisation method with waveform selection
  constexpr void Transmit() {}
  constexpr void Receive() {}
  constexpr void Transceive(const std::span<std::uint16_t> transmitBuffer, std::span<std::uint16_t> receiveBuffer,
                            std::uint32_t bitcount) {
    size_t transmitIndex = 0u;
    size_t receiveIndex = 0u;
    GetPeripheral()->SSPCR0 = (GetPeripheral()->SSPCR0 & ~hardware::SSPCR0::DSS_MASK) | hardware::SSPCR0::DSS(bitcount);
    GetPeripheral()->SSPCR1 = hardware::SSPCR1::SSE;
    while (transmitIndex != transmitBuffer.size()) {
      // TX FIFO not full? Add one element, as we loop we will fill the TX buffer in short order
      if (GetPeripheral()->SSPSR & hardware::SSPSR::TNF_MASK) {
        GetPeripheral()->SSPDR = transmitBuffer[transmitIndex];
        transmitIndex++;
      }
      // if we get some data in the mean time, put it in the receive buffer
      if (GetPeripheral()->SSPSR & hardware::SSPSR::RNE_MASK) {
        receiveBuffer[receiveIndex] = GetPeripheral()->SSPDR;
        receiveIndex++;
      }
    }
    // receive remaining data
    while (transmitIndex > receiveIndex) {
      if (GetPeripheral()->SSPSR & hardware::SSPSR::RNE_MASK) {
        receiveBuffer[receiveIndex] = GetPeripheral()->SSPDR;
        receiveIndex++;
      }
    }
    GetPeripheralClear()->SSPCR1 = hardware::SSPCR1::SSE;
  }
  /**
   * @brief Set the SPI peripheral bit rate
   * Uses defined CLOCK_AHB to compute the actual bit rate
   * @param bitRate requested bit rate
   * @return actual bit rate
   */
  constexpr std::uint32_t SetBitRate(std::uint32_t bitRate) {
    // compute divider and truncate so we can observe a possible round off
    std::uint16_t divider = static_cast<std::uint16_t>(FREQ_PERI / 2 / bitRate);
    GetPeripheral()->SSPCPSR = 2; /* divide by two as a minimum */
    GetPeripheral()->SSPCR0 = (GetPeripheral()->SSPCR0 & ~hardware::SSPCR0::SCR_MASK) | hardware::SSPCR0::SCR(divider);
    return FREQ_PERI / 2 / divider;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to peripheral
   */
  static hardware::Spi* GetPeripheral() {
    return reinterpret_cast<hardware::Spi*>(spi_address_);
  }
  /**
   * @brief get registers from peripheral for atomic set access
   * @return return pointer to peripheral
   */
  static hardware::Spi* GetPeripheralSet() {
    return reinterpret_cast<hardware::Spi*>(spi_address_ + libmcuhw::kPeripheralOffsetSet);
  }
  /**
   * @brief get registers from peripheral for atomic Clear access
   * @return return pointer to peripheral
   */
  static hardware::Spi* GetPeripheralClear() {
    return reinterpret_cast<hardware::Spi*>(spi_address_ + libmcuhw::kPeripheralOffsetClear);
  }
  /**
   * @brief get registers from peripheral for atomic XOR access
   * @return return pointer to peripheral
   */
  static hardware::Spi* GetPeripheralXor() {
    return reinterpret_cast<hardware::Spi*>(spi_address_ + libmcuhw::kPeripheralOffsetXor);
  }

 private:
  static constexpr libmcu::HwAddressType spi_address_{spi_address}; /*!< peripheral address */
};
}  // namespace libmcull::spi
#endif