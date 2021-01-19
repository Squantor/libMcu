/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series General Purpose I/O registers, defines and functions.
 */
#ifndef LPC84X_GPIO_H
#define LPC84X_GPIO_H

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint8_t B[2][32];            /**< Byte pin registers for all port 0 and 1 GPIO pins, array offset: 0x0, array step: index*0x20, index2*0x1 */
       uint8_t RESERVED_0[4032];
  __IO uint32_t W[2][32];           /**< Word pin registers for all port 0 and 1 GPIO pins, array offset: 0x1000, array step: index*0x80, index2*0x4 */
       uint8_t RESERVED_1[3840];
  __IO uint32_t DIR[2];             /**< Direction registers, array offset: 0x2000, array step: 0x4 */
       uint8_t RESERVED_2[120];
  __IO uint32_t MASK[2];            /**< Mask register, array offset: 0x2080, array step: 0x4 */
       uint8_t RESERVED_3[120];
  __IO uint32_t PIN[2];             /**< Port pin register, array offset: 0x2100, array step: 0x4 */
       uint8_t RESERVED_4[120];
  __IO uint32_t MPIN[2];            /**< Masked port register, array offset: 0x2180, array step: 0x4 */
       uint8_t RESERVED_5[120];
  __IO uint32_t SET[2];             /**< Write: Set register for port Read: output bits for port, array offset: 0x2200, array step: 0x4 */
       uint8_t RESERVED_6[120];
  __O  uint32_t CLR[2];             /**< Clear port, array offset: 0x2280, array step: 0x4 */
       uint8_t RESERVED_7[120];
  __O  uint32_t NOT[2];             /**< Toggle port, array offset: 0x2300, array step: 0x4 */
       uint8_t RESERVED_8[120];
  __O  uint32_t DIRSET[2];          /**< Set pin direction bits for port, array offset: 0x2380, array step: 0x4 */
       uint8_t RESERVED_9[120];
  __O  uint32_t DIRCLR[2];          /**< Clear pin direction bits for port, array offset: 0x2400, array step: 0x4 */
       uint8_t RESERVED_10[120];
  __O  uint32_t DIRNOT[2];          /**< Toggle pin direction bits for port, array offset: 0x2480, array step: 0x4 */
} GPIO_Type;

/** GPIO - available ports on LPC84X */
typedef enum {
    GPIO_PORT0 = 0x0u,
    GPIO_PORT1 = 0x1u,
} GPIO_PORT_Type;

static inline void gpioSetPinDIROutput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint8_t pin)
{
    peripheral->DIR[port] |= 1UL << pin;
}

static inline void gpioSetPinDIRInput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint8_t pin)
{
    peripheral->DIR[port] &= ~(1UL << pin);
}

static inline void gpioTogglePinDIR(GPIO_Type *peripheral, GPIO_PORT_Type port, uint8_t pin)
{
    peripheral->DIR[port] ^= 1UL << pin;
}

static inline void gpioSetPortDIROutput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pinMask)
{
    peripheral->DIR[port] |= pinMask;
}

static inline void gpioSetPortDIRInput(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pinMask)
{
    peripheral->DIR[port] &= ~pinMask;
}

static inline void gpioTogglePortDIR(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t pinMask)
{
    peripheral->DIR[port] ^= pinMask;
}

/*!
 * @brief Sets the output level of the one GPIO pin to the logic 1 or 0.
 *
 * @param peripheral    GPIO peripheral peripheral pointer(Typically GPIO)
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
 * @param peripheral    GPIO peripheral peripheral pointer(Typically GPIO)
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
 * @brief Sets the output level of the multiple GPIO pins to the logic 1.
 *
 * @param peripheral    GPIO peripheral peripheral pointer(Typically GPIO)
 * @param port          GPIO port number
 * @param mask          GPIO pin number macro
 */
static inline void gpioPortSet(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t mask)
{
    peripheral->SET[port] = mask;
}

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 0.
 *
 * @param peripheral    GPIO peripheral peripheral pointer(Typically GPIO)
 * @param port          GPIO port number
 * @param mask          GPIO pin number macro
 */
static inline void gpioPortClear(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t mask)
{
    peripheral->CLR[port] = mask;
}

/*!
 * @brief Reverses current output logic of the multiple GPIO pins.
 *
 * @param peripheral    GPIO peripheral peripheral pointer(Typically GPIO)
 * @param port          GPIO port number
 * @param mask          GPIO pin number macro
 */
static inline void gpioPortToggle(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t mask)
{
    peripheral->NOT[port] = mask;
}

/*!
 * @brief Reads the current input value of the whole GPIO port.
 *
 * @param peripheral    GPIO peripheral peripheral pointer(Typically GPIO)
 * @param port          GPIO port number
 */
static inline uint32_t gpioPortRead(GPIO_Type *peripheral, GPIO_PORT_Type port)
{
    return (uint32_t)peripheral->PIN[port];
}

/*!
 * @brief Sets port mask, 0 - enable pin, 1 - disable pin.
 *
 * @param peripheral    GPIO peripheral peripheral pointer(Typically GPIO)
 * @param port          GPIO port number
 * @param mask          GPIO pin number macro
 */
static inline void gpioPortMaskedSet(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t mask)
{
    peripheral->MASK[port] = mask;
}

/*!
 * @brief Sets the output level of the masked GPIO port. Only pins enabled by GPIO_SetPortMask() will be affected.
 *
 * @param peripheral    GPIO peripheral peripheral pointer(Typically GPIO)
 * @param port          GPIO port number
 * @param output        GPIO port output value.
 */
static inline void gpioPortMaskedWrite(GPIO_Type *peripheral, GPIO_PORT_Type port, uint32_t output)
{
    peripheral->MPIN[port] = output;
}

#endif
