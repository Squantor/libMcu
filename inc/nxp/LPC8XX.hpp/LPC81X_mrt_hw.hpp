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

namespace libMcuLL::hw::mrt {

struct mrtChannel {
  volatile std::uint32_t INTVAL; /* Timer interval register */
  volatile std::uint32_t TIMER;  /* Timer register */
  volatile std::uint32_t CTRL;   /* Timer control register */
  volatile std::uint32_t STAT;   /* Timer status register */
};

struct peripheral {
  mrtChannel CHANNEL[4];
  volatile std::uint32_t RESERVED1[45];
  volatile std::uint32_t IDLE_CH;
  volatile std::uint32_t IRQ_FLAG;
};

}  // namespace libMcuLL::hw::mrt
#endif