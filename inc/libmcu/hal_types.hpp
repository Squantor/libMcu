/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file hal_types.hpp
 * @brief Types used by libMcuHal
 */
#ifndef HAL_TYPES_HPP
#define HAL_TYPES_HPP

namespace libmcuhal {
/**
 * @brief Various types of transactions
 */
enum class TransactionType : std::uint8_t {
  EmptyEntry,    /*!< Empty entry */
  SingleWrite,   /*!< Single write */
  StartWrite,    /*!< Start of transaction, needs an address */
  ContinueWrite, /*!< Continue transaction, needs data */
  StopWrite,     /*!< Stop Writing transaction */
  SingleRead,    /*!< Single read */
  StartRead,     /*!< Start of transaction, needs an address */
  ContinueRead,  /*!< Continue transaction, needs data */
  StopRead,      /*!< Stop Reading transaction */
};
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
/**
 * @brief I2C transaction structure
 *
 */
struct I2cTransaction {
  TransactionType type;                        /*!< Type of transaction */
  libmcu::I2cDeviceAddress address;            /*!< I2C address, needed for Start */
  std::span<const std::uint8_t> transmit_data; /*!< Data to send, needed for Continue */
  std::span<std::uint8_t> receive_data;        /*!< Data to receive, needed for Continue */
  libmcu::AsyncInterface* asyncInterface;      /*!< Pointer to class with async callback */
};

struct GpioBase : public HalBase {};                                     /*!< GPIO hal base class */
struct AsyncUartBase : public HalBase, public libmcu::AsyncInterface {}; /*!< Asynchronous UART hal base class */
struct SyncUartBase : public HalBase {};                                 /*!< Synchronous UART hal base class */
struct AsyncSpiBase : public HalBase, public libmcu::AsyncInterface {};  /*!< Asynchronous SPI hal base class */
struct AsyncI2cBase : public HalBase, public libmcu::AsyncInterface {};  /*!< Asynchronous I2C hal base class */

}  // namespace libmcuhal

#endif