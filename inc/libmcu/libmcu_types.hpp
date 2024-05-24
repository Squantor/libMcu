/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file types used by libMcu
 */
#ifndef LIBMCU_TYPES_HPP
#define LIBMCU_TYPES_HPP

/**
 * @brief LibMcu wide used types
 *
 */
namespace libMcu {
/**
 * @brief defines a constant for typesafety
 *
 * @tparam C_ type of constant
 */
template <typename C_>
struct constant {
  using type = C_;

  constexpr operator C_() const {
    return value;
  }

  C_ value;
};

/**
 * @brief Base class where all pin traits are based of from
 * This baseclass is used as a base derivation for the pin traits. We can use the base to typecheck passing pins to various
 * drivers/functions
 *
 */
struct pinBase {};

using isrLambda = std::add_pointer<void()>::type; /**< Base type for an ISR lambda */

}  // namespace libMcu
#endif