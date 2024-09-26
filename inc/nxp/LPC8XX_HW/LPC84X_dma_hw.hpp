/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Direct Memory Access register interface
 */
#ifndef LPC84X_DMA_HW_HPP
#define LPC84X_DMA_HW_HPP

namespace libMcuLL::hw::dma {
/**
 * @brief DMA register definitions
 */
struct peripheral {
  volatile std::uint32_t CTRL;              /**< DMA control */
  volatile const std::uint32_t INTSTAT;     /**< Interrupt status */
  volatile std::uint32_t SRAMBASE;          /**< SRAM address of the channel configuration table */
  std::uint8_t RESERVED_0[20];              /**< Reserved */
  struct {                                  /*  */
    volatile std::uint32_t ENABLESET;       /**< Channel Enable read and Set */
    std::uint8_t RESERVED_0[4];             /**< Reserved */
    volatile const std::uint32_t ENABLECLR; /**< Channel Enable Clear */
    std::uint8_t RESERVED_1[4];             /**< Reserved */
    volatile std::uint32_t ACTIVE;          /**< Channel Active status */
    std::uint8_t RESERVED_2[4];             /**< Reserved */
    volatile std::uint32_t BUSY;            /**< Channel Busy status */
    std::uint8_t RESERVED_3[4];             /**< Reserved */
    volatile std::uint32_t ERRINT;          /**< Error Interrupt status */
    std::uint8_t RESERVED_4[4];             /**< Reserved */
    volatile std::uint32_t INTENSET;        /**< Interrupt Enable read and Set */
    std::uint8_t RESERVED_5[4];             /**< Reserved */
    volatile const std::uint32_t INTENCLR;  /**< Interrupt Enable Clear */
    std::uint8_t RESERVED_6[4];             /**< Reserved */
    volatile std::uint32_t INTA;            /**< Interrupt A status */
    std::uint8_t RESERVED_7[4];             /**< Reserved */
    volatile std::uint32_t INTB;            /**< Interrupt B status */
    std::uint8_t RESERVED_8[4];             /**< Reserved */
    volatile const std::uint32_t SETVALID;  /**< Set ValidPending control bits */
    std::uint8_t RESERVED_9[4];             /**< Reserved */
    volatile const std::uint32_t SETTRIG;   /**< Set Trigger control bits */
    std::uint8_t RESERVED_10[4];            /**< Reserved */
    volatile const std::uint32_t ABORT;     /**< Channel Abort control */
  } COMMON[1];                              /**< Common for all DMA channels */
  std::uint8_t RESERVED_1[900];             /**< Reserved */
  struct {                                  /*  */
    volatile std::uint32_t CFG;             /**< Configuration register for DMA channel */
    volatile std::uint32_t CTLSTAT;         /**< Control and status register for DMA channel */
    volatile std::uint32_t XFERCFG;         /**< Transfer configuration register for DMA channel */
    std::uint8_t RESERVED_0[4];             /**< Reserved */
  } CHANNEL[25];                            /**< Specific DMA channel  */
};
}  // namespace libMcuLL::hw::dma
#endif