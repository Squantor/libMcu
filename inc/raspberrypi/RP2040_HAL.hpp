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

namespace libMcuLL {
using pinsHalType = libMcuHal::pins::pins<libMcuLL::hw::padsBank0Address, libMcuLL::hw::ioBank0Address>;
}

#endif
