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
  None = 0,           /*!< No chip select */
  Ssel0 = (1u << 16), /*!< Hardware chip enable */
};
/**
 * @brief possible SPI clocking/phasing/ordering
 */
enum class Waveforms : std::uint32_t {
  Cpha0Cpol0Msb = 0,                                                               /*!< CPHA is 0, CPOL is 0, MSB first */
  Cpha1Cpol0Msb = hardware::CFG::CPHA,                                             /*!< CPHA is 1, CPOL is 0, MSB first */
  Cpha0Cpol1Msb = hardware::CFG::CPOL,                                             /*!< CPHA is 0, CPOL is 1, MSB first */
  Cpha1Cpol1Msb = hardware::CFG::CPHA | hardware::CFG::CPOL,                       /*!< CPHA is 1, CPOL is 1, MSB first */
  Cpha0Cpol0Lsb = hardware::CFG::LSBF,                                             /*!< CPHA is 0, CPOL is 0, LSB first */
  Cpha1Cpol0Lsb = hardware::CFG::CPHA | hardware::CFG::LSBF,                       /*!< CPHA is 1, CPOL is 0, LSB first */
  Cpha0Cpol1Lsb = hardware::CFG::CPOL | hardware::CFG::LSBF,                       /*!< CPHA is 0, CPOL is 1, LSB first */
  Cpha1Cpol1Lsb = hardware::CFG::CPHA | hardware::CFG::CPOL | hardware::CFG::LSBF, /*!< CPHA is 1, CPOL is 1, LSB first */
};
/**
 * @brief Slave polarity selects
 *
 */
enum class SlavePolaritySelects : std::uint32_t {
  Low = 0,                    /*!< Active low slave select */
  High = hardware::CFG::SPOL, /*!< Active high slave select*/
};
}  // namespace libmcull::spi
#endif