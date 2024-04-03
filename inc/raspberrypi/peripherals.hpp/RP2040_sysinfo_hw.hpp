/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Sysinfo register interface
 */
#ifndef RP2040_SYSINFO_HW_HPP
#define RP2040_SYSINFO_HW_HPP

namespace libMcuLL {
namespace hw {
namespace sysinfo {
/**
 * @brief SYSINFO register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t CHIP_ID;       /**< JEDEC JEP-106 chip identifier */
  volatile std::uint32_t PLATFORM;      /**< Platform register */
  volatile std::uint32_t GITREF_RP2040; /**< Git hash of the chip source. */
};
namespace CHIP_ID {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFF'FFFF; /**< Mask for allowed bits */
constexpr inline std::uint32_t REVISION_MASK = 0xF << 28;   /**< Revison */
constexpr inline std::uint32_t PART_MASK = 0xFFFF << 12;    /**< Part number */
constexpr inline std::uint32_t REVISION_MASK = 0xFFF << 0;  /**< Manufacturer ID */
}  // namespace CHIP_ID
namespace PLATFORM {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000'0003; /**< mask for allowed bits */
constexpr inline std::uint32_t ASIC_MASK = 1 << 1;          /**< Running on ASIC environment */
constexpr inline std::uint32_t FPGA_MASK = 1 << 0;          /**< Running on FPGA environment */
}  // namespace PLATFORM
namespace GITREF_RP2040 {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFF'FFFF; /**< mask for allowed bits */
constexpr inline std::uint32_t
}  // namespace GITREF_RP2040
}  // namespace sysinfo
}  // namespace hw
}  // namespace libMcuLL
#endif