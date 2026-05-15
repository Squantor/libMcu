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

extern libmcull::systick::Systick<libmcuhw::SystickAddress> systick_peripheral;
extern volatile std::uint32_t ticks;

namespace libmcu::bitmap {

/**
 * @brief Blit function
 * @param dst_bitmap Destination bitmap
 * @param src_bitmap Source bitmap
 * @param dst_x destination x coordinate
 * @param dst_y destination y coordinate
 * @param src_x source x coordinate
 * @param src_y source y coordinate
 * @param src_width source width
 * @param src_height source height
 */
constexpr void blit(Bitmap dst_bitmap, Const_bitmap src_bitmap, std::uint16_t dst_x,
                    std::uint16_t dst_y, std::uint16_t src_x = 0, std::uint16_t src_y = 0, std::uint16_t src_width = 0,
                    std::uint16_t src_height = 0) {
  
  uint16_t src_x_end;
  uint16_t src_y_end;
  Bitmap_size src_size = src_bitmap.get_size();
  Bitmap_size dst_size = dst_bitmap.get_size();
  if (src_width == 0)
    src_x_end = src_size.w;
  else {
    src_x_end = src_x + src_width;
    if (src_x_end > src_size.w)
      src_x_end = src_size.w;
  }
  if (src_height == 0)
    src_y_end = src_size.h;
  else {
    src_y_end = src_y + src_height;
    if (src_y_end > src_size.h)
      src_y_end = src_size.h;
  }
  std::uint32_t start_ticks = ticks;
  std::uint32_t start_systicks = systick_peripheral.GetCount();

  std::uint16_t dst_x_idx = dst_x;
  std::uint16_t dst_y_idx = dst_y;
  for (std::uint16_t src_y_idx = src_y; src_y_idx < src_y_end; src_y_idx++) {
    for (std::uint16_t src_x_idx = src_x; src_x_idx < src_x_end; src_x_idx++) {
      dst_bitmap.set_pixel(dst_x_idx, dst_y_idx, src_bitmap.get_pixel(src_x_idx, src_y_idx));
      dst_x_idx++;
      if (dst_x_idx >= dst_size.w)
        break;
    }
    dst_x_idx = dst_x;
    dst_y_idx++;
    if (dst_y_idx >= dst_size.h)
      break;
  }
  std::uint32_t end_ticks = ticks;
  std::uint32_t end_systicks = systick_peripheral.GetCount();
  std::uint32_t total_systicks = 0;
  if (start_ticks == end_ticks) {
    total_systicks = start_systicks - end_systicks;
  }
  if (total_systicks > 60000) {
    libmcull::nop();
  }
}
}  // namespace libmcu::bitmap

#endif  // BLIT_HPP