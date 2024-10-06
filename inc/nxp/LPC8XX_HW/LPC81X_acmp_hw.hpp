/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series analog comparator register interface
 */
#ifndef LPC81X_ACMP_REGS_HPP
#define LPC81X_ACMP_REGS_HPP
namespace libMcuLL::hw::acmp {

/**
 * @brief analog comparator register definitions
 *
 */
struct acmp {
  volatile std::uint32_t CTRL; /**<  Analog Comparator control register */
  volatile std::uint32_t LAD;  /**<  Voltage ladder register */
};
namespace CTRL {
constexpr inline std::uint32_t RESERVED_MASK{0x06B0'3F58u};     /**< register mask for allowed bits */
constexpr inline std::uint32_t EDGESEL_FALLING{0u << 3};        /**< falling edges trigger COMPEDGE */
constexpr inline std::uint32_t EDGESEL_RISING{1u << 3};         /**< rising edges trigger COMPEDGE */
constexpr inline std::uint32_t EDGESEL_BOTH{2u << 3};           /**< both edges trigger COMPEDGE */
constexpr inline std::uint32_t COMPSA_DIR{0u << 6};             /**< comparator output used directly */
constexpr inline std::uint32_t COMPSA_SYNC{1u << 6};            /**< comparator output synchronized to bus clock */
constexpr inline std::uint32_t COMP_VP_SEL_LAD{0u << 8};        /**< comparator plus connected to voltage ladder */
constexpr inline std::uint32_t COMP_VP_SEL_ACMP_I1{1u << 8};    /**< comparator plus connected to ACMP_I1 */
constexpr inline std::uint32_t COMP_VP_SEL_ACMP_I2{2u << 8};    /**< comparator plus connected to ACMP_I2 */
constexpr inline std::uint32_t COMP_VP_SEL_ACMP_VREF{6u << 8};  /**< comparator plus connected to internal reference */
constexpr inline std::uint32_t COMP_VM_SEL_LAD{0u << 11};       /**< comparator minus connected to voltage ladder */
constexpr inline std::uint32_t COMP_VM_SEL_ACMP_I1{1u << 11};   /**< comparator minus connected to ACMP_I1 */
constexpr inline std::uint32_t COMP_VM_SEL_ACMP_I2{2u << 11};   /**< comparator minus connected to ACMP_I2 */
constexpr inline std::uint32_t COMP_VM_SEL_ACMP_VREF{6u << 11}; /**< comparator minus connected to internal reference */
constexpr inline std::uint32_t EDGECLR{1u << 20};               /**< interrupt clear bit */
constexpr inline std::uint32_t COMPSTAT_MASK{1u << 21};         /**< comparator status mask */
constexpr inline std::uint32_t COMPEDGE_MASK{1u << 23};         /**< comparator edge-detect status */
constexpr inline std::uint32_t HYS_NONE{0u << 25};              /**< no comparator hysteresis */
constexpr inline std::uint32_t HYS_5MV{1u << 25};               /**< 5mV comparator hysteresis */
constexpr inline std::uint32_t HYS_10MV{2u << 25};              /**< 10mV comparator hysteresis */
constexpr inline std::uint32_t HYS_20MV{3u << 25};              /**< 20mV comparator hysteresis */
}  // namespace CTRL
namespace LAD {
constexpr inline std::uint32_t RESERVED_MASK{0x0000003Fu}; /**< register mask for allowed bits */
constexpr inline std::uint32_t LADEN{1u << 0};             /**< Voltage ladder enable */
/**
 * @brief Format Voltage ladder value register
 *
 * @param value tap select of ladder, 0 is VSS and 31 is Vref
 * @return formatted data to be put in LADSEL register
 */
constexpr inline std::uint32_t LADSEL(std::uint32_t value) {
  return value << 1;
}
constexpr inline std::uint32_t LADSEL_MASK{0x1Fu << 1}; /**< register mask for ladders select */
constexpr inline std::uint32_t LADREF_VDD{0u << 6};     /**< reference voltage selects VDD pin */
constexpr inline std::uint32_t LADREF_VDDCMP{1u << 6};  /**< reference voltage selects VDDCMP pin */
}  // namespace LAD
}  // namespace libMcuLL::hw::acmp
#endif