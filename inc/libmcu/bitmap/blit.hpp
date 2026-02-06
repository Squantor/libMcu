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

#include <libmcu/bitmap/bitmap.hpp>

namespace libmcu::bitmap {

template <typename Src_pixel, typename Dst_pixel>
constexpr void blit(Bitmap_view<const Src_pixel> src, Bitmap_view<Dst_pixel> dst, std::uint16_t dst_x, std::uint16_t dst_y) {
  for (std::uint16_t src_x = 0; src_x < src.get_height(); src_x++) {
    for (std::uint16_t src_y = 0; src_y < src.get_width(); src_y++) {
      dst.set_pixel(dst_x + src_x, dst_y + src_y, src.get_pixel(src_x, src_y));
    }
  }
}
}  // namespace libmcu::bitmap

#endif  // BLIT_HPP