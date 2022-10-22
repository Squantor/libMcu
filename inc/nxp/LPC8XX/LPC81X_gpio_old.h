/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC810 series GPIO registers, defines and functions.
*/

#ifndef LPC81X_GPIO_OLD_H
#define LPC81X_GPIO_OLD_H

static inline void GpioSetPinDIROutput(GPIO_Type *pGPIO, uint8_t port, uint8_t pin) {
  uint32_t dirRegister = pGPIO->DIR[port] | 1UL << pin;
  pGPIO->DIR[port] = dirRegister;
}

static inline void GpioSetPinDIRInput(GPIO_Type *pGPIO, uint8_t port, uint8_t pin) {
  uint32_t dirRegister = pGPIO->DIR[port] & ~(1UL << pin);
  pGPIO->DIR[port] = dirRegister;
}

static inline void GpioTogglePinDIR(GPIO_Type *pGPIO, uint8_t port, uint8_t pin) {
  uint32_t dirRegister = pGPIO->DIR[port] ^ 1UL << pin;
  pGPIO->DIR[port] = dirRegister;
}

static inline void GpioSetPortDIROutput(GPIO_Type *pGPIO, uint8_t port, uint32_t pinMask) {
  uint32_t dirRegister = pGPIO->DIR[port] | pinMask;
  pGPIO->DIR[port] = dirRegister;
}

static inline void GpioSetPortDIRInput(GPIO_Type *pGPIO, uint8_t port, uint32_t pinMask) {
  uint32_t dirRegister = pGPIO->DIR[port] & ~pinMask;
  pGPIO->DIR[port] = dirRegister;
}

static inline void GpioTogglePortDIR(GPIO_Type *pGPIO, uint8_t port, uint32_t pinMask) {
  uint32_t dirRegister = pGPIO->DIR[port] ^ pinMask;
  pGPIO->DIR[port] = dirRegister;
}

// include common functions
#include <nxp/LPC8XX/LPC8XX_gpio_old.h>

#endif