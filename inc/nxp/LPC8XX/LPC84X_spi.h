/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series SPI registers, defines and functions.
 */
#ifndef LPC84X_SPI_H
#define LPC84X_SPI_H

/** SPI - Register Layout Typedef */
typedef volatile struct {
    uint32_t CFG;           /**< SPI Configuration register, offset: 0x0 */
    uint32_t DLY;           /**< SPI Delay register, offset: 0x4 */
    uint32_t STAT;          /**< SPI Status. Some status flags can be cleared by writing a 1 to that bit position, offset: 0x8 */
    uint32_t INTENSET;      /**< SPI Interrupt Enable read and Set. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set., offset: 0xC */
    uint32_t INTENCLR;      /**< SPI Interrupt Enable Clear. Writing a 1 to any implemented bit position causes the corresponding bit in INTENSET to be cleared., offset: 0x10 */
    const uint32_t RXDAT;   /**< SPI Receive Data, offset: 0x14 */
    uint32_t TXDATCTL;      /**< SPI Transmit Data with Control, offset: 0x18 */
    uint32_t TXDAT;         /**< SPI Transmit Data., offset: 0x1C */
    uint32_t TXCTL;         /**< SPI Transmit Control, offset: 0x20 */
    uint32_t DIV;           /**< SPI clock Divider, offset: 0x24 */
    const uint32_t INTSTAT; /**< SPI Interrupt Status, offset: 0x28 */
} SPI_Type;

#endif
