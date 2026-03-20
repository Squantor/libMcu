/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file cm_assert.hpp
 * \brief Assertion policies used for CortexM microcontrollers
 */
#ifndef CM_ASSERT_HPP
#define CM_ASSERT_HPP

namespace libmcull {
/**
 * @brief Assertion policy class that executes BKPT instruction in a forever loop
 */
struct Assert_bkpt {
  static constexpr bool enabled = true;
  static void fail(const char* message) noexcept {
    (void)message;
    while (true)
      LIBMCULL_BKPT(0x42);
  }
};
}  // namespace libmcull
#endif