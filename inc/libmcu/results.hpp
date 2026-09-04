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
  NoError,             /*!< No error */
  Error,               /*!< Error has occured */
  Started,             /*!< Operation started */
  Uninitialized,       /*!< Uninitialized */
  Initializing,        /*!< Interface is initializing */
  Idle,                /*!< Interface is idle */
  Busy,                /*!< Operation Busy */
  BusyTransmitSingle,  /*!< Interface is busy with a single transmit operation */
  BusyReceiveSingle,   /*!< Interface is busy with a single reception operation */
  BusyCallbackSingle,  /*!< Interface is busy with a single callback operation */
  BusyTransmitMulti,   /*!< Interface is busy with a multiple transmit operation */
  BusyReceiveMulti,    /*!< Interface is busy with a multiple reception operation */
  BusyCallbackMulti,   /*!< Interface is busy with a multiple callback operation */
  BusyCallbackMultiTx, /*!< Interface is busy with a multiple callback operation */
  BusyCallbackMultiRx, /*!< Interface is busy with a multiple callback operation */
  busy_writing,        /*!< Interface is busy writing */
  busy_reading,        /*!< Interface is busy reading */
  WaitForNext,         /*!< Interface is waiting for the next operation to start */
  WaitForNextTransmit, /*!< Interface is waiting for the next transmit operation to start */
  WaitForNextReceive,  /*!< Interface is waiting for the next receive operation to start */
  Done,                /*!< Operation completed*/
  InUse,               /*!< Currently in use */
  Claimed,             /*!< Interface has been successfully claimed */
  Unclaimed,           /*!< Interface has been successfully unclaimed */
  NotClaimed,          /*!< Interface has not been claimed */
  InvalidHandle,       /*!< Invalid handle */
  Timeout,             /*!< Operation timed out */
  InvalidAddress,      /*!< Invalid address */
  TransferError,       /*!< Error occured during data transfer*/
  Overrun,             /*!< buffer overrun */
  FramingError,        /*!< Framing error*/
  ParityError,         /*!< Parity error */
  BreakError,          /*!< Break error */
  ErrorAddress,        /*!< Error address */
  ErrorData,           /*!< Error data */
  Full,                /*!< Buffer is full */
  Empty,               /*!< Buffer is empty */
};
}  // namespace libmcu

#endif