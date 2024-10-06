/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for a generic cortex M0+ microcontroller definitions
 */
#ifndef LIBMCU_CORTEXM0PLUS_LL_HPP
#define LIBMCU_CORTEXM0PLUS_LL_HPP

#include <cstdint>
#include <cstddef>
#include <array>
#include <span>
#include <type_traits>
#include <limits>
#include "../libmcu/libmcu_results.hpp"
#include "../libmcu/libmcu_types.hpp"
#include "../libmcu/libmcu_functions.hpp"
#include "../libmcu/libmcull_types.hpp"
#include "../libmcu/ringbuffer.hpp"

namespace libMcuHw {
// MCU configuration options
namespace core {
constexpr inline std::uint32_t revision = 0x0001; /**< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool present = false; /**< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool present = true;                      /**< presence of vector relocation */
constexpr inline std::uint32_t addressMask = 0xFFFFFF00UL; /**< VTOR bit count */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t variant = 0; /**< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t priorityMask = 0x3; /**< NVIC priority bit mask */
constexpr inline std::uint32_t priorityBits = 2;   /**< NVIC priority bit count */
}  // namespace nvic

enum class interrupts : int8_t {
  reset = -15,
  nonMaskable = -14,
  hardFault = -13,
  svCall = -5,
  pendSv = -2,
  systick = -1,
  dummy0 = 0,   /**< used only for the tests */
  dummy1 = 1,   /**< used only for the tests */
  dummy12 = 12, /**< used only for the tests */
};
}  // namespace libMcuHw

#include "../CortexM/cortex_m0plus.hpp"

#endif
