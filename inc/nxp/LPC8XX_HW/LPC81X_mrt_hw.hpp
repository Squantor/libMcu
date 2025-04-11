/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC81X_mrt_hw.hpp
 * @brief Register structure and bit definitions for the LPC810 series Multi rate timer
 */
#ifndef LPC81X_MRT_HW_HPP
#define LPC81X_MRT_HW_HPP

namespace libmcuhw::mrt {

/**
 * @brief Multi rate timer channel definition
 * @todo try and fold this in mrt peripheral?
 */
struct MrtChannel {
  volatile std::uint32_t INTVAL; /* Timer interval register */
  volatile std::uint32_t TIMER;  /* Timer register */
  volatile std::uint32_t CTRL;   /* Timer control register */
  volatile std::uint32_t STAT;   /* Timer status register */
};
/**
 * @brief Multi rate timer register definitions
 */
struct Mrt {
  MrtChannel CHANNEL[4];
  volatile std::uint32_t RESERVED1[45];
  volatile std::uint32_t IDLE_CH;
  volatile std::uint32_t IRQ_FLAG;
};

}  // namespace libmcuhw::mrt
#endif