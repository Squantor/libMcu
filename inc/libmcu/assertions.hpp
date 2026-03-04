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
/**
 * @brief Default assertion class that does not catch assertions
 */
struct Assert_default {
  static constexpr bool enabled = false;
  static void fail(const char*) noexcept {}
};
/**
 * @brief Assertion class that loops forever
 */
struct Assert_trap {
  static constexpr bool enabled = true;
  static void fail(const char*) noexcept {
    while (true)
      ;
  }
};
/**
 * @brief Concept for checking template assertion classes
 * @tparam T
 */
template <typename T>
concept Assert_concept = requires(const char* message) {
  { T::enabled } -> std::convertible_to<bool>;
  { T::fail(message) } -> std::same_as<void>;
};
}  // namespace libmcu

#endif