/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file libmcu_CortexM0plus_ll.hpp
 * \brief Main entry point for a generic cortex M0+ microcontroller definitions
 */
#ifndef LIBMCU_CORTEXM0PLUS_LL_HPP
#define LIBMCU_CORTEXM0PLUS_LL_HPP

#include "../libmcu/libmcull.hpp"
#include "../libmcu/general_functions_CM0.hpp"

namespace libmcuhw {
// MCU configuration options
namespace core {
constexpr inline std::uint32_t Revision{0x0001}; /*!< Revision number */
}  // namespace core
namespace mpu {
constexpr inline bool Present{false}; /*!< Presence of memory protection unit */
}  // namespace mpu
namespace vtor {
constexpr inline bool Present{true};                      /*!< presence of vector relocation */
constexpr inline std::uint32_t AddressMask{0xFFFFFF00UL}; /*!< VTOR bit count */
}  // namespace vtor
namespace systick {
constexpr inline std::uint32_t Variant{0}; /*!< Type of systick */
}  // namespace systick
namespace nvic {
constexpr inline std::uint32_t PriorityMask{0x3}; /*!< NVIC priority bit mask */
constexpr inline std::uint32_t PriorityBits{2};   /*!< NVIC priority bit count */
}  // namespace nvic

enum class Interrupts : int8_t {
  Reset = -15,
  NonMaskable = -14,
  HardFault = -13,
  SvCall = -5,
  PendSv = -2,
  Systick = -1,
  Dummy0 = 0,   /*!< used only for the tests */
  Dummy1 = 1,   /*!< used only for the tests */
  Dummy12 = 12, /*!< used only for the tests */
};
}  // namespace libmcuhw

#include "../CortexM/cortex_m0plus.hpp"

#endif
