/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file nvic register interface
 */
#ifndef NVIC_HW_HPP
#define NVIC_HW_HPP
namespace libMcuHw::nvic {
struct nvic {
  volatile std::uint32_t ISER[1U]; /**< interrupt set enable register */
  std::uint32_t RESERVED0[31U];
  volatile std::uint32_t ICER[1U]; /**< interrupt clear enable register */
  std::uint32_t RESERVED1[31U];
  volatile std::uint32_t ISPR[1U]; /**< interrupt set pending register */
  std::uint32_t RESERVED2[31U];
  volatile std::uint32_t ICPR[1U]; /**< interrupt clear pending register */
  std::uint32_t RESERVED3[31U];
  std::uint32_t RESERVED4[64U];
  volatile std::uint32_t IP[8U]; /**< interrupt priority register */
};
namespace ISER {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFF; /**< register mask for allowed bits */
/**
 * @brief format for SETENA bits
 *
 * @param interrupt interrupt to enable
 * @return formatted ISER register
 */
constexpr inline std::uint32_t SETENA(std::uint32_t interrupt) {
  return 1 << interrupt;
}
}  // namespace ISER
namespace ICER {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFF; /**< register mask for allowed bits */
/**
 * @brief format for CLRENA bits
 *
 * @param interrupt interrupt to disable
 * @return formatted ICER register
 */
constexpr inline std::uint32_t CLRENA(std::uint32_t interrupt) {
  return 1 << interrupt;
}
}  // namespace ICER
namespace ISPR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFF; /**< register mask for allowed bits */
/**
 * @brief format for SETPEND bits
 *
 * @param interrupt interrupt to set to pending status
 * @return formatted ISPR register
 */
constexpr inline std::uint32_t SETPEND(std::uint32_t interrupt) {
  return 1 << interrupt;
}
/**
 * @brief format register value to extract pending bit
 *
 * @param registerValue register value from peripheral
 * @param interrupt interrupt to check pending status
 * @return zero for not pending, non zero for pending
 */
constexpr inline std::uint32_t GETPEND(std::uint32_t registerValue, std::uint32_t interrupt) {
  return registerValue & (1 << interrupt);
}
}  // namespace ISPR
namespace ICPR {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFFFFFF; /**< register mask for allowed bits */
/**
 * @brief format for CLRPEND bits
 *
 * @param interrupt interrupt to clear pending status
 * @return formatted ICPR register
 */
constexpr inline std::uint32_t CLRPEND(std::uint32_t interrupt) {
  return 1 << interrupt;
}
}  // namespace ICPR
namespace IP {
constexpr inline std::uint32_t RESERVED_MASK = 0xC0C0C0C0; /**< register mask for allowed bits */
/**
 * @brief format for IPR
 *
 * @param registerValue original IP register value
 * @param interrupt interrupt to set the priority of
 * @param priority priority level to set
 * @return modified IP register with the correct priority level
 */
constexpr inline std::uint32_t IPR(std::uint32_t registerValue, std::uint32_t interrupt, std::uint32_t priority) {
  std::uint32_t shiftValue = (interrupt & 0x3) * 8;
  return (registerValue & ~(0xFF << shiftValue)) | (priority << (shiftValue + (8 - libMcuHw::nvic::priorityBits)));
}
}  // namespace IP

}  // namespace libMcuHw::nvic

#endif