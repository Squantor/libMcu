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
#ifndef LIBMCU_RESULTS_HPP
#define LIBMCU_RESULTS_HPP

namespace libmcu {
/**
 * @brief result class used in libMcu for various return values
 * @todo rename enumeration elements to adhere to google standard
 */
enum class Results : std::uint32_t {
  kNoError,        /*!< No error */
  kError,          /*!< Error has occured */
  kStarted,        /*!< Operation started */
  kBusy,           /*!< Operation Busy */
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