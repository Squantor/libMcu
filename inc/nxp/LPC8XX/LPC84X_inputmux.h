/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series Input Multiplexer registers, defines and functions.
 */
#ifndef LPC84X_INPUTMUX_H
#define LPC84X_INPUTMUX_H

/** INPUTMUX - Register Layout Typedef */
typedef volatile struct INPUTMUX_Struct {
    uint32_t DMA_INMUX_INMUX[2];    /*!< DMA output trigger selection to become DMA trigger, array offset: 0x0, array step: 0x4 */
    uint8_t RESERVED_0[24];
    uint32_t SCT_INMUX[4];          /*!< input select register for SCT, array offset: 0x20, array step: 0x4 */
    uint8_t RESERVED_1[16];
    uint32_t DMA_ITRIG_INMUX[25];   /*!< Trigger select register for DMA channel, array offset: 0x40, array step: 0x4 */
} INPUTMUX_Type;

/**
 * SCT Input values enum, TODO: move to device specifics
 */
typedef enum SCT_INMUX_INPUT {
    SCT_INMUX_INPUT_0 = 0,    /*!< SCT Input 0 */
    SCT_INMUX_INPUT_1 = 1,    /*!< SCT Input 1 */
    SCT_INMUX_INPUT_2 = 2,    /*!< SCT Input 2 */
    SCT_INMUX_INPUT_3 = 3,    /*!< SCT Input 3 */
} SCT_INMUX_INPUT_Type;

/**
 * SCT Inputs muxing options
 */
typedef enum SCT_INPUT_MUX {
    SCT_MUX_PIN0 = 0,           /*!< SCT input pin 0 */
    SCT_MUX_PIN1 = 1,           /*!< SCT input pin 1 */
    SCT_MUX_PIN2 = 2,           /*!< SCT input pin 2 */
    SCT_MUX_PIN3 = 3,           /*!< SCT input pin 3 */
    SCT_MUX_ADC_THCMP_IRQ = 4,  /*!< ADC threshold comparator IRQ */
    SCT_MUX_ACMP_O = 5,         /*!< TODO */
    SCT_MUX_T0_MAT2 = 6,        /*!< TODO */
    SCT_MUX_GPIOINT_BMATCH = 7, /*!< TODO */
    SCT_MUX_ARM_TXEV = 8,       /*!< TODO */
    SCT_MUX_DEBUG_HALTED = 9,   /*!< TODO */
} SCT_INPUT_MUX_Type;

#define SCT_INMUX_RESERVED  (0xFFFFFFF0)

static inline void inputMuxSct(INPUTMUX_Type *peripheral, SCT_INMUX_INPUT_Type input, SCT_INPUT_MUX_Type setting)
{
    peripheral->SCT_INMUX[input] = setting & ~SCT_INMUX_RESERVED;
}

#endif
