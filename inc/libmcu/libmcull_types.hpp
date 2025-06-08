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
struct SyncUartBase : PeripheralBase {};  /*!< Synchronous UART base class */
struct AsyncUartBase : PeripheralBase {}; /*!< Asynchronous UART base class */
struct SyncSpiBase : PeripheralBase {};   /*!< Synchronous SPI base class */
struct AsyncSpiBase : PeripheralBase {};  /*!< Asynchronous SPI base class */
struct SyncI2cBase : PeripheralBase {};   /*!< Synchronous I2C base class */
struct AsyncI2cBase : PeripheralBase {};  /*!< Asynchronous I2C base class */

/* I2C general definitions */
using I2cDeviceAddressBase = libmcu::Constant<std::uint8_t>;
using I2cDeviceAddressType = typename I2cDeviceAddressBase::type;

struct I2cDeviceAddress : I2cDeviceAddressBase {}; /*!< General purpose I2C address type */

}  // namespace libmcull
#endif