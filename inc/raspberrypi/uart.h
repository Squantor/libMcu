/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file UART peripheral definitions
 * TODO: Add all bit defines
 */
#ifndef UART_H
#define UART_H

/**
 * @brief UART peripheral register definition
 *
 */
typedef volatile struct {
  uint32_t UARTDR;         /**< Data Register */
  uint32_t UARTRSR;        /**< Receive Status Register/Error Clear Register */
  uint32_t reserved0[4];   /**< reserved */
  uint32_t UARTFR;         /**< Flag Register */
  uint32_t reserved1[1];   /**< reserved */
  uint32_t UARTILPR;       /**< IrDA Low-Power Counter Register */
  uint32_t UARTIBRD;       /**< Integer Baud Rate Register */
  uint32_t UARTFBRD;       /**< Fractional Baud Rate Register */
  uint32_t UARTLCR_H;      /**< Line Control Register */
  uint32_t UARTCR;         /**< Control Register */
  uint32_t UARTIFLS;       /**< Interrupt FIFO Level Select */
  uint32_t UARTIMSC;       /**< Interrupt Mask Set/Clear */
  uint32_t UARTRIS;        /**< Raw Interrupt Status */
  uint32_t UARTMIS;        /**< Masked Interrupt Status */
  uint32_t UARTICR;        /**< Interrupt Clear Register */
  uint32_t UARTDMACR;      /**< DMA Control Register */
  uint32_t reserved2[997]; /**< */
  uint32_t UARTPERIPHID0;  /**< UARTPeriphID0 */
  uint32_t UARTPERIPHID1;  /**< UARTPeriphID1 */
  uint32_t UARTPERIPHID2;  /**< UARTPeriphID2 */
  uint32_t UARTPERIPHID3;  /**< UARTPeriphID3 */
  uint32_t UARTPCELLID0;   /**< UARTPCellID0 */
  uint32_t UARTPCELLID1;   /**< UARTPCellID1 */
  uint32_t UARTPCELLID2;   /**< UARTPCellID2 */
  uint32_t UARTPCELLID3;   /**< UARTPCellID3 */
} UART_Type;

#define UARTDR_OE_MASK (1 << 11)                /**< Overrun error */
#define UARTDR_BE_MASK (1 << 10)                /**< Break error */
#define UARTDR_PE_MASK (1 << 9)                 /**< Parity error */
#define UARTDR_FE_MASK (1 << 8)                 /**< Framing error */
#define UARTDR_DATA(register) (register & 0xFF) /**< get data from register */
#define UARTDR_DATA_MASK (0xFF << 0)            /**< Data character */

#define UARTRSR_OE_MASK (1 << 3) /**< Overrun error */
#define UARTRSR_BE_MASK (1 << 2) /**< Break error */
#define UARTRSR_PE_MASK (1 << 1) /**< Parity error */
#define UARTRSR_FE_MASK (1 << 0) /**< Framing error */

#define UARTFR_RI_MASK (1 << 8)   /**< Ring indicator */
#define UARTFR_TXFE_MASK (1 << 7) /**< Transmit FIFO empty */
#define UARTFR_RXFF_MASK (1 << 6) /**< Receive FIFO full */
#define UARTFR_TXFF_MASK (1 << 5) /**< Transmit FIFO full */
#define UARTFR_RXFE_MASK (1 << 4) /**< Receive FIFO empty */
#define UARTFR_BUSY_MASK (1 << 3) /**< UART Busy */
#define UARTFR_DCD_MASK (1 << 2)  /**< Data carrier detect */
#define UARTFR_DSR_MASK (1 << 1)  /**< Data set ready */
#define UARTFR_CTS_MASK (1 << 0)  /**< Clear to send */

#define UARTILPR_ILPDVSR(divider) (divider << 0) /**< IRDA low power divisor value */

#define UARTIBRD_BAUD_DIVINT(divider) (divider << 0) /**< Integer baud rate divisor */

#define UARTFBRD_BAUD_DIVFRAC(divider) (divider << 0) /**< Fractional baud rate divisor */

#define UARTLCR_H_SPS_EN (1 << 7)            /**< stick parity select */
#define UARTLCR_H_WLEN(length) (length << 5) /**< Word length */
typedef enum {
  UARTLCR_H_WLEN_5BIT = 0x0, /**< 5 bit UART words */
  UARTLCR_H_WLEN_6BIT = 0x1, /**< 6 bit UART words */
  UARTLCR_H_WLEN_7BIT = 0x2, /**< 7 bit UART words */
  UARTLCR_H_WLEN_8BIT = 0x3, /**< 8 bit UART words */
} UARTLCR_H_WLEN_Enum;
#define UARTLCR_H_FEN_EN (1 << 4)  /**< Enable fifos */
#define UARTLCR_H_STP2_EN (1 << 3) /**< Two stop bit select */
#define UARTLCR_H_EPS_EN (1 << 2)  /**< Even parity select */
#define UARTLCR_H_PEN_EN (1 << 1)  /**< Parity enable */
#define UARTLCR_H_BRK_EN (1 << 0)  /**< Send break */

#define UARTCR_CTSEN (1 << 15) /**< CTS Hardware flow enable */
#define UARTCR_RTSEN (1 << 14) /**< RTS Hardware flow enable */
#define UARTCR_OUT2 (1 << 13)  /**< complement of UART out2 status output */
#define UARTCR_OUT1 (1 << 12)  /**< complement of UART out1 status output */
#define UARTCR_RTS (1 << 11)   /**< complement of the UART RTS output */
#define UARTCR_DTR (1 << 10)   /**< complement of UART DTR ouput */
#define UARTCR_RXE (1 << 9)    /**< Receive Enable */
#define UARTCR_TXE (1 << 8)    /**< Transmit Enable */
#define UARTCR_LBE (1 << 7)    /**< Loopback enable */
#define UARTCR_SIRLP (1 << 2)  /**< SIR low power IrDA mode */
#define UARTCR_SIREN (1 << 1)  /**< SIR enable */
#define UARTCR_UARTEN (1 << 0) /**< UART enable */

#define UARTIFLS_RXIFLSEL(level) (level << 3) /**< Receive interrupt FIFO level select */
#define UARTIFLS_TXIFLSEL(level) (level << 0) /**< Tramsit interrupt FIFO level select */

#define UARTIMSC_OEIM (1 << 10)  /**< Overrun error interrupt mask */
#define UARTIMSC_BEIM (1 << 9)   /**< Break error interrupt mask */
#define UARTIMSC_PEIM (1 << 8)   /**< Parity error interrupt mask */
#define UARTIMSC_FEIM (1 << 7)   /**< Framing error interrupt mask */
#define UARTIMSC_RTIM (1 << 6)   /**< Receive timeout interrupt mask */
#define UARTIMSC_TXIM (1 << 5)   /**< Transmit interrupt mask */
#define UARTIMSC_RXIM (1 << 4)   /**< Receive interrupt mask */
#define UARTIMSC_DSRMIM (1 << 3) /**< UARTDSR modem interrupt mask */
#define UARTIMSC_DCDMIM (1 << 2) /**< UARTDCD modem interrupt mask */
#define UARTIMSC_CTSMIM (1 << 1) /**< UARTCTS modem interrupt mask */
#define UARTIMSC_RIMIM (1 << 0)  /**< UARTRI modem interrupt mask */

#define UARTDMACR_RXDMAE (1 << 0)   /**< Receive DMA enable */
#define UARTDMACR_TXDMAE (1 << 1)   /**< Transmit DMA enable */
#define UARTDMACR_DMAONERR (1 << 2) /**< DMA on error */

typedef enum {
  UART_5DATA_BITS = UARTLCR_H_WLEN_5BIT, /**< 5 data bits */
  UART_6DATA_BITS = UARTLCR_H_WLEN_6BIT, /**< 6 data bits */
  UART_7DATA_BITS = UARTLCR_H_WLEN_7BIT, /**< 7 data bits */
  UART_8DATA_BITS = UARTLCR_H_WLEN_8BIT, /**< 8 data bits */
} UART_DATA_BITS_Enum;

/**
 * @brief Stop bits allowed by uartSetFormat
 *
 */
typedef enum {
  UART_1STOP_BIT = 0, /**< One stop bit */
  UART_2STOP_BIT = 1, /**< Two stop bits */
} UART_STOP_Enum;

/**
 * @brief Parity settings allowed by uartSetFormat
 *
 */
typedef enum {
  UART_PARITY_NONE = 0, /**< No parity */
  UART_PARITY_EVEN = 1, /**< Even parity */
  UART_PARITY_ODD = 2,  /**< Odd parity */
} UART_PARITY_Enum;

/**
 * @brief Set the UART baud rate
 *
 * @param peripheral  UART peripheral to configure
 * @param baudrate    wanted baud rate
 * @return uint32_t   set baud rate, might differ from the wanted baud rate
 */
static inline uint32_t uartSetBaudRate(UART_Type *const peripheral, uint32_t baudrate) {
  UART_Type *peripheralSet = (UART_Type *)((char *)peripheral + OFFSET_SET);
  // we scale the clock to create a 24Q8 fixed point divider
  uint32_t divider = (8 * FREQ_PERI) / baudrate;
  uint32_t divInteger = divider >> 7;
  uint32_t divFract = ((divider & 0x7F) + 1) / 2;

  peripheral->UARTIBRD = divInteger;
  peripheral->UARTFBRD = divFract;

  // this dummy write is also done in the SDK
  // this is to latch the divisors
  peripheralSet->UARTLCR_H = 0;

  return (4 * FREQ_PERI) / (64 * divInteger + divFract);
}

/**
 * @brief Setup UART data format
 *
 * @param peripheral  UART peripheral to configure
 * @param bits        data bits in UART frame, see UART_DATA_BITS_Enum for options
 * @param stop        stop bits in UART frame, see UART_STOP_Enum for options
 * @param parity      parity setting in UART frame, see UART_PARITY_Enum for options
 */
static inline void uartSetFormat(UART_Type *const peripheral, UART_DATA_BITS_Enum bits, UART_STOP_Enum stop,
                                 UART_PARITY_Enum parity) {
  uint32_t settings = peripheral->UARTLCR_H;
  settings = settings & 0x91;  // Clear all not touched settings
  settings = settings | UARTLCR_H_WLEN(bits);
  if (stop == UART_2STOP_BIT)
    settings = settings | UARTLCR_H_STP2_EN;
  if (parity == UART_PARITY_EVEN)
    settings = settings | UARTLCR_H_PEN_EN | UARTLCR_H_EPS_EN;
  if (parity == UART_PARITY_ODD)
    settings = settings | UARTLCR_H_PEN_EN;
  peripheral->UARTLCR_H = settings;
}

/**
 * @brief Enable UART in its most common settings
 *
 * These settings should be fine for most use cases
 *
 * @param peripheral  UART peripheral to configure
 */
static inline void uartEnable(UART_Type *const peripheral) {
  UART_Type *peripheralSet = (UART_Type *)((char *)peripheral + OFFSET_SET);
  peripheral->UARTCR = UARTCR_UARTEN | UARTCR_TXE | UARTCR_RXE;
  peripheralSet->UARTLCR_H = UARTLCR_H_FEN_EN;
  // always enable DMA signals, harmless if DMA is not working
  peripheral->UARTDMACR = UARTDMACR_TXDMAE | UARTDMACR_RXDMAE;
}

/**
 * @brief are there received characters present?
 *
 * @param peripheral  UART peripheral to check
 * @return uint32_t   zero if there are characters available, non zero if not
 */
static inline uint32_t uartIsRxAvailable(UART_Type *const peripheral) {
  return (peripheral->UARTFR & UARTFR_RXFE_MASK);
}

/**
 * @brief blocking write to UART
 *
 * @param peripheral  UART peripheral to write to
 * @param src         buffer of data to send
 * @param len         number of bytes to send
 */
static inline void uartWriteBlocking(UART_Type *const peripheral, const uint8_t *src, size_t len) {
  for (size_t i = 0; i < len; ++i) {
    while (0 != (peripheral->UARTFR & UARTFR_TXFF_MASK))
      ;
    peripheral->UARTDR = *src++;
  }
}

/**
 * @brief blocking read from UART
 *
 * @param peripheral  UART peripheral to read from
 * @param dst         buffer to put data in
 * @param len         number of bytes to read
 */
static inline void uartReadBlocking(UART_Type *const peripheral, uint8_t *dst, size_t len) {
  for (size_t i = 0; i < len; ++i) {
    while (0 != (peripheral->UARTFR & UARTFR_RXFE_MASK))
      ;
    *dst++ = (uint8_t)peripheral->UARTDR;
  }
}

#endif