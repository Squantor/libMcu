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
  NO_ERROR,        /*!< No error */
  ERROR,           /*!< Error has occured */
  STARTED,         /*!< Operation started */
  BUSY,            /*!< Operation Busy */
  DONE,            /*!< Operation completed*/
  kInUse,          /*!< Currently in use */
  kClaimed,        /*!< Interface has been successfully claimed */
  kUnclaimed,      /*!< Interface has been successfully unclaimed */
  kNotClaimed,     /*!< Interface has not been claimed */
  kInvalidHandle,  /*!< Invalid handle */
  TIMEOUT,         /*!< Operation timed out */
  INVALID_ADDRESS, /*!< Invalid address */
  TRANSFER_ERROR,  /*!< Error occured during data transfer*/
  OVERRUN,         /*!< buffer overrun */
  FRAMING,         /*!< Framing error*/
  PARITY,          /*!< Parity error */
  BREAK,           /*!< Break error */
  FULL,            /*!< Buffer is full */
  EMPTY,           /*!< Buffer is empty */
};
}  // namespace libmcu

#endif