/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file types used by libMcuHal
 */
#ifndef LIBMCUHAL_TYPES_HPP
#define LIBMCUHAL_TYPES_HPP

namespace libMcuHal {
/**
 * @brief Hal base class that all Hal classes should inherit from
 *
 * You will never copy/move a hal object, they are "eternal" with respect to program lifetime
 *
 */
struct halBase {
  halBase() = default;
  ~halBase() = default;
  halBase(const halBase&) = delete;
  halBase& operator=(const halBase&) = delete;
  halBase(halBase&&) = delete;
  halBase& operator=(halBase&&) = delete;
};
/* Hal base classes */
struct halGpioBase : halBase {};
}  // namespace libMcuHal

#endif