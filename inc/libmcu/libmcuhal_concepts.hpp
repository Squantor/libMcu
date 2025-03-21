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
template <typename T>
concept DerivedFromHalUartSync = std::is_base_of_v<libmcuhal::HalUartSync, T>;
}

#endif