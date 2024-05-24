/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file systick register interface
 */
#ifndef SYSTICK_HW_HPP
#define SYSTICK_HW_HPP
namespace libMcuLL::hw::systick {
struct peripheral {
  volatile std::uint32_t CSR;         /**< systick control and status register */
  volatile std::uint32_t RVR;         /**< systick reload value register */
  volatile std::uint32_t CVR;         /**< systick current value register */
  volatile const std::uint32_t CALIB; /**< systick calibration register */
};
namespace CSR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00010007; /**< register mask for allowed bits */
constexpr inline std::uint32_t ENABLE = (1 << 0);          /**< enable systick */
constexpr inline std::uint32_t TICKINT = (1 << 1);         /**< enable systick interrupt */
constexpr inline std::uint32_t CLKSOURCE_EXT = (0 << 2);   /**< select external reference clock */
constexpr inline std::uint32_t CLKSOURCE_PROC = (1 << 2);  /**< select processor clock */
constexpr inline std::uint32_t COUNTFLAG_MASK = (1 << 16); /** 1 if counter passed 0 after last read */
}  // namespace CSR
namespace RVR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00FFFFFF; /**< register mask for allowed bits */
/**
 * @brief format RELOAD field
 *
 * @param value reload value
 * @return formatted RVR register
 */
constexpr inline std::uint32_t RELOAD(std::uint32_t value) {
  return value << 0;
}
}  // namespace RVR
namespace CVR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00FFFFFF; /**< register mask for allowed bits */
constexpr inline std::uint32_t CURRENT_MASK = 0x00FFFFFF;  /**< current value of systick timer */
}  // namespace CVR
namespace CALIB {
constexpr inline std::uint32_t RESERVED_MASK = 0xC0FFFFFF; /**< register mask for allowed bits */
constexpr inline std::uint32_t TENMS_MASK = 0x00FFFFFFFF;  /**< reload counter value for 10ms interval*/
constexpr inline std::uint32_t SKEW_MASK = (1 << 30);      /**< indicates TENMS is rounded from non integer ratio */
constexpr inline std::uint32_t NOREF_MASK = (1 << 31);     /**< indicates if there is a reference clock */
}  // namespace CALIB
}  // namespace libMcuLL::hw::systick
#endif