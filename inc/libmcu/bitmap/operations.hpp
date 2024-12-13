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

namespace libMcu::bitmap {
/**
 * @brief operations possible when bits are involved
 */
enum class bitblitOperation {
  OP_MOV, /*!< move to overwrite bits */
  OP_NOT, /*!< invert bits */
  OP_AND, /*!< AND bits with source bits */
  OP_OR,  /*!< OR bits with source bits */
  OP_XOR  /*!< XOR bits with source bits */
};
}  // namespace libMcu::bitmap

#endif