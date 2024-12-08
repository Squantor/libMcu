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
#include <libmcu/bitmap/operations.hpp>
#include <libmcu/bitmap/readmodifywrite.hpp>

namespace util {
template <typename destType, typename srcType>
void bitblit1d(destType *__restrict__ dest, unsigned int destWidth, unsigned int destX, const srcType *__restrict__ src,
               unsigned int srcWidth, bitblitOperation op) noexcept {
  if (destX >= destWidth)
    return;  // out of bounds, abort
  // compute count and clamp if needed
  const unsigned int elementBitCnt = std::numeric_limits<destType>::digits;
  unsigned int count;
  bool abortLastWrite;
  if ((srcWidth + destX) >= destWidth) {
    // this double divide makes sure we have a correct count
    count = (destWidth / elementBitCnt) - (destX / elementBitCnt);
    abortLastWrite = true;
  } else {
    count = srcWidth / elementBitCnt;
    abortLastWrite = false;
  }
  // extract special case for aligned writes and adjust counts
  bool alignedWrites = (destX & 7) == 0;
  if (count > 0 && !alignedWrites)
    count--;
  dest = dest + destX / elementBitCnt;
  // compute masks and bit positions
  int destBit = destX & 7;
  unsigned int endBit = destBit + srcWidth;
  unsigned int remainderBits = endBit & 7;
  destType mask = 0xFF << destBit;

  if (srcWidth < elementBitCnt && endBit < 9) {  // case for less then element bits write within a single element
    mask = mask & ~(0xFF << (destBit + srcWidth));
    readModifyWrite(*dest, *src, mask, destBit, op);
    return;
  }

  if (alignedWrites) {  // case for aligned writes
    unsigned int i = count;
    while (i > 0) {
      readModifyWrite(*dest, *src, mask, 0, op);
      dest++;
      src++;
      i--;
    }
    if (remainderBits && !abortLastWrite) {  // handle remainder of bits
      mask = 0xFF >> (remainderBits);
      readModifyWrite(*dest, *src, mask, 0, op);
    }

  } else {  // case for unaligned writes single and multiple
    // first element start
    readModifyWrite(*dest, *src, mask, destBit, op);
    dest++;
    while (count > 0) {  // do the rest
      readModifyWrite(*dest, *src, static_cast<uint8_t>(~mask), -(elementBitCnt - destBit), op);
      src++;
      readModifyWrite(*dest, *src, mask, destBit, op);
      dest++;
      count--;
    }
    if (!abortLastWrite && remainderBits) {  // handle last
      mask = 0xFF >> (remainderBits);
      readModifyWrite(*dest, *src, mask, -(elementBitCnt - destBit), op);
    }
  }
}
}  // namespace util

#endif