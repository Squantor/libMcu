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

//! @todo Contents of this namespace need to be moved to libmcull that is below
namespace libmcu {

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
using i2cDeviceAddressBase = libmcu::Constant<std::uint8_t>;
using i2cDeviceAddressType = typename i2cDeviceAddressBase::type;

struct i2cDeviceAddress : i2cDeviceAddressBase {}; /*!< General purpose I2C address type */

}  // namespace libmcu

namespace libmcull {
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

/* Peripheral bases used by most microcontrollers */
struct LlSyncUartBase : PeripheralBase {};

/* I2C general definitions */
using i2cDeviceAddressBase = libmcu::Constant<std::uint8_t>;
using i2cDeviceAddressType = typename i2cDeviceAddressBase::type;

struct i2cDeviceAddress : i2cDeviceAddressBase {}; /*!< General purpose I2C address type */
}  // namespace libmcull
#endif