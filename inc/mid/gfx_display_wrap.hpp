/**
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file gfx_display_wrap.hpp
 * @brief Graphical display wrapper middle ware class definition
 * Wraps a graphical display driver and provides a fully featured graphical display interface
 */
#ifndef CHAR_DISPLAY_WRAP_HPP
#define CHAR_DISPLAY_WRAP_HPP

#include "../libmcu/libmcumid.hpp"
#include "../libmcu/libmcudrv.hpp"
#include "font.hpp"

namespace libmcumid {
/**
 * @brief Graphical display wrapper
 * @todo add print function
 * @todo add clear function
 * @todo add flip function
 * @todo static methods?
 * @tparam display driver to use
 */
template <auto& display>
requires libmcudrv::Derived_from_gfx_display<std::remove_cvref_t<decltype(display)> >
class Gfx_display_wrap {
  using Display_type = std::remove_reference_t<decltype(display)>;
  using Pixel_type = Display_type::Pixel_type;
  using Coord_type = Display_type::Coord_type;

 public:
  Gfx_display_wrap() : cursor_x{0}, cursor_y{0} {}
  Coord_type get_width() {
    return display.get_width();
  }
  Coord_type get_height() {
    return display.get_height();
  }
  void flip() {
    display.flip();
  }
  void clear(Pixel_type color = 0) {
    display.clear(color);
    cursor_x = 0;
    cursor_y = 0;
  }
  /**
   * @brief
   * @param x_coord
   * @param y_coord
   * @param c
   * @param font
   */
  void print(Coord_type x_coord, Coord_type y_coord, char c, libmcumid::Font& font) {
    auto glyph = font.get_glyph(c);
    display.blit(x_coord, y_coord, glyph);
  }
  /**
   * @brief print character while keeping a cursor
   * @param c Character to print
   * @param font Font to use
   */
  void print(char c, libmcumid::Font& font) {
    if (c == '\n') {
      cursor_x = 0;
      cursor_y += font.height;
    } else {
      print(cursor_x, cursor_y, c, font);
      cursor_x += font.width;
    }
  }
  /**
   * @brief Console like print C string that keeps a position
   * @param str
   * @param font
   */
  void print(const char* str, libmcumid::Font& font) {
    while (*str != '\0') {
      print(*str, font);
      str++;
    }
  }
  /**
   * @brief
   * @param x_coord
   * @param y_coord
   * @param str
   * @param font
   */
  void print(std::uint16_t x_coord, std::uint16_t y_coord, const char* str, libmcumid::Font& font) {
    while (*str != '\0') {
      print(x_coord, y_coord, *str, font);
      str++;
      x_coord += font.width;
    }
  }

  void print(libmcumid::Hex n, libmcumid::Font& font) {
    detail::print(n, [this, &font](const auto c) {
      print(c, font);
    });
  }

  void print(libmcumid::Dec n, libmcumid::Font& font) {
    detail::print(n, [this, &font](const auto c) {
      print(c, font);
    });
  }

 private:
  std::uint16_t cursor_x;
  std::uint16_t cursor_y;
};
}  // namespace libmcumid

#endif