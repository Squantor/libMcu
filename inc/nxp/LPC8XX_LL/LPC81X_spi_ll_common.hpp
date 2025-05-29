/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC81X series common SPI definitions
 */
/**
 * @file LPC81X_spi_ll_common.hpp
 * @brief LPC810 series common SPI interface class and definitions
 */
#ifndef LPC81X_SPI_SW_COMMON_HPP
#define LPC81X_SPI_SW_COMMON_HPP

namespace libmcull::spi {
namespace hardware = libmcuhw::spi;
/**
 * @brief SPI hardware chip enables
 */
enum class ChipEnables : std::uint32_t {
  kNone = 0,           /*!< No chip select */
  kSsel0 = (1u << 16), /*!< Hardware chip enable */
};
/**
 * @brief possible SPI clocking/phasing/ordering
 */
enum class Waveforms : std::uint32_t {
  kCpha0Cpol0Msb = 0,                                                                  /*!< CPHA is 0, CPOL is 0, MSB first */
  kCpha1Cpol0Msb = hardware::CFG::kCPHA,                                               /*!< CPHA is 1, CPOL is 0, MSB first */
  kCpha0Cpol1Msb = hardware::CFG::kCPOL,                                               /*!< CPHA is 0, CPOL is 1, MSB first */
  kCpha1Cpol1Msb = hardware::CFG::kCPHA | hardware::CFG::kCPOL,                        /*!< CPHA is 1, CPOL is 1, MSB first */
  kCpha0Cpol0Lsb = hardware::CFG::kLSBF,                                               /*!< CPHA is 0, CPOL is 0, LSB first */
  kCpha1Cpol0Lsb = hardware::CFG::kCPHA | hardware::CFG::kLSBF,                        /*!< CPHA is 1, CPOL is 0, LSB first */
  kCpha0Cpol1Lsb = hardware::CFG::kCPOL | hardware::CFG::kLSBF,                        /*!< CPHA is 0, CPOL is 1, LSB first */
  kCpha1Cpol1Lsb = hardware::CFG::kCPHA | hardware::CFG::kCPOL | hardware::CFG::kLSBF, /*!< CPHA is 1, CPOL is 1, LSB first */
};
/**
 * @brief Slave polarity selects
 *
 */
enum class SlavePolaritySelects : std::uint32_t {
  kLow = 0,                     /*!< Active low slave select */
  kHigh = hardware::CFG::kSPOL, /*!< Active high slave select*/
};
}  // namespace libmcull::spi
#endif