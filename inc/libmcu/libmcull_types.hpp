/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcull_types.hpp
 * @brief LibMcuLL wide used types
 */
#ifndef LIBMCULL_TYPES_HPP
#define LIBMCULL_TYPES_HPP

namespace libMcu {

/**
 * @brief Peripheral base class that all peripherals should inherit from
 * You will never copy/move a peripheral, they are "eternal" with respect to program lifetime
 */
struct PeripheralBase {
  PeripheralBase() = default;
  ~PeripheralBase() = default;
  PeripheralBase(const PeripheralBase&) = delete;
  PeripheralBase& operator=(const PeripheralBase&) = delete;
  PeripheralBase(PeripheralBase&&) = delete;
  PeripheralBase& operator=(PeripheralBase&&) = delete;
};

/* I2C general definitions */
using i2cDeviceAddressBase = libMcu::constant<std::uint8_t>;
using i2cDeviceAddressType = typename i2cDeviceAddressBase::type;

struct i2cDeviceAddress : i2cDeviceAddressBase {}; /*!< General purpose I2C address type */

}  // namespace libMcu
#endif