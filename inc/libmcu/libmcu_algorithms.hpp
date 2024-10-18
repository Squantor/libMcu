/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file libmcu_algorithms.hpp
 * \brief algorithms used by libMcu
 */
#ifndef LIBMCU_ALGORITHMS_HPP
#define LIBMCU_ALGORITHMS_HPP

namespace libMcu {
/**
 * @brief Finds Least common multiple of two values ranged by a maximum
 * @param a first value
 * @param b second value
 * @param max maximum to search until
 * @return least common multiple, returns zero if no value found
 */
consteval std::uint32_t findLcm(std::uint32_t a, std::uint32_t b, std::uint32_t max) {
  std::uint32_t aSum = a;
  std::uint32_t bSum = b;
  while (aSum != bSum) {
    if (aSum < bSum)
      aSum = aSum + a;
    else
      bSum = bSum + b;
    if (aSum > (max - a))
      return 0;
    if (bSum > (max - b))
      return 0;
  }
  return aSum;
}
}  // namespace libMcu

#endif