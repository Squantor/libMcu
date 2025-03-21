/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcu_LPC1114BD48_301_ll.hpp
 * @brief include for the LPC1114BD48/301 libmcu low level library
 */
#ifndef LIBMCU_LPC1114BD48_301_LL_HPP
#define LIBMCU_LPC1114BD48_301_LL_HPP

#include "../libmcu/libmcu.hpp"
#include "../libmcu/libmcuhw.hpp"
#include "../libmcu/libmcull.hpp"
#include "../libmcu/libmcu_functions_CM0.hpp"

namespace libMcuHw {
// microcontroller core configuration options
}

#include <CortexM/cortex_m0.hpp>

namespace libMcuHw {
// Microcontroller memory addresses
// base memories
// peripherals bus1
// peripherals bus2 etc
}  // namespace libMcuHw

// includes that define the registers namespace go here.

// device peripheral specific headers go here
// these need to go after registers namespace definitions as they are used here

// includes that use the registers namespace go here, typically low level classes
// need to go after registers namespaces and device specific headers

#endif