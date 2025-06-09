/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_iocon_hw.hpp
 * @brief Register structure and bit definitions for the LPC840 series IOCON
 */
#ifndef LPC84X_IOCON_HW_HPP
#define LPC84X_IOCON_HW_HPP

namespace libmcuhw::iocon {
/**
 * @brief IOCON register definitions
 */
struct Iocon {
  volatile std::uint32_t PIO[56]; /*!< Pin control registers */
};
namespace PIO {
constexpr inline std::uint32_t RESERVED_MASK{0x0001FC78u}; /*!< Register mask for allowed bits */
constexpr inline std::uint32_t kINACTIVE{0u << 3};         /*!< No pullup/down */
constexpr inline std::uint32_t kPULLDOWN{1u << 3};         /*!< Pulldown enabled */
constexpr inline std::uint32_t kPULLUP{2u << 3};           /*!< Pullup enabled */
constexpr inline std::uint32_t kREPEATER{3u << 3};         /*!< Repeater mode */
constexpr inline std::uint32_t kHYS{1u << 5};              /*!< Hysteresis enable */
constexpr inline std::uint32_t kINV{1u << 6};              /*!< Invert input enable */
constexpr inline std::uint32_t kI2C_STD{0u << 8};          /*!< standard/fast I2C mode */
constexpr inline std::uint32_t kIO_STD{1u << 8};           /*!< standard I/O functionality */
constexpr inline std::uint32_t kI2C_FAST{2u << 8};         /*!< fast mode plus I2C */
constexpr inline std::uint32_t kOD{1u << 10};              /*!< Open drain enable */
constexpr inline std::uint32_t kBYPASS{0u << 11};          /*!< Bypassed input filter */
constexpr inline std::uint32_t kCYCLES1{1u << 11};         /*!< 1 clock cycle pulses are filtered */
constexpr inline std::uint32_t kCYCLES2{2u << 11};         /*!< 2 clock cycle pulses are filtered */
constexpr inline std::uint32_t kCYCLES3{3u << 11};         /*!< 3 clock cycle pulses are filtered */
constexpr inline std::uint32_t kIOCONCLKDIV0{0u << 13};    /*!< use IOCONCLKDIV0 in SYSCON */
constexpr inline std::uint32_t kIOCONCLKDIV1{1u << 13};    /*!< use IOCONCLKDIV1 in SYSCON */
constexpr inline std::uint32_t kIOCONCLKDIV2{2u << 13};    /*!< use IOCONCLKDIV2 in SYSCON */
constexpr inline std::uint32_t kIOCONCLKDIV3{3u << 13};    /*!< use IOCONCLKDIV3 in SYSCON */
constexpr inline std::uint32_t kIOCONCLKDIV4{4u << 13};    /*!< use IOCONCLKDIV4 in SYSCON */
constexpr inline std::uint32_t kIOCONCLKDIV5{5u << 13};    /*!< use IOCONCLKDIV5 in SYSCON */
constexpr inline std::uint32_t kIOCONCLKDIV6{6u << 13};    /*!< use IOCONCLKDIV6 in SYSCON */
constexpr inline std::uint32_t kDACMODE{1 << 16};          /*!< DAC mode enable */
}  // namespace PIO
}  // namespace libmcuhw::iocon
#endif