/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file STM32F0_syscfg_hw.hpp
 * @brief Register structure and bit definitions for the STM32F0 System configuration
 */
#ifndef STM32F0_SYSCFG_HW_HPP
#define STM32F0_SYSCFG_HW_HPP

namespace libmcuhw::syscfg {
/**
 * @brief syscfg register definitions
 */
struct syscfg {
  volatile std::uint32_t CFGR1;     /*!< SYSCFG configuration register 1 */
  std::uint32_t RESERVED1;          /*!< Reserved */
  volatile std::uint32_t EXTICR[4]; /*!< SYSCFG external interrupt configuration register */
  volatile std::uint32_t CFGR2;     /*!< SYSCFG configuration register 2 */
};
namespace CFGR1 {
constexpr inline std::uint32_t kRESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace EXTICR {
constexpr inline std::uint32_t kRESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
namespace CFGR2 {
constexpr inline std::uint32_t kRESERVED_MASK = 0xFFFFFFFFu; /*!< register mask for allowed bits */
}
}  // namespace libmcuhw::syscfg
#endif