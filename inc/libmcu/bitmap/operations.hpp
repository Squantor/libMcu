/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 *\file operations.hpp
 *
 * operations possible with various bit functions
 *
 */
#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

namespace util {
/**
 * @brief operations
 *
 */
enum class bitblitOperation { OP_MOV, OP_NOT, OP_AND, OP_OR, OP_XOR };
}  // namespace util

#endif