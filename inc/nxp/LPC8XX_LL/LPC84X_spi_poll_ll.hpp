/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_spi_poll_ll.hpp
 * @brief LPC84X series polling SPI low level interface class and definitions
 */
#ifndef LPC84X_SPI_POLL_LL_HPP
#define LPC84X_SPI_POLL_LL_HPP

namespace libmcull::spi {
namespace hardware = libmcuhw::spi;

/**
 * @brief SPI hardware chip enables
 */
enum class SpiChipEnables : std::uint32_t {
  kDevice0 = hardware::TXCTL::kTXSSEL0_N, /*!< Hardware chip enable 0 */
  kDevice1 = hardware::TXCTL::kTXSSEL1_N, /*!< Hardware chip enable 1 */
  kDevice2 = hardware::TXCTL::kTXSSEL2_N, /*!< Hardware chip enable 2 */
  kDevice3 = hardware::TXCTL::kTXSSEL3_N, /*!< Hardware chip enable 3 */
};
/**
 * @brief synchronous SPI peripheral instance
 * @tparam spi_address Peripheral base spi_address_
 * @tparam chipEnables enum of available chip enables
 * @tparam transferType datatype to use for data transfers
 * @todo Slave initializations
 */
template <libmcu::SpiBaseAddress spi_address, typename ChipEnable, typename TransferType>
struct SpiPolled : libmcull::SyncSpiBase {
  /**
   * @brief Initialise SPI peripheral as master device, LSB first mode, CPHA is 0, CPOL is 0,
   * @tparam &clock_config clock configuration to use
   * @param bit_rate requested bit rate
   * @return actual bit rate
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t InitMaster(std::uint32_t bit_rate) {
    std::uint32_t actual_bitrate = SetBitRate<clock_config>(bit_rate);
    GetPeripheral()->CFG = hardware::CFG::kENABLE | hardware::CFG::kMASTER;
    return actual_bitrate;
  }
  /**
   * @brief Set the SPI peripheral bit rate
   * @tparam &clock_config clock configuration to use
   * @param bit_rate requested bit rate
   * @return actual bit rate
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t SetBitRate(std::uint32_t bit_rate) {
    // compute divider and truncate so we can observe a possible round off
    std::uint32_t frequency = GetInputClockFreq<clock_config>();
    std::uint16_t divider = static_cast<std::uint16_t>(frequency / bit_rate);
    GetPeripheral()->DIV = hardware::DIV::DIVVAL(divider);
    return frequency / divider;
  }
  /**
   * @brief get the input clock of this UART peripheral
   * @tparam &clock_config clock configuration to use
   * @tparam config clock configuration
   * @return current input clock frequency
   */
  template <const libmcuhw::clock::PeriClockConfig &clock_config>
  constexpr std::uint32_t GetInputClockFreq() {
    // constexpr check if we configure the right peripheral
    if constexpr ((spi_address_ == libmcuhw::kSpi0Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::SPI0))
      return clock_config.GetFrequency();
    else if constexpr ((spi_address_ == libmcuhw::kSpi1Address) && (clock_config.peripheral_ == libmcuhw::clock::PeriSelect::SPI1))
      return clock_config.GetFrequency();
    else
      static_assert(false, "Clock config and peripherals unknown or not matching!");
    return 0;
  }
  /**
   * @brief get registers from peripheral
   * @return return pointer to spi registers
   */
  constexpr hardware::Spi *GetPeripheral() {
    return reinterpret_cast<hardware::Spi *>(spi_address_);
  }

 private:
  static constexpr libmcu::HwAddressType spi_address_ = spi_address; /*!< peripheral spi_address_ */
};
}  // namespace libmcull::spi
#endif