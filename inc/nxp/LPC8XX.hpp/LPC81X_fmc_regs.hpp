/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series Flash memory control register interface
 */
#ifndef LPC81X_FMC_REGS_HPP
#define LPC81X_FMC_REGS_HPP

namespace registers {
namespace fmc {

/**
 * @brief flash controller register definitions
 *
 */
struct registers {
  volatile const uint32_t RESERVED1[4]; /**< reserved */
  volatile uint32_t FLASHCFG;           /**< Flash Configuration register */
  volatile const uint32_t RESERVED2[3]; /**< reserved */
  volatile uint32_t FMSSTART;           /**< Signature start address register */
  volatile uint32_t FMSSTOP;            /**< Signature stop address register */
  volatile const uint32_t RESERVED3;    /**< reserved */
  volatile const uint32_t FMSW[1];      /**< Signature word regsiter */
};

}  // namespace fmc
}  // namespace registers

#endif