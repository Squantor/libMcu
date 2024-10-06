/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Flash memory control register interface
 */
#ifndef LPC81X_FMC_REGS_HPP
#define LPC81X_FMC_REGS_HPP

namespace libMcuLL::hw::fmc {
/**
 * @brief flash controller register definitions
 */
struct fmc {
  volatile const std::uint32_t RESERVED1[4]; /**< reserved */
  volatile std::uint32_t FLASHCFG;           /**< Flash Configuration register */
  volatile const std::uint32_t RESERVED2[3]; /**< reserved */
  volatile std::uint32_t FMSSTART;           /**< Signature start address register */
  volatile std::uint32_t FMSSTOP;            /**< Signature stop address register */
  volatile const std::uint32_t RESERVED3;    /**< reserved */
  volatile const std::uint32_t FMSW[1];      /**< Signature word regsiter */
};
namespace FLASHCFG {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t FLASHTIM_1_CLOCK{0u << 0};   /**< 1 clock flash access time*/
constexpr inline std::uint32_t FLASHTIM_2_CLOCK{1u << 0};   /**< 1 clock flash access time*/
}  // namespace FLASHCFG
namespace FMSSTART {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace FMSSTART
namespace FMSSTOP {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace FMSSTOP
namespace FMSW {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< register mask for allowed bits */
}  // namespace FMSW

}  // namespace libMcuLL::hw::fmc
#endif