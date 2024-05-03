/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for RP2040 LL include
 */
#ifndef LIBMCURP2040LL_HPP
#define LIBMCURP2040LL_HPP

#include <cstdint>
#include <cstddef>
#include <array>
#include <span>
#include <type_traits>
#include <limits>
#include "libmcull/results.hpp"
#include "libmcull/types.hpp"

#if defined(MCU_RP2040)
#include "raspberrypi/RP2040_LL.hpp"
#else
#error "Unknown or unsupported microcontroller defined, use MCU_Microcontroller"
#endif

#endif
