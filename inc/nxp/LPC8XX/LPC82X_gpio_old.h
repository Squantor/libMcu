/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC820 series GPIO registers, defines and functions.
*/
#ifndef LPC82X_GPIO_OLD_H
#define LPC82X_GPIO_OLD_H

static inline void GpioSetPinDIROutput(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->DIRSET[port] = 1UL << pin;
}

static inline void GpioSetPinDIRInput(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->DIRCLR[port] = 1UL << pin;
}

static inline void GpioTogglePinDIR(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->DIRNOT[port] = 1UL << pin;
}

static inline void GpioSetPortDIROutput(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pinMask)
{
    pGPIO->DIRSET[port] = pinMask;
}

static inline void GpioSetPortDIRInput(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pinMask)
{
    pGPIO->DIRCLR[port] = pinMask;
}

static inline void GpioTogglePortDIR(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pinMask)
{
    pGPIO->DIRNOT[port] = pinMask;
}

// include common functions
#include <nxp/LPC8XX/LPC8XX_gpio.h>

#endif