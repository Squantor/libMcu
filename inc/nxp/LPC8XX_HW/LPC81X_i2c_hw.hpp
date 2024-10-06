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

namespace libMcuLL::hw::i2c {

/**
 * @brief I2C bus register definitions
 */
struct i2c {
  volatile std::uint32_t CFG;                /**< Configuration for shared functions */
  volatile std::uint32_t STAT;               /**< Status register for Master, Slave, and Monitor functions */
  volatile std::uint32_t INTENSET;           /**< Interrupt Enable Set and read register */
  volatile std::uint32_t INTENCLR;           /**< Interrupt Enable Clear register */
  volatile std::uint32_t TIMEOUT;            /**< Time-out value register */
  volatile std::uint32_t CLKDIV;             /**< Clock pre-divider for the entire I2C interface */
  volatile const std::uint32_t INTSTAT;      /**< Interrupt Status register for Master, Slave, and Monitor functions */
  volatile const std::uint32_t RESERVED0;    /**< reserved */
  volatile std::uint32_t MSTCTL;             /**< Master control register */
  volatile std::uint32_t MSTTIME;            /**< Master timing configuration */
  volatile std::uint32_t MSTDAT;             /**< Combined Master receiver and transmitter data register */
  volatile const std::uint32_t RESERVED1[5]; /**< reserved */
  volatile std::uint32_t SLVCTL;             /**< Slave control register */
  volatile std::uint32_t SLVDAT;             /**< Combined Slave receiver and transmitter data register */
  volatile std::uint32_t SLVADR[4];          /**< Slave address register */
  volatile std::uint32_t SLVQUAL0;           /**< Slave Qualification for address 0 */
  volatile const std::uint32_t RESERVED2[9]; /**< reserved */
  volatile const std::uint32_t MONRXDAT;     /**< Monitor receiver data register */
};
namespace CFG {
constexpr inline std::uint32_t RESERVED_MASK{0x0000001Fu}; /**< register mask for allowed bits */
constexpr inline std::uint32_t MSTEN{1u << 0};             /**< Master Enable*/
constexpr inline std::uint32_t SLVEN{1u << 1};             /**< Slave enable */
constexpr inline std::uint32_t MONEN{1u << 2};             /**< Monitor enable */
constexpr inline std::uint32_t TIMEOUTEN{1u << 3};         /**< I2C timeout enable */
constexpr inline std::uint32_t MONCLKSTR{1u << 4};         /**< Monitor clock stretching enable */
}  // namespace CFG
namespace STAT {
constexpr inline std::uint32_t RESERVED_MASK{0x030FFF5Fu};  /**< register mask for allowed bits */
constexpr inline std::uint32_t MSTPENDING{1u << 0};         /**< Master Enable */
constexpr inline std::uint32_t MSTSTATE_MASK{0x7u << 1};    /**< Master State mask */
constexpr inline std::uint32_t MSTSTATE_IDLE{0u << 1};      /**< Master Idle state */
constexpr inline std::uint32_t MSTSTATE_RXRDY{1u << 1};     /**< Master Receive ready state */
constexpr inline std::uint32_t MSTSTATE_TXRDY{2u << 1};     /**< Master Transmit ready state */
constexpr inline std::uint32_t MSTSTATE_NACK_ADDR{3u << 1}; /**< Master Slave nacked address state */
constexpr inline std::uint32_t MSTSTATE_NACK_DATA{4u << 1}; /**< Master Slave nacked data state */
constexpr inline std::uint32_t MSTARBLOSS{1u << 4};         /**< Master Arbitration loss flag*/
constexpr inline std::uint32_t MSTSTSTPERR{1u << 6};        /**< Master Start/Stop error flag */
constexpr inline std::uint32_t SLVPENDING{1u << 8};         /**< Slave pending */
constexpr inline std::uint32_t SLVSTATE_MASK{0x4u << 9};    /**< Slave State mask*/
constexpr inline std::uint32_t SLVSTATE_ADDR{0u << 9};      /**< Slave address received state */
constexpr inline std::uint32_t SLVSTATE_RX{1u << 9};        /**< Slave receive state */
constexpr inline std::uint32_t SLVSTATE_TX{2u << 9};        /**< Slave transmit state */
constexpr inline std::uint32_t SLVNOTSTR{1u << 11};         /**< Slave not stretch */
constexpr inline std::uint32_t SLVIDX_MASK{0x3u << 12};     /**< Slave address match index mask*/
constexpr inline std::uint32_t SLVIDX_0{0u << 12};          /**< Slave address 0 matched */
constexpr inline std::uint32_t SLVIDX_1{1u << 12};          /**< Slave address 1 matched */
constexpr inline std::uint32_t SLVIDX_2{2u << 12};          /**< Slave address 2 matched */
constexpr inline std::uint32_t SLVIDX_3{3u << 12};          /**< Slave address 3 matched */
constexpr inline std::uint32_t SLVSEL{1u << 14};            /**< Slave selected flag */
constexpr inline std::uint32_t SLVDESEL{1u << 15};          /**< Slave deselected flag */
constexpr inline std::uint32_t MONRDY{1u << 16};            /**< Monitor ready flag */
constexpr inline std::uint32_t MONOV{1u << 17};             /**< Monitor overflow flag */
constexpr inline std::uint32_t MONACTIVE{1u << 18};         /**< Monitor active flag */
constexpr inline std::uint32_t MONIDLE{1u << 19};           /**< Monitor idle flag */
constexpr inline std::uint32_t EVENTTIMEOUT{1u << 24};      /**< Event timeout interrupt flag */
constexpr inline std::uint32_t SCLTIMEOUT{1u << 25};        /**< SCL timeout interrupt flag */
}  // namespace STAT
namespace INTENSET {
constexpr inline std::uint32_t RESERVED_MASK{0x030B8951u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t MSTPENDINGEN{1u << 0};      /**< Master Pending interrupt Enable */
constexpr inline std::uint32_t MSTARBLOSSEN{1u << 4};      /**< Master Arbitration Loss interrupt Enable */
constexpr inline std::uint32_t MSTSTSTPERREN{1u << 6};     /**< Master Start/Stop Error interrupt Enable */
constexpr inline std::uint32_t SLVPENDINGEN{1u << 8};      /**< Slave Pending interrupt Enable */
constexpr inline std::uint32_t SLVNOTSTREN{1u << 11};      /**< Slave Not Stretching interrupt Enable */
constexpr inline std::uint32_t SLVDESELEN{1u << 15};       /**< Slave Deselect interrupt Enable */
constexpr inline std::uint32_t MONRDYEN{1u << 16};         /**< Monitor data Ready interrupt Enable */
constexpr inline std::uint32_t MONOVEN{1u << 17};          /**< Monitor Overrun interrupt Enable */
constexpr inline std::uint32_t MONIDLEEN{1u << 17};        /**< Monitor Idle interrupt Enable */
constexpr inline std::uint32_t EVENTTIMEOUTEN{1u << 24};   /**< Event time-out interrupt Enable */
constexpr inline std::uint32_t SCLTIMEOUTEN{1u << 25};     /**< SCL time-out interrupt Enable */
}  // namespace INTENSET
namespace INTENCLR {
constexpr inline std::uint32_t RESERVED_MASK{0x030B8951u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t MSTPENDINGCLR{1u << 0};     /**< Master Pending interrupt clear */
constexpr inline std::uint32_t MSTARBLOSSCLR{1u << 4};     /**< Master Arbitration Loss interrupt clear */
constexpr inline std::uint32_t MSTSTSTPERRCLR{1u << 6};    /**< Master Start/Stop Error interrupt clear */
constexpr inline std::uint32_t SLVPENDINGCLR{1u << 8};     /**< Slave Pending interrupt clear */
constexpr inline std::uint32_t SLVNOTSTRCLR{1u << 11};     /**< Slave Not Stretching interrupt clear */
constexpr inline std::uint32_t SLVDESELCLR{1u << 15};      /**< Slave Deselect interrupt clear */
constexpr inline std::uint32_t MONRDYCLR{1u << 16};        /**< Monitor data Ready interrupt clear */
constexpr inline std::uint32_t MONOVCLR{1u << 17};         /**< Monitor Overrun interrupt clear */
constexpr inline std::uint32_t MONIDLECLR{1u << 19};       /**< Monitor Idle interrupt clear */
constexpr inline std::uint32_t EVENTTIMEOUTCLR{1u << 24};  /**< Event time-out interrupt clear */
constexpr inline std::uint32_t SCLTIMEOUTCLR{1u << 25};    /**< SCL time-out interrupt clear */
}  // namespace INTENCLR
namespace TIMEOUT {
constexpr inline std::uint32_t RESERVED_MASK{0x0000FFFFu}; /**< register mask for allowed bits */
/**
 * @brief Formats data to TO register field
 *
 * @param data data to put in TO register, a value of 0 is 16 clocks, 1 is 32 clocks
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t TO(std::uint_fast16_t data) {
  return static_cast<std::uint32_t>(data) << 4;
}
}  // namespace TIMEOUT
namespace CLKDIV {
constexpr inline std::uint32_t RESERVED_MASK{0x0000FFFFu}; /**< register mask for allowed bits */
/**
 * @brief Formats data to DIVVAL register field
 *
 * @param data data to put in DIVVAL register, 0 is no division of PCLK, 1 is division by 2
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t DIVVAL(std::uint_fast16_t data) {
  return static_cast<std::uint32_t>(data) << 0;
}
}  // namespace CLKDIV
namespace INTSTAT {
constexpr inline std::uint32_t RESERVED_MASK{0x030B8951u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t MSTPENDING{1u << 0};        /**< Master Pending */
constexpr inline std::uint32_t MSTARBLOSS{1u << 4};        /**< Master Arbitration Loss flag */
constexpr inline std::uint32_t MSTSTSTPERR{1u << 6};       /**< Master Start/Stop Error flag */
constexpr inline std::uint32_t SLVPENDING{1u << 8};        /**< Slave Pending */
constexpr inline std::uint32_t SLVNOTSTR{1u << 11};        /**< Slave Not Stretching status */
constexpr inline std::uint32_t SLVDESEL{1u << 15};         /**< Slave Deselected flag */
constexpr inline std::uint32_t MONRDY{1u << 16};           /**< Monitor Ready */
constexpr inline std::uint32_t MONOV{1u << 17};            /**< Monitor Overflow flag */
constexpr inline std::uint32_t MONIDLE{1u << 19};          /**< Monitor Idle flag */
constexpr inline std::uint32_t EVENTTIMEOUT{1u << 24};     /**< Event time-out Interrupt flag */
constexpr inline std::uint32_t SCLTIMEOUT{1u << 25};       /**< SCL time-out Interrupt flag */
}  // namespace INTSTAT
namespace MSTCTL {
constexpr inline std::uint32_t RESERVED_MASK{0x00000007u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t MSTCONTINUE{1u << 0};       /**< Master Continue */
constexpr inline std::uint32_t MSTSTART{1u << 1};          /**< Master Start control */
constexpr inline std::uint32_t MSTSTOP{1u << 2};           /**< Master Stop control */
}  // namespace MSTCTL
namespace MSTTIME {
constexpr inline std::uint32_t RESERVED_MASK{0x00000077u}; /**< register mask for allowed bits */
/**
 * @brief Formats data to MSTSCLLOW register field
 *
 * @param data data to put in MSTSCLLOW register, 0 is 2 cycles SCL low, 1 is 3 cycles SCL low
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t MSTSCLLOW(std::uint_fast8_t data) {
  return static_cast<std::uint32_t>(data) << 0;
}
/**
 * @brief Formats data to MSTSCLHIGH register field
 *
 * @param data data to put in MSTSCLHIGH register, 0 is 2 cycles SCL high, 1 is 3 cycles SCL high
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t MSTSCLHIGH(std::uint_fast8_t data) {
  return static_cast<std::uint32_t>(data) << 4;
}
}  // namespace MSTTIME
namespace MSTDAT {
constexpr inline std::uint32_t RESERVED_MASK = 0x000000FFu; /**< register mask for allowed bits */
/**
 * @brief Formats data to DATA register field
 *
 * @param data data to put in DATA register
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t DATA(std::uint_fast8_t data) {
  return static_cast<std::uint32_t>(data) << 0;
}
}  // namespace MSTDAT
namespace SLVCTL {
constexpr inline std::uint32_t RESERVED_MASK{0x00000003u}; /**< register mask for allowed bits */
constexpr inline std::uint32_t SLVCONTINUE{1u << 0};       /**< Slave Continue */
constexpr inline std::uint32_t SLVNACK{1u << 1};           /**< Slave NACK */
}  // namespace SLVCTL
namespace SLVDAT {
constexpr inline std::uint32_t RESERVED_MASK{0x000000FFu}; /**< register mask for allowed bits */
/**
 * @brief Formats data to DATA register field
 *
 * @param data data to put in DATA register
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t DATA(std::uint_fast8_t data) {
  return static_cast<std::uint32_t>(data) << 0;
}
}  // namespace SLVDAT
namespace SLVADR {
constexpr inline std::uint32_t RESERVED_MASK{0x000000FFu}; /**< register mask for allowed bits */
constexpr inline std::uint32_t SADISABLE{1u << 0};         /**< Slave Address n Disable */
/**
 * @brief Formats data to SLVADR register field
 *
 * @param data data to put in SLVADR register
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t SLVADR(std::uint_fast8_t data) {
  return static_cast<std::uint32_t>(data) << 1;
}
}  // namespace SLVADR
namespace SLVQUAL0 {
constexpr inline std::uint32_t RESERVED_MASK{0x000000FFu}; /**< register mask for allowed bits */
constexpr inline std::uint32_t QUALMODE0{1u << 0};         /**< SLVQUAL0 field extends address 0 matching */
/**
 * @brief Formats data to SLVQUAL0 register field
 *
 * @param data data to put in SLVQUAL0 register
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t SLVQUAL0(std::uint_fast8_t data) {
  return static_cast<std::uint32_t>(data) << 1;
}
}  // namespace SLVQUAL0
namespace MONRXDAT {
constexpr inline std::uint32_t RESERVED_MASK{0x000007FFu}; /**< register mask for allowed bits */
/**
 * @brief Formats MONRXDAT to a value
 *
 * @param data data to put in SLVQUAL0 register
 * @return constexpr std::uint32_t returns formatted data
 */
constexpr inline std::uint32_t MONRXDAT(std::uint32_t reg) {
  return (reg & 0xFFu) >> 0;
}
constexpr inline std::uint32_t MONSTART{1u << 8};   /**< Monitor Received Start flag */
constexpr inline std::uint32_t MONRESTART{1u << 9}; /**< Monitor Received Repeated Start flag */
constexpr inline std::uint32_t MONNACK{1u << 10};   /**< Monitor Received NACK */

}  // namespace MONRXDAT
}  // namespace libMcuLL::hw::i2c
#endif