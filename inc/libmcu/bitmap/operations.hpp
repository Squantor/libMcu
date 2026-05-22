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
 * @brief Blit operations
 */
enum class Blit_ops : std::uint8_t {
  COPY,   /*!< Copy */
  INVERT, /*!< Invert */
  AND,    /*!< AND */
  OR,     /*!< OR */
  XOR,    /*!< XOR */
};

/**
 * @brief Blit operation copy
 */
struct Blit_op_copy {
  /**
   * @brief Execute blit operation copy
   * @param dst Destination word
   * @param src Source word
   * @param mask Mask to use for operation, set bits indicates what will be applied
   */
  static void run(std::uint32_t &dst, std::uint32_t src, std::uint32_t mask) {
    dst = ((dst & ~mask) | ((src)&mask));
  }
};
/**
 * @brief Blit operation copy and invert
 */
struct Blit_op_invert {
  /**
   * @brief Execute blit operation copy and invert
   * @param dst Destination word
   * @param src Source word
   * @param mask Mask to use for operation, set bits indicates what will be applied
   */
  static void run(std::uint32_t &dst, std::uint32_t src, std::uint32_t mask) {
    dst = ((dst & ~mask) | ((~src) & mask));
  }
};
/**
 * @brief Blit operation and
 */
struct Blit_op_and {
  /**
   * @brief Execute blit operation and
   * @param dst Destination word
   * @param src Source word
   * @param mask Mask to use for operation, set bits indicates what will be applied
   */
  static void run(std::uint32_t &dst, std::uint32_t src, std::uint32_t mask) {
    dst = ((dst & ~mask) | ((src & dst) & mask));
  }
};
/**
 * @brief Blit operation or
 *
 */
struct Blit_op_or {
  /**
   * @brief Execute blit operation or
   * @param dst Destination word
   * @param src Source word
   * @param mask Mask to use for operation, set bits indicates what will be applied
   */
  static void run(std::uint32_t &dst, std::uint32_t src, std::uint32_t mask) {
    dst = ((dst & ~mask) | ((src | dst) & mask));
  }
};
/**
 * @brief Blit operation xor
 *
 */
struct Blit_op_xor {
  /**
   * @brief Execute blit operation xor
   * @param dst Destination word
   * @param src Source word
   * @param mask Mask to use for operation, set bits indicates what will be applied
   */
  static void run(std::uint32_t &dst, std::uint32_t src, std::uint32_t mask) {
    dst = ((dst & ~mask) | ((src ^ dst) & mask));
  }
};
}  // namespace libmcu::bitmap

#endif