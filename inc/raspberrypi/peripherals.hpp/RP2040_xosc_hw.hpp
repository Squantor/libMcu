/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 XOSC register interface
 */
#ifndef RP2040_XOSC_HW_HPP
#define RP2040_XOSC_HW_HPP

namespace libMcuHw::xosc {
/**
 * @brief XOSC register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t CTRL;    /**< Control */
  volatile std::uint32_t STATUS;  /**< Status */
  volatile std::uint32_t DORMANT; /**< Pause control */
  volatile std::uint32_t STARTUP; /**< Startup delay */
  volatile std::uint32_t COUNT;   /**< Down counter */
};
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x00FF'FFFFu}; /**< mask for allowed bits */
constexpr inline std::uint32_t ENABLE{0xFABu << 12};        /**< Magic value to enable */
constexpr inline std::uint32_t DISABLE{0xD1Eu << 12};       /**< Magic value to disable */
constexpr inline std::uint32_t FREQ_15MHZ{0xAA0u << 0};     /**< 15MHz oscillator range*/
}  // namespace CTRL
namespace STATUS {
constexpr inline std::uint32_t RESERVED_MASK{0x8100'1003u}; /**< mask for allowed bits */
constexpr inline std::uint32_t STABLE_MASK{1u << 31};       /**< Oscillator running and stable */
constexpr inline std::uint32_t BADWRITE_MASK{1u << 24};     /**< Bad value written */
constexpr inline std::uint32_t ENABLED_MASK{1u << 12};      /**< oscillator just enabled */
constexpr inline std::uint32_t FREQ_RANGE_MASK{3u << 0};    /**< frequency range setting */
}  // namespace STATUS
namespace DORMANT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< mask for allowed bits */
constexpr inline std::uint32_t DORMANT{0x636F6D61u};        /**< set oscillator to dormant */
constexpr inline std::uint32_t WAKE{0x77616B65u};           /**< set oscillator to wake */
}  // namespace DORMANT
namespace STARTUP {
constexpr inline std::uint32_t RESERVED_MASK{0x0010'3FFFu}; /**< mask for allowed bits */
constexpr inline std::uint32_t X4{1u << 20};                /**< Multiply delay by 4 */
constexpr inline std::uint32_t DELAY_MASK{0x3FFFu << 0};    /**< Delay counter mask */
/**
 * @brief Format DELAY field to STARTUP register
 * @param delay delay of crystal startup handover, in multipes of 256 of the xtal period
 * @return DELAY field formatted to STARTUP register
 */
constexpr inline std::uint32_t DELAY(uint32_t delay) {
  return DELAY_MASK & (delay << 0);
}
}  // namespace STARTUP
namespace COUNT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FF}; /**< mask for allowed bits */
}  // namespace COUNT
}  // namespace libMcuHw::xosc
#endif