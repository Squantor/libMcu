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
#include "bitmap.hpp"

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
 * @brief simple blit that copies bit by bit, used for correctness checks
 * @todo add memmove semantics
 * @note Mostly used for debugging and correctness checks, quite slow
 * @tparam Blit_op Blit operation to use
 * @param dst destination span
 * @param src source span
 * @param src_bit Source bit index
 * @param dst_bit Destination bit index
 * @param bit_width Number of bits to copy
 */
template <typename Blit_op>
void blit_1d_bits_simple(std::span<std::uint32_t> dst, std::span<std::uint32_t> src, std::size_t dst_bit, std::size_t src_bit,
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

/**
 * @brief 1D blit operating on bits only
 * @tparam Blit_op Blit operation to use
 * @param dst Span of uint32_t's containing the destination bits
 * @param src Span of uint32_t's containing the source bits
 * @param dst_bit Destination bit index for dst
 * @param src_bit Source bit index for src
 * @param bit_width Number of bits to blit
 * @param op Blit operation
 * @note More optimized for size than raw speed, but still better then single bit reads
 * @note this is a variant of blit that focuses on whole destination indices and bit count subtraction
 * @todo reading from source can be slow, cache source element from source element+1
 * @todo Simplify loop by using a pre and post but this requires first to get rid of get_bits calls
 */
template <typename Blit_op>
void blit_1d_bits(std::span<std::uint32_t> dst, std::span<const std::uint32_t> src, size_t dst_bit, size_t src_bit,
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
/**
 * @brief 1D blit operating on pixels, each pixel is one or more bits
 * @param dst Span of uint32_t's containing the destination pixels
 * @param src Span of uint32_t's containing the source pixels
 * @param pixel_bits Bits per pixel
 * @param pixel_width Width of pixels to blit
 * @param pixel_dst Destination pixel index of the blit
 * @param pixel_src Source pixel index of the blit
 * @param op Blit operation
 */
void blit_1d_pixels(std::span<std::uint32_t> dst, std::span<const std::uint32_t> src, std::size_t pixel_bits,
                    std::size_t pixel_width, std::size_t pixel_dst, std::size_t pixel_src, Blit_ops op = Blit_ops::COPY);
/**
 * @brief 2D blit operating on bitmaps with a destination coordinate
 * @param dst Destination bitmap
 * @param src Source bitmap
 * @param dst_coords Destination coordinate
 * @param op Blit operation
 */
void blit_bitmap(Bitmap dst, Const_bitmap src, Bitmap_coords dst_coords, Blit_ops op = Blit_ops::COPY);
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
                 Blit_ops op = Blit_ops::COPY);

}  // namespace libmcu::bitmap
#endif