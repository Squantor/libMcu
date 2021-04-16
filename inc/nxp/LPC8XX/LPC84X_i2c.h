/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series I2C registers, defines and functions.
 */
#ifndef LPC84X_I2C_H
#define LPC84X_I2C_H

/** I2C - Register Layout Typedef */
typedef volatile struct {
    uint32_t CFG;               /**< Configuration for shared functions., offset: 0x0 */
    uint32_t STAT;              /**< Status register for Master, Slave, and Monitor functions., offset: 0x4 */
    uint32_t INTENSET;          /**< Interrupt Enable Set and read register., offset: 0x8 */
    const uint32_t INTENCLR;    /**< Interrupt Enable Clear register., offset: 0xC */
    uint32_t TIMEOUT;           /**< Time-out value register., offset: 0x10 */
    uint32_t CLKDIV;            /**< Clock pre-divider for the entire I2C interface. This determines what time increments are used for the MSTTIME register, and controls some timing of the Slave function., offset: 0x14 */
    const uint32_t INTSTAT;     /**< Interrupt Status register for Master, Slave, and Monitor functions., offset: 0x18 */
    uint8_t RESERVED_0[4];
    uint32_t MSTCTL;            /**< Master control register., offset: 0x20 */
    uint32_t MSTTIME;           /**< Master timing configuration., offset: 0x24 */
    uint32_t MSTDAT;            /**< Combined Master receiver and transmitter data register., offset: 0x28 */
    uint8_t RESERVED_1[20];
    uint32_t SLVCTL;            /**< Slave control register., offset: 0x40 */
    uint32_t SLVDAT;            /**< Combined Slave receiver and transmitter data register., offset: 0x44 */
    uint32_t SLVADR[4];         /**< Slave address register., array offset: 0x48, array step: 0x4 */
    uint32_t SLVQUAL0;          /**< Slave Qualification for address 0., offset: 0x58 */
    uint8_t RESERVED_2[36];
    const uint32_t MONRXDAT;    /**< Monitor receiver data register., offset: 0x80 */
} I2C_Type;

#endif