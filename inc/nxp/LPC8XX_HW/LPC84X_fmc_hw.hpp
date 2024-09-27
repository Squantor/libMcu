/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Flash Memory Controller register interface
 */
#ifndef LPC84X_FMC_HW_HPP
#define LPC84X_FMC_HW_HPP

namespace libMcuHw::fmc {
/**
 * @brief FMC register definitions
 */
struct fmc {
  std::uint8_t RESERVED_0[16];            /**< Reserved */
  volatile std::uint32_t FLASHCFG;        /**< Flash configuration register */
  std::uint8_t RESERVED_1[12];            /**< Reserved */
  volatile std::uint32_t FMSSTART;        /**< Flash signature start address register */
  volatile std::uint32_t FMSSTOP;         /**< Flash signaure stop address register */
  std::uint8_t RESERVED_2[4];             /**< Reserved */
  volatile std::uint32_t FMSW0;           /**< Flash signature generation result register */
  std::uint8_t RESERVED_3[4016];          /**< Reserved */
  volatile std::uint32_t FMSTAT;          /**< Flash signature generation status bit */
  std::uint8_t RESERVED_4[4];             /**< Reserved */
  volatile const std::uint32_t FMSTATCLR; /**< Clear FLASH signature generation status bit */
};
}  // namespace libMcuHw::fmc
#endif