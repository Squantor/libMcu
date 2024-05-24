/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 System config register interface
 */
#ifndef RP2040_SYSCFG_HW_HPP
#define RP2040_SYSCFG_HW_HPP

namespace libMcuLL::hw::syscfg {
/**
 * @brief System config register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t PROC0_NMI_MASK;         /*!< Processor core 0 NMI source mask */
  volatile std::uint32_t PROC1_NMI_MASK;         /*!< Processor core 1 NMI source mask */
  volatile std::uint32_t PROC_CONFIG;            /*!< Configuration for processors */
  volatile std::uint32_t PROC_IN_SYNC_BYPASS;    /*!< bypass GPIO input synchroniser and SIO */
  volatile std::uint32_t PROC_IN_SYNC_BYPASS_HI; /*!< bypass QSPI GPIO input synchroniser and SIO */
  volatile std::uint32_t DBGFORCE;               /*!< Control the SWD debug port of either processor */
  volatile std::uint32_t MEMPOWERDOWN;           /*!< Control power downs to memories */
};
namespace PROC0_NMI_MASK {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace PROC0_NMI_MASK
namespace PROC1_NMI_MASK {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace PROC1_NMI_MASK
namespace PROC_CONFIG {
constexpr inline std::uint32_t RESERVED_MASK{0xFF00'0003u}; /**< Mask for allowed bits */
}  // namespace PROC_CONFIG
namespace PROC_IN_SYNC_BYPASS {
constexpr inline std::uint32_t RESERVED_MASK{0x3FFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace PROC_IN_SYNC_BYPASS
namespace PROC_IN_SYNC_BYPASS_HI {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'003Fu}; /**< Mask for allowed bits */
}  // namespace PROC_IN_SYNC_BYPASS_HI
namespace DBGFORCE {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< Mask for allowed bits */
}  // namespace DBGFORCE
namespace MEMPOWERDOWN {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< Mask for allowed bits */
}  // namespace MEMPOWERDOWN
}  // namespace libMcuLL::hw::syscfg
#endif