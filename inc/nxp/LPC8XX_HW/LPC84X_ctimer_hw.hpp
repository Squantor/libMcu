/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 standard counter/timer register interface
 */
#ifndef LPC84X_CTIMER_HW_HPP
#define LPC84X_CTIMER_HW_HPP

namespace libMcuHw::ctimer {
/**
 * @brief Ctimer register definitions
 */
struct ctimer {
  volatile std::uint32_t IR;          /**< Interrupt Register */
  volatile std::uint32_t TCR;         /**< Timer Control Register */
  volatile std::uint32_t TC;          /**< Timer Counter */
  volatile std::uint32_t PR;          /**< Prescale Register */
  volatile std::uint32_t PC;          /**< Prescale Counter */
  volatile std::uint32_t MCR;         /**< Match Control Register */
  volatile std::uint32_t MR[4];       /**< Match Register */
  volatile std::uint32_t CCR;         /**< Capture Control Register */
  volatile const std::uint32_t CR[4]; /**< Capture Register */
  volatile std::uint32_t EMR;         /**< External Match Register */
  std::uint8_t RESERVED_0[48];        /**< Reserved */
  volatile std::uint32_t CTCR;        /**< Count Control Register */
  volatile std::uint32_t PWMC;        /**< PWM Control Register */
  volatile std::uint32_t MSR[4];      /**< Match Shadow Register */
};
}  // namespace libMcuHw::ctimer
#endif