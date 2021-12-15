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
LPC800 series common GPIO registers, defines and functions.
*/
#ifndef LPC8XX_GPIO_H
#define LPC8XX_GPIO_H

static inline void GpioWritePortBit(GPIO_Type *pGPIO, uint32_t port, uint8_t pin, bool setting)
{
    pGPIO->B[port][pin] = setting;
}

static inline void GpioSetPinState(GPIO_Type *pGPIO, uint8_t port, uint8_t pin, bool setting)
{
    pGPIO->B[port][pin] = setting;
}

static inline bool GpioReadPortBit(GPIO_Type *pGPIO, uint32_t port, uint8_t pin)
{
    return (bool) pGPIO->B[port][pin];
}

static inline bool GpioGetPinState(GPIO_Type *pGPIO, uint8_t port, uint8_t pin)
{
    return (bool) pGPIO->B[port][pin];
}

static inline void GpioWriteDirBit(GPIO_Type *pGPIO, uint32_t port, uint8_t pin, bool setting)
{
    uint32_t dirRegister;
    if(setting)
    {
        dirRegister = pGPIO->DIR[port] | 1UL << pin;
        pGPIO->DIR[port] = dirRegister;
    }
    else
    {
        dirRegister = pGPIO->DIR[port] & ~(1UL << pin);
        pGPIO->DIR[port] = dirRegister;
    }
}

static inline void GpioSetPinDir(GPIO_Type *pGPIO, uint8_t port, uint8_t pin, bool output)
{
    if (output) {
        GpioSetPinDIROutput(pGPIO, port, pin);
    }
    else {
        GpioSetPinDIRInput(pGPIO, port, pin);
    }
}

static inline bool GpioReadDirBit(GPIO_Type *pGPIO, uint32_t port, uint8_t bit)
{
    return (bool) (((pGPIO->DIR[port]) >> bit) & 1);
}

static inline bool GpioGetPinDIR(GPIO_Type *pGPIO, uint8_t port, uint8_t pin)
{
    return GpioReadDirBit(pGPIO, port, pin);
}

static inline void GpioSetPortDIR(GPIO_Type *pGPIO, uint8_t port, uint32_t pinMask, bool outSet)
{
    if(outSet) 
    {
        GpioSetPortDIROutput(pGPIO, port, pinMask);
    }
    else 
    {
        GpioSetPortDIRInput(pGPIO, port, pinMask);
    }
}

static inline void GpioSetPortDIRMask(GPIO_Type *pGPIO, uint8_t port, uint32_t pinMask, uint32_t outMask)
{
    GpioSetPortDIRInput(pGPIO, port, pinMask & ~outMask);
    GpioSetPortDIROutput(pGPIO, port, pinMask & outMask);
}

static inline uint32_t GpioGetPortDIR(GPIO_Type *pGPIO, uint8_t port)
{
    return pGPIO->DIR[port];
}

static inline void GpioSetPortMask(GPIO_Type *pGPIO, uint8_t port, uint32_t mask)
{
    pGPIO->MASK[port] = mask;
}

static inline uint32_t GpioGetPortMask(GPIO_Type *pGPIO, uint8_t port)
{
    return pGPIO->MASK[port];
}

static inline void GpioSetPortValue(GPIO_Type *pGPIO, uint8_t port, uint32_t value)
{
    pGPIO->PIN[port] = value;
}

static inline uint32_t GpioGetPortValue(GPIO_Type *pGPIO, uint8_t port)
{
    return pGPIO->PIN[port];
}

static inline void GpioSetMaskedPortValue(GPIO_Type *pGPIO, uint8_t port, uint32_t value)
{
    pGPIO->MPIN[port] = value;
}

static inline uint32_t GpioGetMaskedPortValue(GPIO_Type *pGPIO, uint8_t port)
{
    return pGPIO->MPIN[port];
}

static inline void GpioSetValue(GPIO_Type *pGPIO, uint8_t portNum, uint32_t bitValue)
{
    pGPIO->SET[portNum] = bitValue;
}

static inline void GpioSetPortOutHigh(GPIO_Type *pGPIO, uint8_t port, uint32_t pins)
{
    pGPIO->SET[port] = pins;
}

static inline void GpioSetPinOutHigh(GPIO_Type *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->SET[port] = (1 << pin);
}

static inline void GpioClearValue(GPIO_Type *pGPIO, uint8_t portNum, uint32_t bitValue)
{
    pGPIO->CLR[portNum] = bitValue;
}

static inline void GpioSetPortOutLow(GPIO_Type *pGPIO, uint8_t port, uint32_t pins)
{
    pGPIO->CLR[port] = pins;
}

static inline void GpioSetPinOutLow(GPIO_Type *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->CLR[port] = (1 << pin);
}

static inline void GpioSetPortToggle(GPIO_Type *pGPIO, uint8_t port, uint32_t pins)
{
    pGPIO->NOT[port] = pins;
}

static inline void GpioSetPinToggle(GPIO_Type *pGPIO, uint8_t port, uint8_t pin)
{
    pGPIO->NOT[port] = (1 << pin);
}

static inline uint32_t GpioReadValue(GPIO_Type *pGPIO, uint8_t portNum)
{
    return pGPIO->PIN[portNum];
}

#endif