/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file SCB register interface
 */
#ifndef SCB_HW_HPP
#define SCB_HW_HPP
namespace libMcuLL {
namespace hw {
namespace scb {
struct peripheral {
  const volatile std::uint32_t CPUID; /**< CPUID Base Register */
  volatile std::uint32_t ICSR;        /**< Interrupt Control and State Register */
  volatile std::uint32_t VTOR;        /**< Vector Table Offset Register */
  volatile std::uint32_t AIRCR;       /**< Application Interrupt and Reset Control Register */
  volatile std::uint32_t SCR;         /**< System Control Register */
  volatile std::uint32_t CCR;         /**< Configuration Control Register */
  std::uint32_t RESERVED1;
  volatile std::uint32_t SHP[2U]; /**< System Handlers Priority Registers. [0] is RESERVED */
  volatile std::uint32_t SHCSR;   /**< System Handler Control and State Register */
};
namespace CPUID {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFF; /**< register mask for allowed bits */
}
namespace ICSR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFF1FF; /**< register mask for allowed bits */
}
namespace VTOR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFF80; /**< register mask for allowed bits */
}
namespace AIRCR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFF8006; /**< register mask for allowed bits */
}
namespace SCR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000016; /**< register mask for allowed bits */
}
namespace CCR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00000208; /**< register mask for allowed bits */
}
namespace SHP {
constexpr inline std::uint32_t RESERVED_MASK = 0xC0C0C0C0; /**< register mask for allowed bits */
}
namespace SHCSR {
constexpr inline std::uint32_t RESERVED_MASK = 0x00008000; /**< register mask for allowed bits */
}
}  // namespace scb
}  // namespace hw
}  // namespace libMcuLL
