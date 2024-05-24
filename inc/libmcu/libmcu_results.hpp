/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file result types used by libMcu
 */
#ifndef LIBMCU_RESULTS_HPP
#define LIBMCU_RESULTS_HPP

namespace libMcu {
/**
 * @brief result class used in libMcu for various return values
 * Predominantly used in libMcuHal and libMcuDriver
 */
enum class results : std::uint32_t {
  NO_ERROR,  /**< No error */
  ERROR,     /**< Error has occured */
  STARTED,   /**< Operation started */
  BUSY,      /**< Operation Busy */
  DONE,      /**< Operation completed*/
  IN_USE,    /**< Currently in use */
  CLAIMED,   /**< Interface has been successfully claimed */
  UNCLAIMED, /**< Interface has been successfully unclaimed */
};
}  // namespace libMcu

#endif