/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2023 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file result types used by libMcuLL
 */
#ifndef RESULTS_HPP
#define RESULTS_HPP

namespace libMcuLL {
/**
 * @brief result class for libMcuLL
 *
 * Mostly used by asynchronous operations
 *
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
}  // namespace libMcuLL

#endif