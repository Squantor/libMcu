/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcu_results.hpp
 * @brief state type used by libMcu
 */
#ifndef GENERAL_STATES_HPP
#define GENERAL_STATES_HPP

#include "results.hpp"

namespace libmcu {
/**
 * @brief state enumeration used in libMcu for various internal states.
 * This enum depends on results making the translation from state to result easier
 */
enum class States : std::uint8_t {
  Initializing = static_cast<std::uint8_t>(Results::Initializing),               /*!< Interface is initializing */
  Idle = static_cast<std::uint8_t>(Results::Idle),                               /*!< Interface is idle */
  Busy = static_cast<std::uint8_t>(Results::Busy),                               /*!< Busy with an operation */
  BusyReceiveSingle = static_cast<std::uint8_t>(Results::BusyReceiveSingle),     /*!< Busy with a single reception operation */
  BusyTransmitSingle = static_cast<std::uint8_t>(Results::BusyTransmitSingle),   /*!< Busy with a single transmit operation */
  BusyCallbackSingle = static_cast<std::uint8_t>(Results::BusyCallbackSingle),   /*!< Busy with a single callback operation */
  BusyReceiveMulti = static_cast<std::uint8_t>(Results::BusyReceiveMulti),       /*!< Busy with a multiple reception operation */
  BusyTransmitMulti = static_cast<std::uint8_t>(Results::BusyTransmitMulti),     /*!< Busy with a multiple transmit operation */
  BusyCallbackMulti = static_cast<std::uint8_t>(Results::BusyCallbackMulti),     /*!< Busy with a multiple callback operation */
  BusyCallbackMultiTx = static_cast<std::uint8_t>(Results::BusyCallbackMultiTx), /*!< Busy with a multiple callback operation */
  BusyCallbackMultiRx = static_cast<std::uint8_t>(Results::BusyCallbackMultiRx), /*!< Busy with a multiple callback operation */
  Done = static_cast<std::uint8_t>(Results::Done),                               /*!< Operation completed*/
  Claimed = static_cast<std::uint8_t>(Results::Claimed),                         /*!< Interface is claimed */
  WaitForNext = static_cast<std::uint8_t>(Results::WaitForNext),                 /*!< Waiting for the next operation */
  WaitForNextTransmit = static_cast<std::uint8_t>(Results::WaitForNextTransmit), /*!< Waiting for the next transmit operation */
  WaitForNextReceive = static_cast<std::uint8_t>(Results::WaitForNextReceive),   /*!< Waiting for the next receive operation */
  ErrorAddress = static_cast<std::uint8_t>(Results::ErrorAddress),               /*!< Error address */
  ErrorData = static_cast<std::uint8_t>(Results::ErrorData),                     /*!< Error data */
};
}  // namespace libmcu

#endif