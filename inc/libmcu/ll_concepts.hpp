/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file ll_concepts.hpp
 * @brief concepts used by libMcuLL
 */
#ifndef LL_CONCEPTS_HPP
#define LL_CONCEPTS_HPP

namespace libmcull {
/**
 * @brief Concept for types that inherit from libmcull::SyncUartBase
 * @tparam T
 */
template <typename T>
concept DerivedFromSyncUart = std::is_base_of_v<libmcull::SyncUartBase, T>;
/**
 * @brief Concept for types that inherit from libmcull::AsyncUartBase
 * @tparam T
 */
template <typename T>
concept DerivedFromAsyncUart = std::is_base_of_v<libmcull::AsyncUartBase, T>;
/**
 * @brief Concept for types that inherit from libmcull::SyncSpiBase
 * @tparam T
 */
template <typename T>
concept DerivedFromSyncSpi = std::is_base_of_v<libmcull::SyncSpiBase, T>;
/**
 * @brief Concept for types that inherit from libmcull::AsyncSpiBase
 * @tparam T
 */
template <typename T>
concept DerivedFromAsyncSpi = std::is_base_of_v<libmcull::AsyncSpiBase, T>;
/**
 * @brief Concept for types that inherit from libmcull::SyncI2cBase
 * @tparam T
 */
template <typename T>
concept DerivedFromSyncI2c = std::is_base_of_v<libmcull::SyncI2cBase, T>;
/**
 * @brief Concept for types that inherit from libmcull::AsyncI2cBase
 * @tparam T
 */
template <typename T>
concept DerivedFromAsyncI2c = std::is_base_of_v<libmcull::AsyncI2cBase, T>;
/**
 * @brief Concept for types that inherit from libmcull::GpioBase
 * @tparam T
 */
template <typename T>
concept DerivedFromGpio = std::is_base_of_v<libmcull::GpioBase, T>;

}  // namespace libmcull

#endif