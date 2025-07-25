/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file operations.hpp
 * @brief Definitions for operations possible with various bit functions
 */
#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

namespace libmcu::bitmap {
/**
 * @brief operations possible when bits are involved
 */
enum class BitblitOperations {
  Move, /*!< move to overwrite bits */
  Not,  /*!< invert bits */
  And,  /*!< AND bits with source bits */
  Or,   /*!< OR bits with source bits */
  Xor   /*!< XOR bits with source bits */
};
}  // namespace libmcu::bitmap

#endif