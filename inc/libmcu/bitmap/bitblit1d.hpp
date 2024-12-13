/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 *\file bitblit1d.hpp
 *
 * 1d bit transfer routine
 *
 */
#ifndef BITBLIT1D_HPP
#define BITBLIT1D_HPP

#include <limits>
#include <span>
#include <libmcu/bitmap/operations.hpp>
#include <libmcu/bitmap/readmodifywrite.hpp>

namespace libMcu::bitmap {
/**
 * @brief 1d bitblit operation
 * @todo More type flexibility, now more or less hardcoded to using uint8_t
 * @todo check if pointer arithmetic or index arithmetic is faster
 * @tparam destType Destination type
 * @tparam srcType Source type
 * @param destBuf Destination buffer
 * @param destBitWidth Destination width in bits
 * @param destBitPos Destination position offset in bits
 * @param srcBuf Source buffer
 * @param srcBitWidth source width in bits
 * @param op Boolean operation to perform
 */
template <typename destType, typename srcType>
void bitblit1d(std::span<destType> destBuf, std::size_t destBitWidth, std::size_t destBitPos, std::span<srcType> srcBuf,
               std::size_t srcBitWidth, bitblitOperation op) noexcept {
  // compute fixed constants
  constexpr std::size_t destBits = libMcu::bitsInType<destType>();
  constexpr std::size_t srcBits = libMcu::bitsInType<srcType>();
  // runtime code
  if (destBitPos >= destBitWidth)
    return;  // out of bounds, abort
  // compute count and clamp if needed
  const unsigned int elementBitCnt = std::numeric_limits<destType>::digits;
  unsigned int count;
  bool abortLastWrite;
  if ((srcBitWidth + destBitPos) >= destBitWidth) {
    // this double divide makes sure we have a correct count
    count = (destBitWidth / elementBitCnt) - (destBitPos / elementBitCnt);
    abortLastWrite = true;
  } else {
    count = srcBitWidth / elementBitCnt;
    abortLastWrite = false;
  }
  // extract special case for aligned writes and adjust counts
  // @todo: Hardcoded masking operations (7 etc), need to fix
  bool alignedWrites = (destBitPos & 7) == 0;
  if (count > 0 && !alignedWrites)
    count--;
  destType *destPtr = &destBuf[destBitPos / elementBitCnt];
  std::size_t srcIdx = 0;
  // compute masks and bit positions
  std::size_t destBit = destBitPos & 7;
  std::size_t endBit = destBit + srcBitWidth;
  std::size_t remainderBits = endBit & 7;
  destType mask = 0xFF << destBit;

  if (srcBitWidth < elementBitCnt && endBit < 9) {  // case for less then element bits write within a single element
    mask = mask & ~(0xFF << (destBit + srcBitWidth));
    readModifyWrite(*destPtr, srcBuf[srcIdx], mask, destBit, op);
    return;
  }

  if (alignedWrites) {  // case for aligned writes
    std::size_t i = count;
    while (i > 0) {
      readModifyWrite(*destPtr, srcBuf[srcIdx], mask, 0, op);
      destPtr++;
      srcIdx++;
      i--;
    }
    if (remainderBits && !abortLastWrite) {  // handle remainder of bits
      mask = 0xFF >> (remainderBits);
      readModifyWrite(*destPtr, srcBuf[srcIdx], mask, 0, op);
    }
  } else {  // case for unaligned writes single and multiple
    // first element start
    readModifyWrite(*destPtr, srcBuf[srcIdx], mask, destBit, op);
    destPtr++;
    while (count > 0) {  // do the rest
      readModifyWrite(*destPtr, srcBuf[srcIdx], static_cast<uint8_t>(~mask), -(elementBitCnt - destBit), op);
      srcIdx++;
      readModifyWrite(*destPtr, srcBuf[srcIdx], mask, destBit, op);
      destPtr++;
      count--;
    }
    if (!abortLastWrite && remainderBits) {  // handle last
      mask = 0xFF >> (remainderBits);
      readModifyWrite(*destPtr, srcBuf[srcIdx], mask, -(elementBitCnt - destBit), op);
    }
  }
}
}  // namespace libMcu::bitmap

#endif