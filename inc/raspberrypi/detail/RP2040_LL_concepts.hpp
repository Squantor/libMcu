/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_LL_concepts.hpp
 * @brief concepts used for the low level RP2040 code
 */
#ifndef RP2040_LL_CONCEPTS_HPP
#define RP2040_LL_CONCEPTS_HPP

namespace libmcull {
/**
 * @brief Concept for types that inherit from libmcull::SyncUartBase
 * @tparam T
 */
template <typename T>
concept DerivedFromPads = std::is_base_of_v<libmcull::PadsBase, T>;
}  // namespace libmcull

#endif