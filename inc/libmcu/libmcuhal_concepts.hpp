/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcuhal_concepts.hpp
 * @brief Concepts used by libMcuHal
 */
#ifndef LIBMCUHAL_CONCEPTS_HPP
#define LIBMCUHAL_CONCEPTS_HPP

namespace libmcuhal {
/**
 * @brief Concept for types that inherit from libMcuHal::HalUartBase
 * @tparam T
 */
template <typename T>
concept DerivedFromHalUart = std::is_base_of_v<libmcuhal::HalUartBase, T>;
/**
 * @brief Concept for types that inherit from libMcuHal::HalSpiBase
 * @tparam T
 */
template <typename T>
concept DerivedFromHalSpi = std::is_base_of_v<libmcuhal::HalSpiBase, T>;
/**
 * @brief Concept for types that inherit from libMcuHal::HalI2cBase
 * @tparam T
 */
template <typename T>
concept DerivedFromHalI2c = std::is_base_of_v<libmcuhal::HalI2cBase, T>;
/**
 * @brief Concept for checking types that inherit from libMcuHal::HalGpioBase
 * @tparam T
 */
template <typename T>
concept DerivedFromHalGpio = std::is_base_of_v<libmcuhal::HalGpioBase, T>;

}  // namespace libmcuhal

#endif