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

namespace libMcuLL::hw::sysinfo {
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
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu};    /**< Mask for allowed bits */
constexpr inline std::uint32_t REVISION_MASK{0xFu << 28};      /**< Revison */
constexpr inline std::uint32_t PART_MASK{0xFFFFu << 12};       /**< Part number */
constexpr inline std::uint32_t MANUFACTURER_MASK{0xFFFu << 0}; /**< Manufacturer ID */
}  // namespace CHIP_ID
namespace PLATFORM {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0003u}; /**< mask for allowed bits */
constexpr inline std::uint32_t ASIC_MASK{1u << 1};          /**< Running on ASIC environment */
constexpr inline std::uint32_t FPGA_MASK{1u << 0};          /**< Running on FPGA environment */
}  // namespace PLATFORM
namespace GITREF_RP2040 {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< mask for allowed bits */
}  // namespace GITREF_RP2040
}  // namespace libMcuLL::hw::sysinfo
#endif