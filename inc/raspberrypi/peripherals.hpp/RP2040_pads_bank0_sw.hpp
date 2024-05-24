/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2024 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/**
 * \file RP2040 pads bank0 software interface
 */
#ifndef RP2040_PADS_BANK0_SW_HPP
#define RP2040_PADS_BANK0_SW_HPP

#include <raspberrypi/peripherals.hpp/RP2040_pads_sw.hpp>

namespace libMcuLL::sw::padsBank0 {

using namespace libMcuLL::sw::pads;

template <libMcuLL::padsBank0BaseAddress const& padsBank0Address_>
// TODO voltage select method
struct padsBank0 : libMcuLL::peripheralBase {
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
    uint32_t setting = hw::pads::GPIO::IE;  // Safe default setting
    if (pullUpEnable)
      setting = setting | hw::pads::GPIO::PUE;
    if (pullDownEnable)
      setting = setting | hw::pads::GPIO::PDE;
    if (schmittOn)
      setting = setting | hw::pads::GPIO::SCHMITT;
    if (fastSlew)
      setting = setting | hw::pads::GPIO::SLEWFAST;
    setting = setting | hw::pads::GPIO::DRIVE(static_cast<std::uint32_t>(driveStrength));
    padsBank0Peripheral()->GPIO[pin.pinIndex] = setting;
  }
  // TODO simplified setup methods
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static hw::padsBank0::peripheral* padsBank0Peripheral() {
    return reinterpret_cast<hw::padsBank0::peripheral*>(padsBank0Address);
  }

 private:
  static constexpr libMcuLL::hwAddressType padsBank0Address = padsBank0Address_; /**< peripheral address */
};
}  // namespace libMcuLL::sw::padsBank0
#endif