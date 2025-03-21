/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcuhal_types.hpp
 * @brief Types used by libMcuHal
 */
#ifndef LIBMCUHAL_TYPES_HPP
#define LIBMCUHAL_TYPES_HPP

namespace libmcuhal {
/**
 * @brief Hal base class that all Hal classes should inherit from
 * You will never copy/move a hal object, they are "eternal" with respect to program lifetime
 */
struct HalBase {
  HalBase() = default;
  ~HalBase() = default;
  HalBase(const HalBase&) = delete;
  HalBase& operator=(const HalBase&) = delete;
  HalBase(HalBase&&) = delete;
  HalBase& operator=(HalBase&&) = delete;
};
/* Hal base classes */
struct HalGpioBase : HalBase {};
struct HalUartSync : HalBase {};
struct HalSpiSync : HalBase {};
struct HalI2cSync : HalBase {};

}  // namespace libmcuhal

#endif