/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series GPIO register interface
 */
#ifndef LPC81X_GPIO_REGS_HPP
#define LPC81X_GPIO_REGS_HPP

namespace registers {
namespace gpio {

/**
 * @brief gpio register definitions
 *
 */
struct registers {
  volatile uint8_t B[128][32]; /**< Byte pin registers ports 0 to n; pins PIOn_0 to PIOn_31 */
  volatile uint32_t W[32][32]; /**< Word pin registers port 0 to n */
  volatile uint32_t DIR[32];   /**< Direction registers port n */
  volatile uint32_t MASK[32];  /**< Mask register port n */
  volatile uint32_t PIN[32];   /**< Portpin register port n */
  volatile uint32_t MPIN[32];  /**< Masked port register port n */
  volatile uint32_t SET[32];   /**< Write: Set register for port n Read: output bits for port n */
  volatile uint32_t CLR[32];   /**< Clear port n */
  volatile uint32_t NOT[32];   /**< Toggle port n */
};

}  // namespace gpio
}  // namespace registers

#endif