/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series USART registers, defines and functions.
 */
#ifndef LPC84X_USART_H
#define LPC84X_USART_H

/** USART - Register Layout Typedef */
typedef volatile struct {
    uint32_t CFG;               /**< USART Configuration register. Basic USART configuration settings that typically are not changed during operation., offset: 0x0 */
    uint32_t CTL;               /**< USART Control register. USART control settings that are more likely to change during operation., offset: 0x4 */
    uint32_t STAT;              /**< USART Status register. The complete status value can be read here. Writing ones clears some bits in the register. Some bits can be cleared by writing a 1 to them., offset: 0x8 */
    uint32_t INTENSET;          /**< Interrupt Enable read and Set register. Contains an individual interrupt enable bit for each potential USART interrupt. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set., offset: 0xC */
    uint32_t INTENCLR;          /**< Interrupt Enable Clear register. Allows clearing any combination of bits in the INTENSET register. Writing a 1 to any implemented bit position causes the corresponding bit to be cleared., offset: 0x10 */
    const uint32_t RXDAT;       /**< Receiver Data register. Contains the last character received., offset: 0x14 */
    const uint32_t RXDATSTAT;   /**< Receiver Data with Status register. Combines the last character received with the current USART receive status. Allows DMA or software to recover incoming data and status together., offset: 0x18 */
    uint32_t TXDAT;             /**< Transmit Data register. Data to be transmitted is written here., offset: 0x1C */
    uint32_t BRG;               /**< Baud Rate Generator register. 16-bit integer baud rate divisor value., offset: 0x20 */
    const uint32_t INTSTAT;     /**< Interrupt status register. Reflects interrupts that are currently enabled., offset: 0x24 */
    uint32_t OSR;               /**< Oversample selection register for asynchronous communication., offset: 0x28 */
    uint32_t ADDR;              /**< Address register for automatic address matching., offset: 0x2C */
} USART_Type;

#endif
