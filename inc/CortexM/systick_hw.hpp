/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file systick_hw.hpp
 * @brief Register structure and bit definitions for the Cortex M systick
 */
#ifndef SYSTICK_HW_HPP
#define SYSTICK_HW_HPP

namespace libmcuhw::systick {
/**
 * @brief register interface for the system tick
 */
struct systick {
  volatile std::uint32_t CSR;         /*!< systick control and status register */
  volatile std::uint32_t RVR;         /*!< systick reload value register */
  volatile std::uint32_t CVR;         /*!< systick current value register */
  volatile const std::uint32_t CALIB; /*!< systick calibration register */
};
namespace CSR {
constexpr inline std::uint32_t kRESERVED_MASK{0x00010007u}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kENABLE{1u << 0};            /*!< enable systick */
constexpr inline std::uint32_t kTICKINT{1u << 1};           /*!< enable systick interrupt */
constexpr inline std::uint32_t kCLKSOURCE_EXT{0u << 2};     /*!< select external reference clock */
constexpr inline std::uint32_t kCLKSOURCE_PROC{1u << 2};    /*!< select processor clock */
constexpr inline std::uint32_t kCOUNTFLAG_MASK{1u << 16};   /** 1 if counter passed 0 after last read */
}  // namespace CSR
namespace RVR {
constexpr inline std::uint32_t RESERVED_MASK{0x00FFFFFFu}; /*!< register mask for allowed bits */
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
constexpr inline std::uint32_t kRESERVED_MASK{0x00FFFFFFu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kCURRENT_MASK{0x00FFFFFFu};  /*!< current value of systick timer */
}  // namespace CVR
namespace CALIB {
constexpr inline std::uint32_t kRESERVED_MASK{0xC0FFFFFFu}; /*!< register mask for allowed bits */
constexpr inline std::uint32_t kTENMS_MASK{0x00FFFFFFFFu};  /*!< reload counter value for 10ms interval*/
constexpr inline std::uint32_t kSKEW_MASK{1u << 30};        /*!< indicates TENMS is rounded from non integer ratio */
constexpr inline std::uint32_t kNOREF_MASK{1u << 31};       /*!< indicates if there is a reference clock */
}  // namespace CALIB
}  // namespace libmcuhw::systick
#endif