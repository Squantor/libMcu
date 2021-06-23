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

#define NUM_IOCON_PIO  (29)

typedef struct {
    uint32_t pin:8;            /* Pin number */
    uint32_t modefunc:24;    /* Function and mode */
} PINMUX_GRP_T;

typedef volatile struct {
    uint32_t PIO0[NUM_IOCON_PIO + 2]; /* 2 added for reserved register */
} LPC_IOCON_T;

/**
 * @brief IOCON Register bit definitions
 */
/* Pin Mode mask */
#define PIN_MODE_MASK           (0x3 <<  3)
#define PIN_MODE_BITNUM         (3)

/* Pin Hysteresis mask */
#define PIN_HYS_MASK            (0x1 <<  5)
#define PIN_HYS_BITNUM          (5)

/* Pin invert input mask */
#define PIN_INV_MASK            (0x1 <<  6)
#define PIN_INV_BITNUM          (6)

/* Pin open drain mode mask */
#define PIN_OD_MASK             (0x1 << 10)
#define PIN_OD_BITNUM           (10)

/* Pin digital filter sample mode mask */
#define PIN_SMODE_MASK          (0x3 << 11)
#define PIN_SMODE_BITNUM        (11)

/* Pin clock divider mask */
#define PIN_CLKDIV_MASK         (0x7 << 13)
#define PIN_CLKDIV_BITNUM       (13)

/* Pin I2C mode mask - valid for PIO10 & PIO11 only */
#define PIN_I2CMODE_MASK        (0x3 <<  8)
#define PIN_I2CMODE_BITNUM      (8)

typedef enum PIN_MODE {
    PIN_MODE_INACTIVE = 0,
    PIN_MODE_PULLDN = 1,
    PIN_MODE_PULLUP = 2,
    PIN_MODE_REPEATER = 3
} PIN_MODE_T;

typedef enum PIN_SMODE {
    PIN_SMODE_BYPASS = 0,
    PIN_SMODE_CYC1 = 1,
    PIN_SMODE_CYC2 = 2,
    PIN_SMODE_CYC3 = 3
} PIN_SMODE_T;

typedef enum PIN_I2CMODE {
    PIN_I2CMODE_STDFAST = 0,
    PIN_I2CMODE_GPIO = 1,
    PIN_I2CMODE_FASTPLUS = 2
} PIN_I2CMODE_T;

#endif