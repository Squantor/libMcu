/*
SPDX-License-Identifier: MIT

Copyright (c) 2026 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/**
 * \file blit.hpp
 * \brief Function definitions for Blitting functions
 */
#ifndef BLIT_HPP
#define BLIT_HPP

#include <libmcu/bitmap/bitmap_view.hpp>

namespace libmcu::bitmap {

/**
 * @brief Blit function
 * @tparam Dst_pixel Destination pixel type
 * @tparam Src_pixel Source pixel type
 * @param dst_bitmap Destination bitmap
 * @param src_bitmap Source bitmap
 * @param dst_x destination x coordinate
 * @param dst_y destination y coordinate
 * @param src_x source x coordinate
 * @param src_y source y coordinate
 * @param src_width source width
 * @param src_height source height
 */
template <typename Dst_pixel, typename Src_pixel>
constexpr void blit(Bitmap_view<Dst_pixel> dst_bitmap, Bitmap_view<const Src_pixel> src_bitmap, std::uint16_t dst_x,
                    std::uint16_t dst_y, std::uint16_t src_x = 0, std::uint16_t src_y = 0, std::uint16_t src_width = 0,
                    std::uint16_t src_height = 0) {
  if (src_width == 0)
    src_width = src_bitmap.get_width();
  if (src_height == 0)
    src_height = src_bitmap.get_height();
  std::uint16_t dst_x_idx = dst_x;
  std::uint16_t dst_y_idx = dst_y;
  for (std::uint16_t src_y_idx = src_x; src_y_idx < src_height; src_y_idx++) {
    for (std::uint16_t src_x_idx = src_y; src_x_idx < src_width; src_x_idx++) {
      dst_bitmap.set_pixel(dst_x_idx, dst_y_idx, src_bitmap.get_pixel(src_x_idx, src_y_idx));
      dst_x_idx++;
      if (dst_x_idx >= dst_bitmap.get_width())
        break;
    }
    dst_x_idx = dst_x;
    dst_y_idx++;
    if (dst_y_idx >= dst_bitmap.get_height())
      break;
  }
}
}  // namespace libmcu::bitmap

#endif  // BLIT_HPP