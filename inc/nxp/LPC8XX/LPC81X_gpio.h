/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
LPC810 series GPIO registers, defines and functions.
*/

#ifndef LPC81X_GPIO_H
#define LPC81X_GPIO_H


typedef volatile struct {
    uint8_t B[128][32];    /* Byte pin registers ports 0 to n; pins PIOn_0 to PIOn_31 */
    uint32_t W[32][32];    /* Word pin registers port 0 to n */
    uint32_t DIR[32];      /* Direction registers port n */
    uint32_t MASK[32];     /* Mask register port n */
    uint32_t PIN[32];      /* Portpin register port n */
    uint32_t MPIN[32];     /* Masked port register port n */
    uint32_t SET[32];      /* Write: Set register for port n Read: output bits for port n */
    uint32_t CLR[32];       /* Clear port n */
    uint32_t NOT[32];       /* Toggle port n */
} GPIO_Type;

/** GPIO - available ports on LPC84X */
typedef enum {
    GPIO_PORT0 = 0x0u,
} GPIO_PORT_Type;

/*!
 * @brief Sets the output level of the one GPIO pin to the logic 1 or 0.
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pin           GPIO pin number
 * @param output        GPIO pin output logic level.
 *        - 0: corresponding pin output low-logic level.
 *        - 1: corresponding pin output high-logic level.
 */
static inline void gpioPinWrite(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pin, uint8_t output)
{
    peripheral->B[port][pin] = output;
}

/*!
 * @brief Reads the current input value of the GPIO PIN.
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pin           GPIO pin number
 * @retval              GPIO port input value
 *        - 0: corresponding pin input low-logic level.
 *        - 1: corresponding pin input high-logic level.
 */
static inline uint32_t gpioPinRead(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pin)
{
    return (uint32_t)peripheral->B[port][pin];
}

/*!
 * @brief Set the port direction register
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param reg           direction register setting
 */
static inline void gpioSetPortDir(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t reg)
{
    peripheral->DIR[port] = reg;
}

/*!
 * @brief Set the port pin to input mode
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pin           GPIO pin number to set as input
 */
static inline void gpioSetPinDIRInput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint8_t pin)
{
    uint32_t pins = peripheral->DIR[port];
    pins &= ~(1UL << pin);
    peripheral->DIR[port] = pins;
}

/*!
 * @brief Set the port pin to output mode
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pin           GPIO pin number to set as output
 */
static inline void gpioSetPinDIROutput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint8_t pin)
{
    uint32_t pins = peripheral->DIR[port];
    pins |= 1UL << pin;
    peripheral->DIR[port] = pins;
}

/*!
 * @brief Sets the output level of the GPIO port
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param output        GPIO port output value.
 */
static inline void gpioPortWrite(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t output)
{
    peripheral->PIN[port] = output;
}

/*!
 * @brief Reads the current input value of the whole GPIO port.
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 */
static inline uint32_t gpioPortRead(GPIO_Type *peripheral, GPIO_PORT_Type port)
{
    return (uint32_t)peripheral->PIN[port];
}

#include "nxp/LPC8XX/LPC81X_gpio_old.h"

#endif