/**
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file blit_bitmap.hpp
 * @brief bitmap blit functions
 * @version 20260430
 *
 */

#include <cstddef>
#include <cmath>
#include <span>
#include "libmcu/bitmap/blits.hpp"
#include "libmcu/bitmap/bitmap.hpp"

namespace libmcu::bitmap {

/**
 * @brief Blit bitmap loop
 * @note No checks on input parameters performed
 * @tparam Blit_op Blit operation class to use
 * @param dst Destination bitmap
 * @param src Source bitmap
 * @param dst_x Destination X coordinate
 * @param dst_y Destination Y coordinate
 * @param src_x Source X coordinate
 * @param src_y Source Y coordinate
 * @param src_width Source width
 * @param src_height Source height
 */
template <typename Blit_op>
void blit_bitmap_loop(Bitmap dst, Const_bitmap src, Bitmap_coords dst_coords, Bitmap_coords src_coords, Bitmap_size src_size) {
  // prepare bounds/sizes
  const Bitmap_size dst_bitmap_size{dst.get_size()};
  const Bitmap_size src_bitmap_size{src.get_size()};
  const std::size_t src_width_bit_count{static_cast<std::size_t>(src_size.w) * static_cast<std::size_t>(src.get_bits_per_pixel())};
  const std::size_t src_span_size{(static_cast<std::size_t>(src_bitmap_size.w) * static_cast<std::size_t>(src_bitmap_size.h) *
                                   static_cast<std::size_t>(src.get_bits_per_pixel())) /
                                  32};
  const std::size_t dst_span_size{(static_cast<std::size_t>(dst_bitmap_size.w) * static_cast<std::size_t>(dst_bitmap_size.h) *
                                   static_cast<std::size_t>(dst.get_bits_per_pixel())) /
                                  32};
  const std::span src_span(src.data(), src_span_size);
  const std::span dst_span(dst.data(), dst_span_size);
  const std::size_t src_bit_stride{static_cast<std::size_t>(src_bitmap_size.w) *
                                   static_cast<std::size_t>(src.get_bits_per_pixel())};
  const std::size_t dst_bit_stride{static_cast<std::size_t>(dst_bitmap_size.w) *
                                   static_cast<std::size_t>(dst.get_bits_per_pixel())};
  const std::size_t src_bit_end{((src_coords.y + src_size.h) * src_bitmap_size.w + src_coords.x) *
                                static_cast<std::size_t>(src.get_bits_per_pixel())};
  std::size_t src_bit_index{(src_coords.y * src_bitmap_size.w + src_coords.x) * static_cast<std::size_t>(src.get_bits_per_pixel())};
  std::size_t dst_bit_index{static_cast<std::size_t>(dst_coords.y * dst_bitmap_size.w + dst_coords.x) *
                            static_cast<std::size_t>(dst.get_bits_per_pixel())};
  while (src_bit_index < src_bit_end) {
    blit_1d_bits<Blit_op>(dst_span, src_span, dst_bit_index, src_bit_index, src_width_bit_count);
    src_bit_index += src_bit_stride;
    dst_bit_index += dst_bit_stride;
    //! @todo adjust src_bit_end to match destination to get this check out of the loop
    if (dst_bit_index > dst_span_size * 32) {
      break;
    }
  }
}

void blit_bitmap(Bitmap dst, Const_bitmap src, Bitmap_coords dst_coords, Blit_ops op) {
  const Bitmap_size src_bitmap_size{src.get_size()};
  blit_bitmap(dst, src, dst_coords, Bitmap_coords{0, 0}, src_bitmap_size, op);
}

/**
 * @todo Check if bitmaps are the same bit depths
 */
void blit_bitmap(Bitmap dst, Const_bitmap src, Bitmap_coords dst_coords, Bitmap_coords src_coords, Bitmap_size src_size,
                 Blit_ops op) {
  const Bitmap_size dst_bitmap_size{dst.get_size()};
  const Bitmap_size src_bitmap_size{src.get_size()};

  if (dst_coords.y >= dst_bitmap_size.h || dst_coords.x >= dst_bitmap_size.w) {
    return;
  }
  if (src_coords.y >= src_bitmap_size.h || src_coords.x >= src_bitmap_size.w) {
    return;
  }
  // clamp bit counts depending on bitmap sizes
  if (src_coords.x + src_size.w > src_bitmap_size.w) {
    src_size.w = src_bitmap_size.w - src_coords.x;
  }
  if (dst_coords.x + src_size.w > dst_bitmap_size.w) {
    src_size.w = dst_bitmap_size.w - dst_coords.x;
  }
  switch (op) {
    case Blit_ops::COPY:
      blit_bitmap_loop<Blit_op_copy>(dst, src, dst_coords, src_coords, src_size);
      break;
    case Blit_ops::INVERT:
      blit_bitmap_loop<Blit_op_invert>(dst, src, dst_coords, src_coords, src_size);
      break;
    case Blit_ops::AND:
      blit_bitmap_loop<Blit_op_and>(dst, src, dst_coords, src_coords, src_size);
      break;
    case Blit_ops::OR:
      blit_bitmap_loop<Blit_op_or>(dst, src, dst_coords, src_coords, src_size);
      break;
    case Blit_ops::XOR:
      blit_bitmap_loop<Blit_op_xor>(dst, src, dst_coords, src_coords, src_size);
      break;
    default:
      break;
  }
}

}