/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file ll_types.hpp
 * @brief Types used in libmcull
 */
#ifndef LL_TYPES_HPP
#define LL_TYPES_HPP

namespace libmcull {
/**
 * @brief Low level base class that all LL drivers should inherit from
 * You will never copy/move a LL driver, they are "eternal" with respect to program lifetime
 */
struct LowLevelBase {
  LowLevelBase() = default;
  ~LowLevelBase() = default;
  LowLevelBase(const LowLevelBase&) = delete;
  LowLevelBase& operator=(const LowLevelBase&) = delete;
  LowLevelBase(LowLevelBase&&) = delete;
  LowLevelBase& operator=(LowLevelBase&&) = delete;
};

/* Peripheral bases used by most microcontrollers */
struct SyncUartBase : public LowLevelBase {};                                 /*!< Synchronous UART base class */
struct AsyncUartBase : public LowLevelBase, public libmcu::AsyncInterface {}; /*!< Asynchronous UART base class */
struct SyncSpiBase : public LowLevelBase {};                                  /*!< Synchronous SPI base class */
struct AsyncSpiBase : public LowLevelBase, public libmcu::AsyncInterface {};  /*!< Asynchronous SPI base class */
struct SyncI2cBase : public LowLevelBase {};                                  /*!< Synchronous I2C base class */
struct AsyncI2cBase : public LowLevelBase, public libmcu::AsyncInterface {};  /*!< Asynchronous I2C base class */
struct AdcBase : public LowLevelBase {};                                      /*!< ADC base class */
struct GpioBase : public LowLevelBase {};                                     /*!< GPIO base class */

/* I2C general definitions */
using I2cDeviceAddressBase = libmcu::Constant<std::uint8_t>;
using I2cDeviceAddressType = typename I2cDeviceAddressBase::type;

struct I2cDeviceAddress : I2cDeviceAddressBase {}; /*!< General purpose I2C address type */

}  // namespace libmcull
#endif