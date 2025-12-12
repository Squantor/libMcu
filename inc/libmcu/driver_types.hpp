/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2025 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file driver_types.hpp
 * @brief Types used by libmcu drivers
 */
#ifndef DRIVERTYPES_HPP
#define DRIVERTYPES_HPP

namespace libMcuDriver {
/**
 * @brief Driver base class that all Driver classes should inherit from
 * You will never copy/move a Driver, they are "eternal" with respect to program lifetime
 */
struct DriverBase {
  DriverBase() = default;
  ~DriverBase() = default;
  DriverBase(const DriverBase&) = delete;
  DriverBase& operator=(const DriverBase&) = delete;
  DriverBase(DriverBase&&) = delete;
  DriverBase& operator=(DriverBase&&) = delete;
};

struct Display : public DriverBase, public libmcu::NonBlocking {}; /*!< Display driver base class, they are all asynchronous */

}  // namespace libMcuDriver

#endif