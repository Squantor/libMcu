/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file general_types.hpp
 * @brief LibMcu wide used types
 */
#ifndef GENERAL_TYPES_HPP
#define GENERAL_TYPES_HPP

namespace libmcu {
/**
 * @brief defines a constant for typesafety
 * @tparam C_ type of constant
 */
template <typename C_>
struct Constant {
  using type = C_;

  constexpr operator C_() const {
    return value;
  }

  C_ value;
};
/**
 * @brief Base class where all pin traits are based of from
 * This baseclass is used as a base derivation for the pin traits. We can use the base to typecheck passing pins to various
 * drivers/functions
 */
struct PinBase {};
/**
 * @brief Base class where all port traits are based on
 * This baseclass is used as a base derivation for the port traits. We can use the base to typecheck passing ports to various
 * drivers/functions
 */
struct PortBase {};
/**
 * @brief Asynchronous interface base class
 * Every asynchronous capable class should inherit from this
 */
struct AsyncInterface {
  /**
   * @brief Progress function for asynchronous interfaces
   * Usually callbacks are called from this context to upper levels
   */
  virtual void Progress(void) = 0;
  /**
   * @brief Callback function for asynchronous interfaces
   * Usually called from lower levels
   */
  virtual void Callback(void) = 0;
};
/**
 * @brief States of the asynchronous interfaces
 * @todo Maybe change this into results enum as there are a lot of matching cases
 * @todo depricate usage of this state enum and use the States enum that uses Results enum
 */
enum class AsynchronousStates : std::uint8_t {
  Idle,         /*!< Interface is idle, ready to be claimed */
  Claimed,      /*!< Interface is claimed, ready to transact */
  Busy,         /*!< Interface is busy */
  BusyReceive,  /*!< Interface is busy with a Reception operation */
  BusyTransmit, /*!< Interface is busy with a Transmit operation */
  Error,        /*!< Interface is in an error state */
};
/**
 * @brief Type of asynchronous transactions possible
 */
enum class TransactionType : std::uint8_t {
  Single,    /*!< Single transfer */
  Multiple,  /*!< Multiple transfer */
  Terminate, /*!< Terminate transfer */
};

using AsyncHandle = std::uint32_t;
using IsrLambda = std::add_pointer<void()>::type; /*!< Base type for an ISR lambda */

}  // namespace libmcu
#endif