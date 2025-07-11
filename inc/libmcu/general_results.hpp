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
  NoError,        /*!< No error */
  Error,          /*!< Error has occured */
  Started,        /*!< Operation started */
  Idle,           /*!< Interface is idle */
  Busy,           /*!< Operation Busy */
  BusyTransmit,   /*!< Interface is busy with a Transmit operation */
  BusyReceive,    /*!< Interface is busy with a Reception operation */
  WaitForNext,    /*!< Interface is waiting for the next operation to start */
  Done,           /*!< Operation completed*/
  InUse,          /*!< Currently in use */
  Claimed,        /*!< Interface has been successfully claimed */
  Unclaimed,      /*!< Interface has been successfully unclaimed */
  NotClaimed,     /*!< Interface has not been claimed */
  InvalidHandle,  /*!< Invalid handle */
  Timeout,        /*!< Operation timed out */
  InvalidAddress, /*!< Invalid address */
  TransferError,  /*!< Error occured during data transfer*/
  Overrun,        /*!< buffer overrun */
  FramingError,   /*!< Framing error*/
  ParityError,    /*!< Parity error */
  BreakError,     /*!< Break error */
  Full,           /*!< Buffer is full */
  Empty,          /*!< Buffer is empty */
};
}  // namespace libmcu

#endif