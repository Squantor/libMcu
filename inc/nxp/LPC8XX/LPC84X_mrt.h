/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series Multi rate timer registers, defines and functions.
 */
#ifndef LPC84X_MRT_H
#define LPC84X_MRT_H

/** MRT - Register Layout Typedef */
typedef volatile struct MRT_Struct {
    struct {                    /* offset: 0x0, array step: 0x10 */
        uint32_t INTVAL;        /**< MRT Time interval value register. This value is loaded into the TIMER register., array offset: 0x0, array step: 0x10 */
        const uint32_t TIMER;   /**< MRT Timer register. This register reads the value of the down-counter., array offset: 0x4, array step: 0x10 */
        uint32_t CTRL;          /**< MRT Control register. This register controls the MRT modes., array offset: 0x8, array step: 0x10 */
        uint32_t STAT;          /**< MRT Status register., array offset: 0xC, array step: 0x10 */
    } CHANNEL[4];
    uint8_t RESERVED_0[180];
    const uint32_t IDLE_CH;     /**< Idle channel register. This register returns the number of the first idle channel., offset: 0xF4 */
    uint32_t IRQ_FLAG;          /**< Global interrupt flag register, offset: 0xF8 */
} MRT_Type;

#endif
