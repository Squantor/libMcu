/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_xip_ctrl_hw.hpp
 * @brief Register structure and bit definitions for the RP2040 Execute In Place
 */
#ifndef RP2040_XIP_CTRL_HW_HPP
#define RP2040_XIP_CTRL_HW_HPP

namespace libmcuhw::xip {
/**
 * @brief Execute In Place register definitions
 */
struct Xip {
  volatile std::uint32_t DUMMY; /*!< Fill in */
};
namespace DUMMY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /*!< Mask for allowed bits */
}  // namespace DUMMY
}  // namespace libmcuhw::xip
#endif