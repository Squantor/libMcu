/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file bitmap.hpp
 * @brief bitmap types used by libMcu
 */
#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <span>
#include <cstdint>

namespace libmcu {

/**
 * @brief Bitmap base definition
 * @tparam CoordType type of coordinate values
 * @tparam PixelType type of pixels
 */
template <typename CoordType, typename PixelType, std::size_t bits_per_pixel>
struct Bitmap {
  Bitmap(CoordType x, CoordType y, std::span<PixelType> data) : max_x{x}, max_y{y}, bitmap{data} {}
  Bitmap(void) : max_x{0}, max_y{0}, bitmap{std::span<PixelType>{}} {}
  CoordType max_x, max_y;
  std::span<PixelType> bitmap;
};

// Predefined bitmap types used in libmcu
using BitmapSmallMono = Bitmap<std::uint8_t, std::uint8_t, 1>; /*!< Small monochrome bitmap */
using BitmapBigMono = Bitmap<std::uint16_t, std::uint8_t, 1>;  /*!< Big monochrome bitmap */

}  // namespace libmcu

#endif