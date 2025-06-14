/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcu_concepts.hpp
 * @brief concepts used by libMcu in general
 */
#ifndef LIBMCU_CONCEPTS_HPP
#define LIBMCU_CONCEPTS_HPP

namespace libmcu {
/**
 * @brief Concept for types that inherit from libMcuLL::GpioBase
 * @tparam T
 */
template <typename T>
concept DerivedFromPin = std::is_base_of_v<libmcu::PinBase, T>;

}  // namespace libmcu

#endif