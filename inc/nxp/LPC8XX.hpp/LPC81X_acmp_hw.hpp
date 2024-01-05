/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file LPC810 series analog comparator register interface
 */
#ifndef LPC81X_ACMP_REGS_HPP
#define LPC81X_ACMP_REGS_HPP
namespace libMcuLL {
namespace hw {
namespace acmp {

/**
 * @brief analog comparator register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t CTRL; /**<  Analog Comparator control register */
  volatile std::uint32_t LAD;  /**<  Voltage ladder register */
};

}  // namespace acmp
}  // namespace hw
}  // namespace libMcuLL

#endif