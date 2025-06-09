/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_timer_hw.hpp
 * @brief Register structure and bit definitions for the RP2040 Timer
 */
#ifndef RP2040_TIMER_HW_HPP
#define RP2040_TIMER_HW_HPP

namespace libmcuhw::timer {
/**
 * @brief Timer register definitions
 */
struct Timer {
  volatile std::uint32_t DUMMY; /*!< Fill in */
};
namespace DUMMY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /*!< Mask for allowed bits */
}  // namespace DUMMY
}  // namespace libmcuhw::timer
#endif