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

namespace libMcuHw::gpioQspi {
/**
 * @brief QSPI GPIO register definitions
 */
struct gpioQspi {
  volatile std::uint32_t DUMMY; /**< Fill in */
};
namespace DUMMY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /**< Mask for allowed bits */
}  // namespace DUMMY
}  // namespace libMcuHw::gpioQspi
#endif