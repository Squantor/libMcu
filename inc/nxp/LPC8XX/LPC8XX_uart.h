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
#ifndef LPC8XX_PININT_H
#define LPC8XX_PININT_H

/**
 * @brief UART register block structure
 */
typedef struct {
	__IO uint32_t  CFG;		    /* Configuration register */
	__IO uint32_t  CTRL;		/* Control register */
	__IO uint32_t  STAT;		/* Status register */
	__IO uint32_t  INTENSET;	/* Interrupt Enable read and set register */
	__O  uint32_t  INTENCLR;	/* Interrupt Enable clear register */
	__I  uint32_t  RXDATA;		/* Receive Data register */
	__I  uint32_t  RXDATA_STAT;	/* Receive Data with status register */
	__IO uint32_t  TXDATA;		/* Transmit data register */
	__IO uint32_t  BRG;			/* Baud Rate Generator register */
	__IO uint32_t  INTSTAT;		/* Interrupt status register */
	__IO uint32_t  OSR;         /* Oversampling Selection regiser */
	__IO uint32_t  ADDR;        /* Address register for automatic address matching */
} LPC_USART_T;

/* UART CFG register definitions */
#define UART_CFG_ENABLE         (0x01 << 0)
#define UART_CFG_DATALEN_7      (0x00 << 2)		/* UART 7 bit length mode */
#define UART_CFG_DATALEN_8      (0x01 << 2)		/* UART 8 bit length mode */
#define UART_CFG_DATALEN_9      (0x02 << 2)		/* UART 9 bit length mode */
#define UART_CFG_PARITY_NONE    (0x00 << 4)		/* No parity */
#define UART_CFG_PARITY_EVEN    (0x02 << 4)		/* Even parity */
#define UART_CFG_PARITY_ODD     (0x03 << 4)		/* Odd parity */
#define UART_CFG_STOPLEN_1      (0x00 << 6)		/* UART One Stop Bit Select */
#define UART_CFG_STOPLEN_2      (0x01 << 6)		/* UART Two Stop Bits Select */
#define UART_CFG_CTSEN          (0x01 << 9)		/* CTS enable bit */
#define UART_CFG_SYNCEN         (0x01 << 11)	/* Synchronous mode enable bit */
#define UART_CFG_CLKPOL         (0x01 << 12)	/* Un_RXD rising edge sample enable bit */
#define UART_CFG_SYNCMST        (0x01 << 14)	/* Select master mode (synchronous mode) enable bit */
#define UART_CFG_LOOP           (0x01 << 15)	/* Loopback mode enable bit */

/* UART CTRL register definitions */
#define UART_CTRL_TXBRKEN       (0x01 << 1)		/* Continuous break enable bit */
#define UART_CTRL_ADDRDET       (0x01 << 2)		/* Address detect mode enable bit */
#define UART_CTRL_TXDIS         (0x01 << 6)		/* Transmit disable bit */
#define UART_CTRL_CC            (0x01 << 8)		/* Continuous Clock mode enable bit */
#define UART_CTRL_CLRCC         (0x01 << 9)		/* Clear Continuous Clock bit */

/* UART STAT register definitions */
#define UART_STAT_RXRDY         (0x01 << 0)			/* Receiver ready */
#define UART_STAT_RXIDLE        (0x01 << 1)			/* Receiver idle */
#define UART_STAT_TXRDY         (0x01 << 2)			/* Transmitter ready for data */
#define UART_STAT_TXIDLE        (0x01 << 3)			/* Transmitter idle */
#define UART_STAT_CTS           (0x01 << 4)			/* Status of CTS signal */
#define UART_STAT_DELTACTS      (0x01 << 5)			/* Change in CTS state */
#define UART_STAT_TXDISINT      (0x01 << 6)			/* Transmitter disabled */
#define UART_STAT_OVERRUNINT    (0x01 << 8)			/* Overrun Error interrupt flag. */
#define UART_STAT_RXBRK         (0x01 << 10)		/* Received break */
#define UART_STAT_DELTARXBRK    (0x01 << 11)		/* Change in receive break detection */
#define UART_STAT_START         (0x01 << 12)		/* Start detected */
#define UART_STAT_FRM_ERRINT    (0x01 << 13)		/* Framing Error interrupt flag */
#define UART_STAT_PAR_ERRINT    (0x01 << 14)		/* Parity Error interrupt flag */
#define UART_STAT_RXNOISEINT    (0x01 << 15)		/* Received Noise interrupt flag */

/* UART INTENSET/INTENCLR register definitions */
#define UART_INTEN_RXRDY        (0x01 << 0)			/* Receive Ready interrupt */
#define UART_INTEN_TXRDY        (0x01 << 2)			/* Transmit Ready interrupt */
#define UART_INTEN_DELTACTS     (0x01 << 5)			/* Change in CTS state interrupt */
#define UART_INTEN_TXDIS        (0x01 << 6)			/* Transmitter disable interrupt */
#define UART_INTEN_OVERRUN      (0x01 << 8)			/* Overrun error interrupt */
#define UART_INTEN_DELTARXBRK   (0x01 << 11)		/* Change in receiver break detection interrupt */
#define UART_INTEN_START        (0x01 << 12)		/* Start detect interrupt */
#define UART_INTEN_FRAMERR      (0x01 << 13)		/* Frame error interrupt */
#define UART_INTEN_PARITYERR    (0x01 << 14)		/* Parity error interrupt */
#define UART_INTEN_RXNOISE      (0x01 << 15)		/* Received noise interrupt */

/**
 * @brief	Enable the UART
 * @param	pUART		: Pointer to selected UARTx peripheral
 * @return	Nothing
 */
static inline void UART_Enable(LPC_USART_T *pUART)
{
	pUART->CFG = UART_CFG_ENABLE | (pUART->CFG & ~UART_CFG_RESERVED);
}

/**
 * @brief	Disable the UART
 * @param	pUART	: Pointer to selected UARTx peripheral
 * @return	Nothing
 */
static inline void UART_Disable(LPC_USART_T *pUART)
{
	pUART->CFG &= ~(UART_CFG_RESERVED | UART_CFG_ENABLE);
}

/**
 * @brief	Enable transmission on UART TxD pin
 * @param	pUART	: Pointer to selected pUART peripheral
 * @return Nothing
 */
static inline void UART_TXEnable(LPC_USART_T *pUART)
{
	pUART->CTRL &= ~(UART_CTRL_RESERVED | UART_CTRL_TXDIS);
}

/**
 * @brief	Disable transmission on UART TxD pin
 * @param	pUART	: Pointer to selected pUART peripheral
 * @return Nothing
 */
static inline void UART_TXDisable(LPC_USART_T *pUART)
{
	pUART->CTRL = UART_CTRL_TXDIS | (pUART->CTRL & ~UART_CTRL_RESERVED);
}

/**
 * @brief	Transmit a single data byte through the UART peripheral
 * @param	pUART	: Pointer to selected UART peripheral
 * @param	data	: Byte to transmit
 * @return	Nothing
 * @note	This function attempts to place a byte into the UART transmit
 *			holding register regard regardless of UART state.
 */
static inline void UART_SendByte(LPC_USART_T *pUART, uint8_t data)
{
	pUART->TXDATA = (uint32_t) data;
}

/**
 * @brief	Read a single byte data from the UART peripheral
 * @param	pUART	: Pointer to selected UART peripheral
 * @return	A single byte of data read
 * @note	This function reads a byte from the UART receive FIFO or
 *			receive hold register regard regardless of UART state. The
 *			FIFO status should be read first prior to using this function
 */
static inline uint32_t UART_ReadByte(LPC_USART_T *pUART)
{
	/* Strip off undefined reserved bits, keep 9 lower bits */
	return (uint32_t) (pUART->RXDATA & 0x000001FF);
}

/**
 * @brief	Enable UART interrupts
 * @param	pUART	: Pointer to selected UART peripheral
 * @param	intMask	: OR'ed Interrupts to enable
 * @return	Nothing
 * @note	Use an OR'ed value of UART_INTEN_* definitions with this function
 *			to enable specific UART interrupts.
 */
static inline void UART_IntEnable(LPC_USART_T *pUART, uint32_t intMask)
{
	pUART->INTENSET = intMask;
}

/**
 * @brief	Disable UART interrupts
 * @param	pUART	: Pointer to selected UART peripheral
 * @param	intMask	: OR'ed Interrupts to disable
 * @return	Nothing
 * @note	Use an OR'ed value of UART_INTEN_* definitions with this function
 *			to disable specific UART interrupts.
 */
static inline void UART_IntDisable(LPC_USART_T *pUART, uint32_t intMask)
{
	pUART->INTENCLR = intMask;
}

/**
 * @brief	Returns UART interrupts that are enabled
 * @param	pUART	: Pointer to selected UART peripheral
 * @return	Returns the enabled UART interrupts
 * @note	Use an OR'ed value of UART_INTEN_* definitions with this function
 *			to determine which interrupts are enabled. You can check
 *			for multiple enabled bits if needed.
 */
static inline uint32_t UART_GetIntsEnabled(LPC_USART_T *pUART)
{
	return (pUART->INTENSET & ~UART_INTEN_RESERVED);
}

/**
 * @brief	Get UART interrupt status
 * @param	pUART	: The base of UART peripheral on the chip
 * @return	The Interrupt status register of UART
 * @note	Multiple interrupts may be pending. Mask the return value
 *			with one or more UART_INTEN_* definitions to determine
 *			pending interrupts.
 */
static inline uint32_t UART_GetIntStatus(LPC_USART_T *pUART)
{
	return (pUART->INTSTAT & ~UART_INTSTAT_RESERVED);
}

/**
 * @brief	Configure data width, parity and stop bits
 * @param	pUART	: Pointer to selected pUART peripheral
 * @param	config	: UART configuration, OR'ed values of select UART_CFG_* defines
 * @return	Nothing
 * @note	Select OR'ed config options for the UART from the UART_CFG_PARITY_*,
 *			UART_CFG_STOPLEN_*, and UART_CFG_DATALEN_* definitions. For example,
 *			a configuration of 8 data bits, 1 stop bit, and even (enabled) parity would be
 *			(UART_CFG_DATALEN_8 | UART_CFG_STOPLEN_1 | UART_CFG_PARITY_EVEN). Will not
 *			alter other bits in the CFG register.
 */
static inline void UART_ConfigData(LPC_USART_T *pUART, uint32_t config)
{
	uint32_t reg;

	reg = pUART->CFG & ~((0x3 << 2) | (0x3 << 4) | (0x1 << 6) | UART_CFG_RESERVED);
	pUART->CFG = reg | config;
}

/**
 * @brief	Get the UART status register
 * @param	pUART	: Pointer to selected UARTx peripheral
 * @return	UART status register
 * @note	Multiple statuses may be pending. Mask the return value
 *			with one or more UART_STAT_* definitions to determine
 *			statuses.
 */
static inline uint32_t UART_GetStatus(LPC_USART_T *pUART)
{
	return (pUART->STAT & ~UART_STAT_RESERVED);
}

/**
 * @brief	Clear the UART status register
 * @param	pUART	: Pointer to selected UARTx peripheral
 * @param	stsMask	: OR'ed statuses to disable
 * @return	Nothing
 * @note	Multiple interrupts may be pending. Mask the return value
 *			with one or more UART_INTEN_* definitions to determine
 *			pending interrupts.
 */
static inline void UART_ClearStatus(LPC_USART_T *pUART, uint32_t stsMask)
{
	pUART->STAT = stsMask;
}

/**
 * @brief	Set oversample value
 * @param	pUART		: Pointer to selected UARTx peripheral
 * @param	ovrVal		: Oversample value (can be from 5 to 16)
 * @return	Nothing
 * @note	The valid values for ovrVal is 5 to 16 (samples per bit)
 */
static inline void UART_SetOSR(LPC_USART_T *pUART, uint32_t ovrVal)
{
	pUART->OSR = ovrVal - 1;
}

/**
 * @brief	Set address for hardware address matching
 * @param	pUART		: Pointer to selected UARTx peripheral
 * @param	addr		: Address to compare (0x00 to 0xFF)
 * @return	Nothing
 * @note	The valid values for addr is 0x00 to 0xFF
 */
static inline void UART_SetAddr(LPC_USART_T *pUART, uint32_t addr)
{
	pUART->ADDR = addr;
}

/**
 * @brief	Initialize the UART peripheral
 * @param	pUART	: The base of UART peripheral on the chip
 * @return	Nothing
 */
void UART_Init(LPC_USART_T *pUART);

/**
 * @brief	Deinitialize the UART peripheral
 * @param	pUART	: The base of UART peripheral on the chip
 * @return	Nothing
 */
void UART_DeInit(LPC_USART_T *pUART);

/**
 * @brief	Transmit a byte array through the UART peripheral (non-blocking)
 * @param	pUART		: Pointer to selected UART peripheral
 * @param	data		: Pointer to bytes to transmit
 * @param	numBytes	: Number of bytes to transmit
 * @return	The actual number of bytes placed into the FIFO
 * @note	This function places data into the transmit FIFO until either
 *			all the data is in the FIFO or the FIFO is full. This function
 *			will not block in the FIFO is full. The actual number of bytes
 *			placed into the FIFO is returned. This function ignores errors.
 */
int UART_Send(LPC_USART_T *pUART, const void *data, int numBytes);

/**
 * @brief	Read data through the UART peripheral (non-blocking)
 * @param	pUART		: Pointer to selected UART peripheral
 * @param	data		: Pointer to bytes array to fill
 * @param	numBytes	: Size of the passed data array
 * @return	The actual number of bytes read
 * @note	This function reads data from the receive FIFO until either
 *			all the data has been read or the passed buffer is completely full.
 *			This function will not block. This function ignores errors.
 */
int UART_Read(LPC_USART_T *pUART, void *data, int numBytes);

/**
 * @brief	Set baud rate for UART
 * @param	pUART	: The base of UART peripheral on the chip
 * @param	baudrate: Baud rate to be set
 * @return	Nothing
 */
void UART_SetBaud(LPC_USART_T *pUART, uint32_t baudrate);

/**
 * @brief	Transmit a byte array through the UART peripheral (blocking)
 * @param	pUART		: Pointer to selected UART peripheral
 * @param	data		: Pointer to data to transmit
 * @param	numBytes	: Number of bytes to transmit
 * @return	The number of bytes transmitted
 * @note	This function will send or place all bytes into the transmit
 *			FIFO. This function will block until the last bytes are in the FIFO.
 */
int UART_SendBlocking(LPC_USART_T *pUART, const void *data, int numBytes);

/**
 * @brief	Read data through the UART peripheral (blocking)
 * @param	pUART		: Pointer to selected UART peripheral
 * @param	data		: Pointer to data array to fill
 * @param	numBytes	: Size of the passed data array
 * @return	The size of the dat array
 * @note	This function reads data from the receive FIFO until the passed
 *			buffer is completely full. The function will block until full.
 *			This function ignores errors.
 */
int UART_ReadBlocking(LPC_USART_T *pUART, void *data, int numBytes);

/**
 * @brief	UART receive-only interrupt handler for ring buffers
 * @param	pUART	: Pointer to selected UART peripheral
 * @param	pRB		: Pointer to ring buffer structure to use
 * @return	Nothing
 * @note	If ring buffer support is desired for the receive side
 *			of data transfer, the UART interrupt should call this
 *			function for a receive based interrupt status.
 */
void UART_RXIntHandlerRB(LPC_USART_T *pUART, RINGBUFF_T *pRB);

/**
 * @brief	UART transmit-only interrupt handler for ring buffers
 * @param	pUART	: Pointer to selected UART peripheral
 * @param	pRB		: Pointer to ring buffer structure to use
 * @return	Nothing
 * @note	If ring buffer support is desired for the transmit side
 *			of data transfer, the UART interrupt should call this
 *			function for a transmit based interrupt status.
 */
void UART_TXIntHandlerRB(LPC_USART_T *pUART, RINGBUFF_T *pRB);

/**
 * @brief	Populate a transmit ring buffer and start UART transmit
 * @param	pUART	: Pointer to selected UART peripheral
 * @param	pRB		: Pointer to ring buffer structure to use
 * @param	data	: Pointer to buffer to move to ring buffer
 * @param	count	: Number of bytes to move
 * @return	The number of bytes placed into the ring buffer
 * @note	Will move the data into the TX ring buffer and start the
 *			transfer. If the number of bytes returned is less than the
 *			number of bytes to send, the ring buffer is considered full.
 */
uint32_t UART_SendRB(LPC_USART_T *pUART, RINGBUFF_T *pRB, const void *data, int count);

/**
 * @brief	Copy data from a receive ring buffer
 * @param	pUART	: Pointer to selected UART peripheral
 * @param	pRB		: Pointer to ring buffer structure to use
 * @param	data	: Pointer to buffer to fill from ring buffer
 * @param	bytes	: Size of the passed buffer in bytes
 * @return	The number of bytes placed into the ring buffer
 * @note	Will move the data from the RX ring buffer up to the
 *			the maximum passed buffer size. Returns 0 if there is
 *			no data in the ring buffer.
 */
int UART_ReadRB(LPC_USART_T *pUART, RINGBUFF_T *pRB, void *data, int bytes);

/**
 * @brief	UART receive/transmit interrupt handler for ring buffers
 * @param	pUART	: Pointer to selected UART peripheral
 * @param	pRXRB	: Pointer to transmit ring buffer
 * @param	pTXRB	: Pointer to receive ring buffer
 * @return	Nothing
 * @note	This provides a basic implementation of the UART IRQ
 *			handler for support of a ring buffer implementation for
 *			transmit and receive.
 */
void UART_IRQRBHandler(LPC_USART_T *pUART, RINGBUFF_T *pRXRB, RINGBUFF_T *pTXRB);

#endif