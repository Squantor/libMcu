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
#include <libmcu/bitmap/bitmap_view.hpp>
#include <libmcu/bitmap/blit.hpp>

namespace libmcumid {
struct Font {
 public:
  constexpr Font(std::span<const std::uint16_t> mapping, libmcu::bitmap::Const_bitmap &bitmap, std::uint16_t glyph_width,
                 std::uint16_t glyph_height)
    : mapping_table{mapping}, bitmap_font{bitmap}, width{glyph_width}, height{glyph_height} {}
  constexpr void get_glyph(char character, libmcu::bitmap::Bitmap &bitmap) {
    std::uint32_t glyph_y_pos = mapping_table[character];
    libmcu::bitmap::blit(bitmap, bitmap_font, 0, 0, 0, glyph_y_pos, width, height);
  }

 private:
  std::span<const std::uint16_t> mapping_table;
  libmcu::bitmap::Const_bitmap &bitmap_font;
  std::uint16_t width, height;
};
}  // namespace libmcumid

#endif