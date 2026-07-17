/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file eeprom_24xxx_configs.hpp
 * @brief various 24XXX configurations
 */
#ifndef EEPROM_24XXX_CONFIGS_HPP
#define EEPROM_24XXX_CONFIGS_HPP

#include <cstdint>

namespace libmcudrv::eeprom_24xxx {

/**
 * @brief 24XXX configuration
 * @tparam byte_count Total amount of bytes
 * @tparam bytes_per_page Page size
 */
template <std::uint16_t byte_count, std::uint16_t bytes_per_page, std::uint8_t bytes_per_address>
struct Config {
  static constexpr inline std::uint16_t bytes{byte_count};              /*!< total amount of bytes */
  static constexpr inline std::uint16_t page_size{bytes_per_page};      /*!< Size of a page */
  static constexpr inline std::uint8_t address_size{bytes_per_address}; /*!< number of bytes per address */
};

using Generic_24xxx02 = Config<256, 16, 1>; /*!< Generic 2 Kbit 24C02*/

}  // namespace libmcudrv::eeprom_24xxx

#endif