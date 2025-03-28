/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file libmcu_functions_CM0.hpp
 * \brief helper functions used by libMcu used by CortexM0 processors
 */
#ifndef LIBMCU_FUNCTIONS_CM0_HPP
#define LIBMCU_FUNCTIONS_CM0_HPP

#include <climits>

namespace libmcu {

/**
 * @brief Simple delay function
 * @param cycles amount of cycles to delay
 */
inline void Delay(std::uint32_t cycles) {
  asm volatile(
    ".syntax unified \n\t"
    "1: \n\t"
    "subs %0, #1 \n\t"
    "bne 1b"
    : "+r"(cycles));
}

}  // namespace libmcu

#endif