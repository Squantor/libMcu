/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file nonblocking.hpp
 * @brief Contains definitions and types for defining non-blocking classes
 */
#ifndef NONBLOCKING_HPP
#define NONBLOCKING_HPP

namespace libmcu {

/** @brief CRTP base class for non-blocking classes
 * @tparam Derived class to be derived
 */
template <typename Derived>
struct NonBlockingBase {
  /**
   * @brief Progress whatever needs to be run
   */
  void Progress() noexcept {
    static_cast<Derived *>(this)->ProgressImpl();
  }

  /** @brief Callback when something has completed
   */
  void Callback(Results result) noexcept {
    static_cast<Derived *>(this)->CallbackImpl(result);
  }
};

/** @brief Type erasure for non-blocking callbacks
 * Helper class to do type erasure for non-blocking objects
 */
struct NonBlockingEntry {
  void *obj;
  void (*fn)(void *, Results result);
};

template <typename T>
concept HasNonBlockingInterface = requires(T t, Results s) {
  { t.ProgressImpl() } noexcept;
  { t.CallbackImpl(s) } noexcept;
};

}  // namespace libmcu
   // namespace libmcu

#endif