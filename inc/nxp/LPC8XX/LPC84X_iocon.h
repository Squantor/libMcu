/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series I/O Control registers, defines and functions.
 */
#ifndef LPC84X_IOCON_H
#define LPC84X_IOCON_H

typedef struct {
    __IO uint32_t PIO[56];    /**< Digital I/O control for pins PIO0_17..Digital I/O control for pins PIO1_10, array offset: 0x0, array step: 0x4 */
} IOCON_Type;

#define IOCON_RESERVED_PRESET   (0x00000080u)   /**< Default setting for IOCON register, some reserved bits are set. */
#define IOCON_RESERVED_MASK     (0x0001FF78u)   /**< Masking off reserved pins so they do not accidentaly get set */

/* Iocon pin setting enumerations */
typedef enum {
    IOCON_MODE_INACTIVE = 0,    /**< Pin inactive, no pullup/down resistor enabled */
    IOCON_MODE_PULLDOWN = 1,    /**< Pulldown resistor enabled */
    IOCON_MODE_PULLUP = 2,      /**< Pullup resistor enabled */
    IOCON_MODE_REPEATER = 3,    /**< Repeater mode */
} IOCON_MODE_Type;

#define IOCON_MODE(x)   ((x & 0x03) << 3)   /**< IOCON mode setup */
#define IOCON_HYST_EN   (1 << 5)            /**< Enable hysterhesis */
#define IOCON_INVERT_IN (1 << 6)            /**< Invert input enable */

typedef enum {
    IOCON_I2CMODE_STD = 0,  /**< Standard mode/Fast mode I2C */
    IOCON_I2CMODE_GPIO = 1,  /**< GPIO mode */
    IOCON_I2CMODE_FAST = 2,  /**< Fast-mode Plus I2C */
} IOCON_I2CMODE_Type;

#define IOCON_I2CMODE   ((x & 0x03) << 8)   /**< dedicated I2C pin mode */
#define IOCON_OD        (1 << 10)           /**< Open drain mode */

/* Iocon input filter settings */
typedef enum {
    IOCON_S_MODE_BYPASS = 0,    /**< Bypass input filter */
    IOCON_S_MODE_1CLOCK = 1,    /**< Pulses shorter then 1 clock are rejected */
    IOCON_S_MODE_2CLOCK = 2,    /**< Pulses shorter then 2 clocks are rejected */
    IOCON_S_MODE_3CLOCK = 3,    /**< Pulses shorter then 3 clocks are rejected */
} IOCON_S_MODE_Type;

#define IOCON_S_MODE(x) ((x & 0x03) << 11)

/* Iocon clock select for input filter */
typedef enum {
    IOCONCLKDIV0 = 0,   /**< select IOCONCLKDIV0 */
    IOCONCLKDIV1 = 1,   /**< select IOCONCLKDIV1 */
    IOCONCLKDIV2 = 2,   /**< select IOCONCLKDIV2 */
    IOCONCLKDIV3 = 3,   /**< select IOCONCLKDIV3 */
    IOCONCLKDIV4 = 4,   /**< select IOCONCLKDIV4 */
    IOCONCLKDIV5 = 5,   /**< select IOCONCLKDIV5 */
    IOCONCLKDIV6 = 6,   /**< select IOCONCLKDIV6 */
} IOCON_CLK_DIV_Type;

#define IOCON_CLK_DIV(x) ((x & 0x03) << 13)
#define IOCON_DAC_ENABLE    (1 << 16)

/**
 * @brief   Setup IOCON pin setting in one go
 * @param   peripheral  : base address of IOCON peripheral
 * @param   pin         : IOCON pin index
 * @param   settings    : Settings to apply to IOCON pin
 * @return  Nothing
 */
static inline void ioconSetupPin(IOCON_Type *peripheral, const IOCON_PIN_Type pin, const uint32_t settings)
{
    peripheral->PIO[pin] = (settings & IOCON_RESERVED_MASK) | IOCON_RESERVED_PRESET;
}

#endif
