/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file hal_concepts.hpp
 * @brief Concepts used by libMcuHal
 */
#ifndef HAL_CONCEPTS_HPP
#define HAL_CONCEPTS_HPP

namespace libmcuhal {
/**
 * @brief Concept for types that inherit from libmcuhal::AsyncUartBase
 * @tparam T
 */
template <typename T>
concept DerivedFromAsyncUart = std::is_base_of_v<libmcuhal::AsyncUartBase, T>;
/**
 * @brief Concept for types that inherit from libmcuhal::AsyncSpiBase
 * @tparam T
 */
template <typename T>
concept DerivedFromAsyncSpi = std::is_base_of_v<libmcuhal::AsyncSpiBase, T>;
/**
 * @brief Concept for types that inherit from libmcuhal::AsyncI2cBase
 * @tparam T
 */
template <typename T>
concept DerivedFromAsyncI2c = std::is_base_of_v<libmcuhal::AsyncI2cBase, T>;
/**
 * @brief Concept for checking types that inherit from libmcuhal::GpioBase
 * @tparam T
 */
template <typename T>
concept DerivedFromGpio = std::is_base_of_v<libmcuhal::GpioBase, T>;

}  // namespace libmcuhal

#endif