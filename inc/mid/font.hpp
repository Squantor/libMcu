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

namespace libmcumid {
struct Font {
 public:
  constexpr Font(std::span<const std::uint16_t> mapping) : mapping_table{mapping} {}

 private:
  std::span<const std::uint16_t> mapping_table;
};
}  // namespace libmcumid

#endif