/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file libmcu_algorithms.hpp
 * \brief algorithms used by libMcu
 */
#ifndef LIBMCU_ALGORITHMS_HPP
#define LIBMCU_ALGORITHMS_HPP

namespace libmcu {
/**
 * @brief Finds Least common multiple of two values ranged by a maximum
 * @param a first value
 * @param b second value
 * @param max maximum to search until
 * @return least common multiple, returns zero if no value found
 */
consteval std::uint32_t FindLcm(std::uint32_t a, std::uint32_t b, std::uint32_t max) {
  std::uint32_t aSum = a;  // running maximum for parameter a
  std::uint32_t bSum = b;  // running maximum for parameter b
  while (aSum != bSum) {
    if (aSum < bSum)
      aSum = aSum + a;
    else
      bSum = bSum + b;
    if (aSum > max)
      return 0;
    if (bSum > max)
      return 0;
  }
  return aSum;
}
}  // namespace libmcu

#endif