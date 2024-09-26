/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC840 Input multiplexer register interface
 */
#ifndef LPC84X_INMUX_HW_HPP
#define LPC84X_INMUX_HW_HPP

namespace libMcuLL::hw::inmux {
/**
 * @brief INMUX register definitions
 */
struct peripheral {
  volatile std::uint32_t DMA_INMUX_INMUX[2];  /**< DMA output trigger selection to become DMA trigger */
  std::uint8_t RESERVED_0[24];                /**< Reserved */
  volatile std::uint32_t SCT_INMUX[4];        /**< input select register for SCT */
  std::uint8_t RESERVED_1[16];                /**< Reserved */
  volatile std::uint32_t DMA_ITRIG_INMUX[25]; /**< Trigger select register for DMA channel */
};
}  // namespace libMcuLL::hw::inmux
#endif