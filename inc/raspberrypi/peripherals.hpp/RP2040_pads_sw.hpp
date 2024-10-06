/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 pads software interface definitions
 */
#ifndef RP2040_PADS_SW_HPP
#define RP2040_PADS_SW_HPP

namespace libMcuLL::sw::pads {

enum class driveModes : std::uint32_t {
  DRIVE_2MA = libMcuHw::pads::GPIO::DRIVE_2MA,   /**< 2 milliampere drive strength */
  DRIVE_4MA = libMcuHw::pads::GPIO::DRIVE_4MA,   /**< 4 milliampere drive strength */
  DRIVE_8MA = libMcuHw::pads::GPIO::DRIVE_8MA,   /**< 8 milliampere drive strength */
  DRIVE_12MA = libMcuHw::pads::GPIO::DRIVE_12MA, /**< 12 milliampere drive strength */
};
}  // namespace libMcuLL::sw::pads
#endif