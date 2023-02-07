/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file SPI peripheral definitions */
#ifndef SPI_H
#define SPI_H

typedef volatile struct {
  uint32_t SSPCR0;   /**< Control register 0 */
  uint32_t SSPCR1;   /**< Control register 1 */
  uint32_t SSPDR;    /**< Data register */
  uint32_t SSPSR;    /**< Status register */
  uint32_t SSPCPSR;  /**< Clock prescale register */
  uint32_t SSPIMSC;  /**< Interrupt mask set or clear register */
  uint32_t SSPRIS;   /**< Raw interrupt status register */
  uint32_t SSPMIS;   /**< Masked interrupt status register */
  uint32_t SSPICR;   /**< Interrupt clear register */
  uint32_t SSPDMACR; /**< DMA control register*/
  uint32_t reserved0[1006];
  uint32_t SSPPERIPID0; /**< Peripheral identification register 0 */
  uint32_t SSPPERIPID1; /**< Peripheral identification register 1 */
  uint32_t SSPPERIPID2; /**< Peripheral identification register 2 */
  uint32_t SSPPERIPID3; /**< Peripheral identification register 3 */
  uint32_t SSPPCELLID0; /**< PrimeCell identification register 0 */
  uint32_t SSPPCELLID1; /**< PrimeCell identification register 1 */
  uint32_t SSPPCELLID2; /**< PrimeCell identification register 2 */
  uint32_t SSPPCELLID3; /**< PrimeCell identification register 3 */
} SPI_Type;

#define SSP_FIFO_DEPTH (8u) /**< SSP FIFO depth */

#define SSPCR0_SCR_MASK (0xFF << 8)        /**< SSP clock divider mask */
#define SSPCR0_SCR(divider) (divider << 8) /**< SSP clock divider */
#define SSPCR0_SPH (1 << 7)                /**< SSPCLKOUT phase */
#define SSPCR0_SPO (1 << 6)                /**< SSPCLKOUT polarity */
#define SSPCR0_PHASE(phase) (phase << 6)   /**< SSP frame phasing in one go */
typedef enum {
  SSP_PHASE_SPH0_SPO0 = 0, /**< first edge data capture, clock idle low, motorola only */
  SSP_PHASE_SPH0_SPO1 = 1, /**< first edge data capture, clock idle high, motorola only */
  SSP_PHASE_SPH1_SPO0 = 2, /**< second edge data capture, clock idle low, motorola only */
  SSP_PHASE_SPH1_SPO1 = 3, /**< second edge data capture, clock idle high, motorola only */
  SSP_PHASE_NONE = 0,      /**< any other format */
} SSPCR0_PHASE_Enum;
#define SSPCR0_FRF(format) (format << 4) /**< Frame format */
typedef enum {
  SSP_FORMAT_MOTOROLA = 0, /**< Motorola frame format */
  SSP_FORMAT_TI = 1,       /**< Texas instruments frame format */
  SSP_FORMAT_NATIONAL = 2, /**< National Microwire frame format */
} SSPCR0_FORMAT_Enum;
#define SSPCR0_DSS(size) (size << 0) /**< Data size select */

#define SSPCR1_SOD (1 << 3)    /**< Slave-mode output disable */
#define SSPCR1_MASTER (0 << 2) /**< Master mode */
#define SSPCR1_SLAVE (1 << 2)  /**< Slave mode */
#define SSPCR1_SSE (1 << 1)    /**< SSP enable */
#define SSPCR1_LBM_EN (1 << 0) /**< loopback mode enable */

#define SSPDR_DATA_MASK (0xFFFF << 0) /**< transmit/receive Data mask */

#define SSPSR_BSY_MASK (1 << 4) /**< SSP busy flag mask, 0 is idle, 1 is busy */
#define SSPSR_RFF_MASK (1 << 3) /**< RX FIFO full mask, 0 is not full , 1 is full */
#define SSPSR_RNE_MASK (1 << 2) /**< RX FIFO not empty mask, 0 is empty, 1 is not empty */
#define SSPSR_TNF_MASK (1 << 1) /**< TX FIFO not full mask, 0 is full, 1 is not full */
#define SSPSR_TFE_MASK (1 << 0) /**< TX FIFO Empty mask, 0 is not empty, 1 is empty */

#define SSPCPSR_CPSDVSR_MASK (0xFF << 0) /**< Clock prescale divisor mask*/

#define SSPDMACR_TXDMAE (1 << 1) /**< Transmit DMA enable*/
#define SSPDMACR_RXDMAE (1 << 0) /**< Receive DMA enable*/

/**
 * @brief Setup SPI format, phasing etcetera
 *
 * @param peripheral  SPI peripheral to configure
 * @param format      SPI format
 * @param phasing     SPI phasing for motorola format
 * @param bitCount    amount of bits to transfer
 * @param bitRate     bitrate of SPI, divided by Peripheral clock speed
 */
static inline void spiSetup(SPI_Type *const peripheral, SSPCR0_FORMAT_Enum format, SSPCR0_PHASE_Enum phasing, uint8_t bitCount,
                            uint32_t bitRate) {
  // TODO change bitrate computation to use prescaler and SCR combined, see SDK for more info
  uint32_t divider = FREQ_PERI / bitRate;
  peripheral->SSPCR0 = SSPCR0_DSS(bitCount) | SSPCR0_FRF(format) | SSPCR0_PHASE(phasing) | SSPCR0_SCR(divider);
}

/**
 * @brief Enable SPI
 *
 * @param peripheral  SPI peripheral to enable
 * @param slaveMode   set to true for slave mode
 */
static inline void spiEnable(SPI_Type *const peripheral, bool slaveMode) {
  uint32_t ctrlReg = SSPCR1_SSE;
  if (slaveMode)
    ctrlReg |= SSPCR1_SLAVE;
  peripheral->SSPDMACR = SSPDMACR_TXDMAE | SSPDMACR_RXDMAE;  // enable DMA, no problem if DMA is not listening
  peripheral->SSPCR1 = ctrlReg;
  return;
}

static inline void spiTranceive8(SPI_Type *const peripheral, const uint8_t *src, const uint8_t *dest, size_t len) {
  size_t rxRemaining = SSP_FIFO_DEPTH, txRemaining = SSP_FIFO_DEPTH;
  while (rxRemaining || txRemaining) {
    /*
    if (txRemaining && cspi_is_writable(spi) && rx_remaining < tx_remaining + fifo_depth) {
      spi_get_hw(spi)->dr = (uint32_t)*src++;
      --tx_remaining;
    }
    if (rx_remaining && spi_is_readable(spi)) {
      *dst++ = (uint16_t)spi_get_hw(spi)->dr;
      --rx_remaining;
    }
    */
  }
}

#endif