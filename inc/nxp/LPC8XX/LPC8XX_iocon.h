/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>
*/
/* 
LPC800 series common IOCON functions
*/
#ifndef LPC8XX_IOCON_H
#define LPC8XX_IOCON_H

#include <stdint.h>

#define NUM_IOCON_PIO  (29)

typedef struct {
    uint32_t pin:8;            /* Pin number */
    uint32_t modefunc:24;    /* Function and mode */
} PINMUX_GRP_T;

typedef struct {
    volatile uint32_t PIO0[NUM_IOCON_PIO + 2]; /* 2 added for reserved register */
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

// TODO put this in device package file
typedef enum CHIP_PINx {
    IOCON_PIO0  =  0x11,
    IOCON_PIO1  =  0x0B,
    IOCON_PIO2  =  0x06,
    IOCON_PIO3  =  0x05,
    IOCON_PIO4  =  0x04,
    IOCON_PIO5  =  0x03,
    /* The following pins are not present in DIP8 packages */
    IOCON_PIO6  =  0x10,
    IOCON_PIO7  =  0x0F,
    IOCON_PIO8  =  0x0E,
    IOCON_PIO9  =  0x0D,
    IOCON_PIO10 =  0x08,
    IOCON_PIO11 =  0x07,
    IOCON_PIO12 =  0x02,
    IOCON_PIO13 =  0x01,
    /* The following pins are not present in DIP8 & TSSOP16 packages */
    IOCON_PIO14 =  0x12,
    IOCON_PIO15 =  0x0A,
    IOCON_PIO16 =  0x09,
    IOCON_PIO17 =  0x00,
    IOCON_PIO_NUL0 = 0x0C,    /*!< PIN NULL */

    /* The following pins are not present in DIP8, TSSOP16 & TSSOP20 packages */
    IOCON_PIO18 =  0x1E,
    IOCON_PIO19 =  0x1D,
    IOCON_PIO20 =  0x1C,
    IOCON_PIO21 =  0x1B,
    IOCON_PIO22 =  0x1A,
    IOCON_PIO23 =  0x19,
    IOCON_PIO24 =  0x18,
    IOCON_PIO25 =  0x17,
    IOCON_PIO26 =  0x16,
    IOCON_PIO27 =  0x15,
    IOCON_PIO28 =  0x14,
    IOCON_PIO_NUL1 = 0x13,
} CHIP_PINx_T;

typedef enum CHIP_PIN_MODE {
    PIN_MODE_INACTIVE = 0,
    PIN_MODE_PULLDN = 1,
    PIN_MODE_PULLUP = 2,
    PIN_MODE_REPEATER = 3
} CHIP_PIN_MODE_T;

typedef enum CHIP_PIN_SMODE {
    PIN_SMODE_BYPASS = 0,
    PIN_SMODE_CYC1 = 1,
    PIN_SMODE_CYC2 = 2,
    PIN_SMODE_CYC3 = 3
} CHIP_PIN_SMODE_T;

typedef enum CHIP_PIN_I2CMODE {
    PIN_I2CMODE_STDFAST = 0,
    PIN_I2CMODE_GPIO = 1,
    PIN_I2CMODE_FASTPLUS = 2
} CHIP_PIN_I2CMODE_T;

static inline void IOCON_PinMuxSet(LPC_IOCON_T *pIOCON, uint8_t pin, uint32_t modefunc)
{
    pIOCON->PIO0[pin] = modefunc;
}

static inline void IOCON_SetPinMuxing(LPC_IOCON_T *pIOCON, const PINMUX_GRP_T* pinArray, uint32_t arrayLength)
{
    uint32_t ix;

    for (ix = 0; ix < arrayLength; ix++ ) {
         IOCON_PinMuxSet(pIOCON, pinArray[ix].pin, pinArray[ix].modefunc);
    }
}

static inline void IOCON_PinSetMode(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin, CHIP_PIN_MODE_T mode)
{
    uint32_t reg;
    reg = pIOCON->PIO0[pin] & ~(PIN_MODE_MASK);
    pIOCON->PIO0[pin] = reg | (mode << PIN_MODE_BITNUM);
}

static inline void IOCON_PinEnableHysteresis(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin)
{
    pIOCON->PIO0[pin] |= PIN_HYS_MASK;
}

static inline void IOCON_PinDisableHysteresis(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin)
{
    pIOCON->PIO0[pin] &= ~PIN_HYS_MASK;
}

static inline void IOCON_PinSetHysteresis(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin, bool enable)
{
    if(enable == true)
    {
        IOCON_PinEnableHysteresis(pIOCON, pin);
    }
    else 
    {
        IOCON_PinDisableHysteresis(pIOCON, pin);
    }
}

static inline void IOCON_PinEnableInputInverted(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin)
{
    pIOCON->PIO0[pin] |= PIN_INV_MASK;
}

static inline void IOCON_PinDisableInputInverted(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin)
{
    pIOCON->PIO0[pin] &= ~PIN_INV_MASK;
}

static inline void IOCON_PinSetInputInverted(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin, bool invert)
{
    if(invert == true) 
    {
        IOCON_PinEnableInputInverted(pIOCON, pin);
    }
    else 
    {
        IOCON_PinDisableInputInverted(pIOCON, pin);
    }
}

static inline void IOCON_PinEnableOpenDrainMode(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin)
{
    pIOCON->PIO0[pin] |= PIN_OD_MASK;
}

static inline void IOCON_PinDisableOpenDrainMode(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin)
{
    pIOCON->PIO0[pin] &= ~PIN_OD_MASK;
}

static inline void IOCON_PinSetOpenDrainMode(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin, bool open_drain)
{
    if(open_drain == true)
    {
        IOCON_PinEnableOpenDrainMode(pIOCON, pin);
    }
    else 
    {
        IOCON_PinDisableOpenDrainMode(pIOCON, pin);
    }
}

static inline void IOCON_PinSetSampleMode(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin, CHIP_PIN_SMODE_T smode)
{
    uint32_t reg;
    reg = pIOCON->PIO0[pin] & ~(PIN_SMODE_MASK);
    pIOCON->PIO0[pin] = reg | (smode << PIN_SMODE_BITNUM);
}

static inline void IOCON_PinSetClockDivisor(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin, CHIP_PIN_CLKDIV_T clkdiv)
{
    uint32_t reg;
    reg = pIOCON->PIO0[pin] & ~(PIN_CLKDIV_MASK);
    pIOCON->PIO0[pin] = reg | (clkdiv << PIN_CLKDIV_BITNUM);
}

static inline void IOCON_PinSetI2CMode(LPC_IOCON_T *pIOCON, CHIP_PINx_T pin, CHIP_PIN_I2CMODE_T mode)
{
    uint32_t reg;
    reg = pIOCON->PIO0[pin] & ~(PIN_I2CMODE_MASK);
    pIOCON->PIO0[pin] = reg | (mode << PIN_I2CMODE_BITNUM);
}

#endif