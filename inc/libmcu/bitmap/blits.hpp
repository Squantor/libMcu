/**
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file blits.hpp
 * @brief Various bit blit functions
 * @version 20260403
 *
 */
#ifndef BLITS_HPP
#define BLITS_HPP

#include <cstdint>
#include <span>
#include "operations.hpp"
#include "bitmap.hpp"

namespace libmcu::bitmap {
/**
 * @brief Blit policies for speed or size
 */
enum class Blit_policy : std::uint8_t {
  SMALL,
  BALANCED,
  FAST
};
namespace detail {
/**
 * @brief Get the bits object
 * @param src
 * @param src_bit
 * @return std::uint32_t
 */
std::uint32_t get_bits(std::span<const std::uint32_t> src, std::size_t src_bit);
}  // namespace detail
/**
 * @brief 1D blit template class with size optimized blit static method
 */
struct Blit_small {
  /**
   * @brief 1D blit operating on bits only, small but slow
   * @todo add memmove semantics
   * @tparam Blit_op Blit operation to use
   * @param dst destination span
   * @param src source span
   * @param src_bit Source bit index
   * @param dst_bit Destination bit index
   * @param bit_width Number of bits to copy
   */
  template <typename Blit_op>
  static void blit(std::span<std::uint32_t> dst, std::span<const std::uint32_t> src, std::size_t dst_bit, std::size_t src_bit,
                   std::size_t bit_width) {
    // setup source/destination masks
    std::uint32_t src_mask = 0x00000001 << (src_bit & 0x1F);
    std::uint32_t dst_mask = 0x00000001 << (dst_bit & 0x1F);
    for (size_t i = 0; i < bit_width; i++) {
      // extract one bit from source
      uint32_t bit = src[src_bit >> 5] & src_mask;
      // convert bit to destination bit position
      if (bit != 0) {
        bit = dst_mask;
      } else {
        bit = 0;
      }
      // write one bit to destination with the operation in mind
      Blit_op::run(dst[dst_bit >> 5], bit, dst_mask);
      // shift masks
      src_mask = src_mask << 1;
      if (src_mask == 0) {
        src_mask = 0x00000001;
      }
      dst_mask = dst_mask << 1;
      if (dst_mask == 0) {
        dst_mask = 0x00000001;
      }
      src_bit++;
      dst_bit++;
    }
  }
};
/**
 * @brief 1D blit template class with size and speed optimized blit static method
 */
struct Blit_balanced {
  /**
   * @brief 1D blit operating on bits only, balanced between size and speed
   * @tparam Blit_op Blit operation to use
   * @param dst Span of uint32_t's containing the destination bits
   * @param src Span of uint32_t's containing the source bits
   * @param dst_bit Destination bit index for dst
   * @param src_bit Source bit index for src
   * @param bit_width Number of bits to blit
   * @param op Blit operation
   * @todo reading from source can be slow, cache source element from source element+1
   * @todo Simplify loop by using a pre and post but this requires first to get rid of get_bits calls
   */
  template <typename Blit_op>
  static void blit(std::span<std::uint32_t> dst, std::span<const std::uint32_t> src, size_t dst_bit, size_t src_bit,
                   size_t bit_width) {
    std::size_t bit_count = bit_width;
    std::uint32_t bits;
    std::uint32_t mask = 0xFFFFFFFF;
    std::size_t todo_bits = 32;
    // handle starting incomplete element
    // determine if we start with an incomplete element
    std::size_t header_offset = dst_bit & 0x1F;
    if (header_offset != 0) {
      // setup loop to handle first incomplete element
      todo_bits = todo_bits - header_offset;
      mask = 0xFFFFFFFF << header_offset;
    }
    // check if we have a very small span
    if (todo_bits > bit_count) {
      mask = mask & (0xFFFFFFFF >> (todo_bits - bit_count));
      todo_bits = bit_count;
    }
    // handle complete elements
    while (bit_count > 0) {
      if (src_bit < header_offset) {
        // the header offset is out of bounds, fixup
        bits = src[0] << (header_offset - src_bit);
      } else {
        bits = detail::get_bits(src, src_bit - header_offset);
      }

      Blit_op::run(dst[dst_bit >> 5], bits, mask);

      bit_count -= todo_bits;
      src_bit += todo_bits;
      dst_bit += todo_bits;
      header_offset = 0;  // reset header offset

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
};
/**
 * @brief Bit Block transfer pixels from source to destination
 * @param dst Span of uint32_t's containing the destination pixels
 * @param src Span of uint32_t's containing the source pixels
 * @param pixel_bits Bits per pixel
 * @param pixel_width Width of pixels to blit
 * @param pixel_dst Destination pixel index of the blit
 * @param pixel_src Source pixel index of the blit
 * @param op Blit operation
 */
void blit(std::span<std::uint32_t> dst, std::span<const std::uint32_t> src, std::size_t pixel_bits, std::size_t pixel_width,
          std::size_t pixel_dst, std::size_t pixel_src, Blit_ops op = Blit_ops::COPY, Blit_policy policy = Blit_policy::BALANCED);
/**
 * @brief 2D blit operating on bitmaps with a destination coordinate
 * @param dst Destination bitmap
 * @param src Source bitmap
 * @param dst_coords Destination coordinate
 * @param op Blit operation
 */
void blit_bitmap(Bitmap dst, Const_bitmap src, Bitmap_coords dst_coords, Blit_ops op = Blit_ops::COPY,
                 Blit_policy policy = Blit_policy::BALANCED);
/**
 * @brief 2D blit operating on bitmaps with a source coordinate/dimension and a destination coordinate
 * @param dst Destination bitmap
 * @param src Source bitmap
 * @param dst_coords Destination coordinate
 * @param src_coords Source coordinate
 * @param src_size Source dimensions
 * @param op Blit operation
 */
void blit_bitmap(Bitmap dst, Const_bitmap src, Bitmap_coords dst_coords, Bitmap_coords src_coords, Bitmap_size src_size,
                 Blit_ops op = Blit_ops::COPY, Blit_policy policy = Blit_policy::BALANCED);
}  // namespace libmcu::bitmap
#endif