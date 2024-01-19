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
namespace libMcuLL {
namespace hw {
namespace acmp {

/**
 * @brief analog comparator register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t CTRL; /**<  Analog Comparator control register */
  volatile std::uint32_t LAD;  /**<  Voltage ladder register */
};
namespace CTRL {
constexpr inline std::uint32_t MASK = 0x06B03F58;                 /**< register mask for allowed bits */
constexpr inline std::uint32_t EDGESEL_FALLING = (0 << 3);        /**< falling edges trigger COMPEDGE */
constexpr inline std::uint32_t EDGESEL_RISING = (1 << 3);         /**< rising edges trigger COMPEDGE */
constexpr inline std::uint32_t EDGESEL_BOTH = (2 << 3);           /**< both edges trigger COMPEDGE */
constexpr inline std::uint32_t COMPSA_DIR = (0 << 6);             /**< comparator output used directly */
constexpr inline std::uint32_t COMPSA_SYNC = (1 << 6);            /**< comparator output synchronized to bus clock */
constexpr inline std::uint32_t COMP_VP_SEL_LAD = (0 << 8);        /**< comparator plus connected to voltage ladder */
constexpr inline std::uint32_t COMP_VP_SEL_ACMP_I1 = (1 << 8);    /**< comparator plus connected to ACMP_I1 */
constexpr inline std::uint32_t COMP_VP_SEL_ACMP_I2 = (2 << 8);    /**< comparator plus connected to ACMP_I2 */
constexpr inline std::uint32_t COMP_VP_SEL_ACMP_VREF = (6 << 8);  /**< comparator plus connected to internal reference */
constexpr inline std::uint32_t COMP_VM_SEL_LAD = (0 << 11);       /**< comparator minus connected to voltage ladder */
constexpr inline std::uint32_t COMP_VM_SEL_ACMP_I1 = (1 << 11);   /**< comparator minus connected to ACMP_I1 */
constexpr inline std::uint32_t COMP_VM_SEL_ACMP_I2 = (2 << 11);   /**< comparator minus connected to ACMP_I2 */
constexpr inline std::uint32_t COMP_VM_SEL_ACMP_VREF = (6 << 11); /**< comparator minus connected to internal reference */
constexpr inline std::uint32_t EDGECLR = (1 << 20);               /**< interrupt clear bit */
constexpr inline std::uint32_t COMPSTAT_MASK = (1 << 21);         /**< comparator status mask */
constexpr inline std::uint32_t COMPEDGE = (1 << 23);              /**< comparator edge-detect status */
constexpr inline std::uint32_t HYS_NONE = (0 << 25);              /**< no comparator hysteresis */
constexpr inline std::uint32_t HYS_5MV = (1 << 25);               /**< 5mV comparator hysteresis */
constexpr inline std::uint32_t HYS_10MV = (2 << 25);              /**< 10mV comparator hysteresis */
constexpr inline std::uint32_t HYS_20MV = (3 << 25);              /**< 20mV comparator hysteresis */
}  // namespace CTRL
namespace LAD {
constexpr inline std::uint32_t MASK = 0x0000003F; /**< register mask for allowed bits */
constexpr inline std::uint32_t LADEN = (1 << 0);  /**< Voltage ladder enable */
/**
 * @brief Format Voltage ladder value register
 *
 * @param value tap select of ladder, 0 is VSS and 31 is Vref
 * @return formatted data to be put in LADSEL register
 */
constexpr inline std::uint32_t LADSEL(std::uint_fast8_t value) {
  return static_cast<std::uint32_t>(value) << 1;
}
constexpr inline std::uint32_t LADREF_VDD = (0 << 6);    /**< reference voltage selects VDD pin */
constexpr inline std::uint32_t LADREF_VDDCMP = (1 << 6); /**< reference voltage selects VDDCMP pin */
}  // namespace LAD
}  // namespace acmp
}  // namespace hw
}  // namespace libMcuLL

#endif