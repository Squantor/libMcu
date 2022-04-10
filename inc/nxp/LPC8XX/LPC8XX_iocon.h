/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC800 series common IOCON registers, defines and functions.
*/
#ifndef LPC8XX_IOCON_H
#define LPC8XX_IOCON_H

// typedef volatile struct { uint32_t PIO[31]; } IOCON_Type;

#define IOCON_RESERVED_PRESET                                                 \
  (0x00000080u) /**< Reserved settings for IOCON register, some reserved bits \
                   are set. */
typedef enum {
  IOCON_MODE_INACTIVE = 0, /**< Pin inactive, no pullup/down resistor enabled */
  IOCON_MODE_PULLDOWN = 1, /**< Pulldown resistor enabled */
  IOCON_MODE_PULLUP = 2,   /**< Pullup resistor enabled */
  IOCON_MODE_REPEATER = 3, /**< Repeater mode */
} IOCON_MODE_Type;
#define IOCON_MODE(value) ((value & 3) << 2) /**< function mode select*/

#define IOCON_HYST(value) ((value & 1) << 5)   /**< Enable hysterhesis */
#define IOCON_INVERT(value) ((value & 1) << 6) /**< Invert input enable */

typedef enum {
  IOCON_I2CMODE_STD = 0,  /**< Standard mode/Fast mode I2C */
  IOCON_I2CMODE_GPIO = 1, /**< GPIO mode */
  IOCON_I2CMODE_FAST = 2, /**< Fast-mode Plus I2C */
} IOCON_I2CMODE_Type;

#define IOCON_I2CMODE(value) ((value & 0x03) << 8) /**< dedicated I2C pin mode */

#define IOCON_OD(value) ((value & 1) << 10) /**< Open drain mode */

/* Iocon input filter settings */
typedef enum {
  IOCON_S_MODE_BYPASS = 0, /**< Bypass input filter */
  IOCON_S_MODE_1CLOCK = 1, /**< Pulses shorter then 1 clock are rejected */
  IOCON_S_MODE_2CLOCK = 2, /**< Pulses shorter then 2 clocks are rejected */
  IOCON_S_MODE_3CLOCK = 3, /**< Pulses shorter then 3 clocks are rejected */
} IOCON_S_MODE_Type;

#define IOCON_S_MODE(value) ((value & 0x03) << 11) /**< Digital filter sample mode */

/* Select peripheral clock divider for input filter sampling clock. */
typedef enum {
  IOCON_CLK_DIV_0 = 0, /**< Clock division of zero */
  IOCON_CLK_DIV_1 = 1, /**< Clock division of zero */
  IOCON_CLK_DIV_2 = 2, /**< Clock division of zero */
  IOCON_CLK_DIV_3 = 3, /**< Clock division of zero */
  IOCON_CLK_DIV_4 = 4, /**< Clock division of zero */
  IOCON_CLK_DIV_5 = 5, /**< Clock division of zero */
  IOCON_CLK_DIV_6 = 6, /**< Clock division of zero */
} IOCON_CLK_DIV_Type;

#define IOCON_CLK_DIV(value) ((value & 0x03) << 13) /**< Clock divider select for input filter */

/**
 * @brief   Setup IOCON pin setting in one go
 * @param   peripheral  : base address of IOCON peripheral
 * @param   pin         : IOCON pin index
 * @param   settings    : Settings to apply to IOCON pin
 * @return  Nothing
 */
static inline void ioconSetupPin(IOCON_Type *peripheral, const IOCON_PIN_Type pin, const uint32_t settings) {
  peripheral->PIO[pin] = (settings & IOCON_RESERVED_MASK) | IOCON_RESERVED_PRESET;
}

#endif