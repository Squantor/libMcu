/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file char_display_wrap.hpp
 * @brief Character display wrapper middle ware class definition
 * Wraps a graphical display driver and provides a character display interface
 * that is row and column based, requires a font to be provided. This font will
 * determine the total width/height of the display
 */
#ifndef CHAR_DISPLAY_WRAP_HPP
#define CHAR_DISPLAY_WRAP_HPP

#include "../libmcu/libmcumid.hpp"
#include "../libmcu/libmcudrv.hpp"
// include for graphical display driver interface

namespace libmcumid {

/**
 * @brief
 * @todo add font template parameter
 * @tparam display driver to use
 */
template <auto& display>
requires libmcudrv::DerivedFromGfxDisplay<std::remove_cvref_t<decltype(display)> >
class CharDisplayWrap {
 public:
  // TODO
 private:
};
}  // namespace libmcumid

#endif