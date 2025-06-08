/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * @file RP2040_pads_bank0_ll.hpp
 * @brief low level interface for the RP2040 pads bank 0
 */
#ifndef RP2040_PADS_BANK0_SW_HPP
#define RP2040_PADS_BANK0_SW_HPP

#include "RP2040_pads_ll.hpp"

namespace libmcull::padsBank0 {
using namespace libmcull::pads;
namespace hardware = libmcuhw::padsBank0;

/**
 * @brief
 * @tparam padsBank0Address_
 */
template <libmcu::PadsBank0BaseAddress const& padsBank0Address_>
// TODO voltage select method
struct padsBank0 : libmcull::PeripheralBase {
  /**
   * @brief Setup pin pads
   * @tparam T pin trait template
   * @param pin pin instance
   * @param driveStrength Pin drive strength, see driveModes enum class
   * @param pullUpEnable Enable pullup resistor
   * @param pullDownEnable Enable pulldown resistor
   * @param schmittOn Enable schmitt trigger on input
   * @param fastSlew Set fast slew rate
   */
  template <typename T>
  constexpr void setup(T& pin, driveModes driveStrength, bool pullUpEnable, bool pullDownEnable, bool schmittOn, bool fastSlew) {
    uint32_t setting = hardware::GPIO::IE;  // Safe default setting
    if (pullUpEnable)
      setting = setting | hardware::GPIO::PUE;
    if (pullDownEnable)
      setting = setting | hardware::GPIO::PDE;
    if (schmittOn)
      setting = setting | hardware::GPIO::SCHMITT;
    if (fastSlew)
      setting = setting | hardware::GPIO::SLEWFAST;
    setting = setting | hardware::GPIO::DRIVE(static_cast<std::uint32_t>(driveStrength));
    padsBank0Peripheral()->GPIO[pin.pinIndex] = setting;
  }
  // TODO simplified setup methods
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::padsBank0* padsBank0Peripheral() {
    return reinterpret_cast<libmcuhw::padsBank0::padsBank0*>(padsBank0Address);
  }

 private:
  static constexpr libmcu::HwAddressType padsBank0Address = padsBank0Address_; /*!< peripheral address */
};
}  // namespace libmcull::padsBank0
#endif