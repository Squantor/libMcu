/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC820 series GPIO registers, defines and functions.
*/
/*
LPC800 series common GPIO registers, defines and functions.
*/
#ifndef LPC8XX_GPIO_OLD_H
#define LPC8XX_GPIO_OLD_H

static inline void GpioWritePortBit(GPIO_Type *pGPIO, uint32_t port, uint8_t pin, bool setting) {
  pGPIO->B[port][pin] = setting;
}

static inline void GpioSetPinState(GPIO_Type *pGPIO, uint8_t port, uint8_t pin, bool setting) {
  pGPIO->B[port][pin] = setting;
}

static inline bool GpioReadPortBit(GPIO_Type *pGPIO, uint32_t port, uint8_t pin) {
  return (bool)pGPIO->B[port][pin];
}

static inline bool GpioGetPinState(GPIO_Type *pGPIO, uint8_t port, uint8_t pin) {
  return (bool)pGPIO->B[port][pin];
}

static inline void GpioWriteDirBit(GPIO_Type *pGPIO, uint32_t port, uint8_t pin, bool setting) {
  uint32_t dirRegister;
  if (setting) {
    dirRegister = pGPIO->DIR[port] | 1UL << pin;
    pGPIO->DIR[port] = dirRegister;
  } else {
    dirRegister = pGPIO->DIR[port] & ~(1UL << pin);
    pGPIO->DIR[port] = dirRegister;
  }
}

static inline void GpioSetPinDir(GPIO_Type *pGPIO, uint8_t port, uint8_t pin, bool output) {
  if (output) {
    GpioSetPinDIROutput(pGPIO, port, pin);
  } else {
    GpioSetPinDIRInput(pGPIO, port, pin);
  }
}

static inline bool GpioReadDirBit(GPIO_Type *pGPIO, uint32_t port, uint8_t bit) {
  return (bool)(((pGPIO->DIR[port]) >> bit) & 1);
}

static inline bool GpioGetPinDIR(GPIO_Type *pGPIO, uint8_t port, uint8_t pin) {
  return GpioReadDirBit(pGPIO, port, pin);
}

static inline void GpioSetPortDIR(GPIO_Type *pGPIO, uint8_t port, uint32_t pinMask, bool outSet) {
  if (outSet) {
    GpioSetPortDIROutput(pGPIO, port, pinMask);
  } else {
    GpioSetPortDIRInput(pGPIO, port, pinMask);
  }
}

static inline void GpioSetPortDIRMask(GPIO_Type *pGPIO, uint8_t port, uint32_t pinMask, uint32_t outMask) {
  GpioSetPortDIRInput(pGPIO, port, pinMask & ~outMask);
  GpioSetPortDIROutput(pGPIO, port, pinMask & outMask);
}

static inline uint32_t GpioGetPortDIR(GPIO_Type *pGPIO, uint8_t port) {
  return pGPIO->DIR[port];
}

static inline void GpioSetPortMask(GPIO_Type *pGPIO, uint8_t port, uint32_t mask) {
  pGPIO->MASK[port] = mask;
}

static inline uint32_t GpioGetPortMask(GPIO_Type *pGPIO, uint8_t port) {
  return pGPIO->MASK[port];
}

static inline void GpioSetPortValue(GPIO_Type *pGPIO, uint8_t port, uint32_t value) {
  pGPIO->PIN[port] = value;
}

static inline uint32_t GpioGetPortValue(GPIO_Type *pGPIO, uint8_t port) {
  return pGPIO->PIN[port];
}

static inline void GpioSetMaskedPortValue(GPIO_Type *pGPIO, uint8_t port, uint32_t value) {
  pGPIO->MPIN[port] = value;
}

static inline uint32_t GpioGetMaskedPortValue(GPIO_Type *pGPIO, uint8_t port) {
  return pGPIO->MPIN[port];
}

static inline void GpioSetValue(GPIO_Type *pGPIO, uint8_t portNum, uint32_t bitValue) {
  pGPIO->SET[portNum] = bitValue;
}

static inline void GpioSetPortOutHigh(GPIO_Type *pGPIO, uint8_t port, uint32_t pins) {
  pGPIO->SET[port] = pins;
}

static inline void GpioSetPinOutHigh(GPIO_Type *pGPIO, uint8_t port, uint8_t pin) {
  pGPIO->SET[port] = (1 << pin);
}

static inline void GpioClearValue(GPIO_Type *pGPIO, uint8_t portNum, uint32_t bitValue) {
  pGPIO->CLR[portNum] = bitValue;
}

static inline void GpioSetPortOutLow(GPIO_Type *pGPIO, uint8_t port, uint32_t pins) {
  pGPIO->CLR[port] = pins;
}

static inline void GpioSetPinOutLow(GPIO_Type *pGPIO, uint8_t port, uint8_t pin) {
  pGPIO->CLR[port] = (1 << pin);
}

static inline void GpioSetPortToggle(GPIO_Type *pGPIO, uint8_t port, uint32_t pins) {
  pGPIO->NOT[port] = pins;
}

static inline void GpioSetPinToggle(GPIO_Type *pGPIO, uint8_t port, uint8_t pin) {
  pGPIO->NOT[port] = (1 << pin);
}

static inline uint32_t GpioReadValue(GPIO_Type *pGPIO, uint8_t portNum) {
  return pGPIO->PIN[portNum];
}

#endif