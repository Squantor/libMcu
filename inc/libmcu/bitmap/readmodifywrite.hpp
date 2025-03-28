/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file readmodifywrite.hpp
 * @brief Read modify write routines
 */
#ifndef READMODIFYWRITE_HPP
#define READMODIFYWRITE_HPP

#include <limits>
#include <cstdint>
#include <libmcu/bitmap/operations.hpp>

namespace libmcu::bitmap {
/**
 * @brief Read, modifies and writes from source to destination with operation, the source is shifted and masked
 *
 * @tparam destType   destination element type
 * @tparam sourceType source element type
 * @param dest        pointer to destination
 * @param src         pointer to source
 * @param srcMask     mask to apply to source
 * @param srcShift    shift factor to apply to source
 * @param op          operation to perform
 */
template <typename destType, typename srcType>
void readModifyWrite(destType &__restrict__ dest, const srcType &__restrict__ src, destType srcMask, int srcShift,
                     bitblitOperation op) noexcept {
  static_assert(!std::numeric_limits<destType>::is_signed && !std::numeric_limits<srcType>::is_signed,
                "readModifyWrite only accepts unsigned types!");
  static_assert(std::numeric_limits<destType>::digits >= std::numeric_limits<srcType>::digits,
                "source should have equal or less bits then destination!");
  destType dataSrc;
  if (srcShift > 0)
    dataSrc = src << srcShift;
  else if (srcShift < 0)
    dataSrc = src >> -(srcShift);
  else
    dataSrc = src;
  switch (op) {
    case bitblitOperation::OP_AND:
      dest = dest & (dataSrc | ~srcMask);
      break;
    case bitblitOperation::OP_MOV:
      dest = (dest & ~srcMask) | (dataSrc & srcMask);
      break;
    case bitblitOperation::OP_NOT:
      dest = (dest & ~srcMask) | (~dataSrc & srcMask);
      break;
    case bitblitOperation::OP_OR:
      dest = dest | (dataSrc & srcMask);
      break;
    case bitblitOperation::OP_XOR:
      dest = dest ^ (dataSrc & srcMask);
      break;
  }
}
}  // namespace libmcu::bitmap

#endif
