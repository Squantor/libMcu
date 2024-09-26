/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 CRC register interface
 */
#ifndef LPC84X_CRC_HW_HPP
#define LPC84X_CRC_HW_HPP

namespace libMcuLL::hw::crc {
/**
 * @brief CRC register definitions
 */
struct peripheral {
  volatile std::uint32_t MODE;        /**< CRC mode register */
  volatile std::uint32_t SEED;        /**< CRC seed register */
  union {                             /* */
    volatile const std::uint32_t SUM; /**< CRC checksum register */
    volatile std::uint32_t WR_DATA;   /**< CRC data register */
  };
};
}  // namespace libMcuLL::hw::crc
#endif