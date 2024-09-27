/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 series GPIO register interface
 */
#ifndef LPC84X_GPIO_HW_HPP
#define LPC84X_GPIO_HW_HPP

namespace libMcuHw::gpio {

/**
 * @brief gpio register definitions
 *
 */
struct gpio {
  volatile std::uint8_t B[2][32];   /**< Byte pin registers for all port 0 and 1 GPIO pins */
  std::uint8_t RESERVED_0[4032];    /**< Reserved */
  volatile std::uint32_t W[2][32];  /**< Word pin registers for all port 0 and 1 GPIO pins */
  std::uint8_t RESERVED_1[3840];    /**< Reserved */
  volatile std::uint32_t DIR[2];    /**< Direction registers */
  std::uint8_t RESERVED_2[120];     /**< Reserved */
  volatile std::uint32_t MASK[2];   /**< Mask register */
  std::uint8_t RESERVED_3[120];     /**< Reserved */
  volatile std::uint32_t PIN[2];    /**< Port pin register */
  std::uint8_t RESERVED_4[120];     /**< Reserved */
  volatile std::uint32_t MPIN[2];   /**< Masked port register */
  std::uint8_t RESERVED_5[120];     /**< Reserved */
  volatile std::uint32_t SET[2];    /**< Write: Set register for port Read: output bits for port */
  std::uint8_t RESERVED_6[120];     /**< Reserved */
  volatile std::uint32_t CLR[2];    /**< Clear port */
  std::uint8_t RESERVED_7[120];     /**< Reserved */
  volatile std::uint32_t NOT[2];    /**< Toggle port */
  std::uint8_t RESERVED_8[120];     /**< Reserved */
  volatile std::uint32_t DIRSET[2]; /**< Set pin direction bits for port */
  std::uint8_t RESERVED_9[120];     /**< Reserved */
  volatile std::uint32_t DIRCLR[2]; /**< Clear pin direction bits for port */
  std::uint8_t RESERVED_10[120];    /**< Reserved */
  volatile std::uint32_t DIRNOT[2]; /**< Toggle pin direction bits for port */
};
}  // namespace libMcuHw::gpio
#endif