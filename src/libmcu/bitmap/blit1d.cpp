/**
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file blit_1d.hpp
 * @brief 1D blit functions
 * @version 20260403
 *
 */
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <span>
#include <utility>
#include "libmcu/bitmap/blits.hpp"

namespace libmcu::bitmap {
namespace detail {
/**
 * @brief shift bits either positive or negative
 * @param bits bits to shift
 * @param shift shift amount/count
 * @return shifted bits
 */
std::uint32_t shift_bits(std::uint32_t bits, std::int32_t shift) {
  if (shift > 32 || shift < -32) {
    return 0;
  }
  if (shift > 0) {
    return bits << shift;
  } else if (shift < 0) {
    return bits >> -shift;
  }
  return bits;
}
/**
 * @brief Get an uint32_t worth of bits from a span
 * @param src Span of uint32_t's that bits will be collected from
 * @param src_bit Bit index to start from
 * @return Bits from the span
 */
std::uint32_t get_bits(std::span<const std::uint32_t> src, std::size_t src_bit) {
  std::uint32_t bits = 0;
  const std::size_t shift = src_bit & 0x1F;
  const std::size_t index = src_bit >> 5;
  if (shift != 0) {
    bits = src[index] >> shift;
    if (index + 1 < src.size())
      bits = bits | src[index + 1] << (32 - shift);
  } else {
    bits = src[index];
  }
  return bits;
}
}  // namespace detail
/**
 * @brief this is a variant of blit that focuses on whole destination indices and bit count subtraction
 * Only writes its bitmasks!
 * @note Commented out as used during development, might come in handy when debugging
 */
/*
void blit_mask(std::span<std::uint32_t> dst, std::span<std::uint32_t> src, size_t src_bit, size_t dst_bit, size_t
bit_width, Blit_ops op) { std::size_t bit_count = bit_width; std::uint32_t bits; std::uint32_t mask = 0xFFFFFFFF; std::size_t
todo_bits = 32;
  // handle starting incomplete element
  // determine if we have an incomplete element
  std::size_t header_bits = dst_bit& 0x1F;
  if (header_bits != 0) {
    // setup loop to handle incomplete element
    todo_bits = todo_bits - header_bits;
    mask = 0xFFFFFFFF << header_bits;
    // check if we have a very small span
    if (todo_bits > bit_count) {
      mask = mask & (0xFFFFFFFF >> (todo_bits - bit_count));
      todo_bits = bit_count;
    }
  }
  // handle complete elements
  while (bit_count > 0) {
    bits = mask;
    blit_op(dst[dst_bit >> 5], bits, mask, op);

    bit_count = bit_count - todo_bits;
    src_bit += todo_bits;
    dst_bit += todo_bits;

    if (bit_count > 31) {
      mask = 0xFFFFFFFF;
      todo_bits = 32;
    } else if (bit_count > 0) {
      // last incomplete element
      mask = 0xFFFFFFFF >> (32 - bit_count);
      todo_bits = bit_count;
    }
  }
}
*/
void blit(std::span<std::uint32_t> dst, std::span<const std::uint32_t> src, std::size_t pixel_bits, std::size_t pixel_width,
          std::size_t pixel_dst, std::size_t pixel_src, Blit_ops op, Blit_policy policy) {
  if (pixel_bits == 0 || pixel_width == 0) {
    return;
  }
  // check for order
  if (dst.data() == src.data()) {
    if (pixel_dst > pixel_src) {
      std::swap(pixel_dst, pixel_src);
    }
  }
  // clamp pixel_width
  const std::size_t dst_pixel_width = (dst.size() * 32) / pixel_bits;
  if (pixel_dst + pixel_width > dst_pixel_width) {
    pixel_width = dst_pixel_width - pixel_dst;
  }
  switch (policy) {
    case Blit_policy::SMALL:
      switch (op) {
        case Blit_ops::COPY:
          Blit_small::template blit<Blit_op_copy>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits,
                                                  pixel_width * pixel_bits);
          break;
        case Blit_ops::INVERT:
          Blit_small::template blit<Blit_op_invert>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits,
                                                    pixel_width * pixel_bits);
          break;
        case Blit_ops::AND:
          Blit_small::template blit<Blit_op_and>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits,
                                                 pixel_width * pixel_bits);
          break;
        case Blit_ops::OR:
          Blit_small::template blit<Blit_op_or>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits, pixel_width * pixel_bits);
          break;
        case Blit_ops::XOR:
          Blit_small::template blit<Blit_op_xor>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits,
                                                 pixel_width * pixel_bits);
          break;
        default:
          break;
      }
      break;
    case Blit_policy::BALANCED:
    case Blit_policy::FAST:  // Fallthrough
      switch (op) {
        case Blit_ops::COPY:
          Blit_balanced::template blit<Blit_op_copy>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits,
                                                     pixel_width * pixel_bits);
          break;
        case Blit_ops::INVERT:
          Blit_balanced::template blit<Blit_op_invert>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits,
                                                       pixel_width * pixel_bits);
          break;
        case Blit_ops::AND:
          Blit_balanced::template blit<Blit_op_and>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits,
                                                    pixel_width * pixel_bits);
          break;
        case Blit_ops::OR:
          Blit_balanced::template blit<Blit_op_or>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits,
                                                   pixel_width * pixel_bits);
          break;
        case Blit_ops::XOR:
          Blit_balanced::template blit<Blit_op_xor>(dst, src, pixel_dst * pixel_bits, pixel_src * pixel_bits,
                                                    pixel_width * pixel_bits);
          break;
        default:
          break;
      }
      break;
  }
}
}  // namespace libmcu::bitmap