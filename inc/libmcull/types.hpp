/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file types used by libMcuLL
 */
#ifndef TYPES_HPP
#define TYPES_HPP

namespace libMcuLL {

/**
 * @brief defines a constant for typesafety
 *
 * @tparam C_ type of constant
 */
template <typename C_>
struct constant {
  using type = C_;

  constexpr operator C_() const {
    return value;
  }

  C_ value;
};

using hwAddress = constant<std::uint32_t>;
using hwAddressType = typename hwAddress::type;

/* Peripheral address types used by all microcontrollers */
struct I2Caddress : hwAddress {};   /**< I2C */
struct SPIaddress : hwAddress {};   /**< SPI */
struct USARTaddress : hwAddress {}; /**< USART */
struct CRCaddress : hwAddress {};   /**< CRC engine */
struct GPIOaddress : hwAddress {};  /**< GPIO */

/* Peripheral address types used by NXP LPC microcontrollers */
struct WWDTaddress : hwAddress {};   /**< NXP LPC Windowed watchdog */
struct MRTaddress : hwAddress {};    /**< NXP LPC Multi rate timer*/
struct WKTaddress : hwAddress {};    /**< NXP LPC Wakeup timer */
struct SWMaddress : hwAddress {};    /**< NXP LPC Switch Matrix */
struct PMUaddress : hwAddress {};    /**< NXP LPC Power management unit */
struct ACMPaddress : hwAddress {};   /**< NXP LPC Analog comparator */
struct FMCaddress : hwAddress {};    /**< NXP LPC Flash controller */
struct IOCONaddress : hwAddress {};  /**< NXP LPC IO control */
struct SYSCONaddress : hwAddress {}; /**< NXP LPC System control*/
struct SCTaddress : hwAddress {};    /**< NXP LPC state configurable timer */
struct PININTaddress : hwAddress {}; /**< NXP LPC Pin interrupt */

/* Peripheral address types used by STM32 microcontrollers */

/* Peripheral address types used by Raspberry Pi microcontrollers */

}  // namespace libMcuLL

#endif