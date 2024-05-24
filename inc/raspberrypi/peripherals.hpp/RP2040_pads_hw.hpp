/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 general pads register interface
 */
#ifndef RP2040_PADS_HW_HPP
#define RP2040_PADS_HW_HPP

namespace libMcuLL::hw::pads {

namespace VOLTAGE_SELECT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0001u}; /**< Mask for allowed bits */
constexpr inline std::uint32_t VOLTAGE_3_3V{0u << 0};       /**< Set I/O voltage to 3.3V */
constexpr inline std::uint32_t VOLTAGE_1_8V{1u << 0};       /**< Set I/O voltage to 1.8V */
}  // namespace VOLTAGE_SELECT
namespace GPIO {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t DEFAULT{0x0000'0056u};       /**< Default value for register */
constexpr inline std::uint32_t OD{1u << 7};                 /**< Output disable, overrides peripheral */
constexpr inline std::uint32_t IE{1u << 6};                 /**< Input enable */
/**
 * @brief Format DRIVE field to GPIO register
 * @param level drive level, see DRIVE_ definitions
 * @return DRIVE field formatted to GPIO register
 */
constexpr inline std::uint32_t DRIVE(uint32_t level) {
  return level << 4;
}
constexpr inline std::uint32_t DRIVE_2MA{0x0u};   /**< 2 milliAmpere drive level */
constexpr inline std::uint32_t DRIVE_4MA{0x1u};   /**< 4 milliAmpere drive level */
constexpr inline std::uint32_t DRIVE_8MA{0x2u};   /**< 8 milliAmpere drive level */
constexpr inline std::uint32_t DRIVE_12MA{0x3u};  /**< 12 milliAmpere drive level */
constexpr inline std::uint32_t PUE{1u << 3};      /**< Pullup enable */
constexpr inline std::uint32_t PDE{1u << 2};      /**< Pulldown enable */
constexpr inline std::uint32_t SCHMITT{1u << 1};  /**< Schmitt trigger enable */
constexpr inline std::uint32_t SLEWFAST{1u << 0}; /**< Fast slew rate control */
}  // namespace GPIO
}  // namespace libMcuLL::hw::pads
#endif