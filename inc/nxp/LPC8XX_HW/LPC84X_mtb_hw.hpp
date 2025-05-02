/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_mtb_hw.hpp
 * @brief Register structure and bit definitions for the LPC840 series Multi Trace Buffer
 */
#ifndef LPC84X_MTB_HW_HPP
#define LPC84X_MTB_HW_HPP

namespace libmcuhw::mtb {
/**
 * @brief MTB register definitions
 */
struct Mtb {
  volatile std::uint32_t POSITION;   /*!< POSITION Register */
  volatile std::uint32_t MASTER;     /*!< MASTER Register */
  volatile std::uint32_t FLOW;       /*!< FLOW Register */
  volatile const std::uint32_t BASE; /*!< Indicates where the SRAM is located in the processor memory map */
};
}  // namespace libmcuhw::mtb
#endif