/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for the raspberry RP2040 HAL
 */
#ifndef RP2040_HAL_HPP
#define RP2040_HAL_HPP

#include "RP2040_HAL/RP2040_hal_pins.hpp"
#include "RP2040_HAL/RP2040_hal_gpio.hpp"
#include "RP2040_HAL/RP2040_hal_spi_sync.hpp"

namespace libMcuHal {
using pinsHalType = pins::pins<libMcuHw::padsBank0Address, libMcuHw::ioBank0Address>;
using gpioHalType = gpio::gpio<libMcuHw::padsBank0Address, libMcuHw::ioBank0Address, libMcuHw::sioAddress>;
using spi0SyncHalType = spi::spi<libMcuHw::spi0Address>;
using spi1SyncHalType = spi::spi<libMcuHw::spi1Address>;
}  // namespace libMcuHal

#endif
