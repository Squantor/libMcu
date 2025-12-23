/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file assertions.hpp
 * \brief Assertion types and concepts used by libmcu
 */
#ifndef ASSERTIONS_HPP
#define ASSERTIONS_HPP

namespace libmcu {
/** @brief Default assertion function that does nothing
 * Used as default when no assertion function is provided
 */
struct NoAssert {
  /**
   * @brief Assertion function that does nothing
   */
  constexpr void operator()(const char*) const noexcept {}
};

/** @brief Assertion function that loops forever
 */
struct TrapAssert {
  /**
   * @brief Assertion function that loops forever
   * @param message Cause of the assertion
   */
  [[noreturn]] constexpr void operator()(const char* message) const noexcept {
    (void)message;
    while (true)
      ;
  }
};

/**
 * @brief Concept for checking template assertion class inputs
 * @tparam A assertion class to check
 */
template <typename A>
concept AssertCallable = requires(A a, const char* message) {
  { a(message) } noexcept -> std::same_as<void>;
};
}  // namespace libmcu

#endif