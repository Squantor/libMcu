/*
 * SPDX-License-Identifier: Unlicense
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/*
 * LPC84X series I2C registers, defines and functions.
 */
#ifndef LPC84X_I2C_H
#define LPC84X_I2C_H

/** I2C - Register Layout Typedef */
typedef volatile struct I2C_Struct {
  uint32_t CFG;            /*!< Configuration for shared functions., offset: 0x0 */
  uint32_t STAT;           /*!< Status register for Master, Slave, and Monitor functions., offset: 0x4 */
  uint32_t INTENSET;       /*!< Interrupt Enable Set and read register., offset: 0x8 */
  const uint32_t INTENCLR; /*!< Interrupt Enable Clear register., offset: 0xC */
  uint32_t TIMEOUT;        /*!< Time-out value register., offset: 0x10 */
  uint32_t CLKDIV;        /*!< Clock pre-divider for the entire I2C interface. This determines what time increments are used for the
                             MSTTIME register, and controls some timing of the Slave function., offset: 0x14 */
  const uint32_t INTSTAT; /*!< Interrupt Status register for Master, Slave, and Monitor functions., offset: 0x18 */
  uint8_t RESERVED_0[4];
  uint32_t MSTCTL;  /*!< Master control register., offset: 0x20 */
  uint32_t MSTTIME; /*!< Master timing configuration., offset: 0x24 */
  uint32_t MSTDAT;  /*!< Combined Master receiver and transmitter data register., offset: 0x28 */
  uint8_t RESERVED_1[20];
  uint32_t SLVCTL;    /*!< Slave control register., offset: 0x40 */
  uint32_t SLVDAT;    /*!< Combined Slave receiver and transmitter data register., offset: 0x44 */
  uint32_t SLVADR[4]; /*!< Slave address register., array offset: 0x48, array step: 0x4 */
  uint32_t SLVQUAL0;  /*!< Slave Qualification for address 0., offset: 0x58 */
  uint8_t RESERVED_2[36];
  const uint32_t MONRXDAT; /*!< Monitor receiver data register., offset: 0x80 */
} I2C_Type;

#define I2C_CFG_RESERVED (0xFFFFFFE0) /*!< I2C configuration register reserved bits */
#define I2C_CFG_MSTEN (1 << 0)        /*!< I2C Master enable */
#define I2C_CFG_SLVEN (1 << 1)        /*!< I2C Slave enable */
#define I2C_CFG_MONEN (1 << 2)        /*!< I2C Monitor enable */
#define I2C_CFG_TIMEOUTEN (1 << 3)    /*!< I2C Timeout enable */
#define I2C_CFG_MONCLKSTR (1 << 4)    /*!< I2C monitor clock stretching enable */

#define I2C_STAT_RESERVED (0xFCF000A0)                /*!< I2C status register reserved bits */
#define I2C_STAT_MSTPENDING (1 << 0)                  /*!< I2C Master pending or idle*/
#define I2C_STAT_MSTSTATE(status) (status & (7 << 1)) /*!< I2C Master status mask macro */
typedef enum {
  I2C_STAT_MSSTATE_IDLE = (0x0 << 1),           /*!< I2C master is in idle state */
  I2C_STAT_MSSTATE_RECEIVE_READY = (0x1 << 1),  /*!< I2C master has received data available */
  I2C_STAT_MSSTATE_TRANSMIT_READY = (0x2 << 1), /*!< I2C master can transmit data */
  I2C_STAT_MSSTATE_NACK_ADDRESS = (0x3 << 1),   /*!< I2C master did not get address acknowledged */
  I2C_STAT_MSSTATE_NACK_DATA = (0x4 << 1),      /*!< I2C master did not get data acknowledged */
} I2C_STAT_MSSTATE_Type;
#define I2C_STAT_MSTARBLOSS (1 << 4)                  /*!< Master lost arbitration */
#define I2C_STAT_MSTSTSTPERR (1 << 6)                 /*!< Master start stop error flag */
#define I2C_STAT_SLVPENDING (1 << 8)                  /*!< Slave pending */
#define I2C_STAT_SLVSTATE(status) (status & (3 << 9)) /*!< I2C Slave status mask macro */
typedef enum {
  I2C_STAT_SLVSTATE_ADDR = (0x0 << 9),     /*!< I2C slave address matched */
  I2C_STAT_SLVSTATE_RECEIVE = (0x1 << 9),  /*!< I2C slave has received data available */
  I2C_STAT_SLVSTATE_TRANSMIT = (0x2 << 9), /*!< I2C slave can transmit data */
} I2C_STAT_SLVSTATE_Type;
#define I2C_STAT_SLVNOTSTR (1 << 11)                 /*!< Slave not clock stretching */
#define I2C_STAT_SLVIDX(status) (status & (3 << 12)) /*!< Slave address match index */
typedef enum {
  I2C_STAT_SLVIDX_ADDR0 = (0x0 << 12), /*!< I2C slave address 0 matched */
  I2C_STAT_SLVIDX_ADDR1 = (0x1 << 12), /*!< I2C slave address 1 matched */
  I2C_STAT_SLVIDX_ADDR2 = (0x2 << 12), /*!< I2C slave address 2 matched */
  I2C_STAT_SLVIDX_ADDR3 = (0x3 << 12), /*!< I2C slave address 3 matched */
} I2C_STAT_SLVIDX_Type;
#define I2C_STAT_SLVSEL (1 << 14)       /*!< Slave selected flag */
#define I2C_STAT_SLVDESEL (1 << 15)     /*!< Slave deselected flag */
#define I2C_STAT_MONRDY (1 << 16)       /*!< Monitor ready flag*/
#define I2C_STAT_MONOV (1 << 17)        /*!< Monitor overflow flag */
#define I2C_STAT_MONACTIVE (1 << 18)    /*!< Monitor bus active flag */
#define I2C_STAT_MONIDLE (1 << 19)      /*!< Monitor bus idle flag */
#define I2C_STAT_EVENTTIMEOUT (1 << 24) /*!< Event timeout flag */
#define I2C_STAT_SCLTIMEOUT (1 << 25)   /*!< SCL timeout flag */

#define I2C_MSCTL_RESERVED (0xFFFFFFF0) /*!< I2C master data register reserved bits */
#define I2C_MSCTL_MSTCONTINUE (1 << 0)  /*!< I2C master continue to next operation */
#define I2C_MSCTL_MSTSTART (1 << 1)     /*!< I2C master generate start condition */
#define I2C_MSCTL_MSTSTOP (1 << 2)      /*!< I2C master generate stop condition */
#define I2C_MSCTL_MSTDMA (1 << 3)       /*!< I2C master DMA generation enable */

#define I2C_MSDAT_RESERVED (0xFFFFFF00) /*!< I2C master data register reserved bits */

#define I2C_CLKDIV_RESERVED (0xFFFF0000) /*!< I2C clock divide register reserved bits */

#define I2C_SLVCTL_RESERVED (0xFFFFFFF4) /*!< I2C slave control register reserved bits */
#define I2C_SLVCTL_SLVCONTINUE (1 << 0)  /*!< I2C slave continue operation */
#define I2C_SLVCTL_SLVNACK (1 << 1)      /*!< I2C slave not acknowledge */
#define I2C_SLVCTL_SLVDMA (1 << 3)       /*!< I2C slave DMA enable */

#define I2C_SLVADR_RESERVED (0xFFFFFF00) /*!< I2C slave address match register reserved bits */
#define I2C_SLVADR_IGNORE (1 << 0)       /*!< I2C slave adress match ignore flag */
typedef enum {
  I2C_SLVADR_0 = 0, /*!< I2C slave address match index 0 */
  I2C_SLVADR_1 = 1, /*!< I2C slave address match index 1 */
  I2C_SLVADR_2 = 2, /*!< I2C slave address match index 2 */
  I2C_SLVADR_3 = 3, /*!< I2C slave address match index 3 */
} I2C_SLVADR_INDEX_Type;

#define I2C_SLVDAT_RESERVED (0xFFFFFF00) /*!< I2C slave data register reserved bits */

/**
 * @brief   Set I2C configuration register
 * @param   peripheral  base address of I2C peripheral
 * @param   config      I2C peripheral global configuration
 */
static inline void i2cSetConfiguration(I2C_Type *peripheral, uint32_t config) {
  peripheral->CFG = config & ~I2C_CFG_RESERVED;
}

/**
 * @brief   Get I2C Status register
 * @param   peripheral  base address of I2C peripheral
 */
static inline uint32_t i2cGetStatus(I2C_Type *peripheral) {
  return peripheral->STAT & ~I2C_STAT_RESERVED;
}

/**
 * @brief   Set clock division ratio
 * @param   peripheral  base address of I2C peripheral
 * @param   divider     divider value, 0 is passthrough
 */
static inline void i2cSetClockDivider(I2C_Type *peripheral, uint32_t divider) {
  peripheral->CLKDIV = divider & ~I2C_CLKDIV_RESERVED;
}

/**
 * @brief   Set I2C master control register
 * @param   peripheral  base address of I2C peripheral
 * @param   control     control bits to set for master mode
 */
static inline void i2cSetMasterControl(I2C_Type *peripheral, uint32_t control) {
  peripheral->MSTCTL = control & ~I2C_MSCTL_RESERVED;
}

/**
 * @brief   Set I2C master data register
 * @param   peripheral  base address of I2C peripheral
 * @param   data        data to write to I2C master peripheral
 */
static inline void i2cSetMasterData(I2C_Type *peripheral, uint32_t data) {
  peripheral->MSTDAT = data & ~I2C_MSDAT_RESERVED;
}

/**
 * @brief   Get I2C master data register
 * @param   peripheral  base address of I2C peripheral
 */
static inline uint32_t i2cGetMasterData(I2C_Type *peripheral) {
  return peripheral->MSTDAT & ~I2C_MSDAT_RESERVED;
}

/**
 * @brief   Set I2C slave control register
 * @param   peripheral  base address of I2C peripheral
 * @param   control     control bits to set for slave mode
 */
static inline void i2cSetSlaveControl(I2C_Type *peripheral, uint32_t control) {
  peripheral->SLVCTL = control & ~I2C_SLVCTL_RESERVED;
}

/**
 * @brief   Set I2C slave data register
 * @param   peripheral  base address of I2C peripheral
 * @param   data        data to write to I2C slave peripheral
 */
static inline void i2cSetSlaveData(I2C_Type *peripheral, uint32_t data) {
  peripheral->SLVDAT = data & ~I2C_SLVDAT_RESERVED;
}

/**
 * @brief   Get I2C slave data register
 * @param   peripheral  base address of I2C peripheral
 */
static inline uint32_t i2cGetSlaveData(I2C_Type *peripheral) {
  return peripheral->SLVDAT & ~I2C_SLVDAT_RESERVED;
}

/**
 * @brief   Set I2C slave address match register
 * @param   peripheral  base address of I2C peripheral
 * @param   index       Which match register to set
 * @param   address     I2C address for the slave to respond to
 */
static inline void i2cSetSlaveAddress(I2C_Type *peripheral, I2C_SLVADR_INDEX_Type index, uint32_t address) {
  peripheral->SLVADR[index] = address & ~I2C_SLVADR_RESERVED;
}

#endif