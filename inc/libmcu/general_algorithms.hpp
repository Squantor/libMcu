/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file general_algorithms.hpp
 * \brief algorithms used by libMcu
 */
#ifndef GENERAL_ALGORITHMS_HPP
#define GENERAL_ALGORITHMS_HPP

namespace libmcu {
/**
 * @brief Finds Least common multiple of two values ranged by a maximum
 * @param a first value
 * @param b second value
 * @param max maximum to search until
 * @return least common multiple, returns zero if no value found
 */
consteval std::uint32_t FindLcm(std::uint32_t a, std::uint32_t b, std::uint32_t max) {
  std::uint32_t sum_a = a;  // running maximum for parameter a
  std::uint32_t sum_b = b;  // running maximum for parameter b
  while (sum_a != sum_b) {
    if (sum_a < sum_b)
      sum_a = sum_a + a;
    else
      sum_b = sum_b + b;
    if (sum_a > max)
      return 0;
    if (sum_b > max)
      return 0;
  }
  return sum_a;
}
}  // namespace libmcu

#endif