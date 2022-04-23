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
LPC800 series common UART registers, defines and functions.
*/
#ifndef LPC8XX_UART_H
#define LPC8XX_UART_H

/**
 * @brief   setup USART control register
 * @param   peripheral  base address of USART peripheral
 * @param   dataLength
 * @param   parity
 * @param   stopBits
 * @param   options
 */
static inline void usartSetConfig(USART_Type *peripheral, USART_DATALEN_Type dataLength, USART_PARITY_Type parity,
                                  USART_STOPLEN_Type stopBits, uint32_t options) {
  peripheral->CFG = USART_CFG_ENABLE | dataLength | parity | stopBits | options;
}

/**
 * @brief   TODO
 * @param   peripheral  base address of USART peripheral
 */
static inline void usartDisable(USART_Type *peripheral) {
  peripheral->CFG = 0x00000000;
  peripheral->CTL = 0x00000000;
  peripheral->STAT = USART_STAT_CLEAR;
}

/**
 * @brief   TODO
 * @param   peripheral  base address of USART peripheral
 */
static inline void usartTXEnable(USART_Type *peripheral) {
  uint32_t ctlRegister = peripheral->CTL & ~(USART_CTL_TXDIS);
  peripheral->CTL = ctlRegister;
}

/**
 * @brief   TODO
 * @param   peripheral  base address of USART peripheral
 */
static inline void usartTXDisable(USART_Type *peripheral) {
  peripheral->CTL = USART_CTL_TXDIS | peripheral->CTL;
}

/**
 * @brief   TODO
 * @param   peripheral  base address of USART peripheral
 */
static inline uint32_t usartGetStatus(USART_Type *peripheral) {
  return peripheral->STAT;
}

/**
 * @brief   TODO
 * @param   peripheral  base address of USART peripheral
 */
static inline void usartSendData(USART_Type *peripheral, uint16_t data) {
  peripheral->TXDAT = (uint32_t)(data & 0x000001FF);
}

/**
 * @brief   TODO
 * @param   peripheral  base address of USART peripheral
 */
static inline uint32_t usartReadData(USART_Type *peripheral) {
  return (uint32_t)(peripheral->RXDAT & 0x000001FF);
}

/**
 * @brief   TODO
 * @param   peripheral  base address of USART peripheral
 */
static inline uint32_t usartReadDataAndStatus(USART_Type *peripheral) {
  return (uint32_t)(peripheral->RXDATSTAT & 0x0000E1FF);
}

/**
 * @brief   set the baud rate
 * @param   peripheral  base address of USART peripheral
 * @param   baseClock   base clock of the USART peripheral
 * @param   baudRate    wanted baud rate
 * @return  computed baud rate
 */
static inline uint32_t usartSetBaud(USART_Type *peripheral, uint32_t baseClock, uint32_t baudRate) {
  uint32_t baudDivider = baseClock / (baudRate * 16);
  peripheral->BRG = baudDivider;
  return baseClock / 16 / baudDivider;
}

#endif