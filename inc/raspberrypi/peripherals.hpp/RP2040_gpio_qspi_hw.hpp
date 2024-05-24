/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 QSPI GPIO register interface
 */
#ifndef RP2040_GPIO_QSPI_HW_HPP
#define RP2040_GPIO_QSPI_HW_HPP

namespace libMcuLL::hw::gpioQspi {
/**
 * @brief DMA register definitions
 *
 */
struct peripheral {
  volatile std::uint32_t DUMMY; /**< Fill in */
};
namespace DUMMY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace DUMMY
}  // namespace libMcuLL::hw::gpioQspi
#endif