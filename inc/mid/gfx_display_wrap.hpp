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
  }
  void print(const char* str) {}

 private:
};

}  // namespace libmcumid

#endif