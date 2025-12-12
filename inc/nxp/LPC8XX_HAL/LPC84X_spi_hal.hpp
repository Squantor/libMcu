/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_spi_hal.hpp
 * @brief LPC840 series nonblocking SPI HAL
 */
#ifndef LPC84X_SPI_HAL_HPP
#define LPC84X_SPI_HAL_HPP

namespace libmcuhal::spi {
namespace hardware = libmcuhw::spi;
namespace lowlevel = libmcull::spi;
namespace nvic = libmcuhw::nvic;

template <libmcull::DerivedFromAsyncSpi auto& ll_spi_async>
struct Spi : public libmcuhal::SpiBase {};
}  // namespace libmcuhal::spi

#endif