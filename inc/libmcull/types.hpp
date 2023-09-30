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

/* Peripheral address types used by all microcontrollers */
using I2Ctype = std::uint32_t;   /**< I2C */
using SPItype = std::uint32_t;   /**< SPI */
using USARTtype = std::uint32_t; /**< USART */
using CRCtype = std::uint32_t;   /**< CRC engine */
using GPIOtype = std::uint32_t;  /**< GPIO */

/* Peripheral address types used by NXP LPC microcontrollers */
using WWDTtype = std::uint32_t;   /**< NXP LPC Windowed watchdog */
using MRTtype = std::uint32_t;    /**< NXP LPC Multi rate timer*/
using WKTtype = std::uint32_t;    /**< NXP LPC Wakeup timer */
using SWMtype = std::uint32_t;    /**< NXP LPC Switch Matrix */
using PMUtype = std::uint32_t;    /**< NXP LPC Power management unit */
using ACMPtype = std::uint32_t;   /**< NXP LPC Analog comparator */
using FMCtype = std::uint32_t;    /**< NXP LPC Flash controller */
using IOCONtype = std::uint32_t;  /**< NXP LPC IO control */
using SYSCONtype = std::uint32_t; /**< NXP LPC System control*/
using SCTtype = std::uint32_t;    /**< NXP LPC state configurable timer */
using PININTtype = std::uint32_t; /**< NXP LPC Pin interrupt */

/* Peripheral address types used by STM32 microcontrollers */

/* Peripheral address types used by Raspberry Pi microcontrollers */

}  // namespace libMcuLL

#endif