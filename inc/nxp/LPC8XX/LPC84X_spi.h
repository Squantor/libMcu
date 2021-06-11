/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/* 
 * LPC84X series SPI registers, defines and functions.
 */
#ifndef LPC84X_SPI_H
#define LPC84X_SPI_H

/** SPI - Register Layout Typedef */
typedef volatile struct {
    uint32_t CFG;           /*!< SPI Configuration register, offset: 0x0 */
    uint32_t DLY;           /*!< SPI Delay register, offset: 0x4 */
    uint32_t STAT;          /*!< SPI Status. Some status flags can be cleared by writing a 1 to that bit position, offset: 0x8 */
    uint32_t INTENSET;      /*!< SPI Interrupt Enable read and Set. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set., offset: 0xC */
    uint32_t INTENCLR;      /*!< SPI Interrupt Enable Clear. Writing a 1 to any implemented bit position causes the corresponding bit in INTENSET to be cleared., offset: 0x10 */
    const uint32_t RXDAT;   /*!< SPI Receive Data, offset: 0x14 */
    uint32_t TXDATCTL;      /*!< SPI Transmit Data with Control, offset: 0x18 */
    uint32_t TXDAT;         /*!< SPI Transmit Data., offset: 0x1C */
    uint32_t TXCTL;         /*!< SPI Transmit Control, offset: 0x20 */
    uint32_t DIV;           /*!< SPI clock Divider, offset: 0x24 */
    const uint32_t INTSTAT; /*!< SPI Interrupt Status, offset: 0x28 */
} SPI_Type;

#define SPI_CFG_RESERVED    (0xFFFFF042)    /*!< SPI Configuration register reserved bits */
#define SPI_CFG_ENABLE      (1 << 0)        /*!< SPI enable */
#define SPI_CFG_MASTER      (1 << 2)        /*!< master mode */
#define SPI_CFG_SLAVE       (0 << 2)        /*!< slave mode */
#define SPI_CFG_LSBF        (1 << 3)        /*!< LSB First mode enable */
#define SPI_CFG_CPHA        (1 << 4)        /*!< Clock phase select */
#define SPI_CFG_CPOL        (1 << 5)        /*!< Clock polarity select */
#define SPI_CFG_LOOP        (1 << 7)        /*!< Loopback mode enable */
#define SPI_CFG_SPOL0       (1 << 8)        /*!< SSEL0 Polarity select */
#define SPI_CFG_SPOL1       (1 << 9)        /*!< SSEL1 Polarity select */
#define SPI_CFG_SPOL2       (1 << 10)       /*!< SSEL2 Polarity select */
#define SPI_CFG_SPOL3       (1 << 11)       /*!< SSEL3 Polarity select */

#define SPI_DLY_RESERVED        (0xFFFF0000)            /*!< SPI delay register reserved bits */
#define SPI_DLY_PRE(delay)      ((delay & 0xF) << 0)    /*!< delay between SSEL assertion and begin of transfer */
#define SPI_DLY_POST(delay)     ((delay & 0xF) << 4)    /*!< delay between end of transfer and SSEL deassertion */
#define SPI_DLY_FRAME(delay)    ((delay & 0xF) << 8)    /*!< delay between frames */
#define SPI_DLY_TRANSFER(delay) ((delay & 0xF) << 12)   /*!< delay between transfers and SSEL deassert and assert */

static inline void spiSetConfig(SPI_Type *peripheral, uint32_t config)
{
    peripheral->CFG = config & ~SPI_CFG_RESERVED;
} 

static inline void spiSetDelays(SPI_Type *peripheral, uint32_t delays)
{
    peripheral->DLY = delays;
}

#endif
