/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC840 series DMA registers, defines and functions.
 */
#ifndef LPC84X_DMA_H
#define LPC84X_DMA_H

/** DMA - Register Layout Typedef */
typedef volatile struct DMA_Struct {
    uint32_t CTRL;              /**< DMA control., offset: 0x0 */
    const uint32_t INTSTAT;     /**< Interrupt status., offset: 0x4 */
    uint32_t SRAMBASE;          /**< SRAM address of the channel configuration table., offset: 0x8 */
    uint8_t RESERVED_0[20];
    struct {                    /* offset: 0x20, array step: 0x5C */
        uint32_t ENABLESET;     /**< Channel Enable read and Set for all DMA channels., array offset: 0x20, array step: 0x5C */
        uint8_t RESERVED_0[4];
        uint32_t ENABLECLR;     /**< Channel Enable Clear for all DMA channels., array offset: 0x28, array step: 0x5C */
        uint8_t RESERVED_1[4];
        const uint32_t ACTIVE;  /**< Channel Active status for all DMA channels., array offset: 0x30, array step: 0x5C */
        uint8_t RESERVED_2[4];
        const uint32_t BUSY;    /**< Channel Busy status for all DMA channels., array offset: 0x38, array step: 0x5C */
        uint8_t RESERVED_3[4];
        uint32_t ERRINT;        /**< Error Interrupt status for all DMA channels., array offset: 0x40, array step: 0x5C */
        uint8_t RESERVED_4[4];
        uint32_t INTENSET;      /**< Interrupt Enable read and Set for all DMA channels., array offset: 0x48, array step: 0x5C */
        uint8_t RESERVED_5[4];
        uint32_t INTENCLR;      /**< Interrupt Enable Clear for all DMA channels., array offset: 0x50, array step: 0x5C */
        uint8_t RESERVED_6[4];
        uint32_t INTA;          /**< Interrupt A status for all DMA channels., array offset: 0x58, array step: 0x5C */
        uint8_t RESERVED_7[4];
        uint32_t INTB;          /**< Interrupt B status for all DMA channels., array offset: 0x60, array step: 0x5C */
        uint8_t RESERVED_8[4];
        uint32_t SETVALID;      /**< Set ValidPending control bits for all DMA channels., array offset: 0x68, array step: 0x5C */
        uint8_t RESERVED_9[4];
        uint32_t SETTRIG;       /**< Set Trigger control bits for all DMA channels., array offset: 0x70, array step: 0x5C */
        uint8_t RESERVED_10[4];
        uint32_t ABORT;         /**< Channel Abort control for all DMA channels., array offset: 0x78, array step: 0x5C */
    } COMMON[1];
    uint8_t RESERVED_1[900];
    struct {                    /* offset: 0x400, array step: 0x10 */
        uint32_t CFG;           /**< Configuration register for DMA channel ., array offset: 0x400, array step: 0x10 */
        const uint32_t CTLSTAT; /**< Control and status register for DMA channel ., array offset: 0x404, array step: 0x10 */
        uint32_t XFERCFG;       /**< Transfer configuration register for DMA channel ., array offset: 0x408, array step: 0x10 */
        uint8_t RESERVED_0[4];
    } CHANNEL[25];
} DMA_Type;

#endif
