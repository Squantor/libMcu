/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Analog to Digital converter register interface
 */
#ifndef LPC84X_ADC_HW_HPP
#define LPC84X_ADC_HW_HPP

namespace libMcu::hw::adc {
/**
 * @brief Analog to Digital converter register definitions
 */
struct peripheral {
  volatile std::uint32_t CTRL;              /**< ADC Control register */
  std::uint8_t RESERVED_0[4];               /**< Reserved */
  volatile std::uint32_t SEQ_CTRL[2];       /**< ADC Conversion Sequence-n control register */
  volatile const std::uint32_t SEQ_GDAT[2]; /**< ADC Sequence-n Global Data register */
  std::uint8_t RESERVED_1[8];               /**< Reserved */
  volatile const std::uint32_t DAT[12];     /**< ADC Channel N Data register */
  volatile std::uint32_t THR0_LOW;          /**< ADC Low Compare Threshold register 0 */
  volatile std::uint32_t THR1_LOW;          /**< ADC Low Compare Threshold register 1 */
  volatile std::uint32_t THR0_HIGH;         /**< ADC High Compare Threshold register 0 */
  volatile std::uint32_t THR1_HIGH;         /**< ADC High Compare Threshold register 1 */
  volatile std::uint32_t CHAN_THRSEL;       /**< ADC Channel-Threshold Select register */
  volatile std::uint32_t INTEN;             /**< ADC Interrupt Enable register */
  volatile std::uint32_t FLAGS;             /**< ADC Flags register */
  volatile std::uint32_t TRM;               /**< ADC Startup register */
};
}  // namespace libMcu::hw::adc
#endif