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

namespace libMcuLL::hw::clocks {
/**
 * @brief Clock indexes available of CLK
 *
 */
enum clockIndex : std::uint32_t {
  GPOUT0 = 0,
  GPOUT1,
  GPOUT2,
  GPOUT3,
  REF,
  SYS,
  PERI,
  USB,
  ADC,
  RTC,
};
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
constexpr inline std::uint32_t RESERVED_MASK{0x0013'1DE0u}; /**< Mask for allowed bits */
constexpr inline std::uint32_t NUDGE{1u << 20};             /**< Shift output phase by 1 cycle */
/**
 * @brief Format PHASE field to CTRL register
 * @param phase amount of input clock cycles before enable
 * @return PHASE field formatted to CTRL register
 */
constexpr inline std::uint32_t PHASE(std::uint32_t phase) {
  return phase << 16;
}
constexpr inline std::uint32_t DC50{1u << 12};              /**< Enable duty cycle correction for odd divisors */
constexpr inline std::uint32_t ENABLE{1u << 11};            /**< Starts and stops clock generator cleanly */
constexpr inline std::uint32_t KILL{1u << 10};              /**< kills the clock generator */
constexpr inline std::uint32_t AUXSRC_MASK{0xFu << 5};      /**< Clock source mask */
constexpr inline std::uint32_t GPOUT_SRC_PLL_SYS{0u << 5};  /**< GPOUT source is system PLL */
constexpr inline std::uint32_t GPOUT_SRC_GPIN0{1u << 5};    /**< GPOUT source is clock input 0 */
constexpr inline std::uint32_t GPOUT_SRC_GPIN1{2u << 5};    /**< GPOUT source is clock input 1 */
constexpr inline std::uint32_t GPOUT_SRC_PLL_USB{3u << 5};  /**< GPOUT source is USB PLL */
constexpr inline std::uint32_t GPOUT_SRC_ROSC{4u << 5};     /**< GPOUT source is ROSC */
constexpr inline std::uint32_t GPOUT_SRC_XOSC{5u << 5};     /**< GPOUT source is XOSC */
constexpr inline std::uint32_t GPOUT_SRC_CLK_SYS{6u << 5};  /**< GPOUT source is system clock */
constexpr inline std::uint32_t GPOUT_SRC_CLK_USB{7u << 5};  /**< GPOUT source is USB clock */
constexpr inline std::uint32_t GPOUT_SRC_CLK_ADC{8u << 5};  /**< GPOUT source is ADC clock */
constexpr inline std::uint32_t GPOUT_SRC_CLK_RTC{9u << 5};  /**< GPOUT source is RTC clock */
constexpr inline std::uint32_t GPOUT_SRC_CLK_REF{10u << 5}; /**< GPOUT source is reference clock */
}  // namespace CTRL
namespace DIV {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
/**
 * @brief Format INT field to DIV register
 * @param divisor integer component of DIV register
 * @return INT field formatted to DIV register
 */
constexpr inline std::uint32_t INT(std::uint32_t divisor) {
  return divisor << 8;
}
/**
 * @brief Format FRAC field to DIV register
 * @param fractional fractional component of DIV register
 * @return FRAC field formatted to DIV register
 */
constexpr inline std::uint32_t FRAC(std::uint32_t fractional) {
  return fractional << 0;
}
}  // namespace DIV
namespace SELECTED {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace SELECTED
namespace CLK_SYS_RESUS_CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x0001'11FFu}; /**< Mask for allowed bits */
constexpr inline std::uint32_t CLEAR{1u << 16};             /**< Clear resus after fault correction */
constexpr inline std::uint32_t FRCE{1u << 12};              /**< Force a resus */
constexpr inline std::uint32_t ENABLE{1u << 8};             /**< Enable resus */
/**
 * @brief Format TIMEOUT field to CLK_SYS_RESUS_CTRL register
 * @param timeout timeout of resus expressed as ref cycles
 * @return TIMEOUT field formatted to CLK_SYS_RESUS_CTRL register
 */
constexpr inline std::uint32_t TIMEOUT(std::uint32_t timeout) {
  return timeout << 0;
}
}  // namespace CLK_SYS_RESUS_CTRL
namespace CLK_SYS_RESUS_STATUS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace CLK_SYS_RESUS_STATUS
namespace FC0_REF_KHZ {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace FC0_REF_KHZ
namespace FC0_MIN_KHZ {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace FC0_MIN_KHZ
namespace FC0_MAX_KHZ {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace FC0_MAX_KHZ
namespace FC0_DELAY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace FC0_DELAY
namespace FC0_INTERVAL {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace FC0_INTERVAL
namespace FC0_SRC {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace FC0_SRC
namespace FC0_STATUS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace FC0_STATUS
namespace FC0_RESULT {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace FC0_RESULT
namespace WAKE_EN0 {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace WAKE_EN0
namespace WAKE_EN1 {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace WAKE_EN1
namespace SLEEP_EN0 {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace SLEEP_EN0
namespace SLEEP_EN1 {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace SLEEP_EN1
namespace ENABLED0 {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace ENABLED0
namespace ENABLED1 {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace ENABLED1
namespace INTR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace INTR
namespace INTE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace INTE
namespace INTF {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace INTF
namespace INTS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace INTS
}  // namespace libMcuLL::hw::clocks
#endif