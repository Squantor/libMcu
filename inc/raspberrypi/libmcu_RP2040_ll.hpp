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
#include "../libmcu/libmcu_results.hpp"
#include "../libmcu/libmcu_types.hpp"
#include "../libmcu/libmcu_functions.hpp"
#include "../libmcu/libmcull_types.hpp"

#if defined(MCU_RP2040)
#include "RP2040_LL.hpp"
#else
#error "Unknown or unsupported microcontroller defined, use MCU_Microcontroller"
#endif

#endif
