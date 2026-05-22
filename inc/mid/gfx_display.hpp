/**
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file gfx_display.hpp
 * @brief Graphical display wrapper middle ware class definition
 * Wraps a graphical display driver and provides a fully featured graphical display interface
 */
#ifndef GFX_DISPLAY_HPP
#define GFX_DISPLAY_HPP

#include "../libmcu/libmcumid.hpp"
#include "../libmcu/libmcudrv.hpp"
#include "font.hpp"

namespace libmcumid {
/**
 * @brief Graphical display wrapper
 * @todo set/get pixel
 * @todo static methods?
 * @tparam display driver to use
 */
template <auto& display>
requires libmcudrv::Derived_from_gfx_display_driver<std::remove_cvref_t<decltype(display)> >
class Gfx_display {
  using Display_type = std::remove_reference_t<decltype(display)>;
  using Pixel_type = Display_type::Pixel_type;
  using Coord_type = Display_type::Coord_type;

 public:
  Gfx_display() : cursor_x{0}, cursor_y{0} {}
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
  void print(Coord_type x_coord, Coord_type y_coord, char c, libmcumid::Font& font,
             libmcu::bitmap::Blit_ops op = libmcu::bitmap::Blit_ops::COPY) {
    auto glyph = font.get_glyph(c);
    display.blit(x_coord, y_coord, glyph, op);
  }
  /**
   * @brief print character while keeping a cursor
   * @param c Character to print
   * @param font Font to use
   */
  void print(char c, libmcumid::Font& font, libmcu::bitmap::Blit_ops op = libmcu::bitmap::Blit_ops::COPY) {
    if (c == '\n') {
      cursor_x = 0;
      cursor_y += font.height;
    } else {
      print(cursor_x, cursor_y, c, font, op);
      cursor_x += font.width;
    }
  }
  /**
   * @brief Console like print C string that keeps a position
   * @param str
   * @param font
   */
  void print(const char* str, libmcumid::Font& font, libmcu::bitmap::Blit_ops op = libmcu::bitmap::Blit_ops::COPY) {
    while (*str != '\0') {
      print(*str, font, op);
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
  void print(std::uint16_t x_coord, std::uint16_t y_coord, const char* str, libmcumid::Font& font,
             libmcu::bitmap::Blit_ops op = libmcu::bitmap::Blit_ops::COPY) {
    while (*str != '\0') {
      print(x_coord, y_coord, *str, font, op);
      str++;
      x_coord += font.width;
    }
  }

  void print(libmcumid::Hex n, libmcumid::Font& font, libmcu::bitmap::Blit_ops op = libmcu::bitmap::Blit_ops::COPY) {
    detail::print(n, [this, &font, op](const auto c) {
      print(c, font, op);
    });
  }

  void print(libmcumid::Dec n, libmcumid::Font& font, libmcu::bitmap::Blit_ops op = libmcu::bitmap::Blit_ops::COPY) {
    detail::print(n, [this, &font, op](const auto c) {
      print(c, font, op);
    });
  }

 private:
  std::uint16_t cursor_x;
  std::uint16_t cursor_y;
};
}  // namespace libmcumid

#endif