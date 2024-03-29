/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series GPIO register interface
 */
#ifndef LPC84X_GPIO_REGS_HPP
#define LPC84X_GPIO_REGS_HPP
namespace libMcuLL {
namespace hw {
namespace gpio {

/**
 * @brief gpio register definitions
 *
 */
struct peripheral {
  volatile std::uint8_t B[128][32]; /**< Byte pin registers ports 0 to n; pins PIOn_0 to PIOn_31 */
  volatile std::uint32_t W[32][32]; /**< Word pin registers port 0 to n */
  volatile std::uint32_t DIR[32];   /**< Direction registers port n */
  volatile std::uint32_t MASK[32];  /**< Mask register port n */
  volatile std::uint32_t PIN[32];   /**< Portpin register port n */
  volatile std::uint32_t MPIN[32];  /**< Masked port register port n */
  volatile std::uint32_t SET[32];   /**< Write: Set register for port n Read: output bits for port n */
  volatile std::uint32_t CLR[32];   /**< Clear port n */
  volatile std::uint32_t NOT[32];   /**< Toggle port n */
};

}  // namespace gpio
}  // namespace hw
}  // namespace libMcuLL

#endif