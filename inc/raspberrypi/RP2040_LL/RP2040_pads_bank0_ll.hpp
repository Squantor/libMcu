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
#ifndef RP2040_PADS_BANK0_LL_HPP
#define RP2040_PADS_BANK0_LL_HPP

#include "RP2040_pads_ll.hpp"

namespace libmcull::pads {
namespace hardware_bank0 = libmcuhw::padsBank0;
/**
 * @brief
 * @tparam pads_bank0_address
 */
template <libmcu::PadsBank0BaseAddress const& pads_bank0_address>
// TODO voltage select method
struct PadsBank0 : libmcull::PeripheralBase {
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
  constexpr void Setup(T& pin, DriveModes driveStrength, bool pullUpEnable, bool pullDownEnable, bool schmittOn, bool fastSlew) {
    uint32_t setting = hardware_bank0::GPIO::IE;  // Safe default setting
    if (pullUpEnable)
      setting = setting | hardware_bank0::GPIO::PUE;
    if (pullDownEnable)
      setting = setting | hardware_bank0::GPIO::PDE;
    if (schmittOn)
      setting = setting | hardware_bank0::GPIO::SCHMITT;
    if (fastSlew)
      setting = setting | hardware_bank0::GPIO::SLEWFAST;
    setting = setting | hardware_bank0::GPIO::DRIVE(static_cast<std::uint32_t>(driveStrength));
    GetPeripheral()->GPIO[pin.pin_index] = setting;
  }
  // TODO simplified setup methods
  /**
   * @brief get registers from peripheral
   *
   * @return return pointer to peripheral
   */
  static libmcuhw::padsBank0::PadsBank0* GetPeripheral() {
    return reinterpret_cast<libmcuhw::padsBank0::PadsBank0*>(pads_bank0_address_);
  }

 private:
  static constexpr libmcu::HwAddressType pads_bank0_address_ = pads_bank0_address; /*!< peripheral address */
};
}  // namespace libmcull::pads
#endif