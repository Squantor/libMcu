/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_hal_spi_common.hpp
 * @brief LPC840 series common SPI definitions
 */
#ifndef LPC84X_HAL_SPI_COMMON_HPP
#define LPC84X_HAL_SPI_COMMON_HPP

namespace libMcuHal::spi {
namespace hardware = libMcuHw::spi;
/**
 * @brief allowed SPI chip selects
 * We use a bit mask pattern as that matches the SPI peripheral
 */
enum class spiSlaveSelects : uint32_t {
  None = 0,    /*!< No SPI slave select */
  Select0 = 1, /*!< SPI slave select 0 */
  Select1 = 2, /*!< SPI slave select 1 */
  Select2 = 4, /*!< SPI slave select 2 */
  Select3 = 8  /*!< SPI slave select 3 */
};
}  // namespace libMcuHal::spi
#endif