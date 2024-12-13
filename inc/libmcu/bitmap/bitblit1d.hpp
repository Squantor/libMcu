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
 * Destination/sources are max 32 bit
 * @todo More type flexibility, now more or less hardcoded to using uint8_t
 * @todo remove special path for aligned writes, does only add much code but not so much speed
 * @tparam destType Destination type
 * @tparam srcType Source type
 * @param destBuf Destination buffer
 * @param destBitPos Destination position offset in bits
 * @param srcBuf Source buffer
 * @param srcBitWidth source width in bits
 * @param op Boolean operation to perform
 */
template <typename destType, typename srcType>
void bitblit1d(std::span<destType> destBuf, std::size_t destBitPos, std::span<const srcType> srcBuf, std::size_t srcBitWidth,
               bitblitOperation op) noexcept {
  // compute fixed constants
  constexpr std::size_t destBitCnt = libMcu::bitsInType<destType>();
  constexpr std::size_t srcBitCnt = libMcu::bitsInType<srcType>();
  // compute runtime constants
  destType mask;
  destType accumulator;
  // clamp amount of bits to write
  const std::size_t maxDestBits = destBuf.size() * destBitCnt - destBitPos;
  std::size_t bitCount = maxDestBits < srcBitWidth ? maxDestBits : srcBitWidth;
  // generate pointers
  destType *destPtr = &destBuf[destBitPos / destBitCnt];
  const srcType *srcPtr = srcBuf.data();

  // Pre step
  std::size_t srcBitOffset = destBitPos % destBitCnt;
  if (srcBitOffset != 0) {
    mask = static_cast<destType>(0xFFFFFFFF);  // we ignore 64 bit for now
    mask = mask << srcBitOffset;
    accumulator = *srcPtr & mask;
    srcPtr++;
    bitCount -= srcBitOffset;
  }
  // main loop
  mask = static_cast<destType>(0xFFFFFFFF);  // we ignore 64 bit for now
  while (bitCount >= destBitCnt) {
    // iterate over all elements
    readModifyWrite(*destPtr, *srcPtr, mask, 0, op);
    destPtr++;
    srcPtr++;
    bitCount -= destBitCnt;
  }
  // post step
  mask = static_cast<destType>(0xFFFFFFFF);  // we ignore 64 bit for now
  if (bitCount > 0) {
    mask = mask >> (destBitCnt - bitCount);
    readModifyWrite(*destPtr, *srcPtr, mask, 0, op);
  }
}

/**
 * @brief 1d bitblit operation
 * @todo More type flexibility, now more or less hardcoded to using uint8_t
 * @todo remove special path for aligned writes, does only add much code but not so much speed
 * @tparam destType Destination type
 * @tparam srcType Source type
 * @param destBuf Destination buffer
 * @param destBitWidth Destination width in bits
 * @param destBitPos Destination position offset in bits
 * @param srcBuf Source buffer
 * @param srcBitWidth source width in bits
 * @param op Boolean operation to perform
 */
/* commented out while developing new one
template <typename destType, typename srcType>
void bitblit1d(std::span<destType> destBuf, std::size_t destBitWidth, std::size_t destBitPos, std::span<srcType> srcBuf,
               std::size_t srcBitWidth, bitblitOperation op) noexcept {
  // compute fixed constants
  constexpr std::size_t destBitCnt = libMcu::bitsInType<destType>();
  constexpr std::size_t srcBitCnt = libMcu::bitsInType<srcType>();

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
  bool alignedWrites = ((destBitPos % destBitCnt) == 0);
  // if we do not have aligned writes, deduct one count due to partial write, fixed up in the end
  if (count > 0 && !alignedWrites)
    count--;
  // generate pointers
  destType *destPtr = &destBuf[destBitPos / elementBitCnt];
  srcType *srcPtr = srcBuf.data();
  // compute masks and bit positions
  std::size_t destBit = destBitPos & 7;
  std::size_t endBit = destBit + srcBitWidth;
  std::size_t remainderBits = endBit & 7;
  destType mask = 0xFF << destBit;

  if (srcBitWidth < elementBitCnt && endBit < 9) {  // case for less then element bits write within a single element
    mask = mask & ~(0xFF << (destBit + srcBitWidth));
    readModifyWrite(*destPtr, *srcPtr, mask, destBit, op);
    return;
  }

  if (alignedWrites) {  // case for aligned writes
    std::size_t i = count;
    while (i > 0) {
      if constexpr (destBitCnt == srcBitCnt) {
        readModifyWrite(*destPtr, *srcPtr, mask, 0, op);
        destPtr++;
        srcPtr++;
        i--;
      }
    }
    if (remainderBits && !abortLastWrite) {  // handle remainder of bits
      mask = 0xFF >> (remainderBits);
      readModifyWrite(*destPtr, *srcPtr, mask, 0, op);
    }
  } else {  // case for unaligned writes single and multiple
    // first element start
    readModifyWrite(*destPtr, *srcPtr, mask, destBit, op);
    destPtr++;
    while (count > 0) {  // do the rest
      readModifyWrite(*destPtr, *srcPtr, static_cast<uint8_t>(~mask), -(elementBitCnt - destBit), op);
      srcPtr++;
      readModifyWrite(*destPtr, *srcPtr, mask, destBit, op);
      destPtr++;
      count--;
    }
    if (!abortLastWrite && remainderBits) {  // handle last
      mask = 0xFF >> (remainderBits);
      readModifyWrite(*destPtr, *srcPtr, mask, -(elementBitCnt - destBit), op);
    }
  }
}
*/
}  // namespace libMcu::bitmap

#endif