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
  kMove, /*!< move to overwrite bits */
  kNot,  /*!< invert bits */
  kAnd,  /*!< AND bits with source bits */
  kOr,   /*!< OR bits with source bits */
  kXor   /*!< XOR bits with source bits */
};
}  // namespace libmcu::bitmap

#endif