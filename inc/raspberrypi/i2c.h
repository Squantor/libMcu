/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file I2C peripheral definitions */
#ifndef I2C_H
#define I2C_H

typedef volatile struct {
  uint32_t IC_CON;                /**< I2C Control Register */
  uint32_t IC_TAR;                /**< I2C Target Address Register */
  uint32_t IC_SAR;                /**< I2C Slave Address Register */
  uint32_t reserved0[1];          /**< reserved */
  uint32_t IC_DATA_CMD;           /**< I2C Rx/Tx Data Buffer and Command Register */
  uint32_t IC_SS_SCL_HCNT;        /**< Standard Speed I2C Clock SCL High Count Register */
  uint32_t IC_SS_SCL_LCNT;        /**< Standard Speed I2C Clock SCL Low Count Register */
  uint32_t IC_FS_SCL_HCNT;        /**< Fast Mode/Plus I2C Clock SCL High Count Register */
  uint32_t IC_FS_SCL_LCNT;        /**< Fast Mode/Plus I2C Clock SCL Low Count Register */
  uint32_t reserved1[2];          /**< reserved */
  uint32_t IC_INTR_STAT;          /**< I2C Interrupt Status Register */
  uint32_t IC_INTR_MASK;          /**< I2C Interrupt Mask Register */
  uint32_t IC_RAW_INTR_STAT;      /**< I2C Raw Interrupt Status Register */
  uint32_t IC_RX_TL;              /**< I2C Receive FIFO Threshold Register */
  uint32_t IC_TX_TL;              /**< I2C Transmit FIFO Threshold Register */
  uint32_t IC_CLR_INTR;           /**< Clear Combined and Individual Interrupt Register */
  uint32_t IC_CLR_RX_UNDER;       /**< Clear RX_UNDER Interrupt Register */
  uint32_t IC_CLR_RX_OVER;        /**< Clear RX_OVER Interrupt Register */
  uint32_t IC_CLR_TX_OVER;        /**< Clear TX_OVER Interrupt Register */
  uint32_t IC_CLR_RD_REQ;         /**< Clear RD_REQ Interrupt Register */
  uint32_t IC_CLR_TX_ABRT;        /**< Clear TX_ABRT Interrupt Register */
  uint32_t IC_CLR_RX_DONE;        /**< Clear RX_DONE Interrupt Register */
  uint32_t IC_CLR_ACTIVITY;       /**< Clear ACTIVITY Interrupt Register */
  uint32_t IC_CLR_STOP_DET;       /**< Clear STOP_DET Interrupt Register */
  uint32_t IC_CLR_START_DET;      /**< Clear START_DET Interrupt Register */
  uint32_t IC_CLR_GEN_CALL;       /**< Clear GEN_CALL Interrupt Register */
  uint32_t IC_ENABLE;             /**< I2C ENABLE Register */
  uint32_t IC_STATUS;             /**< I2C STATUS Register */
  uint32_t IC_TXFLR;              /**< I2C Transmit FIFO Level Register */
  uint32_t IC_RXFLR;              /**< I2C Receive FIFO Level Register */
  uint32_t IC_SDA_HOLD;           /**< I2C SDA Hold Time Length Register */
  uint32_t IC_TX_ABRT_SOURCE;     /**< I2C Transmit Abort Source Register */
  uint32_t IC_SLV_DATA_NACK_ONLY; /**< Generate Slave Data NACK Register */
  uint32_t IC_DMA_CR;             /**< DMA Control Register */
  uint32_t IC_DMA_TDLR;           /**< DMA Transmit Data Level Register */
  uint32_t IC_DMA_RDLR;           /**< DMA Transmit Data Level Register */
  uint32_t IC_SDA_SETUP;          /**< I2C SDA Setup Register */
  uint32_t IC_ACK_GENERAL_CALL;   /**< I2C ACK General Call Register */
  uint32_t IC_ENABLE_STATUS;      /**< I2C Enable Status Register */
  uint32_t IC_FS_SPKLEN;          /**< I2C SS, FS or FM+ spike suppression limit */
  uint32_t reserved2[1];          /**< reserved */
  uint32_t IC_CLR_RESTART_DET;    /**< Clear RESTART_DET Interrupt Register */
  uint32_t reserved0[18];         /**< reserved */
  uint32_t IC_COMP_PARAM_1;       /**< Component Parameter Register 1 */
  uint32_t IC_COMP_VERSION;       /**< I2C Component Version Register */
  uint32_t IC_COMP_TYPE;          /**< I2C Component Type Register */
} I2C_Type;

#define IC_CON_MASTER_MODE_EN (1 << 0)      /**< Enable master mode */
#define IC_CON_SPEED(mode) (mode << 1)      /**< speed mode setting */
#define IC_CON_IC_10BITADDR_SLAVE (1 << 3)  /**< as a slave use 10 bit addresses */
#define IC_CON_IC_10BITADDR_MASTER (1 << 4) /**< as a master send 10 bit addresses */
#define IC_CON_IC_RESTART_EN (1 << 5)       /**< Determine if restarts can be sent */

#endif