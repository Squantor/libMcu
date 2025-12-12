/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file LPC84X_gpio_hal.hpp
 * @brief LPC840 series GPIO HAL
 */
#ifndef LPC84X_GPIO_HAL_HPP
#define LPC84X_GPIO_HAL_HPP

namespace libmcuhal::gpio {
namespace hardware = libmcuhw::gpio;
namespace lowlevel = libmcull::gpio;
namespace nvic = libmcuhw::nvic;

template <libmcull::DerivedFromGpio auto& ll_gpio>
struct Gpio : public libmcuhal::GpioBase {};

}  // namespace libmcuhal::gpio

#endif