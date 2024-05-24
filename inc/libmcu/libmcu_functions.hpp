/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file helper functions used by libMcu
 */
#ifndef LIBMCU_FUNCTIONS_HPP
#define LIBMCU_FUNCTIONS_HPP

namespace libMcu::sw {
inline void delay(std::uint32_t cycles) {
  asm volatile(
    ".syntax unified \n\t"
    "1: \n\t"
    "subs %0, #1 \n\t"
    "bne 1b"
    : "+r"(cycles));
}
}  // namespace libMcu::sw

#endif