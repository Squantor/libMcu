/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file bitblit2dsmall.hpp
 * @brief 2d bitblit operations, small version
 */
#ifndef BITBLIT2DSMALL_HPP
#define BITBLIT2DSMALL_HPP

#include <limits>
#include <libmcu/bitmap/operations.hpp>
#include <libmcu/bitmap/readmodifywrite.hpp>

namespace libmcu::bitmap {

/**
 * @brief
 *
 * @tparam destType
 * @tparam srcType
 * @param dest
 * @param destWidth
 * @param destHeight
 * @param destX
 * @param destY
 * @param src
 * @param srcWidth
 * @param srcHeight
 * @param op
 */
template <typename destType, typename srcType>
void bitblit2dsmall(destType *__restrict__ dest, unsigned int destWidth, unsigned int destHeight, unsigned int destX,
                    unsigned int destY, const srcType *__restrict__ src, unsigned int srcWidth, unsigned int srcHeight,
                    bitblitOperation op) noexcept {
  constexpr int destDigits = std::numeric_limits<destType>::digits;
  constexpr int srcDigits = std::numeric_limits<srcType>::digits;
  if (destX > destWidth)
    return;
  if (destY > destHeight)
    return;
  // compute iteration limits for width and height
  unsigned int widthCount;
  if ((destX + srcWidth) >= destWidth)
    widthCount = destWidth - destX;
  else
    widthCount = srcWidth;
  unsigned int heightCount;
  if ((destY + srcHeight) >= destHeight)
    heightCount = destHeight - destY;
  else
    heightCount = srcHeight;

  // add height offset to destination
  dest = dest + (destY * (destWidth / destDigits));

  destType destMask;
  srcType srcMask;
  destType *currDestLine;
  const srcType *currSrcLine;

  unsigned int widthCounter, heightCounter;
  heightCounter = heightCount;
  while (heightCounter > 0) {
    // TODO, we have two types of source bitmaps, one where a new line does not use the remaining bits
    // and a bitmap where we use ALL the bits on the end of the line, this is more compact for fonts and such
    widthCounter = widthCount;
    // do X iteration
    destMask = 1 << (destX & (destDigits - 1));
    srcMask = 1;
    currDestLine = dest + (destX / destDigits);
    currSrcLine = src;
    while (widthCounter > 0) {
      bool srcPixel = (*currSrcLine & srcMask) ? true : false;
      bool destPixel = (*currDestLine & destMask) ? true : false;
      // transfer a bit according to operation
      switch (op) {
        case bitblitOperation::OP_AND:
          destPixel = destPixel && srcPixel;
          break;
        case bitblitOperation::OP_MOV:
          destPixel = srcPixel;
          break;
        case bitblitOperation::OP_NOT:
          destPixel = !srcPixel;
          break;
        case bitblitOperation::OP_OR:
          destPixel = destPixel || srcPixel;
          break;
        case bitblitOperation::OP_XOR:
          destPixel = destPixel != srcPixel;
          break;
        default:
          break;
      }
      if (destPixel)
        *currDestLine = *currDestLine | destMask;
      else
        *currDestLine = *currDestLine & ~destMask;
      // compute all indices
      widthCounter--;
      srcMask = srcMask << 1;
      if (srcMask == 0) {
        srcMask = 1;
        currSrcLine++;
      }
      destMask = destMask << 1;
      if (destMask == 0) {
        destMask = 1;
        currDestLine++;
      }
    }
    heightCounter--;
    dest = dest + (destWidth / destDigits);
    src = src + (srcWidth / srcDigits);
  }
}

};  // namespace libmcu::bitmap

#endif