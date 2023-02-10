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

#define SSPCR0_DSS(size) ((size) << 0)     /**< Data size select */
#define SSPCR0_DSS_MASK (0xF << 0)         /**< Data size select mask */
#define SSPCR0_FRF(format) ((format) << 4) /**< Frame format */
typedef enum {
  SSP_FORMAT_MOTOROLA = 0, /**< Motorola frame format */
  SSP_FORMAT_TI = 1,       /**< Texas instruments frame format */
  SSP_FORMAT_NATIONAL = 2, /**< National Microwire frame format */
} SSPCR0_FORMAT_Enum;
#define SSPCR0_PHASE(phase) ((phase) << 6) /**< SSP frame phasing in one go */
typedef enum {
  SSP_PHASE_SPH0_SPO0 = 0, /**< first edge data capture, clock idle low, motorola only */
  SSP_PHASE_SPH0_SPO1 = 1, /**< first edge data capture, clock idle high, motorola only */
  SSP_PHASE_SPH1_SPO0 = 2, /**< second edge data capture, clock idle low, motorola only */
  SSP_PHASE_SPH1_SPO1 = 3, /**< second edge data capture, clock idle high, motorola only */
  SSP_PHASE_NONE = 0,      /**< any other format */
} SSPCR0_PHASE_Enum;
#define SSPCR0_SPO (1 << 6)                  /**< SSPCLKOUT polarity */
#define SSPCR0_SPH (1 << 7)                  /**< SSPCLKOUT phase */
#define SSPCR0_SCR(divider) ((divider) << 8) /**< SSP clock divider */
#define SSPCR0_SCR_MASK (0xFF << 8)          /**< SSP clock divider mask */

#define SSPCR1_LBM_EN (1 << 0) /**< loopback mode enable */
#define SSPCR1_SSE (1 << 1)    /**< SSP enable */
#define SSPCR1_SLAVE (1 << 2)  /**< Slave mode */
#define SSPCR1_MASTER (0 << 2) /**< Master mode */
#define SSPCR1_SOD (1 << 3)    /**< Slave-mode output disable */

#define SSPDR_DATA_MASK (0xFFFF << 0) /**< transmit/receive Data mask */

#define SSPSR_TFE_MASK (1 << 0) /**< TX FIFO Empty mask, 0 is not empty, 1 is empty */
#define SSPSR_TNF_MASK (1 << 1) /**< TX FIFO not full mask, 0 is full, 1 is not full */
#define SSPSR_RNE_MASK (1 << 2) /**< RX FIFO not empty mask, 0 is empty, 1 is not empty */
#define SSPSR_RFF_MASK (1 << 3) /**< RX FIFO full mask, 0 is not full , 1 is full */
#define SSPSR_BSY_MASK (1 << 4) /**< SSP busy flag mask, 0 is idle, 1 is busy */

#define SSPCPSR_CPSDVSR (divider)((0xFF & (divider)) << 0) /**< Clock prescale divisor mask*/

#define SSPIMSC_RORIM (1 << 0) /**< Receive overrun interrupt mask */
#define SSPIMSC_RTIM (1 << 1)  /**< Receive timeout interrupt mask */
#define SSPIMSC_RXIM (1 << 2)  /**< Receive FIFO interrupt mask */
#define SSPIMSC_TXIM (1 << 3)  /**< Transmit FIFO interrupt mask */

#define SSPRIS_RORRIS (1 << 0) /**< Receive overrun raw interrupt state */
#define SSPRIS_RTRIS (1 << 1)  /**< Receive timeout raw interrupt state */
#define SSPRIS_RXRIS (1 << 2)  /**< Receive FIFO raw interrupt state */
#define SSPRIS_TXRIS (1 << 3)  /**< Transmit FIFO raw interrupt state */

#define SSPMIS_RORMIS (1 << 0) /**< masked receive overrun interrupt state */
#define SSPMIS_RTMIS (1 << 1)  /**< masked receive timeout interrupt state */
#define SSPMIS_RXMIS (1 << 2)  /**< masked receive FIFO interrupt state */
#define SSPMIS_TXMIS (1 << 3)  /**< masked transmit FIFO interrupt state */

#define SSPICR_RORIC (1 << 0) /**< Clears the Receive overrun interrupt */
#define SSPICR_RTIC (1 << 1)  /**< Clears the receive timeout interrupt */

#define SSPDMACR_RXDMAE (1 << 0) /**< Receive DMA enable*/
#define SSPDMACR_TXDMAE (1 << 1) /**< Transmit DMA enable*/

/**
 * @brief Setup SPI format, phasing etcetera
 *
 * @param peripheral  SPI peripheral to configure
 * @param format      SPI format
 * @param phasing     SPI phasing for motorola format
 * @param bitCount    amount of bits to transfer
 * @param bitRate     bitrate of SPI, divided by Peripheral clock speed
 * @return uint32_t   achieved bitrate
 */
static inline uint32_t spiSetup(SPI_Type *const peripheral, SSPCR0_FORMAT_Enum format, SSPCR0_PHASE_Enum phasing, uint8_t bitCount,
                                uint32_t bitRate) {
  uint32_t freq_in = FREQ_PERI;
  uint32_t prescale, postdiv;

  // Find smallest prescale value which puts output frequency in range of
  // post-divide. Prescale is an even number from 2 to 254 inclusive.
  for (prescale = 2; prescale <= 254; prescale += 2) {
    if (freq_in < (prescale + 2) * 256 * (uint64_t)bitRate)
      break;
  }

  // Find largest post-divide which makes output <= baudrate. Post-divide is
  // an integer in the range 1 to 256 inclusive.
  for (postdiv = 256; postdiv > 1; --postdiv) {
    if (freq_in / (prescale * (postdiv - 1)) > bitRate)
      break;
  }

  peripheral->SSPCPSR = prescale;
  peripheral->SSPCR0 = SSPCR0_DSS(bitCount) | SSPCR0_FRF(format) | SSPCR0_PHASE(phasing) | SSPCR0_SCR(postdiv - 1);

  return freq_in / (prescale * postdiv);
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

/**
 * @brief Space left in TX FIFO
 *
 * @param peripheral  SPI peripheral to check
 * @return uint32_t   0 for full, not 0 for not full
 */
static inline uint32_t spiTxFree(SPI_Type *const peripheral) {
  return peripheral->SSPSR & SSPSR_TNF_MASK;
}

/**
 * @brief data available in RX FIFO
 *
 * @param peripheral SPI peripheral to check
 * @return uint32_t  0 for not empty, not 0 for empty
 */
static inline uint32_t spiRxAvailable(SPI_Type *const peripheral) {
  return peripheral->SSPSR & SSPSR_RNE_MASK;
}

/**
 * @brief SPI busy
 *
 * @param peripheral SPI peripheral to check
 * @return uint32_t 0 for not busy, not 0 for busy
 */
static inline uint32_t spiBusy(SPI_Type *const peripheral) {
  return peripheral->SSPSR & SSPSR_RNE_MASK;
}

/**
 * @brief Read and Write byte buffers to SPI
 *
 * @param peripheral SPI peripheral to transmit and receive
 * @param src        source buffer to send
 * @param dst        destination buffer to receive
 * @param len        length of buffers
 */
static inline void spiTranceive8(SPI_Type *const peripheral, const uint8_t *src, uint8_t *dst, size_t len) {
  size_t rxRemaining = len, txRemaining = len;
  while (rxRemaining || txRemaining) {
    if (txRemaining && spiTxFree(peripheral) && rxRemaining < txRemaining + SSP_FIFO_DEPTH) {
      peripheral->SSPDR = (uint32_t)*src++;
      --txRemaining;
    }
    if (rxRemaining && spiRxAvailable(peripheral)) {
      *dst++ = (uint8_t)peripheral->SSPDR;
      --rxRemaining;
    }
  }
}

/**
 * @brief Read and Write variable bit size buffers to SPI
 *
 * @param peripheral SPI peripheral to transmit and receive
 * @param src        source buffer to send
 * @param dst        destination buffer to receive
 * @param len        amount of elements in buffer
 * @param bitCount   amount of bits per transfer
 */
static inline void spiTranceiveBits(SPI_Type *const peripheral, const uint16_t *src, uint16_t *dst, uint32_t len,
                                    uint32_t bitCount) {
  uint32_t rxRemaining = len, txRemaining = len;
  peripheral->SSPCR0 = (peripheral->SSPCR0 & ~SSPCR0_DSS_MASK) | SSPCR0_DSS(bitCount - 1);
  while (rxRemaining || txRemaining) {
    if (txRemaining && spiTxFree(peripheral) && rxRemaining < txRemaining + SSP_FIFO_DEPTH) {
      peripheral->SSPDR = (uint32_t)*src++;
      --txRemaining;
    }
    if (rxRemaining && spiRxAvailable(peripheral)) {
      *dst++ = (uint16_t)peripheral->SSPDR;
      --rxRemaining;
    }
  }
}

#endif