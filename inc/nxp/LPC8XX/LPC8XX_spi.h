/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
LPC800 series common Serial Peripheral Interface registers, defines
and functions.
*/
#ifndef LPC8XX_SPI_H
#define LPC8XX_SPI_H

/* SPI register block structure */
typedef volatile struct SPI_Struct {
  uint32_t CFG;           /* SPI Configuration register */
  uint32_t DLY;           /* SPI Delay register */
  uint32_t STAT;          /* SPI Status register */
  uint32_t INTENSET;      /* SPI Interrupt Enable Set register */
  uint32_t INTENCLR;      /* SPI Interrupt Enable Clear register */
  const uint32_t RXDAT;   /* SPI Receive Data register */
  uint32_t TXDATCTL;      /* SPI Transmit Data with Control register */
  uint32_t TXDAT;         /* SPI Transmit Data register */
  uint32_t TXCRL;         /* SPI Transmit Control register */
  uint32_t DIV;           /* SPI clock Divider register */
  const uint32_t INTSTAT; /* SPI Interrupt Status register */
} SPI_Type;

/* Reserved bits masks for registers */
#define SPI_CFG_RESERVED ((1 << 1) | (1 << 6) | 0xfffffe00)
#define SPI_DLY_RESERVED 0xffff0000
#define SPI_STAT_RESERVED (~0x1ff)
#define SPI_INTENSET_RESERVED (~0x3f)
#define SPI_INTENCLR_RESERVED (~0x3f)
#define SPI_RXDAT_RESERVED ((7 << 17) | (0x7ffu << 21))
#define SPI_TXDATCTL_RESERVED ((7 << 17) | (1 << 23) | (0xfu << 28))
#define SPI_TXDAT_RESERVED 0xffff0000
#define SPI_TXCTRL_RESERVED (0xffff | (7 << 17) | (1 << 23) | (0xfu << 28))
#define SPI_DIV_RESERVED 0xffff0000
#define SPI_INTSTAT_RESERVED (~0x3f)

/* Macro defines for SPI Configuration register */
#define SPI_CFG_BITMASK (0x1BD)                /*!< SPI register bit mask */
#define SPI_CFG_SPI_EN (1 << 0)                /*!< SPI Enable */
#define SPI_CFG_SPI_DIS (1 << 0)               /*!< SPI Disable */
#define SPI_CFG_SLAVE_EN (0 << 2)              /*!< SPI Slave mode */
#define SPI_CFG_MASTER_EN (1 << 2)             /*!< SPI Master mode */
#define SPI_CFG_MSB_FIRST_EN (0 << 3)          /*!< SPI MSB First mode */
#define SPI_CFG_LSB_FIRST_EN (1 << 3)          /*!< SPI LSB first mode */
#define SPI_CFG_CPHA0 (0 << 4)                 /*!< SPI Clock Polarity Change first*/
#define SPI_CFG_CPHA1 (1 << 4)                 /*!< SPI Clock Polarity Capture first*/
#define SPI_CFG_CPOL0 (0 << 5)                 /*!< SPI Clock idle low */
#define SPI_CFG_CPOL1 (1 << 5)                 /*!< SPI Clock idle high */
#define SPI_CFG_LOOP_DIS (0 << 7)              /*!< SPI Loopback disable */
#define SPI_CFG_LOOP_EN (1 << 7)               /*!< SPI Loopback enable */
#define SPI_CFG_SPOLNUM_HI(n) (1 << ((n) + 8)) /*!< SSELn is active High, selects 0 - 3 */

/* Macro defines for SPI Delay register */
#define SPI_DLY_BITMASK (0xFFFF) /*!< SPI DLY Register Mask */
#define SPI_DLY_PRE_DELAY(n)                                               \
  (((n)&0x0F) << 0) /*!< Time in SPI clocks between SSEL assertion and the \
                       beginning of a data frame */
#define SPI_DLY_POST_DELAY(n)                                                                            \
  (((n)&0x0F) << 4)                              /*!< Time in SPI clocks between the end of a data frame \
                                                    and SSEL deassertion. */
#define SPI_DLY_FRAME_DELAY(n) (((n)&0x0F) << 8) /*!< Minimum time in SPI clocks between adjacent data frames. */
#define SPI_DLY_TRANSFER_DELAY(n)                                     \
  (((n)&0x0F) << 12) /*!< Minimum time in SPI clocks that the SSEL is \
                        deasserted between transfers. */

/* Macro defines for SPI Status register */
#define SPI_STAT_BITMASK (0x1FF)  /* SPI STAT Register BitMask */
#define SPI_STAT_RXRDY (1 << 0)   /* Receiver Ready Flag */
#define SPI_STAT_TXRDY (1 << 1)   /* Transmitter Ready Flag */
#define SPI_STAT_RXOV (1 << 2)    /* Receiver Overrun interrupt flag */
#define SPI_STAT_TXUR (1 << 3)    /* Transmitter Underrun interrupt flag (In Slave Mode only) */
#define SPI_STAT_SSA (1 << 4)     /* Slave Select Assert */
#define SPI_STAT_SSD (1 << 5)     /* Slave Select Deassert */
#define SPI_STAT_STALLED (1 << 6) /* Stalled status flag */
#define SPI_STAT_EOT (1 << 7)     /* End Transfer flag */
#define SPI_STAT_MSTIDLE (1 << 8) /* Idle status flag */

/* Macro defines for SPI Interrupt Enable read and Set register */
#define SPI_INTENSET_BITMASK (0x3F)  /* SPI INTENSET Register BitMask */
#define SPI_INTENSET_RXDYEN (1 << 0) /* Enable Interrupt when receiver data is available */
#define SPI_INTENSET_TXDYEN                                                                       \
  (1 << 1)                           /* Enable Interrupt when the transmitter holding register is \
                                        available. */
#define SPI_INTENSET_RXOVEN (1 << 2) /*  Enable Interrupt when a receiver overrun occurs */
#define SPI_INTENSET_TXUREN                                                                           \
  (1 << 3)                          /*  Enable Interrupt when a transmitter underrun occurs (In Slave \
                                       Mode Only)*/
#define SPI_INTENSET_SSAEN (1 << 4) /*  Enable Interrupt when the Slave Select is asserted.*/
#define SPI_INTENSET_SSDEN (1 << 5) /*  Enable Interrupt when the Slave Select is deasserted..*/

/* Macro defines for SPI Interrupt Enable Clear register */
#define SPI_INTENCLR_BITMASK (0x3F)  /* SPI INTENCLR Register BitMask */
#define SPI_INTENCLR_RXDYEN (1 << 0) /* Disable Interrupt when receiver data is available */
#define SPI_INTENCLR_TXDYEN                                                                        \
  (1 << 1)                           /* Disable Interrupt when the transmitter holding register is \
                                        available. */
#define SPI_INTENCLR_RXOVEN (1 << 2) /* Disable Interrupt when a receiver overrun occurs */
#define SPI_INTENCLR_TXUREN                                                                           \
  (1 << 3)                          /* Disable Interrupt when a transmitter underrun occurs (In Slave \
                                       Mode Only) */
#define SPI_INTENCLR_SSAEN (1 << 4) /* Disable Interrupt when the Slave Select is asserted. */
#define SPI_INTENCLR_SSDEN (1 << 5) /* Disable Interrupt when the Slave Select is deasserted.. */

/* Macro defines for SPI Receiver Data register */
#define SPI_RXDAT_BITMASK (0x1FFFFF)   /* SPI RXDAT Register BitMask */
#define SPI_RXDAT_DATA(n) ((n)&0xFFFF) /* Receiver Data  */
#define SPI_RXDAT_RXSSELN_ACTIVE                                                                 \
  (0 << 16)                                                   /* The state of SSEL pin is active \
                                                               */
#define SPI_RXDAT_RXSSELN_INACTIVE  ((1 << 16)                /* The state of SSEL pin is inactive */
#define SPI_RXDAT_RXSSELNUM_INACTIVE(n) (1 << ((n) + 16))     /* The state of SSELN pin is inactive */
#define SPI_RXDAT_SOT (1 << 20)                               /* Start of Transfer flag  */

/*
 * Macro defines for SPI Transmitter Data and Control register
 */
#define SPI_TXDATCTL_BITMASK (0xF71FFFF)                                 /*!< SPI TXDATCTL Register BitMask */
#define SPI_TXDATCTL_DATA(n) ((n)&0xFFFF)                                /*!< SPI Transmit Data */
#define SPI_TXDATCTL_CTRLMASK (0xF710000)                                /*!< SPI TXDATCTL Register BitMask for control bits only */
#define SPI_TXDATCTL_ASSERTNUM_SSEL(n) (~(1 << ((n) + 16)) & 0x000F0000) /*!< Assert SSELN pin */
#define SPI_TXDATCTL_DEASSERTNUM_SSEL(n) (1 << ((n) + 16))               /*!< Deassert SSELN pin */
#define SPI_TXDATCTL_DEASSERT_ALL (0xF << 16)                            /*!< Deassert all SSEL pins */
#define SPI_TXDATCTL_EOT                                                       \
  (1 << 20) /*!< End of Transfer flag (TRANSFER_DELAY is applied after sending \
               the current frame) */
#define SPI_TXDATCTL_EOF                                                                                               \
  (1 << 21)                                           /*!< End of Frame flag (FRAME_DELAY is applied after sending the \
                                                         current part) */
#define SPI_TXDATCTL_RXIGNORE (1 << 22)               /*!< Receive Ignore Flag */
#define SPI_TXDATCTL_FLEN(n) ((((n)-1) & 0x0F) << 24) /*!< Frame length, 0 - 16 */

/* Macro defines for SPI Transmitter Data Register */
#define SPI_TXDAT_DATA(n) ((n)&0xFFFF) /* SPI Transmit Data */

/* Macro defines for SPI Transmitter Control register */
#define SPI_TXCTL_BITMASK (0xF7F0000)                                    /*!< SPI TXDATCTL Register BitMask */
#define SPI_TXDATCTL_ASSERTNUM_SSEL(n) (~(1 << ((n) + 16)) & 0x000F0000) /*!< Assert SSELN pin */
#define SPI_TXCTL_DEASSERTNUM_SSEL(n) (1 << ((n) + 16))                  /*!< Deassert SSELN pin */
#define SPI_TXDATCTL_DEASSERT_ALL (0xF << 16)                            /*!< Deassert all SSEL pins */
#define SPI_TXCTL_EOT                                                          \
  (1 << 20) /*!< End of Transfer flag (TRANSFER_DELAY is applied after sending \
               the current frame) */
#define SPI_TXCTL_EOF                                                                                 \
  (1 << 21)                          /*!< End of Frame flag (FRAME_DELAY is applied after sending the \
                                        current part) */
#define SPI_TXCTL_RXIGNORE (1 << 22) /*!< Receive Ignore Flag */
#define SPI_TXCTL_FLEN(n)                                        \
  ((((n)-1) & 0x0F) << 24)             /*!< Frame length, 0 - 16 \
                                        */
#define SPI_TXCTL_FLENMASK (0xF << 24) /*!< Frame length mask */

/* Macro defines for SPI Divider register */
#define SPI_DIV_VAL(n) ((n)&0xFFFF) /*!< Rate divider value mask (In Master Mode only)*/

/* Macro defines for SPI Interrupt Status register */
#define SPI_INTSTAT_BITMASK (0x3F) /* SPI INTSTAT Register Bitmask */
#define SPI_INTSTAT_RXRDY (1 << 0) /* Receiver Ready Flag */
#define SPI_INTSTAT_TXRDY (1 << 1) /* Transmitter Ready Flag */
#define SPI_INTSTAT_RXOV (1 << 2)  /* Receiver Overrun interrupt flag */
#define SPI_INTSTAT_TXUR (1 << 3)  /* Transmitter Underrun interrupt flag (In Slave Mode only) */
#define SPI_INTSTAT_SSA (1 << 4)   /* Slave Select Assert */
#define SPI_INTSTAT_SSD (1 << 5)   /* Slave Select Deassert */

/* SPI Clock Mode*/
#define SPI_CLOCK_CPHA0_CPOL0 (SPI_CFG_CPOL_LO | SPI_CFG_CPHA_FIRST) /*< CPHA = 0, CPOL = 0 */
#define SPI_CLOCK_MODE0 SPI_CLOCK_CPHA0_CPOL0                        /*< Alias for CPHA = 0, CPOL = 0 */
#define SPI_CLOCK_CPHA1_CPOL0 SPI_CFG_CPOL_LO | SPI_CFG_CPHA_SECOND  /*< CPHA = 0, CPOL = 1 */
#define SPI_CLOCK_MODE1 SPI_CLOCK_CPHA1_CPOL0                        /*< Alias for CPHA = 0, CPOL = 1 */
#define SPI_CLOCK_CPHA0_CPOL1 SPI_CFG_CPOL_HI | SPI_CFG_CPHA_FIRST   /*< CPHA = 1, CPOL = 0 */
#define SPI_CLOCK_MODE2 SPI_CLOCK_CPHA0_CPOL1                        /*< Alias for CPHA = 1, CPOL = 0 */
#define SPI_CLOCK_CPHA1_CPOL1 SPI_CFG_CPOL_HI | SPI_CFG_CPHA_SECOND  /*< CPHA = 1, CPOL = 1 */
#define SPI_CLOCK_MODE3 SPI_CLOCK_CPHA1_CPOL1                        /*< Alias for CPHA = 1, CPOL = 1 */

static inline void SpiSetCFGRegBits(SPI_Type *pSPI, uint32_t bits) {
  pSPI->CFG = bits | (pSPI->CFG & SPI_CFG_BITMASK);
}

static inline void SpiClearCFGRegBits(SPI_Type *pSPI, uint32_t bits) {
  pSPI->CFG = ~bits & (pSPI->CFG & SPI_CFG_BITMASK);
}

static inline void SpiEnable(SPI_Type *pSPI) {
  SpiSetCFGRegBits(pSPI, SPI_CFG_SPI_EN);
}

static inline void SpiEnableMasterMode(SPI_Type *pSPI) {
  SpiSetCFGRegBits(pSPI, SPI_CFG_MASTER_EN);

  /* Deassert all chip selects, only in master mode */
  pSPI->TXCRL = SPI_TXDATCTL_DEASSERT_ALL;
}

static inline void SpiEnableSlaveMode(SPI_Type *pSPI) {
  SpiClearCFGRegBits(pSPI, SPI_CFG_MASTER_EN);
}

static inline void SpiEnableLSBFirst(SPI_Type *pSPI) {
  SpiSetCFGRegBits(pSPI, SPI_CFG_LSB_FIRST_EN);
}

static inline void SpiEnableMSBFirst(SPI_Type *pSPI) {
  SpiClearCFGRegBits(pSPI, SPI_CFG_LSB_FIRST_EN);
}

static inline void SpiSetSPIMode(SPI_Type *pSPI, uint32_t mode) {
  SpiClearCFGRegBits(pSPI, (SPI_CFG_CPHA1 | SPI_CFG_CPOL1));
  SpiSetCFGRegBits(pSPI, (uint32_t)mode);
}

static inline void SpiSetCSPolHigh(SPI_Type *pSPI, uint8_t csNum) {
  SpiSetCFGRegBits(pSPI, SPI_CFG_SPOLNUM_HI(csNum));
}

static inline void SpiSetCSPolLow(SPI_Type *pSPI, uint8_t csNum) {
  SpiClearCFGRegBits(pSPI, SPI_CFG_SPOLNUM_HI(csNum));
}

static inline void SpiConfigureSPI(SPI_Type *pSPI, uint32_t config) {
  SpiClearCFGRegBits(pSPI, SPI_CFG_MASTER_EN | SPI_CFG_LSB_FIRST_EN | SPI_CFG_CPHA1 | SPI_CFG_CPOL1);
  SpiSetCFGRegBits(pSPI, config);

  /* Deassert all chip selects, only in master mode */
  pSPI->TXCRL = SPI_TXDATCTL_DEASSERT_ALL;
}

static inline uint32_t SpiGetStatus(SPI_Type *pSPI) {
  return pSPI->STAT & ~SPI_STAT_RESERVED;
}

static inline void SpiClearStatus(SPI_Type *pSPI, uint32_t Flag) {
  pSPI->STAT = Flag;
}

static inline void SpiEnableInts(SPI_Type *pSPI, uint32_t Flag) {
  pSPI->INTENSET = Flag;
}

static inline void SpiDisableInts(SPI_Type *pSPI, uint32_t Flag) {
  pSPI->INTENCLR = Flag;
}

static inline uint32_t SpiGetEnabledInts(SPI_Type *pSPI) {
  return pSPI->INTENSET & ~SPI_INTENSET_RESERVED;
}

static inline uint32_t SpiGetPendingInts(SPI_Type *pSPI) {
  return pSPI->INTSTAT & ~SPI_INTSTAT_RESERVED;
}

static inline uint32_t SpiReadRawRXFifo(SPI_Type *pSPI) {
  return pSPI->RXDAT & ~SPI_RXDAT_RESERVED;
}

static inline uint32_t SpiReadRXData(SPI_Type *pSPI) {
  return pSPI->RXDAT & 0xFFFF;
}

static inline void SpiWriteTXData(SPI_Type *pSPI, uint16_t data) {
  pSPI->TXDAT = (uint32_t)data;
}

/** \brief Spi transmit with additional control bits
 *  @param pSPI SPI peripheral instance
 *  @param control TXDATCTL bits
 *  @param data SPI data to transmit
 */
static inline void SpiWriteTXDataAndCtrl(SPI_Type *pSPI, uint32_t control, uint16_t data) {
  uint32_t reg = control | (uint32_t)data;
  pSPI->TXDATCTL = reg;
}

static inline void spiTxctrl(SPI_Type *pSPI, uint32_t bits) {
  pSPI->TXCRL = bits;
}

static inline void SpiSetTXCTRLRegBits(SPI_Type *pSPI, uint32_t bits) {
  pSPI->TXCRL = bits | (pSPI->TXCRL & SPI_TXDATCTL_CTRLMASK);
}

static inline void SpiClearTXCTRLRegBits(SPI_Type *pSPI, uint32_t bits) {
  pSPI->TXCRL = ~bits & (pSPI->TXCRL & SPI_TXDATCTL_CTRLMASK);
}

static inline void SpiSetTXCtl(SPI_Type *pSPI, uint32_t ctrlBits) {
  SpiSetTXCTRLRegBits(pSPI, ctrlBits);
}

static inline void SpiClearTXCtl(SPI_Type *pSPI, uint32_t ctrlBits) {
  SpiClearTXCTRLRegBits(pSPI, ctrlBits);
}

static inline void SpiSetXferSize(SPI_Type *pSPI, uint32_t ctrlBits) {
  SpiClearTXCTRLRegBits(pSPI, SPI_TXCTL_FLENMASK);
  SpiSetTXCTRLRegBits(pSPI, SPI_TXCTL_FLEN(ctrlBits));
}

static inline void SpiSetDivider(SPI_Type *pSPI, uint32_t dividerBits) {
  pSPI->DIV = dividerBits;
}

static inline void SpiSetDelay(SPI_Type *pSPI, uint32_t delayBits) {
  pSPI->DLY = delayBits;
}

#include "nxp/LPC8XX/LPC8XX_spi_old.h"

#endif