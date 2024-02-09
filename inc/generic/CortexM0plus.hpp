/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file Main entry point for a generic cortex M0+ microcontroller definitions
 */
#ifndef CORTEXM0PLUS_HPP
#define CORTEXM0PLUS_HPP

namespace libMcuLL {
namespace hw {
// MCU configuration options
namespace core {
constexpr inline std::uint32_t revision = 0x0001; /**< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool present = false; /**< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool present = true; /**< presence of vector relocation */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t variant = 0; /**< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t priorityMask = 0x3; /**< NVIC priority bit mask */
constexpr inline std::uint32_t priorityBits = 2;   /** NVIC priority bit count */
}  // namespace nvic

enum class interrupts : int8_t {
  reset = -15,
  nonMaskable = -14,
  hardFault = -13,
  svCall = -5,
  pendSv = -2,
  systick = -1,
};
}  // namespace hw
}  // namespace libMcuLL

#include <CortexM/cortex_m0plus.hpp>

#endif
