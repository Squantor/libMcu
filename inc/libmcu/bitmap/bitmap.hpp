/**
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file bitmap_view.hpp
 * @brief Class definitions for bitmap class
 */
#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <cstdint>
#include <type_traits>
#include <limits>
#include <concepts>

namespace libmcu::bitmap {

using Bitmap_coord = std::uint16_t; /*!< Bitmap coordinate type */
using Bitmap_bbp = std::uint8_t;    /*!< Bitmap bits per pixel type */
/**
 * @brief Bitmap coordinates set
 */
struct Bitmap_coords {
  Bitmap_coord x{0}; /*!< X coordinate */
  Bitmap_coord y{0}; /*!< Y coordinate */
};
/**
 * @brief Bitmap size
 */
struct Bitmap_size {
  Bitmap_coord w{0}; /*!< Width */
  Bitmap_coord h{0}; /*!< Height */
};

namespace detail {
template <typename T>
concept Unsigned32Bit = sizeof(T) == 4 && std::unsigned_integral<T>;

/**
 * @brief Class for representing a bitmap
 * @todo Change the data to a std::span
 * @tparam T
 */
template <Unsigned32Bit T>
class Bitmap_view {
 public:
  using Pixel_type = T;
  constexpr Bitmap_view(Pixel_type *bitmap_data, Bitmap_size bitmap_dimensions, Bitmap_bbp bitmap_bits_per_pixel)
    : data_bitmap(bitmap_data), dimensions(bitmap_dimensions), bits_per_pixel(bitmap_bits_per_pixel) {}
  /**
   * @brief Get the size of the bitmap
   * @return Bitmap_size of the bitmap
   */
  [[nodiscard]] constexpr Bitmap_size get_size() const {
    return dimensions;
  }
  /**
   * @brief Get the bits per pixel of the bitmap
   * @return Bits per pixel of the bitmap
   */
  [[nodiscard]] constexpr Bitmap_bbp get_bits_per_pixel() const {
    return bits_per_pixel;
  }
  /**
   * @brief Get the data of the bitmap
   * @return Data of the bitmap
   */
  [[nodiscard]] constexpr Pixel_type *data() const {
    return data_bitmap;
  }
  /**
   * @brief Fill the bitmap with a value
   * @param pixel Value to fill with
   */
  constexpr void fill(Pixel_type pixel)
  requires(!std::is_const_v<Pixel_type>)
  {
    Pixel_type fill_value = pixel;
    const std::size_t fill_count = 32 / bits_per_pixel;
    for (std::size_t count = 0; count < fill_count; count++) {
      fill_value = fill_value | static_cast<Pixel_type>(fill_value << bits_per_pixel);
    }
    const std::size_t max_bitmap_index = (dimensions.w * dimensions.h * bits_per_pixel) >> 5;
    for (std::size_t i = 0; i < max_bitmap_index; i++) {
      data_bitmap[i] = fill_value;
    }
  }
  /**
   * @brief Get a const version of the bitmap
   * @return constexpr Bitmap_view<const T>
   */
  [[nodiscard]] constexpr Bitmap_view<const T> as_const() const {
    return Bitmap_view<const T>{data_bitmap, Bitmap_size{dimensions.w, dimensions.h}, bits_per_pixel};
  }
  /**
   * @brief Get the pixel value
   * @param x X coordinate
   * @param y Y coordinate
   * @return Pixel value at location x,y
   */
  [[nodiscard]] constexpr Pixel_type get_pixel(Bitmap_coord x, Bitmap_coord y) const {
    if (x >= dimensions.w || y >= dimensions.h)
      return 0;
    using Pixel_type_nonconst = std::remove_const_t<Pixel_type>;
    const std::size_t pixel_index = (y * dimensions.w) + x;
    const std::size_t bit_index = pixel_index * bits_per_pixel;
    const std::size_t data_index = bit_index >> 5;
    const std::size_t lsb_shift = bit_index & 31;
    Pixel_type_nonconst mask = 0xFFFFFFFF >> (32 - bits_per_pixel);
    mask = static_cast<Pixel_type_nonconst>(mask << lsb_shift);
    const Pixel_type_nonconst pixel = static_cast<Pixel_type_nonconst>((data_bitmap[data_index] & mask) >> lsb_shift);
    return pixel;
  }
  /**
   * @brief Set the pixel value
   * @param x X coordinate
   * @param y Y coordinate
   * @param pixel Pixel value
   */
  constexpr void set_pixel(Bitmap_coord x, Bitmap_coord y, Pixel_type pixel)
  requires(!std::is_const_v<Pixel_type>)
  {
    if (x >= dimensions.w || y >= dimensions.h)
      return;
    const std::size_t pixel_index = (y * dimensions.w) + x;
    const std::size_t bit_index = pixel_index * bits_per_pixel;
    const std::size_t data_index = bit_index >> 5;
    const std::size_t lsb_shift = bit_index & 31;
    Pixel_type mask = 0xFFFFFFFF >> (32 - bits_per_pixel);
    mask = static_cast<Pixel_type>(mask << lsb_shift);
    data_bitmap[data_index] = static_cast<Pixel_type>((data_bitmap[data_index] & ~mask) | (pixel << lsb_shift));
  }

 private:
  Pixel_type *data_bitmap;
  Bitmap_size dimensions;
  Bitmap_bbp bits_per_pixel;
};
}  // namespace detail

using Bitmap = detail::Bitmap_view<std::uint32_t>;
using Const_bitmap = detail::Bitmap_view<const std::uint32_t>;

}  // namespace libmcu::bitmap

#endif  // BITMAP_HPP