/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 I2C register interface
 */
#ifndef RP2040_I2C_HW_HPP
#define RP2040_I2C_HW_HPP

namespace libMcuLL::hw::i2c {
/**
 * @brief I2C register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t IC_CON;                /**< I2C Control Register */
  volatile std::uint32_t IC_TAR;                /**< I2C Target Address Register */
  volatile std::uint32_t IC_SAR;                /**< I2C Slave Address Register */
  volatile std::uint32_t reserved0[1];          /**< reserved */
  volatile std::uint32_t IC_DATA_CMD;           /**< I2C Rx/Tx Data Buffer and Command Register */
  volatile std::uint32_t IC_SS_SCL_HCNT;        /**< Standard Speed I2C Clock SCL High Count Register */
  volatile std::uint32_t IC_SS_SCL_LCNT;        /**< Standard Speed I2C Clock SCL Low Count Register */
  volatile std::uint32_t IC_FS_SCL_HCNT;        /**< Fast Mode/Plus I2C Clock SCL High Count Register */
  volatile std::uint32_t IC_FS_SCL_LCNT;        /**< Fast Mode/Plus I2C Clock SCL Low Count Register */
  volatile std::uint32_t reserved1[2];          /**< reserved */
  volatile std::uint32_t IC_INTR_STAT;          /**< I2C Interrupt Status Register */
  volatile std::uint32_t IC_INTR_MASK;          /**< I2C Interrupt Mask Register */
  volatile std::uint32_t IC_RAW_INTR_STAT;      /**< I2C Raw Interrupt Status Register */
  volatile std::uint32_t IC_RX_TL;              /**< I2C Receive FIFO Threshold Register */
  volatile std::uint32_t IC_TX_TL;              /**< I2C Transmit FIFO Threshold Register */
  volatile std::uint32_t IC_CLR_INTR;           /**< Clear Combined and Individual Interrupt Register */
  volatile std::uint32_t IC_CLR_RX_UNDER;       /**< Clear RX_UNDER Interrupt Register */
  volatile std::uint32_t IC_CLR_RX_OVER;        /**< Clear RX_OVER Interrupt Register */
  volatile std::uint32_t IC_CLR_TX_OVER;        /**< Clear TX_OVER Interrupt Register */
  volatile std::uint32_t IC_CLR_RD_REQ;         /**< Clear RD_REQ Interrupt Register */
  volatile std::uint32_t IC_CLR_TX_ABRT;        /**< Clear TX_ABRT Interrupt Register */
  volatile std::uint32_t IC_CLR_RX_DONE;        /**< Clear RX_DONE Interrupt Register */
  volatile std::uint32_t IC_CLR_ACTIVITY;       /**< Clear ACTIVITY Interrupt Register */
  volatile std::uint32_t IC_CLR_STOP_DET;       /**< Clear STOP_DET Interrupt Register */
  volatile std::uint32_t IC_CLR_START_DET;      /**< Clear START_DET Interrupt Register */
  volatile std::uint32_t IC_CLR_GEN_CALL;       /**< Clear GEN_CALL Interrupt Register */
  volatile std::uint32_t IC_ENABLE;             /**< I2C ENABLE Register */
  volatile std::uint32_t IC_STATUS;             /**< I2C STATUS Register */
  volatile std::uint32_t IC_TXFLR;              /**< I2C Transmit FIFO Level Register */
  volatile std::uint32_t IC_RXFLR;              /**< I2C Receive FIFO Level Register */
  volatile std::uint32_t IC_SDA_HOLD;           /**< I2C SDA Hold Time Length Register */
  volatile std::uint32_t IC_TX_ABRT_SOURCE;     /**< I2C Transmit Abort Source Register */
  volatile std::uint32_t IC_SLV_DATA_NACK_ONLY; /**< Generate Slave Data NACK Register */
  volatile std::uint32_t IC_DMA_CR;             /**< DMA Control Register */
  volatile std::uint32_t IC_DMA_TDLR;           /**< DMA Transmit Data Level Register */
  volatile std::uint32_t IC_DMA_RDLR;           /**< DMA Transmit Data Level Register */
  volatile std::uint32_t IC_SDA_SETUP;          /**< I2C SDA Setup Register */
  volatile std::uint32_t IC_ACK_GENERAL_CALL;   /**< I2C ACK General Call Register */
  volatile std::uint32_t IC_ENABLE_STATUS;      /**< I2C Enable Status Register */
  volatile std::uint32_t IC_FS_SPKLEN;          /**< I2C SS, FS or FM+ spike suppression limit */
  volatile std::uint32_t reserved2[1];          /**< reserved */
  volatile std::uint32_t IC_CLR_RESTART_DET;    /**< Clear RESTART_DET Interrupt Register */
  volatile std::uint32_t reserved3[18];         /**< reserved */
  volatile std::uint32_t IC_COMP_PARAM_1;       /**< Component Parameter Register 1 */
  volatile std::uint32_t IC_COMP_VERSION;       /**< I2C Component Version Register */
  volatile std::uint32_t IC_COMP_TYPE;          /**< I2C Component Type Register */
};
namespace IC_CON {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'07FFu};    /**< Mask for allowed bits */
constexpr inline std::uint32_t STOP_DET_MASTER_FLAG{1u << 10}; /**< Master issues STOP_DET interrupt */
constexpr inline std::uint32_t RX_FIFO_FULL_HOLD{1u << 9};     /**< If RX FIFO full, hold bus */
constexpr inline std::uint32_t TX_EMTPY_CTRL{1u << 8};         /**< TX_EMPTY interrupt setting */
constexpr inline std::uint32_t STOP_DET_IFADDRESSED{1u << 7};  /**< STOP_DET interrupt when addressed */
constexpr inline std::uint32_t IC_SLAVE_DISABLE{1u << 6};      /**< I2C slave mode disable */
constexpr inline std::uint32_t IC_RESTART_EN{1u << 5};         /**< Allow RESTART operations */
constexpr inline std::uint32_t IC_10BITADDR_MASTER{1u << 4};   /**< Enable 10 bit addressing */
constexpr inline std::uint32_t SPEED_STD{1u << 1};             /**< standard I2C speed setting */
constexpr inline std::uint32_t SPEED_FAST{2u << 1};            /**< fast mode I2C speed setting */
constexpr inline std::uint32_t SPEED_HIGH{3u << 1};            /**< high speed mode I2C speed setting */
constexpr inline std::uint32_t MASTER_MODE{1u << 0};           /**< Enable master mode */
}  // namespace IC_CON
namespace IC_TAR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'07FFu}; /**< Mask for allowed bits */
}  // namespace IC_TAR
namespace IC_SAR {
constexpr inline std::uint32_t RESERVED_MASK{0x0000'03FFu}; /**< Mask for allowed bits */
}  // namespace IC_SAR
namespace IC_DATA_CMD {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_DATA_CMD
namespace IC_SS_SCL_HCNT {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_SS_SCL_HCNT
namespace IC_SS_SCL_LCNT {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_SS_SCL_LCNT
namespace IC_FS_SCL_HCNT {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_FS_SCL_HCNT
namespace IC_FS_SCL_LCNT {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_FS_SCL_LCNT
namespace IC_INTR_STAT {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_INTR_STAT
namespace IC_INTR_MASK {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_INTR_MASK
namespace IC_RAW_INTR_STAT {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_RAW_INTR_STAT
namespace IC_RX_TL {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_RX_TL
namespace IC_TX_TL {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_TX_TL
namespace IC_CLR_INTR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_INTR
namespace IC_CLR_RX_UNDER {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_RX_UNDER
namespace IC_CLR_RX_OVER {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_RX_OVER
namespace IC_CLR_TX_OVER {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_TX_OVER
namespace IC_CLR_RD_REQ {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_RD_REQ
namespace IC_CLR_TX_ABRT {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_TX_ABRT
namespace IC_CLR_RX_DONE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_RX_DONE
namespace IC_CLR_ACTIVITY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_ACTIVITY
namespace IC_CLR_STOP_DET {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_STOP_DET
namespace IC_CLR_START_DET {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_START_DET
namespace IC_CLR_GEN_CALL {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_GEN_CALL
namespace IC_ENABLE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_ENABLE
namespace IC_STATUS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_STATUS
namespace IC_TXFLR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_TXFLR
namespace IC_SDA_HOLD {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_SDA_HOLD
namespace IC_TX_ABRT_SOURCE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_TX_ABRT_SOURCE
namespace IC_SLV_DATA_NACK_ONLY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_SLV_DATA_NACK_ONLY
namespace IC_DMA_CR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_DMA_CR
namespace IC_DMA_TDLR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_DMA_TDLR
namespace IC_DMA_RDLR {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_DMA_RDLR
namespace IC_SDA_SETUP {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_SDA_SETUP
namespace IC_ACK_GENERAL_CALL {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_ACK_GENERAL_CALL
namespace IC_ENABLE_STATUS {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_ENABLE_STATUS
namespace IC_FS_SPKLEN {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_FS_SPKLEN
namespace IC_CLR_RESTART_DET {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_CLR_RESTART_DET
namespace IC_COMP_PARAM_1 {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_COMP_PARAM_1
namespace IC_COMP_VERSION {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_COMP_VERSION
namespace IC_COMP_TYPE {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace IC_COMP_TYPE
}  // namespace libMcuLL::hw::i2c
#endif