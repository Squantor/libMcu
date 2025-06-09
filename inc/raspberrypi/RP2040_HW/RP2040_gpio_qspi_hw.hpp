/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_gpio_qspi_hw.hpp
 * @brief Register structure and bit definitions for the RP2040 QSPI GPIO
 */
#ifndef RP2040_GPIO_QSPI_HW_HPP
#define RP2040_GPIO_QSPI_HW_HPP

namespace libmcuhw::gpio_qspi {
/**
 * @brief QSPI GPIO register definitions
 */
struct GpioQspi {
  volatile std::uint32_t DUMMY; /*!< Fill in */
};
namespace DUMMY {
constexpr inline std::uint32_t RESERVED_MASK{0xFFFF'FFFFu}; /*!< Mask for allowed bits */
}  // namespace DUMMY
}  // namespace libmcuhw::gpio_qspi
#endif