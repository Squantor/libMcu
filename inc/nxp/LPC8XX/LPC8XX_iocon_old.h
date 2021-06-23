/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC800 series common IOCON registers, defines and functions.
*/
#ifndef LPC8XX_IOCON_OLD_H
#define LPC8XX_IOCON_OLD_H

static inline void IoconPinMuxSet(LPC_IOCON_T *pIOCON, uint8_t pin, uint32_t modefunc)
{
    pIOCON->PIO0[pin] = modefunc;
}

static inline void IoconSetPinMuxing(LPC_IOCON_T *pIOCON, const PINMUX_GRP_T* pinArray, uint32_t arrayLength)
{
    uint32_t ix;

    for (ix = 0; ix < arrayLength; ix++ ) {
         IoconPinMuxSet(pIOCON, pinArray[ix].pin, pinArray[ix].modefunc);
    }
}

static inline void IoconPinSetMode(LPC_IOCON_T *pIOCON, PINx_T pin, PIN_MODE_T mode)
{
    uint32_t pio0Register;
    pio0Register = pIOCON->PIO0[pin] & ~(PIN_MODE_MASK);
    pIOCON->PIO0[pin] = pio0Register | (mode << PIN_MODE_BITNUM);
}

static inline void IoconPinEnableHysteresis(LPC_IOCON_T *pIOCON, PINx_T pin)
{
    uint32_t pio0Register = pIOCON->PIO0[pin] | PIN_HYS_MASK;
    pIOCON->PIO0[pin] = pio0Register;
}

static inline void IoconPinDisableHysteresis(LPC_IOCON_T *pIOCON, PINx_T pin)
{
    uint32_t pio0Register = pIOCON->PIO0[pin] & ~PIN_HYS_MASK;
    pIOCON->PIO0[pin] = pio0Register;
}

static inline void IoconPinSetHysteresis(LPC_IOCON_T *pIOCON, PINx_T pin, bool enable)
{
    if(enable == true)
        IoconPinEnableHysteresis(pIOCON, pin);
    else 
        IoconPinDisableHysteresis(pIOCON, pin);
}

static inline void IoconPinEnableInputInverted(LPC_IOCON_T *pIOCON, PINx_T pin)
{
    uint32_t pio0Register = pIOCON->PIO0[pin] | PIN_INV_MASK;
    pIOCON->PIO0[pin] = pio0Register;
}

static inline void IoconPinDisableInputInverted(LPC_IOCON_T *pIOCON, PINx_T pin)
{
    uint32_t pio0Register = pIOCON->PIO0[pin] & ~PIN_INV_MASK;
    pIOCON->PIO0[pin] = pio0Register;
}

static inline void IoconPinSetInputInverted(LPC_IOCON_T *pIOCON, PINx_T pin, bool invert)
{
    if(invert == true) 
        IoconPinEnableInputInverted(pIOCON, pin);
    else 
        IoconPinDisableInputInverted(pIOCON, pin);
}

static inline void IoconPinEnableOpenDrainMode(LPC_IOCON_T *pIOCON, PINx_T pin)
{
    uint32_t pio0Register = pIOCON->PIO0[pin] | PIN_OD_MASK;
    pIOCON->PIO0[pin] = pio0Register;
}

static inline void IoconPinDisableOpenDrainMode(LPC_IOCON_T *pIOCON, PINx_T pin)
{
    uint32_t pio0Register = pIOCON->PIO0[pin] & ~PIN_OD_MASK;
    pIOCON->PIO0[pin] = pio0Register;
}

static inline void IoconPinSetOpenDrainMode(LPC_IOCON_T *pIOCON, PINx_T pin, bool open_drain)
{
    if(open_drain == true)
        IoconPinEnableOpenDrainMode(pIOCON, pin);
    else 
        IoconPinDisableOpenDrainMode(pIOCON, pin);
}

static inline void IoconPinSetSampleMode(LPC_IOCON_T *pIOCON, PINx_T pin, PIN_SMODE_T smode)
{
    uint32_t pio0Register;
    pio0Register = pIOCON->PIO0[pin] & ~(PIN_SMODE_MASK);
    pIOCON->PIO0[pin] = pio0Register | (smode << PIN_SMODE_BITNUM);
}

static inline void IoconPinSetClockDivisor(LPC_IOCON_T *pIOCON, PINx_T pin, PIN_CLKDIV_T clkdiv)
{
    uint32_t pio0Register;
    pio0Register = pIOCON->PIO0[pin] & ~(PIN_CLKDIV_MASK);
    pIOCON->PIO0[pin] = pio0Register | (clkdiv << PIN_CLKDIV_BITNUM);
}

static inline void IoconPinSetI2CMode(LPC_IOCON_T *pIOCON, PINx_T pin, PIN_I2CMODE_T mode)
{
    uint32_t pio0Register;
    pio0Register = pIOCON->PIO0[pin] & ~(PIN_I2CMODE_MASK);
    pIOCON->PIO0[pin] = pio0Register | (mode << PIN_I2CMODE_BITNUM);
}

#endif