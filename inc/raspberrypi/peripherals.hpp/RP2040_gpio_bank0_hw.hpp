/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Sysinfo register interface
 */
#ifndef RP2040_GPIO_BANK0_HW_HPP
#define RP2040_GPIO_BANK0_HW_HPP

namespace libMcuLL {
namespace hw {
namespace gpioBank0 {
/**
 * @brief GPIO  register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t CHIP_ID;       /**< JEDEC JEP-106 chip identifier */
  volatile std::uint32_t PLATFORM;      /**< Platform register */
  volatile std::uint32_t GITREF_RP2040; /**< Git hash of the chip source. */
};
namespace CHIP_ID {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFF'FFFF; /**< Mask for allowed bits */
}
}  // namespace gpioBank0
}  // namespace hw
}  // namespace libMcuLL
#endif