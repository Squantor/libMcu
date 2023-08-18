/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Multi rate timer register interface
 */
#ifndef LPC81X_MRT_REGS_HPP
#define LPC81X_MRT_REGS_HPP

namespace registers {
namespace mrt {

struct mrtChannel {
  volatile uint32_t INTVAL; /* Timer interval register */
  volatile uint32_t TIMER;  /* Timer register */
  volatile uint32_t CTRL;   /* Timer control register */
  volatile uint32_t STAT;   /* Timer status register */
};

struct registers {
  mrtChannel CHANNEL[4];
  volatile uint32_t RESERVED1[45];
  volatile uint32_t IDLE_CH;
  volatile uint32_t IRQ_FLAG;
};

}  // namespace mrt
}  // namespace registers

#endif