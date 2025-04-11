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

namespace libmcull::sw::spi {
using namespace libmcuhw::spi;
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
  kCpha0Cpol0Msb = 0,                                    /*!< CPHA is 0, CPOL is 0, MSB first */
  kCpha1Cpol0Msb = CFG::kCPHA,                           /*!< CPHA is 1, CPOL is 0, MSB first */
  kCpha0Cpol1Msb = CFG::kCPOL,                           /*!< CPHA is 0, CPOL is 1, MSB first */
  kCpha1Cpol1Msb = CFG::kCPHA | CFG::kCPOL,              /*!< CPHA is 1, CPOL is 1, MSB first */
  kCpha0Cpol0Lsb = CFG::kLSBF,                           /*!< CPHA is 0, CPOL is 0, LSB first */
  kCpha1Cpol0Lsb = CFG::kCPHA | CFG::kLSBF,              /*!< CPHA is 1, CPOL is 0, LSB first */
  kCpha0Cpol1Lsb = CFG::kCPOL | CFG::kLSBF,              /*!< CPHA is 0, CPOL is 1, LSB first */
  kCpha1Cpol1Lsb = CFG::kCPHA | CFG::kCPOL | CFG::kLSBF, /*!< CPHA is 1, CPOL is 1, LSB first */
};
/**
 * @brief Slave polarity selects
 *
 */
enum class SlavePolaritySelects : std::uint32_t {
  kLow = 0,           /*!< Active low slave select */
  kHigh = CFG::kSPOL, /*!< Active high slave select*/
};
}  // namespace libmcull::sw::spi
#endif