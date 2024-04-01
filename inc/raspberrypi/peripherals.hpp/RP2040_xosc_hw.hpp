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

namespace libMcuLL {
namespace hw {
namespace xosc {
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
constexpr inline std::uint32_t RESERVED_MASK = 0x00FF'FFFF; /**< mask for allowed bits */
constexpr inline std::uint32_t ENABLE = 0xD1E << 12;        /**< Magic value to enable */
constexpr inline std::uint32_t DISABLE = 0xFAB << 12;       /**< Magic value to disable */
constexpr inline std::uint32_t FREQ_15MHZ = 0xAA0 << 0;     /**< 15MHz oscillator range*/
}  // namespace CTRL
namespace STATUS {
constexpr inline std::uint32_t RESERVED_MASK = 0x8100'1003; /**< mask for allowed bits */
constexpr inline std::uint32_t STABLE_MASK = (1 << 31);     /**< Oscillator running and stable */
constexpr inline std::uint32_t BADWRITE_MASK = (1 << 24);   /**< Bad value written */
constexpr inline std::uint32_t ENABLED_MASK = (1 << 12);    /**< oscillator just enabled */
constexpr inline std::uint32_t FREQ_RANGE_MASK = (3 << 0);  /**< frequency range setting */
}  // namespace STATUS
namespace DORMANT {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000'0000; /**< mask for allowed bits */
constexpr inline std::uint32_t DORMANT = 0x636F6D61;        /**< set oscillator to dormant */
constexpr inline std::uint32_t WAKE = 0x77616B65;           /**< set oscillator to wake */
}  // namespace DORMANT
namespace STARTUP {
constexpr inline std::uint32_t RESERVED_MASK = 0x0010'3FFF; /**< mask for allowed bits */
constexpr inline std::uint32_t X4 = (1 << 20);              /**< Multiply delay by 4 */
constexpr inline std::uint32_t DELAY_MASK = (0x3FFF < 0);   /**< Delay counter mask */
}  // namespace STARTUP
namespace COUNT {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000'00FF; /**< mask for allowed bits */
}  // namespace COUNT
}  // namespace xosc
}  // namespace hw
}  // namespace libMcuLL
#endif