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

using hwAddressBase = constant<std::uint32_t>;
using hwAddressType = typename hwAddressBase::type;

/* Peripheral address types used by all microcontrollers */
struct I2CbaseAddress : hwAddressBase {};   /**< I2C */
struct SPIbaseAddress : hwAddressBase {};   /**< SPI */
struct USARTbaseAddress : hwAddressBase {}; /**< USART */
struct CRCbaseAddress : hwAddressBase {};   /**< CRC engine */
struct GPIObaseAddress : hwAddressBase {};  /**< GPIO */

/* Peripheral address types used by NXP LPC microcontrollers */
struct WWDTbaseAddress : hwAddressBase {};   /**< NXP LPC Windowed watchdog */
struct MRTbaseAddress : hwAddressBase {};    /**< NXP LPC Multi rate timer*/
struct WKTbaseAddress : hwAddressBase {};    /**< NXP LPC Wakeup timer */
struct SWMbaseAddress : hwAddressBase {};    /**< NXP LPC Switch Matrix */
struct PMUbaseAddress : hwAddressBase {};    /**< NXP LPC Power management unit */
struct ACMPbaseAddress : hwAddressBase {};   /**< NXP LPC Analog comparator */
struct FMCbaseAddress : hwAddressBase {};    /**< NXP LPC Flash controller */
struct IOCONbaseAddress : hwAddressBase {};  /**< NXP LPC IO control */
struct SYSCONbaseAddress : hwAddressBase {}; /**< NXP LPC System control*/
struct SCTbaseAddress : hwAddressBase {};    /**< NXP LPC state configurable timer */
struct PININTbaseAddress : hwAddressBase {}; /**< NXP LPC Pin interrupt */

/* Peripheral address types used by STM32 microcontrollers */

/* Peripheral address types used by Raspberry Pi microcontrollers */

/* I2C general definitions */
using i2cDeviceAddressBase = constant<std::uint8_t>;
using i2cDeviceAddressType = typename i2cDeviceAddressBase::type;

struct i2cDeviceAddress : i2cDeviceAddressBase {}; /**< General purpose I2C address type */

}  // namespace libMcuLL

#endif