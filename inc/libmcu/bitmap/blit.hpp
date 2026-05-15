/**
 * SPDX-License-Identifier: MIT
 * 
 * Copyright (c) 2026 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 *
 * @file blit.hpp
 * @brief Function definitions for Blitting functions
 */
#ifndef BLIT_HPP
#define BLIT_HPP

#include <libmcu/bitmap/bitmap.hpp>

//extern libmcull::systick::Systick<libmcuhw::SystickAddress> systick_peripheral;
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
void blit_old(Bitmap dst_bitmap, Const_bitmap src_bitmap, std::uint16_t dst_x,
                    std::uint16_t dst_y, std::uint16_t src_x = 0, std::uint16_t src_y = 0, std::uint16_t src_width = 0,
                    std::uint16_t src_height = 0) ;
}  // namespace libmcu::bitmap

#endif  // BLIT_HPP