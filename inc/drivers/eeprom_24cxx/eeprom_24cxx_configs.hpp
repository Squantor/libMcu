/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file eeprom_24cxx_configs.hpp
 * @brief various 24CXX configurations
 */
#ifndef EEPROM_24CXX_CONFIGS_HPP
#define EEPROM_24CXX_CONFIGS_HPP

#include <cstdint>

namespace libmcudrv::eeprom_24cxx {

/**
 * @brief 24CXX configuration
 * @tparam byte_size Total amount of bytes
 * @tparam page_size Page size
 */
template <std::size_t byte_size, std::size_t page_size>
struct Config {
  static constexpr inline auto bytes{byte_size}; /*!< total amount of bytes */
  static constexpr inline auto page{page_size};  /*!< Size of a page */
};

using Generic24C02 = Config<256, 16>; /*!< Generic 2 Kbit 24C02*/

}  // namespace libmcudrv::eeprom_24cxx

#endif