/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file  RP2040_spi_poll_hal.hpp
 * @brief RP2040 polling SPI hal class
 */
#ifndef RP2040_SPI_POLL_HAL_HPP
#define RP2040_SPI_POLL_HAL_HPP

namespace libmcuhal::spi {
namespace lowlevel = libmcull::spi;

/**
 * @brief
 * @tparam spi_poll_lowlevel
 */
template <const auto& spi_poll_lowlevel>
struct spi {
  /**
   * @brief
   */
  void Init() {}

 private:
};
}  // namespace libmcuhal::spi

#endif