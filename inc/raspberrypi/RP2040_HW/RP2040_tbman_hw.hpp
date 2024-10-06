/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Testbench manager register interface
 */
#ifndef RP2040_TBMAN_HW_HPP
#define RP2040_TBMAN_HW_HPP

namespace libMcuHw::tbman {
/**
 * @brief Testbench manager register definitions
 */
struct tbman {
  volatile std::uint32_t PLATFORM; /**< Fill in */
};
namespace PLATFORM {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0001u}; /**< Mask for allowed bits */
}  // namespace PLATFORM
}  // namespace libMcuHw::tbman
#endif