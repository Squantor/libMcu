/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Capacitive Touch register interface
 */
#ifndef LPC84X_CAPT_HW_HPP
#define LPC84X_CAPT_HW_HPP

namespace libMcuHw::capt {
/**
 * @brief CAPT register definitions
 */
struct capt {
  volatile std::uint32_t CTRL;          /**< Configuration and control */
  volatile std::uint32_t STATUS;        /**< Status from triggers and time-outs */
  volatile std::uint32_t POLL_TCNT;     /**< Polling counter and measurement counter rules */
  std::uint8_t RESERVED_0[4];           /**< Reserved */
  volatile std::uint32_t INTENSET;      /**< Interrupt enable */
  volatile std::uint32_t INTENCLR;      /**< Interrupt enable clear */
  volatile const std::uint32_t INTSTAT; /**< Interrupt status */
  std::uint8_t RESERVED_1[4];           /**< Reserved */
  volatile const std::uint32_t TOUCH;   /**< Last touch event */
  std::uint8_t RESERVED_2[4056];        /**< Reserved */
  volatile const std::uint32_t ID;      /**< Block ID */
};
}  // namespace libMcuHw::capt
#endif