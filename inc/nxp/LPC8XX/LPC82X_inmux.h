/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/*
LPC820 series common input multiplexer registers, defines and
functions.
*/
#ifndef LPC82X_INMUX_H
#define LPC82X_INMUX_H

typedef volatile struct {
  uint32_t DMA_INMUX_INMUX[2]; /**< DMA Trigger Input 20 & 21 PINMUX 0-1 */
  uint32_t RESERVED[6];        /**< Reserved; Should not be used */
  uint32_t SCT0_INMUX[4];      /**< Input mux register for SCT0; INPUT0-3 */
} LPC_INMUX_T;

/**
 * @brief    DMA INPUT MUX Index see inmuxSetDMAOTrig()
 */
typedef enum {
  DMA_INMUX_0, /**< MUX for DMA input trigger 20 */
  DMA_INMUX_1, /**< MUX for DMA input trigger 21 */
} DMA_INMUX_T;

/**
 * @brief    SCT Input Mux Index; See inmuxSetSCTInMux()
 */
typedef enum {
  SCT_INMUX_0, /**< Input mux for SCT0; INPUT 0 */
  SCT_INMUX_1, /**< Input mux for SCT0; INPUT 1 */
  SCT_INMUX_2, /**< Input mux for SCT0; INPUT 2 */
  SCT_INMUX_3, /**< Input mux for SCT0; INPUT 3 */
} SCT_INMUX_T;

/**
 * @brief    SCT INPUT triggers
 */
typedef enum {
  SCT_INP_IN0 = 0x00,           /**< SCT0_IN0 selected by Pin Matrix */
  SCT_INP_IN1 = 0x01,           /**< SCT0_IN1 selected by Pin Matrix */
  SCT_INP_IN2 = 0x02,           /**< SCT0_IN2 selected by Pin Matrix */
  SCT_INP_IN3 = 0x03,           /**< SCT0_IN3 selected by Pin Matrix */
  SCT_INP_ADC_THCMP_IRQ = 0x04, /**< ADC Threshold compare IRQ */
  SCT_INP_ACMP_O = 0x05,        /**< Analog comparator output */
  SCT_INP_ARM_TXEV = 0x06,      /**< ARM TX Event */
  SCT_INP_DEBUG_HALTED = 0x07,  /**< Debug halted event */
} SCT_INP_T;

/**
 * @brief    Select a trigger source for a DMA channel
 * @param    pINMUX    : The base of INPUT MUX register block
 * @param    imux    : Index of DMA input mux
 * @param    ch        : DMA channel ID
 * @return    Nothing
 */
static inline void inmuxSetDMAOTrig(LPC_INMUX_T *pINMUX, DMA_INMUX_T imux,
                                    DMA_CHID_T ch) {
  pINMUX->DMA_INMUX_INMUX[imux] = ch;
}

/**
 * @brief    Select a trigger source SCT module
 * @param    pINMUX    : The base of INPUT MUX register block
 * @param    isct    : Index of SCT input mux
 * @param    trig    : SCT Input function that will cause the trigger
 * @return    Nothing
 */
static inline void inmuxSetSCTInMux(LPC_INMUX_T *pINMUX, SCT_INMUX_T isct,
                                    SCT_INP_T trig) {
  pINMUX->SCT0_INMUX[isct] = trig;
}

/**
 * @brief DMA trigger pin muxing structure
 */
typedef struct { /* DMA trigger pin muxing register structure */
  uint32_t DMA_ITRIG_INMUX[MAX_DMA_CHANNEL]; /* Trigger input select register
                                                for DMA channels */
} LPC_DMATRIGMUX_T;

/* DMA triggers that can mapped to DMA channels */
typedef enum {
  DMATRIG_ADC_SEQA_IRQ = 0, /* ADC0 sequencer A interrupt as trigger */
  DMATRIG_ADC_SEQB_IRQ,     /* ADC0 sequencer B interrupt as trigger */
  DMATRIG_SCT0_DMA0,        /* SCT 0, DMA 0 as trigger */
  DMATRIG_SCT0_DMA1,        /* SCT 1, DMA 1 as trigger */
  DMATRIG_ACMP_O,           /* Analog comparator output */
  DMATRIG_PINT0,            /* Pin interrupt 0 as trigger */
  DMATRIG_PINT1,            /* Pin interrupt 1 as trigger */
  DMATRIG_DMA_INMUX0,       /* DMA Trigger MUX0 */
  DMATRIG_DMA_INMUX1,       /* DMA Trigger MUX1 */
} DMA_TRIGSRC_T;

/**
 * @brief    Select a trigger source for a DMA channel
 * @param    pDMATRIG    : The base of DMA trigger setup block on the chip
 * @param    ch            : DMA channel ID
 * @param    trig        : Trigger source for the DMA channel
 * @return    Nothing
 * @note    A DMA trigger source only needs to be setup when the DMA is setup
 *            for hardware trigger mode (when Chip_DMA_SetupChannelConfig() is
 *            called with DMA_CFG_HWTRIGEN as OR'ed option).
 */
static inline void dmaTrigMuxSetInputTrig(LPC_DMATRIGMUX_T *pDMATRIG,
                                          DMA_CHID_T ch, DMA_TRIGSRC_T trig) {
  pDMATRIG->DMA_ITRIG_INMUX[ch] = (uint32_t)trig;
}

#include "nxp/LPC8XX/LPC82X_inmux_old.h"

#endif