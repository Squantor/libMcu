/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2022 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** @file XIP control peripheral definitions */
#ifndef XIP_CTRL_H
#define XIP_CTRL_H

typedef volatile struct {
  uint32_t CTRL;        /*!< Cache control */
  uint32_t FLUSH;       /*!< Cache Flush control */
  const uint32_t STAT;  /*!< Cache Status */
  uint32_t CTR_HIT;     /*!< Cache Hit counter */
  uint32_t CTR_ACC;     /*!< Cache Access counter */
  uint32_t STREAM_ADDR; /*!< FIFO stream address */
  uint32_t STREAM_CTR;  /*!< FIFO stream control */
  uint32_t STREAM_FIFO; /*!< FIFO stream data */
} XIP_CTRL_Type;
#endif