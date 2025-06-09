/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_pads_ll.hpp
 * @brief low level interface for the RP2040 pads
 */
#ifndef RP2040_PADS_LL_HPP
#define RP2040_PADS_LL_HPP

namespace libmcull::pads {
/**
 * @brief
 */
enum class DriveModes : std::uint32_t {
  k2mA = libmcuhw::pads::GPIO::DRIVE_2MA,   /*!< 2 milliampere drive strength */
  k4mA = libmcuhw::pads::GPIO::DRIVE_4MA,   /*!< 4 milliampere drive strength */
  k8mA = libmcuhw::pads::GPIO::DRIVE_8MA,   /*!< 8 milliampere drive strength */
  k12mA = libmcuhw::pads::GPIO::DRIVE_12MA, /*!< 12 milliampere drive strength */
};
}  // namespace libmcull::pads
#endif