/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file cm_assert.hpp
 * \brief Assertion type used for CortexM microcontrollers
 */
#ifndef CM_ASSERT_HPP
#define CM_ASSERT_HPP

namespace libmcull {
/** @brief Assertion class used for CortexM microcontrollers that uses BKPT instruction
 * Useful when debugging on CortexM microcontrollers
 */
struct AssertBkpt {
  /**
   * @brief Assertion function that executes BKPT instruction in a forever loop
   */
  [[noreturn]] constexpr void operator()(const char* message) const noexcept {
    (void)message;
    while (true)
      LIBMCULL_BKPT(0x42);
  }
};
}  // namespace libmcull
#endif