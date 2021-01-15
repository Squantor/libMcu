/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series Capacitive Touch registers, defines and functions.
 */
#ifndef LPC84X_CAPT_H
#define LPC84X_CAPT_H

/** CAPT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;              /**< Configuration and control to setup the functional clock, the rules, and the pin selections and rules., offset: 0x0 */
  __IO uint32_t STATUS;            /**< Status from triggers and time-outs including if in a poll now. Some are used for interrupts., offset: 0x4 */
  __IO uint32_t POLL_TCNT;         /**< This sets up the polling counter and measurement counter rules., offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t INTENSET;          /**< Interrupt enable, offset: 0x10 */
  __IO uint32_t INTENCLR;          /**< Interrupt enable clear, offset: 0x14 */
  __I  uint32_t INTSTAT;           /**< Interrupt status (mask of STATUS and INTEN), offset: 0x18 */
       uint8_t RESERVED_1[4];
  __I  uint32_t TOUCH;             /**< Last touch event (touch or no-touch) in context., offset: 0x20 */
       uint8_t RESERVED_2[4056];
  __I  uint32_t ID;                /**< Block ID, offset: 0xFFC */
} CAPT_Type;

#endif
