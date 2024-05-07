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

#include "raspberrypi/HAL/RP2040_pins.hpp"
#include "raspberrypi/HAL/RP2040_gpio.hpp"
#include "raspberrypi/HAL/RP2040_spi_sync.hpp"

namespace libMcuHal {
using namespace libMcuLL::hw;
using pinsHalType = pins::pins<padsBank0Address, ioBank0Address>;
using gpioHalType = gpio::gpio<padsBank0Address, ioBank0Address, sioAddress>;
using spi0SyncHalType = libMcuHal::spi::spi<libMcuLL::hw::spi0Address>;
using spi1SyncHalType = libMcuHal::spi::spi<libMcuLL::hw::spi1Address>;
}  // namespace libMcuHal

#endif
