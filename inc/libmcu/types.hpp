/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file types.hpp
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
 * @brief Nonblocking interface base class
 * Every nonblocking class should inherit from this
 */
struct NonBlocking {
  /**
   * @brief Progress function for nonblocking interfaces
   * Usually callbacks are called from this context to upper levels
   * @todo Maybe an idea to pass ticks to this function?
   */
  virtual void progress(void) = 0;
  /**
   * @brief Callback function for nonblocking interfaces
   * Usually called from lower levels
   * @param result result of the operation
   */
  virtual void callback(libmcu::Results result) = 0;
};
/**
 * @brief States of the nonblocking interfaces
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

/* I2C general definitions */
using I2cDeviceAddressBase = libmcu::Constant<std::uint8_t>;
struct I2cDeviceAddress : I2cDeviceAddressBase {}; /*!< General purpose I2C address type */

/**
 * @brief Checks if a type is derived from a template
 * @tparam Derived
 * @tparam Base
 */
template <typename Derived, template <typename...> class Base>
struct Derived_from_template {
 private:
  template <typename... Args>
  static std::true_type test(const Base<Args...>*);

  static std::false_type test(...);

 public:
  static constexpr bool value = decltype(test(std::declval<Derived*>()))::value;
};

}  // namespace libmcu
#endif