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

namespace libmcuhw::gpioQspi {
/**
 * @brief QSPI GPIO register definitions
 */
struct gpioQspi {
  volatile std::uint32_t DUMMY; /*!< Fill in */
};
namespace DUMMY {
constexpr inline std::uint32_t kRESERVED_MASK{0xFFFF'FFFFu}; /*!< Mask for allowed bits */
}  // namespace DUMMY
}  // namespace libmcuhw::gpioQspi
#endif