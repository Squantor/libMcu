/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcull_concepts.hpp
 * @brief concepts used by libMcuLL
 */
#ifndef LIBMCULL_CONCEPTS_HPP
#define LIBMCULL_CONCEPTS_HPP

namespace libmcull {

template <typename T>
concept DerivedFromLlUartSync = std::is_base_of_v<libmcull::LlSyncUartBase, T>;
}

#endif