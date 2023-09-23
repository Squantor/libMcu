/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series I2C bus register interface
 */
#ifndef LPC81X_I2C_REGS_HPP
#define LPC81X_I2C_REGS_HPP

namespace registers {
namespace i2c {

/**
 * @brief I2C bus register definitions
 *
 */
struct registers {
  volatile uint32_t CFG;                /**< Configuration for shared functions */
  volatile uint32_t STAT;               /**< Status register for Master, Slave, and Monitor functions */
  volatile uint32_t INTENSET;           /**< Interrupt Enable Set and read register */
  volatile uint32_t INTENCLR;           /**< Interrupt Enable Clear register */
  volatile uint32_t TIMEOUT;            /**< Time-out value register */
  volatile uint32_t CLKDIV;             /**< Clock pre-divider for the entire I2C interface */
  volatile const uint32_t INTSTAT;      /**< Interrupt Status register for Master, Slave, and Monitor functions */
  volatile const uint32_t RESERVED0;    /**< reserved */
  volatile uint32_t MSTCTL;             /**< Master control register */
  volatile uint32_t MSTTIME;            /**< Master timing configuration */
  volatile uint32_t MSTDAT;             /**< Combined Master receiver and transmitter data register */
  volatile const uint32_t RESERVED1[5]; /**< reserved */
  volatile uint32_t SLVCTL;             /**< Slave control register */
  volatile uint32_t SLVDAT;             /**< Combined Slave receiver and transmitter data register */
  volatile uint32_t SLVADR[4];          /**< Slave address register */
  volatile uint32_t SLVQUAL0;           /**< Slave Qualification for address 0 */
  volatile const uint32_t RESERVED2[9]; /**< reserved */
  volatile const uint32_t MONRXDAT;     /**< Monitor receiver data register */
};
namespace CFG {
constexpr inline uint32_t MASK = 0x0000001F;    /**< register mask for allowed bits */
constexpr inline uint32_t MSTEN = (1 << 0);     /**< Master Enable*/
constexpr inline uint32_t SLVEN = (1 << 1);     /**< Slave enable */
constexpr inline uint32_t MONEN = (1 << 2);     /**< Monitor enable */
constexpr inline uint32_t TIMEOUTEN = (1 << 3); /**< I2C timeout enable */
constexpr inline uint32_t MONCLKSTR = (1 << 4); /**< Monitor clock stretching enable */
}  // namespace CFG
namespace STAT {
constexpr inline uint32_t MASK = 0x030FFF5F;             /**< register mask for allowed bits */
constexpr inline uint32_t MSTPENDING = (1 << 0);         /**< Master Enable*/
constexpr inline uint32_t MSTSTATE_MASK = (0x7 << 1);    /**< Master State mask*/
constexpr inline uint32_t MSTSTATE_IDLE = (0 << 1);      /**< Master Idle state */
constexpr inline uint32_t MSTSTATE_RXRDY = (1 << 1);     /**< Master Receive ready state */
constexpr inline uint32_t MSTSTATE_TXRDY = (2 << 1);     /**< Master Transmit ready state */
constexpr inline uint32_t MSTSTATE_NACK_ADDR = (3 << 1); /**< Master Slave nacked address state */
constexpr inline uint32_t MSTSTATE_NACK_DATA = (4 << 1); /**< Master Slave nacked data state */
constexpr inline uint32_t MSTARBLOSS = (1 << 4);         /**< Master Arbitration loss flag*/
constexpr inline uint32_t MSTSTSTPERR = (1 << 6);        /**< Master Start/Stop error flag */
constexpr inline uint32_t SLVPENDING = (1 << 8);         /**< Slave pending */
constexpr inline uint32_t SLVSTATE_MASK = (0x4 << 9);    /**< Slave State mask*/
constexpr inline uint32_t SLVSTATE_ADDR = (0 << 9);      /**< Slave address received state */
constexpr inline uint32_t SLVSTATE_RX = (1 << 9);        /**< Slave receive state */
constexpr inline uint32_t SLVSTATE_TX = (2 << 9);        /**< Slave transmit state */
constexpr inline uint32_t SLVNOTSTR = (1 << 11);         /**< Slave not stretch */
constexpr inline uint32_t SLVIDX_MASK = (0x3 << 12);     /**< Slave address match index mask*/
constexpr inline uint32_t SLVIDX_0 = (0 << 12);          /**< Slave address 0 matched */
constexpr inline uint32_t SLVIDX_1 = (1 << 12);          /**< Slave address 1 matched */
constexpr inline uint32_t SLVIDX_2 = (2 << 12);          /**< Slave address 2 matched */
constexpr inline uint32_t SLVIDX_3 = (3 << 12);          /**< Slave address 3 matched */
constexpr inline uint32_t SLVSEL = (1 << 14);            /**< Slave selected flag */
constexpr inline uint32_t SLVDESEL = (1 << 15);          /**< Slave deselected flag */
constexpr inline uint32_t MONRDY = (1 << 16);            /**< Monitor ready flag */
constexpr inline uint32_t MONOV = (1 << 17);             /**< Monitor overflow flag */
constexpr inline uint32_t MONACTIVE = (1 << 18);         /**< Monitor active flag */
constexpr inline uint32_t MONIDLE = (1 << 19);           /**< Monitor idle flag */
constexpr inline uint32_t EVENTTIMEOUT = (1 << 24);      /**< Event timeout interrupt flag */
constexpr inline uint32_t SCLTIMEOUT = (1 << 25);        /**< SCL timeout interrupt flag */
}  // namespace STAT
namespace INTENSET {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace INTENSET
namespace INTENCLR {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace INTENCLR
namespace TIMEOUT {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace TIMEOUT
namespace CLKDIV {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace CLKDIV
namespace INTSTAT {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace INTSTAT
namespace MSTCTL {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace MSTCTL
namespace MSTTIME {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace MSTTIME
namespace MSTDAT {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace MSTDAT
namespace SLVCTL {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace SLVCTL
namespace SLVDAT {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace SLVDAT
namespace SLVADR {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace SLVADR
namespace SLVQUAL0 {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace SLVQUAL0
namespace MONRXDAT {
constexpr inline uint32_t MASK = 0x00000000; /**< register mask for allowed bits */
}  // namespace MONRXDAT
}  // namespace i2c
}  // namespace registers

#endif