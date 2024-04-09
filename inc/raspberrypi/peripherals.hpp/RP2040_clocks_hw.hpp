/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 Clocks register interface
 */
#ifndef RP2040_CLOCKS_HW_HPP
#define RP2040_CLOCKS_HW_HPP

namespace libMcuLL {
namespace hw {
namespace clocks {
/**
 * @brief clocks register definitions
 *
 */
struct peripheral {
  struct {
    volatile std::uint32_t CTRL;                     /**< Clock control */
    volatile std::uint32_t DIV;                      /**< Clock divisor */
    const volatile std::uint32_t SELECTED;           /**< Indicates which SRC is currently selected */
  } CLK[10];                                         /**< Clock selected */
  volatile std::uint32_t CLK_SYS_RESUS_CTRL;         /**<  */
  const volatile std::uint32_t CLK_SYS_RESUS_STATUS; /**<  */
  volatile std::uint32_t FC0_REF_KHZ;                /**< Reference clock frequency in kHz */
  volatile std::uint32_t FC0_MIN_KHZ;                /**< Minimum pass frequency in kHz. */
  volatile std::uint32_t FC0_MAX_KHZ;                /**< Maximum pass frequency in kHz. */
  volatile std::uint32_t FC0_DELAY;                  /**< Delays the start of frequency counting */
  volatile std::uint32_t FC0_INTERVAL;               /**< The test interval */
  volatile std::uint32_t FC0_SRC;                    /**< Clock sent to frequency counter */
  const volatile std::uint32_t FC0_STATUS;           /**< Frequency counter status */
  const volatile std::uint32_t FC0_RESULT;           /**< Result of frequency measurement, only valid when status_done=1 */
  volatile std::uint32_t WAKE_EN0;                   /**< enable clock in wake mode */
  volatile std::uint32_t WAKE_EN1;                   /**< enable clock in wake mode */
  volatile std::uint32_t SLEEP_EN0;                  /**< enable clock in sleep mode */
  volatile std::uint32_t SLEEP_EN1;                  /**< enable clock in sleep mode */
  const volatile std::uint32_t ENABLED0;             /**< indicates the state of the clock enable */
  const volatile std::uint32_t ENABLED1;             /**< indicates the state of the clock enable */
  const volatile std::uint32_t INTR;                 /**< Raw Interrupts */
  volatile std::uint32_t INTE;                       /**< Interrupt Enable */
  volatile std::uint32_t INTF;                       /**< Interrupt Force */
  const volatile std::uint32_t INTS;                 /**< Interrupt status after masking & forcing */
};
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'0000u}; /**< Mask for allowed bits */
}  // namespace CTRL
}  // namespace clocks
}  // namespace hw
}  // namespace libMcuLL
#endif