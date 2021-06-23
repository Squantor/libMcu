/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org>
*/
/* 
LPC800 series common multi rate timer registers, defines and functions.
*/
#ifndef LPC8XX_MRT_H
#define LPC8XX_MRT_H

/* LPC8xx MRT chip configuration */
// TODO: move to controller definitions?
#define MRT_CHANNELS_NUM      (4)
#define MRT_NO_IDLE_CHANNEL   (0x40)

/* MRT register block structure */
typedef struct {
    __IO uint32_t INTVAL;   /* Timer interval register */
    __O  uint32_t TIMER;    /* Timer register */
    __IO uint32_t CTRL;     /* Timer control register */
    __IO uint32_t STAT;     /* Timer status register */
} LPC_MRT_CH_T;

/* MRT register block structure */
typedef struct {
    LPC_MRT_CH_T CHANNEL[MRT_CHANNELS_NUM];
    uint32_t unused[45];
    __O  uint32_t IDLE_CH;
    __IO uint32_t IRQ_FLAG;
} LPC_MRT_T;

/* Reserved bits masks for registers */
// TODO: move to controller definitions?
#define MRT_CTRL_RESERVED   (~7)
#define MRT_STAT_RESERVED   (~3)

/* MRT Interrupt Modes enum */
typedef enum MRT_MODE {
    MRT_MODE_REPEAT =  (0 << 1),    /*!< MRT Repeat interrupt mode */
    MRT_MODE_ONESHOT = (1 << 1)        /*!< MRT One-shot interrupt mode */
} MRT_MODE_T;

/* MRT Time interval register bit fields */
#define MRT_INTVAL_IVALUE        (0x7FFFFFFFUL)    /* Maximum interval load value and mask */
#define MRT_INTVAL_LOAD          (0x80000000UL)    /* Force immediate load of timer interval register bit */

/* MRT Control register bit fields & masks */
#define MRT_CTRL_INTEN_MASK      (0x01)
#define MRT_CTRL_MODE_MASK       (0x06)

/* MRT Status register bit fields & masks */
#define MRT_STAT_INTFLAG         (0x01)
#define MRT_STAT_RUNNING         (0x02)

/* Pointer to individual MR register blocks */
#define LPC_MRT_CH0         ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[0])
#define LPC_MRT_CH1         ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[1])
#define LPC_MRT_CH2         ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[2])
#define LPC_MRT_CH3         ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[3])
#define LPC_MRT_CH(ch)      ((LPC_MRT_CH_T *) &LPC_MRT->CHANNEL[(ch)])

/* Global interrupt flag register interrupt mask/clear values */
#define MRT0_INTFLAG        (1)
#define MRT1_INTFLAG        (2)
#define MRT2_INTFLAG        (4)
#define MRT3_INTFLAG        (8)
#define MRTn_INTFLAG(ch)    (1 << (ch))

#endif