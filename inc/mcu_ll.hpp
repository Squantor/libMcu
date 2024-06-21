/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point
 * Main entry point, one giant list of microcontroller targets that are supported.
 * Keep this header as small as possible, warnings definitions keep them in the
 * MCU specific headers.
 *
 * TODO: depricate this file
 *
 */
#ifndef MCU_LL_HPP
#define MCU_LL_HPP

#include <cstdint>
#include <cstddef>
#include <array>
#include <span>
#include <type_traits>
#include <limits>
#include "libmcu/libmcu_results.hpp"
#include "libmcu/libmcu_types.hpp"
#include "libmcu/libmcu_functions.hpp"
#include "libmcu/libmcull_types.hpp"

#if defined(MCU_LPC812M101DH20)
#include "nxp/LPC812M101DH20.hpp"
#elif defined(MCU_LPC844M201BD64)
#include "nxp/LPC844M201BD64.hpp"
#elif defined(MCU_CortexM0)
#include "generic/CortexM0.hpp"
#elif defined(MCU_CortexM0plus)
#include "generic/CortexM0plus.hpp"
#elif defined(MCU_CortexM3)
#include "generic/CortexM3.hpp"
#elif defined(MCU_CortexM4)
#include "generic/CortexM4.hpp"
#elif defined(MCU_CortexM7)
#include "generic/CortexM7.hpp"
#else
#error "Unknown or unsupported microcontroller defined, use MCU_Microcontroller"
#endif

#endif
