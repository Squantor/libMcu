/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file dummy.hpp
 * @brief Dummy driver
 */
#ifndef DRIVER_DUMMY_HPP
#define DRIVER_DUMMY_HPP

namespace libMcuDrv::dummy {
namespace spi = libmcuhal::spi;
template <typename config, auto &spiHal>
struct memlcd {};
}  // namespace libMcuDrv::dummy

#endif