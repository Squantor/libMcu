/*
SPDX-License-Identifier: Unlicense

Copyright (c) 2021 Bart Bilos
For conditions of distribution and use, see LICENSE file
*/
/* 
LPC820 series common UART registers, defines and functions.
*/
#ifndef LPC82X_UART_H
#define LPC82X_UART_H

/* UART CFG register definitions */
#define UART_CFG_OETA           (0x01 << 18)    /* Output Enable Turnaround time for RS485 */
#define UART_CFG_AUTOADDR       (0x01 << 19)    /* Automatic address matching enable */
#define UART_CFG_OESEL          (0x01 << 20)    /* Output enable select */
#define UART_CFG_OEPOL          (0x01 << 21)    /* Output enable polarity */
#define UART_CFG_RXPOL          (0x01 << 22)    /* Receive data polarity */
#define UART_CFG_TXPOL          (0x01 << 22)    /* Transmit data polarity */
#define UART_CFG_RESERVED       ((1<<1)|(1<<7)|(1<<8)|(1<<10)|(1<<13)|(3 << 16)|(0xffu<<24))

/* UART CTRL register definitions */
#define UART_CTRL_AUTOBAUD      (1 << 16)       /* Enable UART Autobaud */
#define UART_CTRL_RESERVED      (0xFFFEFCB9U)

/* UART STAT register definitions */
#define UART_STAT_ABERR         (0x01 << 16)        /* Auto baud error */
#define UART_STAT_RESERVED      ((1<<7)|(1<<9)|(0xFFFEU<<16))

/* UART INTENSET/INTENCLR register definitions */
#define UART_INTEN_TXIDLE       (0x01 << 3)         /* TX Idle enable/clear */
#define UART_INTEN_ABERR        (0x01 << 16)        /* Auto baud error */
#define UART_INTEN_RESERVED     ((1<<1)|(1<<4)|(1<<7)|(3<<9)|(0xfffeu<<16))
#define UART_INTSTAT_RESERVED   ((1<<1)|(1<<4)|(1<<7)|(3<<9)|(0xfffeu<<16))

#include "nxp/LPC8XX/LPC8XX_uart.h"

#endif