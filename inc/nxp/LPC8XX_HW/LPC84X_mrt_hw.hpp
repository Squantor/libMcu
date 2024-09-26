/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Multi Rate Timer register interface
 */
#ifndef LPC84X_MRT_HW_HPP
#define LPC84X_MRT_HW_HPP

namespace libMcuLL::hw::mrt {

/**
 * @brief multi rate timer register definitions
 */
struct peripheral {
  struct {                              /*  */
    volatile std::uint32_t INTVAL;      /**< MRT Time interval value register */
    volatile const std::uint32_t TIMER; /**< MRT Timer register */
    volatile std::uint32_t CTRL;        /**< MRT Control register */
    volatile std::uint32_t STAT;        /**< MRT Status register */
  } CHANNEL[4];                         /**< MRT channel */
  std::uint8_t RESERVED_0[180];         /**< Reserved */
  volatile const std::uint32_t IDLE_CH; /**< Idle channel register */
  volatile std::uint32_t IRQ_FLAG;      /**< Global interrupt flag register */
};
}  // namespace libMcuLL::hw::mrt
#endif