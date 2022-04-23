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
LPC810 series common UART registers, defines and functions.
*/
#ifndef LPC81X_UART_H
#define LPC81X_UART_H

/** USART - Register Layout Typedef */
typedef volatile struct USART_Struct {
  uint32_t CFG; /*!< USART Configuration register. Basic USART configuration settings that typically are not changed during
                   operation., offset: 0x0 */
  uint32_t CTL; /*!< USART Control register. USART control settings that are more likely to change during operation., offset: 0x4 */
  uint32_t STAT;     /*!< USART Status register. The complete status value can be read here. Writing ones clears some bits in the
                        register. Some bits can be cleared by writing a 1 to them., offset: 0x8 */
  uint32_t INTENSET; /*!< Interrupt Enable read and Set register. Contains an individual interrupt enable bit for each potential
                        USART interrupt. A complete value may be read from this register. Writing a 1 to any implemented bit
                        position causes that bit to be set., offset: 0xC */
  uint32_t INTENCLR; /*!< Interrupt Enable Clear register. Allows clearing any combination of bits in the INTENSET register. Writing
                        a 1 to any implemented bit position causes the corresponding bit to be cleared., offset: 0x10 */
  const uint32_t RXDAT;     /*!< Receiver Data register. Contains the last character received., offset: 0x14 */
  const uint32_t RXDATSTAT; /*!< Receiver Data with Status register. Combines the last character received with the current USART
                               receive status. Allows DMA or software to recover incoming data and status together., offset: 0x18 */
  uint32_t TXDAT;           /*!< Transmit Data register. Data to be transmitted is written here., offset: 0x1C */
  uint32_t BRG;             /*!< Baud Rate Generator register. 16-bit integer baud rate divisor value., offset: 0x20 */
  const uint32_t INTSTAT;   /*!< Interrupt status register. Reflects interrupts that are currently enabled., offset: 0x24 */
} USART_Type;

#define USART_CFG_RESERVED (0xFF032582)   /*!< USART Config register reserved bits */
#define USART_CFG_ENABLE (0x01 << 0)      /*!< USART enable */
#define USART_CFG_DATALEN_7 (0x00 << 2)   /*!< USART 7 bit length mode */
#define USART_CFG_DATALEN_8 (0x01 << 2)   /*!< USART 8 bit length mode */
#define USART_CFG_DATALEN_9 (0x02 << 2)   /*!< USART 9 bit length mode */
#define USART_CFG_PARITY_NONE (0x00 << 4) /*!< No parity */
#define USART_CFG_PARITY_EVEN (0x02 << 4) /*!< Even parity */
#define USART_CFG_PARITY_ODD (0x03 << 4)  /*!< Odd parity */
#define USART_CFG_STOPLEN_1 (0x00 << 6)   /*!< USART One Stop Bit Select */
#define USART_CFG_STOPLEN_2 (0x01 << 6)   /*!< USART Two Stop Bits Select */
#define USART_CFG_CTSEN (0x01 << 9)       /*!< CTS enable bit */
#define USART_CFG_SYNCEN (0x01 << 11)     /*!< Synchronous mode enable bit */
#define USART_CFG_CLKPOL (0x01 << 12)     /*!< Un_RXD rising edge sample enable bit */
#define USART_CFG_SYNCMST (0x01 << 14)    /*!< Select master mode (synchronous mode) enable bit */
#define USART_CFG_LOOP (0x01 << 15)       /*!< Loopback mode enable bit */

#define USART_CTL_RESERVED (0xFFFEFCB9) /*!< USART Control register reserved bits */
#define USART_CTL_TXBRKEN (0x01 << 1)   /*!< Break enable */
#define USART_CTL_ADDRDET (0x01 << 2)   /*!< Enable address detect mode */
#define USART_CTL_TXDIS (0x01 << 6)     /*!< Transmit disable */
#define USART_CTL_CC (0x01 << 8)        /*!< Continuous clock generation */
#define USART_CTL_CLRCCONRX (0x01 << 9) /*!< Clear continuous clock */

#define USART_STAT_RESERVED (0xFFFE0280)  /*!< USART status register reserved bits */
#define USART_STAT_CLEAR (0x0001F920)     /*!< clear bits with 1's per datasheet */
#define USART_STAT_RXRDY (1 << 0)         /*!< Receiver ready flag*/
#define USART_STAT_RXIDLE (1 << 1)        /*!< Receiver idle */
#define USART_STAT_TXRDY (1 << 2)         /*!< Transmitter ready flag */
#define USART_STAT_TXIDLE (1 << 3)        /*!< Transmitter idle */
#define USART_STAT_CTS (1 << 4)           /*!< CTS signal status */
#define USART_STAT_DELTACTS (1 << 5)      /*!< CTS changed flag */
#define USART_STAT_TXDISSTAT (1 << 6)     /*!< Transmitter disabled interrupt flag */
#define USART_STAT_OVERRUNINT (1 << 8)    /*!< Overrun interrupt flag */
#define USART_STAT_RXBRK (1 << 10)        /*!< Received Break */
#define USART_STAT_DELTARXBRK (1 << 11)   /*!< Received break changed flag */
#define USART_STAT_START (1 << 12)        /*!< Start detected flag */
#define USART_STAT_FRAMERRINT (1 << 13)   /*!< Framing error interrupt flag */
#define USART_STAT_PARITYERRINT (1 << 14) /*!< Parity error interrupt flag */
#define USART_STAT_RXNOISEINT (1 << 15)   /*!< Received noise interrupt flag */

#define USART_RXDATSTAT_RESERVED (0x0000E1FF) /*!< USART RX data with status register reserved bits*/
#define USART_RXDATSTAT_FRAMERR (1 << 13)     /*!< Framing error detected */
#define USART_RXDATSTAT_PARITYERR (1 << 14)   /*!< Parity error detected */
#define USART_RXDATSTAT_RXNOISE (1 << 15)     /*!< Received noise detected */

#include "nxp/LPC8XX/LPC8XX_uart.h"

#endif