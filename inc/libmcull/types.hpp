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
struct I2CbaseAddress : hwAddress {};   /**< I2C */
struct SPIbaseAddress : hwAddress {};   /**< SPI */
struct USARTbaseAddress : hwAddress {}; /**< USART */
struct CRCbaseAddress : hwAddress {};   /**< CRC engine */
struct GPIObaseAddress : hwAddress {};  /**< GPIO */

/* Peripheral address types used by NXP LPC microcontrollers */
struct WWDTbaseAddress : hwAddress {};   /**< NXP LPC Windowed watchdog */
struct MRTbaseAddress : hwAddress {};    /**< NXP LPC Multi rate timer*/
struct WKTbaseAddress : hwAddress {};    /**< NXP LPC Wakeup timer */
struct SWMbaseAddress : hwAddress {};    /**< NXP LPC Switch Matrix */
struct PMUbaseAddress : hwAddress {};    /**< NXP LPC Power management unit */
struct ACMPbaseAddress : hwAddress {};   /**< NXP LPC Analog comparator */
struct FMCbaseAddress : hwAddress {};    /**< NXP LPC Flash controller */
struct IOCONbaseAddress : hwAddress {};  /**< NXP LPC IO control */
struct SYSCONbaseAddress : hwAddress {}; /**< NXP LPC System control*/
struct SCTbaseAddress : hwAddress {};    /**< NXP LPC state configurable timer */
struct PININTbaseAddress : hwAddress {}; /**< NXP LPC Pin interrupt */

/* Peripheral address types used by STM32 microcontrollers */

/* Peripheral address types used by Raspberry Pi microcontrollers */

/* I2C general definitions */
using hwAddress = constant<std::uint32_t>;
using hwAddressType = typename hwAddress::type;

}  // namespace libMcuLL

#endif