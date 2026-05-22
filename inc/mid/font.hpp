/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file font.hpp
 * @brief Font middleware class definitions
 */
#ifndef FONT_HPP
#define FONT_HPP

#include <cstdint>
#include <span>
#include <libmcu/bitmap/bitmap.hpp>
#include <libmcu/bitmap/blits.hpp>

namespace libmcumid {
struct Font {
 public:
  Font(std::span<const std::uint16_t> mapping, libmcu::bitmap::Const_bitmap &bitmap, std::uint16_t glyph_width,
       std::uint16_t glyph_height)
    : width{glyph_width}, height{glyph_height}, mapping_table{mapping}, bitmap_font{bitmap} {}

  void get_glyph(char character, libmcu::bitmap::Bitmap &bitmap) {
    libmcu::bitmap::Bitmap_coord glyph_y_pos = mapping_table[character];
    libmcu::bitmap::blit_bitmap(bitmap, bitmap_font, libmcu::bitmap::Bitmap_coords{0, 0},
                                libmcu::bitmap::Bitmap_coords{0, glyph_y_pos}, libmcu::bitmap::Bitmap_size{width, height},
                                libmcu::bitmap::Blit_ops::COPY, libmcu::bitmap::Blit_policy::BALANCED);
  }

  libmcu::bitmap::Const_bitmap get_glyph(char character) {
    libmcu::bitmap::Bitmap_coord glyph_y_pos = mapping_table[character];
    libmcu::bitmap::blit_bitmap(temp_glyph, bitmap_font, libmcu::bitmap::Bitmap_coords{0, 0},
                                libmcu::bitmap::Bitmap_coords{0, glyph_y_pos}, libmcu::bitmap::Bitmap_size{width, height},
                                libmcu::bitmap::Blit_ops::COPY, libmcu::bitmap::Blit_policy::BALANCED);
    return temp_glyph.as_const();
  }
  std::uint16_t width, height;

 private:
  std::span<const std::uint16_t> mapping_table;
  libmcu::bitmap::Const_bitmap &bitmap_font;
  std::array<std::uint32_t, 2> glyph_buffer;
  libmcu::bitmap::Bitmap temp_glyph{glyph_buffer.data(), libmcu::bitmap::Bitmap_size{8, 8}, 1};
};
}  // namespace libmcumid

#endif