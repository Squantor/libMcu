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
LPC800 series common GPIO functions
*/
#ifndef LPC8XX_GPIO_H
#define LPC8XX_GPIO_H

#include <stdint.h>

/* GPIO initilisation function */
static inline void GPIO_Init(LPC_GPIO_T *pGPIO)
{
    Clock_EnablePeriphClock(SYSCTL_CLOCK_GPIO);
}

/* GPIO deinitialisation function */
static inline void GPIO_DeInit(LPC_GPIO_T *pGPIO)
{
    Clock_DisablePeriphClock(SYSCTL_CLOCK_GPIO);
}

static inline void GPIO_WritePortBit(LPC_GPIO_T *pGPIO, uint32_t port, uint8_t pin, bool setting)
{
    pGPIO->B[port][pin] = setting;
}

static inline void GPIO_SetPinState(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin, bool setting)
{
    pGPIO->B[port][pin] = setting;
}

static inline bool GPIO_ReadPortBit(LPC_GPIO_T *pGPIO, uint32_t port, uint8_t pin)
{
    return (bool) pGPIO->B[port][pin];
}

static inline bool GPIO_GetPinState(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    return (bool) pGPIO->B[port][pin];
}

static inline void GPIO_WriteDirBit(LPC_GPIO_T *pGPIO, uint32_t port, uint8_t pin, bool setting)
{
    if(setting)
    {
        pGPIO->DIR[port] |= 1UL << pin;
    }
    else
    {
        pGPIO->DIR[port] &= ~(1UL << pin);
    }
}

static inline void GPIO_SetPinDIR(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin, bool output)
{
    if (output) {
        GPIO_SetPinDIROutput(pGPIO, port, pin);
    }
    else {
        GPIO_SetPinDIRInput(pGPIO, port, pin);
    }
}

static inline bool GPIO_ReadDirBit(LPC_GPIO_T *pGPIO, uint32_t port, uint8_t bit)
{
    return (bool) (((pGPIO->DIR[port]) >> bit) & 1);
}

static inline bool GPIO_GetPinDIR(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    return GPIO_ReadDirBit(pGPIO, port, pin);
}

static inline void GPIO_SetPortDIR(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pinMask, bool outSet)
{
    if(outSet) 
    {
        GPIO_SetPortDIROutput(pGPIO, port, pinMask);
    }
    else 
    {
        GPIO_SetPortDIRInput(pGPIO, port, pinMask);
    }
}

static inline void GPIO_SetPortDIRMask(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pinMask, uint32_t outMask)
{
    GPIO_SetPortDIRInput(pGPIO, port, pinMask & ~outMask);
    GPIO_SetPortDIROutput(pGPIO, port, pinMask & outMask);
}

static inline uint32_t GPIO_GetPortDIR(LPC_GPIO_T *pGPIO, uint8_t port)
{
    return pGPIO->DIR[port];
}

static inline void GPIO_SetPortMask(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t mask)
{
    pGPIO->MASK[port] = mask;
}

static inline uint32_t GPIO_GetPortMask(LPC_GPIO_T *pGPIO, uint8_t port)
{
    return pGPIO->MASK[port];
}

static inline void GPIO_SetPortValue(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t value)
{
    pGPIO->PIN[port] = value;
}

static inline uint32_t GPIO_GetPortValue(LPC_GPIO_T *pGPIO, uint8_t port)
{
    return pGPIO->PIN[port];
}

static inline void GPIO_SetMaskedPortValue(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t value)
{
    pGPIO->MPIN[port] = value;
}

static inline uint32_t GPIO_GetMaskedPortValue(LPC_GPIO_T *pGPIO, uint8_t port)
{
    return pGPIO->MPIN[port];
}

static inline void GPIO_SetValue(LPC_GPIO_T *pGPIO, uint8_t portNum, uint32_t bitValue)
{
    pGPIO->SET[portNum] = bitValue;
}

static inline void GPIO_SetPortOutHigh(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pins)
{
    pGPIO->SET[port] = pins;
}

static inline void GPIO_SetPinOutHigh(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->SET[port] = (1 << pin);
}

static inline void GPIO_ClearValue(LPC_GPIO_T *pGPIO, uint8_t portNum, uint32_t bitValue)
{
    pGPIO->CLR[portNum] = bitValue;
}

static inline void GPIO_SetPortOutLow(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pins)
{
    pGPIO->CLR[port] = pins;
}

static inline void GPIO_SetPinOutLow(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->CLR[port] = (1 << pin);
}

static inline void GPIO_SetPortToggle(LPC_GPIO_T *pGPIO, uint8_t port, uint32_t pins)
{
    pGPIO->NOT[port] = pins;
}

static inline void GPIO_SetPinToggle(LPC_GPIO_T *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->NOT[port] = (1 << pin);
}

static inline uint32_t GPIO_ReadValue(LPC_GPIO_T *pGPIO, uint8_t portNum)
{
    return pGPIO->PIN[portNum];
}

#endif