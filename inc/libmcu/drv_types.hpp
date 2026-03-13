/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file drv_types.hpp
 * @brief Types used by libmcu drivers
 */
#ifndef DRV_TYPES_HPP
#define DRV_TYPES_HPP

#include <libmcu/bitmap/bitmap_view.hpp>

namespace libmcudrv {
/**
 * @brief Driver base class that all Driver classes should inherit from
 * You will never copy/move a Driver, they are "eternal" with respect to program lifetime
 */
struct DriverBase {
  DriverBase() = default;
  ~DriverBase() = default;
  DriverBase(const DriverBase&) = delete;
  DriverBase& operator=(const DriverBase&) = delete;
  DriverBase(DriverBase&&) = delete;
  DriverBase& operator=(DriverBase&&) = delete;
};

enum class Display_state : uint8_t {
  Off,
  On,
  Inverted,
};

/**
 * @brief Graphical display driver base class
 * They are all nonblocking by default
 */
template <typename CoordType, typename PixelType>
struct GfxDisplay : public DriverBase, public libmcu::NonBlocking {
  /**
   * @brief Get the pixel width
   * @return Pixel width count
   */
  virtual CoordType get_width(void) = 0;
  /**
   * @brief Get the pixel height
   * @return Pixel height count
   */
  virtual CoordType get_height(void) = 0;
  /**
   * @brief Transfer display buffer to the display
   * @todo should have an argument for callbacks when done flipping as it is a timeconsuming operation
   */
  virtual void flip(void) = 0;
  virtual void clear(PixelType) = 0;
  virtual void set_state(Display_state) = 0;
  virtual void set_pixel(CoordType, CoordType, PixelType) = 0;
  virtual void blit(CoordType, CoordType, const libmcu::bitmap::Bitmap_view<const uint32_t>&) = 0;
};

}  // namespace libmcudrv

#endif