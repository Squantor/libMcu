/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 pads bank 0 register interface
 */
#ifndef RP2040_PADS_BANK0_HW_HPP
#define RP2040_PADS_BANK0_HW_HPP

#include "RP2040_pads_hw.hpp"

namespace libMcuHw::padsBank0 {

using namespace libMcuHw::pads;
/**
 * @brief Bank 0 pads definition
 */
struct padsBank0 {
  volatile std::uint32_t VOLTAGE_SELECT; /**< Voltage select. Per bank control */
  volatile std::uint32_t GPIO[30];       /**< Pad control register */
  volatile std::uint32_t SWCLK;          /**< Pad control register */
  volatile std::uint32_t SWD;            /**< Pad control register */
};
namespace SWCLK {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< Mask for allowed bits */
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
}  // namespace SWCLK
namespace SWD {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'00FFu}; /**< Mask for allowed bits */
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
}  // namespace SWD
}  // namespace libMcuHw::padsBank0
#endif