/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC820 series GPIO registers, defines and functions.
*/
/*
LPC800 series common GPIO registers, defines and functions.
*/
#ifndef LPC8XX_GPIO_H
#define LPC8XX_GPIO_H

/*!
 * @brief Set the port direction register
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param reg           direction register setting
 */
static inline void gpioSetPortDir(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t reg) {
  peripheral->DIR[port] = reg;
}

/*!
 * @brief Set the port pin to output mode
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pin           GPIO pin number to set as output
 */
static inline void gpioSetPinDIROutput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint8_t pin) {
  uint32_t pins = peripheral->DIR[port];
  pins |= 1UL << pin;
  peripheral->DIR[port] = pins;
}

/*!
 * @brief Set the port pin to input mode
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pin           GPIO pin number to set as input
 */
static inline void gpioSetPinDIRInput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint8_t pin) {
  uint32_t pins = peripheral->DIR[port];
  pins &= ~(1UL << pin);
  peripheral->DIR[port] = pins;
}

/*!
 * @brief Toggle the port pin direction
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pin           GPIO pin number to direction toggle
 */
static inline void gpioTogglePinDIR(GPIO_Type *peripheral, GPIO_PORT_Type port, uint8_t pin) {
  uint32_t pins = peripheral->DIR[port];
  pins ^= 1UL << pin;
  peripheral->DIR[port] = pins;
}

/*!
 * @brief Set the port register to outputs
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pinMask       direction register output setting
 */
static inline void gpioSetPortDIROutput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pinMask) {
  uint32_t pins = peripheral->DIR[port];
  pins |= pinMask;
  peripheral->DIR[port] = pins;
}

/*!
 * @brief Set the port register to inputs
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pinMask       direction register input setting
 */
static inline void gpioSetPortDIRInput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pinMask) {
  uint32_t pins = peripheral->DIR[port];
  pins &= ~pinMask;
  peripheral->DIR[port] = pins;
}

/*!
 * @brief Toggle the port register direct
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param pinMask       direction register input setting
 */
static inline void gpioTogglePortDIR(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pinMask) {
  uint32_t pins = peripheral->DIR[port];
  pins ^= pinMask;
  peripheral->DIR[port] = pins;
}

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
static inline void gpioPinWrite(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pin, uint8_t output) {
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
static inline uint32_t gpioPinRead(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pin) {
  return (uint32_t)peripheral->B[port][pin];
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 1.
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param mask          GPIO pins to set
 */
static inline void gpioPortSet(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t mask) {
  peripheral->SET[port] = mask;
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 0.
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param mask          GPIO pins to clear
 */
static inline void gpioPortClear(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t mask) {
  peripheral->CLR[port] = mask;
}

/*!
 * @brief Reverses current output logic of the multiple GPIO pins.
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param mask          GPIO pins to toggle
 */
static inline void gpioPortToggle(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t mask) {
  peripheral->NOT[port] = mask;
}

/*!
 * @brief Sets the output level of the GPIO port
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param output        GPIO port output value.
 */
static inline void gpioPortWrite(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t output) {
  peripheral->PIN[port] = output;
}

/*!
 * @brief Reads the current input value of the whole GPIO port.
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 */
static inline uint32_t gpioPortRead(GPIO_Type *peripheral, GPIO_PORT_Type port) {
  return (uint32_t)peripheral->PIN[port];
}

/*!
 * @brief Sets port mask, 0 - enable pin, 1 - disable pin.
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param mask          GPIO pin number macro
 */
static inline void gpioPortMaskedSet(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t mask) {
  peripheral->MASK[port] = mask;
}

/*!
 * @brief Sets the output level of the masked GPIO port. Only pins enabled by
 * GPIO_SetPortMask() will be affected.
 *
 * @param peripheral    GPIO peripheral peripheral pointer
 * @param port          GPIO port number
 * @param output        GPIO port output value.
 */
static inline void gpioPortMaskedWrite(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t output) {
  peripheral->MPIN[port] = output;
}

#endif