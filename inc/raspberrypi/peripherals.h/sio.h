/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file Single-Cyle I/O peripheral definitions */
#ifndef SIO_H
#define SIO_H

typedef volatile struct {
  const uint32_t CPUID;        /**< Processor core identifier */
  const uint32_t GPIO_IN;      /**< Input value for GPIO pins */
  uint32_t GPIO_HI_IN;         /**< Input value for QSPI pins */
  uint32_t reserved0;          /**< Reserved */
  uint32_t GPIO_OUT;           /**< GPIO output value */
  uint32_t GPIO_OUT_SET;       /**< GPIO output value set */
  uint32_t GPIO_OUT_CLR;       /**< GPIO output value clear */
  uint32_t GPIO_OUT_XOR;       /**< GPIO output value XOR */
  uint32_t GPIO_OE;            /**< GPIO output enable */
  uint32_t GPIO_OE_SET;        /**< GPIO output enable set */
  uint32_t GPIO_OE_CLR;        /**< GPIO output enable clear */
  uint32_t GPIO_OE_XOR;        /**< GPIO output enable XOR */
  uint32_t GPIO_HI_OUT;        /**< QSPI output value */
  uint32_t GPIO_HI_OUT_SET;    /**< QSPI output value set */
  uint32_t GPIO_HI_OUT_CLR;    /**< QSPI output value clear */
  uint32_t GPIO_HI_OUT_XOR;    /**< QSPI output value XOR */
  uint32_t GPIO_HI_OE;         /**< QSPI output enable */
  uint32_t GPIO_HI_OE_SET;     /**< QSPI output enable set */
  uint32_t GPIO_HI_OE_CLR;     /**< QSPI output enable clear */
  uint32_t GPIO_HI_OE_XOR;     /**< QSPI output enable XOR */
  uint32_t FIFO_ST;            /**< Status register for inter-core FIFOs (mailboxes). */
  uint32_t FIFO_WR;            /**< Write access to this core’s TX FIFO */
  uint32_t FIFO_RD;            /**< Read access to this core’s RX FIFO */
  uint32_t SPINLOCK_ST;        /**< Spinlock state */
  uint32_t DIV_UDIVIDEND;      /**< Divider unsigned dividend */
  uint32_t DIV_UDIVISOR;       /**< Divider unsigned divisor */
  uint32_t DIV_SDIVIDEND;      /**< Divider signed dividend */
  uint32_t DIV_SDIVISOR;       /**< Divider signed divisor */
  uint32_t DIV_QUOTIENT;       /**< Divider result quotient */
  uint32_t DIV_REMAINDER;      /**< Divider result remainder */
  uint32_t DIV_CSR;            /**< Control and status register for divider. */
  uint32_t reserved1;          /**< Reserved */
  uint32_t INTERP0_ACCUM0;     /**< Read/write access to accumulator 0 */
  uint32_t INTERP0_ACCUM1;     /**< Read/write access to accumulator 1 */
  uint32_t INTERP0_BASE0;      /**< Read/write access to BASE0 register */
  uint32_t INTERP0_BASE1;      /**< Read/write access to BASE1 register */
  uint32_t INTERP0_BASE2;      /**< Read/write access to BASE2 register */
  uint32_t INTERP0_POP_LANE0;  /**< Read LANE0 result, simultaneously write to both accumulators (POP) */
  uint32_t INTERP0_POP_LANE1;  /**< Read LANE1 result, simultaneously write to both accumulators (POP) */
  uint32_t INTERP0_POP_FULL;   /**< Read FULL result, simultaneously write to both accumulators (POP) */
  uint32_t INTERP0_PEEK_LANE0; /**< Read LANE0 result, without altering any internal state (PEEK) */
  uint32_t INTERP0_PEEK_LANE1; /**< Read LANE1 result, without altering any internal state (PEEK) */
  uint32_t INTERP0_PEEK_FULL;  /**< Read FULL result, without altering any internal state (PEEK) */
  uint32_t INTERP0_CTRL_LANE0; /**< Control register for lane 0 */
  uint32_t INTERP0_CTRL_LANE1; /**< Control register for lane 1 */
  uint32_t INTERP0_ACCUM0_ADD; /**< Values written here are atomically added to ACCUM0 */
  uint32_t INTERP0_ACCUM1_ADD; /**< Values written here are atomically added to ACCUM1 */
  uint32_t INTERP0_BASE_1AND0; /**< lower 16 bits to BASE0, upper to BASE1 simultaneously */
  uint32_t INTERP1_ACCUM0;     /**< Read/write access to accumulator 0 */
  uint32_t INTERP1_ACCUM1;     /**< Read/write access to accumulator 1 */
  uint32_t INTERP1_BASE0;      /**< Read/write access to BASE0 register */
  uint32_t INTERP1_BASE1;      /**< Read/write access to BASE1 register */
  uint32_t INTERP1_BASE2;      /**< Read/write access to BASE2 register */
  uint32_t INTERP1_POP_LANE0;  /**< Read LANE0 result, simultaneously write to both accumulators (POP) */
  uint32_t INTERP1_POP_LANE1;  /**< Read LANE1 result, simultaneously write to both accumulators (POP) */
  uint32_t INTERP1_POP_FULL;   /**< Read FULL result, simultaneously write to both accumulators (POP) */
  uint32_t INTERP1_PEEK_LANE0; /**< Read LANE0 result, without altering any internal state (PEEK) */
  uint32_t INTERP1_PEEK_LANE1; /**< Read LANE1 result, without altering any internal state (PEEK) */
  uint32_t INTERP1_PEEK_FULL;  /**< Read FULL result, without altering any internal state (PEEK) */
  uint32_t INTERP1_CTRL_LANE0; /**< Control register for lane 0 */
  uint32_t INTERP1_CTRL_LANE1; /**< Control register for lane 1 */
  uint32_t INTERP1_ACCUM0_ADD; /**< Values written here are atomically added to ACCUM0 */
  uint32_t INTERP1_ACCUM1_ADD; /**< Values written here are atomically added to ACCUM1 */
  uint32_t INTERP1_BASE_1AND0; /**< lower 16 bits to BASE0, upper to BASE1 simultaneously. */
  uint32_t SPINLOCK[32];       /**< Spinlock registers */
} SIO_Type;

#include "raspberrypi/peripherals.h/sio_gpio.h"
#include "raspberrypi/peripherals.h/sio_ipc.h"
#include "raspberrypi/peripherals.h/sio_div.h"
#include "raspberrypi/peripherals.h/sio_interp.h"

#endif