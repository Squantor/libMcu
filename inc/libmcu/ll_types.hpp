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

/**
 * @brief Asynchronous interface base class
 * Every asynchronous capable class should inherit from this
 */
struct AsyncInterface : LowLevelBase {
  /**
   * @brief Progress function for asynchronous interfaces
   * Usually callbacks are called from this context to upper levels
   * @todo add claim/unclaim interfaces here?
   */
  virtual void Progress(void) = 0;
  /* There is no Callback function for LL drivers are at the top level */
};

/* Peripheral bases used by most microcontrollers */
struct SyncUartBase : LowLevelBase {};    /*!< Synchronous UART base class */
struct AsyncUartBase : AsyncInterface {}; /*!< Asynchronous UART base class */
struct SyncSpiBase : LowLevelBase {};     /*!< Synchronous SPI base class */
struct AsyncSpiBase : AsyncInterface {};  /*!< Asynchronous SPI base class */
struct SyncI2cBase : LowLevelBase {};     /*!< Synchronous I2C base class */
struct AsyncI2cBase : AsyncInterface {};  /*!< Asynchronous I2C base class */
struct AdcBase : LowLevelBase {};         /*!< ADC base class */
struct GpioBase : LowLevelBase {};        /*!< GPIO base class */

/* I2C general definitions */
using I2cDeviceAddressBase = libmcu::Constant<std::uint8_t>;
using I2cDeviceAddressType = typename I2cDeviceAddressBase::type;

struct I2cDeviceAddress : I2cDeviceAddressBase {}; /*!< General purpose I2C address type */

}  // namespace libmcull
#endif