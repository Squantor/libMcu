/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series SPI registers, defines and functions.
 */
#ifndef LPC84X_SPI_H
#define LPC84X_SPI_H

/** SPI - Register Layout Typedef */
typedef volatile struct SPI_Struct {
  uint32_t CFG;         /*!< SPI Configuration register, offset: 0x0 */
  uint32_t DLY;         /*!< SPI Delay register, offset: 0x4 */
  uint32_t STAT;        /*!< SPI Status. Some status flags can be cleared by writing a 1 to that bit position, offset: 0x8 */
  uint32_t INTENSET;    /*!< SPI Interrupt Enable read and Set. A complete value may be read from this register. Writing a 1 to any
                           implemented bit position causes that bit to be set., offset: 0xC */
  uint32_t INTENCLR;    /*!< SPI Interrupt Enable Clear. Writing a 1 to any implemented bit position causes the corresponding bit in
                           INTENSET to be cleared., offset: 0x10 */
  const uint32_t RXDAT; /*!< SPI Receive Data, offset: 0x14 */
  uint32_t TXDATCTL;    /*!< SPI Transmit Data with Control, offset: 0x18 */
  uint32_t TXDAT;       /*!< SPI Transmit Data., offset: 0x1C */
  uint32_t TXCTL;       /*!< SPI Transmit Control, offset: 0x20 */
  uint32_t DIV;         /*!< SPI clock Divider, offset: 0x24 */
  const uint32_t INTSTAT; /*!< SPI Interrupt Status, offset: 0x28 */
} SPI_Type;

#define SPI_CFG_RESERVED (0xFFFFF042) /*!< SPI Configuration register reserved bits */
#define SPI_CFG_ENABLE (1 << 0)       /*!< SPI enable */
#define SPI_CFG_MASTER (1 << 2)       /*!< master mode */
#define SPI_CFG_SLAVE (0 << 2)        /*!< slave mode */
#define SPI_CFG_LSBF (1 << 3)         /*!< LSB First mode enable */
#define SPI_CFG_CPHA (1 << 4)         /*!< Clock phase select */
#define SPI_CFG_CPOL (1 << 5)         /*!< Clock polarity select */
#define SPI_CFG_LOOP (1 << 7)         /*!< Loopback mode enable */
#define SPI_CFG_SPOL0 (1 << 8)        /*!< SSEL0 Polarity select */
#define SPI_CFG_SPOL1 (1 << 9)        /*!< SSEL1 Polarity select */
#define SPI_CFG_SPOL2 (1 << 10)       /*!< SSEL2 Polarity select */
#define SPI_CFG_SPOL3 (1 << 11)       /*!< SSEL3 Polarity select */

#define SPI_DLY_RESERVED (0xFFFF0000)                 /*!< SPI delay register reserved bits */
#define SPI_DLY_PRE(delay) ((delay & 0xF) << 0)       /*!< delay between SSEL assertion and begin of transfer */
#define SPI_DLY_POST(delay) ((delay & 0xF) << 4)      /*!< delay between end of transfer and SSEL deassertion */
#define SPI_DLY_FRAME(delay) ((delay & 0xF) << 8)     /*!< delay between frames */
#define SPI_DLY_TRANSFER(delay) ((delay & 0xF) << 12) /*!< delay between transfers and SSEL deassert and assert */

#define SPI_STAT_RESERVED (0xFFFFFE00) /*!< SPI status register reserved bits */
#define SPI_STAT_CLEAR (0x000000BC)    /*!< SPI status register write 1 to clear bits */
#define SPI_STAT_RXRDY (1 << 0)        /*!< Receiver ready flag */
#define SPI_STAT_TXRDY (1 << 1)        /*!< Transmitter ready flag */
#define SPI_STAT_RXOV (1 << 2)         /*!< Receiver Overrunt interrupt flag */
#define SPI_STAT_TXUR (1 << 3)         /*!< Transmitter underrun interrupt flag */
#define SPI_STAT_SSA (1 << 4)          /*!< Slave Select Assert */
#define SPI_STAT_SSD (1 << 5)          /*!< Slave Select Deassert */
#define SPI_STAT_STALLED (1 << 6)      /*!< Stalled status flag */
#define SPI_STAT_ENDTRANSFER (1 << 7)  /*!< End transfer control bit */
#define SPI_STAT_MSTIDLE (1 << 8)      /*!< Master idle status flag */

#define SPI_RXDAT_RESERVED (0x00000000)    /*!< SPI Receive data register reserved bits */
#define SPI_RXDAT_DATA(reg) (reg & 0xFFFF) /*!< extract data from RXDAT */
#define SPI_RXDAT_RXSSEL0_N (1 << 16)      /*!< Slave select 0 for receive inverted*/
#define SPI_RXDAT_RXSSEL1_N (1 << 17)      /*!< Slave select 1 for receive inverted*/
#define SPI_RXDAT_RXSSEL2_N (1 << 18)      /*!< Slave select 2 for receive inverted*/
#define SPI_RXDAT_RXSSEL3_N (1 << 19)      /*!< Slave select 3 for receive inverted*/
#define SPI_SOT (1 << 20)                  /*!< Start of transfer flag */

#define SPI_TXDATCTL_RESERVED (0xF0800000)          /*!< SPI Transmit data and control register reserved bits */
#define SPI_TXDATCTL_TXDAT(data) (data & 0xFFFF)    /*!< data to transmit */
#define SPI_TXDATCTL_TXSSEL0_N (1 << 16)            /*!< Transmit slave select 0 inverted */
#define SPI_TXDATCTL_TXSSEL0 (0xe << 16)            /*!< Transmit slave select 0 masked */
#define SPI_TXDATCTL_TXSSEL1_N (1 << 17)            /*!< Transmit slave select 1 inverted */
#define SPI_TXDATCTL_TXSSEL1 (0xd << 16)            /*!< Transmit slave select 1 masked */
#define SPI_TXDATCTL_TXSSEL2_N (1 << 18)            /*!< Transmit slave select 2 inverted */
#define SPI_TXDATCTL_TXSSEL2 (0xb << 16)            /*!< Transmit slave select 2 masked */
#define SPI_TXDATCTL_TXSSEL3_N (1 << 19)            /*!< Transmit slave select 3 inverted */
#define SPI_TXDATCTL_TXSSEL3 (0x7 << 16)            /*!< Transmit slave select 3 masked */
#define SPI_TXDATCTL_EOT (1 << 20)                  /*!< End of transfer */
#define SPI_TXDATCTL_EOF (1 << 21)                  /*!< End of Frame */
#define SPI_TXDATCTL_RXIGNORE (1 << 22)             /*!< Receive ignore */
#define SPI_TXDATCTL_LEN(n) (((n - 1) & 0xF) << 24) /*!< Data length */

#define SPI_TXDAT_RESERVED (0xFFFF0000)      /*!< SPI transmit data register reserved bits */
#define SPI_TXDA_TXDAT(data) (data & 0xFFFF) /*!< data to transmit */

#define SPI_TXCTL_RESERVED (0xF080FFFF)          /*!< SPI transmit control register reserved bits */
#define SPI_TXCTL_TXSSEL0_N (1 << 16)            /*!< Transmit slave select 0 inverted */
#define SPI_TXCTL_TXSSEL1_N (1 << 17)            /*!< Transmit slave select 1 inverted */
#define SPI_TXCTL_TXSSEL2_N (1 << 18)            /*!< Transmit slave select 2 inverted */
#define SPI_TXCTL_TXSSEL3_N (1 << 19)            /*!< Transmit slave select 3 inverted */
#define SPI_TXCTL_EOT (1 << 20)                  /*!< End of transfer */
#define SPI_TXCTL_EOF (1 << 21)                  /*!< End of Frame */
#define SPI_TXCTL_RXIGNORE (1 << 22)             /*!< Receive ignore */
#define SPI_TXCTL_LEN(n) (((n - 1) & 0xF) << 24) /*!< Data length */

#define SPI_DIV_RESERVED (0xFFFF0000) /*!< SPI clock divider register reserved bits */

/**
 * @brief   Setup the SPI configuration
 * @param   peripheral  base address of USART peripheral
 * @param   config      configuration bits to set, use the SPI_CFG defines for this
 */
static inline void spiSetConfig(SPI_Type *peripheral, uint32_t config) {
  peripheral->CFG = config & ~SPI_CFG_RESERVED;
}

/**
 * @brief   Setup the SPI delays
 * @param   peripheral  base address of USART peripheral
 * @param   delays      Values of delays, use the SPI_DLY_ defines for this
 */
static inline void spiSetDelays(SPI_Type *peripheral, uint32_t delays) {
  peripheral->DLY = delays;
}

/**
 * @brief   Set and get the SPI peripheral status
 * @param   peripheral  base address of USART peripheral
 * @param   statuses    Status bits to clear, use the SPI_STAT_ defines for this
 * @return  SPI status register
 */
static inline uint32_t spiSetGetStatus(SPI_Type *peripheral, uint32_t statuses) {
  peripheral->STAT = statuses & SPI_STAT_CLEAR;
  return peripheral->STAT;
}

/**
 * @brief   Get receiver data
 * @param   peripheral  base address of USART peripheral
 * @return  received SPI data
 */
static inline uint32_t spiGetRxData(SPI_Type *peripheral) {
  return peripheral->RXDAT;
}

/**
 * @brief   Set Transmit data and control
 * @param   peripheral  base address of USART peripheral
 * @param   transfer    Data and control information
 */
static inline void spiSetTxCtrlData(SPI_Type *peripheral, uint32_t transfer) {
  peripheral->TXDATCTL = transfer & ~SPI_TXDATCTL_RESERVED;
}

/**
 * @brief   Set Transmit data
 * @param   peripheral  base address of USART peripheral
 * @param   data        Data to transmit
 */
static inline void spiSetTxData(SPI_Type *peripheral, uint32_t data) {
  peripheral->TXDAT = data & ~SPI_TXDAT_RESERVED;
}

/**
 * @brief   Set Transmit control
 * @param   peripheral  base address of USART peripheral
 * @param   transfer    Data and control information
 */
static inline void spiSetTxCtl(SPI_Type *peripheral, uint32_t control) {
  peripheral->TXCTL = control & ~SPI_TXCTL_RESERVED;
}

/**
 * @brief   Set divider value
 * @param   peripheral  base address of USART peripheral
 * @param   divider     Rate divider value
 */
static inline void spiSetDivider(SPI_Type *peripheral, uint32_t divider) {
  peripheral->DIV = divider & ~SPI_DIV_RESERVED;
}

#endif
