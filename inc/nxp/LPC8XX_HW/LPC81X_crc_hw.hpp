/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_crc_hw.hpp
 * @brief Register structure and bit definitions for the LPC810 series CRC peripheral
 */
#ifndef LPC81X_CRC_HW_HPP
#define LPC81X_CRC_HW_HPP

namespace libmcuhw::crc {

/**
 * @brief gpio register definitions
 */
struct Crc {
  volatile std::uint32_t MODE; /*!< CRC Mode Register */
  volatile std::uint32_t SEED; /*!< CRC SEED Register */
  union {
    volatile const std::uint32_t SUM; /*!< CRC Checksum Register. */
    volatile std::uint32_t WRDATA32;  /*!< CRC Data Register: write size 32-bit */
    volatile std::uint16_t WRDATA16;  /*!< CRC Data Register: write size 16-bit */
    volatile std::uint8_t WRDATA8;    /*!< CRC Data Register: write size 8-bit */
  };
};

}  // namespace libmcuhw::crc
#endif