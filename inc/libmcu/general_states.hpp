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

#include "general_results.hpp"

namespace libmcu {
/**
 * @brief state enumeration used in libMcu for various internal states.
 * This enum depends on results making the translation from state to result easier
 */
enum class States : std::uint8_t {
  Initializing = static_cast<std::uint8_t>(Results::Initializing), /*!< Interface is initializing */
  Idle = static_cast<std::uint8_t>(Results::Idle),                 /*!< Interface is idle */
  Busy = static_cast<std::uint8_t>(Results::Busy),                 /*!< Busy with an operation */
  BusyReceive = static_cast<std::uint8_t>(Results::BusyReceive),   /*!< Busy with a Reception operation */
  BusyTransmit = static_cast<std::uint8_t>(Results::BusyTransmit), /*!< Busy with a Transmit operation */
  BusyCallback = static_cast<std::uint8_t>(Results::BusyCallback), /*!< Busy with a Callback operation */
  Done = static_cast<std::uint8_t>(Results::Done),                 /*!< Operation completed*/
  Claimed = static_cast<std::uint8_t>(Results::Claimed),           /*!< Interface is claimed */
  WaitForNext = static_cast<std::uint8_t>(Results::WaitForNext),   /*!< Interface is waiting for the next operation to start */
};
}  // namespace libmcu

#endif