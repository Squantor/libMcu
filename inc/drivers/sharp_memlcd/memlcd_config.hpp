/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file memlcd_config.hpp
 * @brief various Sharp memory LCD configurations
 */
#ifndef MEMLCD_CONFIG_HPP
#define MEMLCD_CONFIG_HPP

#include <cstdint>

namespace libMcuDrv::memlcd {
/**
 * @brief Sharp memory LCD configuration structure
 * @tparam xSize Maximum X coordinate
 * @tparam ySize  Maximum Y coordinate
 * @tparam shift Shift position for the line address
 */
template <int xSize, int ySize, int shift>
struct config {
  static constexpr inline auto maxX{xSize};      /*!< X size of the LCD */
  static constexpr inline auto maxY{ySize};      /*!< Y size of the LCD */
  static constexpr inline auto addrShift{shift}; /*!< amount of shift for putting address in right spot */
};

// few example LCD configurations
using LS010B7DH04 = config<128, 128, 8>;
using LS010B7DH01 = config<128, 128, 8>;
using LS011B7DH03 = config<160, 68, 8>;
using LS013B4DN04 = config<96, 96, 8>;
using LS013B7DH03 = config<128, 128, 8>;
using LS013B7DH05 = config<144, 168, 8>;
using LS027B7DH01 = config<400, 240, 8>;
using LS032B7DD02 = config<336, 536, 6>;
}  // namespace libMcuDrv::memlcd

#endif