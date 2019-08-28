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
LPC800 series common UART registers,definitions and functions.
*/
#ifndef LPC8XX_UART_H
#define LPC8XX_UART_H

/**
 * @brief UART register block structure
 */
typedef struct {
    __IO uint32_t  CFG;            /* Configuration register */
    __IO uint32_t  CTRL;        /* Control register */
    __IO uint32_t  STAT;        /* Status register */
    __IO uint32_t  INTENSET;    /* Interrupt Enable read and set register */
    __O  uint32_t  INTENCLR;    /* Interrupt Enable clear register */
    __I  uint32_t  RXDATA;        /* Receive Data register */
    __I  uint32_t  RXDATA_STAT;    /* Receive Data with status register */
    __IO uint32_t  TXDATA;        /* Transmit data register */
    __IO uint32_t  BRG;            /* Baud Rate Generator register */
    __IO uint32_t  INTSTAT;        /* Interrupt status register */
    __IO uint32_t  OSR;         /* Oversampling Selection regiser */
    __IO uint32_t  ADDR;        /* Address register for automatic address matching */
} LPC_USART_T;

/* UART CFG register definitions */
#define UART_CFG_ENABLE         (0x01 << 0)
#define UART_CFG_DATALEN_7      (0x00 << 2)        /* UART 7 bit length mode */
#define UART_CFG_DATALEN_8      (0x01 << 2)        /* UART 8 bit length mode */
#define UART_CFG_DATALEN_9      (0x02 << 2)        /* UART 9 bit length mode */
#define UART_CFG_PARITY_NONE    (0x00 << 4)        /* No parity */
#define UART_CFG_PARITY_EVEN    (0x02 << 4)        /* Even parity */
#define UART_CFG_PARITY_ODD     (0x03 << 4)        /* Odd parity */
#define UART_CFG_STOPLEN_1      (0x00 << 6)        /* UART One Stop Bit Select */
#define UART_CFG_STOPLEN_2      (0x01 << 6)        /* UART Two Stop Bits Select */
#define UART_CFG_CTSEN          (0x01 << 9)        /* CTS enable bit */
#define UART_CFG_SYNCEN         (0x01 << 11)    /* Synchronous mode enable bit */
#define UART_CFG_CLKPOL         (0x01 << 12)    /* Un_RXD rising edge sample enable bit */
#define UART_CFG_SYNCMST        (0x01 << 14)    /* Select master mode (synchronous mode) enable bit */
#define UART_CFG_LOOP           (0x01 << 15)    /* Loopback mode enable bit */

/* UART CTRL register definitions */
#define UART_CTRL_TXBRKEN       (0x01 << 1)        /* Continuous break enable bit */
#define UART_CTRL_ADDRDET       (0x01 << 2)        /* Address detect mode enable bit */
#define UART_CTRL_TXDIS         (0x01 << 6)        /* Transmit disable bit */
#define UART_CTRL_CC            (0x01 << 8)        /* Continuous Clock mode enable bit */
#define UART_CTRL_CLRCC         (0x01 << 9)        /* Clear Continuous Clock bit */

/* UART STAT register definitions */
#define UART_STAT_RXRDY         (0x01 << 0)            /* Receiver ready */
#define UART_STAT_RXIDLE        (0x01 << 1)            /* Receiver idle */
#define UART_STAT_TXRDY         (0x01 << 2)            /* Transmitter ready for data */
#define UART_STAT_TXIDLE        (0x01 << 3)            /* Transmitter idle */
#define UART_STAT_CTS           (0x01 << 4)            /* Status of CTS signal */
#define UART_STAT_DELTACTS      (0x01 << 5)            /* Change in CTS state */
#define UART_STAT_TXDISINT      (0x01 << 6)            /* Transmitter disabled */
#define UART_STAT_OVERRUNINT    (0x01 << 8)            /* Overrun Error interrupt flag. */
#define UART_STAT_RXBRK         (0x01 << 10)        /* Received break */
#define UART_STAT_DELTARXBRK    (0x01 << 11)        /* Change in receive break detection */
#define UART_STAT_START         (0x01 << 12)        /* Start detected */
#define UART_STAT_FRM_ERRINT    (0x01 << 13)        /* Framing Error interrupt flag */
#define UART_STAT_PAR_ERRINT    (0x01 << 14)        /* Parity Error interrupt flag */
#define UART_STAT_RXNOISEINT    (0x01 << 15)        /* Received Noise interrupt flag */

/* UART INTENSET/INTENCLR register definitions */
#define UART_INTEN_RXRDY        (0x01 << 0)            /* Receive Ready interrupt */
#define UART_INTEN_TXRDY        (0x01 << 2)            /* Transmit Ready interrupt */
#define UART_INTEN_DELTACTS     (0x01 << 5)            /* Change in CTS state interrupt */
#define UART_INTEN_TXDIS        (0x01 << 6)            /* Transmitter disable interrupt */
#define UART_INTEN_OVERRUN      (0x01 << 8)            /* Overrun error interrupt */
#define UART_INTEN_DELTARXBRK   (0x01 << 11)        /* Change in receiver break detection interrupt */
#define UART_INTEN_START        (0x01 << 12)        /* Start detect interrupt */
#define UART_INTEN_FRAMERR      (0x01 << 13)        /* Frame error interrupt */
#define UART_INTEN_PARITYERR    (0x01 << 14)        /* Parity error interrupt */
#define UART_INTEN_RXNOISE      (0x01 << 15)        /* Received noise interrupt */

static inline void UART_Enable(LPC_USART_T *pUART)
{
    pUART->CFG = UART_CFG_ENABLE | (pUART->CFG & ~UART_CFG_RESERVED);
}

static inline void UART_Disable(LPC_USART_T *pUART)
{
    pUART->CFG &= ~(UART_CFG_RESERVED | UART_CFG_ENABLE);
}

static inline void UART_TXEnable(LPC_USART_T *pUART)
{
    pUART->CTRL &= ~(UART_CTRL_RESERVED | UART_CTRL_TXDIS);
}

static inline void UART_TXDisable(LPC_USART_T *pUART)
{
    pUART->CTRL = UART_CTRL_TXDIS | (pUART->CTRL & ~UART_CTRL_RESERVED);
}

static inline void UART_SendByte(LPC_USART_T *pUART, uint8_t data)
{
    pUART->TXDATA = (uint32_t) data;
}

static inline uint32_t UART_ReadByte(LPC_USART_T *pUART)
{
    return (uint32_t) (pUART->RXDATA & 0x000001FF);
}

static inline void UART_IntEnable(LPC_USART_T *pUART, uint32_t intMask)
{
    pUART->INTENSET = intMask;
}

static inline void UART_IntDisable(LPC_USART_T *pUART, uint32_t intMask)
{
    pUART->INTENCLR = intMask;
}

static inline uint32_t UART_GetIntsEnabled(LPC_USART_T *pUART)
{
    return (pUART->INTENSET & ~UART_INTEN_RESERVED);
}

static inline uint32_t UART_GetIntStatus(LPC_USART_T *pUART)
{
    return (pUART->INTSTAT & ~UART_INTSTAT_RESERVED);
}

static inline void UART_ConfigData(LPC_USART_T *pUART, uint32_t config)
{
    uint32_t reg;
    reg = pUART->CFG & ~((0x3 << 2) | (0x3 << 4) | (0x1 << 6) | UART_CFG_RESERVED);
    pUART->CFG = reg | config;
}

static inline uint32_t UART_GetStatus(LPC_USART_T *pUART)
{
    return (pUART->STAT & ~UART_STAT_RESERVED);
}

static inline void UART_ClearStatus(LPC_USART_T *pUART, uint32_t stsMask)
{
    pUART->STAT = stsMask;
}

static inline void UART_SetOSR(LPC_USART_T *pUART, uint32_t ovrVal)
{
    pUART->OSR = ovrVal - 1;
}

static inline void UART_SetAddr(LPC_USART_T *pUART, uint32_t addr)
{
    pUART->ADDR = addr;
}

/* Return UART clock ID from the UART register address */
static inline SYSCTL_CLOCK_T getUARTClockID(LPC_USART_T *pUART)
{
    if (pUART == LPC_USART0) {
        return SYSCTL_CLOCK_UART0;
    }
    else if (pUART == LPC_USART1) {
        return SYSCTL_CLOCK_UART1;
    }

    return SYSCTL_CLOCK_UART2;
}

static inline void UART_Init(LPC_USART_T *pUART)
{
    /* Enable USART clock */
    Clock_EnablePeriphClock(getUARTClockID(pUART));

    /* UART reset */
    if (pUART == LPC_USART0) {
        /* Peripheral reset control to USART0 */
        SYSCTL_PeriphReset(RESET_USART0);
    }
    else if (pUART == LPC_USART1) {
        /* Peripheral reset control to USART1 */
        SYSCTL_PeriphReset(RESET_USART1);
    }
    else {
        /* Peripheral reset control to USART2 */
        SYSCTL_PeriphReset(RESET_USART2);
    }
}

static inline void UART_DeInit(LPC_USART_T *pUART)
{
    Clock_DisablePeriphClock(getUARTClockID(pUART));
}

static inline void UART_SetBaud(LPC_USART_T *pUART, uint32_t baudrate)
{
    uint32_t baudRateGenerator;
    baudRateGenerator = Clock_GetUSARTNBaseClockRate() / (16 * baudrate);
    pUART->BRG = baudRateGenerator - 1;    /* baud rate */
}

#endif