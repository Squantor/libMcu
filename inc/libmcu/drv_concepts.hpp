/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file drv_concepts.hpp
 * @brief Concepts used by libmcu drivers
 */
#ifndef DRV_CONCEPTS_HPP
#define DRV_CONCEPTS_HPP

#include <concepts>

namespace libmcudrv {
/**
 * @brief Concept for types that inherit from libmcudriver::DriverBase
 * @tparam T Type to check
 */
template <typename T>
concept Derived_from_driver = std::is_base_of_v<DriverBase, T>;
/**
 * @brief Concept for types that inherit from libmcu::Gfx_display_driver
 * @tparam T Type to check
 */
template <typename T>
concept Derived_from_gfx_display_driver = libmcu::Derived_from_template<T, Gfx_display_driver>::value;

}  // namespace libmcudrv

#endif