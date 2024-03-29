/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC800 series common multi rate timer registers, defines and functions.
*/
#ifndef LPC8XX_MRT_H
#define LPC8XX_MRT_H

/* LPC8xx MRT chip configuration */
// TODO: move to controller definitions?
#define MRT_CHANNELS_NUM (4)
#define MRT_NO_IDLE_CHANNEL (0x40)

/* MRT register block structure */
typedef volatile struct {
  uint32_t INTVAL; /* Timer interval register */
  uint32_t TIMER;  /* Timer register */
  uint32_t CTRL;   /* Timer control register */
  uint32_t STAT;   /* Timer status register */
} MRT_CH_Type;

/* MRT register block structure */
typedef volatile struct {
  MRT_CH_Type CHANNEL[MRT_CHANNELS_NUM];
  uint32_t unused[45];
  uint32_t IDLE_CH;
  uint32_t IRQ_FLAG;
} MRT_Type;

/* Reserved bits masks for registers */
// TODO: move to controller definitions?
#define MRT_CTRL_RESERVED (~7)
#define MRT_STAT_RESERVED (~3)

/* MRT Interrupt Modes enum */
typedef enum MRT_MODE {
  MRT_MODE_REPEAT = (0 << 1), /*!< MRT Repeat interrupt mode */
  MRT_MODE_ONESHOT = (1 << 1) /*!< MRT One-shot interrupt mode */
} MRT_MODE_T;

/* MRT Time interval register bit fields */
#define MRT_INTVAL_IVALUE (0x7FFFFFFFUL) /* Maximum interval load value and mask */
#define MRT_INTVAL_LOAD (0x80000000UL)   /* Force immediate load of timer interval register bit */

/* MRT Control register bit fields & masks */
#define MRT_CTRL_INTEN_MASK (0x01)
#define MRT_CTRL_MODE_MASK (0x06)

/* MRT Status register bit fields & masks */
#define MRT_STAT_INTFLAG (0x01)
#define MRT_STAT_RUNNING (0x02)

/* Pointer to individual MR register blocks */
#define MRT_CH0 ((MRT_CH_Type *)&MRT->CHANNEL[0])
#define MRT_CH1 ((MRT_CH_Type *)&MRT->CHANNEL[1])
#define MRT_CH2 ((MRT_CH_Type *)&MRT->CHANNEL[2])
#define MRT_CH3 ((MRT_CH_Type *)&MRT->CHANNEL[3])
#define MRT_CH(ch) ((MRT_CH_Type *)&MRT->CHANNEL[(ch)])

/* Global interrupt flag register interrupt mask/clear values */
#define MRT0_INTFLAG (1)
#define MRT1_INTFLAG (2)
#define MRT2_INTFLAG (4)
#define MRT3_INTFLAG (8)
#define MRTn_INTFLAG(ch) (1 << (ch))

#include "nxp/LPC8XX/LPC8XX_mrt_old.h"

#endif