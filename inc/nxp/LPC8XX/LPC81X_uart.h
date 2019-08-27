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
LPC810 series common UART registers,definitions and functions.
*/
#ifndef LPC81X_UART_H
#define LPC81X_UART_H

/* UART CFG register definitions */
#define UART_CFG_RESERVED       ((1<<1)|(1<<7)|(1<<8)|(1<<10)|(1<<13)|(0xffffu<<16))

/* UART CTRL register definitions */
#define UART_CTRL_RESERVED      (1|(7<<3)|(1<<7)|0xfffffc00u)

/* UART STAT register definitions */
#define UART_STAT_RESERVED      ((1<<7)|(1<<9)|(0xffffu<<16))

/* UART INTENSET/INTENCLR register definitions */
#define UART_INTEN_RESERVED     ((1<<1)|(3<<3)|(1<<7)|(3<<9)|(0xffffu<<16))
#define UART_INTSTAT_RESERVED   ((1<<1)|(3<<3)|(1<<7)|(3<<9)|(0xffffu<<16))

#include "nxp/LPC8XX/LPC8XX_uart.h"

#endif