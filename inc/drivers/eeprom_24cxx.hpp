/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file EEPROM_24CXX.hpp
 * @brief Driver for the 24CXX series I2C EEPROM
 */
#ifndef EEPROM_24CXX_HPP
#define EEPROM_24CXX_HPP

#include "eeprom_24cxx/eeprom_24cxx_configs.hpp"

namespace libmcudrv::eeprom_24cxx {
namespace i2c = libmcuhal::i2c;
template <typename config, auto &i2c_hal>
struct Eeprom24cxx {};
}  // namespace libmcudrv::eeprom_24cxx

#endif