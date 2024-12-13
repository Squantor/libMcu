/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcu_functions.hpp
 * @brief helper functions used by libMcu
 */
#ifndef LIBMCU_FUNCTIONS_HPP
#define LIBMCU_FUNCTIONS_HPP

#include <climits>

namespace libMcu {

template <typename T>
constexpr size_t bitsInType() {
  return sizeof(T) * CHAR_BIT;
}

}  // namespace libMcu

#endif