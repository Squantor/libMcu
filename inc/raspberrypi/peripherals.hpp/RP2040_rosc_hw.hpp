/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 ROSC register interface
 */
#ifndef RP2040_ROSC_HW_HPP
#define RP2040_ROSC_HW_HPP

namespace libMcuLL {
namespace hw {
namespace rosc {
/**
 * @brief ROSC register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t CTRL;      /**< Control */
  volatile std::uint32_t FREQA;     /**< Freqency control A */
  volatile std::uint32_t FREQB;     /**< Frequency control B */
  volatile std::uint32_t DORMANT;   /**< Pause control */
  volatile std::uint32_t DIV;       /**< Output divider */
  volatile std::uint32_t PHASE;     /**< Phase shift output control */
  volatile std::uint32_t STATUS;    /**< Status */
  volatile std::uint32_t RANDOMBIT; /**< random 1 bit value */
  volatile std::uint32_t COUNT;     /**< Down counter */
};
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK = 0x00FF'FFFF; /**< mask for allowed bits */
constexpr inline std::uint32_t ENABLE = 0xD1E << 12;        /**< Magic value to enable */
constexpr inline std::uint32_t DISABLE = 0xFAB << 12;       /**< Magic value to disable */
constexpr inline std::uint32_t FREQ_LOW = 0xFA4 << 0;       /**< Low oscillator range */
constexpr inline std::uint32_t FREQ_MED = 0xFA5 << 0;       /**< Medium oscillator range */
constexpr inline std::uint32_t FREQ_HIGH = 0xFA7 << 0;      /**< High oscillator range */
constexpr inline std::uint32_t FREQ_TOO_HIGH = 0xFA6 << 0;  /**< Too high oscillator range */
}  // namespace CTRL
namespace FREQA {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFF'7777; /**< mask for allowed bits */
constexpr inline std::uint32_t PASSWD = 0x9696 << 16;       /**< Password to apply settings */
/**
 * @brief Format stage 3 drive strength
 * @param strength strength value varying from 0 to 3
 * @return stage 3 strength value formatted to FREQA register
 */
constexpr inline std::uint32_t DS3(std::uint32_t strength) {
  return strength << 12;
}
/**
 * @brief Format stage 2 drive strength
 * @param strength strength value varying from 0 to 3
 * @return stage 2 strength value formatted to FREQA register
 */
constexpr inline std::uint32_t DS2(std::uint32_t strength) {
  return strength << 8;
}
/**
 * @brief Format stage 1 drive strength
 * @param strength strength value varying from 0 to 3
 * @return stage 1 strength value formatted to FREQA register
 */
constexpr inline std::uint32_t DS1(std::uint32_t strength) {
  return strength << 4;
}
/**
 * @brief Format stage 0 drive strength
 * @param strength strength value varying from 0 to 3
 * @return stage 0 strength value formatted to FREQA register
 */
constexpr inline std::uint32_t DS0(std::uint32_t strength) {
  return strength << 0;
}
}  // namespace FREQA
namespace FREQB {
constexpr inline std::uint32_t RESERVED_MASK = 0xFFFF'7777; /**< mask for allowed bits */
constexpr inline std::uint32_t PASSWD = 0x9696 << 16;       /**< Password to apply settings */
/**
 * @brief Format stage 7 drive strength
 * @param strength strength value varying from 0 to 3
 * @return stage 7 strength value formatted to FREQB register
 */
constexpr inline std::uint32_t DS7(std::uint32_t strength) {
  return strength << 12;
}
/**
 * @brief Format stage 6 drive strength
 * @param strength strength value varying from 0 to 3
 * @return stage 6 strength value formatted to FREQB register
 */
constexpr inline std::uint32_t DS6(std::uint32_t strength) {
  return strength << 8;
}
/**
 * @brief Format stage 5 drive strength
 * @param strength strength value varying from 0 to 3
 * @return stage 5 strength value formatted to FREQB register
 */
constexpr inline std::uint32_t DS5(std::uint32_t strength) {
  return strength << 4;
}
/**
 * @brief Format stage 4 drive strength
 * @param strength strength value varying from 0 to 3
 * @return stage 4 strength value formatted to FREQB register
 */
constexpr inline std::uint32_t DS4(std::uint32_t strength) {
  return strength << 0;
}
}  // namespace FREQB
namespace DORMANT {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000'0000; /**< Mask for allowed bits */
constexpr inline std::uint32_t DORMANT = 0x636F6D61;        /**< Set oscillator to dormant */
constexpr inline std::uint32_t WAKE = 0x77616B65;           /**< Set oscillator to wake */
}  // namespace DORMANT
namespace DIV {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000'0FFF; /**< Mask for allowed bits */
constexpr inline std::uint32_t PASS = 0xAA0;                /**< Password for updating the divisor */
/**
 * @brief Format divisor field to DIV register
 * @param divisor output divider value from 1 to 31
 * @return divisor value formatted to DIV register
 */
constexpr inline std::uint32_t DIV(std::uint32_t divisor) {
  return divisor << 0;
}
}  // namespace DIV
namespace PHASE {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000'0FFF; /**< Mask for allowed bits */
constexpr inline std::uint32_t PASS = 0xAA0;                /**< Password for updating the divisor */
constexpr inline std::uint32_t ENABLE = 1 << 3;             /**< Enable phase shifted output */
constexpr inline std::uint32_t FLIP = 1 << 2;               /**< Invert phase shifted output */
/**
 * @brief Format phase shift field to PHASE register
 * @param stages amount of phase shift from 0 to 3
 * @return phase shift value formatted to PHASE register
 */
constexpr inline std::uint32_t SHIFT(std::uint32_t stages) {
  return stages << 0;
}
}  // namespace PHASE
namespace STATUS {
constexpr inline std::uint32_t RESERVED_MASK = 0x8101'1000; /**< Mask for allowed bits */
constexpr inline std::uint32_t STABLE_MASK = 1 << 31;       /**< Oscillator running and stable */
constexpr inline std::uint32_t BADWRITE_MASK = 1 << 24;     /**< Bad write performed */
constexpr inline std::uint32_t DIV_RUNNING_MASK = 1 << 16;  /**< Post divider running */
constexpr inline std::uint32_t ENABLED_MASK = 1 << 12;      /**< Oscillator enabled */
}  // namespace STATUS
namespace RANDOMBIT {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000'0001; /**< Mask for allowed bits */
constexpr inline std::uint32_t RANDOM_MASK = 1 << 0;        /**< Output state of oscillator, random bit*/
}  // namespace RANDOMBIT
namespace COUNT {
constexpr inline std::uint32_t RESERVED_MASK = 0x0000'0000; /**< Mask for allowed bits */
constexpr inline std::uint32_t COUNT_MASK = 0xFF << 0;      /**< Down counter mask */
}  // namespace COUNT
}  // namespace rosc
}  // namespace hw
}  // namespace libMcuLL
#endif