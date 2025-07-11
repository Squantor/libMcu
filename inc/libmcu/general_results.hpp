/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file libmcu_results.hpp
 * @brief result types used by libMcu
 */
#ifndef GENERAL_RESULTS_HPP
#define GENERAL_RESULTS_HPP

namespace libmcu {
/**
 * @brief result class used in libMcu for various return values
 * This enum is also used as state within asycnhronous capable classes, this is done to save on translation code between state
 * and result
 */
enum class Results : std::uint8_t {
  kNoError,        /*!< No error */
  kError,          /*!< Error has occured */
  kStarted,        /*!< Operation started */
  kIdle,           /*!< Interface is idle */
  kBusy,           /*!< Operation Busy */
  kBusyTransmit,   /*!< Interface is busy with a Transmit operation */
  kBusyReceive,    /*!< Interface is busy with a Reception operation */
  kWaitForNext,    /*!< Interface is waiting for the next operation to start */
  kDone,           /*!< Operation completed*/
  kInUse,          /*!< Currently in use */
  kClaimed,        /*!< Interface has been successfully claimed */
  kUnclaimed,      /*!< Interface has been successfully unclaimed */
  kNotClaimed,     /*!< Interface has not been claimed */
  kInvalidHandle,  /*!< Invalid handle */
  kTimeout,        /*!< Operation timed out */
  kInvalidAddress, /*!< Invalid address */
  kTransferError,  /*!< Error occured during data transfer*/
  kOverrun,        /*!< buffer overrun */
  kFramingError,   /*!< Framing error*/
  kParityError,    /*!< Parity error */
  kBreakError,     /*!< Break error */
  kFull,           /*!< Buffer is full */
  kEmpty,          /*!< Buffer is empty */
};
}  // namespace libmcu

#endif