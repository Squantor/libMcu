/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC81X series common SPI definitions
 */
#ifndef LPC81X_SPI_SW_COMMON_HPP
#define LPC81X_SPI_SW_COMMON_HPP

namespace libMcuLL {
namespace sw {
namespace spi {

using namespace hw::spi;

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
  CPHA0_CPOL0_MSB = 0,                                 /**< CPHA is 0, CPOL is 0, MSB first */
  CPHA1_CPOL0_MSB = CFG::CPHA,                         /**< CPHA is 1, CPOL is 0, MSB first */
  CPHA0_CPOL1_MSB = CFG::CPOL,                         /**< CPHA is 0, CPOL is 1, MSB first */
  CPHA1_CPOL1_MSB = CFG::CPHA | CFG::CPOL,             /**< CPHA is 1, CPOL is 1, MSB first */
  CPHA0_CPOL0_LSB = CFG::LSBF,                         /**< CPHA is 0, CPOL is 0, LSB first */
  CPHA1_CPOL0_LSB = CFG::CPHA | CFG::LSBF,             /**< CPHA is 1, CPOL is 0, LSB first */
  CPHA0_CPOL1_LSB = CFG::CPOL | CFG::LSBF,             /**< CPHA is 0, CPOL is 1, LSB first */
  CPHA1_CPOL1_LSB = CFG::CPHA | CFG::CPOL | CFG::LSBF, /**< CPHA is 1, CPOL is 1, LSB first */
};

/**
 * @brief Slave polarity selects
 *
 */
enum class slavePolaritySelects : std::uint32_t {
  SPOL_LOW = 0,          /**< Active low slave select */
  SPOL_HIGH = CFG::SPOL, /**< Active high slave select*/
};

}  // namespace spi
}  // namespace sw
}  // namespace libMcuLL

#endif