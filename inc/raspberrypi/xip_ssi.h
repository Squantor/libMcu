/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file XIP SSI peripheral definitions */
#ifndef XIP_SSI_H
#define XIP_SSI_H

typedef volatile struct {
  uint32_t CTRLR0;               /**< Control register 0 */
  uint32_t CTRLR1;               /**< Master control register 1 */
  uint32_t SSIENR;               /**< SSI Enable */
  uint32_t MWCR;                 /**< Microwire Control*/
  uint32_t SER;                  /**< Slave enable*/
  uint32_t BAUDR;                /**< Baud rate */
  const uint32_t TXFTLR;         /**< TX FIFO threshold level */
  const uint32_t RXFTLR;         /**< RX FIFO threshold level */
  const uint32_t SR;             /**< Status register */
  uint32_t IMR;                  /**< Interrupt mask */
  const uint32_t ISR;            /**< Interrupt status */
  const uint32_t RISR;           /**< Raw interrupt status */
  const uint32_t TXOICR;         /**< TX FIFO overflow interrupt clear */
  const uint32_t RXOICR;         /**< RX FIFO overflow interrupt clear */
  const uint32_t RXUICR;         /**< RX FIFO underflow interrupt clear */
  const uint32_t MSTICR;         /**< Multi-master interrupt clear */
  const uint32_t ICR;            /**< interrupt clear */
  uint32_t DMACR;                /**< DMA control */
  uint32_t DMATDLR;              /**< DMA TX data level */
  uint32_t DMARDLR;              /**< DMA RX data level */
  const uint32_t IDR;            /**< Identification register */
  const uint32_t SSI_VERSION_ID; /**< Version ID */
  uint32_t DR[36];               /**< Dataregister */
  uint32_t RX_SAMPLE_DLY;        /**< RX sample delay */
  uint32_t SPI_CTRLR0;           /**< SPI control */
  uint32_t TXD_DRIVE_EDGE;       /**< TX drive edge */
} XIP_SSI_Type;

#define XIP_SSI_CTRLR0_RESERVED (0xFE800000) /**< CTRL0 reseved bits */

#define XIP_SSI_CTRLR0_DFS(size) (((size)&0x0F) << 0)     /**< Data frame size, not applicable in XIP SSI */
#define XIP_SSI_CTRLR0_FRF(format) (((format)&0x03) << 4) /**< Frame format, not applicable in XIP SSI */
/**
 * @brief normal SPI format modes, not applicable in XIP SSI
 */
typedef enum {
  XIP_SSI_CTRLR0_FRF_MOTOROLA = (0x0), /**< Motorola format, not applicable in XIP SSI */
  XIP_SSI_CTRLR0_FRF_TEXAS = (0x1),    /**< Texas instruments format, not applicable in XIP SSI */
  XIP_SSI_CTRLR0_FRF_NATIONAL = (0x2), /**< National Microwire format, not applicable in XIP SSI */

} XIP_SSI_CTRLR0_FRF_Enum;
#define XIP_SSI_CTRLR0_SCPH_EN (0x1 << 6)              /**< Motorola CLKOUT Polarity enable, not applicable in XIP SSI */
#define XIP_SSI_CTRLR0_SCPH_DIS (0x0 << 6)             /**< Motorola CLKOUT Polarity disable, not applicable in XIP SSI */
#define XIP_SSI_CTRLR0_SCPOL_EN (0x1 << 7)             /**< Motorola Phase Polarity enable, not applicable in XIP SSI */
#define XIP_SSI_CTRLR0_SCPOL_DIS (0x0 << 7)            /**< Motorola Phase Polarity disable, not applicable in XIP SSI */
#define XIP_SSI_CTRLR0_TMOD(mode) (((mode)&0x03) << 8) /**< transfer mode */
/**
 * @brief XIP SSI transfer modes
 */
typedef enum {
  XIP_SSI_CTRL0_TMOD_TX_AND_RX = (0x0), /**< Both transmit and receive */
  XIP_SSI_CTRL0_TMOD_TX_ONLY = (0x1),   /**< Transmit only (not for FRF = 0, standard SPI mode) */
  XIP_SSI_CTRL0_TMOD_RX_ONLY = (0x2),   /**< Receive only (not for FRF = 0, standard SPI mode) */
  XIP_SSI_CTRL0_TMOD_EEPROM = (0x3),    /**< EEPROM read mode (TX then RX) */
} XIP_SSI_CTRL0_FRF_Enum;
#define XIP_SSI_CTRLR0_SLV_OE_EN (0x1 << 10)  /**< Slave output enable */
#define XIP_SSI_CTRLR0_SLV_OE_DIS (0x0 << 10) /**< Slave output disable */

#define XIP_SSI_CTRLR0_SRL_EN (0x1 << 11)  /**< Shift register loop (test mode) enable */
#define XIP_SSI_CTRLR0_SRL_DIS (0x0 << 11) /**< Shift register loop (test mode) disable */

#define XIP_SSI_CTRLR0_CFS(size) (((size)&0x0F) << 12) /**< Control frame size, n is n+1 clock per frame */

#define XIP_SSI_CTRLR0_DFS_32(size) (((size)&0x01F) << 16) /**< Data frame size in 32b mode, n is n+1 clock per frame */

#define XIP_SSI_CTRLR0_SPI_FRF(mode) (((mode)&0x03) << 21) /**< transfer mode */
/**
 * @brief XIP SSI frame format modes
 */
typedef enum {
  XIP_SSI_CTRL0_SPI_FRF_1BIT = (0x0), /**< Standard 1-bit SPI frame format; 1 bit per SCK, full-duplex */
  XIP_SSI_CTRL0_SPI_FRF_DUAL = (0x1), /**< Dual-SPI frame format; two bits per SCK, half-duplex */
  XIP_SSI_CTRL0_SPI_FRF_QUAD = (0x2), /**< Quad-SPI frame format; four bits per SCK, half-duplex */
} XIP_SSI_CTRL0_SPI_FRF_Enum;

#define XIP_SSI_CTRLR0_SSTE_EN (0x1 << 24)  /**< Slave select toggle enable */
#define XIP_SSI_CTRLR0_SSTE_DIS (0x0 << 24) /**< Slave select toggle disable */

#define XIP_SSI_CTRLR1_RESERVED (0xFFFF0000)            /**< CTRL1 reseved bits */
#define XIP_SSI_CTRLR1_NDF(size) (((size)&0xFFFF) << 0) /**< Number of data frames */

#define XIP_SSI_SSIENR_RESERVED (0xFFFFFFFE) /**< SSI enable reserved bits */
#define XIP_SSI_SSIENR_EN (0x1 << 0)         /**< SSI enable bit */
#define XIP_SSI_SSIENR_DIS (0x0 << 0)        /**< SSI disable bit */

#define XIP_SSI_BAUDR_RESERVED (0xFFFF0000) /**< SSI baud rate reserved bits */

#define XIP_SSI_SPI_CTRLR0_RESERVED (0x00F804C0) /**< SPI control reserved bits */

#define XIP_SSI_SPI_CTRLR0_TRANS_TYPE(mode) (((mode)&0x03) << 0) /**< transfer format */
/**
 * @brief Address and instruction transfer formats
 */
typedef enum {
  XIP_SSI_SPI_CTRLR0_TRANS_TYPE_STD_BOTH = (0x0), /**< Command and address in standard SPI frame format */
  XIP_SSI_SPI_CTRLR0_TRANS_TYPE_FRF_ADDR = (0x1), /**< Command standard SPI format, address FRF specified format */
  XIP_SSI_SPI_CTRLR0_TRANS_TYPE_FRF_BOTH = (0x2), /**< Command and address FRF specified format */
} XIP_SSI_SPI_CTRLR0_TRANS_TYPE_Enum;

#define XIP_SSI_SPI_CTRLR0_ADDR_L(size) (((size)&0x0F) << 2) /**< Address length (0b-60b in 4b increments) */

#define XIP_SSI_SPI_CTRLR0_INST_L(mode) (((mode)&0x03) << 8) /**< Instruction length (0/4/8/16b) */
/**
 * @brief Address and instruction transfer formats
 */
typedef enum {
  XIP_SSI_SPI_CTRLR0_INST_L_NO_INSTR = (0x0),  /**< No instruction */
  XIP_SSI_SPI_CTRLR0_INST_L_4B_INSTR = (0x1),  /**< 4-bit instruction */
  XIP_SSI_SPI_CTRLR0_INST_L_8B_INSTR = (0x2),  /**< 8-bit instruction */
  XIP_SSI_SPI_CTRLR0_INST_L_16B_INSTR = (0x3), /**< 16-bit instruction */
} XIP_SSI_SPI_CTRLR0_INST_L_Enum;

#define XIP_SSI_SPI_CTRLR0_WAIT_CYCLES(cycles) (((cycles)&0x1F) << 11) /**< SCLK cycles between control and data reception */

#define XIP_SSI_SPI_CTRLR0_SPI_DDR_EN (0x1 << 16)  /**< SPI DDR transfer enable */
#define XIP_SSI_SPI_CTRLR0_SPI_DDR_DIS (0x0 << 16) /**< SPI DDR transfer disable */

#define XIP_SSI_SPI_CTRLR0_INST_DDR_EN (0x1 << 17)  /**< Instruction DDR transfer enable */
#define XIP_SSI_SPI_CTRLR0_INST_DDR_DIS (0x0 << 17) /**< Instruction DDR transfer disable */

#define XIP_SSI_SPI_CTRLR0_SPI_RXDS_EN (0x1 << 18)  /**< Read data strobe enable */
#define XIP_SSI_SPI_CTRLR0_SPI_RXDS_DIS (0x0 << 18) /**< Read data strobe disable */

#define XIP_SSI_SPI_CTRLR0_SPI_XIP_CMD(command) (((command)&0xFF) << 24) /**< SPI Command for XIP mode */

/**
 * @brief TODO
 *
 * @param peripheral  XIP SSI peripheral
 * @param settings
 */
static inline void xipssiCtrlr0(XIP_SSI_Type* const peripheral, uint32_t settings) {
  peripheral->CTRLR0 = ~XIP_SSI_CTRLR0_RESERVED & settings;
}

/**
 * @brief TODO
 *
 * @param peripheral  XIP SSI peripheral
 * @param settings
 */
static inline void xipssiCtrlr1(XIP_SSI_Type* const peripheral, uint32_t settings) {
  peripheral->CTRLR1 = ~XIP_SSI_CTRLR1_RESERVED & settings;
}

/**
 * @brief enable/disable XIP SSI
 *
 * @param peripheral  XIP SSI peripheral
 * @param enabled     state of peripheral
 */
static inline void xipssiEnable(XIP_SSI_Type* const peripheral, bool enabled) {
  if (enabled)
    peripheral->SSIENR = XIP_SSI_SSIENR_EN;
  else
    peripheral->SSIENR = XIP_SSI_SSIENR_DIS;
}

/**
 * @brief
 *
 * @param peripheral  XIP SSI peripheral
 * @param baudrate    baudrate (TODO how to compute)
 */
static inline void xipssiBaudrate(XIP_SSI_Type* const peripheral, uint32_t baudrate) {
  peripheral->BAUDR = ~XIP_SSI_BAUDR_RESERVED & baudrate;
}

/**
 * @brief TODO
 *
 * @param peripheral  XIP SSI peripheral
 * @param settings
 */
static inline void xipssiSpictrl0(XIP_SSI_Type* const peripheral, uint32_t settings) {
  peripheral->SPI_CTRLR0 = ~XIP_SSI_SPI_CTRLR0_RESERVED & settings;
}

#endif