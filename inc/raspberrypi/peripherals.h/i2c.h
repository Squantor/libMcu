/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file I2C peripheral definitions
 * TODO: Add all bits to #defines
 */
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
  uint32_t reserved3[18];         /**< reserved */
  uint32_t IC_COMP_PARAM_1;       /**< Component Parameter Register 1 */
  uint32_t IC_COMP_VERSION;       /**< I2C Component Version Register */
  uint32_t IC_COMP_TYPE;          /**< I2C Component Type Register */
} I2C_Type;

#define IC_CON_STOP_DET_IF_MASTER_ACTIVE (1 << 10) /**< send STOP_DET interrupt if or not active*/
#define IC_CON_RX_FIFO_FULL_HLD_CTRL (1 << 9)      /**< hold bus if RX FIFO is full */
#define IC_CON_TX_EMPTY_CTRL (1 << 8)              /**< Controlled TX_EMPTY interrupt*/
#define IC_CON_STOP_DET_IFADRESSED (1 << 7)        /**< in slave mode send STOP_DET interrupt */
#define IC_CON_IC_SLAVE_DISABLE (1 << 6)           /**< Disable I2C slave */
#define IC_CON_IC_RESTART_EN (1 << 5)              /**< Determine if restarts can be sent */
#define IC_CON_IC_10BITADDR_MASTER (1 << 4)        /**< as a master send 10 bit addresses */
#define IC_CON_IC_10BITADDR_SLAVE (1 << 3)         /**< as a slave use 10 bit addresses */
#define IC_CON_SPEED(mode) ((mode) << 1)           /**< speed mode setting */
typedef enum {
  IC_CON_SPEED_STD = 0x1,       /**< standard mode */
  IC_CON_SPEED_FASTMODE = 0x2,  /**< Fast or fast mode plus */
  IC_CON_SPEED_HIGHSPEED = 0x3, /**< high speed mode */
} IC_CON_SPEED_Enum;
#define IC_CON_MASTER_MODE_EN (1 << 0) /**< Enable master mode */

#define IC_TAR_SPECIAL (1 << 11)                     /**< enable programming of general or start transmission */
#define IC_TAR_GC_OR_START (1 << 10)                 /**< start byte transmission */
#define IC_TAR_IC_TAR_MASK(address) ((address) << 0) /**< Target addres for master transmission */

#define IC_SAR_IC_SAR(address) ((address) << 0) /**< Holds slave address */

#define IC_DATA_CMD_FIRST_DATA_BYTE (1 << 11)         /**< non sequential data received */
#define IC_DATA_CMD_RESTART (1 << 10)                 /**< Issue RESTART before this command */
#define IC_DATA_CMD_STOP (1 << 9)                     /**< Issue STOP after this command */
#define IC_DATA_CMD_CMD_READ (1 << 8)                 /**< Master read command */
#define IC_DATA_CMD_CMD_WRITE (0 << 8)                /**< Master write command */
#define IC_DATA_CMD_DAT(register) ((register) & 0xFF) /**< get data from register */
#define IC_DATA_CMD_DAT_MASK (0xFF << 0)              /**< I2C data mask */

#define IC_ENABLE_TX_CMD_BLOCK (1 << 2) /**< block tranmsission on I2C bus with not empty TX FIFO*/
#define IC_ENABLE_ABORT (1 << 1)        /**< initiate Abort operation, autocleared */
#define IC_ENABLE_ENABLE (1 << 0)       /**< Enable I2C peripheral */

#define IC_STATUS_SLV_ACTIVITY (1 << 6)  /**< Slave FSM activity status, 1 not in IDLE state */
#define IC_STATUS_MST_ACTIVITY (1 << 5)  /**< Master FSM activity status, 1 not in IDLE state */
#define IC_STATUS_RFF_MASK (1 << 4)      /**< RX FIFO completely empty */
#define IC_STATUS_RFNE_MASK (1 << 3)     /**< RX FIFO not empty */
#define IC_STATUS_TFE_MASK (1 << 2)      /**< TX FIFO completely empty */
#define IC_STATUS_TFNF_MASK (1 << 1)     /**< TX FIFO not full  */
#define IC_STATUS_ACTIVITY_MASK (1 << 0) /**< I2C active, 1 means yes */

#define IC_SDA_HOLD_IC_SDA_RX_HOLD(clocks) ((clocks) << 16) /**< SDA RX hold time in ic_clk clocks */
#define IC_SDA_HOLD_IC_SDA_RX_HOLD_MASK (0xFF << 16)        /**< SDA RX hold time mask */
#define IC_SDA_HOLD_IC_SDA_TX_HOLD(clocks) ((clocks) << 0)  /**< SDA TX hold time in ic_clk clocks */
#define IC_SDA_HOLD_IC_SDA_TX_HOLD_MASK (0xFFFF)            /**< SDA TX hold time mask */

#define IC_DMA_CR_TDMAE (1 << 1) /**< Transmit DMA enable */
#define IC_DMA_CR_RDMAE (1 << 0) /**< Receive DMA enable */

/**
 * @brief Setup I2C peripheral as fast mode master
 *
 * @param peripheral  I2C peripheral to configure
 * @param speed       speed mode of peripheral, see IC_CON_SPEED_Enum for options
 * @param bitRate     bitrate of I2C peripheral in Hertz
 * @return uint32_t   actual bitrate of I2C peripheral, zero for error
 */
static inline uint32_t i2cSetupMaster(I2C_Type *const peripheral, IC_CON_SPEED_Enum speed, uint32_t bitRate) {
  // disable peripheral
  peripheral->IC_ENABLE = 0;
  // configure according to arguments
  peripheral->IC_CON =
    IC_CON_MASTER_MODE_EN | IC_CON_SPEED(speed) | IC_CON_IC_RESTART_EN | IC_CON_IC_SLAVE_DISABLE | IC_CON_TX_EMPTY_CTRL;
  // set watermarks to 1 to simplify handling
  peripheral->IC_TX_TL = 0;
  peripheral->IC_RX_TL = 0;
  // enable DREQ signaling, harmless without DMA
  peripheral->IC_DMA_CR = IC_DMA_CR_RDMAE | IC_DMA_CR_TDMAE;

  // set baudrate, taken from pico SDK
  // I2C is synchronous design that runs from clk_sys
  uint32_t frequencyInput = FREQ_CPU;

  // TODO there are some subtleties to I2C timing which we are completely ignoring here
  uint32_t period = (frequencyInput + bitRate / 2) / bitRate;
  uint32_t lcnt = period * 3 / 5;
  uint32_t hcnt = period - lcnt;

  // Per I2C-bus specification a device in standard or fast mode must
  // internally provide a hold time of at least 300ns for the SDA signal to
  // bridge the undefined region of the falling edge of SCL. A smaller hold
  // time of 120ns is used for fast mode plus.
  uint32_t sdaTxHoldCount;
  if (bitRate < 1000000) {
    // sdaTxHoldCount = frequencyInput [cycles/s] * 300ns * (1s / 1e9ns)
    // Reduce 300/1e9 to 3/1e7 to avoid numbers that don't fit in uint.
    // Add 1 to avoid division truncation.
    sdaTxHoldCount = ((frequencyInput * 3) / 10000000) + 1;
  } else {
    // sdaTxHoldCount = frequencyInput [cycles/s] * 120ns * (1s / 1e9ns)
    // Reduce 120/1e9 to 3/25e6 to avoid numbers that don't fit in uint.
    // Add 1 to avoid division truncation.
    sdaTxHoldCount = ((frequencyInput * 3) / 25000000) + 1;
  }

  // Always use "fast" mode (<= 400 kHz, works fine for standard mode too)
  peripheral->IC_FS_SCL_HCNT = hcnt;
  peripheral->IC_FS_SCL_LCNT = lcnt;
  peripheral->IC_FS_SPKLEN = lcnt < 16 ? 1 : lcnt / 16;

  peripheral->IC_SDA_HOLD =
    (peripheral->IC_SDA_HOLD & ~IC_SDA_HOLD_IC_SDA_TX_HOLD_MASK) | IC_SDA_HOLD_IC_SDA_TX_HOLD(sdaTxHoldCount);

  // enable
  peripheral->IC_ENABLE = IC_ENABLE_ENABLE;
  return frequencyInput / period;
}

#endif